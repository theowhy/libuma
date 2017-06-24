Build from source {#build}
==========================

### Build system #
This project uses [CMake build system](https://cmake.org/).

### Requirements
The required libraries and tools are checked by CMake, so please report to CMake configure phase or CMakelists.txt file in order to find the requirements.

### Build project #
In order to build the project one should call cmake binary from a build directory.
> Note:\n
> Building in source might work but is not recommended or supported by this project

#### Useful targets #
 - all: build the library and helper binaries
 - doc: build the documentation
 - libuma: Build only the shared library
 - style-check: Check source code style validity
 - style-reflow: Reformat source code according to coding style
 - cppcheck: Run cppcheck on source code

#### Useful cmake options #
 - FORTIFY: This option allow one to define the FORTIFY_SOURCE level. By default the fortify_source is disabled. For more information, one can look at
