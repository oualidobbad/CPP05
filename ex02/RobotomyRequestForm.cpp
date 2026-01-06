#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm(target, 72, 45)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other){

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	AForm::operator=(other);
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeExacte() const
{
	int randoNumber = std::rand() % 11;

	std::cout << "hererererererererererererererererererererereererererererer" << std::endl;
	if (randoNumber <= 5)
		std::cout << getName() + ": has been robotomized successfully 50% of the time."<<std::endl;
	else
		std::cout << "Robotomy on " + getName() + " failed." <<std::endl;

}
