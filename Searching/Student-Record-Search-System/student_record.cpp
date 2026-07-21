// Develop a menu - driven Student Record Search System in C++ that allows users to manage student records efficiently.The application should support adding, updating, deleting, displaying, sorting, and searching student records while demonstrating the practical implementation of searching algorithms.
// Each student record should include the following informatio
//  PRN Number(Unique Identifier) Roll Number Student Name Department Semester CGPA
// The system must ensure that every PRN Number is unique and prevent duplicate entries.
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

struct Student
{
    int prn;
    int rollNo;
    string name;
    string department;
    int semester;
    float cgpa;
};

void display_record(const vector<Student> &record)
{
    if (record.empty())
    {
        cout << "No student records found.\n";
        return;
    }

    cout << string(95, '-') << endl;

    cout << left
         << setw(15) << "PRN"
         << setw(10) << "Roll No"
         << setw(25) << "Name"
         << setw(20) << "Department"
         << setw(12) << "Semester"
         << setw(8) << "CGPA"
         << endl;

    cout << string(95, '-') << endl;

    for (int i = 0; i < record.size(); i++)
    {
        cout << left
             << setw(15) << record[i].prn
             << setw(10) << record[i].rollNo
             << setw(25) << record[i].name
             << setw(20) << record[i].department
             << setw(12) << record[i].semester
             << fixed << setprecision(2)
             << setw(8) << record[i].cgpa
             << endl;
    }

    cout << string(95, '-') << endl;
}

class Student_Record
{
public:
    int prn;
    string name;

    Student s;
    void add_student(vector<Student> &record)
    {

        int n;
        cout << "Enter number of students to add: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "\n========== Student " << (i + 1) << " ==========\n";

            // Unique PRN Validation
            while (true)
            {
                bool found = false;

                cout << "Enter PRN: ";
                cin >> s.prn;

                for (int j = 0; j < record.size(); j++)
                {
                    if (record[j].prn == s.prn)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    cout << "PRN already exists! Please enter a different PRN.\n";
                }
                else
                {
                    break;
                }
            }

            cout << "Enter Roll Number: ";
            cin >> s.rollNo;

            cout << "Enter Student Name: ";
            getline(cin >> ws, s.name);

            cout << "Enter Department: ";
            getline(cin >> ws, s.department);

            cout << "Enter Semester: ";
            cin >> s.semester;

            cout << "Enter CGPA: ";
            cin >> s.cgpa;

            record.push_back(s);

            cout << "Student added successfully!\n";
            sort(record.begin(), record.end(), [](Student a, Student b)
                 { return a.prn < b.prn; });
        }
    }

    void update_student(vector<Student> &record)
    {
        if (record.empty())
        {
            cout << "No record exists to update..." << endl;
        }
        bool found = false;
        cout << "Enter a student prn to update:";
        cin >> prn;
        int start = 0, end = record.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (record[mid].prn == prn)
            {
                found = true;
                cout << "Enter a new prn to update:";
                cin >> record[mid].prn;
                cout << "Enter a new roll no to update:";
                cin >> record[mid].rollNo;
                cout << "Enter a name to update:";
                getline(cin >> ws, record[mid].name);
                cout << "Enter a department to update:";
                getline(cin >> ws, record[mid].department);
                cout << "Enter Semester to update:";
                cin >> record[mid].semester;
                cout << "Enter a GPA to update:";
                cin >> record[mid].cgpa;
                cout << endl
                     << "Student record updated Succesfully!...." << endl;
                break;
            }
            else if (record[mid].prn < prn)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (!found)
        {
            cout << "Student prn dose'nt exists..." << endl;
        }
    }

    void delete_student(vector<Student> &record)
    {
        bool found = false;
        cout << "Enter a student prn to delete:";
        cin >> prn;
        int start = 0, end = record.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (record[mid].prn == prn)
            {
                found = true;
                record.erase(record.begin() + mid);
                cout << "Record deleted succesfully!.." << endl;
                break;
            }
            else if (record[mid].prn < prn)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (!found)
        {
            cout << "Student not found..." << endl;
        }
    }

    void department_record(const vector<Student> &record)
    {
        if (record.empty())
        {
            cout << "No student records found.\n";
            return;
        }

        map<string, vector<Student>> deptMap;

        // Group students department-wise
        for (const auto &s : record)
        {
            deptMap[s.department].push_back(s);
        }

        for (const auto &dept : deptMap)
        {
            string heading = "Department : " + dept.first;

            cout << "\n";
            cout << string(90, '=') << endl;
            cout << setw((90 + heading.length()) / 2) << heading << endl;
            cout << string(90, '=') << endl;

            cout << left
                 << setw(15) << "PRN"
                 << setw(10) << "Roll No"
                 << setw(25) << "Name"
                 << setw(20) << "Department"
                 << setw(12) << "Semester"
                 << setw(8) << "CGPA"
                 << endl;

            cout << string(90, '-') << endl;

            for (const auto &s : dept.second)
            {
                cout << left
                     << setw(15) << s.prn
                     << setw(10) << s.rollNo
                     << setw(25) << s.name
                     << setw(20) << s.department
                     << setw(12) << s.semester
                     << fixed << setprecision(2)
                     << setw(8) << s.cgpa
                     << endl;
            }

            cout << string(90, '-') << endl;
            cout << "Total Students : " << dept.second.size() << "\n";
        }
    }

    void serach_student(const vector<Student> &record)
    {
        bool found = false;
        cout << "Enter a name of student to search record:";
        getline(cin >> ws, name);
        vector<int> match;
        for (int i = 0; i < record.size(); i++)
        {
            if (record[i].name == name)
            {
                found = true;
                match.push_back(i);
            }
        }
        if (!found)
        {
            cout << "No record for the student exists..." << endl;
        }
        else
        {
            cout << string(90, '-');
            cout << left
                 << setw(15) << "PRN"
                 << setw(10) << "Roll No"
                 << setw(25) << "Name"
                 << setw(20) << "Department"
                 << setw(12) << "Semester"
                 << setw(8) << "CGPA"
                 << endl;

            cout << string(90, '-') << endl;
            for (int i = 0; i < match.size(); i++)
            {
                cout << left
                     << setw(15) << record[match[i]].prn
                     << setw(10) << record[match[i]].rollNo
                     << setw(25) << record[match[i]].name
                     << setw(20) << record[match[i]].department
                     << setw(12) << record[match[i]].semester
                     << fixed << setprecision(2)
                     << setw(8) << record[match[i]].cgpa
                     << endl;
            }
            cout << string(90, '-') << endl;
        }
    }
};

int main()
{
    cout << "----Welcome To Student Record Managemnt System-----" << endl
         << endl;
    vector<Student> record;
    int ch;
    Student_Record sr;
    while (true)
    {
        cout << "---Menu---" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Add a Student" << endl;
        cout << "2. Update Student Record" << endl;
        cout << "3. Delete  Student Record" << endl;
        cout << "4. Display All Student Record" << endl;
        cout << "5. Display Department Wise Record" << endl;
        cout << "6. Search Student Record" << endl;
        cout << "7. Exit" << endl;
        cout << "---------------------------------------" << endl
             << endl;
        cout << "Enter a choice:";
        cin >> ch;
        if (ch == 1)
        {
            sr.add_student(record);
        }
        else if (ch == 2)
        {
            sr.update_student(record);
        }
        else if (ch == 3)
        {
            sr.delete_student(record);
        }
        else if (ch == 4)
        {
            display_record(record);
        }
        else if (ch == 5)
        {
            sr.department_record(record);
        }
        else if (ch == 6)
        {
            sr.serach_student(record);
        }
        else
        {
            break;
        }
    }

    return 0;
}