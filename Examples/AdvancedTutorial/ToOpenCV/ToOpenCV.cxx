

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

  /* Step 1 */

  /* Step 2 */
  // Convert ITK to OpenCV image
  cv::Mat ocvImage;

  /* Step 3 (Optional) */

  // Filter and write using OpenCV
  cv::Mat output;
  cv::medianBlur ( ocvImage, output, 5 );

  cv::imwrite ( outputFilename, output );

  return EXIT_SUCCESS;
}
