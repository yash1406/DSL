//F3-21337

#include<iostream>
using namespace std;
class String
{
public:
char arr[20];
int len=0;

public:
void get()
{
int i=0;
 cout<<"enter string"<<endl;
cin>>arr;



}

int length(char h[])
{
 int i=0,x;
   while(h[i]!='\0')
   {
      x++;
      i++;
   }
  cout<<"length is "<<x<<endl;
  return x;
}

void copy()
{
char arr2[20];
int i=0;
while(arr[i]!='\0')
{
arr2[i]=arr[i];
i++;
}

arr2[i]='\0';
cout<<arr2<<endl;

}

void concat()
{
    char s[20];
    int i=0,k;

    cout<<"enter string to concat"<<endl;
    cin>>s;

    char con[40];
    while(arr[i]!='\0')
    {
        con[i]=arr[i];
        i++;
    }

    k=i;
    i=0;
    while(s[i]!='\0')
    {
        con[k]=s[i];
        k++;
        i++;
    }
    con[k]='\0';
    cout<<con<<endl;
}
  void equal()
  {
      char arr1[20];
      cout<<"enter 2nd string"<<endl;
      cin>>arr1;
      int i=0,count=0;
      while(arr[i]!='\0')
      {
          if(arr[i]==arr1[i])
          {
              count++;
          }
          i++;
      }
      if(count==i)
      {
          cout<<"strings are equal"<<endl;
      }
      else
      {
          cout<<"strings are not equal"<<endl;
      }

}
  void reverse(int a)
  {
      char arr1[20];
      int i=0,k;
      
      k=a-1;
      while(arr[i]!='\0')
      {
          arr1[i]=arr[ k];
          i++;
          k--;
      }
      arr1[i]='\0';
      cout<<arr1<<endl;

  }

  void sub(int m)
  {
      char s[20];
      cout<<"enter sub string"<<endl;
      cin>>s;
      int i=0,count=0,k=0,q,e,u;
      m=length(s);
      while(arr[i]!='\0')
      {
          
          if(arr[i]==s[k])
          {
             q=i;e=k;
          for(u=0;u<m;u++)
           {
           
             if(arr[q]==s[e])
               {
              count++;
              q++; 
              e++;
                }
              
            }
                if(count==m)
                 {
                 break;
                 }
          }
          i++;
      }
      if(count==m)
      {
          cout<<"sub string found"<<endl;
      }
      else
      {
          cout<<"sub string not found"<<endl;
      }
  }

  void freq()
  {
      char a;
      cout<<"enter character"<<endl;
      cin>>a;
      int i=0,count=0;
      while(arr[i]!='\0')
      {
          if(arr[i]==a)
          {
              count++;
          }
          i++;
      }
      cout<<"character "<<a<<" has occured "<<count<<" times"<<endl;
  }
  void chardelete()
  {

      char a;
      cout<<"enter character"<<endl;
      cin>>a;
      int i=0,k;
      while(arr[i]!='\0')
      {
          while(a==arr[i])
          {
              for(k=i;arr[k]!='\0';k++)
              {
                  arr[k]=arr[k+1];
              }
              arr[k]='\0';
          }
            i++;
      }
      cout<<arr<<endl;

  }
  void pldm(int a)
  {    char arr1[20];
       int i=0,k;
       k=a-1;
       while(arr[i]!='\0')
       {
           arr1[i]=arr[k];
           i++;
           k--;
       }
       arr1[i]='\0';
        cout<<arr1<<endl;
      int count=0;
       i=0;

      while(arr[i]!='\0')
      {
          if(arr[i]==arr1[i])
          {
              count++;
          }

          i++;
      }
     if(count==a)
     {
         cout<<"it is a pallindrome"<<endl;
     }
     else
     {
         cout<<"it is not a pallindrome"<<endl;
     }

  }

  void replace()
  {   char s[20],x[20];
      cout<<"enter sub string"<<endl;
      cin>>s;
      int i=0,count=0,k=0,j=0,l,m,q,e,u;
      m=length(s);
      char arr2[20];
      cout<<"enter replacement string"<<endl;
      cin>>arr2;
      while(arr[i]!='\0')
       {
       x[i]=arr[i];
      i++;
       }

     x[i]='\0';
     i=0;
      while(arr[i]!='\0'&&s[k]!='\0')
      {
         
          if(arr[i]==s[k])
        {
          count=0;
          q=i;e=k;
          for(u=0;u<m;u++)
            {
           
               if(arr[q]==s[e])
                {
                   count++;
                   q++; 
                   e++;
                }
               
           }
                if(count==m)
                 {
                 break;
                 }

        }
          i++;
      }
      
      if(count==m)
      {
          cout<<"sub string found"<<endl;
          i=0;
           while(arr[i]!='\0')
           {
           if(arr[i]==s[0]&&arr[i+1]==s[1])
           {
           break;
           }
             i++;
           }
             k=0;
             l=i;
           while(arr2[k]!='\0')
            {
             arr[i]=arr2[k];
             k++;
              i++;        
             }
             
             k=l+m;
             while(x[k]!='\0')
             {
              arr[i]=x[k];
              i++;
              k++;
              }
              arr[i]='\0';
          cout<<arr<<endl;

      }
      else
      {
          cout<<"sub string not found"<<endl;
      }

  }

  void del()
  {
     int start,l,i=0,k=0,j=0,m;
     cout<<"enter start and length as indexing start from 0"<<endl;
     cin>>start>>l;
     m=start;
     if(start<=(length(arr)-1))
     {    int count=0;
         while(arr[start]!='\0')
         {
             count++;
             start++;
         }

     if(l<=count)
     {
         i=0;
     while(arr[i]!='\0'&&j<l)
     {
         if(arr[i]==arr[m])
         {
             for(k=i;arr[k]!='\0';k++)
             {
                 arr[k]=arr[(k+l)];
                 
             }
             arr[k]='\0';
             
             j++;
         }
           i++;

     }
     cout<<arr<<endl;
     }
     else
     {
          cout<<"cannot be done as there are less characters than length after start"<<endl;
     }

     }
     else
     {
         cout<<"cannot be done as start>length"<<endl;
     }




  }


};


int main()
{
  String s;
   int ch,z;
do
{
  cout<<"enter choice"<<endl<<"1:get string"<<endl<<"2:length"<<endl<<"3:copy"<<endl<<"4:concat"<<endl<<"5:equal"<<endl<<"6:reverse"<<endl<<"7:substring"<<endl
     <<"8:frequency"<<endl<<"9:delete character"<<endl<<"10:pallindrome"<<endl<<"11:replace"<<endl<<"12:delete"<<endl<<"13:exit"<<endl;
 
   cin>>ch;
  switch(ch)
 { 
   case 1:s.get();
          break;
   case 2://s.get();
          z=s.length(s.arr);
          break;
   case 3://s.get();
          s.copy();
          break;
   case 4://s.get();
          s.concat();
          break;
   case 5://s.get();
          s.equal();
          break;
   case 6://s.get();
          z=s.length(s.arr);
          s.reverse(z);
          break;
   case 7://s.get();
   z=s.length(s.arr);
          s.sub(z);
          break;
   case 8://s.get();
          s.freq();
          break;
   case 9://s.get();
          s.chardelete();
          break;
   case 10://s.get();
   z=s.length(s.arr);
           s.pldm(z);
           break;
   case 11://s.get();
           s.replace();
           break;
   case 12://s.get();
           s.del();
           break;
   case 13:ch=0;        


}
}while(ch);

}


















