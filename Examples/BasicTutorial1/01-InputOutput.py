# Welcome to the Input/Output demo
print 'SimpleITK Input Output'

# <demo> --- stop ---

# Every demo starts by importing the SimpleITK module
import SimpleITK

# <demo> --- stop ---

# Find some data
import os
dataDir = os.environ["HOME"] + "/Source/SimpleITK/Testing/Data/Input"

# <demo> --- stop ---

# Create a reader
reader = SimpleITK.ImageFileReader()
reader.SetFileName ( dataDir + "/WhiteDots.png" )
# Read
image = reader.Execute()

# <demo> --- stop ---

# meh, do it with less typing
image = SimpleITK.ReadImage ( dataDir + "/WhiteDots.png" )

# <demo> --- stop ---

# What'd we get?
print image

# <demo> --- stop ---

# What's the image look like?
SimpleITK.Show ( image )

# <demo> --- stop ---

# 3D image
image = SimpleITK.ReadImage ( dataDir + "/OAS1_0001_MR1_mpr-1_anon.nrrd" )
SimpleITK.Show ( image )

# <demo> --- stop ---



# <demo> --- stop ---
# <demo> --- stop ---
