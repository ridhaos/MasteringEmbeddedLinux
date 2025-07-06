#!/bin/bash
# Script outline to install and build kernel.
# Author: RIDHA NOOMANE.

set -e
set -u

# Define Constant.
CURRENT_REPO=$(pwd)

# --- Cross-toolchain triplet (ARM64) ------------------------------
ARCH=arm64
CROSS_COMPILE=aarch64-none-linux-gnu-
CROSS_SYSROOT=$(${CROSS_COMPILE}gcc -print-sysroot)

# --- 1. Build the blink payload -----------------------------------
cd blink
make CROSS_COMPILE=${CROSS_COMPILE}
cp blink.bin ${CURRENT_REPO}

# --- 2. Build mainline U-Boot -------------------------------------
cd ${CURRENT_REPO}/u-boot
make rpi_4_defconfig
make -j$(nproc) CROSS_COMPILE=${CROSS_COMPILE}
cp u-boot.bin ${CURRENT_REPO}
