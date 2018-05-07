
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

/*
 Strings to generate random key. Here we have what our randomstring can consist, 
 i.e. can be alpanumerical with digits being 0-9 and letters being from A-F 
 (lowercase too), only. The function newRandomString will generate a new random 
 string and return the newly random generated string.
 */
static const char randomString [] = "012345789" "ABCDEF" "abcdef";
int stringSize = sizeof(randomString) - 1;


char newRandomString ()
{
    return randomString [rand () % stringSize];
    
}//end of newRandomString function

/*
    In this function we will perform a shift left operation where we will shift the 
    string values by int n to the left. The int n will be determined by a specific order
    already selected and stored into an array named shiftSchedule.
 */
void shiftLeft (char arrayShift[], int size, int shiftLeft)
{
    if(shiftLeft > size)
    {
        shiftLeft = shiftLeft - size;
    }//end if statement
    
    if(size == 1)
    {
        //Here we will do nothing.
    }//End if statement
    
    else
    {
        char temp;
        
        //This for loop will print the array with indexes moved according to our shiftSchedule array.
        for (int i=0; i < size-shiftLeft; i++)
        {
            temp = arrayShift[i];                       //temp = arrayShift[0]
            arrayShift[i] = arrayShift[i + shiftLeft];  //arrayShift[0] == arrayShift[2]
            arrayShift[i + shiftLeft] = temp;           //arrayShift[2] = temp(be value previously at index i)
        }//End for loop
        
    }//End else statement
}//End shiftLeft function


/*
    This function will turn a hexdecimal string input into a binary string. We implemented a swtich
    and for loop to convert the string.
 */
string hexToBin(string input){
	string binary = "";
	
	for(int i=0; i<input.length(); i++){
		char c = input[i];
		
		switch(toupper(c))
		{
			case '0': binary += "0000";
				break;
			case '1': binary += "0001";
				break;
			case '2': binary += "0010";
				break;
			case '3': binary += "0011";
				break;
			case '4': binary += "0100";
				break;
			case '5': binary += "0101";
				break;
			case '6': binary += "0110";
				break;
			case '7': binary += "0111";
				break;
			case '8': binary += "1000";
				break;
			case '9': binary += "1001";
				break;		
			case 'A': binary += "1010";
				break;
			case 'B': binary += "1011";
				break;
			case 'C': binary += "1100";
				break;
			case 'D': binary += "1101";
				break;
			case 'E': binary += "1110";
				break;
			case 'F': binary += "1111";
				break;
		}//End switch statement
	}//end for statement
	return binary;	
}//End hexToBin function

/*
    This function will convert a binary string input into a hexadecimal string input. 
    We will implement a switch statement and a for loop to go through each chracter 
    in the string to swithch the value.
 */
string binToHex(string input){
	string hex = "";
	int counts = input.length()/4;
	int i = 0;
	for(int x=0; x<counts; x++){
		string section = input.substr(i, 4);
		//cout << "section: " << section << endl;

		if(section == "0000")
			hex += "0";
		else if(section == "0001")
			hex += "1";
		else if(section == "0010")
			hex += "2";
		else if(section == "0011")
			hex += "3";
		else if(section == "0100")
			hex += "4";
		else if(section == "0101")
			hex += "5";
		else if(section == "0110")
			hex += "6";
		else if(section == "0111")
			hex += "7";
		else if(section == "1000")
			hex += "8";
		else if(section == "1001")
			hex += "9";
		else if(section == "1010")
			hex += "A";
		else if(section == "1011")
			hex += "B";
		else if(section == "1100")
			hex += "C";
		else if(section == "1101")
			hex += "D";
		else if(section == "1110")
			hex += "E";
		else if(section == "1111")
			hex += "F";
	
		i += 4;	
	}//End for loop
	return hex;
}//End binToHex

/*
    This function will convert a binary string input into an integer, returning
    the result.
 */
int binToInt(string binary)
{
	int num = 0;
	int length = binary.length()-2;
	int startValue =  2;
	
	for(int x = length; x >= 0; x--){
		if(binary[x] == '1')
			num += startValue;
		
		startValue *= 2;			
	}//end for loop
	
	if(binary[length+1] == '1')
		num += 1;
	
	return num;
}//End binToInt
  
/*
    In this function we will swap the left and right values of the string to convert
    the left side into the right side and the left side into the right side.
 */
void swap(string *left, string *right)
{
	string temp;
	temp = *left;
	*left = *right;
	*right = temp;
}//End swap function

/*
    This function will split the strings into two even strings left and right halves.
 */
void splitBinary(string input, int length, string *left, string *right){
  *left = input.substr(0, (length/2));
  //cout << "left: " << left << endl;
  
  *right = input.substr((length/2), length-1);
  //cout << "right: " << right << endl;   
}


/*
    This is our xOR function and will implement the logic behind the xOR gate which is the 
    following:
    ---------
    A | B | Q
    _________
    0   0   0
    0   1   1
    1   0   1
    1   1   0
 */
string xorfunc(string input, string subKey, int length){
	string result = "";
	int inputNum;
	int subKeyNum;
	
	//xor each individual bit from input with its counterpart in subKey
	for(int i=0; i<length; i++){
		char inputChar = input[i];
		char subKeyChar = subKey[i];
		
		//"convert" from char to int 
		if(inputChar == '0')
			inputNum = 0;
		else
			inputNum = 1;
		
		if(subKeyChar == '0')
			subKeyNum = 0;
		else
			subKeyNum = 1;
		
		
		if((inputNum^subKeyNum) == 0)
			result += "0";
		else
			result += "1";
	}
	
	return result;
	
}//End xorfunc function


/**************************************************************************************/
//                                  Encrypting function.                              //
//  This is our encrypting function, we will take in three strings from our main      //
//  function. The inputBin, the keyBin, and the iv. The inputBin is the value of our  //
//  hexadecimal user input or randomly generated converted into binary. The keyBin    //
//  is the keyBin generated randomly or inputed by the user in hexadecimal converted  //
//  to binary. The string IV is the intialization vector that can either be randomly  //
//  generated or inputted by the user used to start our original iterated process.    //
//  The first step in encryption is to create 16 subkeys which will each be 48 bits   //
//  long. The 64-bit key will be peurmated using the permutation box PC1, each spot   //
//  will be desiganted according to the spot of the permutation box.Next we will go   //
//  ahead and split each half into 28 bits and call our key shift function where we   //
//  each subkey will be shifted according to the value of the current round of the    //
//  shift schedule. We will then combine both strings again, that have been manipu-   //
//  lated by the shift schedule. With this new combined subkey we perform a second    //
//  permuation using the PC1 table.                                                   //
//                                                                                    //
//  The second step is to encode the block of data itself. Wiith our block of data    //
//  there will be an initial permutation, IP of the message using the array of char   //
//  char IP. Then divide the block of data permutated by half, where you have the     //
//  the left and right side. The program then goes through 16 iterations for 1        //
//  <=n<=16, using a key of 48bits to produce two blocks to generate the following    //
//  L_n=R_n-1 and R_n = L_n-1 + f(R_n-1, K_n). In order to do this we have to go      //
//  the xor addtion fnction, and place the results in the final block. the K_n will   //
//  our subkeys that we have previously geneated in the first step.                   //
//                                                                                    //
//  In order to to calculate the function we must go through an expansion of the      //
//  right side We will use our character array of E[48] also called our expansion     //
//  box and do an xOR output of the expnasion with the current subkey. Afterwards     //
//  We use the s-boxes to form the output S_i(B_i). We go thorugh the entire itera-   //
//  tion of s-boxes. The final stage will be then do a permutate of the S-box out-    //
//  put using the P[32] array. Combining both the R_n and L_n round we can go ahead   //
//  and apply our final permutation denoted by FP[64]. This will be our final ecnry-  //
//  pted message given to the user.
/**************************************************************************************/

string encrypt(string inputBin, string keyBin, string iv){
  	string leftInput;
	string rightInput;
	string leftKey;
	string rightKey;
  
	
	// PC-1 table (initial key permutation)
	int PC1[56] = {
		57,	49,	41,	33,	25,	17,	9,
		1,	58,	50,	42,	34,	26,	18,
		10,	2,	59,	51,	43,	35,	27,
		19,	11,	3,	60,	52,	44,	36,
		63,	55,	47,	39,	31,	23,	15,
		7,	62,	54,	46,	38,	30,	22,
		14,	6,	61,	53,	45,	37,	29,
		21,	13,	5,	28,	20,	12,	4
	};

	// PC-2 table (permutation for generating each subkey)
	int PC2[48] = {
		14,	17,	11,	24,	1,	5,	3,	28,
		15,	6,	21,	10,	23,	19,	12,	4,
		26,	8,	16,	7,	27,	20,	13,	2,
		41,	52,	31,	37,	47,	55,	30,	40,
		51,	45,	33,	48,	44,	49,	39,	56,
		34,	53,	46,	42,	50,	36,	29,	32
	};

	
	
	//key = keypermutation
	//key initial permutation
	string keyAIP = "                                                         ";
	for(int i=0; i<56; i++)
    {
		keyAIP[i] = keyBin[PC1[i]-1];
	}//end for loop
	

	
	int shiftSchedule[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	string subKeyArray[16];
	
	//generate 16 subkeys
	for(int i=0; i<16; i++)
    {
        //Declaring two seperate strings to
		string leftSideKey;
		string rightSideKey;
		
		splitBinary(keyAIP, keyAIP.length(), &leftSideKey, &rightSideKey);

		
		//rotate left side
		int size = leftSideKey.length();
		char line[size];
		
		for(int x=0; x<size; x++)
        {
			line[x] = leftSideKey[x];			
        }//end for loop
        
        //Call our shiftLeft function, we will decide on how many to shift pre-determined by
        //shiftSchedule array, already determined at the beginning of our function.
		shiftLeft(line, size, shiftSchedule[i]);
		
		string leftSide = "";
		
		for(int x=0; x<size; x++)
        {
			leftSide += line[x];
		}//end for loop
		
		//rotate right side
		int rSize = rightSideKey.length();
		char rLine[rSize];
		
		for(int x=0; x<rSize; x++)
        {
			rLine[x] = rightSideKey[x];			
		}//end for loop
		
		shiftLeft(rLine, rSize-1, shiftSchedule[i]);
		

		string rightSide = "";
		for(int x=0; x<rSize; x++)
        {
			rightSide += rLine[x];
		}//end for loop


		keyAIP = leftSide + rightSide;
		
		
		//subkey permutations
		string subKey = "                                                ";
		for(int x=0; x<48; x++)
        {
			subKey[x] = keyAIP[PC2[x]-1];
            
		}//end for loop

        subKeyArray[i] = subKey;
        

    }//end subkey array for

	
	//xor initial value with input
	inputBin = xorfunc(inputBin, iv, inputBin.length());
	
	//initial permutation
	char IP[64] = {
		58,	50,	42,	34,	26,	18,	10,	2,
		60,	52,	44,	36,	28,	20,	12,	4,
		62,	54,	46,	38,	30,	22,	14,	6,
		64,	56,	48,	40,	32,	24,	16,	8,
		57,	49,	41,	33,	25,	17,	9,	1,
		59,	51,	43,	35,	27,	19,	11,	3,
		61,	53,	45,	37,	29,	21,	13,	5,
		63,	55,	47,	39,	31,	23,	15,	7
	};
 
	string inputAIP = "                                                                ";
	
	//use IP to perform initial permutation
	for(int i=0; i<64; i++)
    {
		inputAIP[i] = inputBin[IP[i]-1];
	}//end for loop
    

    //call our splitBinary function.
	splitBinary(inputAIP, inputAIP.length(), &leftInput, &rightInput);

	
	//expansion box
	char E[48] = {
		32,	1,	2,	3,	4,	5,
		4,	5,	6,	7,	8,	9,
		8,	9,	10,	11,	12,	13,
		12,	13,	14,	15,	16,	17,
		16,	17,	18,	19,	20,	21,
		20,	21,	22,	23,	24,	25,
		24,	25,	26,	27,	28,	29,
		28,	29,	30,	31,	32,	1
	};
	
	//substitution boxes
	//addressable using xxyyyy where xx are the first and last bits, and yyyy are the middle 4 bits
    //there will be eight boxes
	int S1[64] = {
		14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7,
		0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8,
		4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0,
		15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13
	};

	int S2[64] = {
		15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10,
		3,	13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5,
		0,	14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15,
		13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9
	};

	int S3[64] = {
		10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8,
		13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1,
		13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7,
		1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12
	};

	int S4[64] = {
		7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15,
		13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9,
		10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4,
		3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14
	};

	int S5[64]  = {
		2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9,
		14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6,
		4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14,
		11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3
	};

	int S6[64] = {
		12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11,
		10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8,
		9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6,
		4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13
	};

	int S7[64] = {
		4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1,
		13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6,
		1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2,
		6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12
	};

	int S8[64] = {
		13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7,
		1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2,
		7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8,
		2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11
	};

	int* SBOXMAP[] = {S1, S2, S3, S4, S5, S6, S7, S8};
	
		
	//This will iterate through the expanded input for the
    //right side for 16 rounds.
	for(int round = 0; round < 16; round++)
    {

		
		//Expands each right input from 32 bits to 48 bits.
		string expandedInput = "                                                ";
		for(int i = 0; i < 48; i++)
        {

			expandedInput[i] = rightInput[E[i]-1];
        }//end for loop
		

		//xOR the returned expanded strings.
		string xorResult = xorfunc(expandedInput, subKeyArray[round], expandedInput.length());
		
		//row bits are first and last bits
		//column bits are middle 4 bits
		//add row(down) bit to index so add 16*rowbit(will be 0,1,2, or 3) + column index to get position in sbox
		//use 8 s-boxes
		//string division[8];
		
		string SBoxesResult = "";
		string line;
		int index = 0;
		for(int i = 0; i < 8; i++){

            line = xorResult.substr(index, 6);
			index += 6;

            string rowBits = line.substr(0, 1) + line.substr(5, 1);
			string columnBits = line.substr(1, 4);

            int rowNum = binToInt(rowBits);

			int columnNum = binToInt(columnBits);
			
			
			int boxIndex = (rowNum * 16) + columnNum;
			
			//value will be converted to binary and those 4 bits will be concatenated to an overall string (SBoxesResult) 
			//which will then be put through final permutation
			int value = SBOXMAP[i][boxIndex]; 
			
			
			string set = bitset<4> (value).to_string();
			SBoxesResult += set;
		}//end for loop

		
		//Permutation box
		char P[32] = {
			16, 7, 20, 21, 29, 12, 28, 17,
			1, 15, 23, 26, 5, 18, 31, 10,
			2, 8, 24, 14, 32, 27, 3, 9,
			19, 13, 30, 6, 22, 11, 4, 25
		};
		
		string afterPerm = "                                ";
		
		for(int i=0; i<32; i++)
        {
			afterPerm[i] = SBoxesResult[P[i]-1];			
		}//end for loop
		
		
		//xor result of cipher function with left side in order to create a chain for the next round
		string output = xorfunc(afterPerm, leftInput, afterPerm.length());
		
		//set the left to output
		leftInput = output;
		swap(&leftInput, &rightInput);
        
	} //end rounds for
	
	//call to our swap function using the right and left input.
	swap(&leftInput, &rightInput);
    //put back togehter the string into a new string called entireInput
	string entireInput = leftInput + rightInput;
	// final permutation
	char FP[64] = {
	      40,	8,	48,	16,	56,	24,	64,	32,
	      39,	7,	47,	15,	55,	23,	63,	31,
	      38,	6,	46,	14,	54,	22,	62,	30,
	      37,	5,	45,	13,	53,	21,	61,	29,
	      36,	4,	44,	12,	52,	20,	60,	28,
	      35,	3,	43,	11,	51,	19,	59,	27,
	      34,	2,	42,	10,	50,	18,	58,	26,
	      33,	1,	41,	9,	49,	17,	57,	25
	};
	
	
	/************************
            Test code
	input after initial permuation
	string inputAIP = "                                                                ";
	
	//use IP to perform initial permutation
	for(int i=0; i<64; i++){
		inputAIP[IP[i]-1] = inputBin[i];		 
	}
	*************************/
	string afterFinal = "                                                                ";
	
	for(int i = 0; i < 64; i++)
    {
	    afterFinal[i] = entireInput[FP[i]-1];
	  
	}//end for loop
    

    //return our final encrypted message.
    
	return afterFinal;  
}//End of Decryption function

/**************************************************************************************/
//                                Decryption Function.                                 //
//  In order to use the decryption function we have to go thorugh the enryption func- //
//  tion backwards. So we iterate through the previous steps in our encryption func-  //
//  tion except instead of using the right side and left side from the beginning      //
//  We will be working from R_15 and L_15 to zero. Same goes for subkeys. Instead     //
//  of using our generated subkeys from 0 to 16, we will go ahead and go from 16 to   //
//  zero. The user should be able to input the key and initialization vector into the //
//  The command line to call the decrypt function. We will continue to use the intial //
//  permuation and final permuation to deliver the decrypted function.                //
/**************************************************************************************/


string decrypt(string inputBin, string keyBin, string iv){
  	string leftInput;
	string rightInput;
	string leftKey;
	string rightKey;
  
	
	// PC-1 table (initial key permutation)
	int PC1[56] = {
		57,	49,	41,	33,	25,	17,	9,
		1,	58,	50,	42,	34,	26,	18,
		10,	2,	59,	51,	43,	35,	27,
		19,	11,	3,	60,	52,	44,	36,
		63,	55,	47,	39,	31,	23,	15,
		7,	62,	54,	46,	38,	30,	22,
		14,	6,	61,	53,	45,	37,	29,
		21,	13,	5,	28,	20,	12,	4
	};

	// PC-2 table (permutation for generating each subkey)
	int PC2[48] = {
		14,	17,	11,	24,	1,	5,	3,	28,
		15,	6,	21,	10,	23,	19,	12,	4,
		26,	8,	16,	7,	27,	20,	13,	2,
		41,	52,	31,	37,	47,	55,	30,	40,
		51,	45,	33,	48,	44,	49,	39,	56,
		34,	53,	46,	42,	50,	36,	29,	32
	};

	
	//key initial permutation
	string keyAIP = "                                                         ";
	for(int i=0; i<56; i++)
    {
		keyAIP[i] = keyBin[PC1[i]-1];
	}//end for loop
	

	
	int shiftSchedule[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	string subKeyArray[16];
	
	int reverse = 15;
    //wll generate 16 subkeys
	for(int i=0; i<16; i++)
    {
		string leftSideKey;
		string rightSideKey;
		
		splitBinary(keyAIP, keyAIP.length(), &leftSideKey, &rightSideKey);

		
		//rotate the left side
		int size = leftSideKey.length();
		char line[size];
		
		for(int x=0; x<size; x++)
        {
			line[x] = leftSideKey[x];			
		}//end for loop

        //calling our shiftLeft function by a shiftSchedule.
        shiftLeft(line, size, shiftSchedule[i]);
		
        //declaring our new leftSide and
        //using a for loop to fill it from
        //the line function.
		string leftSide = "";
		
		for(int x=0; x<size; x++)
        {
			leftSide += line[x];
		}//end for loop
		
		//This will rotate our right side.
        
		int rSize = rightSideKey.length();
		char rLine[rSize];
		
        //have our rLine string equal to the rightSideKey by character.
		for(int x=0; x<rSize; x++)
        {
			rLine[x] = rightSideKey[x];			
		}//end for loop
		
        //call our shiftLeft function using the shiftSchedule as integers.
		shiftLeft(rLine, rSize-1, shiftSchedule[i]);

        //Use the string rightSide to go to the rLine using a for loop.
		string rightSide = "";
		for(int x=0; x<rSize; x++)
        {
			rightSide += rLine[x];
		}//end for loop
			
        //We will combined both the leftside and the rightside string together in the keyAIP string.
		keyAIP = leftSide + rightSide;

		//subkey permutations
		string subKey = "                                                ";
		for(int x=0; x<48; x++){
			subKey[x] = keyAIP[PC2[x]-1];
            
		}

        //call the subKeyArray in reverse and store into subKey.
        subKeyArray[reverse--] = subKey;
        

	}//end subkey array for
	

	// initial permutation 
	char IP[64] = {
		58,	50,	42,	34,	26,	18,	10,	2,
		60,	52,	44,	36,	28,	20,	12,	4,
		62,	54,	46,	38,	30,	22,	14,	6,
		64,	56,	48,	40,	32,	24,	16,	8,
		57,	49,	41,	33,	25,	17,	9,	1,
		59,	51,	43,	35,	27,	19,	11,	3,
		61,	53,	45,	37,	29,	21,	13,	5,
		63,	55,	47,	39,	31,	23,	15,	7
	};
 
	//input after initial permuation
	string inputAIP = "                                                                ";
	
	for(int i=0; i<64; i++)
    {
		inputAIP[i] = inputBin[IP[i]-1];
	}//End for loop

    //a call to the splitBinary function.
    splitBinary(inputAIP, inputAIP.length(), &leftInput, &rightInput);

	
	// expansion box
	char E[48] = {
		32,	1,	2,	3,	4,	5,
		4,	5,	6,	7,	8,	9,
		8,	9,	10,	11,	12,	13,
		12,	13,	14,	15,	16,	17,
		16,	17,	18,	19,	20,	21,
		20,	21,	22,	23,	24,	25,
		24,	25,	26,	27,	28,	29,
		28,	29,	30,	31,	32,	1
	};
	
	// substitution boxes
	// addressable using xxyyyy where xx are the first and last bits, and yyyy are the middle 4 bits
	int S1[64] = {
		14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7,
		0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8,
		4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0,
		15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13
	};

	int S2[64] = {
		15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10,
		3,	13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5,
		0,	14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15,
		13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9
	};

	int S3[64] = {
		10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8,
		13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1,
		13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7,
		1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12
	};

	int S4[64] = {
		7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15,
		13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9,
		10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4,
		3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14
	};

	int S5[64]  = {
		2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9,
		14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6,
		4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14,
		11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3
	};

	int S6[64] = {
		12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11,
		10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8,
		9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6,
		4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13
	};

	int S7[64] = {
		4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1,
		13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6,
		1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2,
		6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12
	};

	int S8[64] = {
		13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7,
		1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2,
		7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8,
		2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11
	};

	int* SBOXMAP[] = {S1, S2, S3, S4, S5, S6, S7, S8};
		
	//16 rounds
	for(int round = 0; round < 16; round++){
		//will be using right side
		
		//expand rightInput from 32 to 48 bits
		string expandedInput = "                                                ";
		for(int i = 0; i < 48; i++){
			expandedInput[i] = rightInput[E[i]-1];
		}
		
		//making a call to our xorfunction and storing it in a string called xor result
        
		string xorResult = xorfunc(expandedInput, subKeyArray[round], expandedInput.length());
        string SBoxesResult = "";
		string line;
		int index = 0;
        
        //This for loop is in charge of decrypting the s-boxes generated results.
        //
		for(int i = 0; i < 8; i++)
        {
            
            
			line = xorResult.substr(index, 6);
			index += 6;
			string rowBits = line.substr(0, 1) + line.substr(5, 1);
			string columnBits = line.substr(1, 4);
			int rowNum = binToInt(rowBits);

			int columnNum = binToInt(columnBits);
						
			int boxIndex = (rowNum * 16) + columnNum;

			int value = SBOXMAP[i][boxIndex]; 
			
			
			string set = bitset<4> (value).to_string();
			SBoxesResult += set;

		}//end sBoxes result for loop

		
		//Permutation box
		char P[32] = {
			16, 7, 20, 21, 29, 12, 28, 17,
			1, 15, 23, 26, 5, 18, 31, 10,
			2, 8, 24, 14, 32, 27, 3, 9,
			19, 13, 30, 6, 22, 11, 4, 25
		};
		
		string afterPerm = "                                ";
		
		for(int i=0; i<32; i++){
			afterPerm[i] = SBoxesResult[P[i]-1];			
		}
		
		//xor result of cipher function with left side in order to create a chain for the next round
		string output = xorfunc(afterPerm, leftInput, afterPerm.length());
		
		//set left to output
		leftInput = output;

        //swap sides to create block chaining
		swap(&leftInput, &rightInput);

	} //end rounds for
	

	
	swap(&leftInput, &rightInput);

	string entireInput = leftInput + rightInput;
	// final permutation
	char FP[64] = {
	      40,	8,	48,	16,	56,	24,	64,	32,
	      39,	7,	47,	15,	55,	23,	63,	31,
	      38,	6,	46,	14,	54,	22,	62,	30,
	      37,	5,	45,	13,	53,	21,	61,	29,
	      36,	4,	44,	12,	52,	20,	60,	28,
	      35,	3,	43,	11,	51,	19,	59,	27,
	      34,	2,	42,	10,	50,	18,	58,	26,
	      33,	1,	41,	9,	49,	17,	57,	25
	};
	
	
	string afterFinal = "                                                                ";
	
	for(int i = 0; i < 64; i++){
	    //afterFinal[FP[i]-1] = entireInput[i];	  
	    afterFinal[i] = entireInput[FP[i]-1];	  
	  
	}
    
    
	//call the xor function with the inputs afterFinale, iv, and the length
    //of afterfinal, return it to the after final string.
	afterFinal = xorfunc(afterFinal, iv, afterFinal.length());

	  
    //return our afterFinal string, i.e our decreypted message.
	return afterFinal;  
}
/*********************************************************************************/
//                                  Main Function                               //
//  Our main function will prompt the user if they want to generate their own   //
//  random user generated key and initializtion vector when run. They can input //
//  their own if they desire. You should be able to call the encyrpt and decrypt//
//  function when calling on the command line of the terminal. The main function//
//  will be in charge of calling the speerate functions in order to encrypt and //
//  and decrypt the message.                                                    //
/*********************************************************************************/


int main(int argc, char *argv[]){
    string enDec;
	string input;
	string key;  //userKey
	string keyBin;
	string inputBin;
	//string iv;
	string ivBin;
	string inputFileName;
	ifstream inputFile;
		
	
    /*
     Declaring userKey string for manual user key input and generatedUserKey string for the random
     key generator. Answer will be to get user input to either generate a random key or insert their
     own. Rand function called in order to generate a random userKey.
    */
    string userKey = "";
    string generatedUserKey ="";
    string iv="";
    string answer;
    srand(time(0));
    int inputFlag = -1;
    int keyFlag = -1;
    int ivFlag = -1;
    int eFlag = -1;
    int dFlag = -1;
    string iInput = "-i";
    string kInput = "-k";
    string ivInput = "-iv";
    string eInput = "-e";
    string dInput = "-d";
    
    
     //check for command line inputs
   for(int i=0; i<argc; i++){
     //cout << "argv: " << argv[i] << endl;
      if(argv[i] == iInput){
	inputFileName = argv[++i];
	//cout << "Filename: " << inputFileName << endl;
	inputFlag = 1;
      }
      else if(argv[i] == kInput){
	userKey = argv[++i];
	keyFlag = 1;
      }
      else if(argv[i] == ivInput){
	iv = argv[++i];
	ivFlag = 1;
      }
      else if(argv[i] == eInput){
	enDec = "E";
	eFlag = 1;
      }
      else if(argv[i] == dInput){
	enDec = "D";
	eFlag = 1;
      }
      
      
    }//end command line options
    
    //if no input file specified
    if(inputFlag != 1){
      cout << "Error: no input file specified" << endl;
      exit(EXIT_FAILURE);
    }
    
    if(keyFlag != ivFlag){
     cout << "Error: you must provide either BOTH key and iv or NEITHER in which case a random key and iv will be generated" << endl;
     exit(EXIT_FAILURE);
    }
    
    //if no key was given
    if(keyFlag != 1 && ivFlag != 1){
      answer = "NO";
    }
    else{
      answer = "YES";
    }
    if(eFlag == -1 && dFlag != 1){
      cout << "Error: you must choose to encrypt or decrypt" << endl;
      exit(EXIT_FAILURE);
    }

    
//    cout << "\nWould you like to use your own key? Type 'Yes' to do so, or 'No' to generate a random key.\n";
//    cin  >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
	
    /*
     Generate a random string. Here we will ask if the user wants to generate a random
     userKey, or if they wish to provide their own. If user answers 'Yes' than we will
     generate a random userKey, if not the user will be allowed to input their own user
     key. Once it does that, it turns the key into binary using the function convert2binary. 
     Afterwards it will remove the 8th bit from the 64 bit key to turn into  56 bit key using the
     remove8bit function. Once we have removed every 8th bit, using our new 56 bit key we will use
     the shift bit key function to shift the 56 bit key by either 1 or 2 bits to the left. Once
     that is done we shall permuate the 56 bit to have a 46 bit key and that will be our key
     to feed into the cycle.
    */
    
    if(answer.compare("YES"))
    {
    for(unsigned int i = 0; i <16; i++)
    {
        generatedUserKey +=newRandomString();
		iv += newRandomString();
    }
    cout << "\nNew random key generated in hexadecimal form: \n" << generatedUserKey << "\n";
    generatedUserKey = hexToBin(generatedUserKey);
//    cout << "\nYour userkey in binary is: \n" << generatedUserKey << "\n";
	
	cout << "\nNew random iv generated in hexadecimal form: \n" << iv << "\n\n";
	iv = hexToBin(iv);
//	cout << "\nYour iv in binary is: \n" << iv << "\n";
	
	userKey = generatedUserKey;
    //generatedUserKey = remove8bit(generatedUserKey, 8);
    //cout << "\nNth bit removed is: \n" << generatedUserKey << "\n";
    //generatedUserKey = keyShift(generatedUserKey, 1);
    //cout << "\nKey shift function\n";
    //cout << userKey <<"\n";
    }//end if statement comapre to yes

    /* 
      In this function, if user answers yes, than they should be able to put in their own
      key in hexadecimal form. We need the key to have 16 bits, so if the user does anything
      less or more, it will prompt the user to enter the key once again. Once it does that,
      it turns the key into binary using the function convert2binary. Afterwards it will 
      remove the 8th bit from the 64 bit key to turn into  56 bit key using the remove8bit
      function. Once we have removed every 8th bit, using our new 56 bit key we will use the 
      shift bit key function to shift the 56 bit key by either 1 or 2 bits to the left. Once
      that is done we shall permuate the 56 bit to have a 46 bit key and that will be our key
      to feed into the cycle.
     */
    else if (answer.compare("NO"))
    {
//    cout << "Enter your own key in hexadecimal form, must be 16 bits long: \n" ;
//    cin >> userKey;
	    
    while(userKey.length() !=16)
    {
        cout <<"Error: Your key was not 16 bits long: \n";
        //cin >> userKey;
	exit (EXIT_FAILURE);
    }
    
//    cout << "Enter your own iv in hexadecimal form, must be 16 bits long: \n" ;
//    cin >> iv;
    
    while(iv.length() !=16)
    {
        cout <<"Error: Your iv was not 16 bits long: \n";
        //cin >> userKey;
	exit (EXIT_FAILURE);
    }
        
//    cout << "\nYour user key in hexadecimal form is: \n" << userKey;
    userKey = hexToBin (userKey);
//    cout << "\nYour userkey in binary is: \n" << userKey << "\n";
	iv = hexToBin(iv);
//	cout << "\nYour iv in binary is: \n" << iv << "\n";
//    userKey = remove8bit(userKey, 8);
//   cout << "\nNth bit removed is: \n" << userKey << "\n";
    
//   cout << "\nKey shift function\n";
//   userKey = keyShift(userKey , 2);
//   cout << userKey << "\n";
    }//end else statement compare to no	
	
//	cout <<"Enter name of input file with file extension: \n";
//	cin >> inputFileName;
	
//	cout << endl << "Would you like to encrypt or decrypt? Enter 'E' or 'D'\n";
//	cin >> enDec;
	transform(enDec.begin(), enDec.end(), enDec.begin(), ::toupper);
	

	

	
	string var = "";
	if(enDec == "E"){

	  
	  ifstream file(inputFileName.c_str(), ios::in|ios::binary);
	  
	  vector<string> inputVector;
	  unsigned long long partial = 0;
	  unsigned char character;
	  
	  int pushNum = 0;
	  while (file.read((char*)&character,1)) {
	    partial *= 256;
	    partial += (int)character;
	    if (++pushNum % 8 == 0) {
	      bitset<64> set(partial);
//	      cout << set << endl;
	      string s = set.to_string();
	      inputVector.push_back(s);
	      partial = 0;
	    }
	  }
	file.close();
    /*
for(int i=0; i<inputVector.size(); i++){
 cout << inputVector[i] << endl;   
}
*/
	  if(partial > 0 ){
	    bitset<64> set2(partial);
	    inputVector.push_back(set2.to_string());
	  }
	  for(int i=0; i<inputVector.size(); i++){
	    inputVector[i] = encrypt(inputVector[i], userKey, iv);
	  }

	  /*
for(int i=0; i<inputVector.size(); i++){
 cout << inputVector[i] << endl;   
}
    */
    
	  // After encryption
	  ofstream outFile("CIPHER.txt", ios::out| ios::binary);


	 // int i = 56;
	  for(int i = 0; i < inputVector.size(); i++){
  
	    string s = inputVector[i];
	    //reverse(s.begin(), s.end());
	    //cout <<"s reverse: " << s << endl;
	    bitset<64> bit (s);
	    
	    unsigned long long longNum = bit.to_ullong();
	    while(longNum > 0){
	      unsigned char c = longNum >> 56;
	      outFile.write((char *)&c, sizeof(unsigned char));
	      longNum <<= 8;
	    }
	  }  
	  outFile.close();
	  cout << "CIPHER.txt file created with ciphertext" << endl;	  
	  
	}
	else if(enDec == "D"){//////////////////////////////////////////////////////////
	  ifstream file(inputFileName.c_str(), ios::in|ios::binary);
	  
	  vector<string> inputVector;
	  unsigned long long partial = 0;
	  unsigned char character;
	  
	  int pushNum = 0;
	  while (file.read((char*)&character,1)) {
	    partial *= 256;
	    partial += (int)character;
	    if (++pushNum % 8 == 0) {
	      bitset<64> set(partial);
//	      cout << set << endl;
	      string s = set.to_string();
	      inputVector.push_back(s);
	      partial = 0;
	    }
	  }
	  file.close();
//          cout << "PUSH NUM "<<pushNum << endl;
    /*
for(int i=0; i<inputVector.size(); i++){
 cout << inputVector[i] << endl;   
}
*/
	  if(partial > 0 ){
	    bitset<64> set(partial); 
	    inputVector.push_back(set.to_string());
	  }
	  for(int i=0; i<inputVector.size(); i++){
	    inputVector[i] = decrypt(inputVector[i], userKey, iv);
	  }

/*	  
for(int i=0; i<inputVector.size(); i++){
 cout << inputVector[i] << endl;   
}
*/ 
    
	  // After encryption
	  ofstream outFile("PLAIN.txt", ios::out| ios::binary);


	 // int i = 56;
	  for(int i = 0; i < inputVector.size(); i++){
  
	    string s = inputVector[i];
	    //reverse(s.begin(), s.end());
	    //cout <<"s reverse: " << s << endl;
	    bitset<64> bit (s);
	    unsigned long long longNum = bit.to_ullong();
	    string a = "00000000";
	    int j = 0;
	    while(bit.to_string().substr(0,8) == a){
	      longNum <<= 8;
	      bit = longNum;
//	      cout << "INDECRYPT\n";
//	      cout << bit << endl;
	    }
	    
	    
	    while(longNum > 0){
	      unsigned char c = longNum >> 56;
	      outFile.write((char *)&c, sizeof(unsigned char));
	      longNum <<= 8;
	    }
	  }  
	  outFile.close();
	  cout << "PLAIN.txt file created with plaintext" << endl;	  
	  
	}	  
	

}

