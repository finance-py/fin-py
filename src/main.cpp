#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>


#include "tokenizer.h"
#include "parser.h"
#include "generation.cpp"
#include "errors.h"
#include "position.h"


std::string Errors::fileName;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "fin-py takes one argument: file name. Example..." << std::endl;
		std::cerr << "fin-py <fileName.fp>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string sourceFile = argv[1];
	std::string sourceFileName;
	{
		size_t lastIDX = sourceFile.find_last_of("/");
		sourceFileName = sourceFile.substr(lastIDX+1, sourceFile.length());
	}
	
	Errors::fileName = sourceFileName;

	std::string fileContents;
	{
		std::stringstream contents_stream;
		std::fstream input(sourceFile, std::ios::in);
		contents_stream << input.rdbuf();
		fileContents = contents_stream.str();
	}

	Tokenizer tokenizer(fileContents);
	std::vector <Tokens> tokens = tokenizer.Tokenize();

	Parser parser(tokens);
	std::optional<NodeProg> prog = parser.ParseProgram();

	if (!prog.has_value())
	{
		std::cerr << "Invalid program, no instructions detected" << std::endl;
		exit(EXIT_FAILURE);
	}

	// check if there already is an out file
	if (std::filesystem::exists("out.c") == 1)
	{
		E0204 err(Position{ 0, 0 });
	}

	Generator generator(prog.value());
	{
		std::fstream file("out.c", std::ios::out);
		file << generator.GenProg();
	}

	//! create file name that wont cause overriding
	//! give user option to choose output name
	std::string compiler = "gcc";
	std::string CfileName = "out.c";

	// create outputFileName
	std::string outputFileName;
	{
		size_t lastIDX = sourceFileName.find_last_of(".");
		outputFileName = sourceFileName.substr(0, lastIDX);
	}
	

	std::string command = compiler +  " -o " + outputFileName + " " + CfileName;
	
	const char* cmd = command.c_str();
	
	system(cmd);

	// delete out.c
	std::remove("out.c");

	return EXIT_SUCCESS;
}