#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other){

}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	AForm::operator=(other);
}

PresidentialPardonForm::~PresidentialPardonForm(){}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	if (!getIsSigned())
		throw "The Form Not Signed";

	std::cout << getName() <<  " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
