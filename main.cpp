#include <iostream>

using namespace std;

template <typename type>
class Node
{
public:
    type value;
    Node * next;
    Node * prev;
};

template <typename type>
class List
{
private:
    Node <type> * head;
    Node <type> * tail;
    int Sizee;
    bool flag=0;
public:

    class myiterator
    {
    public:
        Node <type> * point;
        myiterator()
        {
            point=NULL;
        }
        myiterator(Node<type> * itNode)
        {
            point =itNode;
        }

        //get next node
        void operator ++ (int)
        {
            if(point->next!=NULL)
                point=point->next;
            else
                cout<<"\nOut of Range\n";
        }

        //get previous node
        void operator -- (int)
        {
            if(point->prev!=NULL)
                point=point->prev;
            else
                cout<<"\nOut of Range\n";
        }
        type& operator*() const
        {
            return point->value;
        }
    };

    // Default Constructor
    List()
    {
        head=NULL;
        tail=NULL;
        Sizee=0;
    }

    // Parametrized Constructor
    List(type value, int initial_size)
    {
        while(initial_size<1)
        {
            cout<<"wrong size \nEnter correct size more than 0 : ";
            cin>>initial_size;
        }
        Node <type> * start=new Node<type>();
        start->next=NULL;
        start->prev=NULL;
        start->value=value;
        head = start;
        Node <type> * current = new Node<type>() ;
        current=start;
        for(int i = 1 ; i < initial_size ; i++)
        {
            Node <type> * newNode = new Node <type>();
            newNode->prev=current;
            newNode->next=NULL;
            newNode->value=value;
            current->next=newNode;
            current=current->next;
        }
        tail=current;
        Sizee=initial_size;
    }

    // Get Size of list
    int size()
    {
        return Sizee;
    }

    // Copy using = operator
    List<type>& operator = (List<type> another_list)
    {
        if(this == &another_list)
        {
            return * this;
        }
        else
        {
            int ind=0;
            type val;
            Node <type> * current = new Node <type> ();
            current=another_list.head;
            while(another_list.Sizee>ind)
            {
                ind++;
                this->push_back(current->value);
                if(ind!=another_list.Sizee)
                    current = current->next;
            }
            Sizee=another_list.size();
            another_list.flag=1;
            return * this;
        }
    }

    //Destructor
    ~List()
    {
        if(flag==0)
        {
            myiterator itr= this->begin();
            while(tail!=head)
            {
                itr=erase(itr);
            }
            delete head;
            delete tail;
        }
        else
            flag=0;
    }

    //
    void insert(type value, myiterator position)
    {
        Node <type> * newnode = new Node <type> ();
        newnode->value = value;
        Sizee++;
        if(position.point==head)
        {
            newnode->prev=NULL;
            position.point->prev=newnode;
            newnode->next=position.point;
            head=newnode;
        }
        else
        {
            newnode->prev=position.point->prev;
            position.point->prev=newnode;
            newnode->next=position.point;
            newnode->prev->next=newnode;
        }
    }

    //
    myiterator erase(myiterator position)
    {
        Node <type> * newnode = new Node <type> ();
        Sizee--;
        if(position.point==head)
        {
            newnode=position.point;
            head=position.point->next;
            position.point=position.point->next;
            if(position.point!=NULL)
                position.point->prev=NULL;
            newnode=NULL;
            delete newnode;
            return position;
        }
        else if(position.point == tail)
        {
            newnode=position.point;
            tail=position.point->prev;
            position.point=position.point->prev;
            position.point->next=NULL;
            newnode=NULL;
            delete newnode;
            return position;
        }
        else
        {
            newnode=position.point;
            position.point=position.point->next;
            position.point->prev=newnode->prev;
            newnode->prev->next=newnode->next;
            newnode=NULL;
            delete newnode;
            return position;
        }
    }

    //to print list
    void print()
    {
        Node <type> * Current = head;
        if(head==NULL)
        {
            cout<<"No data to show\n";

        }
        else
        {
            for(int w=0 ; w < Sizee ; w++)
            {
                cout<<Current->value<<" / ";
                Current=Current->next;
            }
            cout<<"\n";
        }
    }

    myiterator begin()
    {
        return myiterator(head);
    }
    myiterator end()
    {
        return myiterator(tail);
    }
    void push_back(type val)
    {
        if(head!=NULL)
        {

            Node <type> * newNode = new Node <type>();
            newNode->value=val;
            newNode->prev=tail;
            newNode->next=NULL;
            tail->next=newNode;
            tail=tail->next;
            Sizee++;
        }
        else
        {
            Node <type> * newNode = new Node <type>();
            newNode->value=val;
            newNode->prev=NULL;
            newNode->next=NULL;
            tail=newNode;
            head=newNode;
            Sizee++;
        }
    }
};




int main()
{
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    cout<<"List 0 : ";
    myList.print();
    List<int>:: myiterator it = myList.begin();
    it++;
    cout<<"iterator :";
    cout<< *it<<endl;
    List <int> list1(3,2);
    List<int>::myiterator myit  = list1.begin();
    cout<<"List 1: ";
    list1.print();
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(9);
    cout<<"After Push back in List 1: ";
    list1.print();
    List <int> list2;
    list2=list1;
    cout<<"Use = operator to assign List 2: ";
    list2.print();
    List<int>::myiterator myit1  = list2.begin();
    cout<<"List 2: head = "<<*myit1<<endl<<"insert 4 at head\n";
    list2.insert(4,myit1);
    cout<<"List 2: ";
    list2.print();
    cout<<"Size List 2: " <<list2.size()<<endl;
    myit1--;
    cout<<"erase head\n";
    list2.erase(myit1);
    cout<<"List 2: ";
    list2.print();
    myit1=list2.end();
    cout<<"List 2: tail = "<<*myit1<<endl;
    myit1--;
    cout<<"List 2: previous tail = "<<*myit1<<endl;
    return 0;
}
