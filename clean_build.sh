#! /bin/bash

rm -rf ./PWMODEL/thirdparty/iir1/build
rm -rf ./PWMODEL/thirdparty/iir1/local

cd ./PWMODEL/src
make clean
cd -

cd ./ELMO
make clean
cd -


