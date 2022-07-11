// EmployeeTrainingRoster  created by Simone Christen
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int employeeArray[6] = { 420, 69 };
int emp_index = 1;


int rosterSize = sizeof(employeeArray) / 4; // get number of bytes and divide by 4 to get size of int array

int add(int array[], int emp_index, int employeeid)
{
    employeeArray[emp_index] = employeeid;
    cout << "Employee ID # " << employeeid << " is set to index " << emp_index << "\n";
    return 0;
};

int binarySearch(int array[], int key, int l, int r)
{
    int count = 0;

    //As long as left index is less than right index 
    while (l <= r)
    {
        count++;
        //Middle element 
        int m = (l + r) / 2;

        //If the search key on the left half 
        if (key < array[m])
        {
            //Update right index 
            r = m - 1;
        }
        //If the search key on the right half 
        else if (key > array[m])
        {
            //Update the left index 
            l = m + 1;
        }
        //We found the key 
        else
        {
            return count;
        }
    }

    //Key was not found  

    return -1;
};

bool search(int array[], int size, int searchkey)
{
    int len = sizeof(employeeArray) / sizeof(employeeArray[0]);

    // cout<<"Before sorting array : ";
    /* for(int i=0; i<len; i++)
    {
      cout << " " << employeeArray[i];
    } */

    std::sort(employeeArray, employeeArray + len);
    int sortSize = len - 1;
    int sortedArray[sortSize];

    // cout  << "\n\nAfter sorting array : ";
    for (int i = 0; i < len; i++)
    {
        //  cout << " " << employeeArray[i];
        sortedArray[i] = employeeArray[i];
        // cout << " " << sortedArray[i];
    }

    int left = 0;
    int right = rosterSize - 1;


    int outcome = binarySearch(employeeArray, searchkey, 0, rosterSize - 1);

    if (outcome == -1)
    {
        // cout << "searchkey not found.";
        return false;
    }
    else {
        // cout << "searchkey found.";
        return true;
    }


}

int main()
{
    int id;
    int searchkey;
    int menuChoice;

    cout << "MAIN MENU" << "\n" << "Select:" << "\n" "1 to add an employee to the roster, or" << "\n" << "2 to search the roster." << "\n";

    cin >> menuChoice;

    if (menuChoice == 1)
    {
        cout << "Adding employees, type -1 to quit." << "\n" << "Type in an employee ID # to add to the roster." << "\n";

        while (emp_index < rosterSize)
        {
            cin >> id;

            if (id != -1)
            {
                add(employeeArray, emp_index, id);
                emp_index++;
                cout << "Enter another employee ID." << "\n";
                cout << "Checking employee roster for space..." << "\n";
            }
            else {
                cout << "Quitting...";
                return 0;
            }
        }
        cout << "Roster full. No more employee IDs can be added.";

    }
    if (menuChoice == 2)
    {
        // cout << "You selected menu choice 2." << "\n";    

        cout << "\n" << "Enter the searchkey." << "\n";
        cin >> searchkey;

        bool result = search(employeeArray, rosterSize, searchkey);

        if (result == true)
        {
            cout << "Employee ID " << searchkey << " has already completed the required training." << "\n";
        }


        else
        {
            cout << "Employee ID " << searchkey << " must complete the required training" << "\n";
        }

    }


    else {

        return 0;
    }

}
