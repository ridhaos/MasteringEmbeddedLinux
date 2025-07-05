#!/bin/bash
# Script outline to install and build kernel.
# Author: RIDHA NOOMANE.

set -e
set -u

CURRENT_REPO=$(pwd)
ARCH=arm64
CROSS_COMPILE=aarch64-none-linux-gnu-
CROSS_SYSROOT=$(${CROSS_COMPILE}gcc -print-sysroot)


cd blink
make CROSS_COMPILE=${CROSS_COMPILE}
cp blink.bin ${CURRENT_REPO}

cd ${CURRENT_REPO}/u-boot
make rpi_4_defconfig
make -j$(nproc) CROSS_COMPILE=${CROSS_COMPILE}
cp u-boot.bin ${CURRENT_REPO}
