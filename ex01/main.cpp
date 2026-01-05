#include "Form.hpp"
int main ()
{

	try
	{
		std::cout << "========================| Bureaucrat |==================="<<std::endl;
		Bureaucrat Bureaucrat1("oualid", 2);
		std::cout << Bureaucrat1 << std::endl;
		Bureaucrat Bureaucrat2("ahmed", 20);
		std::cout << Bureaucrat2 << std::endl << std::endl;

		std::cout << "========================| forms |========================"<<std::endl;
		Form form("Tax", 10, 120);
		std::cout<< form << std::endl;
		Form form2("Dariba", 15, 34);
		std::cout<< form2 << std::endl<< std::endl;

		std::cout << "=====================| sign Form or not |================"<<std::endl;
		Bureaucrat1.signForm(form);
		std::cout<<form << std::endl;
		Bureaucrat2.signForm(form2);
		std::cout<<form2 << std::endl<< std::endl;
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

