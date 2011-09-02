

#include <SimpleITK.h>
#include <itkMirrorPadImageFilter.h>

#include <iostream>
#include <string>

int main ( int argc, char **argv )
{
  if ( argc < 3 )
    {
    std::cerr << "Usage: " << argv[0] << " <input> <output>" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputFilename ( argv[1] );
  std::string outputFilename ( argv[2] );

  // Load the image via SimpleITK
  itk::simple::Image sitkImage = itk::simple::ReadImage ( inputFilename );
  if ( sitkImage.GetDimension() != 3 )
    {
    std::cerr << "Input image is required to be 3 dimensional!" << std::endl;
    return EXIT_FAILURE;
    }

  if ( sitkImage.GetPixelIDValue() != itk::simple::sitkFloat32 )
    {
    std::cout << "Input image is " << sitkImage.GetPixelIDTypeAsString() << " converting to float" << std::endl;
    sitkImage = itk::simple::Cast ( sitkImage, itk::simple::sitkFloat32 );
    }

  // Construct the ITK Pipeline
  typedef itk::Image<float,3> ImageType;
  typedef itk::MirrorPadImageFilter<ImageType,ImageType> PadFilterType;
  PadFilterType::SizeType upperBound, lowerBound;

  PadFilterType::Pointer pad = PadFilterType::New();
  for ( unsigned int i = 0; i < 3; i++ )
    {
      upperBound[i] = sitkImage.GetSize()[i];
      lowerBound[i] = sitkImage.GetSize()[i];
    }
  pad->SetPadUpperBound ( upperBound );
  pad->SetPadLowerBound ( lowerBound );

  // Link pipeline to SimpleITK
  ImageType::Pointer inputImage = (ImageType*) sitkImage.GetImageBase();
  pad->SetInput ( inputImage );

  // Update pipeline
  pad->Update();

  // Create output SimpleITK image
  itk::simple::Image sOutput ( pad->GetOutput() );

  // Save image via SimpleITK
  itk::simple::WriteImage ( sOutput, outputFilename );

  // (Optional) Show the results
  itk::simple::Show ( sOutput, "Mirror Padded Results" );
  return EXIT_SUCCESS;
}
