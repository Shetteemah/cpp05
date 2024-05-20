/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:52:17 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:52:18 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm: " << this->getName() << " created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    if (this->getSignedGrade() < 1 || this->getExecGrade() < 1)
        throw GradeTooHighException();
    else if (this->getSignedGrade() > 150 || this->getExecGrade() > 150)
        throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Robotomy Request Form", 72, 45), _target(src.getTarget())
{
    std::cout << "RobotomyRequestForm: copy constructor initiated" << std::endl;
    std::cout << src.getName() << " Successfully copied to " << this->getName() << "!" << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: " << this->getName() << " destroyed!" << std::endl;
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    std::cout << "RobotomyRequestForm: assignment operator initiated" << std::endl;
    this->AForm::operator=(src);
    return (*this);
    std::cout << "RobotomyRequestForm: operator assignment done!" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
    std::cout << exec.getName() << " grade: " << exec.getGrade() << std::endl;
    std::cout << "Execution grade: " << this->getExecGrade() << std::endl;
    if (exec.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
    {
        std::cout << "((((Grrr!!))))" << std::endl;
        if (rand() % 2 == 0)
            std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
        else
            std::cout << this->getTarget() << " robotomization failed!" << std::endl;
    }
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << form.getName() << " Details" << std::endl;
    os << "Form grade: " << form.getSignedGrade();
    os << "\nSigned state: " << (form.getSignedState() ? "true" : "false");
    os << "\nExecution grade: " << form.getExecGrade();
    os << "\nSigned grade: " << form.getSignedGrade() << std::endl;
    return (os);
}
