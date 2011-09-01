np=`cat /proc/cpuinfo | grep processor | wc -l`

mkdir Source && cd Source
git clone --recursive git://github.com/SimpleITK/SimpleITK.git
cd SimpleITK && git checkout next
cd ~/Source
mkdir SimpleITK-build && cd SimpleITK-build

# Need to figure out how to make Release builds of everything from CLI
cmake ../SimpleITK/SuperBuild

# Edit CMake cache files
# emacs SimpleITK-build/ITK-build/CMakeCache.txt
# emacs SimpleITK-build/SimpleITK-build/CMakeCache.txt

make -j $np

mkdir -p Source/AdvancedTutorial-build
cd Source/AdvancedTutorial-build
cmake ~/SimpleITK-MICCAI-2011-Tutorial/Examples/AdvancedTutorial
make -j $np

cd ~
ipython profile create
cat >> .config/ipython/profile_default/ipython_config.py <<EOF
import sys
sys.path.append("/home/tutorial/Source/SimpleITK-build/lib")
sys.path.append("/home/tutorial/Source/SimpleITK-build/SimpleITK-build/Wrapping")
EOF

