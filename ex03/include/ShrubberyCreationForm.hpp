#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm const &operator=(const ShrubberyCreationForm &src);
        void execute(const Bureaucrat &exec) const;
        const std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif