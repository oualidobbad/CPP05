#pragma once

#include <iostream>

class Form;

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
		const std::string getName();
		const int& getGrade();

		void incrementGrade();
    	void decrementGrade();
		void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);