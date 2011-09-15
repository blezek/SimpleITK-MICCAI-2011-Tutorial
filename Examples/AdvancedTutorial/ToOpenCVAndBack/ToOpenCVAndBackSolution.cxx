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
  sitk::Image sOutput = 0.0 * sitk::Cast ( sitkImage, sitk::sitkFloat32 );

  std::cout << "Processing: " << std::flush;
  for ( unsigned int s = 0; s < sitkImage.GetDepth(); s++ )
    {
    std::cout << s << ".." << std::flush;
    // Extract a slice
    std::vector<unsigned int> size = sitkImage.GetSize();
    size[2] = 1;
    std::vector<int> index ( 3, 0 );
    index[2] = s;
    sitk::Image slice = sitk::RegionOfInterest ( sitkImage, size, index );

    if ( slice.GetPixelIDValue() != sitk::sitkFloat32 )
      {
      std::cout << "Converting to float" << std::endl;
      slice = sitk::Cast ( slice, sitk::sitkFloat32 );
      }

    // Convert ITK to OpenCV image
    cv::Mat ocvImage ( slice.GetHeight(), slice.GetWidth(), CV_32F, (void*)slice.GetBufferAsFloat() );

    // Filter using OpenCV
    cv::Mat output;
    cv::Sobel ( ocvImage, output, -1, 1, 1 );

    // Convert back to SimpleITK
    sitk::ImportImageFilter importer;
    importer.SetSize ( size );
    importer.SetSpacing ( sitkImage.GetSpacing() );
    importer.SetOrigin ( sitkImage.GetOrigin() );
    importer.SetBufferAsFloat ( output.ptr<float>() );

    sitk::Image toSimpleITKImage = importer.Execute();

    // Paste the image back into SimpleITK
    sOutput = sitk::Paste ( sOutput, toSimpleITKImage, toSimpleITKImage.GetSize(), std::vector<int> ( 3,0 ), index );
    }
  // (Optional) Show the results
  sitk::Show ( sOutput );
  std::cout << "Done" << std::endl;

  sitk::WriteImage ( sOutput, outputFilename );
  return EXIT_SUCCESS;
}
