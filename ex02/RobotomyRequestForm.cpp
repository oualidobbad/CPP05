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