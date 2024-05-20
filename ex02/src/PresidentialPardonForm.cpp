/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:52:14 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:52:15 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default") 
{
    std::cout << "PresidentialPardonForm: " << this->getName() << " created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    if (this->getSignedGrade() < 1 || this->getExecGrade() < 1)
        throw GradeTooHighException();
    else if (this->getSignedGrade() > 150 || this->getExecGrade() > 150)
        throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("Presidential Pardon Form", 25, 5), _target(src.getTarget())
{
    std::cout << "PresidentialPardonForm: copy constructor initiated" << std::endl;
    std::cout << src.getName() << " Successfully copied to " << this->getName() << "!" << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: " << this->getName() << " destroyed!" << std::endl;
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "PresidentialPardonForm: assignment operator initiated" << std::endl;
    this->AForm::operator=(src);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &exec) const
{
    if (exec.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox!" << std::endl;
}

const std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
    os << form.getName() << " Details" << std::endl;
    os << "Form grade: " << form.getSignedGrade();
    os << "\nSigned state: " << (form.getSignedState() ? "true" : "false");
    os << "\nExecution grade: " << form.getExecGrade();
    os << "\nSigned grade: " << form.getSignedGrade() << std::endl;
    return (os);
}
