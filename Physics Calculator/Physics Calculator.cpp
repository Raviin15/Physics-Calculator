// Physics Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;





int main()
{
	// Initialize Variables

	const int charLimit = 50;
	char input[charLimit];
	int count = 0;
	char end = '`';
	int parCountS = 0;
	int parCountE = 0;
	int prevStart[charLimit];
	int prevEnd[charLimit];
	int parPos[charLimit];
	int pairCount = 0;

	int skip = 0;
	int closeShift = 0;
	int shiftMax = 0;
	int endMax = 0;
	int endMaxPos;
	


	// Gather input until ` is returned

	cout << "Please enter text: ";

	for (int i = 0; i < charLimit; i++) {

		cin >> input[i];
		count++;

		if (input[i] == end) {

			break;

		}
	}



	// Counting the number and locations of ( and )

	for (int i = 0; i < count; i++) {

		if (input[i] == '(') {

			prevStart[parCountS] = i;
			parCountS++;

		}
	}
	for (int i = 0; i < count; i++) {

		if (input[i] == ')') {

			prevEnd[parCountE] = i;
			parCountE++;

		}
	}



	// Locate Parenthesis pairs

	for (int j = 0; j < parCountS; j++) {



		for (int i = prevStart[j] + 1; i < count; i++) {

			if (  input[i] == '('  ) {

				skip++;
				closeShift++;
				if (closeShift > shiftMax) {
					shiftMax = closeShift;
				}


			}

			if (  input[i] == ')'  ) {
				if (skip == 0) {
					parPos[pairCount] = prevStart[j];
					parPos[(pairCount + 1)] = prevEnd[(pairCount / 2) + closeShift];
					pairCount = pairCount + 2;


					/*if (prevEnd[(pairCount / 2) + closeShift] > endMax) {
						endMax = prevEnd[(pairCount / 2) + closeShift];
					}*/



					if (closeShift > 0) {
						closeShift = closeShift - (shiftMax + 1);
					}

					break;
				}
				if (skip > 0) {
					skip--;
				}

			}
			
		}
		/*if (input[j] > endMax) {
			closeShift = 0;
			endMax = 0;
		}*/
		
	}
	

	


	// Convert characters to integer numbers


	for (int i = 0; i < count; i++) {

		if (input[i] == '0' or input[i] == '1' or input[i] == '2' or input[i] == '3' or input[i] == '4' or input[i] == '5' or input[i] == '6' or input[i] == '7' or input[i] == '8' or input[i] == '9') {

			

		}
	}


















	// Print out data for debugging

	for (int i = 0; i < (count-1); i++) {

	
		cout << input[i];

	}
	cout <<endl<< "Starting Positions: ";
	for (int i = 0; i < (parCountS); i++) {


		cout << prevStart[i]<<", ";

	}
	cout <<endl<< "Ending Positions: ";
	for (int i = 0; i < (parCountE); i++) {


		cout << prevEnd[i]<<", ";

	}
	cout << endl << "Pair Positions: ";
	for (int i = 0; i < (pairCount); i++) {


		cout << parPos[i];
		if ((i + 1) % 2 != 0) {
			cout << ",";
		}
		if ((i + 1) % 2 == 0) {
			cout << " ; ";
		}

	}

}

