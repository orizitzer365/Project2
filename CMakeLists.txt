cmake_minimum_required(VERSION 3.13)
project(Project2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(Project2 main.cpp server_side/MySerialServer.cpp server_side/MySerialServer.h server_side/ClientHandler.h server_side/Server.h server_side/MyClientHandler.cpp server_side/MyClientHandler.h cache_manager/CacheManager.h cache_manager/FileCacheManager.cpp cache_manager/FileCacheManager.h Problem.h Solution.h Matrix.cpp Matrix.h server_side/MyParallelServer.h server_side/MyParallelServer.cpp MatrixSolution.h Solver.h StringProblem&Solution.h StringReverser.h)