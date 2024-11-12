

#include<iostream>
using namespace std;

// Comment 1: Defining a structure for a singly linked list node.
struct LinkedList
{
    int value;
    LinkedList* next;
};

// Comment 2: Declaring a pointer to a LinkedList to create new nodes.
struct LinkedList* newnode;

void append_node(LinkedList** first, LinkedList** last)
{
    newnode = new LinkedList();
    cout << "Enter a number : ";
    cin >> newnode->value;
    newnode->next = NULL;

    // Comment 3: Checking if the linked list is empty.
    if (*first == NULL)
    {
        *first = newnode;
        *last = newnode;
    }
    else
    {
        (*last)->next = newnode;
        *last = newnode;
    }
}

// Comment 4: Insterting new nodes in ascending order based on the value of the node
void insert_node(LinkedList** first)
{
    int val;
    newnode = new LinkedList();
    LinkedList* t, * old = nullptr;
    cout << endl << "Enter a number for a new node to insert to the linked list : ";
    cin >> val;
    newnode->value = val;
    newnode->next = nullptr;
    t = *first;

    // Comment 5: Going through the linked list to find the right place to put the node
    while (t != nullptr)
    {
        if (t->value >= val)
        {
            if (old == nullptr)
            {
                newnode->next = t;
                *first = newnode;
            }
            else
            {
                newnode->next = t;
                old->next = newnode;
            }
            break;
        }
        else
        {
            old = t;
            t = t->next;
        }
    }
}

void delete_node(LinkedList** first)
{
    int no;
    cout << endl << "Enter the number of the node that you want to delete from the linked list : ";
    cin >> no;
    LinkedList* tem, * old = nullptr;
    tem = *first;

    // Comment 6: Finding the specified node and deleting it 
    while (tem != nullptr)
    {
        if (tem->value == no)
        {
            if (old == nullptr)
            {
                *first = tem->next;
            }
            else
            {
                old->next = tem->next;
            }
            delete tem;
            break;
        }
        else
        {
            old = tem;
            tem = tem->next;
        }
    }
}

// Comment 7: Displaying the values of the linked list nodes.
void display_node(LinkedList** first)
{
    LinkedList* tem;
    tem = *first;
    while (tem != nullptr)
    {
        cout << tem->value << endl;
        tem = tem->next;
    }
}

// Comment 8: Searching for a node with a specific value in the linked list.
void search_node(LinkedList** first)
{
    int no, c = 0, d = 0;
    cout << endl << "Enter the number that you want to search for in the list : ";
    cin >> no;
    LinkedList* tem = *first;

    while (tem != nullptr)
    {
        if (tem->value == no)
        {
            d = 1;
            break;
        }
        else
        {
            tem = tem->next;
            c++;
        }
    }
    cout << endl << "Number found at index " << c << " in the linked list";
    if (d == 0)
    {
        cout << endl << "Number is not found in the linked list";
    }
}

// Comment 9: Destroying the entire linked list for memory
void destroy_list(LinkedList** first)
{
    LinkedList* tem;
    tem = *first;
    while (tem != nullptr)
    {
        LinkedList* nextNode = tem->next;
        delete tem;
        tem = nextNode;
    }
}

int main()
{
    int n = 1, i;
    LinkedList* first = nullptr, * last = nullptr;

    // Comment 10: Initializing the linked list with the users number of nodes.
    while (n > 0)
    {
        cout << "Enter the number of initial nodes ( must be at least 1) : ";
        cin >> n;

        if (n > 0)
        {
            cout << endl;
            for (i = 1; i <= n; i++)
            {
                append_node(&first, &last);
            }
            break;
        }
        else
        {
            n = 1;
        }
    }

    cout << endl << "Here the initial values in the linked list : " << endl;
    display_node(&first);
    insert_node(&first);
    cout << endl << "Here is the updated linked list :" << endl;
    display_node(&first);
    delete_node(&first);
    cout << endl << "Here is the updated linked list :" << endl;
    display_node(&first);
    search_node(&first);
    destroy_list(&first);

    return 0;
}
