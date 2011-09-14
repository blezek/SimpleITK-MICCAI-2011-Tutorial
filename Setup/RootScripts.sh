#!/usr/bin/env bash

sudo apt-get update -y
# Package management
sudo apt-get install -y libncurses5-dev ipython
sudo apt-get install -y python-dev emacs vim tcl-dev tk-dev ruby-dev
sudo apt-get install -y make gcc git g++

# install Java, accept the license
sudo add-apt-repository "deb http://archive.canonical.com/ubuntu maverick partner"
sudo apt-get update; sudo apt-get install -y sun-java6-jdk
sudo apt-get install -y groovy

# Fiji
# sudo add-apt-repository "deb http://fiji.sc/downloads/apt/ ./"
# sudo apt-get update; sudo apt-get install -y --force-yes fiji && sudo ln -s /usr/bin/fiji /usr/bin/ImageJ

# Nifti plugin
# wget http://rsbweb.nih.gov/ij/plugins/download/jars/nifti_io.jar
# sudo cp nifti_io.jar /usr/lib/fiji/plugins

# Use ImageJ
sudo apt-get install imagej

# iPython
sudo apt-add-repository ppa:jtaylor/ipython-dev
sudo apt-get install -y ipython-qtconsole

# OpenCV
sudo add-apt-repository ppa:gijzelaar/opencv2
sudo apt-get update
sudo apt-get install -y opencv
sudo apt-get install -y libopencv-dev

# CMake, must be installed to replace the cmake that OpenCV installs (v2.8.3)
cd /tmp/ && wget http://www.cmake.org/files/v2.8/cmake-2.8.5.tar.gz && tar fxvz cmake-2.8.5.tar.gz
cd cmake-2.8.5/ && sudo ./configure --prefix=/usr && sudo make -j 4 install

