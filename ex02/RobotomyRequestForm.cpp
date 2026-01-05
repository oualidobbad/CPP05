#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm(target, 72, 45)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other){

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	AForm::operator=(other);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	if (!getIsSigned())
		throw "The Form Not Signed";

	std::cout << "hererererererererererererererererererererereererererererer" << std::endl;

	int randoNumber = rand() % 10;
	if (randoNumber <= 5)
		std::cout << getName() + ": has been robotomized successfully 50% of the time."<<std::endl;
	else
		std::cout << "Robotomy on " + getName() + " failed." <<std::endl;

}
