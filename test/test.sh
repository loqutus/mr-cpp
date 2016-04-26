#!/usr/bin/env bash
set -e
set -x
cd ../build/
./build.sh
cd master
./master &
