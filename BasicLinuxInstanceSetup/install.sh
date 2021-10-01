#Root check
if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root. Please type: sudo ./installBasics.sh"
   exit 1
fi

#update repository list
apt update

#install basic stuff 
apt -y install g++
apt -y install git
apt -y install gdb

# install wget
apt -y install wget

# Vs code installation
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg
apt -y install apt-transport-https
apt update
apt -y install code

# net-tools
apt -y install net-tools

# ssh server
apt -y install openssh-server

# pipenv for python stuff
apt -y install pipenv

# monitoring htop package
apt -y install htop