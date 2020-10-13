#include "Main_Window.h"

#include "Student_View_Window.h"


bool Main_Window::shutdown;

 unsigned int Main_Window::selected = 0;

 unsigned int Main_Window::selected_student_index = 0;

 HANDLE Main_Window::handle = GetStdHandle(STD_OUTPUT_HANDLE);


    void Main_Window::Selected_Window_Open()
    {
       

        if (selected == 0)
        {
            Student_View_Window::Nazad = false;
            while (Student_View_Window::Nazad != true)
            {
                Student_View_Window::To_screen();
            }
           
        }
        else if (selected == 1)
        {
            File_Type_Selected_Window::Nazad = false;
            while(File_Type_Selected_Window::Nazad != true)
            { 
                File_Type_Selected_Window::To_Screen();
            }
        }
        else if (selected == 2)
        {
            
                Main_Window::Exit();
            
        }

        if (Main_Window::shutdown == true)
        {
            return;
        }

        Screen_Update();
       
    }



    void Main_Window::To_screen()
    {

        setlocale(LC_ALL, "Ukrainian");

        Screen_Update();


        if (Main_Window::shutdown == true)
        {
            return;
        }

        //cin.get();

    }

    void Main_Window::Exit()
    {
       

        if(File_Type_Selected_Window::Get_mode() == "text")
        {
            Student::RW();
        }
        else
        {
            //cout << File_Type_Selected_Window::Get_mode();
            //system("pause");
            Student::RW("123");
        }
        Main_Window::shutdown = true;

       if(Main_Window::shutdown == true)
       { 
            return;
       }
    }


    void Main_Window::Screen_Update()
    {

        system("cls");

        if (Main_Window::shutdown == true)
        {
            return;
        }

        if (selected == 0)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "1. Перегляд Студентiв" << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "1. Перегляд Студентiв" << endl;
        }


        if (selected == 1)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "2. Оновлення Бази Данних" << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "2. Оновлення Бази Данних" << endl;
        }

        if (selected == 2)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "3. Вихiд" << endl;
            SetConsoleTextAttribute(handle, WHITE_PEN);
        }
        else
        {
            cout << "3. Вихiд" << endl;
        }

        Select();


    }


    void Main_Window::Select()
    {
        if (Main_Window::shutdown == true)
        {
            return;
        }

        while (true)
        {

            switch (_getch())
            {
            case up_key:
                if (selected != 0)
                {
                    selected--;
                    Screen_Update();
                }
                break;
            case down_key:
                if (selected != 2)
                {
                    selected++;
                    Screen_Update();
                }
                break;
            case Enter_key:
                Selected_Window_Open();
                break;

            }

            if (Main_Window::shutdown == true)
            {
                return;
            }
        }


    }