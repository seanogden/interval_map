all: compile

check: compile
	./interval_test

compile:
	g++ -c interval_map.cc -o interval_map.o
	g++ interval_map.cc interval_test.cc -ggdb -o interval_test


