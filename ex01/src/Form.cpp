#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signedGrade(150), _execGrade(150)
{}

Form::Form(const std::string &name, int signedGrade, int execGrade) : _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade)
{}

Form::Form(const Form &src) : _name(src.getName() + ("_copy")), _signed(src.getSignedState()), _signedGrade(src.getSignedGrade()), _execGrade(src.getExecGrade())
{}

Form::~Form() {}

Form const &Form::operator=(const Form &src)
{}

const std::string Form::getName() const
{}

int Form::getSignedGrade() const
{}

int Form::getExecGrade() const
{}

int Form::getSignedState() const
{}

void Form::beSigned(const Bureaucrat *bureau)
{}

const char *Form::GradeTooHighException::what() const throw()
{}

const char *Form::GradeTooLowException::what() const throw()
{}

std::ostream &operator<<(std::ostream &os, const Form &form)
{}