#include "Bureaucrat.hpp"
int main ()
{
	
	try
	{
		Bureaucrat obj("oualid");
		obj.setGrade(150);
		std::cout << obj << std::endl;
		obj.decrementGrade();
		std::cout << obj << std::endl;
		obj.decrementGrade();
		std::cout << obj << std::endl;

		// obj.setGrade(0);
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
