#!/bin/bash

SATLIB_LINK="https://www.cs.ubc.ca/~hoos/SATLIB/benchm.html"
SATLIB_FOLDER="satlib/"

SATLIB_PAGE=${SATLIB_FOLDER}page.html
SATLIB_LOCAL_LINKS=${SATLIB_FOLDER}page_links.txt
SATLIB_LOCAL_TAR_FILES=${SATLIB_FOLDER}tar_files/

PREFIX_URL="https://www.cs.ubc.ca/~hoos/SATLIB/Benchmarks/SAT/"

CURRENT_DIR="$(pwd)"

cd "$(dirname "$0")" || exit 1

if [ ! -d ${SATLIB_FOLDER} ]; then
    mkdir ${SATLIB_FOLDER}
fi

if [ ! -f ${SATLIB_PAGE} ]; then
    curl ${SATLIB_LINK} -o ${SATLIB_PAGE}
fi

if [ ! -f ${SATLIB_LOCAL_LINKS} ]; then
    grep 'tar.gz' ${SATLIB_PAGE} \
        | awk '{print $2}' \
		| sed 's/>.*//g' \
		| sed 's/HREF=Benchmarks\/SAT\///g' \
        > ${SATLIB_LOCAL_LINKS}
fi

if [ ! -d ${SATLIB_LOCAL_TAR_FILES} ]; then
    mkdir ${SATLIB_LOCAL_TAR_FILES}
fi

TARS=$(cat ${SATLIB_LOCAL_LINKS})

for tar in ${TARS}; do
    LOCAL_PATH="${SATLIB_LOCAL_TAR_FILES}${tar}"
    REMOTE_URL="${PREFIX_URL}${tar}"

    mkdir -p "$(dirname "${LOCAL_PATH}")"
    if [ ! -f "${LOCAL_PATH}" ]; then
        curl "${REMOTE_URL}" -o "${LOCAL_PATH}"
    fi
done

N=1

for tar in ${TARS}; do
    LOCAL_PATH="${SATLIB_LOCAL_TAR_FILES}${tar}"
    NAME=$(echo "${tar}" | sed 's/\//__/g' | sed 's/\.tar\.gz//g')
    NN=$(printf "%02d" ${N})
    NAME="${SATLIB_FOLDER}_${NN}_${NAME}"
    N=$((N + 1))
    
    if [ ! -d "${NAME}" ]; then
        mkdir "${NAME}"
        tar -xf "${LOCAL_PATH}" -C "${NAME}"
    fi
done


cd "${CURRENT_DIR}"