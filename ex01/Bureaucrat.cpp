#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade):name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (&other != this)
	{
		throw "you cannot use assignement operator because you have const attribute";
	}
	return *this;
}

const std::string Bureaucrat::getName()
{
	return name;
}

const int& Bureaucrat::getGrade()
{
	return grade;
}
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Form& form)
{
	try{
		form.beSigned(*this);
		std::cout << name + " signed " + form.getName() + " successfully"<<std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << name <<" couldn’t sign "<< form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}


std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}