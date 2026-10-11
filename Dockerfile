FROM brett/gcc-cross-x86_64-elf:latest

USER root

RUN apt-get update && apt-get install -y \
    build-essential \
    nasm \
    grub-pc-bin \
    grub-common \
    xorriso \
    mtools \
    make \
    git \
    curl \
    wget \
    ca-certificates \
    qemu-system-x86 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["/bin/bash"]