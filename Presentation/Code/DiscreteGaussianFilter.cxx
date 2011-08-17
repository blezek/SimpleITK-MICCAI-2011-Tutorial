  // Setup image types.
  typedef    float InputPixelType;
  typedef    float OutputPixelType;
  typedef itk::Image<InputPixelType, 2> InputImageType;
  typedef itk::Image<OutputPixelType,2> OutputImageType;
  // Filter type
  typedef itk::DiscreteGaussianImageFilter<
                 InputImageType, OutputImageType >
          FilterType;
  // Create a filter
  FilterType::Pointer filter = FilterType::New();
  // Create the pipeline
  filter->SetInput( reader->GetOutput() );
  filter->SetVariance( 1.0 );
  filter->SetMaximumKernelWidth( 5 );
  filter->Update();
  OutputImageType::Pointer blurred = filter->GetOutput();
