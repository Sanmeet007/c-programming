#include <conio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;
bool check = true;

struct node
{
    int no, doj, dor, hno;
    string name, fname, dept, country, city, state, pin;
    node *next;
} * head, *lastptr;

void print_user_details(node *current)
{
    if (current != NULL)
        cout << endl
             << "Employee number : " << current->no << endl
             << "Employee name:" << current->name << endl
             << "Employee's father name:" << current->fname << endl
             << "Date of joining:" << current->doj << endl
             << "Department:" << current->dept << endl
             << "Date of retirement:" << current->dor << endl
             << "\nAddress:" << endl
             << "House number:" << current->hno << endl
             << "Country:" << current->country << endl
             << "City:" << current->city << endl
             << "State:" << current->state << endl
             << "PIN:" << current->pin << endl;
    else
        cout << "List is empty" << endl;
}
void add()
{
    node *p;
    p = new node;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t ********************" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "\t\t\t | ENTER NEW RECORD |" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t\t\t ********************" << endl;

    cout << "Enter Employee number (int) :" << endl;
    cin >> p->no;

    cout << "Enter Employee name (string) :" << endl;
    cin >> p->name;

    cout << "Enter Employee's father name (string) :" << endl;
    cin >> p->fname;

    cout << "Enter Date of joining (int) :" << endl;
    cin >> p->doj;

    cout << "Enter Department (string) :" << endl;
    cin >> p->dept;

    cout << "Enter Date of retirement (int) :" << endl;
    cin >> p->dor;

    cout << endl
         << "Address field - "
         << "Enter House number (int) :" << endl;
    cin >> p->hno;

    cout << "Enter Country (string) :" << endl;
    cin >> p->country;

    cout << "Enter City (string) :" << endl;
    cin >> p->city;

    cout << "Enter State (string) :" << endl;
    cin >> p->state;

    cout << "Enter PIN (string) :" << endl;
    cin >> p->pin;

    p->next = NULL;

    if (check)
    {
        head = p;
        lastptr = p;
        check = false;
    }
    else
    {
        lastptr->next = p;
        lastptr = p;
    }
    cout << endl
         << "Record Entered Successfully!" << endl;
    getch();
}
void modify()
{
    node *ptr;
    node *prev = NULL;
    node *current = NULL;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t*****************" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "\t\t\t| MODIFY RECORD |" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t\t\t*****************" << endl;

    int number;
    cout << "Enter Employee number to search:" << endl;
    cin >> number;
    prev = head;
    current = head;
    while (current->no != number)
    {
        prev = current;
        current = current->next;
    }

    ptr = new node;
    cout << "Enter Employee name:" << endl;
    cin >> ptr->name;
    cout << "Enter Employee's father name:" << endl;
    cin >> ptr->fname;
    cout << "Enter Date of joining:" << endl;
    cin >> ptr->doj;
    cout << "Enter Department:" << endl;
    cin >> ptr->dept;
    cout << "Enter Date of retirement:" << endl;
    cin >> ptr->dor;
    cout << "\nEnter Address:" << endl;
    cout << "Enter House number:" << endl;
    cin >> ptr->hno;
    cout << "Enter Country:" << endl;
    cin >> ptr->country;
    cout << "Enter City:" << endl;
    cin >> ptr->city;
    cout << "Enter State:" << endl;
    cin >> ptr->state;
    cout << "Enter PIN:" << endl;
    cin >> ptr->pin;

    prev->next = ptr;
    ptr->next = current->next;
    current->next = NULL;
    delete current;
    cout << endl
         << "Record Modified Successfully!";
    getch();
}

void search()
{

    node *prev = NULL;
    node *current = NULL;

    char ct[20];
    cout << "Enter Employee city to search:" << endl;
    cin >> ct;

    prev = head;
    current = head;
    while (current->city != ct)
    {
        prev = current;
        current = current->next;
    }
    print_user_details(current);
    getch();
}
void del()
{
    node *ptr = NULL;
    node *prev = NULL;
    node *current = NULL;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t*****************" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t\t\t| DELETE RECORD |" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t\t\t*****************" << endl;

    int number;
    cout << "Enter Employee number to Delete:" << endl;
    cin >> number;
    prev = head;
    current = head;
    while (current->no != number)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    current->next = NULL;
    delete current;
    cout << endl
         << "Record Deleted Successfully!";
    getch();
}

void get_records(string type)
{
    // Prints records based type of details wanted
    int records_found = 0;
    string state, city, country;
    int doj, dor;
    node *temp = head;

    if (type == "loc")
    {
        cout << "Enter state : " << endl;
        cin >> state;
        cout << "Enter country : " << endl;
        cin >> country;
        cout << "Enter city : " << endl;
        cin >> city;

        while (temp != NULL)
        {
            if (temp->state == state)
            {
                print_user_details(temp);
                records_found++;
            }

            temp = temp->next;
        }
    }
    else if (type == "dor")
    {
        cout << "Enter retired date : " << endl;
        cin >> dor;

        while (temp != NULL)
        {
            if (temp->dor == dor)
            {
                print_user_details(temp);
                records_found++;
            }

            temp = temp->next;
        }
    }
    else if (type == "doj")
    {
        cout << "Enter joining date : " << endl;
        cin >> doj;

        while (temp != NULL)
        {
            if (temp->doj == doj)
            {
                print_user_details(temp);
                records_found++;
            }

            temp = temp->next;
        }
    }

    cout << endl
         << "Total " << records_found << " records found." << endl;

    getch();
}

void backup_records()
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << endl
             << "List is empty" << endl;
        getch();
        return;
    }

    try
    {
        string file_extentsion = "csv";
        ofstream file("records." + file_extentsion, ios::out);

        file << "id,name,father_name,date_of_joining,department,date_of_retirement,house_number,country,city,state,pin" << endl;

        while (temp != NULL)
        {
            file << ""
                 << temp->no << ","
                 << temp->name << ","
                 << temp->fname << ","
                 << temp->doj << ","
                 << temp->dept << ","
                 << temp->dor << ","
                 << temp->hno << ","
                 << temp->city << ","
                 << temp->state << ","
                 << temp->pin << ""
                 << endl;
            temp = temp->next;
        }

        file.close();

        cout << endl
             << "Records saved successfully " << endl;
        getch();
    }
    catch (exception e)
    {
        cout << endl
             << "An error occured while writing to file !" << endl;
        getch();
    }
}

int main()
{
    char x;
    do
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 1);
        cout << "\t\t\t-----------------------------" << endl;

        cout << "\t\t\t| EMPLOYEE MANAGEMENT SYSTEM |" << endl;

        cout << "\t\t\t-----------------------------" << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Delete Record" << endl;
        cout << "\t\t\t 5. Search Record (location based) \n";
        cout << "\t\t\t 6. Search Record (retired date) \n";
        cout << "\t\t\t 7. Search Record (joining date) \n";
        cout << "\t\t\t 8. Backup all records \n";
        cout << "\t\t\t 9. Exit\n"
             << endl;
        SetConsoleTextAttribute(h, 8);
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tChoose Options:[1/2/3/4/5]" << endl;
        cout << "\t\t\t............................" << endl;
        SetConsoleTextAttribute(h, 7);

        x = getch();

        switch (x)
        {
        case '1':
            add();
            break;
        case '2':
            search();
            break;
        case '3':
            modify();
            break;
        case '4':
            del();
            break;
        case '5':
            get_records("loc");
            break;
        case '6':
            get_records("dor");
            break;
        case '7':
            get_records("doj");
            break;
        case '8':
            backup_records();
            break;
        case '9':
            exit(0);
            break;

        default:
            // Handle default case here
            break;
        }
    } while (x != 27);
    getch();

    return 0;
}
