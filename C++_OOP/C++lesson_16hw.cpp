#include <iostream>

class Automobile
{
private:
    char _brand[50];
    char _model[50];
    size_t _year;
    size_t _mileage;
         
public:
    Automobile() 
    {
        strncpy_s(_brand, "Unknown", sizeof(_brand));
        strncpy_s(_model, "Unknown", sizeof(_model));
        _year = 0;
        _mileage = 0;
    }

    Automobile(const char* brand, const char* model, const size_t year, const size_t mileage)
    {
        setBrand(brand);
        setModel(model);
        setYear(year);
        setMileage(mileage);
    }

    const char* getBrand() const { return _brand; }
    const char* getModel() const { return _model; }
    size_t getYear() const { return _year; }
    size_t getMileage() const { return _mileage; }


    void setBrand(const char* newBrand)
    {
        if (newBrand && _brand[0] != '\0')
        {
            strncpy_s(_brand, newBrand, sizeof(_brand));
            _brand[strlen(newBrand) - 1] = '\0';
        }
    }

    void setModel(const char* setModel)
    {
        if (setModel && _model[0] != '\0')
        {
            strncpy_s(_model, setModel, sizeof(_model));
            _model[strlen(setModel) - 1] = '\0';
        }
    }

    void setYear(const size_t newYear) 
    {
        if (newYear >= 1894)
        {
            _year = newYear;
        }
    }

    void setMileage(const size_t newMileage) /*проверка больше 0 не требуется из-за size_t*/
    {
        _mileage = newMileage;
    }

    void drive(size_t km)
    {
        _mileage += km;
    }

    int getAge(size_t currentYear)
    {
        if (currentYear >= _year)
        {
            return currentYear - _year;
        }

        return -1;
    }

};

void DisplayAutomobile(const Automobile& automobile)
{
    std::cout << "Brand: " << automobile.getBrand()
        << "\nModel: " << automobile.getModel()
        << "\nYear: " << automobile.getYear()
        << "\nMileage: " << automobile.getMileage()
        << "\n";
}

int main()
{
    /*Automobile test;
    DisplayAutomobile(test);*/
    Automobile automobile1("Mercedes-Benz", "EQB 300", 2022, 69400);
    DisplayAutomobile(automobile1);
    std::cout << "Age: " << automobile1.getAge(2024) << "\n";
    automobile1.drive(500);
    DisplayAutomobile(automobile1);
    
    return 0;
}