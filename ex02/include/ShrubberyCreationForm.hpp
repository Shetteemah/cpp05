/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:51:56 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:51:57 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm const &operator=(const ShrubberyCreationForm &src);
        void execute(const Bureaucrat &exec) const;
        const std::string getTarget() const;
};

#endif