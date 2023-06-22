# %%
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

# %%
#load image
img = np.asarray(Image.open('stinkbug.png'))
print(repr(img))

# %%
# plot image
imgplot = plt.imshow(img)

# %%
lum_img = img[:, :, 0]
plt.imshow(lum_img)
#plt.imshow(lum_img, cmap="hot")
plt.colorbar()

# %%
#plot histogram
plt.hist(lum_img.ravel(), bins=range(256), fc='k', ec='k')
# %%
