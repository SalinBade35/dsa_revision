#include<stdlib.h>
#include<iostream>
#define max 10

using namespace std;

int main()
{
    int rear = -1, front = -1, n, queue[max], data;
    string ch;
do
    {
        
        cout<<"entre option: ";
        cout<<"\n1. enqueue\n2. dequeue\n3. display\n4. exit\n";
        cin>>n;

        switch (n)
        {
        case 1:
        {
            if(front == (rear + 1)%max)
            {
                cout<<"queue is full";
            }
            else{
                cout<<"entre data: ";
                cin>>data;
                rear = (rear+1)%max;
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
            else if(front == rear)
            {
                cout<<queue[front]<<"is deleted";
                // resetting the space
                cout<<"queue is now reset";
                front = -1;
                rear = -1;
            }
            else{
                data  = queue[front];
                cout<<data<<" is deleted\n";
                front = (front+1)%max;

            }
            break;
        }

        case 3:
        {
            if(front == -1)
            {
                cout<<"queue is empty\n";
            }
            else
            {
                cout << "Queue elements are: ";
                int i = front;
                while (i != rear)
                {
                    cout << queue[i] << " ";
                    i = (i + 1) % max;
                }
                cout << queue[i] << "\n"; // Display the last element
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
    
}