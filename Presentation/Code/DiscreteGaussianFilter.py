import SimpleITK
input = SimpleITK.ReadImage ( filename )
output = SimpleITK.DiscreteGaussianFilter( input, 1.0, 5 )
