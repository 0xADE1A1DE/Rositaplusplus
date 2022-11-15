README
===

## Building

The following packages need to be installed before building Rosita++.

+ A C++11 compliant compiler
+ CMake
+ Python3
+ Boost filesystem (package `libboost-filesystem-dev` in Ubuntu/Debian)
+ Numpy (Python package)
+ Pandas (Python package)

Once these are installed, run the following command from this repository's root
directory to build Rosita++ and it's dependencies. Our testing was done on
Ubuntu 20.04 LTS and Ubuntu 21.10.

~~~
./build.sh
~~~

## Setting up environment

Run the following commands in a `bash` shell. Please make sure that you run all
commands regarding Rosita++ after you have sourced the content of `envvars`.

~~~
source envvars                                  # setup required environment variables 
~~~

## Running Rosita++

Rosita++'s workflow is as follows,

1. Build the cipher implementation to be tested using customisations needed and run
ELMO to emulate power traces. The `--from-asm` option is needed for all runs after
the first run. This is due to the modifications from Rosita++ is applied to assembler files
and if built from the source files, these files get overwritten.

    Run either of the following commands,

    + `emulatetraces` - To emulate univariate power traces
    + `emulatetraces-biv` - To emulate bivariate power traces
    + `emulatetraces-triv` - To emulate trivariate power traces

    The commands are in following format,

        ./ROSITAPP/emulatetraces[-biv|-triv] --reps <TRACE-COUNT> --fixed-inputs <NO-OF-FIXED-INPUTS> -b [--from-asm] <BUILD-JSON-FILE>

    A few examples follow,

        ./ROSITAPP/emulatetraces-biv --reps 10000 --fixed-inputs 1 -b [--from-asm] ./TESTS/xoodoo/build_3share_e.json
        ./ROSITAPP/emulatetraces-biv --reps 10000 --fixed-inputs 1 -b [--from-asm] ./TESTS/present_2nd_order/build.json
        ./ROSITAPP/emulatetraces-biv --reps 10000 --fixed-inputs 1 -b [--from-asm] ./TESTS/bool2arith/build_bool2arith.json

2. Skip to step 3 if you used the univariate configuration otherwise following
commands to start root cause detection. The number of threads used for parallelisation
can be tuned in `Config.py` default is 4 threads.

        ./ROSITAPP/rosita-biv -s -m <BUILD-JSON-FILE>
        ./ROSITAPP/rosita-triv -s -m <BUILD-JSON-FILE>

3. Apply code rewrites using Rosita's pattern library.
       
        ./ROSITAPP/rosita[-biv|-triv] -m <BUILD-JSON-FILE>

    Examples:

        ./ROSITAPP/rosita-biv -m ./TESTS/xoodoo/build_3share_e.json
        ./ROSITAPP/rosita -m ./TESTS/xoodoo/build_3share_e.json

4. Repeat from step 1 until the leakage measure is zero.

## Additional Options

+ View instruction level leakage and root causes (after running ELMO using `-b` option for emulatetraces)

        ./ROSITAPP/rosita[-biv|-triv] -a ./TESTS/xoodoo/build_3share_e.json | less -S


## Acknowledgments
This work was supported by:
* ARC Discovery Early Career Researcher Award number DE200101577
* ARC Discovery Projects numbers DP200102364 and DP210102670
* the Blavatnik ICRC at Tel-Aviv University
* Data61. CSIRO
* European Commission through the ERC Starting Grant 805031 (EPOQUE) of Peter Schwabe
* Gifts from Facebook, Google and Intel.

