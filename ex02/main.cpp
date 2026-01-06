#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
int main ()
{

	try
	{
		std::srand(std::time(NULL));
		ShrubberyCreationForm shrubbery("home");
		// PresidentialPardonForm p("hokoma");
		// RobotomyRequestForm r("oobbad");

		AForm *form = &shrubbery;
		Bureaucrat b("oualid", 44);

		b.executeForm(*form);
		b.signForm(*form);
		b.executeForm(*form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const char *msj)
	{
		std::cerr << msj << std::endl;
	}
}

