#!/bin/sh
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && mv compile_commands.json ..
make -j PMAC-Interpreter-tests
./PMAC-Interpreter-tests
