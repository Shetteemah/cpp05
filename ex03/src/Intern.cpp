#include "../include/Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern Constructor initiated!" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "Intern copy constructor initiated!" << std::endl;
    *this = src;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed!" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    if (this == &src)
        return (*this);
    return (*this);
    std::cout << "Intern: operator assignment done!" << std::endl;
}

AForm *Intern::makeForm(const std::string &newForm, const std::string &target)
{
    AForm *forms[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    for (int i = 0; i < 3; i++)
    {
        if (newForm.compare(forms[i]->getName()) == 0)
        {
            std::cout << "Intern create " << *forms[i] << "!" << std::endl;
            return (forms[i]);
        }
    }
    std::cout << newForm << " couldn't be created!" << std::endl;
    return (0);
}
