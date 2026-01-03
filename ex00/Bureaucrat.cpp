#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(): name(""), grade(1) {}
Bureaucrat::Bureaucrat(const std::string& name):name(name), grade(1) {}
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

const unsigned int& Bureaucrat::getGrade()
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}