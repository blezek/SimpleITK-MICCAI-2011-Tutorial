project(AdvancedTutorials)

cmake_minimum_required(VERSION 2.8)

set(ITK_INSTALL_PREFIX "$ENV{HOME}/Source/SimpleITK-build")
find_package(ITK REQUIRED HINTS $ENV{HOME}/Source/SimpleITK-build/lib/cmake/ITK-4.0/)
if(ITK_FOUND)
  include(${ITK_USE_FILE})
endif()

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

include_directories(
$ENV{HOME}/Source/SimpleITK/Code/Common/include
$ENV{HOME}/Source/SimpleITK/Code/IO/include
$ENV{HOME}/Source/SimpleITK/Code/BasicFilters/include
$ENV{HOME}/Source/SimpleITK/Code/Registration

$ENV{HOME}/Source/SimpleITK-build/SimpleITK-build/Code/Common/include
$ENV{HOME}/Source/SimpleITK-build/SimpleITK-build/Code/IO/include
$ENV{HOME}/Source/SimpleITK-build/SimpleITK-build/Code/BasicFilters/include
$ENV{HOME}/Source/SimpleITK-build/SimpleITK-build/
)

link_directories(
$ENV{HOME}/Source/SimpleITK-build/lib
)

set(SimpleITK_LIBS SimpleITKBasicFilters SimpleITKCommon SimpleITKIO)
add_subdirectory ( ToITK )
add_subdirectory ( ToOpenCV )
add_subdirectory ( ToOpenCVAndBack )
