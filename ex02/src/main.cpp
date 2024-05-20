/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:02:00 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 23:10:47 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main()
{
    srand(time(0));
    std::cout << "\n" << std::endl;
    try {
        Bureaucrat highRank("HighRank", 1);
        std::cout << highRank << std::endl;
        Bureaucrat midRank("MidRank", 75);
        std::cout << midRank << std::endl;
        Bureaucrat lowRank("LowRank", 150);
        std::cout << lowRank << std::endl;

        PresidentialPardonForm form1("Target1");
        std::cout << form1 << std::endl;
        RobotomyRequestForm form2("Target2");
        std::cout << form2 << std::endl;
        ShrubberyCreationForm form3("Target3");
        std::cout << form3 << std::endl;

        try
        {
            std::cout << "\n" << std::endl;
            lowRank.signForm(&form1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            midRank.signForm(&form2);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            highRank.signForm(&form3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            highRank.executeForm(form1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            midRank.executeForm(form2);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            lowRank.executeForm(form3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            highRank.signForm(&form1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            highRank.executeForm(form1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "\n" << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            highRank.executeForm(form3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "\n" << std::endl;
        }

        std::cout << highRank.getName() << " grade: " << highRank.getGrade() << std::endl;
        std::cout << "Execution grade: " << form2.getExecGrade() << std::endl;
        for (int i = 0; i < 10; i++) {
            try
            {
                std::cout << "\n" << std::endl;
                highRank.executeForm(form2);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        std::cout << "\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}