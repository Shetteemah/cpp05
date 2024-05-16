#include "Bureaucrat.hpp"

        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
