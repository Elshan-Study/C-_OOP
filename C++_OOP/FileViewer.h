#pragma once
#include <iostream>
#include <string>
#include "FileException.h"

class FileViewer
{
protected:
    FILE* OpenFile(const char* path, const char* mode) {
        FILE* file = nullptr;
        const errno_t err = fopen_s(&file, path, mode);
        if (!file) {
            throw FileOpenException();
        }
        return file;
    }

    void CheckReadError(FILE* file) {
        if (ferror(file)) { /*я узнал про то, что этот метод позволяет находить возможные ошибки*/
            throw FileReadException();
        }
    }

public:
    virtual ~FileViewer() = default;
    virtual void Display(const char* path) = 0;
};

class TextViewer : public FileViewer {
public:
    void Display(const char* path) override {
        FILE* file = OpenFile(path, "r");

        //char buffer[1024];
        //while (fgets(buffer, sizeof(buffer), file)) { /*я узнал про то, что этот метод выводит всю строку*/
        //    std::cout << buffer; 
        //}

        unsigned char buffer[1];
        while (fread(buffer, sizeof(buffer), 1, file)) {
            std::cout << buffer[0];
        }

        CheckReadError(file);
        fclose(file);
    }
};

class AsciiViewer : public FileViewer {
public:
    void Display(const char* path) override {
        FILE* file = OpenFile(path, "r");

        unsigned char buffer[1];  
        while (fread(buffer, sizeof(buffer), 1, file)) {
            std::cout << (int)(buffer[0]) << ' ';
        }

        std::cout << std::endl;
        CheckReadError(file);
        fclose(file);
    }
};

class BinaryViewer : public FileViewer {
public:
    void Display(const char* path) override {
        FILE* file = OpenFile(path, "r");

        /*HOW?*/
        /*unsigned char buffer[1];
        while (fread(buffer, sizeof(buffer), 1, file)) {
            for (int i = 7; i >= 0; --i) {
                std::cout << ((buffer[0] >> i) & 1);
            }
            std::cout << ' ';
        }*/

        std::cout << std::endl;
        CheckReadError(file);
        fclose(file);
    }
};
