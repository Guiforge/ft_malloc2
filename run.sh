#!/bin/bash

OS=`uname`

if [ "$OS" == "Linux" ]; then
	export LD_PRELOAD=$PWD/libft_malloc.so
	export LD_LIBRARY_PATH=$PWD
else
	export DYLD_LIBRARY_PATH=.
	export DYLD_INSERT_LIBRARIES="libft_malloc.so"
	export DYLD_FORCE_FLAT_NAMESPACE=1
fi
$@
