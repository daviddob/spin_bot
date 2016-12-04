#!/bin/bash
output="$(ls /dev/tty.*)"
echo "${output[@]}"
