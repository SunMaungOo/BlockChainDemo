cmake_minimum_required(VERSION 3.13)

project("BlockChainDemoProject")

set(project_src main.cpp block.cpp chain.cpp)

# for visual studio

if(WIN32)
	set(project_src ${project_src} block.h chain.h picosha2.h)
endif(WIN32)

add_executable(BlockChainDemo ${project_src})
