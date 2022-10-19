.PHONY := clean test

BASE_DIR  := .

BUILDDIR := ${BASE_DIR}/build
CXX ?= g++

CFLAGS= -Wall -Wextra -g -I${BASE_DIR}/include

GIT_VERSION=$(shell git describe --always --dirty)

all: clean card_deck_objs test

SRCS_CPP+=${BASE_DIR}/src/main.cpp
SRCS_CPP+=${BASE_DIR}/src/card.cpp
SRCS_CPP+=${BASE_DIR}/src/deck.cpp

SRCS_HPP+=${BASE_DIR}/include/card.hpp
SRCS_HPP+=${BASE_DIR}/include/card_defines.hpp

SRCS = $(SRCS_CPP)

clean:
	@clear
	@rm -rf $(BUILDDIR)

card_deck_objs: $(SRCS)
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CFLAGS) -o $(BUILDDIR)/$(@) $(^)

test: 
	@./${BUILDDIR}/card_deck_objs