#ifndef WORKFLOW_FILEDOESNOTEXISTEXCEPTION_H
#define WORKFLOW_FILEDOESNOTEXISTEXCEPTION_H



class FileDoesNotExistException : public std::exception {
    std::string exception;
public:
    FileDoesNotExistException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override {
        return exception.c_str();
    }
};

#endif