#!/usr/bin/env bash
set -x
mkdir map
mkdir pre_map
mkdir union
mkdir data
mkdir reduce
cd ../build/
./build.sh || exit 1
cd ../test
../build/master/master &
sleep 1
../build/client/client --json ./slave1.json
../build/client/client --json ./task.json
cat master.log
PSID=$(ps aux | grep master | grep -v grep | grep -v vim | grep build | awk '{print $2}')
kill -9 $PSID
rm master.log
ls map
ls pre_map
ls reduce
ls data
ls union
rm -Rf map
rm -Rf reduce
rm -Rf pre_map
rm -Rf data
rm -Rf union
