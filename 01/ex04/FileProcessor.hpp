#ifndef FILE_PROCESSOR_HPP
#define FILE_PROCESSOR_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileProcessor
{
	public:
	FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2);
	bool processFile();

	private:
	std::string filename;
	std::string searchString;
	std::string replaceString;
	std::ifstream inputFile;

	bool openInputFile();
	bool openOutputFile();
	void findAndReplace(std::string &line);
	void processline();
	void closeFiles();
};

#endif