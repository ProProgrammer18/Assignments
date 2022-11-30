from telnetlib import NOP
import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("img1.jpg",0);

(x,y) = img.shape
print(img.shape)

print(x,y)
freq=[0]*256;

size = x*y



numOfPix = np.sum(img);
print("No. of pixels = " , numOfPix)

temp=0;

for i in range(0,x):
    for j in range(0,y):
        temp = img[i][j];
        freq[temp]+=1
        
for i in freq:
    print(i);
    # print("\n")
        
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

plt.bar(pixels,hs)
plt.show()
