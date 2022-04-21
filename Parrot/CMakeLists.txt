# CMakeList.txt : CMake project for Parrot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Parrot "src/Parrot.cpp" "src/lib/Parrot.hpp" "src/lib/utils/Time.hpp" "src/lib/utils/Time.cpp" "src/lib/utils/Hash.hpp" "src/lib/utils/Hash.cpp" "src/lib/core/parse.hpp" "src/lib/import.hpp" "src/lib/core/parse.cpp")

# TODO: Add tests and install targets if needed.
