#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const& executor) const;
};

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{

	if (getGradeExecute() < executor.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (!getIsSigned())
		throw "The Form Not Signed";
	
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


	file.open(getName() + "_shrubbery");
	if (file.is_open())
	{
		file << tree;
	}
	else
		throw "creation of file failed";
	file.close();
}
