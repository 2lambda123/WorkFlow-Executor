#ifndef WORKFLOW_CANTOPENFILEEXCEPTION_H
#define WORKFLOW_CANTOPENFILEEXCEPTION_H

class CantOpenFileException : public std::exception {
    std::string exception;
public:
    CantOpenFileException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override {
        return exception.c_str();
    }
};

#endif