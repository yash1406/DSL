#include<iostream>

using namespace std;

#define MAX 30

class Stack
{
    char data[MAX];

    int top;

public:

    Stack()
    {
        top=-1;
    }

    void push(char);
    char pop();
    int full();
    int empty();
    void print();
    void postfix(char post[]);
    int check(char);
    
};

class Stack1
{
    int data[MAX];

    int top;

public:

    Stack1()
    {
        top=-1;
    }
    void push1(int);
    int pop1();
    int full1();
    int empty1();
    void print1();
    void evaluate(char post[]); 
};

int Stack::full()
{
    if(top==MAX-1)
    {
        return 1;
    }
    return 0;
}

int Stack::empty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

void Stack::push(char a)
{
    if(!full())
    {
        top++;
        data[top]=a;
    }
    else
    {
        cout<<"stack is full\n";
    }

}

char Stack::pop()
{
    if(!empty())
    {
        char x;
        x=data[top];
        top--;
        return x;
    }
    else
    {
        cout<<"stack is empty\n";
        return 0;
    }
}

void Stack::print()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<data[i];
    }
}

int Stack1::full1()
{
    if(top==MAX-1)
    {
        return 1;
    }
    return 0;
}

int Stack1::empty1()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

void Stack1::push1(int a)
{
    if(!full1())
    {
        top++;
        data[top]=a;
    }
    else
    {
        cout<<"stack is full\n";
    }

}

int Stack1::pop1()
{
    if(!empty1())
    {
        int x;
        x=data[top];
        top--;
        return x;
    }
    else
    {
        cout<<"stack is empty\n";
        return 0;
    }
}

void Stack1::print1()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<data[i]<<"\t";
    }
}


void Stack::postfix(char post[])
{
    string str;
    int i=0,j=0;
    char c,temp;
    cout<<"enter expression\t";
    //cin.ignore();
    cin>>str;
     
    while(str[i]!='\0')
    {
        if(str[i]>=48 && str[i]<=57)
        {
            post[j]=str[i];
            j++;
	   	
        }
        else
        {
            if(empty())
            {
                push(str[i]);
            }
            else if(str[i]=='(')
            {
		if(i>0 && (str[i-1]>=48 && str[i-1]<=57 ) && (str[i+1]>=48 && str[i]<=57))
		{
			push('*');
		}

                push(str[i]);
            }
            else if(str[i]==')')
            {
                while(data[top]!='(')
                {
                    post[j]=pop();
                    j++;
                }
                temp=pop();

		if(i>0 && (str[i-1]>=48 && str[i-1]<=57 ) && (str[i+1]>=48 && str[i]<=57))
		{
			push('*');
		}
            }
            else if(data[top]=='(')
            {
		
                push(str[i]);
            }
            else if(check(str[i]) > check(data[top]))
            {
                push(str[i]);
            }
            else if(check(str[i]) <= check(data[top]))
            {
                while(!empty() && data[top]!='(' && (check(str[i]) <= check(data[top])))
                {
                    post[j]=pop();
                    j++;

                }

                push(str[i]);



            }

        }
        
        i++;

    }
    while(!empty())
    {
        post[j]=pop();
        j++;
    }
    post[j]='\0';
    cout<<"Postfix Expression:"<<post<<endl;



}

int Stack::check(char a)
{
    switch(a)
    {
    case '+': return 0;
        break;

    case '-': return 0;
        break;

    case '*': return 1;
        break;

    case '/': return 1;
        break;
    

    }

}

void Stack1::evaluate(char post[])
{
    int i=0;
    int ans;

    while(post[i]!='\0')
    {
        if(post[i]>=48 && post[i]<=57)
        {

            push1(post[i]-48);

        }

        else
        {
            int o1=pop1();
            int o2=pop1();
            
		
            switch(post[i])
            {

            case '+': push1(o2+o1);
                break;

            case '-': push1(o2-o1);
                break;

            case '*': push1(o2*o1);
                break;

            case '/': push1(o2/o1);


            }
        }
	 
        i++;
    }

    ans=pop1();

    cout<<"ANSWER="<<ans<<endl;
}


int main()
{
    Stack s;
    Stack1 k;
 
    char post[100];

    s.postfix(post);
    k.evaluate(post);

}





