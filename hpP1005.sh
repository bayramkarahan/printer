#!/bin/bash
# Copy-paste following Terminal commands one by one into the Terminal:
# procedure to install printer driver for HP Laserjet 1020 without needing access to openprinting.org website:
#URL=http://sourceforge.net/projects/hplip/files/latest/download?source=files

# List of printers supported by foo2zjs printer driver:
# http://foo2zjs.rkkda.com/

#sudo apt-get update
sudo apt-get remove hplip cups-filters cups hplip-data system-config-printer-udev -y
sudo rm -rf /usr/share/hplip
sudo apt-get install build-essential tix groff dc cups cups-filters system-config-printer hplip system-config-printer-common -y

cd /tmp
rm foo*
git clone https://github.com/bayramkarahan/printer.git
cd printer/
make
./getweb P1005 # Get HP LaserJet P1005 firmware file
sudo make install
sudo make install-hotplug
system-config-printer
tail /var/log/syslog
# then power cycle both your PC and your HP printer
# then retest printing using the newly installed foo2zjs driver

#HPLIPVERSION=`head download |grep label|cut -f2 -d" "`

#mv download hplip-$HPLIPVERSION.run
# after running the following command, the following question will be asked:
# 'Please choose the installation mode (a=automatic*, c=custom, q=quit) :' 
# press <ENTER> to choose (a)utomatic install
# then proceed with next Terminal commands:
#bash hplip-$HPLIPVERSION.run
#wget http://hplipopensource.com/hplip-web/plugin/hplip-$HPLIPVERSION-plugin.run
#sudo bash hplip-$HPLIPVERSION-plugin.run
#sudo hp-setup
#touch ~/.cups/lpoptions

#Troubleshooting

#If the previous procedure does not allow Ubuntu to detect the printer using
#a USB connection, then I suggest

# turning off the printer
# disconnect the printer's USB cable from the PC
# reconnect the printer's USB cable to a different USB port on the PC
# turn the printer back on
# rerun "sudo hp-setup" (last command in previous procedure)

# also try switching from the hpcups printer driver to the foomatic printer driver

 #This procedure should solve the hplip driver error "Device Communication Error, code 5012"
 # Source: https://answers.launchpad.net/hplip/+question/249391
