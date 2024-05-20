/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:51:50 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:51:51 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;
class Bureaucrat;

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