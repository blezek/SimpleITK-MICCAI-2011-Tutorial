using itk::simple;
// Read the image file
ImageFileReader reader;
reader.SetFileName ( "/my/fancy/file.nrrd" );
Image image = reader.Execute();

// This filters perform a gaussian bluring with sigma in
// physical space. The output image will be of real type.
SmoothingRecursiveGaussianImageFilter gaussian;
gaussian.SetSigma ( 2.0 );
Image blurredImage = gaussian.Execute ( image );
