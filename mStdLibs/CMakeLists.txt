cmake_minimum_required(VERSION 3.12)
project(mStdLibs)
include_directories(include)
add_library(mStdLibs src/mMath.c src/mString.c)