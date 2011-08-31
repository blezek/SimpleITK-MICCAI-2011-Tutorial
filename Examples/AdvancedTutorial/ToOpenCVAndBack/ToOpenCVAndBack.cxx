#include <SimpleITK.h>
#include <sitkImageOperators.h>
#include <opencv2/opencv.hpp>

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

  itk::simple::Image sitkImage = itk::simple::ReadImage ( inputFilename );

  // Quick way to make a copy of the image
  itk::simple::Image sOutput = 0.0 * sitkImage;

  for ( unsigned int s = 0; s < sitkImage.GetDepth(); s++ )
    {
    // Extract a slice
    // Go through ITK to grab the data
    // Convert ITK to OpenCV image
    // Filter using OpenCV
    // Convert back to SimpleITK
    // Paste the image back into SimpleITK
    }
  itk::simple::WriteImage ( sOutput, outputFilename );
  return EXIT_SUCCESS;
}
