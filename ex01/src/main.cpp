#include "../include/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat defaultBureaucrat;
        std::cout << defaultBureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr <<  e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat validBureaucrat("John", 50);
        std::cout << validBureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat tooHighBureaucrat("Yusuf", 1);
        std::cout << tooHighBureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat tooLowBureaucrat("Robert", 150);
        std::cout << tooLowBureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat original("Original", 75);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << "Copy: " << copy << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error with copy constructor: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat bureaucrat1("Bureaucrat1", 75);
        Bureaucrat bureaucrat2("Bureaucrat2", 100);
        std::cout << bureaucrat1 << bureaucrat2 << std::endl;
        bureaucrat2 = bureaucrat1;
        std::cout << "After assignment:\n" << bureaucrat1 << bureaucrat2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error with assignment operator: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat gradeTest("Tester", 5);
        std::cout << gradeTest << std::endl;
        for (int i = gradeTest.getGrade(); i > 1; i++)
        {
            gradeTest.incrementGrade();
            std::cout << gradeTest << std::endl;
        }
        gradeTest.incrementGrade();
        std::cout << gradeTest << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n" << std::endl;
        Bureaucrat lowTest("LowTester", 149);
        std::cout << lowTest << std::endl;
        for (int i = lowTest.getGrade(); i < 150; i++)
        {
            lowTest.decrementGrade();
            std::cout << lowTest << std::endl;
        }
        lowTest.decrementGrade();
        std::cout << lowTest << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
