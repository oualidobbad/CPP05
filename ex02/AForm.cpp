#include "AForm.hpp"

// ==========================| Orthodox Canonical Form |=============================
AForm::AForm(): name(""), isSigned(false), gradeSign(1), gradeExecute(1){}

AForm::AForm(const std::string& name, int gSigne, int gExe): name(name), isSigned(false), gradeSign(gSigne), gradeExecute(gExe)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	(void) other;
	throw "you cannot use assignement operator because you have const attribute";
}

AForm::~AForm(){}

// ================================  | getters |===============================
const std::string& AForm::getName() const{
	return name;
}
const bool& AForm::getIsSigned() const {
	return isSigned;
}
const int& AForm::getGradeSign() const {
	return gradeSign;
}
const int& AForm::getGradeExecute() const {
	return gradeExecute;
}

// =====================| member function |==========================
void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > gradeSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

// ================================== | Netsed class |===============================
const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}
const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
		throw "The Form Not Signed";
	executeExacte(executor);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form " << form.getName() + ", sign grade:" << form.getGradeSign() << ", exec grade: "<< form.getGradeExecute() << " signed: " << (form.getIsSigned() ? "Yes" : "No");
	return out;
}