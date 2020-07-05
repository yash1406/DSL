#include<iostream>
#define MAX 5

using namespace std;

class Queue
{

    int arr[MAX];
    int rear,front;
public:
    Queue()
    {
        rear=front=-1;
    }

    void enqueR(int);
    void enqueF(int);
    int dequeF();
    int dequeR();
    int full();
    int empty();
    void print();


};

void Queue::enqueR(int temp)
{
    int i;

    if(!full())
    {
        if(empty())
        {
            rear=front=0;
            arr[rear]=temp;

        }

        else
        {

            rear++;
            arr[rear]=temp;

        }
    }

    else
    {
        cout<<"queue is full\n";
    }
}


int Queue::dequeF()
{

    int i,var;
    if(!empty())
    {

        if(front==rear)
        {

            var=arr[front];
            cout<<var<<endl;
            front=rear=-1;

        }

        else
        {
            var=arr[front];
            front++;
            cout<<var<<endl;
        }
        return var;
    }

    else
    {
        cout<<"queue is empty\n";
    }
}



int Queue::full()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    return 0;
}


int Queue::empty()
{
    if(rear==-1)
    {
        return 1;
    }
    return 0;
}

void Queue::enqueF(int temp)
{
   if(front!=0)
   {
       if(empty())
       {
           rear=front=0;
           arr[front]=temp;

       }
       else
       {
           front--;
           arr[front]=temp;

       }
   }
   else
   {
       cout<<"queue is full\n";
   }
}

int Queue::dequeR()
{
    int i,var;
    if(!empty())
    {

        if(front==rear)
        {

            var=arr[rear];
            cout<<var<<endl;
            front=rear=-1;

        }

        else
        {
            var=arr[rear];
            rear--;
            cout<<var<<endl;
        }
        return var;
    }

    else
    {
        cout<<"queue is empty\n";
    }
}

void Queue::print()
{
    int i;


    if(!empty())
    {
        for(i=front;i<=rear;i++)
        {
            cout<<arr[i]<<"\t";

        }

    }
}
int main()
{
    int ch,ob,ob1;

    Queue obj;

    do
    {
        cout<<"\n1:Add from Rear\n2:Add from Front\n3:Delete from Rear\n4:Delete from Front\n5:Print\n6:Exit\n";
        cin>>ch;

        switch(ch)
        {
        case 1:cout<<"enter number\n";
               cin>>ob;
               obj.enqueR(ob);
            break;
        case 2:cout<<"enter number\n";
               cin>>ob;
               obj.enqueF(ob);
            break;
        case 3:ob1=obj.dequeR();
            break;
        case 4:ob1=obj.dequeF();
            break;
        case 5:obj.print();
            break;
        case 6:ch=0;


        }




    }while(ch);
}
