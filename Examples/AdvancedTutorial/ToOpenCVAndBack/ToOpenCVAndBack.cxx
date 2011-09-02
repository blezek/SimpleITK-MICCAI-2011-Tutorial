#include <SimpleITK.h>
#include <sitkImageOperators.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

namespace sitk = itk::simple;

int main ( int argc, char **argv )
{
  if ( argc < 3 )
    {
    std::cerr << "Usage: " << argv[0] << " <input> <output>" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputFilename ( argv[1] );
  std::string outputFilename ( argv[2] );

  sitk::Image sitkImage = sitk::ReadImage ( inputFilename );

  // Quick way to make a copy of the image
  sitk::Image sOutput = 0.0 * sitkImage;

  for ( unsigned int s = 0; s < sitkImage.GetDepth(); s++ )
    {
    // Extract a slice
    // Go through ITK to grab the data
    // Convert ITK to OpenCV image
    // Filter using OpenCV
    // Convert back to SimpleITK
    // Paste the image back into SimpleITK
    }
  sitk::WriteImage ( sOutput, outputFilename );
  return EXIT_SUCCESS;
}
