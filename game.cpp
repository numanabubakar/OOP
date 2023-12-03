#include<iostream>
#include <string>  //library for using string related operations such as getline
#include <fstream> //library for file handling functions
#include <vector>  //library for using vectors and related operations

    using namespace std;

struct Patient
{ // using structures to save different datatypes through one name
    int id;
    string f_name;
    string s_name;
    string address;
};

struct Appointment
{
    int id;
    string date;
    string time;
};

struct Billing
{
    int id;
    int amount;
};

vector<Patient> patients; // using vectors. Vectors will store different objects of a structure in sequence
vector<Appointment> appointments;
vector<Billing> billings;

void addPatient()
{              // function for adding data of patients
    Patient p; // p as an object of structure type Patient
    cout << "Enter patient ID: ";
    cin >> p.id; // id as an element of object p
    cout << "Enter patient's first name: ";
    cin >> p.f_name;
    cout << "Enter patient's second name: ";
    cin >> p.s_name;
    cout << "Enter patient address: (Press . to end)" << endl;
    getline(cin, p.address, '.'); // we use getline because address contains spaces, and string doesn't take them
    patients.push_back(p);        // push_back func used to store an object in a vector
    cout << "Patient added successfully." << endl;
}

void deletePatient()
{ // function to remove the date of a patient
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < patients.size(); i++)
    { // patients.size() contains the size of patients vector
        if (patients[i].id == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Patient not found." << endl;
        return;
    }
    patients.erase(patients.begin() + index);
    cout << "Patient deleted successfully." << endl;
}

void modifyPatient()
{
    int id;
    cout << "Enter patient ID to modify: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].id == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Patient not found." << endl;
        return;
    }
    Patient p = patients[index];
    cout << "Enter patient's first name: ";
    cin >> p.f_name;
    cout << "Enter patient's second name: ";
    cin >> p.s_name;
    cout << "Enter patient address: (Press . to end)" << endl;
    getline(cin, p.address, '.');
    patients[index] = p;
    cout << "Patient modified successfully." << endl;
}

void scheduleAppointment()
{
    Appointment a;
    cout << "Enter appointment ID: ";
    cin >> a.id;
    cout << "Enter appointment date (DD/MM/YYYY):";
    cin >> a.date;
    cout << "Enter appointment time (24 hours format):";
    cin >> a.time;
    appointments.push_back(a);
    cout << "Appointment scheduled successfully." << endl;
    ofstream file;
    file.open("Appointment.txt");
    file << "\nAppointment ID: " << a.id << endl;
    file << "Date: " << a.date << endl;
    file << "Time: " << a.time << endl;
    file.close();
}

void generateBill()
{
    Billing b;
    cout << "Enter billing ID: ";
    cin >> b.id;
    cout << "Enter billing amount: ";
    cin >> b.amount;
    billings.push_back(b);
    cout << "Bill generated successfully." << endl;
}

void displayPatients()
{
    for (int i = 0; i < patients.size(); i++)
    {
        cout << i + 1 << " ID: " << patients[i].id << "\nName: " << patients[i].f_name << " " << patients[i].s_name << "\nAddress: " << patients[i].address << endl;
    }
}

void displayAppointments()
{
    for (int i = 0; i < appointments.size(); i++)
    {
        cout << i + 1 << " ID: " << appointments[i].id << "\nDate: " << appointments[i].date << "\nTime: " << appointments[i].time << endl;
    }
}

void displayBillings()
{
    cout << "ID\tAmount" << endl;
    for (int i = 0; i < billings.size(); i++)
    {
        cout << i + 1 << " ID: " << billings[i].id << "\nAmount: " << billings[i].amount << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\nWelcome to the Main Menu of Lahore Hospital's Management System!" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Delete Patient" << endl;
        cout << "3. Modify Patient" << endl;
        cout << "4. Schedule Appointment" << endl;
        cout << "5. Generate Bill" << endl;
        cout << "6. Display Patients" << endl;
        cout << "7. Display Appointments" << endl;
        cout << "8. Display Billings" << endl;
        cout << "9. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            deletePatient();
            break;
        case 3:
            modifyPatient();
            break;
        case 4:
            scheduleAppointment();
            break;
        case 5:
            generateBill();
            break;
        case 6:
            displayPatients();
            break;
        case 7:
            displayAppointments();
            break;
        case 8:
            displayBillings();
            break;
        case 9:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 9);
    return 0;
}