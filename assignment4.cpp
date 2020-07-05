#include<iostream>

using namespace std;

class node
{
public:
    int prn;
    string name;
    node *next;

    node()
    {
        prn=0;
        name="xyz";
        next=NULL;
    }
    node(int a,string b)
    {
        prn=a;
        name=b;

    }


};

class SLL
{
    public:
    node *president;
    node *secretary;


    SLL()
    {
        president=NULL;
        secretary=NULL;

    }
    void create();
    void show();
    int count();
    void add();
    void show_rec(node*);
    void display()
    {
        cout<<"PRN"<<"\t"<<"NAME"<<endl<<"--------------------------"<<endl;
        show_rec(president);
    }

    int delete1(int);
    void concat(SLL,SLL);
    void insertatbeg();
    void insertatend();
    void sort1();


};



void SLL::create()
{
    node *p;
    int n,x,i;
    string var;
    cout<<"enter no. of nodes\n";
    cin>>n;

    cout<<"enter PRN and name of president\n";
     cin.ignore();
    cin>>x;
    getline(cin,var);
    president=new node (x,var);
    p=president;

    for(i=1;i<n;i++)
    {

        cout<<"enter PRN and name\n";
        cin>>x;
       // cin.ignore();
        getline(cin,var);
        p->next=new node (x,var);
        p=p->next;


    }
    secretary=p;




}
void SLL::insertatbeg()
{
    node *p,*q;
    int x;
    string var;
    cout<<"enter PRN\t";
    cin>>x;
    cout<<"enter name\t";
     cin.ignore();
    getline(cin,var);
    p=new node (x,var);
    if(president==NULL)
    {
        president=p;
        secretary=p;
        return;
    }
    p->next=president;
    president=p;
}

void SLL::insertatend()
{
    node *p,*q;
    int x;
    string var;
    cout<<"enter PRN\t";
    cin>>x;
    cout<<"enter name\t";
     cin.ignore();
    getline(cin,var);
    p=new node (x,var);
    if(president==NULL)
    {
        president=p;
        secretary=p;
        return;
    }

    else
    {
         q=president;


            while(q->next!=NULL)
            {
                q=q->next;
            }

            q->next=p;
            secretary=p;


    }

}

void SLL::add()
{
    node *p,*q;
    int x;
    string var;
    cout<<"enter PRN\t";
    cin>>x;
    cout<<"enter name\t";
     cin.ignore();
    getline(cin,var);
    p=new node (x,var);
    if(president==NULL)
    {
        president=p;
     //   secretary=p;
        return;
    }

    else if(president->next==NULL)
    {

        president->next=p;
       // secretary=p;
        return;
    }

    else
    {
         q=president;


            while(q->next!=secretary)
            {
                q=q->next;
            }
            p->next=secretary;
            q->next=p;
            //secretary=p;




    }

}

void SLL::show()
{
    node *p;
    p=president;
    if(president!=NULL)
 {
   cout<<"PRN"<<"\t"<<"NAME"<<endl<<"--------------------------"<<endl;
    int i;
    while(p!=NULL)
    {
        cout<<p->prn<<"\t";
        cout<<p->name;
        cout<<endl;
        p=p->next;


    }
}
    else
    {
        cout<<"empty list\n";
    }

}

void SLL::show_rec(node *p)
{

    if(p!=NULL)
    {
        show_rec(p->next);
        cout<<p->prn<<"\t"<<p->name;
        cout<<endl;
    }

}

int SLL::count()
{
    int x=0;

    node *p=president;
    while(p!=NULL)
    {
        x++;
        p=p->next;

    }


    return x;
}


int SLL::delete1(int x)
{
    node *p=president,*q;
    int flag=0;
    if(president==NULL)
    {
        cout<<"List is empty\n";
        return -1;
    }

    else if(president->prn==x)
    {
        president=president->next;
        delete p;
        return x;
    }

    else
    {
        while(p!=NULL && p->prn!=x)
        {
            q=p;
            p=p->next;
        }

        if(p!=NULL)
        {
            q->next=p->next;

          if(p==secretary)
          {
            secretary=q;
          }
            delete p;

            return x;
        }

        if(p==NULL)
        {
            cout<<"No such member\n";
            return -1;

        }

    }

}

void SLL::concat(SLL d1, SLL d2)
{
   if(d1.president!=NULL)
{

    int temp;
    node*p=d1.president,*q=d2.president,*r;
    president=new node(p->prn,p->name);
    r=president;
    p=p->next;
   while(p!=NULL)
   {
       r->next=new node(p->prn,p->name);
       r=r->next;
       p=p->next;

   }

   while(q!=NULL)
   {
       r->next=new node(q->prn,q->name);
       r=r->next;
       q=q->next;
   }



}
   else
   {
       cout<<"empty list\n";
   }




}

void SLL::sort1()
{
    node *p=president,*q;
    int temp;
    if(president!=NULL)
    {

    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->prn>q->prn)
            {
               temp=p->prn;
               p->prn=q->prn;
               q->prn=temp;
            }
            q=q->next;
        }
        p=p->next;
    }

   }
    else
    {
        cout<<"empty list\n";
    }


}




int main()
{
    SLL s,w,sort;
    int cnt,a,b,c,d;
    cout<<"\nENTER LIST 1\n";


    do
    {
        cout<<"1:Add member\n2:Show\n3:Count\n4:Display in reverse order\n5:Delete\n6:Get 2nd list\n7:Concat 2 lists\n8:Insert President\n9:Insert secretary\n10:Sort 2 lists\n11:Exit\n";
        cin>>a;
        switch(a)
        {
        case 1:s.add();
            break;

        case 2:s.show();
            break;

        case 3:cnt=s.count();
            cout<<"count="<<cnt<<endl;
            break;

        case 4:s.display();
            break;


        case 5:cout<<"enter PRN to delete\n";
              cin>>b;
              b=s.delete1(b);
              cout<<"PRN no. "<<b<<" is deleted\n";
            break;

        case 6:

                cout<<"ENTER LIST 2\n";

           do
            {
                cout<<"1:Add member\n2:show\n3:count\n4:exit\n";
                cin>>d;
                switch(d)
                {
                case 1:w.add();
                    break;
                case 2:w.show();
                    break;
                case 3:w.count();
                    break;
                case 4:d=0;
                }

            }while(d);
            break;

        case 7:sort.concat(s,w);
               sort.show();
            break;
        case 8:s.insertatbeg();
            break;
        case 9:s.insertatend();
            break;
        case 10:sort.sort1();
                sort.show();
            break;
        case 11:a=0;



        }

    }while(a);


}




