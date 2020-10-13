#include "Student_View_Window.h"


#pragma once
#define _CRT_SECURE_NO_WARNINGS



#define up_key 72
#define down_key 80
#define left_key 75
#define right_key 77
#define one_select_key 49
#define two_select_key 50
#define three_select_key 51
#define four_select_key 52
#define five_select_key 53
#define six_select_key 54
#define seven_select_key 55
#define eight_select_key 56
#define nine_select_key 57
#define ten_select_key 58
#define Enter_key 13
#define Delete_key 83
#define Delete_key 83
#define Esc_key 27


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <locale>
#include <Windows.h>
#include <processenv.h>
#include <WinBase.h>
#include <consoleapi2.h>

#include <string>

#include "Student.h"


using namespace std;







    unsigned int Student_View_Window::selected_student_index = 0;

    HANDLE Student_View_Window::handle = GetStdHandle(STD_OUTPUT_HANDLE);


    bool Student_View_Window::Nazad;


    void Student_View_Window::To_screen()
    {
        setlocale(LC_ALL, "Ukrainian");

        system("cls");
       
        if (Student::first_student == NULL)
        {
            cout << "Немає студентIв у базI данних натиснIть плюс,"<< 
                endl << " щоб додати, або Esc щоб вийти до головного меню " << endl;

            bool cont = true;


           
            while(cont)
            { 
                switch (_getch())
                {
                case Esc_key:
                    cont = false;
                    Nazad = true;
                    break;
                case Plus_key:
                    cont = false;
                    Student_Add();                  
                    break;
                }

                if (Nazad == true)
                {
                    return;
                }
            }
            
        }
       

        Student::selected_student = Student::first_student;

        Screen_update();

        if (Student::first_student == NULL)
        {
            cout << "Немає студентiв у базi данних" << endl;
            //Main_Window::To_screen();
            return;
        }


        return;

        //cin.get();

    }


    void Student_View_Window::Screen_update()
    {
        system("cls");




        if (Nazad == true)
        {
            return;
        }








        if (selected_student_index == 0)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Iм'я :" + Student::selected_student->get("first_name") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Iм'я :" + Student::selected_student->get("first_name") << endl;
        }


        if (selected_student_index == 1)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Прiзвище :" + Student::selected_student->get("last_name") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Прiзвище :" + Student::selected_student->get("last_name") << endl;
        }

        if (selected_student_index == 2)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Вiк :" + Student::selected_student->get("years_old") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Вiк :" + Student::selected_student->get("years_old") << endl;
        }


        if (selected_student_index == 3)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Дата народження :" + Student::selected_student->get("bithrday_date") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Дата народження :" + Student::selected_student->get("bithrday_date") << endl;
        }


        if (selected_student_index == 4)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Адреса :" + Student::selected_student->get("adress") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Адреса :" + Student::selected_student->get("adress") << endl;
        }


        if (selected_student_index == 5)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Телефон :" + Student::selected_student->get("telephone") << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "Телефон :" + Student::selected_student->get("telephone") << endl;
        }

        cout << endl;

        cout << "Виберiть поле та натиснiть Enter для редагування, або Delete для видалення." << endl 
            <<  "Натиснiть Esc для повернення до головного меню, або Insert, щоб додати нового студента" << endl;

        Select();




    }

    void Student_View_Window::edit(int parameter)
    {

        string temp;

        cout << "ВведIть нове значення: ";
        getline(cin, temp);

        switch (parameter)
        {
        case 0:
            Student::selected_student->set("first_name", temp);
            break;
        case 1:
            Student::selected_student->set("last_name", temp);
            break;
        case 2:
            Student::selected_student->set("years_old", temp);
            break;
        case 3:
            Student::selected_student->set("bithrday_date", temp);
            break;
        case 4:
            Student::selected_student->set("adress", temp);
            break;
        case 5:
            Student::selected_student->set("telephone", temp);
            break;

        }
    }


    void Student_View_Window::Select()
    {
        while (true)
        {

            switch (_getch())
            {
            case right_key:
                if (Student::selected_student->next != NULL)
                {

                    Student::selected_student = Student::selected_student->next;
                    Screen_update();
                }
                else
                {
                    MessageBeep(0);
                }
                break;
            case left_key:
                if (Student::selected_student->prev != NULL)
                {
                    Student::selected_student = Student::selected_student->prev;
                    Screen_update();
                }
                else
                {
                    MessageBeep(0);
                }
                break;
            case up_key:
                if (selected_student_index != 0)
                {
                    selected_student_index--;
                    Screen_update();
                }
                else
                {
                    MessageBeep(0);
                }
                break;
            case down_key:
                if (selected_student_index != 5)
                {
                    selected_student_index++;
                    Screen_update();
                }
                else
                {
                    MessageBeep(0);
                }
                break;
            case Enter_key:
                edit(selected_student_index);
                Screen_update();
                break;
            case Delete_key:
                Student::selected_student->Remove();
                Screen_update();
                break;
            case Esc_key:
                Nazad = true;
                break;
            case Plus_key:                
                Student_Add();                
                break;

            }

            if (Nazad == true)
            {
                return;
            }

        }
    }



    void Student_View_Window::Student_Add()
    {
        

        string mas[6];

        string tempus;

        
        system("cls");


        cout << "Введiть Iм'я: ";
        cin >> mas[0];
        cout << endl;


        cout << "Введiть ПрIзвище: ";
        cin >> mas[1];
        cout << endl;

        cout << "Введiть ВIк: ";
        cin >> mas[2];
        cout << endl;

        cout << "Введiть дату народження: ";
        cin >> mas[3];
        cout << endl;


        cout << "Введiть адресу: ";
        cin >> mas[4];
        cout << endl;


        cout << "Введiть телефон: ";
        cin >> mas[5];
        cout << endl;

        Student* temp = new Student(mas[0] , mas[1], mas[2], mas[3], mas[4], mas[5]);


       

        To_screen();

        

    }

