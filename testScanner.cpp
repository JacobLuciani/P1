//---------------------------------------------------------------------------
//File name: testScanner.cpp
//Author: Jacob Luciani
//Purpose: Serves as an interface with the scanner that processes an input file of "source code"
//         and displays the tokens identified along with token info
//---------------------------------------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "inputProcessing.h"
#include "Scanner.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	//holds the "base" name related to the source of input
	char *baseName;
	baseName = getBaseName(argc, argv);

	//File pointer to input file
	FILE *input;
	
	//get pointer to a file with input regardless of input source
	input = processArgs(baseName);
	
	//create Scanner object pointing to input file
	Scanner scan (input);
	
	Token nextToken;
	
	//loop through input file processing it into tokens and displaying token info
	do {
		nextToken = scan.getNextToken();
		cout << printToken(nextToken);
	} while (nextToken.tokenId != eofTok);
	
	//printf("suppo\n");
	//clean up resources before termination
	fclose(input);
	free(baseName);
	
	return EXIT_SUCCESS;
}