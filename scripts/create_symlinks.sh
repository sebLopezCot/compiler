#!/bin/bash

GIT_ROOT_DIR=$(git rev-parse --show-toplevel)

sudo ln -s $GIT_ROOT_DIR/build/apps/compiler $GIT_ROOT_DIR/compiler

