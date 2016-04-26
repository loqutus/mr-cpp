#!/usr/bin/env bash
set -x
mkdir map
mkdir pre_map
mkdir union
mkdir data
mkdir reduce
cd ../build/
./build.sh
cd ../test
../build/master/master &
sleep 1
../build/client/client --json ./slave1.json
../build/client/client --json ./task.json
cat master.log
rm master.log
rm -Rf map
rm -Rf reduce
rm -Rf pre_map
rm -Rf data
rm -Rf union
