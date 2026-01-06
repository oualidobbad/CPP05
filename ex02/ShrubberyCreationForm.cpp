#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeExacte() const
{

	std::ofstream file;
	
	std::string tree = 
	"      ccee88oo\n"
	"  C8O8O8Q8PoOb o8oo\n"
	" dOB69QO8PdUOpugoO9bD\n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\\\  douUP\n"
	"        \\\\\\\\\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   . .... //||||\\... .\n";

	std::string name_file = getName() + "_shrubbery";
	file.open(name_file.c_str());
	if (file.is_open())
	{
		file << tree;
	}
	else
		throw "creation of file failed";
	file.close();
}
