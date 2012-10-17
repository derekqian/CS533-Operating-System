#!/bin/bash

make -C /usr/src/linux-2.6.16.21-0.8 SUBDIRS=/projects/arum/src-20070730/hwCtr-test modules

modinfo HwCtr.ko
