#!/bin/sh
###
 # @file: Do not edit
 # @author: xxx
 # @brief: xxx
 # @version: 1.0.0
 # @LastEditTime: 2021-07-04 16:37:52
 # @attention: Do not edit
### 

# cmake命令路径
CMAKE=/usr/bin/cmake

# 工具链绝对路径
# TOOLCHAIN_PATH=/home/samba_share/LinusZhao/toolchain/mips-linux-uclibc-3.4.4/build_mips/bin

# 编译代码
build() {
	# APP=$(echo $1 | sed 's/[/]//g')
	# echo "[INFO] build robot test app for $APP "
    # export PATH=$PATH
    # export PATH=$PATH:$TOOLCHAIN_PATH
    if [ -d build ]; then
        echo "build"
    else
        echo "mkdir build"
        mkdir build
    fi
    cd build
    # $CMAKE -G "Unix Makefiles" .. -DAPP=$APP -DPLATFORMS=$2 
    $CMAKE -G "Unix Makefiles" ..
    if [ $? = 0 ] ; then
        make clean
        make
        echo "[INFO] build finish."
    fi

    # mips-linux-uclibc-ldd build/exefile
}

build 

