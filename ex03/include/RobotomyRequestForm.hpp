#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm const &operator=(const RobotomyRequestForm &src);
        void execute(const Bureaucrat &exec) const;
        const std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif