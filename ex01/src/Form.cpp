#include "Form.hpp"

Form::Form() {}
Form::Form(const std::string &name) {}
Form::Form(int signedGrade, int execGrade) {}
Form::Form(const std::string &name, int signedGrade, int execGrade) {}
Form::Form(const Form &src) {}
Form::~Form() {}
Form const &Form::operator=(const Form &src) {}
const std::string Form::getName() const {}
int Form::getSignedGrade() const {}
int Form::getExecGrade() const {}
int Form::getSignedState() const {}
void Form::beSigned(const Bureaucrat *bureau) {}
const char *Form::GradeTooHighException::what() const throw() {}
const char *Form::GradeTooHighException::what() const throw() {}
