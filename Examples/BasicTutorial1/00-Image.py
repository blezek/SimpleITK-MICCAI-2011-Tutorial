# Welcome to the first demo
print 'SimpleITK Image Basics'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK

# <demo> --- stop ---

# Create an image
image = SimpleITK.Image ( 256, 128, 64, SimpleITK.sitkInt16 );

# <demo> --- stop ---

# What can an image do for us?
help ( image )

# <demo> --- stop ---

# Number of dimensions
image.GetDimension()

# <demo> --- stop ---

# Size of the image
image.GetSize()

# <demo> --- stop ---

# Individual demensions
image.GetWidth()
image.GetHeight()
image.GetDepth()

# <demo> --- stop ---

# Origin and Spacing
image.GetOrigin()
image.GetSpacing()

# <demo> --- stop ---

# Pixel type
image.GetPixelIDValue()
image.GetPixelIDTypeAsString()

# <demo> --- stop ---

# Addressing pixels
image.GetPixel ( 0, 0, 0 )
image.SetPixel ( 0, 0, 0, 1 )
image.GetPixel ( 0, 0, 0 )

# <demo> --- stop ---

# Addressing pixels the easier way
image[0,0,0]
image[0,0,0] = 10
image[0,0,0]

# <demo> --- stop ---

# How about 2d?
twoD = SimpleITK.Image ( 64, 64, SimpleITK.sitkFloat32 )
twoD.GetDimension()
twoD.GetSize()

# <demo> --- stop ---

# Summary

# <demo> --- stop ---

# Input and Output


# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---




# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
# <demo> --- stop ---
