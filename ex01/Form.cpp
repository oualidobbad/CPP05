#pragma once
#include <iostream>


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
};

Form::Form(): name(""), isSigned(false), gradeSign(0), gradeExecute(0){}

Form::Form(const std::string& name, int gSigne, int gExe): name(name), isSigned(false), gradeSign(gSigne), gradeExecute(gExe){}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}

Form& Form::operator=(const Form& other)
{
	throw "you cannot use assignement operator because you have const attribute";
}

Form::~Form()
{
}
