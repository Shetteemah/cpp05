#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
int main()
{
    std::cout << "\n" << std::endl;
    try {
        Bureaucrat highRank("HighRank", 1);
        std::cout << highRank << std::endl;
        Bureaucrat midRank("MidRank", 75);
        std::cout << midRank << std::endl;
        Bureaucrat lowRank("LowRank", 150);
        std::cout << lowRank << std::endl;

        PresidentialPardonForm form1("Target1");
        std::cout << form1 << std::endl;
        RobotomyRequestForm form2("Target2");
        std::cout << form2 << std::endl;
        ShrubberyCreationForm form3("Target3");
        std::cout << form3 << std::endl;

        std::cout << "\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}