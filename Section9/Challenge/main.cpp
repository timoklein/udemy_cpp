// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;

int main(){

    bool flag {true};
    // needs to be declared outside loop! Else it's always reset to empty with each iteration
    vector <int> list;

    do {
        cout << "-----------------------" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";

        char user_input {};
        cin >> user_input;
        user_input = std::tolower(user_input);

        switch (user_input) {
            // Case 'p': Display list if not empty (done)
            case 'p': {
                if (list.size() == 0)
                    cout << "[] - the list is empty" << endl;
                else {
                    cout << "[ ";
                    for (auto item: list) {
                        cout << item << " ";
                    }
                    cout << "]" << endl;
                }
            break;
            }

            // case 'a': ask for integer and add to the list
            case 'a': {
                int add_to_list {};
                cout << "Please enter an integer to add to the list: ";
                cin >> add_to_list;
                list.push_back(add_to_list);
                break;
            }

            // calculate the mean unless the list has no elements (done)
            case 'm':{
                if (list.size() == 0)
                    cout << "Unable to calculate the mean - no data" << endl;
                else {
                    double sum {};
                    for (auto value: list){
                        sum += value;
                    }
                    cout << "The mean of the list is " << sum/list.size() << endl;
                }
                break;
            }

            // display the smallest element when there are elements in the list (done)
            case 's':{
                if (list.size() == 0)
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                else {
                    int minimum {list.at(0)};
                    for (unsigned i {1}; i < list.size(); ++i){
                        if (list.at(i) < minimum)
                            minimum = list.at(i);
                    }
                    cout << "The smallest number is " << minimum << endl;
                }
                break;
            }

            // display the largest element when there are elements in the list (done)
            case 'l':{
                if (list.size() == 0)
                    cout << "Unable to determine the largest number - list is empty" << endl;
                else {
                    int maximum {list.at(0)};
                    for (unsigned i {1}; i < list.size(); ++i){
                        if (maximum < list.at(i))
                            maximum = list.at(i);
                    }
                    cout << "The largest number is " << maximum << endl;
                }
                break;
            }

            // quit the program (done)
            case 'q':{
                cout << "Goodbye!" << endl;
                flag = false;
                break;
            }

            // Other cases -> invalid input; go to start (done)
            default:{
                cout << "Unknown selection, please try again" << endl;
                continue;
            }
        }

    } while (flag);


    return 0;
    
}