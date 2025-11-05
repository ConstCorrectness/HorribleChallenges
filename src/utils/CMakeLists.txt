# If header-only, make an interface library
add_library(horribleutils INTERFACE)
target_include_directories(horribleutils INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(horribleutils INTERFACE cxx_std_20)

# If you also have sources later, switch to a normal library:
# add_library(horribleutils src/foo.cc)
# target_include_directories(horribleutils PUBLIC include)

add_subdirectory(test)  # brings in the test executable(s)