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

# Clone image
b = SimpleITK.Image ( image )
print image
print b

# <demo> --- stop ---

print b
b[0,0,0] = 1
print b
print image

