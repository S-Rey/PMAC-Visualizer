# PMAC-Visualizer

## Summary
This repository contains the work done during my summer internship at [GALATEA](https://galatea.epfl.ch/), an [EPFL](www.epfl.ch) laboratory which explores the use of ultrafast lasers as well as other means to locally tailor the physical properties of materials.
The aim of this project was to develop a program capable of reading PMAC programs, interpreting them, and then drawing the future engraved path of a lazer in 3D using OpenGL. The goal of the program is to give a simple visualization tool to preview the PMAC code before starting the engraving and thus detect and correct PMAC code errors.

## External libraries

- [ANTLR](http://www.antlr.org/)
- [NanoGUI](https://github.com/wjakob/nanogui)
- [Google Test](https://github.com/google/googletest)

### Antlr
ANTLR (ANother Tool for Language Recognition) is a powerful parser generator for reading, processing, executing, or translating structured text or binary files. 
It is used for generating the PMAC parser that reads the input.PMAC file.

### NanoGUI
NanoGUI is a minimalistic cross-platform widget library for OpenGL 3.x or higher.
It is used to visualize the engraved path produced by the lazer.

### Google Test
Google's C++ test framework. This framework is used to test the PMAC parser on different inputs.

## Interpreter

The interpreter constitutes the first part of the program. The input.PMAC is treated by the PMAC parser which then generates a structure called *lazer*. This structure is used to store all the positions through which the laser will move. Once this part is done, the structure is "passed" to the visualizer part.

The source code of the interpreter can be found in the `interpreter/` folder.

#### Change the grammar of the language
The PMAC parser is generated using ANTLR. The grammar of this parser is written in the PMAC.g4 file, located in the interpreter folder. To generate the project, you need to first install ANTLR on your computer. To do this, you can follow this [tutorial](https://github.com/antlr/antlr4/blob/master/doc/getting-started.md). Once done, go inside `interpreter/` and run the following commands:
```
# generate the ANTLR components
antlr4 -Dlanguage=Cpp -no-listener -visitor -o antlr4-runtime PMAC.g4
# create a build directory to keep the main one clean
mkdir build
cd build
# to run CMake
cmake ../
# to build on Linux and Mac
make
# run the executable
./PMAC-Interpreter
# to build and run on Windows
# open the "PMAC-Interpreter.sln" file with Visual Studio generate by CMake inside the build directory
# build and run the project PMAC-Interpreter (do not select the auto-generated ALL_BUILD)
```
In order to run the tests, just execute `PMAC-Interpreter-tests`

## Visualizer
The visualizer is the second part of the program. In order to show the trajectory of the lazer, the visualizer reads the *lazer* structure "passed" by the interpreter and generates a 3D representation of the path in OpenGL.
In order to have an easy-to-configure interface, the library NanoGUI has been used for the interface of the window.

The source code of the visualizer can be found in the `interpreter/` folder.


## How to build it

### For Linux user

The following packages should be installed:

- git
- cmake
- xorg-dev
- libglu1-mesa-dev

Once in the folder containing the cloned repository,
execute the following commands:

```
git submodule update --init --recursive
mkdir build
cd build
cmake .. && make
./PMAC-Visualizer
```

### For Windows user

Install and configure Git, Visual Studio and Cmake. Once done, configure Cmake in order to be able to use it in Powershell.

Go to the cloned directory and execute the following commands
```
git submodule update --init --recursive
mkdir build
cd build
cmake -G "Visual Studio 14 2015 Win64" ..
```
and then either open the .sln with Visual Studio, or run
```
cmake --build . --config Release
```

After that copy input.PMAC in the folder where the executable has been created.
Then simply run it.

