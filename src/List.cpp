/*#include "List.h"
#include <iostream>

using namespace std;

//Default Constructor
template <typename type>
List <type> ::List()
{
    head=0;
    tail=0;
}

//Parametrized Constructor
template <typename type>
List <type> ::List(int value, int initial_size)
{
    Node <type> * start;
        start->prev=0;
        start->next=0;
        start->value=value;
    head = start;

    Node <type> * current = start;
    for(int i = 0 ; i < initial_size ; i++)
    {
        for(int w = -1 ; w < i ; w++)
        {
            cout << current->value<<" "<<w<<"\n";
        }
        Node <type> * newNode;
            newNode->prev=current;
            newNode->next=0;
            newNode->value=value;
        current=newNode;
    }
}

//Destructor
template <typename type>
List <type> ::~List()
{
    delete head ;
    delete tail ;
}
*/
