#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <locale>
#include <Windows.h>
#include <processenv.h>
#include <WinBase.h>
#include <consoleapi2.h>
#include <stdio.h>
#include <vector>
#include <string>








using namespace std;








class Student
{
private:
    string first_name;
    string last_name;
    string years_old;
    string bithrday_date;
    string adress;
    string telephone;


public:
    Student* next = NULL;
    Student* prev = NULL;


    static Student* first_student;
    static Student* end_student;
    static Student* selected_student;


   

public:

    Student(string first_name, string last_name, string years_old, string bithrday_date, string adress, string telephone);



    void Remove();


    static void Clean();



    std::string get(string target);



    void set(string target, string znak);


    static void RW();


    static void RD();


    static void RW(string g);



    static void RD(string g);




};

