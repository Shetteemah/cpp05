/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:51:42 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:51:43 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string   _name;
        bool                _signed;
        const int           _signedGrade;
        const int           _execGrade;
        AForm();
        AForm(const std::string &name, int signedGrade, int execGrade);

    public:
        AForm(const AForm &src);
        virtual ~AForm();
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