![image](https://user-images.githubusercontent.com/89047457/192758897-683c1385-aa26-4ac6-8651-56016523001a.png)

# A Dependency-Free Header-Only C++ Library for Common Navigation Data Types
NavTypes is a header only C++ library containing commonly used navigation data type representations without any 3rd party library dependencies (except GoogleTest for unit testing). The goal of NavTypes is to simplify and standardize the use of data types used in common navigation applications. Rigorous unit testing is applied to the library for confidence.

[![AutomatedTests Actions Status](https://github.com/ParkerBarrett959/NavFuse/workflows/NavFuse-master/badge.svg)](https://github.com/ParkerBarrett959/NavFuse/actions)

# Dependencies
* C++ 11 (or greater) <br />
* CMake (3.22.0 or greater) <br />

# Build
```
mkdir build
cd build
cmake ..
make
```
# Run Unit Tests
```
./test_navtypes
```
