/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:53:14 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:55:07 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;
class Bureaucrat;

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