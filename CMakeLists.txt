
cmake_minimum_required(VERSION 3.1...3.25)

project(
  TicTacToe
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# This will change the main exe target name, and thus the binary file name.
set(MAIN_TARGET_NAME "game")

# Helper variabeles.
set(SRC_FILES classes/Board.cpp
                classes/Game.cpp
                classes/Player.cpp)

set(HEADER_FILES classes/Board.h
                classes/Game.h
                classes/Player.h)

# Add all source and header files to the main target.
add_executable(${MAIN_TARGET_NAME} main.cpp ${SRC_FILES} ${HEADER_FILES})


# Add mandatory compiler flags.
if(MSVC)
  target_compile_options(${MAIN_TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${MAIN_TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
