#include <iostream>
#include <typeinfo>

// static cast
// dynamic cast
// reinterpret cast
// const cast


void my_print(char* str)
{
    std::cout << str;
}

class Animal
{
public:
    virtual ~Animal() {}
    virtual void make_sound() const = 0;
};

class Dog : public Animal
{
public:
    void make_sound()  const override
    {
        std::cout << "Dog make_sound" << std::endl;
    }

    void fetch()
    {
        std::cout << "Dog fetch" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void make_sound()  const override
    {
        std::cout << "Cat make_sound" << std::endl;
    }

    void climb()
    {
        std::cout << "Cat climb" << std::endl;
    }
};


void play_with_animal(Animal* animal)
{
    // animal->make_sound();
    //
    // if (Dog *dog = dynamic_cast<Dog*>(animal))
    // {
    //     dog->fetch();
    // }
    //
    // if (Cat *cat = dynamic_cast<Cat*>(animal))
    // {
    //     cat->climb();
    // }

    Cat* cat = static_cast<Cat*>(animal);
    cat->make_sound();
}

class Base
{
public:
    virtual ~Base() {}
    virtual void Print() { std::cout << "Base::Print" << '\n'; }
};

class Derived : public Base
{
public:
    void Print() override { std::cout << "Derived::Print" << '\n'; }
    void Foo() { std::cout << "Derived::Foo" << '\n'; }
};


void test(Derived* base)
{
    std::cout << typeid(*base).name() << std::endl;
}

void bagdagul()
{
    std::cout << "bagdagul" << std::endl;
}

//int main() {
//    // static cast ==============================
//    // double d = 3.14;
//    // int a = static_cast<int>(d);
//    // std::cout << a << '\n';
//
//    // class Base{};
//    // class Derived : public Base{};
//    // class Derived2 : public Base
//    // {
//    //     public:
//    //     void foo ()
//    //     {
//    //         std::cout << "foo" << std::endl;
//    //     }
//    // };
//
//    // Derived derived;
//    // Base * basePtr = static_cast<Base*>(&derived); // upcast
//    // std::cout << typeid(basePtr).name() << '\n';
//
//    // Base base;
//    // Derived * derivedPtr = static_cast<Derived*>(&base); // downcast
//    // std::cout << typeid(derivedPtr).name() << '\n';
//
//    // Base* base = new Base();
//    // Derived2* derived = static_cast<Derived2*>(base); // downcast
//
//    // Base* base = new Base();
//    // Derived2* derived = static_cast<Derived2*>(base); // downcast
//    // derived->foo();
//
//    // int a = 5;
//    // void* v_ptr = &a;
//    // std::cout << *(static_cast<int*>(v_ptr)) << std::endl;
//
//    // dynamic cast ==============================
//
//    // int a= 4;
//    // double b = dynamic_cast<double>(a);
//
//    // Base* base_ptr = new Derived();
//    // Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr); // safe downcast
//    //
//    // if (derived_ptr)
//    // {
//    //     derived_ptr->Foo();
//    //     derived_ptr->Print();
//    //     base_ptr->Print();
//    // }
//
//    // Base* base = new Derived();
//    // Derived* d = dynamic_cast<Derived*>(base);
//    // test(d);
//
//
//
//    //Dog *dog = new Dog();
//    //Cat *cat = new Cat();
//    //play_with_animal(dog);
//    //play_with_animal(cat);
//
//
//    // reinterpret cast ==============================
//    // int a = 50;
//    // uintptr_t ptr_value = reinterpret_cast<uintptr_t>(&a);
//    // int* ptr = reinterpret_cast<int*>(ptr_value);
//    // std::cout << *ptr << std::endl;
//
//    // void * ptr_func = reinterpret_cast<void *>(bagdagul);
//    // void(*original_function)() = reinterpret_cast<void(*)()>(ptr_func);
//    // original_function();
//
//    // const cast ==============================
//
//    const char* const_str = "Hello World!";
//    my_print(const_cast<char*>(const_str));
//
//    return 0;
//}