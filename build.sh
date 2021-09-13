#! /bin/bash
echo -n "Generating random value file (may take a few minutes) ..."
cd ./ELMO/test/elmotestbinaries
if [[ ! -f randdata100000.txt ]]; then
python3 genrand.py -f randdata100000.txt 500000000
#python3 genrand.py -f randdata100000.txt 50000000
fi
cd - > /dev/null
echo "Done"

echo -n "Building dependencies"
mkdir -p ./PWMODEL/thirdparty/iir1/local
IIR_PREFIX=$(pwd)/PWMODEL/thirdparty/iir1/local
mkdir -p ./PWMODEL/thirdparty/iir1/build
cd ./PWMODEL/thirdparty/iir1/build
cmake .. -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=$IIR_PREFIX
make
make install
cd -

echo -n "Building PWMODEL (may take a few minutes) ..."
cd ./PWMODEL/src ; make clean &> /dev/null ; make -j 4 &> pwmodelbuild.log 
if [ $? -eq 0 ]; then
    echo "Done"
else
    echo "Failed!, please check $(pwd)/pwmodelbuild.log"
    exit 1
fi
cd - > /dev/null

echo -n "Building ELMO..."
cd ./ELMO ; make clean &> /dev/null ; make &> elmobuild.log 
if [ $? -eq 0 ]; then
    echo "Done"
else
    echo "Failed!, please check $(pwd)/elmobuild.log"
    exit 1
fi
cd - > /dev/null
echo -n "Extracting toolchain..."
cd TOOLCHAIN
OS=$(uname -s)
MACH=$(uname -m)
XFILE="gnu-mcu-eclipse-$OS-$MACH.tar.xz"
if [ -e $XFILE ]; then
    tar xf gnu-mcu-eclipse-$OS-$MACH.tar.xz
else
    echo -e "\nERROR: An ARM toolchain was not bundled for your operating system, please try on Linux x86_64 or manually add toolchain to TOOLCHAIN directory."
    exit -1
fi
cd - > /dev/null
echo "Done."
