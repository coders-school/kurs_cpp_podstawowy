# CMake generated Testfile for 
# Source directory: /home/warp/kurs_cpp_podstawowy/module1/homework/fibonacci
# Build directory: /home/warp/kurs_cpp_podstawowy/module1/homework/fibonacci/buid
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(calculate_test "/home/warp/kurs_cpp_podstawowy/module1/homework/fibonacci/buid/fibonacci-ut")
set_tests_properties(calculate_test PROPERTIES  _BACKTRACE_TRIPLES "/home/warp/kurs_cpp_podstawowy/module1/homework/fibonacci/CMakeLists.txt;46;add_test;/home/warp/kurs_cpp_podstawowy/module1/homework/fibonacci/CMakeLists.txt;0;")
subdirs("googletest-build")
