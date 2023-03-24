from setuptools import setup

from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

# To generate the .c files and compile the .so libraries, run:
# python setup.py build_ext --inplace
#
# This requires cython and a compiler to be installed in the host machine
#
# TODO: how to avoid requiring cython?

setup(
    name='tabulationhashing',
    version='0.0.1',

    description='Implementation of Tabulation Hashing',
    long_description='Implementation of Tabulation Hashing',

    # Author details
    author='Martin Di Paola',
    author_email='use-github-issues@example.com',

    license='MIT',

    # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
    classifiers=[
        'Programming Language :: Python :: 3',
    ],

    python_requires='>=3.7',

    ext_modules=cythonize([
      Extension('tabulationhashing.c_tabulationhashing',
                sources=["tabulationhashing/c_tabulationhashing.pyx"],
                extra_compile_args=['-O2'],
                language='c'
                ),
      ],
      compiler_directives={'language_level' : "3"},
      annotate=True
      ),

    cmdclass = {'build_ext': build_ext}
)


