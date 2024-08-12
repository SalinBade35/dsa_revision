#include<stdlib.h>
#include<iostream>
#define max 10

using namespace std;

int n, rear = -1, front = -1, data;

int queue[max];
string ch;

int main()
{
    do
    {
        
        cout<<"entre option: ";
        cout<<"\n1. enqueue\n2. dequeue\n3. display\n4. exit\n";
        cin>>n;

        switch (n)
        {
        case 1:
        {
            if(rear == max - 1)
            {
                cout<<"queue is full";
            }
            else{
                cout<<"entre data: ";
                cin>>data;
                rear += 1;
                if (front == -1)
                {
                    front = 0;
                }
                queue[rear] = data;
            }
            break;
        }
        
        case 2:
        {
            if(front == -1)
            {
                cout<<"queue is empty";
            }
            if(front > rear)
            {
                // resetting the space
                front = -1;
                rear = -1;
                cout<<"queue is now reset";
            }
            else{
                data  = queue[front];
                cout<<data<<" is deleted\n";
                front += 1;

            }
            break;
        }

        case 3:
        {
            if(front == -1 || front > rear)
            {
                cout<<"queue is empty\n";
            }
            else
            {
                for(int j = front; j<= rear; j++)
                {
                    cout<<queue[j]<<endl;
                }
            }
            break;
        }
        
        case 4:
        exit(1);

        default:
        cout<<"invalid";

        }
        cout<<"\nDo you want to resume?\n";
        cin>>ch;

   } while(ch == "y" || ch == "Y" || ch == "yes" || ch == "Yes" || ch == "YES");
        
};
    
