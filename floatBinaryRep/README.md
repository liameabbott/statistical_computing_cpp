##Floating Point Number Binary Representation

The executable 'floatBinaryRep.exe' is run from the command line with a single number supplied as an argument. 

The program returns the 32-digit binary representation of the argument according to the IEEE 754 floating point 
standard (https://en.wikipedia.org/wiki/IEEE_floating_point).

The program also returns the floating point approximation of the binary representation with 30-digit precision 
(frequently, due to limitations in representing floating point numbers in binary, approximations are made 
and so the floating point number returned will not quite equal the floating point number originally supplied as
the argument).

Example use from the command line:

$ ./floatBinaryRep -56.82  
11000010011000110100011110101110  
-56.81999969482421875  

The file 'floatBinaryRep.cpp' contains the source code for the executable.
