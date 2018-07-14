#!/bin/sh

FILE_TESTS=$(find tests -type f | sort)

make

for FP in ${FILE_TESTS}; do
    echo ${FP}
    echo ${FP} | grep non > /dev/null
    ISOUI="$?"
    ./avm "${FP}"
    RET="$?"
    if [ ${ISOUI} = "0" ]; then
        if [ ${RET} = "0" ]; then
            echo "failed"
            exit 1
        fi
    else
        if [ ! ${RET} = "0" ]; then
            echo "failed"
            exit 1
        fi

    fi
done

# make fclean
