//F3-21337
#include<iostream>
using namespace std;
int row ,col;
int arr[5][5];

void uptri();
void dsum();
void add();
void saddle();
void transpose();


int main()
{

int i,j;


cout<<"enter no. of rows and columns"<<"\n";
cin>>row>>col;

cout<<"enter elements of matrix"<<"\n";
    for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
         {
            cin>>arr[i][j];
         }
   }
    for(i=0;i<row;i++)
    {  cout<<"\n";
       for(j=0;j<col;j++)
         {
            cout<<arr[i][j]<<"\t";
         }

    }

    int ch;
    do
    {
    cout<<"\n"<<"enter choice"<<"\n";
    cout<<"1:upper triangular"<<endl<<"2:sum of diagonal elements"<<endl<<"3:addition,subtraction & multipliction"<<endl<<"4:saddle point"<<endl<<"5:transpose"<<endl<<"6:exit"<<"\n";
    cin>>ch;


    switch(ch)
    {
    case 1:uptri();
           break;

    case 2:dsum();
           break;
    case 3:add();
           break;
    case 4:saddle();
           break;

    case 5:transpose();
           break;
    case 6:ch=0;

    }

  }while(ch);

}




void uptri()
{
    int i,j;
    int count=0;
 for(i=0;i<row;i++)
   {
       for(j=(col/2);j<i;j++)
         {
            if(arr[i][j]!=0&&j<col)
              {
                cout<<"matrix is not upper triangular"<<"\n";
                count++;
                break;
              }
         }
             if(count!=0)
             {break;}
   }
   
    if(count==0)
   {
    cout<<"matrix is upper triangular"<<"\n";
   }

}



void dsum()
{

    int i,j,sum=0;

    for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
         {
           if(i==j)
           {
              sum=sum+arr[i][j];
           }
         }
   }

cout<<"sum of diagonal elements is "<<sum;

}

void add()
{
    int i,j,a,b,sum=0,k;
    cout<<"enter rows and columns of second matrix"<<"\n";
    cin>>a>>b;
    int arr1[a][b],arr2[a][b],arr3[a][b],arr4[row][b];
    cout<<"enter elements of second matrix"<<"\n"; 
    for(i=0;i<a;i++)
   {
       for(j=0;j<b;j++)
         {
            cin>>arr1[i][j];
         }
   }

    if((a==row)&&(b==col))
    {
        for(i=0;i<a;i++)
       {
           for(j=0;j<b;j++)
             {
               arr2[i][j]=arr[i][j]+arr1[i][j];
             }
       }
       cout<<"\n"<<"addition is:"<<"\n";

      for(i=0;i<a;i++)
     {
       for(j=0;j<b;j++)
         {
            cout<<arr2[i][j]<<"\t";
         }
       cout<<"\n";
     }
  }
    else
    {
        cout<<"addition cannot be performed";
    }
     cout<<"\n"<<"subtraction is:"<<"\n";

    
   if((a==row)&&(b==col))
    {
        for(i=0;i<a;i++)
       {
           for(j=0;j<b;j++)
             {
               arr3[i][j]=arr[i][j]-arr1[i][j];
             }
       }

      for(i=0;i<a;i++)
     {
       for(j=0;j<b;j++)
         {
            cout<<arr3[i][j]<<"\t";
         }
       cout<<"\n";
     }
  }
    else
    {
        cout<<"subtraction cannot be performed";
    }
   
      
   if(col==a)
    {
        for(i=0;i<col;i++)
       {
           for(j=0;j<b;j++)
             { 
                 sum=0;
               for(k=0;k<a;k++)
                 {
                    sum+=arr[i][k]*arr1[k][j];
                 }
                arr3[i][j]=sum;
             }
       }
   }          
    else
      {cout<<"no multiplication";}
    
   cout<<"multiplication is:"<<"\n";

    
        for(i=0;i<row;i++)
       {
           for(j=0;j<b;j++)
             {

          cout<<arr3[i][j]<<"\t";
             }
         cout<<"\n";
      }

}


void saddle()
{


int i,j,k,l,count=0,count1=0;
  for(i=0;i<row;i++)
     {
           for(j=0;j<col;j++)
         {
               count=0,count1=0;
              for(k=0;k<col;k++)
             {
              if(arr[i][j]>=arr[i][k])
              {
                count++;
              }
             }
           for(l=0;l<row;l++)
             {
              if(arr[i][j]<=arr[l][j])
              {
                count1++;
              }
             }
            if(count==1&&count1==1)
          {
           cout<<arr[i][j]<<" is saddle point"<<endl;
          }
       }
    }


  for(i=0;i<row;i++)
     {
           for(j=0;j<col;j++)
         {
               count=0,count1=0;
              for(k=0;k<col;k++)
             {
              if(arr[i][j]<=arr[i][k])
              {
                count++;
              }
             }
           for(l=0;l<row;l++)
             {
              if(arr[i][j]>=arr[l][j])
              {
                count1++;
              }
             }
            if(count==0&&count1==0)
          {
           cout<<arr[i][j]<<" is saddle point"<<endl;
          }
       }
   }
 /* if(count!=0&&count1!=0)
  {
      cout<<"no saddle point";
  }
  */

}

void transpose()
{
    int arr1[col][row],i,j;

    for(i=0;i<col;i++)
       {
             for(j=0;j<row;j++)
           {
                 arr1[i][j]=arr[j][i];
           }

       }
 cout<<"Transpose is:"<<"\n";
    for(i=0;i<col;i++)
       {
             for(j=0;j<row;j++)
           {
                cout<<arr1[i][j]<<"\t";
           }
             cout<<"\n";

       }




}




