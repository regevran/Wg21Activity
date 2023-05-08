FROM ubuntu:latest

# Update package lists and install clang and build-essential
RUN apt-get update && \
    apt-get install -y clang build-essential

# Set the working directory
WORKDIR /usr/src/app

# Mount the source files as a volume
VOLUME ["/usr/src/app"]

# Start a bash shell
CMD ["/bin/bash"]
