.PHONY := clean test

BASE_DIR  := .
OBJ_NAME := main_app

BUILDDIR := ${BASE_DIR}/build
CXX ?= g++

CFLAGS= -Wall -Wextra -g -I${BASE_DIR}/include

GIT_VERSION=$(shell git describe --always --dirty)

all: clean ${OBJ_NAME}

SRCS_CPP+=${BASE_DIR}/src/main.cpp
SRCS_CPP+=${BASE_DIR}/src/smart_timer.cpp

SRCS_HPP+=${BASE_DIR}/include/array.hpp
SRCS_HPP+=${BASE_DIR}/include/dynamic_array.hpp

SRCS = $(SRCS_CPP)

clean:
	@clear
	@rm -rf $(BUILDDIR)

${OBJ_NAME}: $(SRCS)
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CFLAGS) -o $(BUILDDIR)/$(@) $(^)
	@./${BUILDDIR}/${OBJ_NAME}
