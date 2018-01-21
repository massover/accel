.PHONY: build

build:
	CC=xcpp LDSHARED=xcpp python setup.py build_ext --inplace