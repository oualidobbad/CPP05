#pragma once
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExecute;

	public:
		AForm();
		AForm(const std::string& name, int gSigne, int gExe);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		
		const std::string& getName() const;
		const bool& getIsSigned() const;
		const int& getGradeSign() const;
		const int& getGradeExecute() const;

		void execute(Bureaucrat const & executor) const;
		virtual void executeExacte(Bureaucrat const& executor) const = 0;
		virtual ~AForm();
		
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

std::ostream& operator<<(std::ostream& out, const AForm& form);

