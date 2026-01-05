#pragma once
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExecute;

	public:
		Form();
		Form(const std::string& name, int gSigne, int gExe);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();
		const std::string& getName() const;
		const bool& getIsSigned() const;
		const int& getGradeSign() const;
		const int& getGradeExecute() const;
		void beSigned(Bureaucrat &b);

		class GradeTooHighException: public std::exception{
			public:
			const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
			const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Form& form);

