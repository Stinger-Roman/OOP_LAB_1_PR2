#include "Student.h"


Student* Student::first_student = NULL;
Student* Student::end_student = NULL;
Student* Student::selected_student = NULL;

Student::Student(string first_name, string last_name, string years_old, string bithrday_date, string adress, string telephone)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->years_old = years_old;
    this->bithrday_date = bithrday_date;
    this->adress = adress;
    this->telephone = telephone;



    if (first_student == NULL)
    {
        next = NULL;
        prev = NULL;
        first_student = this;
        end_student = this;
        selected_student = this;

    }
    else
    {
        Student* temp = first_student;
        while (temp)
        {
            //cout << this->last_name << endl;
            //cout << temp->last_name << endl;
            //system("pause");
            //system("cls");
            char temp_char = _strdup(temp->last_name.c_str())[0];

            char this_object_char = _strdup(last_name.c_str())[0];


            if (this_object_char <= temp_char)
            {

                if (temp->prev == NULL)
                {
                    this->prev = NULL;
                    this->next = temp;
                    temp->prev = this;
                    first_student = this;
                    break;
                }
                else
                {
                    Student* temp_prev = temp->prev;


                    this->prev = temp_prev;
                    this->next = temp;
                    this->prev->next = this;
                    this->next->prev = this;
                    break;
                }




            }
            else if (temp->next == NULL)
            {
                this->prev = temp;
                this->prev->next = this;
                this->next = NULL;
                break;
            }


            //selected_student = first_student;



            temp = temp->next;
        }









    }

}



void Student::Remove()
{
    Student* temp = selected_student;

    if (temp->prev == NULL)
    {
        selected_student = temp->next;
        first_student = temp->next;
        first_student->prev = NULL;

    }
    else if (temp->next == NULL)
    {
        selected_student = temp->prev;
        end_student = temp->prev;
        first_student->next = NULL;
    }
    else
    {
        selected_student = temp->prev;
        selected_student->next = temp->next;
        temp->next->prev = selected_student;
    }



    delete(temp);




}



void Student::Clean()
{
    if (first_student == NULL)
    {
        return;
    }

    Student* temp = Student::first_student;

    Student* temp_next;



    while (true)
    {

        if (temp->next != NULL)
        {
            temp_next = temp->next;
            delete(temp);
        }
        else
        {
            delete(temp);
            break;
        }


        temp = temp_next;
    }


    Student::selected_student = NULL;
    Student::first_student = NULL;
    Student::end_student = NULL;


}


std::string Student::get(string target)
{

    if (target == "first_name")
    {
        return this->first_name;
    }
    else if (target == "last_name")
    {
        return this->last_name;
    }
    else if (target == "years_old")
    {
        return this->years_old;
    }
    else if (target == "bithrday_date")
    {
        return this->bithrday_date;
    }
    else if (target == "adress")
    {
        return this->adress;
    }
    else if (target == "telephone")
    {
        return this->telephone;
    }


}



void Student::set(string target, string znak)
{
    if (target == "first_name")
    {
        first_name = znak;
    }
    else if (target == "last_name")
    {
        last_name = znak;
    }
    else if (target == "years_old")
    {
        years_old = znak;
    }
    else if (target == "bithrday_date")
    {
        bithrday_date = znak;
    }
    else if (target == "adress")
    {
        adress = znak;
    }
    else if (target == "telephone")
    {
        telephone = znak;
    }
}



void Student::RW()
{
    ofstream text_file;

    text_file.open("cppstudio.txt");

    Student* temp = first_student;

    while (temp)
    {

        text_file << temp->first_name << endl;
        text_file << temp->last_name << endl;
        text_file << temp->years_old << endl;
        text_file << temp->bithrday_date << endl;
        text_file << temp->adress << endl;
        text_file << temp->telephone << endl;
        text_file << "object" << endl;

        temp = temp->next;

    }

    text_file << "end" << endl;

    text_file.close();

}

void Student::RD()
{

    string line;

    string mas[6];

    int i = 0;

    ifstream in("cppstudio.txt");


    if (in.is_open())
    {
        while (getline(in, line))
        {

            if (line == "")
            {
                break;
            }

            //cout << line<< endl;
            if (line == "object")
            {
                i = 0;

                Student* temp = new Student(mas[0], mas[1], mas[2], mas[3], mas[4], mas[5]);

            }
            else  if (line == "end")
            {
                break;
            }
            else
            {
                mas[i] = line;

                i++;
            }


        }

        in.close();

    }


}


void Student::RW(string g)
{
    ofstream out("cppstudio.DAT", ios::binary | ios::out);
    //Записываем в файл значение "x"

    Student* temp = first_student;

    while (temp)
    {
        string::size_type n = temp->first_name.size();

        out.write((const char*)&n, sizeof(string::size_type));
        out.write(temp->first_name.c_str(), temp->first_name.size());

        n = temp->last_name.size();
        out.write((const char*)&n, sizeof(string::size_type));
      
        out.write(temp->last_name.c_str(), temp->last_name.size());

        n = temp->years_old.size();
        out.write((const char*)&n, sizeof(string::size_type));
     
        out.write(temp->years_old.c_str(), temp->first_name.size());

      
        n = temp->bithrday_date.size();
        out.write((const char*)&n, sizeof(string::size_type));


        out.write(temp->bithrday_date.c_str(), temp->first_name.size());

        n = temp->adress.size();
        out.write((const char*)&n, sizeof(string::size_type));
    
        out.write(temp->adress.c_str(), temp->first_name.size());

        n = temp->telephone.size();
        out.write((const char*)&n, sizeof(string::size_type));
      
        out.write(temp->telephone.c_str(), temp->first_name.size());
      
        


        


        temp = temp->next;

    }

   


    //out.write((char*)&y, sizeof(y));        //Записываем в файл значение "y"
    out.close();
}


void Student::RD(string g)
{
    ifstream in("cppstudio.DAT", ios::binary | ios::in);
    //Записываем в файл значение "x"

    string::size_type n;

    char* line;

    string mas[6];

    int count = 0;

    Student* temp = Student::selected_student;

    if (in.is_open())
    {

           while(in.read((char*)&n, sizeof(string::size_type)))
           { 

               

            string sout(n, 0);

            for (int i = 0; i < n; ++i)
            {
                
            
                in.read(&sout[i], sizeof(sout[0]));

                

                

            }

            mas[count] = sout;

            //cout << mas[count] << endl;

            count++;
            
            //system("pause");

            if (count == 6)
            {

                Student* temp = new Student(mas[0], mas[1], mas[2], mas[3], mas[4], mas[5]);
                count = 0;

            }
           
            
            
           }

                

            
            


        }

    



    //out.write((char*)&y, sizeof(y));        //Записываем в файл значение "y"
    in.close();
}


