#include "RobotomyRequestForm.hpp"

        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm const &operator=(const RobotomyRequestForm &src);
        void execute(const Bureaucrat &exec) const;
        const std::string getTarget() const;
