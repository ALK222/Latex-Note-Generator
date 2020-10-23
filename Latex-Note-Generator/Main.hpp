/**
 * 
 * @file Main.hpp
 *
 * @author Alejandro Barrachina Argudo
 *
 *
 *
 */

#pragma once
#include <string>
#include <iostream>
#include "LatexGenerator.hpp"
#include "cxxopts.hpp"
#include <filesystem>

/// <summary>
/// Stores the data for the folder generator
/// </summary>
struct Data
{
	std::string author;
	std::string path;
	std::string subject;
	std::string acronym;
};


void parseOptions(cxxopts::Options option, Data& d, int& argc, const char* argv[]);

std::string createAcronym(std::string subject);
