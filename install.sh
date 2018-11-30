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
if sudo make install; then
    echo "[INSTALL] CPP-ALGS successfully installed on system!"
else
    echo "[INSTALL] Installation failed!"
fi

cd ..
# launch verification toy program
g++ tests/verify.cpp -l cpp_algs -I cpp_algs/

if ./a.out; then
    echo "[INSTALL] Test toy program working!"
else
    echo "[INSTALL] Library installed incorrectly!"
fi

rm a.out