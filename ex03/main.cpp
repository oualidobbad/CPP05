
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main ()
{
	std::srand(std::time(NULL));

	try
	{
		Intern inetrn;
		// AForm *form = inetrn.makeForm("robotomy request", "Bred");
		AForm *form = inetrn.makeForm("presidential pardon", "Alice");
		Bureaucrat b("oualid", 44);

		b.signForm(*form);
		b.executeForm(*form);
		delete form;
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

