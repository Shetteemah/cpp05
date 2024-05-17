#include "../include/Bureaucrat.hpp"

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

        std::cout << "\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}