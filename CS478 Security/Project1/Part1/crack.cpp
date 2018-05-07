

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//displays letters and their frequency
void displayArray(int** array){
	for(int i=0; i<26; i++){
		char c = array[i][0]; 
		cout << c << ": ";
		cout << array[i][1] << endl;
	}	
}

//sort array with most frequent letter first
int** sortArray(int** array){
	//cout << "sortArray func\n";
	int tempFreq;
	int tempAscii;
	
	for(int i=0; i < 25; i++){
		for(int x=0; x < 25; x++){
			if(array[x][1] < array[x+1][1]){
				//swap letter frequency
				tempFreq = array[x][1];
				array[x][1] = array[x+1][1];
				array[x+1][1] = tempFreq;				

				//swap letter ascii
				tempAscii = array[x][0];
				array[x][0] = array[x+1][0];
				array[x+1][0] = tempAscii;
			}
		}			
	}
	
//	displayArray(array);	
	return array;	
}

//create 2d array and initialize to 0
int **create2DArray(){
	//int alphabet[26][2]; // [ascii representation][frequency]
	int **array = 0; 

	//set length of first part
	array = new int*[26];
	
	//set length of second part
	for (int i=0; i<26; i++){
		array[i] = new int[2];
	}
		
		
	//set ascii representation and initialize frequency to 0
	for (int i=0; i<26; i++){		
		array[i][0] = 65 + i;
		array[i][1] = 0;
	}
	
	return array;
}

//calculates and displays letters and their frequency
//returns sorted array of letters and their frequency
int** frequency(string cipherText, int flag){
	
	int **alphabet = create2DArray();	
	
	//count the frequency of each letter
	for(int i = 0; i < cipherText.length(); i++){
		char letter = cipherText[i];
		switch(letter){
			case 'A' : alphabet[0][1]++;
				break;
			case 'B' : alphabet[1][1]++;
				break;
			case 'C' : alphabet[2][1]++;
				break;
			case 'D' : alphabet[3][1]++;
				break;
			case 'E' : alphabet[4][1]++;
				break;
			case 'F' : alphabet[5][1]++;
				break;
			case 'G' : alphabet[6][1]++;
				break;
			case 'H' : alphabet[7][1]++;
				break;
			case 'I' : alphabet[8][1]++;
				break;
			case 'J' : alphabet[9][1]++;
				break;
			case 'K' : alphabet[10][1]++;
				break;
			case 'L' : alphabet[11][1]++;
				break;
			case 'M' : alphabet[12][1]++;
				break;
			case 'N' : alphabet[13][1]++;
				break;
			case 'O' : alphabet[14][1]++;
				break;
			case 'P' : alphabet[15][1]++;
				break;
			case 'Q' : alphabet[16][1]++;
				break;
			case 'R' : alphabet[17][1]++;
				break;
			case 'S' : alphabet[18][1]++;
				break;
			case 'T' : alphabet[19][1]++;
				break;
			case 'U' : alphabet[20][1]++;
				break;
			case 'V' : alphabet[21][1]++;
				break;
			case 'W' : alphabet[22][1]++;
				break;
			case 'X' : alphabet[23][1]++;
				break;
			case 'Y' : alphabet[24][1]++;
				break;
			case 'Z' : alphabet[25][1]++;
				break;			
		}
		//cout << letter << endl;		
	}	
		
	
	//sort alphabet by frequency
	alphabet = sortArray(alphabet);
	
	if(flag == 1){
	cout << "Frequency Analysis of Ciphertext: \n";
	displayArray(alphabet);
	cout << endl;
	}
	
	return alphabet;
}

//decrypt ciphertext with a given key
//ciphertext must be stored in "ciphertext.txt"
//1st letter in key will replace "A", 2nd letter will replace "B", and so on
string decryptWithKey(string cipherText, string key){
	string plainText = "";		
	
	//replace each letter in cipherText with the letter it is tied to in the key
	for(int i=0; i < cipherText.length(); i++){
		char letter = cipherText[i];
				
		switch(letter){
			case 'A' : plainText += key[0];
				break;
			case 'B' : plainText += key[1];
				break;
			case 'C' : plainText += key[2];
				break;
			case 'D' : plainText += key[3];
				break;
			case 'E' : plainText += key[4];
				break;
			case 'F' : plainText += key[5];
				break;
			case 'G' : plainText += key[6];
				break;
			case 'H' : plainText += key[7];
				break;
			case 'I' : plainText += key[8];
				break;
			case 'J' : plainText += key[9];
				break;
			case 'K' : plainText += key[10];
				break;
			case 'L' : plainText += key[11];
				break;
			case 'M' : plainText += key[12];
				break;
			case 'N' : plainText += key[13];
				break;
			case 'O' : plainText += key[14];
				break;
			case 'P' : plainText += key[15];
				break;
			case 'Q' : plainText += key[16];
				break;
			case 'R' : plainText += key[17];
				break;
			case 'S' : plainText += key[18];
				break;
			case 'T' : plainText += key[19];
				break;
			case 'U' : plainText += key[20];
				break;
			case 'V' : plainText += key[21];
				break;
			case 'W' : plainText += key[22];
				break;
			case 'X' : plainText += key[23];
				break;
			case 'Y' : plainText += key[24];
				break;
			case 'Z' : plainText += key[25];
				break;			
		}		
	}
	
	cout << "Plain Text: \n" << plainText << endl;
	cout << endl;
	
	return plainText;
	
}


void findKey(string cipherText){
	//frequency function creates and sorts array based on frequency
	int **alphabet = frequency(cipherText, 0);
	string keyGuess;
	string plainText = "";
	string alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string change = "y";
	
	//                E  T  A  O  I  N  S  H  R  D  L  C  U  M  W  F  G  Y  P  B  V  K  J  X  Q  Z
	int stFreq[26] = {69,84,65,79,73,78,83,72,82,68,76,67,85,77,87,70,71,89,80,66,86,75,74,88,81,90};
	
	//displayArray(alphabet);
	
	for(int i=0; i<cipherText.length(); i++){
		char letter = cipherText[i];
		for(int x=0; x<26; x++){			
			if(letter == alphabet[x][0])
				plainText += stFreq[x];
		}
	}
	
	int wordCount = 0;
	string word;
	
	//count number of words
	ifstream dictionary("dictionary.txt");
	while(getline(dictionary, word)){
		if(plainText.find(word) != string::npos){
			//cout << word << endl;
			wordCount++;			
		}
	}
	
	
		         
				   
    //set key using frequency distribution	
	keyGuess = "DALJGXBQNCEHYUMOWTPIVSRZFK"; 
	
	//original key guess
	//A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
	
	//D  A  L  J  G  X  B  Q  N  C  E  H  Y  U  M  O  W  T  P  I  V  S  R  Z  F  K
			

	//keeps altering key until user says no
	while(change == "y" || change == "Y"){
	//cout << "CipherText: wc : " << wordCount << endl; 
	cout << "CipherText: \n" << cipherText << endl;
	
	
	//show message with guessed key
	plainText = decryptWithKey(cipherText, keyGuess);
	
	//show guessed key
	cout << "Key: \n";
	cout << alphabetString << endl;
	cout << keyGuess << endl;
	
	
	
	//ask user if they want to modify key
	cout << endl;
	cout << "Modify Key? y/n\n";
	cin >> change;
	
	// if yes then input new key guess and repeat from step 1
	if(change == "y" || change == "Y"){
	   cout << "Enter New Key: \n";
	   cout << "Old Key: \n" << keyGuess << endl;
	   cin >> keyGuess;
	}
	else{
	 //display key
	 cout << "Key is: " << keyGuess << endl;
	 
	 //display message
	 cout << "Plaintext is: \n" << plainText << endl; 
	 
	 //write final key and plain text to a file
	 ofstream plain;
	 plain.open("result.txt");
	 plain << "Key: \n" << keyGuess << "\n\n" << "Plaintext: \n" << plainText;
	 plain.close();
	 
	}
		
	//cout << cipherText << endl;
	//cout << plainText << endl;
	cout << endl;
	
	
	}
	
}


int main(){
	
	string cipherText = "";
	string cipherLine = "";
	
	//concatenate all lines from ciphertext file into cipherText string
	ifstream file("ciphertext.txt");	
	while(getline(file, cipherLine)){
		cipherText += cipherLine;
	}	
	file.close();
	
	//loop through program until user enters 0
	int input = 1;	
	while(input != 0){
		cout << "Input 1: Compute and display frequency analysis of ciphertext\n";
		cout << "Input 2: Decrypt ciphertext using a key\n";
		cout << "input 3: Guess key of the cipher\n";	
		cout << "Input 0: End program\n";
		cin >> input;
	
	    //find frequency of letters in plaintext
		if(input == 1)
			int **array = frequency(cipherText, 1);
		//find plaintext with given key
		else if(input == 2){
			string key;
			cout << "Input Key\n";
			cin >> key;
			
			string plainText = decryptWithKey(cipherText, key);			
		}
		//find key of ciphertext
		else if(input == 3)
			findKey(cipherText);
		//exit program
		else if (input == 0)
			cout << "Exiting Program\n";
	}
	
	

}



























