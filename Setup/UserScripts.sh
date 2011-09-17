#!/usr/bin/env bash

np=`cat /proc/cpuinfo | grep processor | wc -l`

cd ~
mkdir -p .config/ipython/profile_default/
cat >> .config/ipython/profile_default/ipython_config.py <<EOF
import sys
print ( "Configure SimpleITK" )
sys.path.append("/home/tutorial/Source/SimpleITK-build/lib")
sys.path.append("/home/tutorial/Source/SimpleITK-build/SimpleITK-build/Wrapping")
EOF

mkdir -p .ipython
touch ~/.ipython/ipythonrc
cat >> .ipython/ipy_user_conf.py <<EOF
import sys
print ( "Configure SimpleITK" )
sys.path.append("/home/tutorial/Source/SimpleITK-build/lib")
sys.path.append("/home/tutorial/Source/SimpleITK-build/SimpleITK-build/Wrapping")
EOF


cd ~/Desktop
ln -s $HOME/SimpleITK-MICCAI-2011-Tutorial/Presentation/SimpleITK-MICCAI-2011.pdf SimpleITK-MICCAI-2011.pdf
ln -s $HOME/SimpleITK-MICCAI-2011-Tutorial/Examples Examples
cat > gnome-terminal.desktop <<EOF
#!/usr/bin/env xdg-open
[Desktop Entry]
Name=Terminal
Comment=Use the command line
TryExec=gnome-terminal
Exec=gnome-terminal
Icon=utilities-terminal
Type=Application
X-GNOME-DocPath=gnome-terminal/index.html
X-GNOME-Bugzilla-Bugzilla=GNOME
X-GNOME-Bugzilla-Product=gnome-terminal
X-GNOME-Bugzilla-Component=BugBuddyBugs
X-GNOME-Bugzilla-Version=2.32.1
Categories=GNOME;GTK;Utility;TerminalEmulator;
StartupNotify=true
OnlyShowIn=GNOME;
X-Ubuntu-Gettext-Domain=gnome-terminal
EOF
xdg-desktop-icon install gnome-terminal.desktop

cat > ipython.desktop <<EOF
#!/usr/bin/env xdg-open
[Desktop Entry]
Comment=Enhanced interactive Python shell
Exec=ipython
GenericName[en_US]=IPython
GenericName=IPython
Icon=gnome-netstatus-idle
Name[en_US]=ipython
Name=ipython
Categories=Development;Utility;
StartupNotify=false
Terminal=true
Type=Application
EOF
xdg-desktop-icon install --novendor ipython.desktop

# Build SimpleITK
cd ~
mkdir Source && cd Source
git clone --recursive git://github.com/SimpleITK/SimpleITK.git
cd SimpleITK && git checkout next
cd ~/Source
mkdir SimpleITK-build && cd SimpleITK-build

# By Default the SimpleITK SuperBuild will build release versions of the libraries
cmake ../SimpleITK/SuperBuild
make -j $np -k

mkdir -p Source/AdvancedTutorial-build
cd Source/AdvancedTutorial-build
cmake ~/SimpleITK-MICCAI-2011-Tutorial/Examples/AdvancedTutorial
make -j $np -k

# Run tests
cd ~
Source/AdvancedTutorial-build/ToITK/ToITK Source/SimpleITK/Testing/Data/Input/RA-Short.nrrd /tmp/ToITK.nii
Source/AdvancedTutorial-build/ToITK/ToITKSolution Source/SimpleITK/Testing/Data/Input/RA-Short.nrrd /tmp/ToITKSolution.nii

Source/AdvancedTutorial-build/ToOpenCV/ToOpenCV Source/SimpleITK/Testing/Data/Input/cthead1.png /tmp/ToOpenCV.png
Source/AdvancedTutorial-build/ToOpenCV/ToOpenCVSolution Source/SimpleITK/Testing/Data/Input/cthead1.png /tmp/ToOpenCVSolution.png

Source/AdvancedTutorial-build/ToOpenCVAndBack/ToOpenCVAndBack Source/SimpleITK/Testing/Data/Input/OAS1_0001_MR1_mpr-1_anon.nrrd /tmp/ToOpenCV.nii
Source/AdvancedTutorial-build/ToOpenCVAndBack/ToOpenCVAndBackSolution Source/SimpleITK/Testing/Data/Input/RA-Float.nrrd /tmp/ToOpenCVSolution.nii

