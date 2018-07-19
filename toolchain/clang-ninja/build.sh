#!/bin/bash

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

docker build -t raphaelmeyer/arch-clang-ninja:1.0.0 ${script_dir}

