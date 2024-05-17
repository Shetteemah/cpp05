#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm const &operator=(const PresidentialPardonForm &src);
        void execute(const Bureaucrat &exec) const;
        const std::string getTarget() const;
};
#endif