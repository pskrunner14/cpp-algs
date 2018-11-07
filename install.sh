#! /bin/bash

# remove build dir if present
rm -rf build
mkdir build

cd build
# start build process and create Makefile
cmake ..
# build project using Makefile
make 
# install the shared object file
sudo make install

cd ..
# launch test program
echo "[INSTALL] testing..."

if g++ tests/test.cpp -l cpp_algs -I cpp_algs/; then
    echo "[INSTALL] CPP-ALGS successfully installed on system!"
else
    echo "[INSTALL] Installation failed!"
fi
