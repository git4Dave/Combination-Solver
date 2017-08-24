//============================================================================
// Name        : CombinationSolver.cpp
// Author      : David Machin
//============================================================================

#include <iostream>
using namespace std;
//void findCombination(string &matrix[][], string givenHint);
void findCombinationRow(string row, int length, string givenHint, int index);
void findCombinationCol(string col, int length, string givenHint, int index);
void LPS(string key, int size, int *longestPS);

//string rowCombinations, colCombinations;

int main() {
	string hint, rowContents, colContents;
	char character;
	unsigned int length;
	cin>>hint;
	cin>>length;
	char matrix[length][length];
	for(unsigned int i = 0; i < length; i++){
		for(unsigned int j = 0; j < length; j++){
			cin>>character;
			matrix[i][j] = character;
			rowContents.push_back(character);
		}
		cout<<"here"<<endl;
		findCombinationRow(rowContents, length, hint, i);
		cout<<"here2"<<endl;

		for(unsigned int k = 0; k < length; k++){
			colContents.push_back(matrix[k][i]);
		}
		cout<<"here3"<<endl;
		findCombinationCol(colContents, length, hint, i);
	}
	return 0;
}

void findCombinationRow(string row, int length, string givenHint, int index){
	int hintLength = givenHint.length();
	int longestPrefixSuffix[hintLength];
	int rowCode[length];

	LPS(givenHint, hintLength, longestPrefixSuffix);
	int hintIterator = 0, rowCombinations = 0, iterator = 0;
	while(iterator < length){
			if(row[iterator] == givenHint[hintIterator]){
				hintIterator++;
				iterator++;
			}
			if(hintIterator == hintLength){
				hintIterator = longestPrefixSuffix[hintIterator - 1];
				rowCombinations++;
			}
			else if(iterator < length && givenHint[hintLength] != row[iterator]){
				if(hintLength != 0){
					hintLength = longestPrefixSuffix[hintLength - 1];
				}
				else{
					iterator = iterator + 1;
				}
			}
		}
		cout<<"aaaa"<<endl;
			rowCode[index] = rowCombinations;
//	int colCode[length];
//
//	LPS(givenHint, length, longestPrefixSuffix);
//	int matrixIterator = 0, matrixIterator2 = 0;
//	int hintIterator = 0, rowCombinations = 0, colCombinations = 0;
//	string rowCombination = "";
//	while(matrixIterator < length){
//		rowCombinations = 0;
//		while(matrixIterator2 < length){
//			if(matrix[matrixIterator][matrixIterator2] == givenHint[hintIterator]){
//				hintIterator++;
//				matrixIterator2++;
//			}
//			if(hintIterator == hintLength){
//				hintIterator = longestPrefixSuffix[hintIterator - 1];
//				rowCombinations++;
//			}
//			else if(matrixIterator2 < length && givenHint[hintLength] != matrix[matrixIterator][matrixIterator2]){
//				if(hintLength != 0){
//					hintLength = longestPrefixSuffix[hintLength - 1];
//				}
//				else{
//					matrixIterator2 = matrixIterator2 + 1;
//				}
//			}
//		}
//		rowCode[matrixIterator] = rowCombinations;
//	}
//}
//
//	while(matrixIterator2 < length){
//		colCombinations = 0;
//		while(matrixIterator < length){
//			if(matrix[matrixIterator][matrixIterator2] == givenHint[hintIterator]){
//				hintIterator++;
//				matrixIterator++;
//			}
//			if(hintIterator == hintLength){
//				hintIterator = longestPrefixSuffix[hintIterator - 1];
//				colCombinations++;
//			}
//			else if(matrixIterator2 < length && givenHint[hintLength] != longestPrefixSuffix[matrixIterator][matrixIterator2]){
//				if(hintLength != 0){
//					hintLength = longestPrefixSuffix[hintLength - 1];
//				}
//				else{
//					matrixIterator = matrixIterator + 1;
//				}
//			}
//		}
//		colCode[matrixIterator2] = colCombinations;
//		matrixIterator2++;
//	}
			for(int i = 0; i < length; i++){
				cout<<rowCode[i];
			}
			cout<<endl;
}

void findCombinationCol(string col, int length, string givenHint, int index){
	int colCode[length];
	int hintLength = givenHint.length();

	int longestPrefixSuffix[hintLength];

	LPS(givenHint, hintLength, longestPrefixSuffix);
	int hintIterator = 0, colCombinations = 0, iterator = 0;
	while(iterator < length){
		if(col[iterator] == givenHint[hintIterator]){
			hintIterator++;
			iterator++;
		}
		if(hintIterator == hintLength){
			hintIterator = longestPrefixSuffix[hintIterator - 1];
			colCombinations++;
		}
		else if(iterator < length && givenHint[hintLength] != col[iterator]){
			if(hintLength != 0){
				hintLength = longestPrefixSuffix[hintLength - 1];
			}
			else{
				iterator = iterator + 1;
			}
		}
	}
	cout<<"dddd"<<endl;
		colCode[index] =colCombinations;

		for(int i = 0; i < length; i++){
			cout<<colCode[i];
		}
		cout<<endl;
}

void LPS(string key, int size, int *longestPS){
	int patternLength = 0;
	longestPS[0] = 0;

	for(int i = 0; i < size; i++){ //initialize the array
		longestPS[i] = 0;
	}
	cout<<size<<endl;
	cout<<"eeee"<<endl;
	int keyIterator = 1;
	while(keyIterator < size){
		if(key[keyIterator] == key[patternLength]){
			patternLength++;
			longestPS[keyIterator] = patternLength;
			keyIterator++;
			cout<<"hello"<<endl;
		}
		else{
			cout<<"hey there"<<endl;
			if(patternLength != 0){
				patternLength = longestPS[patternLength - 1];
				cout<<"yooo"<<endl;
			}
			else{ //if pattern length = 0
				longestPS[keyIterator] = 0;
				keyIterator++;
				cout<<"hiiii"<<endl;
			}
			cout<<"fsfsf"<<endl;
		}
		cout<<"H"<<endl;
		cout<<keyIterator<<" "<<size;
		cout<<"ok...."<<endl;
	}
	cout<<"here now"<<endl;
}
