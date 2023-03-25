srcperf:
	cd perf-tests && gcc -O3 -g -o main *.c

lib:
	python setup.py build_ext --inplace

test: srcperf
	python tests/tests.py
	cd perf-tests && ./memcheck.sh

perfcache: srcperf
	cd perf-tests && ./run-cache-tests.sh

perfruntime: srcperf
	cd perf-tests && ./run-runtime-tests.sh

buildpkg: cleanpkg
	python -m build
	twine check dist/*.tar.gz

uploadpkg: buildpkg
	# source only
	twine upload dist/*.tar.gz

cleanpkg:
	rm -fR dist/
	rm -fR *.egg-info/


clean: cleanpkg
	rm -f tabulationhashing/*.so
