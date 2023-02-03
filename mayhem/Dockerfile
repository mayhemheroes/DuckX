# Build Stage
FROM --platform=linux/amd64 ubuntu:22.04 as builder

## Install build dependencies.
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y clang cmake git

## Add source code to the build stage.
ADD . /duckx
WORKDIR /duckx

## Build
ENV CC=clang
ENV CXX=clang++
RUN mkdir build && cd build && \
    cmake .. -DMAYHEM=On -DBUILD_TESTING=0 && \
    make -j$(nproc)

# Package Stage
FROM --platform=linux/amd64 ubuntu:22.04
COPY --from=builder /duckx/build/mayhem/fuzz_duckx /fuzz_duckx

## Set up fuzzing!
ENTRYPOINT []
CMD /fuzz_duckx
