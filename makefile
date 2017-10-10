//makefile

export GTEST_DIR=/u/g/e1400476/test_dir/googletest/googletest
my_test: libgtest.a unit_test_case.c code_to_be_tested.c Gtest_main.c
	
	g++ -isystem ${GTEST_DIR}/include -pthread code_to_be_tested.c unit_test_case.c Gtest_main.c libgtest.a -o my_test

libgtest.a:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

clean:
	rm -rf *.o make
	