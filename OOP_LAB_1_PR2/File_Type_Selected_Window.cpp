#include "File_Type_Selected_Window.h"




using namespace std;

unsigned int File_Type_Selected_Window::selected = 0;

string File_Type_Selected_Window::mode = "text";


HANDLE File_Type_Selected_Window::handle = GetStdHandle(STD_OUTPUT_HANDLE);

bool File_Type_Selected_Window::Nazad;


void File_Type_Selected_Window::To_Screen()
{
    //Nazad = false;

    Screen_update();

    return;

}

void File_Type_Selected_Window::Screen_update()
{
    system("cls");

   
    if (Nazad == true)
    {
        return;
    }


    if (selected == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "���������" << endl;
        SetConsoleTextAttribute(handle, WHITE_PEN);
        cout << "�i������" << endl;
        cout << "�����" << endl;
    }
    else if (selected == 1)
    {
        cout << "���������" << endl;
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "�i������" << endl;
        SetConsoleTextAttribute(handle, WHITE_PEN);
        cout << "�����" << endl;
    }
    else if (selected == 2)
    {
        cout << "���������" << endl;
        cout << "�i������" << endl;
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "�����" << endl;
        SetConsoleTextAttribute(handle, WHITE_PEN);
    }


    cout << endl;

    cout << "���i���i� �i��������� �� ��������� ���i����� ����, �� � ����. ������i�� Enter ��� �i��������� ��i� ���i�." << endl;

    Select();

    




}

void File_Type_Selected_Window::Select()
{
    while (true)
    {

        switch (_getch())
        {
        case up_key:
            if (selected != 0)
            {
                selected--;
                Screen_update();
            }
            else
            {
                MessageBeep(0);
            }
            break;
        case down_key:
            if (selected != 2)
            {
                selected++;
                Screen_update();
            }
            else
            {
                MessageBeep(0);
            }
            break;
        case Enter_key:
            Selector();
            Screen_update();
            break;
        

        }


        if (Nazad == true)
        {
            return;
        }

    }

}

void File_Type_Selected_Window::Selector()
{

    if (selected == 0)
    {
        if (mode != "text")
        {
            mode = "text";

            Student::RW("qwe");

            Student::Clean();

            Student::RD();
        }
       
        
    }
    else if (selected == 1)
    {
        if (mode != "bin")
        {
            mode = "bin";

            Student::RW();

            Student::Clean();

            Student::RD("qwe");
        }
        
    }
    else
    {
        Nazad = true;
    }

    Nazad = true;

    //Main_Window::ToScreen();

}


string File_Type_Selected_Window::Get_mode()
{
    return mode;
}


