import matplotlib.pyplot as plt
import numpy as np
import imageio

with open('f_libraries_of_the_world.txt','r') as f:
    
    b, l, d = [int(x) for x in next(f).split()]
    print(b)
    print(l)
    image = np.zeros((b,l))

    book_values = [int(x) for x in next(f).split()]
    
    for i in range(l):
        
        n, t, m =  [int(x) for x in next(f).split()]
        indencies = [int(x) for x in next(f).split()]
        
        for j in indencies:
            image[j, i] = book_values[j]
imageio.imwrite('roskopocepanac.bmp', image)
#plt.imshow(image)
#plt.show()
