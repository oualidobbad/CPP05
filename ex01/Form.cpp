#include "Form.hpp"

// ==========================| Orthodox Canonical Form |=============================
Form::Form(): name(""), isSigned(false), gradeSign(1), gradeExecute(1){}

Form::Form(const std::string& name, int gSigne, int gExe): name(name), isSigned(false), gradeSign(gSigne), gradeExecute(gExe)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}

Form& Form::operator=(const Form& other)
{
	(void) other;
	throw "you cannot use assignement operator because you have const attribute";
}

Form::~Form(){}

// ================================  | getters |===============================
const std::string& Form::getName() const{
	return name;
}
const bool& Form::getIsSigned() const {
	return isSigned;
}
const int& Form::getGradeSign() const {
	return gradeSign;
}
const int& Form::getGradeExecute() const {
	return gradeExecute;
}

// =====================| member function |==========================
void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > gradeSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

// ================================== | Netsed class |===============================
const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}
const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form " << form.getName() + ", sign grade:" << form.getGradeSign() << ", exec grade: "<< form.getGradeExecute() << " signed: " << (form.getIsSigned() ? "Yes" : "No");
	return out;
}