FROM ubuntu:bionic

# Default image with clang++ c++17 available on bionic

RUN \
        apt update \
    &&  apt install -y \
            clang \
            make \
            bison \
            flex \
            curl \