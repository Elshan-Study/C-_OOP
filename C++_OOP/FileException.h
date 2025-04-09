#pragma once
#include <iostream>
#include <string>

class FileException : public std::exception
{
private:
    std::string _msg;
public:
    FileException(const std::string& msg) : _msg(msg) {}

    char const* what() const noexcept override
    {
        return _msg.c_str();
    }
};

class FileOpenException : public FileException {
public:
    explicit FileOpenException(const std::string& message = "FileOpenException: Failed to open file!") : FileException(message) {}
};

class FileReadException : public FileException {
public:
    explicit FileReadException(const std::string& message = "FileReadException: Error reading file!") : FileException(message) {}
};