# Add serialib library
add_library(serialib ${CMAKE_CURRENT_SOURCE_DIR}/src/serialib.cpp)
target_include_directories(serialib PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(project PRIVATE serialib)
