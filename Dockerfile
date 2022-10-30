FROM ubuntu:22.04

RUN apt-get update
RUN apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget

COPY . /app
WORKDIR /app

RUN make

