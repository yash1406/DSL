#include<iostream>

using namespace std;

class arr
{
public:
    int degree;
    int coef;
};



class Polynomial
{
   public:
     arr pol1[100],pol2[100];
     int h1,h2;
   void get()
   {
        cout<<"enter number of terms of 1st polynomial "<<endl;
        cin>>h1;
        cout<<"enter number of terms of 2nd polynomial"<<endl;
        cin>>h2;

        int i;
        cout<<"1st polynomial in increasing order\n";
        
       for(i=0;i<h1;i++)
         {
           cout<<"enter degree of "<<i<<"th term"<<"\t";
           cin>>pol1[i].degree;
           cout<<"enter coefficient of "<<i<<"th term"<<"\t";
           cin>>pol1[i].coef;
           cout<<endl;

         }

        cout<<"2nd polynomial in increasing order\n";
        
       for(i=0;i<h2;i++)
       {
           cout<<"enter degree of "<<i<<"th term"<<"\t";
           cin>>pol2[i].degree;
           cout<<"enter coefficient of "<<i<<"th term"<<"\t";
           cin>>pol2[i].coef;
           cout<<endl;

       }
 

   }
   void print()
   {
       int i,j;
       for(i=0;i<h1;i++)
        {
            cout<<pol1[i].coef<<"x^"<<pol1[i].degree;
            if(i<h1-1)
            {
            
            cout<<"+";
             
            }
        }
        
       cout<<endl;
       for(i=0;i<h2;i++)
        {
             cout<<pol2[i].coef<<"x^"<<pol2[i].degree;
             if(i<h2-1)
            {
            
            cout<<"+";
             
            }
             
        }
        cout<<endl;

   }

   void add()
   {
      arr pol3[100];
      int i=0,j=0,k=0,c1=0,c2=0,c3=0;
      
      while(i<h1 && j<h2)
      {
          if(pol1[i].degree==pol2[j].degree)
         {
        
              pol3[k].degree=pol1[i].degree;
              pol3[k].coef=pol1[i].coef+pol2[j].coef;
              i++;
              j++;
              k++;
         }
         
          else if(pol1[i].degree<pol2[j].degree)
         {
            
              pol3[k].degree=pol1[i].degree;
              pol3[k].coef=pol1[i].coef;
              i++;
              k++;
         }
         
          else
         {
               
              pol3[k].degree=pol2[j].degree;
              pol3[k].coef=pol2[j].coef;
              j++;
              k++;
         } 
         c1++;
      
      }
      
      while(i<h1)
      {
          pol3[k].degree=pol1[i].degree;
          pol3[k].coef=pol1[i].coef;
          i++;
          k++;
          c2++;
      }
      
      while(j<h2)
      {
                
          pol3[k].degree=pol2[j].degree;
          pol3[k].coef=pol2[j].coef;
          j++;
          c3++;
          k++;
      }       
      
      
         for(i=0;i<c1+c2+c3;i++)
          {

              cout<<pol3[i].coef<<"x^"<<pol3[i].degree;
              if(i<c1+c2+c3-1)
              {
              cout<<"+";
              }
              
          }

      
    
   }


   void mul()
   {
      arr pol4[100],pol5[100];
      int i,j,k=0;

         for(i=0;i<h1;i++)
         {
             for(j=0;j<h2;j++)
             {
                 pol4[k].coef=pol1[i].coef*pol2[j].coef;
                 pol4[k].degree=pol1[i].degree+pol2[j].degree;
                 k++;
             } 

         }
       int  count=pol1[h1-1].degree;
       int c1=pol2[h2-1].degree;
       int s=count+c1;
       int cot[s+1];
       
       for(i=0;i<=s;i++)
       {
          cot[i]=0;
       }  
        
       for(i=0;i<h1*h2;i++)
       {
            cot[pol4[i].degree]=cot[pol4[i].degree]+pol4[i].coef;
       }
            
         
        for(i=0;i<=s;i++) 
       {
          pol5[i].coef=cot[i];
          
          pol5[i].degree=i;
       }   
           
         for(i=0;i<=s;i++)
          {
            
             if(pol5[i].coef!=0)
             {

                   cout<<pol5[i].coef<<"x^"<<pol5[i].degree;
                   if(i<s)
                   {
                    cout<<"+";
                   }
             }
             
          }




   }




};




int main()
{

  Polynomial s;
  int a,b=1;
 
 do
 {
     cout<<endl;
     
     cout<<"1:get  polynomials"<<endl<<"2:display"<<endl<<"3:add"<<endl<<"4:multiply"<<endl<<"5:exit"<<endl;
     cin>>a;

     switch(a)
   {

      case 1:s.get();
        break;
      case 2:s.print();
        break;
      case 3:s.add();
         break;
      case 4:s.mul();
       break;
      case 5:b=0;
       break;
  }
  
}while(b);

return 0;

}
