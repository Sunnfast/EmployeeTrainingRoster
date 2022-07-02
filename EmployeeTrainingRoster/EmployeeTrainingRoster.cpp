// EmployeeTrainingRoster  created by Simone Christen
//

#include <iostream>
#include <string>
#include <algorithm>;
using namespace std;

int employeeArray [6] = {1};
int emp_index;
int id;
int rosterSize;
int searchkey;

int add(int array[], int emp_index, int employeeid)
{
    cout << "Enter the employee ID that you wish to add to the roster" << "\n" << "and then add the index on the roster where you want to place them.";
    cin >> id;
    cin >> emp_index;

    cout << "the id is " << id <<" and the emp_index is " << emp_index;

    return 0;
}

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
}

int search(int array[], int size, int searchkey)
{
    sort(array, array + size);

    //receives input array along with left and right indexes
    //Returns the index of the search key if it is found 
    //otherwise it returns -1 

    //check to see if sorts in place or produces new array sorted
   
    binarySearch(employeeArray, searchkey, /*left, right */);

}

int main()
{
    add(employeeArray, emp_index, id);
    search(employeeArray, rosterSize, searchkey);
}

/*
Add function: (5 points)

    add one employee id number to the array in the specified emp_index position
    Required parameters: array, emp_index, employeeid

Search function: (5 points)

    sort the array, then search for a specific employee id.
    Required parameters: array, size, searchkey
    Required return value: true if the searchkey if found, or false if not found

main function: (10 points)

    Create an array and a variable to hold the size of the array.
    Create a menu with 2 options: 
    "1. Add employee to training roster" and  
    "2. Search for an employee on the training roster" . 
    Note, this menu does not need to be in a loop, but it would be a nice enhancement if you are up to the challenge.
    Prompt the user to select a menu option.
    If the user chooses to add an employee, 
    you will need a variable called emp_index to track the number of employees that are added to the roster.  
    Run a loop for input of employee ids in the main function. Use a while loop or a do while loop (do not use a for loop).
        Prompt the user to input the employee id until the user inputs -1.
        If the array is not full, call the add function in the body of the loop, pass the required arguments, then increment the emp_index variable.
        If the array is full, display the message "Roster full" and break out of the loop.
    If the user chooses to search for an employee, ask the user for the employee id.  
    Call the search function and pass the required arguments.  Display a message depending on the return value of the search function.  For example, if the searchkey was 8345, the following message should display if the search function returns true: "Employee id 8345 has already completed the required training". Otherwise, display a different message.  For example, if the searchkey is 8345, the following message should display if the search function returns false: "Employee id 8345 must complete the required training".


*/
