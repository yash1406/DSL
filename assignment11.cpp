#include<iostream>

using namespace std;

class Search
{
	int arr[100],num,num1;

public:
    Search()
    {
        num=0;
        num1=0;
    }

	void get();
	void check();
    void print();
	void binary();
	void sort();
    void sentinel();
    void fibonacci();
    int minimum(int ,int);

};

void Search::get()
{
    int i;
	cout<<"enter total number of students\n";
	cin>>num;

	cout<<"enter total number of present students\n";
label1:
    cin>>num1;
    if(num<num1)
    {
        cout<<"invalid re-enter\n";
        goto label1;

    }

    cout<<"enter roll numbers of present students\n";

    for(i=0;i<num1;i++)
	{
		label:

		cin>>arr[i];
		if(arr[i]<1 || arr[i]>num)
		{
			cout<<"invalid re-enter\n";
			goto label;
		
		}
	}

}



void Search::check()
{
    if(num1<=0)
    {
        cout<<"empty array\n";
        return;
    }
	int n,i,flag=0;
	cout<<"enter roll no to search\n";
	cin>>n;

	if(n<1 || n>num)
	{
        cout<<"such roll number does not exist\n";
		return;
	}

	for(i=0;i<num;i++)
	{
		if(n==arr[i])
		{
			cout<<"roll no."<<arr[i]<<" is present\n";
			flag=1;
		}
	}

	if(flag==0)
	{
        cout<<"roll no."<<n<<"is absent\n";
	}


}

void Search::sentinel()
{
    if(num1<=0)
    {
        cout<<"empty array\n";
        return;
    }

    int i=0,n;
    cout<<"enter roll no to search\n";
    cin>>n;

    if(n<1 || n>num)
    {
        cout<<"such roll number does not exist\n";
        return;
    }


    arr[num1]=n;
    while(arr[i]!=n)
    {
        i++;
    }
    if(i==num1)
    {
        cout<<"roll no."<<arr[i]<<" is absent\n";
    }
    else
    {
        cout<<"roll no."<<arr[i]<<" is present\n";
    }


}

void Search::sort()
{
    int i,j,temp;
    for(i=0;i<num1;i++)
    {
        for(j=i+1;j<num1;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }
}

void Search::binary()
{
    if(num1<=0)
    {
        cout<<"empty array\n";
        return;
    }
    sort();


    int n,flag=0,first,last,mid;
    first=0;
    last=num1-1;
    cout<<"enter roll no to search\t";
	cin>>n;
    mid=(first+last)/2;
    if(n<1 || n>num)
    {
        cout<<"such roll number number does not exist\n";
        return;
    }

    while(first<=last)
	{
		if(n==arr[mid])
		{
			cout<<"roll no."<<arr[mid]<<" is present\n";
            flag=1;
            return;
		}

		else if(n<arr[mid])
		{

            last=mid-1;


		}

		else
		{
            first=mid+1;


		}

        mid=(first+last)/2;

    }

    if(flag==0)
    {
        cout<<"roll no."<<n<<" is absent\n";
    }
	
}


void Search::fibonacci()
{
    if(num1<=0)
    {
        cout<<"empty array\n";
        return;
    }
    sort();
    int i,key,fib[100],j=-1,n,f,f1,f2,flag=0;
    n=num1-1;
    cout<<"enter roll no to search\n";
    cin>>key;

    if(key<1 || key>num)
    {
        cout<<"such roll number does not exist\n";
        return;
    }
    fib[0]=0;
    fib[1]=1;
    i=1;
    while(n>fib[i])
    {
        fib[i+1]=fib[i]+fib[i-1];
        i++;
    }
    f2=fib[i-2];
    f1=fib[i-1];
    f=fib[i];
    cout<<i<<endl;
    while(f>=1)
    {
        j=minimum(j+f2,n);


         if(key>arr[j])
        {
            f=f1;
            f1=f2;
            f2=f-f1;
        }
        else if(key<arr[j])
        {
            f=f2;
            f1=f1-f;
            f2=f-f1;
        }



        i--;
    }

    if(key==arr[j])
    {
        cout<<"roll no."<<arr[j]<<" is present at index "<<j<<endl;
        flag=1;
        return;
    }

    if(flag!=1)
    {
        cout<<"roll no."<<key<<" is absent\n";
    }



}

int Search::minimum(int x,int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void Search::print()
{
    int i;
    for(i=0;i<num1;i++)
    {
        cout<<arr[i]<<"\t";
    }
}


int main()
{
	Search obj;
	int ch;
	do
	{
        cout<<"\n1:get\n2:linear search\n3:binary search\n4:sentinel search\n5:fibonacci search\n6:print\n7:exit\n";
		cin>>ch;

		switch(ch)
		{
			case 1:obj.get();
				break;
			case 2:obj.check();
				break;
            case 3:obj.binary();
				break;
            case 4:obj.sentinel();
                break;
            case 5:obj.fibonacci();
                break;
            case 6:obj.print();
                break;
            case 7:ch=0;
		}
	}while(ch);   
}	



			





