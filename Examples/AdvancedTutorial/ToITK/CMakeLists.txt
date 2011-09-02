add_executable ( ToITK ToITK.cxx )
target_link_libraries ( ToITK  ${SimpleITK_LIBS} ${ITK_LIBRARIES})

add_executable ( ToITKSolution ToITKSolution.cxx )
target_link_libraries ( ToITKSolution  ${SimpleITK_LIBS} ${ITK_LIBRARIES})
