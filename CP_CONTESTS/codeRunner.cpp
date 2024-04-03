#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void traversal()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void InsertAtBeginning(int x)
    {
        Node *ptr = new Node(x);

        ptr->next = head;
        head = ptr;
    }

    void InsertAtEnd(int x)
    {
        Node *ptr = new Node(x);

        Node *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        ptr->next = NULL;
        p->next = ptr;
    }

    void InsertAtIndex(int pos, int x)
    {
        Node *ptr = new Node(x);

        Node *p = head;
        int i = 0;

        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
    }

    void deleteHead()
    {
        Node *ptr = head;
        head = head->next;
        free(ptr);
    }

    void deleteAtIndex(int index)
    {
        Node *p = head;
        Node *q = head->next;
        
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }

        p->next = q->next;
        free(q);
    }

    void deleteLast()
    {
        Node *p = head;
        Node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
    }
    void deleteValue(int data)
    {
        Node *p = head; //prev node
        Node *q = head->next; //curr node

        while (q->data != data && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        if (q->data == data)
        {
            p->next = q->next;
            free(q);
        }
    }

    void reverse()
    {
        Node *p = head, *prev = NULL, *ptr = NULL;

        while (p != NULL)
        {
            ptr = p->next;
            p->next = prev;

            prev = p;
            p = ptr;
        }
        head = prev;
    }

};

int main()
{
    LinkedList *ll = new LinkedList();


    int cont;
    do
    {
        cout << "1 - Display Data \n2 - Insert Data \n3 - Delete Data \n4 - Reverse List";

        int x;
        cout << "Enter your choice : ";
        cin >> x;
        if (x == 1)
        {
            ll->traversal();
        }
        else if (x == 2)
        {
            cout << "1 - Insert At Beginning \n2 - Insert At End \n3 - Insert At Index\n";
            int y;
            int data;

            cin >> y;

            if (y == 1)
            {
                cout << "Enter Data : ";
                cin >> data;
                ll->InsertAtBeginning(data);
            }
            else if (y == 2)
            {
                cout << "Enter Data : ";
                cin >> data;
                ll->InsertAtEnd(data);
            }
            else if (y == 3)
            {
                cout << "Enter Data : ";
                cin >> data;
                cout << "Enter Index : ";
                int pos;
                cin >> pos;
                if(pos>=ll->size-1){
                    ll->InsertAtEnd(data);
                }
                else if(pos<=0){
                    ll->InsertAtBeginning(data);
                }
                else{
                    ll->InsertAtIndex(data, pos);
                }
            }
            ll->size++;
        }
        else if (x == 3)
        {
            cout << "1 - Delete Head \n2 - Delete From Last \n3 - Delete Index \n4 - Delete value";
            int y;
            int data;

            cin >> y;

            if (y == 1)
            {
                ll->deleteHead();
            }
            else if (y == 2)
            {
                ll->deleteLast();
            }
            else if (y == 3)
            {
                cout << "Enter Data : ";
                cin >> data;
                ll->deleteValue(data);
            }
            else if (y == 4)
            {
                cout << "Enter Index : ";
                cin >> data;
                ll->deleteAtIndex(data);
            }
            ll->size--;
        }
        else if (x == 4)
        {
            ll->reverse();
        }
        cout << "Press 1 to continue : ";
        cin >> cont;

    } while (cont == 1);

    return 0;
}