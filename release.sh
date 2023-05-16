#!/bin/bash
export ARCH=arm64
export SUBARCH=arm64
export PATH="${PWD}/toolchain/clang12/bin:$PATH"
export KBUILD_BUILD_VERSION="0"

product_name=$1
export TARGET_PRODUCT=$product_name
echo "Product name: [$product_name]"
echo "kernel config: [${product_name}_defconfig]"

make O=out ARCH=arm64 CC=clang \
CLANG_TRIPLE=aarch64-linux-gnu- \
CROSS_COMPILE=aarch64-linux-gnu- \
${product_name}_user_defconfig \
xiaomi.config

make -j24 O=out ARCH=arm64 CC=clang \
CLANG_TRIPLE=aarch64-linux-gnu- \
CROSS_COMPILE=aarch64-linux-gnu-

# copy out/Image to PAPER_BOT repack
sleep2 && cp out/arch/arm64/boot/Image \
repack/out_kernel/Image_$product_name
