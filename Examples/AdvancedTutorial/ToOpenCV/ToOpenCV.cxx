

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
  if ( sitkImage.GetPixelIDValue() != itk::simple::sitkFloat32 )
    {
    std::cout << "Input image is " << sitkImage.GetPixelIDTypeAsString() << " converting to float" << std::endl;
    sitkImage = itk::simple::Cast ( sitkImage, itk::simple::sitkFloat32 );
    }

  // Extract the center slice
  std::vector<unsigned int> size = sitkImage.GetSize();
  size[2] = 1;
  std::vector<int> index ( 3, 0 );
  index[2] = sitkImage.GetDepth() / 2.0;
  std::cout << "Extracting: " << size[2] << " from " << index[2] << std::endl;
  itk::simple::Image centerSlice = itk::simple::RegionOfInterest ( sitkImage, size, index );

  itk::simple::WriteImage ( centerSlice, "/tmp/CenterSlice.nii" );

  // Go through ITK to grab the data
  typedef itk::Image<float,2> ImageType;
  ImageType::Pointer itkImage = (ImageType*)centerSlice.GetImageBase();

  // Initialize
  cv::Mat ocvImage ( sitkImage.GetHeight(), sitkImage.GetWidth(), CV_32F,  (void*)itkImage->GetBufferPointer() );

  // Filter
  cv::Mat output, temp;
  cv::medianBlur ( ocvImage, output, 5 );

  // NB: the imshow function requires 8-bit data, so convert
  ocvImage.convertTo ( temp, CV_8U );
  cv::imshow ( "original slice", temp );
  output.convertTo ( temp, CV_8U );
  cv::imshow ( "bilateral filtering", temp );

  std::cout << "Press any key to continue" << std::endl;
  cv::waitKey();

  cv::imwrite ( outputFilename, output );

  return EXIT_SUCCESS;
}
