#include<iostream>
using namespace std;

class node
{
public:
    bool bin;
    node *pre;
    node *next;

    node()
    {
        bin=0;
        pre=NULL;
        next=NULL;
    }
    node(bool a)
    {
        bin=a;
        pre=NULL;
        next=NULL;
    }


};

class DLL
{
    public:
    node *head;
    node *rear;
    int bcount;
	DLL()
	{
		head=NULL;
		rear=NULL;
	}
    void create();
    void show();
    void onec();
    void twoc();
    void add(DLL,DLL);
    void addbit(bool);


};


void DLL::create()
{
    int num,i,temp=1;
    cout<<"enter number\n";
    cin>>num;
    node *p,*q;
	if(num>=0)
  {	
    head=new node(num%2);
    num=num/2;
    p=head;
   
 
    while(num>0)
    {
        p->next=new node(num%2);
        num=num/2;
        p->next->pre=p;
        p=p->next;
    }

    rear=p;
    show();
  }
  bcount=1;
  if(num<0)
  {
	num=(-num);
    head=new node(num%2);
    num=num/2;
    p=head;
   
 
    while(temp!=8)
    {
        p->next=new node(num%2);
        num=num/2;
        p->next->pre=p;
        p=p->next;
        temp++;
    }
        
    rear=p;
	twoc();
  }
	

}

void DLL::onec()
{
    
    node *p=head;

    while(p!=NULL)
    {
        if(p->bin==0)
        {
            p->bin=1;
        }
        else
        {
            p->bin=0;
        }

        p=p->next;
    }


}

void DLL::twoc()
{
    onec();
    bool carry=1;
    node *p=head;

    while(p!=NULL)
    {
        if(carry==1 && p->bin==1)
        {
            p->bin=0;
            carry=1;
        }
        else if(carry==1 && p->bin==0)
        {
            p->bin=1;
            carry=0;
        }
        else if(carry==0)
        {
            break;
        }
        p=p->next;
    }
    show();

}

void DLL::add(DLL d1,DLL d2)
{
    bool carry=0;
	head=rear=NULL;
    node *p=d1.rear,*q=d2.rear,*r;
    
    p=d1.head;q=d2.head ;
while(p!=NULL && q!=NULL)
 {
    r=new node(p->bin^q->bin^carry);
    
    if(head==NULL)
    {
        head=r;
        rear=r;

    }

    else
    {
      rear->next=r;
      r->pre=rear;
      rear=r;
	  

    }

    carry=(p->bin && q->bin)  || (q->bin && carry) || (carry && p->bin);
    p=p->next;
    q=q->next;
   

 }
	while(p!=NULL)
	{
		r=new node(p->bin^carry);	

	  rear->next=r;
      r->pre=rear;
      rear=r;
	  carry=(carry && p->bin);
      p=p->next;
	}
	while(q!=NULL)
	{
		r=new node(q->bin^carry);	

	  rear->next=r;
      r->pre=rear;
      rear=r;
	  carry=(carry && q->bin);
      q=q->next;
	}
	if(carry==1)
	{
		r=new node(carry);
		rear->next=r;
        r->pre=rear;
        rear=r;		
	}

}
void DLL::addbit(bool a)
{

    node *p,*q;
    if(head==NULL)
    {
        head=new node(a);
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=new node(a);
        p->next->pre=p;
        p=p->next;

    }
    rear=p;
}

void DLL::show()
{
   node *p=rear;

   while(p!=NULL)
   {
       cout<<p->bin;
       p=p->pre;
   }

}


int main()
{
    DLL s,k,ans;
    int n;

    do
    {
        cout<<"\n1:create\n2:show\n3:1's complement\n4:2's complement\n5:get 2nd no.\n6:add two binary\n7:exit\n";
        cin>>n;
        switch(n)
        {
        case 1:s.create();
            break;
        case 2:s.show();
            break;
        case 3:s.onec();
            break;
        case 4:s.twoc();
            break;
        case 5:k.create();
              // k.show();
            break;
        case 6:ans.add(s,k);
               ans.show();
            break;
        case 7:n=0;

        }
    }while(n);
}
