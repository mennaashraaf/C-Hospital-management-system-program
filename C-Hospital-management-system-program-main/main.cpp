#include<iostream>
#include<string>
#include "DoctorCode.h"
#include "PatientCode.h"
using namespace std;

int main()
{
    system("cls");
    system("color F3");
    cout << "\n";
    cout << "\n";

    cout << "\t\t   |   ++++++++++  MAIN MENU  ++++++++++   |  \n";
    cout << "\t\t   |       Hospital Management System      |\n";
    cout << "\t\t   |=======================================|   \n";

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t       Select One Option         \n";
    cout << "1-Doctor " << endl;
    cout << "2-Patient  " << endl;
    cout << "\n=====================================================================================\n";
    cout << "\n\n\t\tEnter Your Choice : ";
    int x;
    cin >> x;
    if (x == 1) {
        pascode();
    }
    else if (x == 2) {
        patientList(0);
    }
    return 0;
}

//1- Login --> pascode()
//2- Select Doctor/Patient
//If Doctor -> Menu of DoctorCode   --> menu()
//If Patient -> Menu of PatientCode --> _menu()