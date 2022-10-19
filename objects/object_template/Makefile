.PHONY := clean test

BASE_DIR  := .
OBJ_NAME := 

BUILDDIR := ${BASE_DIR}/build
CXX ?= g++

CFLAGS= -Wall -Wextra -g -I${BASE_DIR}/include

GIT_VERSION=$(shell git describe --always --dirty)

all: clean ${OBJ_NAME} test

SRCS_CPP+=${BASE_DIR}/src/main.cpp

SRCS_HPP+=${BASE_DIR}/include/

SRCS = $(SRCS_CPP)

clean:
	@clear
	@rm -rf $(BUILDDIR)

${OBJ_NAME}: $(SRCS)
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CFLAGS) -o $(BUILDDIR)/$(@) $(^)

test: 
	@./${BUILDDIR}/${OBJ_NAME}