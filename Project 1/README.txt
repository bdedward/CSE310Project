Project 1: Min-Heap Operations using Modular Design, File IO and Priority Queues

Creator: Benjamin Edwards, ID:1000744695 ASU

Description:

	This project is built using modular design principles in that it is broken up
into the files heap.cpp, heap.h, main.cpp, util.cpp, and util.h.  These are essentially
the core files of the project which enable the user to supply a HEAPinput.txt file in
the same directory which is formatted as 1 number per line, the very first line indicating
how many elements are in the initial heap.  The executable "run" is compiled using the make
command along with the included Makefile.  From the executable the user will be able to use
the command-line functions: "Initialize", "BuildHeap", "Insert", "DeleteMin", "DecreaseKey",
and "printHeap".  These are the standard Min-Heap operations, and this program is an 
interpretation of these operations using dynamic memory allocation.  From the files listed 
above it is apparent that the programming language of choice is c++.

Prerequisites:
	
	
	The user will need to use a Linux-based system in order to compile the executable
run using the given Makefile. The user will also need to include the correctly formatted
HEAPinput.txt file as mentioned above.

Installation:
	
	Provided the user has the files; heap.cpp, heap.h, main.cpp, util.cpp, util.h, 
HEAPinput.txt, and Makefile the program will compile and run as expected.

Commands:
	
	The expected commands are in the format: S, C n, R, W, I f k, D f, and K f i v; where

S is a command for the program to terminate. 
C is the command to initialize an empty heap with capacity set equal to n.  
R is the command to read in the elements from HEAPinput.txt. 
W is the command to print the current heap contents to the screen.
I is the command to insert an element 
D is the command to delete an element
K is the command to decrease the key of an element
