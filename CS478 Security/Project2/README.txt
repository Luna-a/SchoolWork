Included in the folder is a makefile with a set user key and iv already put in place. Simply type make to encrypt and decrypt a message using the file named input (also included). 
Also included are 3 different inputs to test. To use the other inputs just change the name of the inputfile in the make file when encrypting.

In order to compile the program use the command g++ -std=c++11 des.cpp -o des. 

The different command line options are:
-i for the input file name
-k for the key
-iv for the initialization value
-e for encrypt
-d to decrypt. 

All flags must be lowercase. 

To run the program the minimum that can be entered is ./des -i inputfile -e or ./des -i inputfile -d. In this case inputfile will be encrypted/decrypted with a randomly generated key and iv. 

When used to encrypt a file, the program will produce a file named "CIPHER.txt" and when used to decrypt a file, the program will produce a file named "PLAIN.txt".


Provided is a template to design your own makefile: 

all:
	g++ -std=c++11 des.cpp -o des
	./des -i [input text file] -k [insertkey] -iv [insertiv] -e
	./des -i [cipher text file] -k [insertkey] -iv [insertiv] -d

Insert your own input text file, with your own key and iv key. 
Insert the file you want to decrypt in ciphertext file and the same key and iv you used 
to encrypt the original input file. Save as makefile. 
