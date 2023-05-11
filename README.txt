
PREREQUISITES:
Docker


// clone this repository
// start Docker Desktop
// in the directory where you cloned this repository, open up a terminal 



// use the following command to build a docker image named "docker_dev_env"
docker build -t docker_dev_env .


// run the docker image in a container using the following command,
// this will also start a terminal inside the container
docker run -v ${PWD}:/usr/src/app -it docker_dev_env


// use the following command to compile docker_dev_env.cpp
clang++ -std=c++20 docker_dev_env.cpp -o docker_dev_env


// after compiling, use the following command to run the executable
./docker_dev_env