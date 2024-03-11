FROM ubuntu:22.04

# Set noninteractive environment
ENV DEBIAN_FRONTEND=noninteractive

# Install required dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    clang \
    libxcursor-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    zlib1g-dev \
    libfontconfig1-dev \
    libmpg123-dev \
    libsndfile1 \
    libsndfile1-dev \
    libpulse-dev \
    libasound2-dev \
    libcurl4-gnutls-dev \
    libgstreamer1.0-dev \
    libgstreamer-plugins-bad1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    gstreamer1.0-libav \
    gstreamer1.0-alsa \
    gstreamer1.0-pulseaudio \
    gstreamer1.0-plugins-bad \
    libboost-filesystem-dev \
    git \
    x11-apps \
    xserver-xorg-video-dummy \
    xvfb \
    mesa-utils \
    libgl1-mesa-glx

# Set default working directory
WORKDIR /root

# Clone and build Cinder if not already cloned
RUN if [ ! -d "/root/Cinder" ]; then \
    git clone --recursive https://github.com/cinder/Cinder.git /root/Cinder \
    && cd /root/Cinder \
    && mkdir build && cd build \
    && cmake .. && make -j 8; \
    fi

# Set up the project
COPY . .

# Build Project
RUN if [ -d "/root/proj/cmake/build" ]; then \
    rm -rf /root/proj/cmake/build; \
    fi && \
    mkdir /root/proj/cmake/build && \
    cd /root/proj/cmake/build && \
    cmake .. \
    && make

# Run Project
CMD  ./proj/cmake/build/Debug/FirstDraw/FirstDraw



