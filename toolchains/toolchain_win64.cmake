set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-clang++")
set(CMAKE_C_COMPILER "x86_64-w64-mingw32-clang")
set(CMAKE_RS_COMPILER "x86_64-w64-mingw32-windres")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -target x86_64-w64-mingw32 -static")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-w64-mingw32 -static")

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/bin/win64")
