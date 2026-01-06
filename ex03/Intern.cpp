#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other){(void)other;}
Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	int i = 0;

	while (i < 3 && formNames[i] != formName)
		i++;

	for (int j = 0; j < 3; j++)
	{
		if (j == i)
			continue;
		delete forms[j];
	}
	if (i == 3)
		throw std::runtime_error("can't find this Form " + formName);
	else
		std::cout << "Intern creates " + formName << std::endl;
	return forms[i];
}

