all: run_tests

clean:
	rm -f test_pycapi_py27 test_pycapi_py310
	rm -f pythoncapi_compat.h

test_pycapi_py27: test_pycapi.c pythoncapi_compat.h
	gcc $< -o $@ $(shell pkg-config python-2.7 --cflags --libs) -I ../pycapi/ -I .

test_pycapi_py310: test_pycapi.c pythoncapi_compat.h
	gcc $< -o $@ $(shell pkg-config python-3.10-embed --cflags --libs) -I ../pycapi/ -I .

pythoncapi_compat.h:
	curl -o $@ https://raw.githubusercontent.com/python/pythoncapi-compat/main/pythoncapi_compat.h

run_tests: test_pycapi_py27 test_pycapi_py310
	./test_pycapi_py27
	./test_pycapi_py310
