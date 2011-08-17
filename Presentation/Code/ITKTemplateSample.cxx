  typedef unsigned char PixelType;
  enum {ImageDimension = 2};
  typedef itk::Image<PixelType,ImageDimension> ImageType;
  typedef itk::Vector<float,ImageDimension> VectorType;
  typedef itk::Image<VectorType,ImageDimension> FieldType;
  typedef itk::Image<VectorType::ValueType,ImageDimension> FloatImageType;
  typedef ImageType::IndexType  IndexType;
  typedef ImageType::SizeType   SizeType;
  typedef ImageType::RegionType RegionType;
  typedef itk::MultiResolutionPDEDeformableRegistration<ImageType,
    ImageType, FieldType> RegistrationType;
