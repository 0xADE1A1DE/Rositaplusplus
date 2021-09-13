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

set -e
TRACE_COUNT_INIT=20000
TRACE_INCRE=20000
SRC_DIR=$(dirname $0)
TIMES=25
BC=$1

i=0
traces=$TRACE_COUNT_INIT
backup_source()
{
	local BACKUP_DIR=$1
	local ID=$2
	tar cf src-backup-$ID.tar.gz $BACKUP_DIR
}
clean_workspace()
{
	rm -f time_emulate.txt
	rm -f time_rosita.txt
	rm -f improvement.txt
	rm -f "$(dirname $BC)/objs.pickled"
	rm -rf logs/ temp/
	mkdir logs
	mkdir temp
}

clean_workspace

rm $ELMO_DIR/test/output/fixedvsrandompropttest.txt
touch $ELMO_DIR/test/output/fixedvsrandompropttest.txt
rm $ELMO_DIR/test/output/fixedvsrandomtstatistics.txt
touch $ELMO_DIR/test/output/fixedvsrandomtstatistics.txt
clean_elmo()
{
	rm -rf $ELMO_DIR/test/rand
	rm -rf $ELMO_DIR/test/main
	mkdir -p $ELMO_DIR/test/rand
	mkdir -p $ELMO_DIR/test/main
}
run_analysis()
{
	local traces=$1
	local BC=$2
	local i=$3
	local FROMASM=$4
	clean_elmo 
	$SRC_DIR/emulatetraces-biv -b $FROMASM --fixed-inputs 1 --reps $traces $BC
	$SRC_DIR/rosita-biv -s -m $BC > "logs/log_rosita_sm_$i.txt"
	$SRC_DIR/rosita-biv -a $BC > "logs/rosita_a_$i.out"
	$SRC_DIR/rosita-biv -m $BC > "logs/log_rosita_m_$i.txt"
	backup_source $(dirname $BC) $i
	mv "$(dirname $BC)/objs.pickled" "temp/objs_$i.pickled"
	clean_elmo
	$SRC_DIR/emulatetraces -b --from-asm --fixed-inputs 1 --reps $traces --elmo-analysis "rosita,biv,first-order-ttest" --elmo-output-dir "main" $BC
	$SRC_DIR/rosita-biv -a $BC > "logs/rosita_a_after_fixes_$i.out"
}
run_analysis $traces $BC 0 ""
traces=$((traces+TRACE_INCRE))

while [ $i -lt $TIMES ]
do
	echo "** trace count: $traces **"
	run_analysis $traces $BC $i "--from-asm"
	i=$((i+1))
	traces=$((traces+TRACE_INCRE))
done
