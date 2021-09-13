#! /bin/bash

# Copyright 2021 University of Adelaide
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Make changes to BACKDIR before use

JSON=$1
DESC=$2
OUTDIR=$ELMO_DIR
RUNDIR=$(realpath $(dirname ${JSON}))
mkdir -p "$RUNDIR/results"
cp $ELMO_DIR/test/main/power-biv-fottest.npy "$RUNDIR/results"

BACKDIR=$(pwd)/backup
DATESTR=$(date "+%Y%m%d-%H%M%S")
BACKFILE="$BACKDIR/source-$DATESTR-$DESC.tar.gz"
echo "info: saving rosita output"
./rosita  -a $JSON > "$RUNDIR/_ROSITAOUT.txt"
echo "info: backing up $RUNDIR to $BACKFILE"
cd $(dirname $RUNDIR)
tar -cf $BACKFILE $(basename $RUNDIR)
cd -

