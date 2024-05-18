#include "../include/Bureaucrat.hpp"

int main()
{
    try
    {
        // std::cout << "\n" << std::endl;
        Bureaucrat john("John", 40);
        std::cout << john << std::endl;

        Bureaucrat ceo("CEO", 1);
        std::cout << ceo << std::endl;
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;

        try
        {
            std::cout << ceo;
            ceo.incrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "\n" << std::endl;
            std::cout << intern;
            intern.decrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n" << std::endl;
        Form f1("Form1", 45, 50);
        std::cout << f1 << std::endl;

        try
        {
            std::cout << "\n" << std::endl;
            john.signForm(&f1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << f1 << std::endl;
        try
        {
            std::cout << "\n" << std::endl;
            ceo.signForm(&f1);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << f1 << std::endl;

        std::cout << "\n" << std::endl;
        Form f2("Form2", 45, 35);
        std::cout << f2 << std::endl;
        try
        {
            std::cout << "\n" << std::endl;
            intern.signForm(&f2);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << f2 << std::endl;

        Bureaucrat cloneJohn(john);
        std::cout << cloneJohn << std::endl;
        Bureaucrat assignedIntern = intern;
        std::cout << assignedIntern << std::endl;

        Form f3(f1);
        std::cout << f3 << std::endl;
        Form assignedForm = f2;
        std::cout << assignedForm << std::endl;

        try
        {
            std::cout << "\n" << std::endl;
            ceo.signForm(&f3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << f3 << std::endl;

        try
        {
            std::cout << "\n" << std::endl;
            std::cout << intern << std::endl;
            intern.signForm(&f3);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << f3 << std::endl;

        try
        {
            std::cout << "\n" << std::endl;
            std::cout << intern << std::endl;
            intern.signForm(&assignedForm);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << assignedForm << std::endl;

    } catch (const std::exception &e)
    {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}