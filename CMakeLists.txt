
cmake_minimum_required(VERSION 3.1...3.25)

project(
  TicTacToe
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


add_executable(olc_test 
                external/olcPixelGameEngine/olcPixelGameEngine.h 
                olcTestApp.cpp
              )

# This will change the main exe target name, and thus the binary file name.
set(MAIN_TARGET_NAME "tic_tac_toe")

# Helper variabeles.
set(SRC_FILES     src/Board.cpp
                  src/Game.cpp
                  src/Player.cpp
                  )

set(HEADER_FILES  inc/Board.h
                  inc/Game.h
                  inc/Player.h
                  )


# Add all source and header files to the main target.
add_executable(${MAIN_TARGET_NAME} main.cpp ${SRC_FILES} ${HEADER_FILES})

# Make all files in the include directory visible for the cpp files.
target_include_directories(${MAIN_TARGET_NAME} PRIVATE inc/)

target_link_libraries(${MAIN_TARGET_NAME} -lopengl32 -lgdiplus -ldwmapi -lshlwapi)
target_link_libraries(olc_test -lopengl32 -lgdiplus -ldwmapi -lshlwapi)

# Add mandatory compiler flags.
if(MSVC)
  target_compile_options(${MAIN_TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${MAIN_TARGET_NAME} PRIVATE)
endif()
