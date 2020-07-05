#include<iostream>


using namespace std;

void bubblesort(float arr[],int n)
{
    int i,j;
    float temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

}


void selectionsort(float arr[],int n)
{
    int i,j,min;
    float temp;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;

        }
    }

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

}

void insertionsort(float arr[],int n)
{

    int i,j=0,k;
    float temp;

    for(i=0;i<n;i++)
    {
        j=0;

         while(j<i && arr[i]>arr[j])
         {
             j++;
         }

          temp=arr[i];

          for(k=i-1;k>=j;k--)
          {
              arr[k+1]=arr[k];
          }

          arr[j]=temp;

    }

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }


}

void shellsort(float arr[],int n)
{

    int temp,step,i,j;

    for(step=n/2;step>0;step=step/2)
    {

        for(i=step;i<n;i++)
        {
            temp=arr[i];
            for(j=i;j>=0;j=j-step)
            {
                if(temp<arr[j-step])
                {
                    arr[j]=arr[j-step];
                }
                else
                {
                    break;
                }
                arr[j]=temp;

            }

        }


    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

}


int fixmyelement(float arr[],int low ,int up)
{
    int i,j;
    float pivot,temp;
    pivot=arr[low];
    i=low+1;
    j=up;


    while(i<=j)
    {
        while(i<=up && arr[i]<pivot)
        {
            i++;

        }

        while(j>=low && arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    temp=arr[j];
    arr[j]=pivot;
    arr[low]=temp;


    return j;

}

void quicksort(float arr[],int low ,int up)
{
    int i,j,ind;
    if(low<=up)
    {
        ind=fixmyelement(arr,low,up);
        quicksort(arr,low,ind-1);
        quicksort(arr,ind+1,up);
    }



}

void print(float arr[],int n)
{
    int i;

    if(n>=5)
    {
        for(i=0;i<5;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }

    else
    {
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
}


void get(float arr[],int n)
{
    int i;

    cout<<"enter avg. of "<<n<<" studnets out of 100\n";

    for(i=0;i<n;i++)
    {
        hi:
        cin>>arr[i];
        if(arr[i]<0 || arr[i]>100)
        {
            cout<<"invalid re-enter\n";
            goto hi;
        }
    }
}

int main()
{
    int n,i;

    cout<<"enter total no. of students\n";
    cin>>n;

    float arr[n];

   do
    {
        cout<<"\n1:get array\n2:bubble sort\n3:selection sort\n4:insertion sort\n5:shell sort\n6:quick sort\n7:print top 5\n8:exit\n";
        cin>>i;

        switch(i)
        {
        case 1:get(arr,n);
            break;
        case 2:bubblesort(arr,n);
            break;
        case 3:selectionsort(arr,n);
            break;
        case 4:insertionsort(arr,n);
            break;
        case 5:shellsort(arr,n);
            break;
        case 6:quicksort(arr,0,n-1);
            for(i=0;i<n;i++)
            {
                cout<<arr[i]<<"\t";
            }
            break;
        case 7:print(arr,n);
            break;
        case 8:i=0;
        }



    }while(i);


}
