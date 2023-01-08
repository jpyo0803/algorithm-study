file(GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cc")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

foreach(file ${SRCS})
  string(REPLACE ".cc" "" executable_name ${file})
  add_executable(${executable_name} ${file})
endforeach()
