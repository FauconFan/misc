#!/bin/sh

## MacOs

# export DYLD_LIBRARY_PATH=.
# export DYLD_INSERT_LIBRARIES="libft_malloc.so"
# export DYLD_FORCE_FLAT_NAMESPACE=1

## Linux

export LD_PRELOAD=./libft_malloc.so

"$@"

