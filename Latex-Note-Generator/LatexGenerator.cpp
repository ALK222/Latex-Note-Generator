#include "LatexGenerator.hpp"


LatexGenerator::LatexGenerator(std::string path, std::string author, std::string subject, std::string acron) {
	_path = path;
	_author = author;
	_subject = subject;
	_acron = acron;
}

void LatexGenerator::generateProject()
{
	try
	{
		generatePath();
		generateSubPaths();
		generateMainFile();
	}
	catch (const std::exception& e)
	{
		throw e;
	}
	
}


void LatexGenerator::generatePath() {
	try
	{
		if (!std::filesystem::exists(_path + "\\" + _acron)) {
			std::filesystem::create_directory(_path + "\\" + _acron);
		}
		else {
			std::cout << "Directory already exists" << std::endl;
		}

	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

void LatexGenerator::generateSubPaths() {
	try
	{
		if (!std::filesystem::exists(_path + "\\" + _acron + "\\Temas")) {
			std::filesystem::create_directory(_path + "\\" + _acron + "\\Temas");
		}
		else {
			std::cout << "Directory already exists" << std::endl;
		}

		if (!std::filesystem::exists(_path + "\\" + _acron + "\\Imagenes")) {
			std::filesystem::create_directory(_path + "\\" + _acron + "\\Imagenes");
		}
		else {
			std::cout << "Directory already exists" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

void LatexGenerator::generateMainFile() {
	try
	{
		time_t t;
		std::time(&t);
		tm* aTime = localtime(&t);
		if (!std::filesystem::exists(_path + "\\" + _acron + "\\" + _acron + ".tex")) {
			std::ofstream outfile(_path + "\\" + _acron + "\\" + _acron + ".tex");
			outfile << "\\documentclass{article}" << std::endl;
			outfile << "\\usepackage[utf8]{inputenc}" << std::endl;
			outfile << "\\usepackage[spanish]{babel}" << std::endl;
			outfile << "\\usepackage[margin=0.8in]{geometry}" << std::endl;
			outfile << "\\usepackage{ragged2e}" << std::endl;
			outfile << std::endl;
			outfile << "\\justifying" << std::endl;
			outfile << "\\title{" + _subject + "}" << std::endl;
			outfile << "\\author{" + _author + "}" << std::endl;
			outfile << "\\date{" + monthToString(aTime->tm_mon + 1) + " " + std::to_string(aTime->tm_year) + '}' << std::endl;
			outfile << std::endl;
			outfile << "\\begin{document}" << std::endl;
			outfile << "\\maketitle" << std::endl;
			outfile << "\\newpage" << std::endl;
			outfile << "\\end{document}" << std::endl;
			outfile.close();
			delete aTime;
		}
		else {
			std::cout << "Directory already exists" << std::endl;
		}

	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

std::string LatexGenerator::monthToString(int month) {
	switch (month)
	{
	case 1: 
		return "Enero";
	case 2:
		return "Febrero";
	case 3:
		return "Marzo";
	case 4:
		return "Abril";
	case 5:
		return "Mayo";
	case 6:
		return "Junio";
	case 7:
		return "Julio";
	case 8:
		return "Agosto";
	case 9: 
		return "Septiembre";
	case 10:
		return "Octubre";
	case 11: 
		return "Noviembre";
	case 12:
		return "Diciembre";
	default:
		return "Enero";
	}
	return "Enero";
}


