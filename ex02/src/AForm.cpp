#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signedGrade(150), _execGrade(150)
{
    std::cout << "Form: " << this->getName() << " created!" << std::endl;
}

Form::Form(const std::string &name, int signedGrade, int execGrade) : _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade)
{
    std::cout << "Form: " << this->getName() << " created!" << std::endl;
    if (_signedGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    else if (_signedGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName() + ("_copy")), _signed(src.getSignedState()), _signedGrade(src.getSignedGrade()), _execGrade(src.getExecGrade())
{
    std::cout << "Form: copy constructor initiated" << std::endl;
    std::cout << src.getName() << " Successfully copied to " << this->getName() << "!" << std::endl;
    *this = src;
}

Form::~Form()
{
    std::cout << "Form: " << this->getName() << " destroyed!" << std::endl;
}

Form const &Form::operator=(const Form &src)
{
    std::cout << "Form: assignment operator initiated" << std::endl;
    this->_signed = src.getSignedState();
    return (*this);
}

const std::string Form::getName() const
{
    return (this->_name);
}

int Form::getSignedGrade() const
{
    return (this->_signedGrade);
}

int Form::getExecGrade() const
{
    return (this->_execGrade);
}

int Form::getSignedState() const
{
    return (this->_signed);
}

void Form::beSigned(const Bureaucrat *bureau)
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

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << " Details" << std::endl;
    os << "Form grade: " << form.getSignedGrade();
    os << "\nSigned state: " << (form.getSignedState() ? "true" : "false");
    os << "\nExecution grade: " << form.getExecGrade();
    os << "\nSigned grade: " << form.getSignedGrade() << std::endl;
    return (os);
}
