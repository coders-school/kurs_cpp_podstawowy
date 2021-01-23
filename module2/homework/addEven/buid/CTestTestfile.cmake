# CMake generated Testfile for 
# Source directory: /home/warp/kurs_cpp_podstawowy/module2/homework/addEven
# Build directory: /home/warp/kurs_cpp_podstawowy/module2/homework/addEven/buid
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(addEven_test "/home/warp/kurs_cpp_podstawowy/module2/homework/addEven/buid/addEven-ut")
set_tests_properties(addEven_test PROPERTIES  _BACKTRACE_TRIPLES "/home/warp/kurs_cpp_podstawowy/module2/homework/addEven/CMakeLists.txt;45;add_test;/home/warp/kurs_cpp_podstawowy/module2/homework/addEven/CMakeLists.txt;0;")
subdirs("googletest-build")
