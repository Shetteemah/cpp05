#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureau);

#endif