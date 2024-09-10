#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *pfirst = NULL, *pnew, *pthis, *ptemp;
int count = 0;

void create(int data)
{
    pnew = new node(); // Using new instead of malloc
    pnew->info = data;
    pnew->next = NULL;
    count++;
}

void delete_from_sp_position(int pos)
{
    if(pos < 1 || pos > count)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pfirst == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(pos == 1)
    {
        ptemp = pfirst;
        pfirst = pfirst->next;
        delete ptemp; // Using delete instead of free
        count--;
    }
    else
    {
        pthis = pfirst;
        for(int i = 1; i < pos - 1; i++) 
        {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = ptemp->next;
        delete ptemp;
        count--;
    }
}

void delete_from_end()
{
    delete_from_sp_position(count); // Reusing the specific position deletion logic
}

void display()
{
    if(pfirst == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    pthis = pfirst;
    cout << "List: ";
    while(pthis != NULL)
    {
        cout << pthis->info << " ";
        pthis = pthis->next;
    }
    cout << endl;
}

void insert_at_beg(int data)
{
    create(data);
    if(pfirst == NULL)
    {
        pfirst = pnew;
    }
    else
    {
        pnew->next = pfirst;
        pfirst = pnew;
    }
}

void insert_at_sp_pos(int loc, int data)
{
    if(loc < 1 || loc > count + 1) 
    {
        cout << "Invalid location\n";
        return;
    }

    create(data);
    if(loc == 1)
    {
        insert_at_beg(data);
    }
    else
    {
        pthis = pfirst;
        for(int i = 1; i < loc - 1; i++) 
        {
            pthis = pthis->next;
        }
        pnew->next = pthis->next;
        pthis->next = pnew;
    }
}

void node_count()
{
    cout << "Total nodes: " << count << endl;
}

int main()
{
    int option, pos, data;
    string ch;

    do {
        cout << "1. Insert at Specific Position\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Delete from Specific Position\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Node Count\n";
        cin >> option;

        switch(option)
        {
            case 1:
                cout << "Enter position and data: ";
                cin >> pos >> data;
                insert_at_sp_pos(pos, data);
                break;

            case 2:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                insert_at_beg(data);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                delete_from_sp_position(pos);
                break;

            case 4:
                delete_from_end();
                break;

            case 5:
                display();
                break;

            case 6:
                node_count();
                break;

            default:
                cout << "Invalid option\n";
                break;
        }
        cout << "Do you want to continue? ";
        cin >> ch;
    } while(ch == "yes" || ch == "Yes" || ch == "y" || ch == "Y");
    
    return 0;
}
