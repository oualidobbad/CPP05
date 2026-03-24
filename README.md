# CPP05

C++ Module 05: exception handling with a Bureaucrat/Form hierarchy — grade validation, custom exceptions, three concrete form types, and an Intern factory.

## Project Overview
- What it does: models a bureaucratic system where Bureaucrats sign and execute Forms, with grade-range exceptions enforcing constraints.
- Core themes: custom exception classes, `try/catch`, abstract classes, factory pattern.

## Architecture & Design
- **ex00 (Bureaucrat)**: grade 1 (highest) to 150 (lowest); `GradeTooHighException`/`GradeTooLowException`; `increment()`/`decrement()`; `operator<<`.
- **ex01 (+Form)**: `Form` with `name`, `isSigned`, `gradeSign`, `gradeExecute`; `beSigned(Bureaucrat&)` checks grade.
- **ex02 (AForm + concrete forms)**: `AForm` abstract with `executeExacte() = 0`; `execute(Bureaucrat const&)` checks signed + grade. Three derived forms:
  - `ShrubberyCreationForm`: writes ASCII trees to `<target>_shrubbery`.
  - `RobotomyRequestForm`: 50% success robotomy message.
  - `PresidentialPardonForm`: unconditional pardon message.
- **ex03 (+Intern)**: `Intern::makeForm(name, target)` — factory that creates the correct form type by name.

## Core Concepts (with code)
- Abstract form with grade-guarded execution:
```cpp
// AForm.hpp
class AForm {
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExecute;
public:
    void execute(Bureaucrat const& executor) const;  // checks signed + grade
    virtual void executeExacte() const = 0;  // pure virtual
    void beSigned(Bureaucrat& b);  // checks gradeSign
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};
```

## Code Walkthrough
1) ex00: Bureaucrat constructor validates grade [1,150]; getters; increment/decrement with bounds checking.
2) ex01: Form stores two grade thresholds; `beSigned()` compares bureaucrat grade vs required.
3) ex02: `execute()` verifies form is signed AND bureaucrat grade <= gradeExecute; then calls `executeExacte()`.
4) ex03: Intern uses a string-to-constructor mapping (function pointer array or if-chain) to create forms.

## Installation & Setup
- `make` per exercise (C++98).

## Technical Deep Dive
- Nested exception classes inherit from `std::exception` with `what()` returning `const char*`.
- `const` member variables (`name`, grade thresholds) set in initializer list — immutable after construction.
- Intern factory avoids `switch` on strings (not available in C++98); uses parallel arrays of names and creator functions.

## Improvements & Future Work
- Add a form queue for batch processing by Bureaucrats.
- Add logging to track sign/execute history.

## Author
Oualid Obbad (@oualidobbad)