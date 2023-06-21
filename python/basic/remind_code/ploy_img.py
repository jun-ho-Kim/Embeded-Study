#%%

import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

#%%
#load image
img = np.asarray(Image.open('stinkbug.png'))
print(repr(img))

implot = plt.imshow(img);

#%%
# plot image
lum_img = img[:,:, 0] # 채널 한 개만 가져오도록 함
plt.imshow(lum_img)
#plt.imshow(lum_img, cmap="hot")
plt.colorbar()

#%%
#plot histgram
plt.hist(lum_img.ravel(), bins=range(256), fc='k', ec='k')
# %%
