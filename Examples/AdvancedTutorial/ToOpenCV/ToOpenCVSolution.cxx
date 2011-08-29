

#include <SimpleITK.h>
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
  if ( sitkImage.GetPixelIDValue() != itk::simple::sitkFloat32 )
    {
    std::cout << "Input image is " << sitkImage.GetPixelIDTypeAsString() << " converting to float" << std::endl;
    sitkImage = itk::simple::Cast ( sitkImage, itk::simple::sitkFloat32 );
    }

  // Go through ITK to grab the data
  typedef itk::Image<float,2> ImageType;
  ImageType::Pointer itkImage = (ImageType*)sitkImage.GetImageBase();

  // Convert ITK to OpenCV image
  cv::Mat ocvImage ( sitkImage.GetHeight(), sitkImage.GetWidth(), CV_32F,  (void*)itkImage->GetBufferPointer() );

  // Filter and write using OpenCV
  cv::Mat output;
  cv::medianBlur ( ocvImage, output, 5 );

  // NB: the imshow function requires 8-bit data, so convert
  cv::Mat temp;
  ocvImage.convertTo ( temp, CV_8U );
  cv::imshow ( "original slice", temp );
  output.convertTo ( temp, CV_8U );
  cv::imshow ( "bilateral filtering", temp );

  std::cout << "Press any key to continue" << std::endl;
  cv::waitKey();

  cv::imwrite ( outputFilename, output );

  return EXIT_SUCCESS;
}
