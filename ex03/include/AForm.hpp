#ifndef AFORM_HPP
#define AFORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signedGrade;
        const int           _execGrade;

    public:
        AForm();
        AForm(const std::string &name);
        AForm(int signedGrade, int execGrade);
        AForm(const std::string &name, int signedGrade, int execGrade);
        AForm(const AForm &src);
        ~AForm();
        AForm const &operator=(const AForm &src);
        const std::string getName() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        int getSignedState() const;
        void beSigned(const Bureaucrat *bureau);
        virtual void execute(const Bureaucrat &exec) const = 0;

    class GradeTooHighException : virtual public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : virtual public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);
#endif