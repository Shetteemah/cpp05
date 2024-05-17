#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    srand(time(0));
    std::cout << "\n" << std::endl;
    try
    {
        Bureaucrat highRank("HighRank", 1);
        std::cout << highRank << std::endl;
        Bureaucrat midRank("MidRank", 75);
        std::cout << midRank << std::endl;
        Bureaucrat lowRank("LowRank", 150);
        std::cout << lowRank << std::endl;

        Intern intern;
        AForm* forms[4];
        
        forms[0] = intern.makeForm("presidential pardon", "Target1");
        forms[1] = intern.makeForm("robotomy request", "Target2");
        forms[2] = intern.makeForm("shrubbery creation", "Target3");
        forms[3] = intern.makeForm("invalid form", "Target4");

        for (int i = 0; i < 3; ++i)
        {
            std::cout << *forms[i] << std::endl;
        }

        try
        {
            std::cout << "\nAttempt to create an invalid form" << std::endl;
            if (!forms[3])
            {
                std::cout << "Form creation failed as expected for invalid form type." << std::endl;
            } else {
                std::cout << *forms[3] << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nSign and execute forms with different Bureaucrats tests" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "\nProcessing form: " << forms[i]->getName() << std::endl;
            try
            {
                lowRank.signForm(forms[i]);
                lowRank.executeForm(*forms[i]);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }

            try
            {
                midRank.signForm(forms[i]);
                midRank.executeForm(*forms[i]);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }

            try
            {
                highRank.signForm(forms[i]);
                highRank.executeForm(*forms[i]);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            delete forms[i];
        }
        
        std::cout << "\ninvalid Bureaucrat grades tests" << std::endl;
        try
        {
            Bureaucrat invalidHigh("InvalidHigh", 0);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            Bureaucrat invalidLow("InvalidLow", 151);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nEdge cases tests" << std::endl;
        try
        {
            Bureaucrat edgeHigh("EdgeHigh", 1);
            Bureaucrat edgeLow("EdgeLow", 150);
            PresidentialPardonForm form("EdgeCase");

            edgeHigh.signForm(&form);
            edgeHigh.executeForm(form);

            edgeLow.signForm(&form);
            edgeLow.executeForm(form);

            edgeLow.incrementGrade();
            edgeLow.signForm(&form);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nTests completed.\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
