#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <time.h>

class LatexGenerator
{
public:
	LatexGenerator(std::string path, std::string author, std::string subject, std::string acron);
	void generateProject();
	void generatePath();
	void generateSubPaths();
	void generateMainFile();
	std::string monthToString(int month);
private:
	std::string _path;
	std::string _author;
	std::string _subject;
	std::string _acron;
};



