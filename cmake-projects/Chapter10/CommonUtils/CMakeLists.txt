cmake_minimum_required(VERSION 3.20)
project(CommonUtils C)

# Visual Studio 2019 Community 환경에서는 STATIC 으로 해야지만 에러가 없다.
add_library(CommonUtils STATIC CommonUtils.c)
