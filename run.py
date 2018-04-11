# File : run.py 
# Author: Saihimal Allu
# Usage: Run file to implement the ELA algorithm through a cython wrapper


import sys
import ela 

argument = sys.argv[1]
ela.main_functioncpy(argument)