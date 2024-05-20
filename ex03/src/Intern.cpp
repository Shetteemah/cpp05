/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:53:25 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:56:22 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Default Intern Constructor initiated!" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "Intern copy constructor initiated!" << std::endl;
    *this = src;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed!" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern: operator assignment initiated!" << std::endl;
    if (this == &src)
        return (*this);
    return (*this);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    for (int i = 0; i < 3; i++)
	{
        if (formNames[i] == formName)
		{
            std::cout << "Intern creates " << formNames[i] << std::endl;
            for (int j = 0; j < 3; j++)
                if (i != j)
                    delete forms[j];
            return forms[i];
        }
    }
    for (int i = 0; i < 3; i++)
        delete forms[i];
    std::cout << "Error: Form name " << formName << " is invalid!" << std::endl;
    return (NULL);
}
