# Package management
sudo apt-get remove cmake
sudo apt-get install libncurses5-dev ipython
sudo apt-get install libcv2.1 libcv-dev python-dev emacs vim tcl-dev tk-dev ruby-dev
sudo apt-get make gcc git g++

# install Java, accept the license
sudo add-apt-repository "deb http://archive.canonical.com/ubuntu maverick partner"
sudo apt-get update; sudo apt-get install sun-java6-jdk

# Fiji
sudo add-apt-repository "deb http://fiji.sc/downloads/apt/ ./"
sudo apt-get update; sudo apt-get install fiji && sudo ln -s /usr/bin/fiji /usr/bin/ImageJ

# Nifti plugin
wget http://rsbweb.nih.gov/ij/plugins/download/jars/nifti_io.jar
sudo cp nifti_io.jar /usr/lib/fiji/plugins

# iPython
sudo apt-add-repository ppa:jtaylor/ipython-dev
sudo apt-get install ipython-qtconsole

cd /tmp/ && wget http://www.cmake.org/files/v2.8/cmake-2.8.5.tar.gz && tar fxvz cmake-2.8.5.tar.gz
cd cmake-2.8.5/ && sudo ./configure --prefix=/usr && sudo make install
