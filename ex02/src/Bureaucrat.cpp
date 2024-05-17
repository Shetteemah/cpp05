#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
    std::cout << "Default Bureaucrat created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "Bureaucrat: " << this->getName() << " created!" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(("Cloned_") + src.getName()), _grade(src.getGrade())
{
    std::cout << "Bureaucrat: copy constructor initiated" << std::endl;
    *this = src;
    std::cout << src.getName() << " Successfully copied to " << this->_name << "!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->getName() << " is destroyed!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (!(this == &src))
    {
        this->_grade = src._grade;
        std::cout << "Bureaucrat: operator assignment done!" << std::endl;
    }
    return (*this);
}

const std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade < 2)
    {
        std::cout << "Cannot increase beyond 1! ";
        throw GradeTooHighException();
    }
    else
    {
        this->_grade--;
        std::cout << "Grade increased +1!" << std::endl;   
    }
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade > 149)
    {
        std::cout << "Cannot decrease beyond 150! ";
        throw GradeTooLowException();
    }
    else
    {
        this->_grade++;
        std::cout << "Grade decreased -1!" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade = " << bureaucrat.getGrade() << "." << std::endl;
    return (os);
}

void Bureaucrat::signForm(AForm *form)
{
    form->beSigned(this);
}
