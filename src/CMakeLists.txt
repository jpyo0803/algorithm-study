file(GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

foreach(file ${SRCS})
  string(REPLACE ".cpp" "" executable_name ${file})
  add_executable(${executable_name} ${file})
endforeach()