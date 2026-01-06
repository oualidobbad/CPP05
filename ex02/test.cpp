#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

void testShrubbery()
{
	std::cout << "\n========== SHRUBBERY CREATION FORM TEST ==========" << std::endl;
	
	try
	{
		ShrubberyCreationForm shrubbery("garden");
		Bureaucrat lowGrade("Intern", 145);

		std::cout << shrubbery << std::endl;
		std:: cout << lowGrade << std::endl;
		
		// Test:  Try to execute without signing
		std::cout << "\n--- Test 1: Execute without signing ---" << std::endl;
		lowGrade.executeForm(shrubbery);
		
		// Test: Sign the form
		std::cout << "\n--- Test 2: Sign the form ---" << std::endl;
		lowGrade.signForm(shrubbery);
		
		// Test: Execute after signing
		std::cout << "\n--- Test 3: Execute after signing ---" << std::endl;
		lowGrade.executeForm(shrubbery);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomy()
{
	std::cout << "\n========== ROBOTOMY REQUEST FORM TEST ==========" << std::endl;
	
	try
	{
		RobotomyRequestForm robotomy("Bender");
		Bureaucrat goodGrade("Director", 40);
		Bureaucrat badGrade("Assistant", 80);
		
		std::cout << robotomy << std::endl;
		std::cout << goodGrade << std::endl;
		std::cout << badGrade << std::endl;
		
		// Test: Try to sign with too low grade
		std::cout << "\n--- Test 1: Sign with low grade (should fail) ---" << std::endl;
		badGrade.signForm(robotomy);
		
		// Test: Sign with good grade
		std::cout << "\n--- Test 2: Sign with good grade ---" << std::endl;
		goodGrade.signForm(robotomy);
		
		// Test: Execute multiple times to see randomness
		std::cout << "\n--- Test 3: Execute 5 times (check randomness) ---" << std::endl;
		for (int i = 1; i <= 5; i++)
		{
			std::cout << "\nAttempt " << i << ":" << std::endl;
			goodGrade.executeForm(robotomy);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception:  " << e.what() << std::endl;
	}
}

void testPresidential()
{
	std::cout << "\n========== PRESIDENTIAL PARDON FORM TEST ==========" << std::endl;
	
	try
	{
		PresidentialPardonForm pardon("Arthur Dent");
		Bureaucrat president("President", 1);
		Bureaucrat vicePresident("VP", 20);
		Bureaucrat manager("Manager", 50);
		
		std::cout << pardon << std::endl;
		std::cout << president << std::endl;
		std::cout << vicePresident << std::endl;
		
		// Test: Try to sign with too low grade
		std::cout << "\n--- Test 1: Sign with too low grade (should fail) ---" << std::endl;
		manager.signForm(pardon);
		
		// Test: Sign with good grade
		std::cout << "\n--- Test 2: Sign with VP (grade 20) ---" << std::endl;
		vicePresident.signForm(pardon);
		
		// Test: Try to execute with too low grade
		std::cout << "\n--- Test 3: Execute with VP (should fail, need grade 5) ---" << std::endl;
		vicePresident.executeForm(pardon);
		
		// Test: Execute with president
		std::cout << "\n--- Test 4: Execute with President (grade 1) ---" << std::endl;
		president. executeForm(pardon);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception:  " << e.what() << std::endl;
	}
}

void testPolymorphism()
{
	std::cout << "\n========== POLYMORPHISM TEST ==========" << std::endl;
	
	try
	{
		Bureaucrat god("God Mode", 1);
		
		// Create different forms
		ShrubberyCreationForm shrubbery("office");
		RobotomyRequestForm robotomy("Bob");
		PresidentialPardonForm pardon("Criminal");
		
		// Use polymorphism - treat all as AForm*
		AForm* forms[3];
		forms[0] = &shrubbery;
		forms[1] = &robotomy;
		forms[2] = &pardon;
		
		std::cout << "\n--- Sign and execute all forms polymorphically ---" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "\n>> Processing form " << (i + 1) << ":" << std::endl;
			std::cout << *forms[i] << std::endl;
			god.signForm(*forms[i]);
			god.executeForm(*forms[i]);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception:  " << e.what() << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << "\n========== EDGE CASES TEST ==========" << std::endl;
	
	try
	{
		std::cout << "\n--- Test 1: Sign already signed form ---" << std::endl;
		ShrubberyCreationForm form("test");
		Bureaucrat b1("Boss1", 100);
		Bureaucrat b2("Boss2", 100);
		
		b1.signForm(form);
		b2.signForm(form);  // Try to sign again
		
		std::cout << "\n--- Test 2: Execute twice ---" << std::endl;
		b1.executeForm(form);
		b1.executeForm(form);  // Execute again (should work)
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception:  " << e.what() << std::endl;
	}
}

int main()
{
	// Seed random number generator for robotomy
	std::srand(std::time(NULL));
	
	std::cout << "╔═══════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║         BUREAUCRAT FORM TESTING SUITE                ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════╝" << std::endl;
	
	// Run all tests
	testShrubbery();
	testRobotomy();
	testPresidential();
	testPolymorphism();
	testEdgeCases();
	
	std::cout << "\n╔═══════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║              ALL TESTS COMPLETED                      ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════╝" << std::endl;
	
	return 0;
}

