#include<iostream>

using namespace std;
#define MAX 20

class Job
{
public:
    int id;
    int n;
};

class Queue
{

    Job arr[MAX];
    int rear,front;
public:
    Queue()
    {
        rear=front=-1;
    }

    void enque(Job);
    Job deque();
    int full();
    int empty();
    void print();


};

void Queue::enque(Job temp)
{
    int i;

    if(!full())
    {
        if(empty())
        {
            rear=front=0;
            arr[0]=temp;

        }

        else
        {
            /*i=rear;

            while(i>=front && arr[i].n>temp.n )
            {
                arr[i+1]=arr[i];
                i--;
            }*/
            rear++;
            arr[rear]=temp;

        }
    }

    else
    {
        cout<<"queue is full\n";
    }
}

Job Queue::deque()
{
    Job var=arr[0],temp;
    int i,ind=0,min;
    if(!empty())
    {

        if(front==rear)
        {

            var=arr[front];

            cout<<var.id<<"\t"<<var.n<<endl;
            front=rear=-1;

        }

        else
        {
            min=arr[0].n;
            for(i=front;i<=rear;i++)
            {
                if(min>arr[i].n)
                {
                    min=arr[i].n;
                    var=arr[i];
                    ind=i;

                }
            }

            while(ind)
            {
                arr[ind]=arr[ind-1];
                ind--;
            }
            cout<<var.id<<"\t"<<var.n<<endl;
            front++;

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

void Queue::print()
{
    int i;
    cout<<"ID\tPriority\n";

    if(!empty())
    {
        for(i=front;i<=rear;i++)
        {
            cout<<arr[i].id<<"\t"<<arr[i].n<<endl;

        }

    }
}

int main()
{
    int ch;
    Job ob,ob1;
    Queue obj;

    do
    {
        cout<<"\n1:Add\n2:Delete\n3:Print\n4:Exit\n";
        cin>>ch;

        switch(ch)
        {
        case 1:cout<<"enter Job id and priority\n";
               cin>>ob.id>>ob.n;
               obj.enque(ob);
            break;
        case 2:ob1=obj.deque();
            break;
        case 3:obj.print();
            break;
        case 4:ch=0;


        }




    }while(ch);
}




















