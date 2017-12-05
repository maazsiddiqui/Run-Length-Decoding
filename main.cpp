#include <iostream>
#include <fstream> // class necessary to read files
using namespace std;

class runLengthDecoding {

	private:
		int numRows, numCols, minVal, maxVal;
		int** arr; // dynamic array
		char* inFile; // pointer to argv[1]
		char* outFile; // pointer to argv[2]

	public:
		runLengthDecoding(char* inFile, char* outFile) {  // Constructor
			
			this->inFile = inFile;
			this->outFile = outFile;
			
			ifstream myfile(inFile);
			
			myfile >> numRows;
			myfile >> numCols;
			myfile >> minVal;
			myfile >> maxVal;

			myfile.close(); // close input file

			arr = new int*[numRows];
			for(int i = 0; i < numRows; i++) arr[i] = new int[numCols];
	 
	  		for(int i = 0; i < numRows; i++) {
	  			for(int j = 0; j < numCols; j++)
	      			arr[i][j] = 0;
			}
		}
		
		void runLengthPrint() {

			ifstream myfile(inFile);
			
			string line;
			getline(myfile, line);	// skip header line

			int startRow, startCol, pixelColor, runLength;
		
			while (!myfile.eof()) {
							
				myfile >> startRow;
				myfile >> startCol;
				myfile >> pixelColor;
				myfile >> runLength;
								
				for (int i = 0; i < runLength; i++) {
					arr[startRow][startCol++] = pixelColor;
				}
			}
			
			myfile.close(); // close input file
				
			ofstream myoutfile(outFile);
			
			myoutfile	<< numRows << " "
						<< numCols << " "
						<< minVal << " "
						<< maxVal << endl;
						
			for(int i = 0; i < numRows; i++) {
	  			for(int j = 0; j < numCols; j++) {
				  	myoutfile << arr[i][j] << " ";
				}
				myoutfile << endl;
			}
			myoutfile.close();
		}
};

int main(int argc, char *argv[]) {

	runLengthDecoding myRLE(argv[1], argv[2]);
	myRLE.runLengthPrint();

	return 0;

} // end of main

