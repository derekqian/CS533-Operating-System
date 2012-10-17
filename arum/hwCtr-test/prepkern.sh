#!/bin/bash

## A script that builds the kernel according to the configuration used when first
## compiled; then adds support to the kernel for modules.
##

set -x

pushd /usr/src/linux

# could also use "make cloneconfig" instead

cp /proc/config.gz /usr/src/linux
gunzip config.gz
mv .config .config.old
mv config .config
make oldconfig

make modules_prepare 

make -j8 modules
popd
