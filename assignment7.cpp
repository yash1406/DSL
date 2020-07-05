#include<iostream>

using namespace std;

#define MAX 10

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
    void check();
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
    }
}

void Stack::print()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<data[i]<<"\t";
    }
}
void Stack::check()
{
    char str[100];
    int i=0;
    char c;
    cout<<"enter expression";
    cin.ignore();
    cin.getline(str,99);

    while(str[i]!='\0')
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(str[i]);
        }
        else if(!empty() && ((str[i]=='}' && data[top]=='{') || (str[i]==']' && data[top]=='[') || (str[i]==')' && data[top]=='(')))
        {


                    c=pop();


        }
        else if(empty() && ((str[i]==')' || str[i]=='}' || str[i]==']')))
        {
            cout<<"missing opening bracket for "<<str[i]<<endl;
            cout<<"wrong expression\n";
            return;
        }
        i++;
    }
    if(empty())
    {
        cout<<"correct expression\n";
    }
    else
    {
        while(!empty())
        {
            cout<<"missing closing bracket for "<<pop()<<endl;
        }
        cout<<"expression is wrong\n";
    }
}

int main()
{
    Stack s;
    int ch;
    do
    {
        cout<<"1:check\n2:exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:s.check();
            break;
        case 2:ch=0;

        }

    }while(ch);
}



