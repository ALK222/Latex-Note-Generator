/**
 *
 * @file Main.cpp
 *
 * @author Alejandro Barrachina Argudo
 *
 *
 * 
 */

#include <iostream>
#include "LatexGenerator.hpp"
#include "Main.hpp"



int main(int argc, const char *argv[])
{
	std::string author = "A.L.K.";
	std::string path = "D:\\Code\\LaTex-Stuff\\";
	std::string subject = "Ingenierķa del software 1";
	std::string acronym = "IS1";

	LatexGenerator* lg = new LatexGenerator(path, author, subject, acronym);
	lg->generateProject();
	delete lg;

	return 0;
}



