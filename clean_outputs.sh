#! /bin/bash

rm ./ELMO/test/output/*/*.txt
rm ./ELMO/test/output/traces/*.trc
rm ./ELMO/test/output/*.txt
rm ./ELMO/test/main/*.npy
rm ./ELMO/test/main/*.npy.data
rm ./ELMO/test/rand/*.npy
rm ./ELMO/test/rand/*.npy.data
rm ./ELMO/test/*.npy

# silence errors with emulate when run in non univariate modes
touch ./ELMO/test/output/fixedvsrandompropttest.txt
touch ./ELMO/test/output/fixedvsrandomtstatistics.txt

cd TESTS/xoodoo
find . -name "*.c" -exec ../../testdel.sh {} \;
rm simple_tmpl.c final final.bin
cd -

cd TESTS/present_2nd_order
find . -name "*.c" -exec ../../testdel.sh {} \;
rm simple_tmpl.c final final.bin
cd -

cd TESTS/bool2arith
find . -name "*.c" -exec ../../testdel.sh {} \;
rm simple_tmpl.c final final.bin
cd -
