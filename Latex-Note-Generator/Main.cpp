/**
 *
 * @file Main.cpp
 *
 * @author Alejandro Barrachina Argudo
 *
 *
 * 
 */

#include "Main.hpp"



int main(int argc, const char* argv[])
{
	Data d;
	std::string path = std::filesystem::current_path().u8string();
	try
	{
		cxxopts::Options options(argv[0], "LaTeX note generator");
		options.add_options()
			("a, author", "Author of the notes", cxxopts::value<std::string>())
			("p, path", "Path for the folder to generate", cxxopts::value<std::string>()->default_value(path))
			("s, subject", "Name of the lesson", cxxopts::value<std::string>())
			("c, acronym", "Acronym of the lesson", cxxopts::value<std::string>())
			("h, help", "Print usage");
		parseOptions(options, d, argc, argv);
	}
	catch (const cxxopts::OptionException& e)
	{
		std::cout << "Error parsing options:" << e.what() << std::endl;
		exit(1);
	}
	
	LatexGenerator* lg = new LatexGenerator(d.path, d.author, d.subject, d.acronym);
	lg->generateProject();
	delete lg;

	return 0;
}

/**
 * @brief Parses the command line
 * @param option Parser
 * @param d Structure where the values are stored
 * @param argc Number of parameters to parse
 * @param argv Values to parse
*/
void parseOptions(cxxopts::Options option, Data& d, int& argc, const char* argv[])
{
	auto result = option.parse(argc, argv);

	if (argv[1] == NULL || result.count("help")) {
		std::cout << option.help() << std::endl;
		exit(0);
	}

	// Author parse
	if (!result.count("author")) {
		std::cout << "No author found" << std::endl;
		std::cout << option.help() << std::endl;
		exit(1);
	}
	else {
		d.author = result["author"].as<std::string>();
	}

	// Path parse
	if (result.count("path")) {
		d.path = result["path"].as<std::string>();
	}
	else{
		d.path = result["path"].as<std::string>();
	}

	// Subject parse

	if (!result.count("subject")) {
		std::cout << "No subject found" << std::endl;
		std::cout << option.help() << std::endl;
		exit(1);
	}
	else {
		d.subject = result["subject"].as<std::string>();
	}

	// Acronym parse
	if (result.count("acronym")) {
		d.acronym = result["acronym"].as<std::string>();
	}
	else {
		d.acronym = createAcronym(d.subject);
	}
}

/**
 * @brief Creates a subject acronym if not given one
 * @param subject Subject to generate the acronym
 * @return The first letter of every word in the subject
*/
std::string createAcronym(std::string subject) {
	std::string result = "";
	bool v = true;
	for (int i = 0; i < subject.length(); ++i) {
		if (subject[i] == ' ') {
			v = true;
		}
		else if (subject[i] != ' ' && v == true) {
			result.push_back(subject[i]);
			v = false;
		}
	}
	return result;
}
