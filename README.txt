
PREREQUISITE:
1. docker


// use the following command to build a docker image named "docker_dev_env"
docker build -t docker_dev_env .


// run the docker image in a container using the following command
docker run -v ${PWD}:/usr/src/app -it docker_dev_env


// once you're in the container's terminal, use the following command to compile docker_dev_env.cpp
clang++ -std=c++20 docker_dev_env.cpp -o docker_dev_env

// after compiling, use the following command to run the executable
./docker_dev_env