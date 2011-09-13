# Welcome to the Morphology demo
print 'SimpleITK Morphology'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK as sitk

# <demo> --- stop ---

# Find some data
import os
dataDir = os.environ["HOME"] + "/Source/SimpleITK/Testing/Data/Input"
image = sitk.ReadImage ( dataDir + "/WhiteDots.png" )
sitk.Show ( image, "WhiteDots" )

# <demo> --- stop ---

# Erode
sitk.Show ( sitk.BinaryErode ( image ), "Eroded" )

# <demo> --- stop ---

# Hmm, can we visualize better?
sitk.Show ( 0.5 * image + 0.5 * sitk.BinaryErode ( image ), "ThinErosion" )

# <demo> --- stop ---

# Bigger kernel
filter = sitk.BinaryErodeImageFilter()
filter.SetKernelRadius ( 5 ).SetForegroundValue ( 255 )
eroded = filter.Execute ( image )
sitk.Show ( 0.5 * image + 0.5 * eroded, "ThickErosion" )

# <demo> --- stop ---

# Try with a cross
filter.SetKernelType ( sitk.BinaryErodeImageFilter.Cross )
eroded = filter.Execute ( image )
sitk.Show ( 0.5 * image + 0.5 * eroded, "CrossErosion" )

# <demo> --- stop ---

# Dilate
filter = sitk.BinaryDilateImageFilter()
filter.SetKernelRadius ( 5 ).SetForegroundValue ( 255 )
dilated = filter.Execute ( image )
sitk.Show ( 0.5 * image + 0.5 * dilated, "Dilate5" )

# <demo> --- stop ---

# Grayscale
head = sitk.ReadImage ( dataDir + "/cthead1.png" )
sitk.Show ( image, "Head" )
