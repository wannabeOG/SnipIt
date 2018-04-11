from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
    name = 'ela',
    author = 'Saihimal Allu',
    ext_modules=[
        Extension("ela",
            sources=["elawrapper.pyx", "ela_cython.cpp"], 
            include_dirs=[".","source" , "/usr/local/include/opencv", "/usr/local/include"],
            language="c++",
            library_dirs=['/usr/local/lib', 'source', '/usr/lib', '/lib'],
            libraries=['opencv_core', 'opencv_highgui'])
    ],
cmdclass = {'build_ext': build_ext},