#include "Form.hpp"
int main ()
{
	
	try
	{
		Bureaucrat Bureaucrat1("oualid", 120);
		Form form("Tax", 130, 120);

		Bureaucrat1.signForm(form);
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

