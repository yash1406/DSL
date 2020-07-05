#include<iostream>


using namespace std;

class node
{
public:
    int coef;
    int pow;
    node *next;
    node(int a,int b)
    {
        coef=a;
        pow=b;
        next=NULL;
    }


};

class CLL
{
public:
    node *head;
    int n;

    CLL()
    {
        head=NULL;
    }
    void create();
    void show();
    void evaluate(int);
    void add(CLL,CLL);
};

void CLL::create()
{
    node *p;
    int deg,coe,i;
    cout<<"enter no. of terms of polynomial\n";
    cin>>n;
    cout<<"enter coefficient of term\n";
    cin>>coe;
    cout<<"enter degree of term\n";
    cin>>deg;
    head=new node(coe,deg);
    p=head;

    for(i=1;i<n;i++)
    {
        cout<<"enter coefficient of term\n";
        cin>>coe;
        hi:
        cout<<"enter degree of term\n";
        cin>>deg;
        if(deg<=p->pow)
        {
            cout<<"inavlid re-enter\n";
            goto hi;
        }
        p->next=new node(coe,deg);
        p=p->next;


    }
    p->next=head;


}

void CLL::show()
{
    node *p=head;
    do
    {
        cout<<p->coef<<"x^"<<p->pow;
        if(p->next!=head)
        {
            cout<<"+";
        }
        p=p->next;

    }while(p!=head);
}
void CLL::evaluate(int num)
{
    node *p=head;

    int ans=0,temp=1,i;


    do
    {
        temp=1;
        i=p->pow;
        while(i)
        {
            temp=temp*num;
            i--;

        }

        ans=ans+(p->coef*temp);

        p=p->next;

    }while(p!=head);
    cout<<"ans="<<ans;
}


void CLL::add(CLL p1,CLL p2)
{
    node *p=p1.head,*q=p2.head,*r;
    int i=1,j=1;

if(p!=NULL && q!=NULL)
  {

    if(p->pow < q->pow)
    {
        head=new node(p->coef,p->pow);
        p=p->next;
        i++;


    }
    else if(p->pow > q->pow)
    {
        head=new node(q->coef,q->pow);
        q=q->next;
        j++;
    }
    else
    {
        head=new node(p->coef+q->coef,p->pow);
        p=p->next;
        q=q->next;
        i++;
        j++;

    }

    r=head;

    while(i<=p1.n && j<=p2.n)
    {
        if(p->pow < q->pow)
        {
            r->next=new node(p->coef,p->pow);
            p=p->next;
            i++;

            r=r->next;


        }

        else if(p->pow > q->pow)
        {
            r->next=new node(q->coef,q->pow);
            q=q->next;
            j++;

            r=r->next;

        }

        else
        {

            r->next=new node(p->coef+q->coef,p->pow);
            p=p->next;
            q=q->next;
            i++;
            j++;

            r=r->next;

        }

   }

    while(i<=p1.n)
    {
        r->next=new node(p->coef,p->pow);
        p=p->next;
        i++;

        r=r->next;


    }

    while(j<=p2.n)
    {
        r->next=new node(q->coef,q->pow);
        q=q->next;
        j++;

        r=r->next;

    }

    r->next=head;
 }

}

int main()
{
    CLL p1,p2,p3;
    int ch,n1;
    do
    {
        cout<<"\n1:create\n2:show\n3:evaluate\n4:add\n5:exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:cout<<"enter 1st polynomial in increasing order\n";
               p1.create();
               cout<<"enter 2st polynomial in increasing order\n";
               p2.create();
               break;

        case 2:p1.show();
               cout<<endl;
               p2.show();
               break;
        case 3:cout<<"enter no. to evaluate\n";
               cin>>n1;
               p1.evaluate(n1);
               cout<<endl;
               p2.evaluate(n1);
               break;
        case 4:p3.add(p1,p2);
            if(p3.head!=NULL)
            {
               p3.show();
            }
               break;

        case 5:ch=0;




        }
    }while(ch);
}






