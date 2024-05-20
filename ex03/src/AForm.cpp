/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:53:19 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:56:15 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signedGrade(150), _execGrade(150)
{
    std::cout << "AForm: " << this->getName() << " created!" << std::endl;
}

AForm::AForm(const std::string &name, int signedGrade, int execGrade) : _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade)
{
    std::cout << "AForm: " << this->getName() << " created!" << std::endl;
    if (_signedGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    else if (_signedGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName() + ("_copy")), _signed(src.getSignedState()), _signedGrade(src.getSignedGrade()), _execGrade(src.getExecGrade())
{
    std::cout << "AForm: copy constructor initiated" << std::endl;
    std::cout << src.getName() << " Successfully copied to " << this->getName() << "!" << std::endl;
    *this = src;
}

AForm::~AForm()
{
    std::cout << "AForm: " << this->getName() << " destroyed!" << std::endl;
}

AForm const &AForm::operator=(const AForm &src)
{
    std::cout << "AForm: assignment operator initiated" << std::endl;
    this->_signed = src.getSignedState();
    return (*this);
}

const std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getSignedGrade() const
{
    return (this->_signedGrade);
}

int AForm::getExecGrade() const
{
    return (this->_execGrade);
}

int AForm::getSignedState() const
{
    return (this->_signed);
}

void AForm::beSigned(const Bureaucrat *bureau)
{
    std::cout << bureau->getName() << " attempting to sign " << this->getName() << "..." << std::endl;
    if (bureau->getGrade() > this->getSignedGrade())
    {
        std::cout << bureau->getName() << " cannot sign " << this->getName() << ". ";
        throw GradeTooLowException();
    }
    else if (this->getSignedState())
    {
        std::cout << this->getName() << " is already signed!" << std::endl;
        return ;
    }
    _signed = true;
    std::cout << bureau->getName() << " signed " << this->getName() << "!" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << Aform.getName() << " Details" << std::endl;
    os << "AForm grade: " << Aform.getSignedGrade();
    os << "\nSigned state: " << (Aform.getSignedState() ? "true" : "false");
    os << "\nExecution grade: " << Aform.getExecGrade();
    os << "\nSigned grade: " << Aform.getSignedGrade() << std::endl;
    return (os);
}
