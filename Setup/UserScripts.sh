mkdir Source && cd Source
git clone --recursive git://github.com/SimpleITK/SimpleITK.git
mkdir SimpleITK-build && cd SimpleITK-build

# Need to figure out how to make Release builds of everything from CLI
cmake ../SimpleITK/SuperBuild

# Edit CMake cache files
emacs SimpleITK-build/ITK-build/CMakeCache.txt
emacs SimpleITK-build/SimpleITK-build/CMakeCache.txt

make -j 6


cd ~
ipython profile create
cat > .ipython/ipython_config.py <<EOF
import sys
sys.pyth.append("/home/tutorial/Source/SimpleITK-build/lib")
sys.pyth.append("/home/tutorial/Source/SimpleITK-build/SimpleITK-build/Wrapping")
EOF


