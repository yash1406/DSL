//F3-21337

#include<stdio.h>
void average(int *p,int n);
void minmax(int *a,int b);
void mode(int *p,int n);
void absent(int *p,int n);

int main()
{
  int n;
  printf("enter total no. of students\n");
  scanf("%d",&n);
  printf("enter -1 if the student is absent\n");
  int m[n];
  int i,j;

 for(i=0;i<n;i++)
{
   printf("enter marks of %d student\n",i+1);
   scanf("%d",&m[i]);
}
   
   int temp;
   for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(m[j]<m[i])
      {
        temp=m[i];
        m[i]=m[j];
        m[j]=temp;
      }
   }
 }
 
 
   int g;
do
 {
 
   printf("\npress\n1:average\n2:minmax\n3:max marks scored\n4:absent students\n5:exit\n");
   scanf("%d",&g);

   switch(g)
  {
      case 1:  average(m,n);
               break;
      case 2:  minmax(m,n);
               break;
      case 3:  mode(m,n);
               break;
      case 4:  absent(m,n);
               break;
      case 5:  g=0;
         
  }
  
 }while(g);
 
 
  return 0;
}

   void average(int *p,int n)
{
 
 int i;
 float avg,sum=0,count=0;

for(i=0;i<n;i++)
  {
     if(*(p+i)>-1)
    {
    
     sum=sum + *(p+i);
     count++;
     
    }
    
  }
   avg=(sum/count);
   printf("\naverage is %f\n",avg);
}



    void minmax(int *a,int b)
 {
 
 int i,count=0;
 for(i=0;i<b;i++)
  {
     if(*(a+i)==-1)
    {
    
    count++;
    
    }
    
  }

 printf("\nmaximum marks are %d",*(a+(b-1)));
 printf("\nminimum marks are %d",*(a+count));
 
 }

void mode(int *p,int n)
{

    int a=0,ct[n],i,j,count=0,max;
    for(i=0;i<n;i++)
    {
       count=0;
       for(j=0;j<n;j++)
      {
         if (*(p+i)==*(p+j) && *(p+i)>-1)
          {
           count++;
          }
      }
       ct[i]=count;
    }

    max=ct[0];
    for(i=0;i<n;i++)
   { 
      if(max<ct[i])
      {
        max=ct[i];
        a=i;
     
      }
   }

    printf("\nmax marks scored are %d by %d students",p[a],ct[a]);
}



void absent(int *p,int n)
{
  
  int i,count=0;

  for(i=0;i<n;i++)
 {
    if(*(p+i)== -1)
    {
      count++;
    }
 }
 
   printf("\nabsent students are %d",count);


}


















