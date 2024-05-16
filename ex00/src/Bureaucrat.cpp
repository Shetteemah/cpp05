#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {}

const std::string Bureaucrat::getName() const {}
int Bureaucrat::getGrade() const {}

void Bureaucrat::incrementGrade() {}
void Bureaucrat::decrementGrade() {}
