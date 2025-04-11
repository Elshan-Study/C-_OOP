#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAX_SIZE = 100;

struct Student
{
    std::string name;
    int age;
    float scholarship;
};

struct StudentArray
{
    Student data[100];
    int count;
};

void writeStudentsToFile(const StudentArray& students, const std::string& fileName)
{
    std::ofstream outFile(fileName);

    if (!outFile)
    {
        return;
    }

    for (int i = 0; i < students.count; i++)
    {
        outFile << students.data[i].name << '\n'
            << students.data[i].age << '\n'
            << students.data[i].scholarship << '\n';
    }

    outFile.close();
}

void readStudentsFromFile(StudentArray& students, const std::string& fileName)
{
    std::ifstream inFile(fileName);

    if (!inFile)
    {
        return;
    }

    students.count = 0;

    while (students.count < MAX_SIZE && std::getline(inFile, students.data[students.count].name))
    {
        inFile >> students.data[students.count].age
            >> students.data[students.count].scholarship;
        inFile.ignore();
        students.count++;
    }

    inFile.close();

}

void printStudents(const StudentArray& students)
{
    for (int i = 0; i < students.count; i++)
    {
        std::cout << students.data[i].name << '\n'
            << students.data[i].age << '\n'
            << students.data[i].scholarship << '\n';
    }
}




// ifstream - read from file
// ofstream - write to file


int main() {
    // std::ofstream fOut("example.txt");
    //
    // if (!fOut)
    // {
    //     std::cerr << "Error opening file" << '\n';
    //     return 1;
    // }
    //
    // fOut << "Hello world!\n";
    // fOut << 42 << "-----" << 67.4 << "\n";
    //
    // fOut.close();



    // std::ifstream fIn("example.txt");
    //
    // if (!fIn)
    // {
    //     std::cerr << "Error opening file" << '\n';
    //     return 1;
    // }

    // std::string txt;
    //
    // while (std::getline(fIn, txt))
    // {
    //     std::cout << txt << '\n';
    // }
    // fIn.seekg(0);
    // std::string text;
    // int counter;
    // float biba;
    //
    // std::getline(fIn, text);
    // fIn >> counter >> biba;



    // std::stringstream buffer;
    // buffer << fIn.rdbuf();
    // std::string boba = buffer.str();
    // std::cout << boba << '\n';

    // fIn.close();

    // Student student_1 = {"John", 17, 110};
    // Student student_2 = {"Ehmed", 19, 75};
    // Student student_3 = {"Lalezar", 68, 145};
    //
    StudentArray students;
    // students.data[0] = {"John", 17, 110};
    // students.data[1] = {"Ehmed", 19, 75};
    // students.data[2] = {"Lalezar", 68, 145};
    //
    // students.count = 3;

    //writeStudentsToFile(students, "students.txt");

    readStudentsFromFile(students, "students.txt");
    printStudents(students);

    return 0;
}