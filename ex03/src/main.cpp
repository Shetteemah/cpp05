/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:53:27 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:56:25 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    srand(time(0));
    std::cout << "\n" << std::endl;
    try
    {
        Bureaucrat highRank("HighRank", 1);
        std::cout << highRank << std::endl;
        Bureaucrat midRank("MidRank", 75);
        std::cout << midRank << std::endl;
        Bureaucrat lowRank("LowRank", 150);
        std::cout << lowRank << std::endl;

        Intern intern;
        // std::cout << "\n" << std::endl;
        AForm *forms[4];
        std::cout << "\n" << std::endl;

        forms[0] = intern.makeForm("PresidentialPardonForm", "Target1");
        std::cout << "\n" << std::endl;
        forms[1] = intern.makeForm("RobotomyRequestForm", "Target2");
        std::cout << "\n" << std::endl;
        forms[2] = intern.makeForm("ShrubberyCreationForm", "Target3");
        std::cout << "\n" << std::endl;
        forms[3] = intern.makeForm("Haitian form", "Target4");

        for (int i = 0; i < 3; ++i)
        {
            std::cout << "\n" << std::endl;
            std::cout << *forms[i] << std::endl;
        }

        try
        {
            std::cout << "\nAttempt to create an invalid form" << std::endl;
            if (!forms[3])
                std::cout << "Form creation failed as expected for invalid form type." << std::endl;
            else
                std::cout << *forms[3] << "\n" << std::endl;
        }
        catch (const std::exception &e)
        {
            // std::cout << "\n" << std::endl;
            std::cout << e.what() << "\n" << std::endl;
        }

        std::cout << "\nSign and execute forms with different Bureaucrats tests\n" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "Processing form: " << forms[i]->getName() << "\n" << std::endl;
            try
            {
                lowRank.signForm(forms[i]);
                lowRank.executeForm(*forms[i]);
                std::cout << "\n" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n" << std::endl;
            }

            try
            {
                midRank.signForm(forms[i]);
                midRank.executeForm(*forms[i]);
                std::cout << "\n" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n" << std::endl;
            }

            try
            {
                highRank.signForm(forms[i]);
                highRank.executeForm(*forms[i]);
                std::cout << "\n" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n" << std::endl;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            std::cout << "\n" << std::endl;
            delete forms[i];
        }
        
        std::cout << "\ninvalid Bureaucrat grades tests\n" << std::endl;
        try
        {
            Bureaucrat invalidHigh("InvalidHigh", 0);
            std::cout << "\n" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << "\n" << std::endl;
        }

        try
        {
            Bureaucrat invalidLow("InvalidLow", 151);
            std::cout << "\n" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nEdge cases tests\n" << std::endl;
        try
        {
            Bureaucrat edgeHigh("EdgeHigh", 1);
            Bureaucrat edgeLow("EdgeLow", 150);
            PresidentialPardonForm form("EdgeCase");

            edgeHigh.signForm(&form);
            edgeHigh.executeForm(form);

            edgeLow.signForm(&form);
            edgeLow.executeForm(form);

            edgeLow.incrementGrade();
            edgeLow.signForm(&form);
            std::cout << "\n" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nTests completed.\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
