/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:53:37 by sheali            #+#    #+#             */
/*   Updated: 2024/05/20 22:56:43 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm: " << this->getName() << " created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    if (this->getSignedGrade() < 1 || this->getExecGrade() < 1)
        throw GradeTooHighException();
    else if (this->getSignedGrade() > 150 || this->getExecGrade() > 150)
        throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
    std::cout << "ShrubberyCreationForm: copy constructor initiated" << std::endl;
    std::cout << src.getName() << " Successfully copied to " << this->getName() << "!" << std::endl;
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: " << this->getName() << " destroyed!" << std::endl;
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyCreationForm: assignment operator initiated" << std::endl;
    this->AForm::operator=(src);
    return (*this);
    std::cout << "ShrubberyCreationForm: operator assignment done!" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
    if (exec.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
    {
        std::ofstream file(this->getTarget() + "_shrubbery");
        file << "                                       ..........                                         " << std::endl; 
        file << "                                ..... ..... .... :....                                    " << std::endl;
        file << "                              :..::.::.:.:...:.:.......                                   " << std::endl;
        file << "                            .::::::::::..:::.:::.:::.:...:.                               " << std::endl;
        file << "                         .:..::::.:::::::::::::::::::::..::...:.                          " << std::endl;
        file << "                        .:..:.::.:::::::::::::..::.:::::.:..:..                           " << std::endl;
        file << "                         ..:--:::-::-::::::.::-:::..::::-:--:.:.                          " << std::endl;
        file << "                         :.. ::::::::::.....:::::::..:...:..:::..                         " << std::endl;
        file << "                ....     ..:.....:..:::::::: .::.:.:::.::.........                        " << std::endl;
        file << "                ........:..:   : ::::.  :   :.::::..:::::::... .:.                        " << std::endl;
        file << "                .....::. ..      ::..:::.  ..  ::::......                                 " << std::endl;
        file << "                :....:.....:.. :::. :::. .      . ...   ...                               " << std::endl;
        file << "           .....:..::.:::..:::::::..::.                                                   " << std::endl;
        file << "       .:..::.::::.:::::::-:-.:-:::.....                                                  " << std::endl;
        file << "      ..:.:..::::..:.::::::: :..::.       .    .                                          " << std::endl;
        file << "      .:::::::::::::::-:-..: :.:::.       ......   ...                                    " << std::endl;
        file << "       ..:::.:::::.:::.    ....::.:.     ..:: :::.::.:..... . :..                         " << std::endl;
        file << "           ...:.::.  ..  . ...:. :.......  :.:..:....:.......:....                        " << std::endl;
        file << "               ..       ....... :...:.         . ....:..:.......:.                        " << std::endl;
        file << "                ....  .....:::::...:::::.          ..:..:.:::..:::.                       " << std::endl;
        file << "                ........:....::........::.. . ..    ....:...... ....                      " << std::endl;
        file << "             ...:.........:............ ..:....:.  ..:.... ... ..                         " << std::endl;
        file << "         ... ..::::-:::: :.  ...::..::.:..:::.:::-:-:.::.:-:::::...                       " << std::endl;
        file << "        ........ .......      .:::..:..:.::..:..:..:::::.....:..:.:....:                  " << std::endl;
        file << "              .  ...        ...:::::::.::.:.::.:.  :::::::...:...:..::.......      .      " << std::endl;
        file << "                            :.:.:..:::..:.......      .::..  ....:...:...:.:........      " << std::endl;
        file << "                             .:.::.::.::..:  :        .-::       .::::::::::....::....    " << std::endl;
        file << "                              ......:..               .:::           ..  ...:::.:....     " << std::endl;
        file << "                             ....:...  .           .::::                    .:.......     " << std::endl;
        file << "                                .:...             :::::.                    .. ..  .      " << std::endl;
        file << "                                   ..            :.::.                                    " << std::endl;
        file << "                                               ::::.                                      " << std::endl;
        file << "                                             ..::.                                        " << std::endl;
        file << "                                           .:..:.                                         " << std::endl;
        file << "                                          ..:::                                           " << std::endl;
        file << "                                         .::.:                                            " << std::endl;
        file << "                                        ::::::                                            " << std::endl;
        file << "                                 .:::...::. :..:.                                         " << std::endl;
        file << "                      .... .........:....:.....................                           " << std::endl;
        file << "                    ...: ..:...:::..::. ...:.:...:..... .::.  ...                         " << std::endl;
        file << "                    ...::.........::::::....:: :::.......:........                        " << std::endl;
        file << "                    :.:::::::::::::::::::::.::.:::::::::::::::::..                        " << std::endl;
        file << "                      .:::.::.:::::::::::::::::::::::::::::::::.                          " << std::endl;
        file << "                       .....:.....:::::::::.::.:::::::::....:::                           " << std::endl;
        file << "                       .....:..:::..:::::::.::.:.:.:.:..:::.:.                            " << std::endl;
        file << "                        :::::::::-::-::::::::::::::::-::-:::::                            " << std::endl;
        file << "                        .........:..:..::......::::..:..:....                             " << std::endl;
        file << "                        .:.::.:::::::::::::.::.::::::::::::..                             " << std::endl;
        file << "                         .... ............. .................                             " << std::endl;
        file << "                         ...:.:.:::::::::::::::::::::::::::.                              " << std::endl;
        file << std::endl
                << std::endl;
        file.close();
    }
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << form.getName() << " Details" << std::endl;
    os << "Form grade: " << form.getSignedGrade();
    os << "\nSigned state: " << (form.getSignedState() ? "true" : "false");
    os << "\nExecution grade: " << form.getExecGrade();
    os << "\nSigned grade: " << form.getSignedGrade() << std::endl;
    return (os);
}
