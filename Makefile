all:
	python setup.py build_ext --inplace

test: all
	python tests/tests.py
