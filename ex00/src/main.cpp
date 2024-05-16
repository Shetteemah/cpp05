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
    return 0;
}
