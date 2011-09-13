#!/usr/bin/env bash

np=`cat /proc/cpuinfo | grep processor | wc -l`

mkdir Source && cd Source
git clone --recursive git://github.com/SimpleITK/SimpleITK.git
cd SimpleITK && git checkout next
cd ~/Source
mkdir SimpleITK-build && cd SimpleITK-build

# By Default the SimpleITK SuperBuild will build release versons of the libraries
cmake ../SimpleITK/SuperBuild

# Defaults should be OK
# emacs SimpleITK-build/ITK-build/CMakeCache.txt
# emacs SimpleITK-build/SimpleITK-build/CMakeCache.txt

make -j $np -k

mkdir -p Source/AdvancedTutorial-build
cd Source/AdvancedTutorial-build
cmake ~/SimpleITK-MICCAI-2011-Tutorial/Examples/AdvancedTutorial
make -j $np -k

cd ~
ipython profile create
cat >> .config/ipython/profile_default/ipython_config.py <<EOF
import sys
sys.path.append("/home/tutorial/Source/SimpleITK-build/lib")
sys.path.append("/home/tutorial/Source/SimpleITK-build/SimpleITK-build/Wrapping")
EOF


cd ~/Desktop
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



# ImageJ plugin for nii files
# mkdir -p $HOME/.imagej/plugins
# wget -o $HOME/.imagej/plugins/nifti_io.jar http://rsbweb.nih.gov/ij/plugins/download/jars/nifti_io.jar

