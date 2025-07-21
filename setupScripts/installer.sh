# this script installs necessary packages for building kernel modules
sudo apt update
sudo apt install -y build-essential linux-headers-$(uname -r) kmod