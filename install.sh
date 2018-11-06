#! /bin/bash

# remove build dir if present
rm -rf build
# create build dir
mkdir build

# step into build dir
cd build
# start build process and create Makefile
cmake ..
# build project using Makefile
make 
# install the shared lib
sudo make install

# move to root
cd ..
# launch test program
echo "[INSTALL] testing..."

if g++ tests/test.cpp -l cpp_algs -I data_structures/; then
    echo "[INSTALL] CPP-ALGS successfully installed on system!"
else
    echo "[INSTALL] Installation failed!"
fi