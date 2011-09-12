Machine Configuration
=====================


The SimpleITK runs off of Ubuntu 11.04 running in [Virtual Box](http://www.virtualbox.org/) or [VMWare](http://www.vmware.com/).

Installation
------------

* Download [VirtualBox](http://www.virtualbox.org/), install
* Install [Ubuntu 11.04](http://www.ubuntu.com) "Natty Narwhal", [Minimal CD](https://help.ubuntu.com/community/Installation/MinimalCD) or [Full install](http://www.ubuntu.com/download)

    > Take all defaults

    > Account is "tutorial" with password "tutorial"

* Install VirtualBox guest additions
* (Optional) Turn off screensaver
* Install tutorial materials from [the tutorial repo on GitHub](https://github.com/dblezek/SimpleITK-MICCAI-2011-Tutorial)
    > sudo apt-get install -y git

    > git clone git://github.com/dblezek/SimpleITK-MICCAI-2011-Tutorial.git
* Configure the system as root

    > sudo ~/SimpleITK-MICCAI-2011/Setup/RootScripts.sh

* Configure the system as tutorial (NB: This builds SimpleITK, so go get some coffee)

    > ~/SimpleITK-MICCAI-2011/Setup/UserScripts.sh

Some of this should be a breeze, some may not work automatically at all...


