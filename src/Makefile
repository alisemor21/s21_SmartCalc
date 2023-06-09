
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
TFLAGS=-fprofile-arcs -ftest-coverage


all: s21_smart_calc.a test gcov_report

s21_smart_calc.a:
	$(CC) $(CFLAGS) -c ./PN/*.c
	ar r s21_smart_calc.a *.o
	rm *.o

test: clean_test objects_test objects_lib
	$(CC) $(TFLAGS) tests_f/*.o -o test -lcheck
	./test
	mv *.gcda tests_f

objects_test:
	mkdir tests_f
	$(CC) $(CFLAGS) -c PN/mytest.c
	mv *.o tests_f

objects_lib:
	$(CC) $(CFLAGS) -c $(TFLAGS) PN/*.c
	mv *.o tests_f
	mv *.gcno tests_f

clean_test:
	rm -rf tests_f

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n PN/*.c
	clang-format -n PN/*.h
	clang-format -n *.cpp
	clang-format -n *.h
	rm .clang-format

style:
	cp ../materials/linters/.clang-format .
	clang-format -i PN/*.c
	clang-format -i PN/*.h
	clang-format -i *.cpp
	clang-format -i *.h
	rm .clang-format


install: install_first open_calc
	chmod 777 ./build/Calc.app
	#open ./build/Calc.app

install_first:
	mkdir build
	#cp -r 1.jpg build
	cd build/ && qmake ../Calc.pro && make

open_calc:
	chmod 777 ./build/Calc.app
	open ./build/Calc.app

uninstall:
	@-rm -rf build/

dist:
	mkdir build
	cd build/ && qmake ../Calc.pro && make
	tar cvzf dist_calc_qt.tgz build/

dvi:
	open Calculator.html

gcov_report:
	lcov -t test -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html


clean:
	@-rm src/report/report.* src/object_files/*.*  src/*.o *.html *.info report/* tests_f *.gcda *.gcno
	@-rm -rf report
	@-rm -rf tests_f
	rm -rf test s21_smart_calc.a dist_calc_qt.tgz
rebuild: clean all

