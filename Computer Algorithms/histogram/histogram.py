# ===================================================================================

# CA Assignment 4:
    
# Name: Om Vivek Gharge
# PRN: 2020BTEIT00041

# ===================================================================================
# -----------------------------------------------------------------------------------


import numpy as np
import matplotlib.pyplot as plt
from skimage import exposure as ex
import cv2
from mpi4py import MPI
# -----------------------------------------------------------------------------------

frequency = []
# MPI Functions
comm = MPI.COMM_WORLD
p = comm.Get_size()
rank = comm.Get_rank()

# -----------------------------------------------------------------------------------

# Showing the image and the histogram of the image.    
def imgShow(img):
    number_of_pix = np.sum(img) 
    print('Number of pixels : ', number_of_pix)
    plt.imshow(img)
    plt.show()

    histr = cv2.calcHist([img], [0], None, [256], [0,256])
    plt.plot(histr)
    plt.show()
    return

# -----------------------------------------------------------------------------------

"""
It takes an image as input and returns the histogram of the image

:param img: The image to be processed
:return: the histogram of the image.
"""
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
        
    print("PDF of the data: \n",pdf,"\n","CDF of the data: \n",cdf,"\n","CDF*255 of the data: \n",tr)

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
    return hs

# -----------------------------------------------------------------------------------

def equilize(img):
    """
    plots the histogram of the greyscale image
    
    :param img: Input image. It should be grayscale and float32 type
    """

    result = grey(img)
    plt.imshow(result)
    plt.show()

    histr = cv2.calcHist([result], [0], None, [256], [0,256])
    plt.plot(histr)
    plt.show()
    return 

# -----------------------------------------------------------------------------------

    """
    It takes an image, converts it to grayscale, and then applies histogram equalization to it
    
    :param img: The image to be processed
    :return: the image after it has been converted to greyscale and equalized.
    """
def grey(img):
    outImg = ex.equalize_hist(img[:, :])*255

    outImg[outImg > 255] = 255
    outImg[outImg < 0] = 0
    return outImg.astype(np.uint8)

# -----------------------------------------------------------------------------------

def main():
    # img_name = sys.argv[1]
    img_name = "img1.jpg"
    img = cv2.imread("img1.jpg",0)
    (height,width) = img.shape
    size=width*height


    # Sending the image to the other processes and then receiving the image from the other processes.
    if rank == 1 :
     comm.send(imgShow(img), dest=0)
    
    if rank == 2 :
     comm.send(freqPrint(img), dest=0)

    if rank == 3 :
     comm.send(equilize(img), dest=0)

    else:
     for procid in range(1, p):
        message = comm.recv(source=procid)
        plt.show()
        print("Process 0 received message from process" ,p,message);
    
    MPI.Finalize();
# -----------------------------------------------------------------------------------
        
if __name__ == '__main__':
    main();

# -----------------------------------------------------------------------------------
