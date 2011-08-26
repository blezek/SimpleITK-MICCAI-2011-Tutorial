# Welcome to the Morphology demo
print 'SimpleITK Morphology'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK

# <demo> --- stop ---

# Find some data
import os
dataDir = os.environ["HOME"] + "/Source/SimpleITK/Testing/Data/Input"
image = SimpleITK.ReadImage ( dataDir + "/WhiteDots.png" )
SimpleITK.Show ( image, "WhiteDots" )

# <demo> --- stop ---

# Erode
SimpleITK.Show ( SimpleITK.BinaryErode ( image ), "Eroded" )

# <demo> --- stop ---

# Hmm, can we visualize better?
SimpleITK.Show ( 0.5 * image + 0.5 * SimpleITK.BinaryErode ( image ), "ThinErosion" )

# <demo> --- stop ---

# Bigger kernel
filter = SimpleITK.BinaryErodeImageFilter()
filter.SetKernelRadius ( 5 ).SetForegroundValue ( 255 )
eroded = filter.Execute ( image )
SimpleITK.Show ( 0.5 * image + 0.5 * eroded, "ThickErosion" )

# <demo> --- stop ---

# Try with a cross
filter.SetKernelType ( SimpleITK.BinaryErodeImageFilter.Cross )
eroded = filter.Execute ( image )
SimpleITK.Show ( 0.5 * image + 0.5 * eroded, "CrossErosion" )

# <demo> --- stop ---

# Dilate
filter = SimpleITK.BinaryDilateImageFilter()
filter.SetKernelRadius ( 5 ).SetForegroundValue ( 255 )
dilated = filter.Execute ( image )
SimpleITK.Show ( 0.5 * image + 0.5 * dilated, "Dilate5" )

# <demo> --- stop ---

# Grayscale
head = SimpleITK.ReadImage ( dataDir + "/cthead1.png" )
SimpleITK.Show ( image, "Head" )
