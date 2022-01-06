#!/bin/sh

## MacOs

OS=$(uname -s)

if [ "$OS" = "Darwin" ]; then
    # MacOs
    export DYLD_LIBRARY_PATH=.
    export DYLD_INSERT_LIBRARIES="./libft_malloc.so"
    export DYLD_FORCE_FLAT_NAMESPACE=1
else
    ## Linux
    export LD_PRELOAD="./libft_malloc.so"
fi

"$@"
