FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y g++ cmake make libgtest-dev

# Build GoogleTest (Ubuntu ships only headers by default)
RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

WORKDIR /workspace

