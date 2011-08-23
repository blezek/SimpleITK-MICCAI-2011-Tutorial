# Welcome to the Filters demo
print 'SimpleITK Filters'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK

# <demo> --- stop ---

# Find some data
import os
dataDir = os.environ["HOME"] + "/Source/SimpleITK/Testing/Data/Input"
image = SimpleITK.ReadImage ( dataDir + "/RA-Short.nrrd" )
SimpleITK.Show ( image )

# <demo> --- stop ---

# Simple smoothing
smooth = SimpleITK.SmoothingRecursiveGaussian ( image, 2.0 )
SimpleITK.Show ( smooth )

# <demo> --- stop ---

# Boom!  What happened?
SimpleITK.Show ( SimpleITK.Subtract ( image, smooth ) )

# <demo> --- stop ---

# Much better
smooth = SimpleITK.Cast ( smooth, image.GetPixelIDValue() )
print image.GetPixelIDTypeAsString()
print smooth.GetPixelIDTypeAsString()
SimpleITK.Show ( SimpleITK.Subtract ( image, smooth ) )

# <demo> --- stop ---

# 3D image
image = SimpleITK.ReadImage ( dataDir + "/OAS1_0001_MR1_mpr-1_anon.nrrd" )
SimpleITK.Show ( image )

# <demo> --- stop ---



# <demo> --- stop ---
# <demo> --- stop ---
