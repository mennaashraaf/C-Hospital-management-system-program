#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string>
#include <windows.h>
/////////////////////function decleration///////////////////////////////////////
int c_choice;
void menu();
void pascode();
void cpascode();
using namespace std;
////////////////////////////class one///////////////////////////////////////////
class one
{
public:
    virtual void get() = 0;
    virtual void show() = 0;
};
////////////////////////////class information///////////////////////////////////
class info :public one
{
public:
    string name, time;
    int num, age;
    void get()
    {
        system("cls");
        //cin.sync();
        cout << "\nEnter the Patient name :";
        cin >> name;
        cout << "\n Enter the Appointment time :";
        cin >> time;
        cout << "\n Enter Age :";
        cin >> age;
        cout << "\nEnter Appointment number :";
        cin >> num;
    }
    void show()
    {
        cout << "\nName :" << name;
        cout << "\nAge :" << age;
        cout << "\nNum :" << num;
        cout << "\nTime :" << time;
        Sleep(3000);
    }
};
//////////////////////////////////class Doctors//////////////////////////////////
class Doctors :public info
{
public:
    info a1;
    void adddoctor(info doctor)
    {
        ofstream myfile;
        myfile.open("example.txt", ios::app);
        string patient_info = doctor.name + "," + doctor.time + "," + to_string(doctor.age) + "," + to_string(doctor.num) + "," + to_string(c_choice) + "\n";
        myfile << patient_info;
        myfile.close();
    }

    void get()
    {
        system("cls");
        a1.get();
        adddoctor(a1);
        cout << "Your Entry has been saved ...";
        _getch();
        menu();
    }
    void show()
    {
        ifstream in("example.txt");
        if (!in.is_open())
        {
            cout << "\n\nNo Data In the File ";
            cout << "\n\n\t\tPress Any Key to Continue: ";
            _getch();
            void menu();
        }
        else
        {
            string patient;
            while (getline(in, patient))
            {
                int att_index = 0;
                string patient_info[5];
                string att = "";
                for (int i = 0; i < patient.length(); i++) {
                    if (patient[i] != ',')
                        att += patient[i];
                    else {
                        patient_info[att_index] = att;
                        att_index++;
                        att = "";
                    }
                }
                patient_info[att_index] = att; //Handling the last attribute
                //patient = mahmoud,12,20,3,1

                a1.name = patient_info[0];
                a1.time = patient_info[1];
                a1.age = stoi(patient_info[2]);
                a1.num = stoi(patient_info[3]);
                if (c_choice == stoi(patient_info[4]))
                    a1.show();
                //in.read((char*)&a1, sizeof(a1));                
            }
            in.close();
            _getch();
            menu();
        }
    }
};
////////////////////class staff////////////////////
class staff :public one
{
public:
    string all;
    string name, age, sal, pos;

    void get()
    {
        ofstream out("staff.txt", ios::app);
        {
            system("cls");
            //cin.sync();
            cout << "\nEnter Name = ";
            cin >> name;
            cout << "\nEnter Age = ";
            cin >> age;
            cout << "\nEnter Salary =";
            cin >> sal;
            cout << "\nEnter Working Position = ";
            cin >> pos;
        }
        out << "\nName = " << name << "\nAge :" << age << "\nSalary =" << sal << "\nWorking Position :\n" << pos;
        out.close();
        cout << "\n\nYour Information has been saved :\n\t\t\tPress Any Key to Continue ";
        _getch();
        menu();
    }
    void show()
    {
        ifstream in("staff.txt");
        if (!in)
        {
            cout << "File open Error";
        }
        while (!(in.eof()))
            //while(getline(in,all))
        {
            // in.getline(all, 999);
            in >> all;
            cout << all << endl;
        }
        in.close();
        cout << "\n\n\t\tPress Any Key to Continue ";
        _getch();
        menu();

    }
};
///////////////////////////////////////////////////class information////////////////////////////
class information
{
public:
    void drInfo()
    {
        system("cls");
        system("color F3");
        cout << "\n===============================================================================\n";
        cout << "\n\n\t\t(six Doctors Available) \n\n \t\t[Information And Timing Are Given Below]\n";
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "\t\tDoctors Available :\n";
        cout << "\t\t  DR Ahmed samir (skin specialist)\n\n";
        cout << "\t\t\t [[Timing]]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t 9AM TO 5PM\n";
        cout << "\tSaturday              \t\t9AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t DR Hassan Ehab (child specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\t From Monday to Friday \t\t2PM To 10PM\n";
        cout << "\t Saturday              \t\t8AM\n ";
        cout << "\t Sunday                \t\t 9AM TO 1 PM \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t  DR Marwa ibrhim (heart specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t8AM TO 5PM\n";
        cout << "\tSaturday              \t\t10AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t  DR Waleed Mohamed (heart specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t5AM TO 5PM\n";
        cout << "\tSaturday              \t\t7AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t DR Hadeer Ahmed (heart specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t3AM TO 5PM\n";
        cout << "\tSaturday              \t\t10AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t DR Salma Hatem (heart specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t8AM TO 5PM\n";
        cout << "\tSaturday              \t\t9AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << " Press Any Key to Continue...";
        _getch();
        menu();
    }
};
void call_dr()
{
    system("cls");
    int choice;
    cout << "\n\n\t\t Press 1 for DR Ahmed samir \n\n\t\t Press 2 for DR Hassan Ehab \n\n\t\t press 3 for DR Marwa ibrhim  \n\n\t\t press 4 for DR Waleed Mohamed \n\n\t\t press 5 for DR Hadeer Ahmed \n\n\t\t press 6 for DR Salma Hatem   ";
    cin >> choice;
    c_choice = choice;
    one* ptr;
    Doctors s3;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
    {
        ptr = &s3;
        ptr->get();
    }
    else
    {
        cout << "Sorry Invalid Choice";
        _getch();
        menu();
    }

}
void pinfoshow()
{
    system("cls");
    int choice;
    cout << "Enter Your Choice ";
    cin >> choice;
    c_choice = choice;
    one* ptr;
    Doctors s3;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
    {
        ptr = &s3;
        ptr->show();
    }
    else
    {
        cout << "Sorry Invalid Choice";
        _getch();
        menu();
    }

}
void menu()
{
    system("cls");
    system("color FC");
    cout << "\n";
    cout << "\n";

    cout << "\t\t   |   ++++++++++  MAIN MENU  ++++++++++   |  \n";
    cout << "\t\t   |       Hospital Management System      |\n";
    cout << "\t\t   |=======================================|   \n";

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t     Select The Option You Want    \n";

    cout << "\n\n\t1-\t\tPress 1 For Available Doctor Information\n\n";
    cout << "\t2-\t\tPress 2 For Doctor Appointment\n\n";
    cout << "\t3-\t\tPress 3 For Saving Staff Information\n\n";
    cout << "\t4-\t\tPress 4 For Checking patient Appointment Menu\n\n";
    cout << "\t5-\t\tPress 5 For Checking Staff Information Menu\n\n";
    cout << "\t6-\t\tPress 6 For Changing Password or Creating a New password\n\n";
    cout << "\t7-\t\t[    Press 7 to Logout    ]\n";

    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tEnter Your Choice : ";
    information a1;
    one* ptr;
    staff a2;
    int a;
    cin >> a;
    if (a == 1)
    {
        a1.drInfo();
    }
    else if (a == 2)
    {
        call_dr();
    }
    else if (a == 3)
    {
        ptr = &a2;
        ptr->get();
    }
    else if (a == 4)
    {
        pinfoshow();
    }
    else if (a == 5)
    {
        ptr = &a2;
        ptr->show();
    }
    else if (a == 6)
    {
        cpascode();
    }
    else if (a == 7)
    {
        pascode();
    }
    else
    {
        cout << "Sorry Invalid Choice";
    }

}
void pascode()
{
    system("cls");
    string p1, p2;
    system("color Fc");
    ifstream in("password.txt");
    {
        // cin.sync();
        cout << "\n\n\n\n\n\n\n\t\t\tEnter the Password: ";
        cin >> p1;
        in >> p2;
        if (p1 == p2)
        {
            menu();
        }
        else
        {
            cout << "\n\n\t\t\tIncorrect Passcode Plese Try Again\n";
            Sleep(999);

        }

    }
}
void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout << "\n\n\n\n\t\t\tEnter The New Password: ";
        cin.getline(n, 50);
        out << n;
    }
    out.close();
    cout << "\n\nYour Password has been saved";
    _getch();
    menu();
}

