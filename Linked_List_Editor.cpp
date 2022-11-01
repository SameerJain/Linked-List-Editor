/*
TODO:Double Check Length function
test find function
*/
#include <iostream>
using namespace std;

struct node
{

    int data;
    node *next;
};

class list
{

public:
    bool SortedIsEmpty();  // Returns true if the list is empty
    int SortedGetLength(); // returns length of the list
    bool SortedFind(int pos, int &x); // returns the value of the kth element
    int SortedSearch(int key); // returns the position of the element which is the same as key
    void SortedInsert1(int x); // inserts x to the right postion of the sorted linked list ALLOWING FOR DUPLICATE
    void SortedInsert2(int x); // Inserts WITHOUT ALLOWING FOR DUPLICATE ELEMENT
    void SortedDelete(int pos, int &x, bool &success); // deletes the kth element

    void PrintList(); // Prints out the entire linked list
    void DeleteLargest();
private:
    node *head = 0;
};

int main()
{

    list sList;

    int input;int pos;int x;bool success;

// Intro
    cout << "********************************" << endl;
    cout << "Welcome to the Linked List Editor!" << endl;
    cout << "********************************" << endl;
    cout << "Select the operation you would like to perform on the Sorted Singly Linked List!  " << endl << endl;

    while (true)
    {

        // options
        cout << "\n\nMenu:\n";
        cout << "1) Check if the list is Empty\n";
        cout << "2) Get the length of the list\n";
        cout << "3) Find the value of the element from given postion\n";
        cout << "4) Find the position of the element which is the same as the key\n";
        cout << "5) Insert a value to the right postion of the sorted linked list ALLOWING FOR DUPLICATE\n";
        cout << "6) Insert WITHOUT allowing for duplicate element of the linked list\n";
        cout << "7) Delete a element form the linked list from given position\n";
        cout << "8) Print out the linked list\n ";
        cout << "9) Delete largest element of the linked list\n ";
        cout << "\n\nEnter a choice: ";

        cin >> input;

        cout << "\n\n";

        // Switch case for options

        switch (input)
        {

        case 1:

            cout << "Checking if the list is empty:\n";

            if (sList.SortedIsEmpty() == true)
            {
                cout << "List is Empty\n";
            }
            else
            {
                cout << "List is NOT empty\n";
            }
            break;

        case 2:
            cout << "Getting the length of the list:\n";
            cout << "Length of list: " << sList.SortedGetLength();
            break;
        case 3:
            cout << "Enter element position number: ";
            cin >> pos;
            cout << "Finding value of element in postion:" << pos << endl;
            sList.SortedFind(pos, x);
            cout << "Value of Element " << pos << " is:" << x << "\n";
            break;
        case 4:
            cout << "Enter element position number: ";
            cin >> x;
            sList.SortedSearch(x);
            break;
        case 5:
            cout << "Inserting into list allowing for duplicate\n";
            cout << "Enter a number to insert: ";
            cin >> x;
            sList.SortedInsert1(x);
            sList.PrintList();
            cout << "\nSuccess!";
            break;
        case 6:
            cout << "Inserting into list WITHOUT allowing for duplicate\n";
            cout << "Enter a number to insert: ";
            cin >> x;
            sList.SortedInsert2(x);
            sList.PrintList();
            break;
        case 7:
            cout << "Delete a element from the given position:\n";
            cout << "Enter position";
            cin >> pos;
            sList.SortedDelete(pos,x,success);
            sList.PrintList();
            break;
        case 8:
            cout <<"Printing the entire list:\n";
            sList.PrintList();
            break;
        case 9:
        cout << "Delete largest\n\n";
        sList.DeleteLargest();
        sList.PrintList();
        break;

        default:
        cout << "Invalid Input";

        }
        
    }
}

// Function Definitons


bool list::SortedIsEmpty()
{

    node *temp = new node();
    temp = head;

    if (head == NULL)
    {

        return false;
    }

    while (temp != NULL)
    {

        if (temp == NULL)
        {

            return false;
        }

        temp = temp->next;
    }

    return true;
}

int list::SortedGetLength()
{

    int counter = 0;

    node *temp = head;

    while (temp != NULL)
    {

        counter++;

        temp = temp->next;
    }

    return counter;
}

bool list::SortedFind(int k, int &x){

    
    node *temp = head;

    int counter = 1;

  if (k == 0 || list::SortedGetLength() < k)
    {

        cout << "Invalid Positon for Find Function " << endl;

        return false;
    }

        while (counter != k)
    {

        temp = temp->next;
        counter++;
    }

    x = temp->data;

    return true;
    
}

int list::SortedSearch(int key)
{

    node *temp = head;
    int counter = 1;

    if (head == NULL)
    {

        cout << "List is empty" << endl;
        return -1;
    }

    while (temp != NULL)
    {

        if (temp->data == key)
        {
            cout << "Element " << key << " is found in position: " << counter << "\n";
            return 0;
        }

        else if(temp->data > key) {
            cout << "Doesnt Exist.";
            return -1;
        }

        temp = temp->next;
        counter++;
    }

    if (temp == NULL)
    {

        cout << key << " is not found in list\n";

        return -1;
    }

    return 0;
}

void list::SortedInsert1(int x)
{ 
    node *temp;
    node *s = new node();
    temp = head;
    s->data = x; 

    if (head == NULL){
        head = s;
    }

    else if(x <= head->data){
    s->next = head;
    head = s;
    return; 
    }

    else {


        while (temp->next != NULL){

            if(temp->next->data >= x) {
                s->next = temp->next;
                temp->next = s;
                break;
            }

            else{
            temp = temp->next;
            }
        }

        if(temp->next == NULL){
        s->next = NULL;
        temp->next = s;
        }
    }

}

void list::SortedInsert2(int x)
{

    node *temp;
    node *s = new node();
    temp = head;
    s->data = x; 

    if (head == NULL){
        head = s;
    }

    else if(x <= head->data){
    s->next = head;
    head = s;
    return; 
    }

    else {


        while (temp->next != NULL){

            if(temp->next && temp->next->data == x) {
                cout << x << " Already in list\n";
                break;
            }

            else{
            temp = temp->next;
            }
        }

        if(temp->next == NULL){
        s->next = NULL;
        temp->next = s;
        }
    }

}

void list::SortedDelete(int k, int &x, bool &success)
{

    node *temp = new node();
    node *s = new node();
    temp = head;

    int counter = 0;

    if (head == NULL)
    {
        success = false;

        cout << "List is empty\n";
        return;
    }

    if (k == 1)
    {

        success = true;

        head = temp->next;
    }

    else
    {

        while (temp != NULL)
        {

            temp = temp->next;

            counter++;
        }

        if (k > counter || k <= 0)
        {
            success = false;

            cout << "Invalid position\n";
        }

        else
        {
            success = true;

            temp = head;

            for (int i = 1; i < k; i++)
            {

                s = temp;

                temp = temp->next;
            }

            s->next = temp->next;
        }
    }

    x = temp->data;
    cout << "Value of deleted element is: " << x << "\n";
    delete temp;
}

void list::PrintList()
{

    node *temp = new node();
    temp = head;

    if (head == NULL)
    {
        cout << "List is empty\n";
    }

    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL";
        cout << "\n";
    }
}

void list::DeleteLargest(){

node *temp = head;
node *prev  = temp;
node *largest = temp;
node *prevlargest = 0;

temp = temp->next;

if(head == NULL ) {

    cout << "List is empty\n";

}

else if(head->next == NULL) {

    delete temp;
    
}

else {


    while (temp != NULL) {

        if(temp->data > largest->data){
            prevlargest = prev;
            largest = temp;
        }
        prev = temp;
        temp = temp->next; 
    }

}

if(largest == head){

    head = head->next;

}

else{

    prevlargest->next = largest->next;

}

delete largest;

}