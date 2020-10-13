// OOP_LAB_1_PR2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Main_Window.h"
#include "Student.h"

int main()
{
    //std::cout << "Hello World!\n";
    setlocale(LC_ALL, "Ukrainian");

        //Student vasil2 = Student("Vasia", "Aupkin", "20", "12/12/1990", "Ulica", "2934729837");

        //Student vasil1 = Student("Vasia", "Pupkin", "20", "12/12/1990", "Ulica", "2934729837");

        //Student volodiya = Student("Volodimir", "Zupkin", "20", "12/12/1990", "Ulica", "2934729837");

        //Student tomas = Student("Tomas", "Timski", "20", "12/12/1222", "Ulica", "1234");

    Student::RD();

    Main_Window::shutdown = false;

    while (Main_Window::shutdown != true)
    { 
        Main_Window::To_screen();
    }

    return 0;
    
}

