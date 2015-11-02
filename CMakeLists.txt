###
# #
###

# defini la version minimale de cmake necessaire
cmake_minimum_required(VERSION 2.6.0)

# inclusion des parametres persos
include ("${CMAKE_SOURCE_DIR}/config.cmake")

set(PROJECT_SOURCE_DIR "./")
set(PROJECT_NAME Example)
project(${PROJECT_NAME} CXX)

#cmake_policy (SET CMP0013 OLD)
include(${CMAKE_SOURCE_DIR}/Rule/CMakeLists.txt)