#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// class Biba
// {
// private:
//     double bagdagul;
// protected:
//     int test;
// public:
//     Biba()
//     {
//         test = 0;
//         bagdagul = 0;  
//     };
//     void Foo()
//     {
//         std::cout<<"Foo \n";
//     }
// };
//
// class Boba :  private Biba
// {
// public:
//     void Test()
//     {
//         std::cout<<test << "\n";
//     }
// };
//
// class Baba :public Boba
// {
//     public:
//     // void Yuppy()
//     // {
//     //     std::cout<<"Baba \n" << test;
//     // }
// };






// class A
// {
// public:
//     A()
//     {
//         std::cout << "A::Constructor" << std::endl;
//     }
//     void foo()
//     {
//         std::cout << "A::foo" << std::endl;
//     }
// };
//
// class B: public A
// {
// public:
//     B()
//     {
//         std::cout << "B::Constructor" << std::endl;
//     }
//     void foo()
//     {
//         std::cout << "B::foo" << std::endl;
//     }
// };
// class C: public A
// {
// public:
//     C()
//     {
//         std::cout << "C::Constructor" << std::endl;
//     }
//     void foo()
//     {
//         std::cout << "C::foo" << std::endl;
//     }
// };
//
// class D: public B, public C
// {
// public:
//     D()
//     {
//         std::cout << "D::Constructor" << std::endl;
//     }
//     void foo()
//     {
//         std::cout << "D::foo" << std::endl;
//     }
// };


class User
{
protected:
    char _name[20];
    int _age;
public:
    User()
    {
        strcpy(_name, "Unknown");
        _age = 0;
    };

    User(const char* name, int age)
    {
        std::cout << "User Constructor\n";
        strcpy(_name, name);
        _age = age;
    }
};

class Teacher : public User
{
private:
    char _subject[20];
public:
    Teacher(const char* name, int age, const char* subject) : User(name, age)
    {
        std::cout << "Teacher Constructor\n";
        strcpy(_subject, subject);
    }
};


int main()
{
    // Biba biba;
    // Boba boba;
    // //boba.Foo();
    // boba.Test();
    // Baba baba;
    // baba.Test();
    //

    // A a;
    // B b;
    // C c;
    // D d;

    // a.foo();
    // b.foo();
    // c.foo();
    // d.foo();

    //Teacher t("Test", 54, "test");
    return 0;
}