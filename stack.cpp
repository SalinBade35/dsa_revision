#include<iostream>
#include<stdlib.h>
#define max 10

using namespace std;

int main()
{
    int top = -1;
    int n, data, stack[max];
    string ch;

   do
   {
    cout<<"select option:\n";
    cout<<"1. Push\n2. Pop\n3. Display\n4. exit\n";
    cin>>n;

    switch(n)
    {
        case 1:
        {
            if(top == max -1) // inorder to push, stack must have some space
            {
                cout<<"stack is full";
            }
            else
            {
                cout<<"entre data: ";
                cin>>data;
                top = top + 1;
                stack[top] = data;
                cout<<stack[top]<<" is pushed";
            }
            break;
        }

        case 2:
        {
            if(top == -1) // inorder to pop, stack must have some data
            {
                cout<<"stack is empty";
            }
            else
            {
                data = stack[top];
                cout<<data<<" is poped";
                top = top - 1;
            }
            break;
        }

        case 3:
        {
            if(top == -1)
            {
                cout<<"stack is empty";
            }
            else
            {
                cout<<"Displaying the data on stack";
                for(int x = 0; x<= top; x++)
                {
                    cout<<" | "<<stack[x];
                }
                cout<<" | ";
            }
            break;
        }

        case 4:
        {
            exit(0);
        }

        default:
            cout<<"Invalid";
    }
    cout<<"\nDo you want to resume?\n";
        cin>>ch;

   } while(ch == "y" || ch == "Y" || ch == "yes" || ch == "Yes" || ch == "YES");

   }
