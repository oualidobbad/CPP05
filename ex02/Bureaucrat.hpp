#pragma once

#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;	
	
	public:
	//nested classes exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		//canonical Form
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//methodes getter
		const std::string getName() const;
		const int& getGrade() const;

		void incrementGrade();
    	void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);

void Bureaucrat::executeForm(AForm const & form) const{
	try
	{
		form.execute(*this);
		std::cout << getName() + " executed " + form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		
	}
}