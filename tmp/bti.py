from PIL import Image
import os
import struct
from matplotlib import pyplot as plt
import numpy as np


inbstr = b''
with open('image2.txt', 'rb') as file:
    inbstr = file.read()


data = struct.unpack('i'*100*100, inbstr)


pixels = np.split(np.array(data), 100)

print(pixels)

plt.imshow(pixels, cmap='gray')
plt.show()
