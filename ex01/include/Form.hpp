/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:50:53 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:50:54 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signedGrade;
        const int           _execGrade;

    public:
        Form();
        Form(const std::string &name);
        Form(int signedGrade, int execGrade);
        Form(const std::string &name, int signedGrade, int execGrade);
        Form(const Form &src);
        ~Form();
        Form const &operator=(const Form &src);
        const std::string getName() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        int getSignedState() const;
        void beSigned(const Bureaucrat *bureau);

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

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif