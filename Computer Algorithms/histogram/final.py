import numpy as np
import matplotlib.pyplot as plt
from skimage import exposure as ex
from skimage import filters as flt
import imageio.v2 as imageio
import cv2
from mpi4py import MPI


frequency = []
# MPI Functions
comm = MPI.COMM_WORLD
p = comm.Get_size()
rank = comm.Get_rank()
    
def imgShow(img):
    histr = cv2.calcHist([img], [0], None, [256], [0,256])
    return histr
# plt.plot(histr)
#     plt.show()    

def freqPrint(img):
    # Print Height and Width
    (x,y) = img.shape
    print(x,y)

    freq=[0]*256;
    size = x*y
    numOfPix = np.sum(img);

    temp=0;

    for i in range(0,x):
        for j in range(0,y):
            temp = img[i][j];
            freq[temp]+=1
        
    print("Frequency of pixels :")
    for i in freq:
        print(i);

            
    pdf = []
    for i in freq:
        pdf.append(i/size)
            
    cdf = []
    total = 0
    for i in pdf:
        total=total+i
        cdf.append(total)

    tr = []
    for i in cdf:
        t = round(i*255)
        tr.append(t)
        
    print(pdf,"\n",cdf,"\n",tr)

    pixels = []

    for i in range(256):
        pixels.append(x)
        
    hs = []
    for i in pixels:
        count=0
        tot=0
        for j in tr:
            if(j==i):
                tot=tot+freq[count];
            count+=1

        hs.append(tot)

    result = grey(img)
    # plt.imshow(result)
    # plt.show()
    return result

def equilize(img):

    result = grey(img)
    # plt.imshow(result)
    # plt.show()

    histr = cv2.calcHist([result], [0], None, [256], [0,256])
    # plt.plot(histr)
    # plt.show()
    return histr


def grey(img):
    outImg = ex.equalize_hist(img[:, :])*255

    outImg[outImg > 255] = 255
    outImg[outImg < 0] = 0
    return outImg.astype(np.uint8)

def main():
    # img_name = sys.argv[1]
    img_name = "img.jpg"
    img = cv2.imread("img.jpg",0)
    (height,width) = img.shape
    size=width*height
    number_of_pix = np.sum(img) 
    print('Number of pixels : ', number_of_pix)


    if rank == 1 :
     comm.send(imgShow(img), dest=0)
    
    if rank == 2 :
     comm.send(freqPrint(img), dest=0)

    if rank == 3 :
     comm.send(equilize(img), dest=0)

    if rank == 0 :
        plt.imshow(img)
        plt.show()
        for procid in range(1, p):
            hist = comm.recv(source=procid)
            plt.plot(hist)
            plt.show()
            print("Process 0 received message from process" ,p);


if __name__ == '__main__':
    main()