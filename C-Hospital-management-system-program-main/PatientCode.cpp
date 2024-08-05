#include "PatientCode.h"
#include "DoctorCode.h"
#include <fstream>
#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

double totalcost = 0;

struct pInfo {
    string name, lastname, gender, str;
    int age, phonenumber, r, bloodtype, rCode = 0;
};
pInfo p;
void patientList(int rc) {
    system("color F3");

    int y;

    cout << "1- New Patient " << endl;
    cout << "2- Old Patient " << endl;
    cout << "\n\n\t\tEnter Your Choice : ";
    cin >> y;
    if (y == 1) {
        regestrationList();
        system("cls");

    }
    if (y == 2) {
        p.rCode = 0;
        cout << "Enter your Name: ";
        cin >> p.name;
        cout << "Enter Your Last Name: ";
        cin >> p.lastname;
        p.str = p.name + p.lastname;
        for (int i = 0; i < p.str.length(); i++)
        {
            p.rCode += (int)p.str[i];
        }
        e1:
        cout << "Enter Your ID: ";
        cin >> rc;
        if (rc != p.rCode) {
            cout << "Invalid ID!..." << endl;
            goto e1;
        }
        system("cls");
        oldPatient();
    }
}
void oldPatient() {
    int s;
    system("cls");
    system("color F3");
    cout << "\t\t   |   ++++++++++  PATIENT MENU  ++++++++++   |  \n";
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t        Select One Option        \n";
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\t\t 1) Select A Clinic\n\n";
    cout << "\t\t\t 2) support Area\n\n";
    cout << "\t\t\t 3) laboratory\n\n";
    cout << "\t\t\t[    Press 4 to Logout    ]\n";
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tEnter Your Choice : ";
    cin >> s;
    switch (s) {
    case 1:
        clinic();
        break;
    case 2:
        support_menu();
        break;
    case 3:
        Laboratory();
        break;
    case 4:
        break;
    default:
        cout << "Invalid Number!...." << endl;
        oldPatient();
    }
}
void regestrationList() {
    system("cls");
    system("color F3");
    
    
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t       FILL THE FORM IN         \n";
    cout << "\n=====================================================================================\n";
    cout << "Name: ";
    cin >> p.name;
    cout << "Last Name: ";
    cin >> p.lastname;
    cout << "Age: ";
    cin >> p.age;
    cout << "Gender: ";
    cin >> p.gender;
    cout << "Phone Number: ";
    cin >> p.phonenumber;
    cout << "Blood Type: " << endl;
    cout << "1- A " << endl;
    cout << "2- B " << endl;
    cout << "3- AB " << endl;
    cout << "4- O " << endl;
    cout << "5- Unknown  ";
    cin >>p. bloodtype;
    p.str = p.name + p.lastname;
    for (int i = 0; i < p.str.length(); i++)
    {
        p.rCode += (int)p.str[i];
    }

   appoint();

    cout << "Your Rservation Code (ID) is: " << p.rCode << endl;
    cout << "\t-\t\t[    Press 1 To Go Back To The Patient Menu    ]\n";
    cout << "\t-\t\t[    Press 2 To LogOut    ]\n";
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tEnter Your Choice : ";
    cin >> p.r;
    switch (p.r) {
    case 1:
        patientList(p.rCode);
        break;
    case 2:
        break;
    default:
        cout << "Invalid Number!...." << endl;
        _getch();
        regestrationList();
    }

}
void doctorsList(char m, int n) {
    if (m == 'a' || m == 'A') {
        switch (n) {
        case 1:
            cout << "1- Dr Ahmed Samir " << endl;
            Appointment(1);

            break;
        case 2:
            cout << "1- Dr Hassan Ehab " << endl;
            Appointment(2);
            break;
        case 3:
            cout << "1- Dr Waleed Mohamed " << endl;
            Appointment(3);
            break;
        case 4:
            cout << "1- Dr Marwa Ibrahim " << endl;
            Appointment(4);
            break;
        default:
            cout << "Invalid Number!..." << endl;
            _getch();
            clinic();
        }
    }
    if (m == 'b' || m == 'B') {
        switch (n) {
        case 1:
            cout << "1- Dr Hadeer Ahmed " << endl;
            Appointment(5);
            break;
        case 2:
            cout << "1- Dr Salma Hatem " << endl;
            Appointment(6);
            break;
        default:
            cout << "Invalid Number!..." << endl;
            _getch();
            clinic();

        }
    }

}
void clinic() {
    system("cls");
    system("color F3");
    char c;
    int x, d;
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t        Select A Clinic        \n";
    cout << "\n=====================================================================================\n";
    cout << "A- Specialized Clinics " << endl;
    cout << "B- General Surgery Clinic " << endl;

    cout << "\n\n\t\tEnter Your Choice : ";

    cin >> c;
    if (c == 'A' || c == 'a') {
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t        Select The Specialization        \n";
        cout << "\n=====================================================================================\n";
        cout << "1- Cardiology Clinic " << endl;
        cout << "2- Dental Clinic " << endl;
        cout << "3- Eye Clinic " << endl;
        cout << "4- Ears,Nose and Throat Clinic " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";

        cin >> x;

        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t        Select A Doctor       \n";
        cout << "\n=====================================================================================\n";
        doctorsList(c, x);
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> d;
    }

    if (c == 'B' || c == 'b') {
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t        Select The Specialization        \n";
        cout << "\n=====================================================================================\n";
        cout << "1- Endocrine Surgery " << endl;
        cout << "2- Transplant Surgery " << endl;
        cin >> x;
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t        Select A Doctor       \n";
        cout << "\n=====================================================================================\n";
        doctorsList(c, x);
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> d;
    }
    else {
        cout << "Incorrect Choice!...." << endl;
        _getch();
        clinic();
    }


}
void Appointment(int a) {
    system("cls");
    system("color F3");
    int x;
    void Totalcharge(int a);
    cout << "\n===============================================================================\n";
    cout << "\n\n\t\t[Information And Timing Are Given Below]\n";
    cout << "\n--------------------------------------------------------------------------------\n";
    if (a == 1) {
        cout << "\t\t\tDr Ahmed Samir\n\n";
        cout << "\t\t\t [[Timing]]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t 9AM TO 5PM\n";
        cout << "\tSaturday              \t\t9AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\t\t\t[[fees : 350 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(350);
        
            appoint();

        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    if (a == 2) {
        cout << "\t\tDr Hassan Ehab\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\t From Monday to Friday \t\t2PM To 10PM\n";
        cout << "\t Saturday              \t\t8AM\n ";
        cout << "\t Sunday                \t\t 9AM TO 1 PM \n";
        cout << "\t\t\t[[fees : 400 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(400);
            
            appoint();
        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    if (a == 3) {
        cout << "\t\tDr Waleed Mohamed\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t8AM TO 5PM\n";
        cout << "\tSaturday              \t\t10AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\t\t\t[[fees : 300 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(300);
            
            appoint();
        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    if (a == 4) {
        cout << "\t\tDr Marwa Ibrahim\n\n";
        cout << "\t\t\t [[Timing]]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t 9AM TO 5PM\n";
        cout << "\tSaturday              \t\t9AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\t\t\t[[fees : 350 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(350);
            
            appoint();
        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    if (a == 5) {
        cout << "\t\tDr Hadeer Ahmed\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\t From Monday to Friday \t\t2PM To 10PM\n";
        cout << "\t Saturday              \t\t8AM\n ";
        cout << "\t Sunday                \t\t 9AM TO 1 PM \n";
        cout << "\t\t\t[[fees : 250 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(250);
            
            appoint();
        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    if (a == 6) {
        cout << "\t\tDr Salma Hatem\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tFrom Monday to Friday \t\t8AM TO 5PM\n";
        cout << "\tSaturday              \t\t10AM TO 1PM\n ";
        cout << "\tSunday                \t\t off \n";
        cout << "\t\t\t[[fees : 500 EGP]]:\n\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "1- Book Now " << endl;
        cout << "2- Back to clinics " << endl;
        cout << "\n\n\t\tEnter Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            Totalcharge(500);
            
            appoint();
        }
        else
            clinic();
        _getch();
        system("cls");
        oldPatient();
    }
    else {
        cout << "Invalid Number!...." << endl;
        _getch();
        system("cls");
        oldPatient();
    }

    void paymentMethod();
}
void insurance() {
    int n, id;
    //AVAILABLE INSURANCE NUMBERS
    int arr[10]; arr[0] = 623451745;arr[1] = 623125763;arr[2] = 623496823;arr[3] = 623415678; arr[4] = 623145269;arr[5] = 623478956; arr[6] = 623154632; arr[7] = 623015247;arr[8] = 623401432; arr[9] = 623471398;

jump:

    cout << " Do you have health insurance ? :\n 1- Yes \n 2- No \n";

    cin >> n;
    if (n == 1)
    {
        cout << " Enter member ID  : \n";
        cin >> id;
        for (int i = 0; i < 10; i++)
        {

            if (id == arr[i])
            {
                cout << " You have a discount up to 10 % \n";
                cout << " The New total charge = " << (totalcost) * 0.9;
                break;
            }
            else
            {
                cout << "sorry , wrong number .... Try again \n";
                goto jump;
            }
            break;
        }
    }
    else
        if (n == 2)
        {

        }
        else
        {
            cout << " invalid choice \n";
            goto jump;
        }
}
void paymentMethod()
{
    int n, CCnum, scode;
    string CCname, ex;
jump:
    cout << " Choose the payment method :\n 1- Cash payment \n 2- Credit Card Payment \n";
    cin >> n;
    if (n == 1)
    {
        cout << "pleas go to the cashier to complete the payment process \n ";
    }
    else
        if (n == 2)
        {
            cout << " Enter card number \n";
            cin >> CCnum;
            cout << " Enter card holder name \n";
            cin >> CCname;
            cout << "Enter card expiration month/year \n";
            cin >> ex;
            cout << " Enter card security code \n";
            cin >> scode;

        }
        else
        {
            cout << "Invalid choice \n";
            goto jump;
        }
    cout << "Payment completed successfully";
}
void Totalcharge(int a)
{
    totalcost += a;
    cout << "The total charge = " << totalcost << "EGP \n";

    insurance();
    paymentMethod();
}
void CBC()
{
    system("cls");
    system("color F3");
    int Hemoglobina_percent, WBCs_percent, RBCs_percent;
    cout << "If Patient suffer from Shortness of Breath,Fatigue,Chest pain,Arrhythmia,Weakness ,then Patient need to apply  CBC for Anemia test to check up " << endl;
    cout << "\n=====================================================================================\n";
    cout << "Enter your Haemoglobin percent:";
    cin >> Hemoglobina_percent;
    cout << "Enter your WBCs percent:";
    cin >> WBCs_percent;
    cout << "Enter your RBCs percent:";
    cin >> RBCs_percent;
    if (Hemoglobina_percent == 18 && WBCs_percent == 10 && RBCs_percent == 6)
    {

        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << "Patient's CBC is normal" << endl;
        cout << "patient must apply another Blood test to know the cause of his illness" << endl;
    }
    else if (Hemoglobina_percent != 18 && WBCs_percent != 10 && RBCs_percent != 6)

    {
        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << "patient's CBC is not normal" << endl;
        cout << "patient suffer from Anemia" << endl;
    }
    cout << "\n=====================================================================================\n";
    cout << "At the beginning , The patient needs to apply blood test to check up" << endl;
    cout << "Laboratory examination of blood sample used to check for a variety of things, including the functioning of certain organs (such as the liver, kidneys, thyroid and heart), infections and certain genetic disorders, as well as to assess an individual’s general health." << endl;
    cout << "\n=====================================================================================\n";
    cout << "Press Any Key To Continue......." << endl;
    _getch();
    Laboratory();
}
void Cholestrol()
{
    system("cls");
    system("color F3");
    double HDL_percent, LDL_percent;
    cout << "In case that the patient Suffer from FastHeartRate,SlowHeartRate,can't make any effort,Shortness of breath,fainting,dizziness, Then The patient must apply BloodTest for his Heart" << endl;
    cout << "Enter patient's HDL percent:";
    cin >> HDL_percent;
    cout << "Enter patient's LDL percent:";
    cin >> LDL_percent;
    if (HDL_percent >= 40.2 && LDL_percent <= 130.4)

    {
        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << "patient'Heart is okay as HDL and LDL percent is at normal level as it  keeps the arteries open and blood following more smoothly" << endl;

    }
    else if (HDL_percent != 40.2 && LDL_percent != 130.4)

    {
        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << "The Patient is at risk of heart attacks and it can lead to plaque buildup in the arteries, reducing blood flow. These plaque deposits sometimes rupture and lead to major cardiovascular problems." << endl;

    }
    cout << "Press Any Key To Continue......." << endl;
    _getch();
    Laboratory();
}
void Covid_test()
{
    system("cls");
    system("color F3");
    double CRP_percent, D_Dimer_percent, Ferritin_percent;
    cout << "In case that patient suffer from high body temperature,sneezing, loss of sense of smell and taste,tiredness,cough,headache, Then the patient must do covid test " << endl;
    cout << "Enter CRP:";
    cin >> CRP_percent;
    cout << "D-Dimer:";
    cin >> D_Dimer_percent;
    cout << "Ferritin:";
    cin >> Ferritin_percent;
    if (CRP_percent <= 5 && D_Dimer_percent <= 0.5 && Ferritin_percent <= 150)
    {
        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << " Test is negative ,The patient does not have coronavirus" << endl;
    }
    else if (CRP_percent != 5 && D_Dimer_percent != 0.5 && Ferritin_percent != 150)

    {
        cout << "\n=====================================================================================\n";
        cout << "Comment: " << endl;
        cout << " Test is positive, The patient have coronavirus" << endl;
    }
    cout << "Press Any Key To Continue......." << endl;
    _getch();
    Laboratory();

}
void Laboratory()
{
    system("cls");
    system("color F3");
    int x;
    cout << "\t\t   |   ++++++++++  Laboratory  ++++++++++   |  \n";
    cout << "\t\t   |=======================================|   \n";

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t       Select One Option         \n";
    cout << "1-CBC Blood Test " << endl;
    cout << "2-Cholesterol to checkup heart" << endl;
    cout << "3-Covid Test" << endl;
    cout << "4-Return to menu" << endl;
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tEnter Your Choice : ";
    cin >> x;
    cout << endl;
    if (x == 1)
    {
        CBC();
    }
    else if (x == 2)
    {
        Cholestrol();
    }
    else if (x == 3)
    {
        Covid_test();
    }

    else if (x == 4) {
        oldPatient();
    }
    else {
        cout << "Invalid Number! " << endl;
        _getch();
        Laboratory();
    }
}
void appoint() {
    ofstream myfile;
    myfile.open("patientInfo.txt", ios::app); //Chgange filename
 //Change attributes of the patient_info string
    string patient_info = p.name + " , " + p.lastname + " , " + p.gender+ " , "+ to_string(p.bloodtype)+ " , "+ to_string(p.age)+" , " + to_string(p.phonenumber) + " , " + to_string(p.rCode) +"\n";
    myfile << patient_info;
    myfile.close();
}
void support_menu()
{
    int operator_number;
    system("cls");
    system("color F3");
    cout << "\n";
    cout << "=====================================================================================\n";
    cout << "\t\t\t++++++++++WELCOME YOU IN THE SUPPORT AREA++++++++++\n";
    cout << "\t++++++++++WE ARE AT YOUR SERVICE ANY TIME AND ANY WHERE,24 HOURS A DAY++++++++++\n";
    cout << "\n=====================================================================================\n";
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\n\t\t\t\t1)emergency\n";
    cout << "\n\t\t\t\t2)reschedule\n";
    cout << "\n\t\t\t\t3)access data\n";
    cout << "\n\t\t[    Press 4 to rturn to the patient menue    ]\n";
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tplease choose number : ";
    cin >> operator_number;
    switch (operator_number)
    {
    case 1:
        emergency();
        break;
    case 2:
        reschedule();
        break;
    case 3:
        access_data();
        break;
    case 4:
        oldPatient();
        break;
    default:
        cout << "\t\twrong chosen\n";
        support_menu();
    }
}
void emergency()
{
    system("cls");
    system("color F3");
    int operator_number;
    string answer;
    cout << "\n=====================================================================================\n";
    cout << "1)ambulance\n";
    cout << "2)very tired patient\n";
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tplease choose number : ";
    cin >> operator_number;
    system("cls");
    if (operator_number == 1)
    {
        cout << "=====================================================================================\n";
        cout << "\t\tdoes patient has an ID ?";
        cout << "\n------------------------------------------------------------------------------------\n";
        cin >> answer;
        system("cls");
        if (answer == "NO" || answer == "no")
        {
            ambulance();
        }
        else if (answer == "YES" || answer == "yes")
        {
            string caller_name, address, location;
            int id;
            ofstream out("patient.txt");
            if (!out.is_open())
            {
                cout << "you can't open the file\n";
            }
            cout << "please enter your ID:";
            out << "ID:";
            cin >> id;
            out << id;
            cout << "\nplease enter the caller name: ";
            out << "\n8)caller name: ";
            cin >> caller_name;
            out << caller_name;
            cout << endl << "enter the address: ";
            out << endl << "9)the address: ";
            getline(cin, address);
            out << address;
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "enter your location\n";
            out << endl << "10)location: ";
            cin >> location;
            out << location << endl;
            out.close();
            system("cls");
            cout << "=====================================================================================\n";
            cout << "\t\t\t\t++++++++++YOUR DATA HAS BEEN SAVED++++++++++\n";
            cout << "\t\t\t++++++++++WE WILL SEND AN AMBULANCE TO YOU IMMEDIATELY++++++++++\n";
            cout << "------------------------------------------------------------------------------------\n";
            cout << " Press Any Key to return to the support menu...\n";
            _getch();
            system("cls");
            support_menu();
        }
    }
    else if (operator_number == 2)
    {
        string answer;
        cout << "=====================================================================================\n";
        cout << "\t\tdoes patient has an ID ?";
        cout << "\n------------------------------------------------------------------------------------\n";
        cin >> answer;
        system("cls");
        if (answer == "NO" || answer == "no")
        {
            regestration();
            system("cls");
            cout << "=====================================================================================\n";
            cout << "\t\t\t\t++++++++++YOUR DATA HAS BEEN SAVED++++++++++\n";
            cout << "\t\t\t++++++++++FOR YOUR SAFETY,WE WILL TAKE YOU TO THE DOCTOR IMMEDIATELY++++++++++\n";
            cout << "------------------------------------------------------------------------------------\n";
            cout << "Press Any Key to return to the support menu...\n";
            _getch();
            system("cls");
            support_menu();
        }
        else if (answer == "YES" || answer == "yes")
        {
            int id;
            cout << "please enter your ID:";
            cin >> id;
            cout << "=====================================================================================\n";
            cout << "\t\t\t\t++++++++++YOUR DATA IS ALREADY SAVED++++++++++\n";
            cout << "\t\t\t++++++++++FOR YOUR SAFETY,WE WILL TAKE YOU TO THE DOCTOR IMMEDIATELY++++++++++\n";
            cout << "------------------------------------------------------------------------------------\n";
            cout << "Press Any Key to return to the support menu...\n";
            _getch();
            system("cls");
            support_menu();
        }
    }
}
void ambulance()
{
    system("color F3");
    string caller_name, address, location;
    ofstream out("patient.txt", ios::app);
    if (!out.is_open())
    {
        cout << "you can't open the file\n";
    }
    regestration();
    cout << "\ncaller name: ";
    out << "\ncaller name: ";
    cin >> caller_name;
    out << caller_name;
    cout << endl << "address: ";
    out << endl << "address: ";
    getline(cin, address);
    out << address;
    cin.clear();
    cin.ignore(256, '\n');
    cout << endl << "location\n";
    out << endl << "location\n";
    getline(cin, location);
    out << location << endl;
    out.close();
    system("cls");
    cout << "=====================================================================================\n";
    cout << "\t\t\t\t++++++++++YOUR DATA HAS BEEN SAVED++++++++++\n";
    cout << "\t\t\t++++++++++WE WILL SEND AN AMBULANCE TO YOU IMMEDIATELY++++++++++\n";
    cout << "------------------------------------------------------------------------------------\n";
    cout << " Press Any Key to return to the support menu...\n";
    _getch();
    system("cls");
    support_menu();
}
void regestration()
{
    system("color F3");
    int age, phonenumber, bloodtype, rcode = 0;
    string name, lastname, email, gender, str;
    ofstream out("patient.txt");
    if (!out.is_open())
    {
        cout << "you can't open the file\n";
    }
    cout << "Please Fill In The Form\n";
    cout << "Name: ";
    out << "1)Name: ";
    cin >> name;
    out << name;
    cout << endl << "Last Name: ";
    out << endl << "2)Last Name: ";
    cin >> lastname;
    out << lastname;
    cout << endl << "Age: ";
    out << endl << "3)Age: ";
    cin >> age;
    out << age;
    cout << endl << "Gender: ";
    out << endl << "4)Gender: ";
    cin >> gender;
    out << gender;
    cout << endl << "Phonenumber: ";
    out << endl << "5)Phonenumber: ";
    cin >> phonenumber;
    out << phonenumber;
    cout << endl << "E-mail: ";
    out << endl << "6)E-mail: ";
    cin >> email;
    out << email;
    cout << endl << "Blood Type: " << endl;
    cout << "1- A" << endl;
    cout << "2- B" << endl;
    cout << "3- AB" << endl;
    cout << "4- O" << endl;
    cout << "5- Unknown " << endl;
    cout << "choose your blood type: ";
    cin >> bloodtype;
    out << endl << "7)Blood Type: ";
    out << "1- A" << endl;
    out << endl << "2- B" << endl;
    out << "3- AB" << endl;
    out << "4- O" << endl;
    out << "5- Unknown " << endl;
    out << "choose your blood type: ";
    out << bloodtype;
    str = name + lastname;
    for (int i = 0; i < str.length(); i++)
    {
        rcode += (int)str[i];
    }
    cout << endl << "Your resevation code (ID) is: " << rcode << endl;
    out << endl << "Your resevation code (ID) is: " << rcode << endl;
    out.close();
}
void reschedule()
{
    system("cls");
    system("color F3");
    string doctor_name, time;
    int num;
    cout << "plese enter your doctor name :";
    getline(cin, doctor_name);
    cin.clear();
    cin.ignore(256, '\n');
    cout << "\nEnter your new Appointment time :";
    getline(cin, time);
    cout << "\nEnter your new Appointment number :";
    cin >> num;
    system("cls");
    cout << "=====================================================================================\n";
    cout << "\t\t\t++++++++++your data has successfully changed++++++++++\n";
    cout << "------------------------------------------------------------------------------------\n";
    cout << " Press Any Key to return to the support menu...\n";
    _getch();
    system("cls");
    support_menu();
}
void access_data()
{
    system("cls");
    system("color F3");
    string email, caller_name, address, location, answer;
    int phonenumber, bloodtype, number_of_operator;
    char ch;
    ifstream in("patient.txt");
    if (!in.is_open())
    {
        cout << "the file does not exist\n";
    }
    cout << "=====================================================================================\n";
    cout << "\t\t\t++++++++++your entered data are++++++++++";
    cout << "\n------------------------------------------------------------------------------------\n";
    while (!in.eof())
    {
        in.get(ch);
        cout << ch;
    }
    in.close();
    cout << "=====================================================================================\n";
    cout << "\n\t\tdo you want to change your data : ";
    cout << "\n------------------------------------------------------------------------------------\n";
    cin >> answer;
    if (answer == "YES" || answer == "yes")
    {
        cout << "=====================================================================================\n";
        cout << "\n\t\tplease enter number of operator to change your data which are (5,6,7,8,9,or10) : ";
        cout << "\n------------------------------------------------------------------------------------\n";
        cin >> number_of_operator;
        system("cls");
        switch (number_of_operator)
        {
        case 5:
            cout << "=====================================================================================\n";
            cout << "\t\tenter your new Phonenumber:";
            cout << "\n------------------------------------------------------------------------------------\n";
            cin >> phonenumber;
            break;
        case 6:
            cout << "enter your new E-mail: ";
            getline(cin, email);
            break;
        case 7:
            cout << "choose your new Blood Type: " << endl;
            cout << "1- A" << endl;
            cout << "2- B" << endl;
            cout << "3- AB" << endl;
            cout << "4- O" << endl;
            cout << "5- Unknown " << endl;
            cin >> bloodtype;
            break;
        case 8:
            cin.clear();
            cin.ignore(256, '\n');
            cout << "enter your new caller name: ";
            getline(cin, caller_name);
            break;
        case 9:
            cin.clear();
            cin.ignore(256, '\n');
            cout << "=====================================================================================\n";
            cout << "\t\tenter your new address: ";
            cout << "\n------------------------------------------------------------------------------------\n";
            getline(cin, address);
            break;
        case 10:
            cin.clear();
            cin.ignore(256, '\n');
            cout << "enter your new location: ";
            getline(cin, location);
            break;
        default:
            cout << "wrong choice\n";
        }
        system("cls");
        cout << "=====================================================================================\n";
        cout << "\n";
        cout << "\t\t++++++++++your data has successfully changed++++++++++\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        int choice;
        cout << "\n=====================================================================================\n";
        cout << "\n";
        cout << "\t\t\t[    Press 1 to return to access data menue...   ]\n";
        cout << "\t\t\t[    Press 2 to return to the support menue...    ]\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            access_data();
            break;
        case 2:
            support_menu();
            break;
        default: 
            cout << "=====================================================================================\n";
            cout << "\t\t\t++++++++++WRONG CHOSEN++++++++++";
            cout << "\n------------------------------------------------------------------------------------\n";
             cout << " Press Any Key to return to continue...\n";
             _getch();
             system("cls");
             support_menu();
       
        }
        cout << " Press Any Key to return to the support menu...\n";
        _getch();
        system("cls");
        support_menu();
    }
    else
    {
        cout << "\n=====================================================================================\n";
        cout << "\n";
        cout << "\t\t++++++++++DO NOT WORRY YOUR DATA HAS BEEN SAVED++++++++++\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << " Press Any Key to return to the support menu...\n";
        _getch();
        system("cls");
        support_menu();
    }
}

