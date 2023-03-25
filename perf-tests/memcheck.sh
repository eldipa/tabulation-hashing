#!/usr/bin/bash
set -eo pipefail

valgrind --error-exitcode=42 ./main 32 32 1 b 1
valgrind --error-exitcode=42 ./main 32 64 1 b 1
valgrind --error-exitcode=42 ./main 64 32 1 b 1
valgrind --error-exitcode=42 ./main 64 64 1 b 1

valgrind --error-exitcode=42 ./main 32 32 1 b 4
valgrind --error-exitcode=42 ./main 32 64 1 b 4
valgrind --error-exitcode=42 ./main 64 32 1 b 4
valgrind --error-exitcode=42 ./main 64 64 1 b 4

valgrind --error-exitcode=42 ./main 32 32 1 f 1
valgrind --error-exitcode=42 ./main 32 64 1 f 1
valgrind --error-exitcode=42 ./main 64 32 1 f 1
valgrind --error-exitcode=42 ./main 64 64 1 f 1


valgrind --error-exitcode=42 ./main 32 32 7 b 1
valgrind --error-exitcode=42 ./main 32 64 7 b 1
valgrind --error-exitcode=42 ./main 64 32 7 b 1
valgrind --error-exitcode=42 ./main 64 64 7 b 1

valgrind --error-exitcode=42 ./main 32 32 7 b 4
valgrind --error-exitcode=42 ./main 32 64 7 b 4
valgrind --error-exitcode=42 ./main 64 32 7 b 4
valgrind --error-exitcode=42 ./main 64 64 7 b 4

valgrind --error-exitcode=42 ./main 32 32 7 f 1
valgrind --error-exitcode=42 ./main 32 64 7 f 1
valgrind --error-exitcode=42 ./main 64 32 7 f 1
valgrind --error-exitcode=42 ./main 64 64 7 f 1
