#include<iostream>

using namespace std;



class mat
{
public:
    int row;
    int col;
    int value;


};

class Sparse
{
public:
    mat *x;
    int n;
    int row1,col1;

    void get()
    {
        int i,j,k;
        cout<<"enter number of rows and columns"<<endl;
        cin>>row1>>col1;
        cout<<"enter number of non zero elements"<<endl;
        cin>>n;
        x=new mat[n+1];
        x->row=row1;
        x->col=col1;
        x->value=n;
          for(i=1;i<=n;i++)
          {


              cout<<"enter row number"<<"\t";
              cin>>(x+i)->row;
              if((x+i)->row > row1)
              {
                  cout<<"invalid re-enter\n";
                         cin>>(x+i)->row;
              }
              cout<<"enter column number"<<"\t";
              cin>>(x+i)->col;
              if((x+i)->col > col1)
              {
                  cout<<"invalid re-enter\n";
                   cin>>(x+i)->col;
              }
              cout<<"enter element"<<"\t";
              cin>>(x+i)->value;
              cout<<endl;

          }
    }

    void print()
    {
        int i,j;
             cout<<"row="<<row1<<"\t"<<"col="<<col1<<" ele="<<n<<endl;

             for(i=1;i<n+1;i++)
             {

                 cout<<(x+i)->row<<"\t"<<(x+i)->col<<"\t"<<(x+i)->value<<endl;
             }
    }

    void transpose()
    {
       int i,j;
       mat *t;
        int arr1[20][3],index[col1],count[col1];
        t=new mat [n+1];
        t->row=col1;
        t->col=row1;
        t->value=n;
      for(i=0;i<col1;i++)
      {
          count[i]=0;

      }

       for(i=1;i<=n;i++)
       {
           count[(x+i)->col]++;


       }
      cout<<"count:\t";
       for(i=0;i<col1;i++)
       {
           cout<<count[i]<<"\t";

       }
       index[0]=1;
      for(i=1;i<col1;i++)
       {
          index[i]=index[i-1]+count[i-1];


       }
      cout<<endl<<"start pos:";
        for(i=0;i<col1;i++)
        {
            cout<<index[i]<<"\t";
        }


        for(i=1;i<=n;i++)
        {
            (t+index[(x+i)->col])->row=(x+i)->col;
            (t+index[(x+i)->col])->col=(x+i)->row;
            (t+index[(x+i)->col])->value=(x+i)->value;
            index[(x+i)->col]++;

        }
       cout<<endl;
        cout<<"row="<<col1<<"\t"<<"col="<<col1<<" ele="<<n<<endl;

        for(i=1;i<n+1;i++)
        {

            cout<<(t+i)->row<<"\t"<<(t+i)->col<<"\t"<<(t+i)->value<<endl;
        }










    }



    void add()
    {

        cout<<"enter 2nd matrix\n";
        mat *y;
        int i,j,row2,col2,n1,k;
        cout<<"enter number of rows and columns"<<endl;
        cin>>row2>>col2;
		if(row1!=row2 || col1!=col2)
		{
			cout<<"inavlid re-enter\n";
			cout<<"enter number of rows and columns"<<endl;
			cin>>row2>>col2;
		}
        cout<<"enter number of non zero elements"<<endl;
        cin>>n1;
        y=new mat[n1+1];
        y->row=row1;
        y->col=col1;
        y->value=n1;
          for(i=1;i<=n1;i++)
          {


              cout<<"enter row number"<<"\t";
              cin>>(y+i)->row;
              if((y+i)->row > row2)
              {
                  cout<<"invalid re-enter\n";
                         cin>>(y+i)->row;
              }
              cout<<"enter column number"<<"\t";
              cin>>(y+i)->col;
              if((y+i)->col > row2)
              {
                  cout<<"invalid re-enter\n";
                   cin>>(y+i)->col;
              }
              cout<<"enter element"<<"\t";
              cin>>(y+i)->value;
              cout<<endl;
          }


          cout<<"row="<<row2<<"\t"<<"col="<<col2<<" ele="<<n1<<endl;

          for(i=1;i<n1+1;i++)
          {

              cout<<(y+i)->row<<"\t"<<(y+i)->col<<"\t"<<(y+i)->value<<endl;
          }

    
          mat *z;
          z=new mat[n1+n+1];
          z->row=row1;
          z->col=col1;

          i=1;
          j=1;
          k=1;
           while(i<=n && j<=n1)
           {
               if((x+i)->row==(y+j)->row)
               {

                   if((x+i)->col==(y+j)->col)
                   {
                       (z+k)->row=(x+i)->row;
                       (z+k)->col=(x+i)->col;
                       (z+k)->value=(y+j)->value+(x+i)->value;
                       i++;
                       j++;
                       k++;
                   }
					
                   else if((x+i)->col < (y+j)->col)
                   {
                       (z+k)->row=(x+i)->row;
                       (z+k)->col=(x+i)->col;
                       (z+k)->value=(x+i)->value;
                       i++;
                      
                       k++;
                   }
					
                   else if((x+i)->col > (y+j)->col)
                   {
                       (z+k)->row=(y+j)->row;
                       (z+k)->col=(y+j)->col;
                       (z+k)->value=(y+j)->value;
                       
                       j++;
                       k++;
                   }


               }

               else if((x+i)->row < (y+j)->row)
               {

                   (z+k)->row=(x+i)->row;
                   (z+k)->col=(x+i)->col;
                   (z+k)->value=(x+i)->value;
                   i++;

                   k++;
               }

              else if((x+i)->row > (y+j)->row)
               {

                   (z+k)->row=(y+j)->row;
                   (z+k)->col=(y+j)->col;
                   (z+k)->value=(y+j)->value;
                   j++;

                   k++;

               }

           }


           while(i<=n)
           {


               (z+k)->row=(x+i)->row;
               (z+k)->col=(x+i)->col;
               (z+k)->value=(x+i)->value;
               i++;

               k++;


           }

           while(j<=n1)
           {


               (z+k)->row=(y+j)->row;
               (z+k)->col=(y+j)->col;
               (z+k)->value=(y+j)->value;
               j++;

               k++;


           }



           z->value=k-1;
           int w=z->value;

          cout<<"\nrow="<<row2<<"\t"<<"col="<<col2<<" ele="<<k-1<<endl;
           i=1;
           while(i<=w)
           {

               cout<<(z+i)->row<<"\t"<<(z+i)->col<<"\t"<<(z+i)->value<<endl;
               i++;
           }



    }


};

int main()
{
    Sparse s;
    int a,b=1;


    do

    {
        cout<<"enter choice"<<endl;
        cout<<"1:get"<<endl<<"2:print"<<endl<<"3:transpose"<<endl<<"4:add"<<endl<<"5:exit"<<endl;
        cin>>a;


        switch(a)
        {
        case 1:
             s.get();
              break;
        case 2:s.print();
              break;
        case 3:s.transpose();
              break;
        case 4:s.add();
              break;
        case 5:b=0;

        }




    }while(b);



}
