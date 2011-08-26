# Welcome to Memory Management
print 'SimpleITK Memory Management'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK

# <demo> --- stop ---

# Create an image, details in the presentation
image = SimpleITK.Image ( 32, 32, 32, SimpleITK.sitkInt16 );
print image

# <demo> --- stop ---

# Reference the image
image2 = image
print image

# <demo> --- stop ---

# Clone the image
