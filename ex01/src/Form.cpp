#include "Form.hpp"

        Form();
        Form(const std::string &name);
        Form(int signedGrade, int execGrade);
        Form(const std::string &name, int signedGrade, int execGrade);
        Form(const Form &src);
        ~Form();
        Form const &operator=(const Form &src);
        const std::string getName() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        int getSignedState() const;
        void beSigned(const Bureaucrat *bureau);
