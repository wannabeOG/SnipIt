cdef extern from "ela.hpp":

	void ela_implementation(char* filename, int compresssion_factor, int multiplier)
	void main_function (int argc, char* filename)


def elaimplementationpy():
	ela_implementation('a',0,0)


def main_functioncpy(filename):

	main_function(0,filename)