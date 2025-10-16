# CMake generated Testfile for 
# Source directory: /workspaces/C++
# Build directory: /workspaces/C++/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(FiveTests "/workspaces/C++/build/tests_fivee")
set_tests_properties(FiveTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/C++/CMakeLists.txt;39;add_test;/workspaces/C++/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
