#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename I>
class Memory_Calculate
{
private:
    I id;
    string name;

public:
    Memory_Calculate(I Student_Id, string Student_Name)
    {
        this->id = Student_Id;
        this->name = Student_Name;
    }

    void Show_Student_Details()
    {
        // cout <<  id << " , Name: "<< name << endl;

        cout << "-------------------------------------------------" << endl;
        cout << " ID: " << id << "       Name: " << name << endl;
        cout << "-------------------------------------------------" << endl;
    }

    I getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }
};

template <typename I>
class Student_Management_System
{
private:
    vector<Memory_Calculate<I>> students;

public:
    void Add_Student(I id, string name)
    {
        int count = 0;
        for (Memory_Calculate<I> &student : students)
        {
            if (student.getID() == id)
            {
                count++;
            }
        }

        if (count == 0)
        {
            students.push_back(Memory_Calculate<I>(id, name));
            cout << "Student added successfully!" << endl;
        }
        else
        {
            cout << "Student with ID " << id << " already exists ." << endl;
        }
    }

    void Display_All_Students()
    {
        int All_Student = students.size();

        if (All_Student == 0)
        {
            cout << "0 Students availabe in this system.";
            return;
        }

        cout << "=================================================" << endl;
        cout << "|                 STUDENT LIST                  |" << endl;
        cout << "=================================================" << endl;
        cout << "| ID        | NAME                              |" << endl;
        cout << "-------------------------------------------------" << endl;

        for (Memory_Calculate<I> &student : students)
        {
            student.Show_Student_Details();
        }
    }

    void Remove_Student(I id)
    {
        int remove_ID = -1;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getID() == id)
            {
                remove_ID = i;
            }
        }
        if (remove_ID != -1)
        {
            students.erase(students.begin() + remove_ID);
            cout << "Student with ID " << id << " Removed Succefully!" << endl;
        }
        else
        {
            cout << "Student Not found with ID" << id << endl;
        }
    }

    void Serching(I id)
    {
        int found_ID = -1;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getID() == id)
            {
                found_ID = i;
                break;
            }
        }
        if (found_ID != -1)
        {
            cout << "Student Founded:" << endl;
            students[found_ID].Show_Student_Details();
        }
        else
        {
            cout << "Student not availabel with ID " << id << endl;
        }
    }
};

void Menu()
{
    Student_Management_System<int> STDSYSTM;
    int choice, id;
    string name;

    do
    {
        cout << endl << endl;
        cout << "#################################################" << endl;
        cout << "#                                               #" << endl;
        cout << "#           STUDENT MANAGEMENT SYSTEM           #" << endl;
        cout << "#                                               #" << endl;
        cout << "#################################################" << endl;
        cout << "=================================================" << endl;
        cout << "|  1  |  Add Student To A List.                 |" << endl;
        cout << "=================================================" << endl;
        cout << "|  2  |  Display The List Of Student.           |" << endl;
        cout << "=================================================" << endl;
        cout << "|  3  |  Remove A Student From The List by ID.  |" << endl;
        cout << "=================================================" << endl;
        cout << "|  4  |  Search For A Student by ID.            |" << endl;
        cout << "=================================================" << endl;
        cout << "|  5  |  For Exit...                            |" << endl;
        cout << "=================================================" << endl;

        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;
            STDSYSTM.Add_Student(id, name);
            break;

        case 2:
            STDSYSTM.Display_All_Students();
            break;

        case 3:
            cout << "Remove Student with ID: ";
            cin >> id;
            STDSYSTM.Remove_Student(id);
            break;

        case 4:

            cout << "Search A Student With ID: ";
            cin >> id;
            STDSYSTM.Serching(id);
            break;

        case 5:
            cout << "Exiting Student Management System." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    while (choice != 5);
}

int main()
{

    Menu();

    return 0;
}