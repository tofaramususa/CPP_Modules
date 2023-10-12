#include "FileProcessor.hpp"

FileProcessor::FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2) : filename(filename), searchString(s1), replaceString(s2) {}

bool FileProcessor::processFile()
{
	if(!openInputFile())
	{
		std::cout << "Error: Unable to open input file: " << filename << std::endl;
		return (false);
	}
	processline();
	closeFiles();
	return (true);
}

void FileProcessor::processline()
{
	std::string line;
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());

	while(!inputFile.eof())
	{
		std::getline(inputFile, line);
		findAndReplace(line);
		outputFile << line << std::endl;
	}
	outputFile.close();
}

bool FileProcessor::openInputFile()
{
	inputFile.open(filename);
	return inputFile.is_open();
}

void FileProcessor::findAndReplace(std::string &line)
{
	for(size_t i = 0;;)
	{
		i = line.find(searchString, i);
		if(i == std::string::npos)
			break;
		line.erase(i, searchString.length());
		line.insert(i, replaceString);
	}

}

void FileProcessor::closeFiles()
{
	inputFile.close();
}