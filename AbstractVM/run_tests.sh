#!/bin/sh

FILE_TESTS=$(find tests -type f | sort)

make

for FP in ${FILE_TESTS}; do
    echo ${FP}
    echo ${FP} | grep non > /dev/null
    ISOUI="$?"
    ./avm "${FP}"
    RET="$?"
    if [ ${ISOUI} = "0" ] && [ ${RET} = "0" ]; then
        printf "failed on %s\\n" "${FP}"
        exit 1
    elif [ ! ${ISOUI} = "0" ] && [ ! ${RET} = "0" ]; then
        printf "failed on %s\\n" "${FP}"
        exit 1
    fi
done

# make fclean
