#pragma once
#include <iostream>


class Bureaucrat
{
	private:
		const std::string name;
		unsigned int grade;	
	
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
		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//methodes getter
		const std::string getName();
		const unsigned int& getGrade();
		void setGrade(int grade);

		void incrementGrade();
    	void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);