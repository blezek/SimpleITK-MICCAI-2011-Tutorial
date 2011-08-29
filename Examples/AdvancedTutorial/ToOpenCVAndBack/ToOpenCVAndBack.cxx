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
    std::vector<unsigned int> size = sitkImage.GetSize();
    size[2] = 1;
    std::vector<int> index ( 3, 0 );
    index[2] = s;
    std::cout << "Extracting: " << s << std::endl;
    itk::simple::Image slice = itk::simple::RegionOfInterest ( sitkImage, size, index );

    if ( slice.GetPixelIDValue() != itk::simple::sitkFloat32 )
      {
      slice = itk::simple::Cast ( slice, itk::simple::sitkFloat32 );
      }

    // Go through ITK to grab the data
    typedef itk::Image<float,2> ImageType;
    ImageType::Pointer itkImage = (ImageType*)slice.GetImageBase();

    // Convert ITK to OpenCV image
    cv::Mat ocvImage ( slice.GetHeight(), slice.GetWidth(), CV_32F,  (void*)itkImage->GetBufferPointer() );

    // Filter and write using OpenCV
    cv::Mat output;
    cv::Sobel ( ocvImage, output, -1, 1, 1 );
/*
    std::cout << ocvImage << std::endl;
    std::cout << output << std::endl;
    return 1;
*/

    // Convert back to SimpleITK
    typedef itk::Image<float,3> ImageType3;
    ImageType3::SizeType size2;
    size2[0] = slice.GetWidth();
    size2[1] = slice.GetHeight();
    ImageType3::IndexType start;
    start.Fill(0);
    ImageType3::RegionType region;
    region.SetIndex ( start );
    region.SetSize ( size2 );

    ImageType3::Pointer toITKImage = ImageType3::New();
    toITKImage->GetPixelContainer()->SetImportPointer ( output.ptr<float>(), output.size().width * output.size().height, false );
    toITKImage->Allocate();
    toITKImage->SetOrigin ( sitkImage.GetOrigin()[0] );
    toITKImage->SetSpacing ( sitkImage.GetSpacing()[0] );

    itk::simple::Image toSimpleITKImage ( toITKImage );
    toSimpleITKImage = itk::simple::Cast ( toSimpleITKImage, sitkImage.GetPixelIDValue() );

    // Paste the image back into SimpleITK
    sOutput = itk::simple::Paste ( sOutput, toSimpleITKImage, toSimpleITKImage.GetSize(), std::vector<int> ( 3,0 ), index );
    }
  itk::simple::WriteImage ( sOutput, outputFilename );
  return EXIT_SUCCESS;
}
