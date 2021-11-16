
#include "cmpslib19.h"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#include "SLinkedList.h"
#include "fraction.h"


void ShowMenu()
{
    cout << "  Linked List Menu \n";
    cout << "  ==================================================\n";
    cout << "  i  Insert a value into the list                   \n";
    cout << "  a  Insert a value After a value                   \n";
    cout << "  d  Delete a value from the list (1st from front)  \n";
    cout << "  e  Delete from the end  (last value)              \n";
    cout << "  c  Does the list contain a specific value         \n";
    cout << "  p  Print the value returned by ToString           \n";
    cout << "  f  Print the value returned by Front()            \n";
    cout << "  b  Print the value returned by Back()             \n";
    cout << "  m  Show this menu                                 \n";
    cout << "  x  Exit                                           \n";
    cout << "  ==================================================\n";
}

int main()
{
    InitializeLogger("runme1.log");



    if (true)
    { // make a subsccope


        SLinkedList<ELEMTYPE>  list;
        ELEMTYPE elem;
        ELEMTYPE elem2;

        char selection;
        ShowMenu();

        do
        {
            Prompt("  Enter selection: ",selection);
            cout << "\nOption " << selection << " chosen\n";

            switch(selection)
            {

                case 'i':
                    Prompt("Enter element to insert into the list: ",elem);
                    if(list.Insert(elem))
                    {
                        cout << elem << " was added.\n";
                    }
                    else
                    {
                        cout << elem << " was NOT added.\n";
                    }
                    break;

                case 'a':
                    Prompt("Enter element to insert into the list: ", elem);
                    Prompt("Enter element to insert after: ", elem2);
                    list.InsertAfter(elem2, elem);
                    break;

                case 'd':
                    Prompt("Enter element to delete: ", elem);
                    if(list.Delete(elem) == true)
                        cout << elem << " removed from the list." << endl;
                    else
                        cout << "Could not remove " << elem << " from the list." << endl;
                    break;

                case 'e':
                    list.DeleteEnd();
                    cout << "last value removed from the list." << endl;
                    break;

                case 'c':
                    Prompt("Enter value to check for: ", elem);
                    if(list.Contains(elem) == true)
                        cout << elem << " is in the list." << endl;
                    else
                        cout << elem << " is not in the list." << endl;
                    break;

                case 'p':
                    cout << list.ToString() << endl;
                    break;

                case 'f':
                    cout << list.Front() << endl;
                    break;

                case 'b':
                    cout << list.Back() << endl;
                    break;

                case 'm':
                    ShowMenu();
                    break;

                case 'x':
                    cout << "Goodbye.\n";
                    break;
                
                default:
                    cout << "Invalid menu option!\n";

            }
        }
        while(selection != 'x');
    }// end of subscope

}



