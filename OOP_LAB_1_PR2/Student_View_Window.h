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
#define Plus_key 82

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

//#include "Student_View_Window.h"


using namespace std;





class Student_View_Window
{

    static unsigned int selected_student_index;

    static HANDLE handle;

   

public:


    static bool Nazad;

    static void Student_Add();

    static void To_screen();
    

    static void Screen_update();
    

    static void edit(int parameter);

    
   


    static void Select();
   

    
    
};