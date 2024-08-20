#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct node
{
    int info;
    struct node *next;
}

struct node *pfrist = NULL, *pnew, *pthis, *ptemp;
int count = 0;

void create()
{
    pnew = (struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"entre data: ";
    cin>>data;
    pnew->info = data;
    pnew->next = NULL;
    count++;
}

void delete_from_sp_position(int pos)
{
    if(pos<1||pos>count)
    {
        cout<<"invalid";
    }
    else if(pos ==1)
    {
        if(pfirst == NULL)
        {
            cout<<"list is empty";

        }
        else{
            ptemp = pfirst;
            pfirst = pfirst->next;
            free(ptemp);
            count--;
        }
    }
    else if(pos == count)
    {
       
        if(pfirst == NULL)
        {
            cout<<"list is empty";

        } 
        else if(pfirst->next == NULL)
        {
            free(pfirst);
            pfirst = NULL;
            count--;
        }
        else
        {
            pthis = pfirst;
            while(pthis->next->next!=NULL)
            {
                pthis=pthis->next;

            }
            ptemp=pthis->next;
            pthis->next=NULL;
            free(ptemp);
            count--;
        }
        else{
            pthis = pfirst;
            for(int i=0; i<pos-2;i++)
            {
                pthis=pthis->next;
                ptemp = pthis->next;
                pthis->next=ptemp->next;
                free(ptemp);
                count--;
            }
        }
    }
}

void display()
{
    if(pfirst == NULL)
    {
        cout<<"empty list";
    }
    else{
        pthis = pfirst;
        cout<<"list: ";
        while(pthis != NULL)
        {
            cout<<pthis->info<<endl;
            pthis = pthis->next;
        }
        cout<<endl;
    }
}

void insert_at_sp_pos()
{
    int loc;
    cout<<"entre location: ";
    cin>>loc;
    if(loc == count)
    {
        create();
        if(pfirst==NULL)
        {
            pfirst = pnew;
            else
            {
                pthis=pfirst;
                while(pthis->next!=NULL)
                {
                    pthis=pthis->next;

                }
                pthis->next = pnew;
            }
        }

    }
    else
    {
        create();
        pthis = pfirst;
        for(int i = 0; i<loc-1; i++)
        {
            pthis=pthis->next;
            pnew->next=pthis->next;
            pthis->next=pnew;
        }
    }
}

int main()
{
    int option, pos;
    char ch;

    do
    {
        cout<<"entre option: "<<endl;
        cout<<"1. "
    } while ({
        
    });
    

}