#include <iostream>
#include <fstream>

using namespace std;
class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    public:
    void menu();
    void administator();
    void customer();
    void list();
    void add();
    void edit();
    void rem();
    void receipt();
    void checkout();
};

void shopping :: menu()
{   
  /*label of goto statement it will jump to here*/
  m:
    int choice;
    string email;
    string password;

    cout<<"\t\t---------------------------\n";
    cout<<"\t\t---------------------------\n\n\n";
    cout<<"\t\t  ____SHOPPING CART____\n\n\n";
    cout<<"\t\t\t[ 1. Administrator ]\n";
    cout<<"\n";
    cout<<"\t\t\t[ 2.Customer ]\n";
    cout<<"\n";
    cout<<"\t\t\t[ 3.Exit ]\n\n";
    cout<<"\t\t---------------------------\n";
    cout<<"\t\t---------------------------\n";
    cout<<"\t\t\t  Please Select:)";
    cin>>choice;

      switch(choice)
       {
          case 1:
          cout<<"\t\t  Please Login\n";
          cout<<"\t\t Enter Email\n";
          cin>>email;
          cout<<"\t\t  Enter Password\n";
          cin>>password;

        if(email=="prernasingh.6november@gmail.com" && password=="prernasingh@123")
          {
            administator();
          }
        else
          {
            cout<<"\t\t  INVALID EMAIL|PASSWORD \n";
          }
        break;
          case 2:
          {
            customer();
          }
          case 3:
          {
            exit(0);
          }
        default :
          {
           cout<<"\t\t  Please select correct option :)\n";
          }
    }
/*help to jump to the main menu*/    
goto m;
}

void shopping :: administator()
 {
  m:
  int choice;
  cout<<"\t\t  __ADMINISTATOR MENU__  \n";
  cout<<"\n\n";
  cout<<"\t\t  1. Add the product \n";
  cout<<"\t\t  2. Modify the product  \n";
  cout<<"\t\t  3. Delete the product  \n";
  cout<<"\t\t  4. Back to Main Menu  \n\n";
  cout<<"\t\t  Please enter your choice :)  \n";
  cin>>choice;

switch(choice)
  {
    case 1:
     add();
     break;
    
    case 2:
     edit();
     break;

    case 3:
     rem();
     break;
    
    case 4:
     menu();
     break;
    
    default :
     cout<<"INVALID CHOICE\n"; 
  }
  goto m;
 }


void shopping :: customer()
{
  m:
  int choice;
  cout<<"\t\t   __CUSTOMER__  \n";
  cout<<"\t\t  1. Buy Product  \n";
  cout<<"\t\t  2. Go Back  \n";
  cout<<"\t\t  Enter your choice \n";

  cin>>choice;

  switch(choice)
   {
     case 1:
       receipt();
       break;
    
     case 2:
       menu();
       break;

     default :
       cout<<"Invalid Choice\n";
   }
goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\t\t Add new product\n";
    cout<<"\t\t Product code of the product\n";
    cin>>pcode;
    cout<<"\n\t\t Name of the product\n";
    cin>>pname;
    cout<<"\n\t\t Price o product\n";
    cin>>price;
    cout<<"\n\t\t Discount on product\n";
    cin>>dis;
    
    data.open("database.txt",ios::in);
    
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        
        while(!data.eof())
        {
          if(c ==pcode)  
          {
             token++; 
          }
          data>>c>>n>>p>>d;
        }
        data.close();
    
    if(token==1)
    goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();  
        
    }
}
    cout<<"\n\n\t\t Record inserted:)";
    
    
}
void shopping::edit()
{
  fstream data,data1;
  int pkey;
  int token;
  int c;
  float p;
  float d;
  string n;

  cout<<"\t\t  Modify the record\n";
  cout<<"\t\t  Product code\n";
  cin>>pkey;

  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\t\t File does not exsist!\n";
  }
  else{
    data1.open("database1.txt",ios::app|ios::out);

    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
      /*pkey is the code entered by the administator which he wants to edit if that matches */
      if(pkey==pcode)
      {
        cout<<"\t\t Product new code\n";
        cin>>c;
        cout<<"\t\t Name of the product\n";
        cin>>pname;
        cout<<"\t\t Price\n";
        cin>>p;
        cout<<"\t\t Discount \n";
        cin>>dis;
        data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        cout<<"\t\t Record edited\n";
        token++;
      }
      else
      {
        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
      cout<<"\t\t Record not found sorry:(\n";
    }
  }
}
void shopping::rem()
{
 fstream data,data1;
 int pkey;
 int token=0;
 cout<<"\t\t Delete product\n";
 cout<<"\t\t Product code\n";
 cin>>pkey;
 data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"File does not exist\n\n";
  }  
  else
  {
    data.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
       if(pcode=pkey)
       {
         cout<<"\t\t Product deleted successfully\n";
         token++;
       }
       else 
       {
         data1<<" "<<pcode<<" "<<price<<" "<<dis<<"\n";
       }
         data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
      cout<<"\n\n\t\t  Record not found\n";
    }
  }
}
void shopping::list()
{
  fstream data;
  data.open("database.txt",ios::in);
  cout<<"______________________________________\n";
  cout<<"ProductNo\t\tName\t\tPrice\n";
  cout<<"______________________________________\n";
  data>>pcode>>pname>>price>>dis;
  while(!data.eof())
  {
     cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
     data>>pcode>>pname>>price>>dis;
  }
  data.close();
}
void shopping::receipt()
{
 fstream data;

 int arrc[100];/*array of codes*/
 int arrq[100];/*array of quantity*/
 char choice;
 int c=0;
 float amount=0;
 float dis=0;
 float total=0;

 cout<<"\t\t RECEIPT\n";
 data.open("database.txt",ios::in);
 if(!data)
  {
   cout<<"\t\t\n Empty database";
  }
 
 else
  {
   data.close();
  
   list();
   cout<<"\n----------------------------------------\n\n";
   cout<<"\t\t Please place the order\n";
   cout<<"\n----------------------------------------\n\n";
   do
   {
     m:    
     cout<<"\t\t Enter product code\n";
     cin>>arrc[c];
     cout<<"\n\t\t Enter the quantity\n";
     cin>>arrq[c];
     for(int i=0;i<c;i++)
     {
      if(arrc[c]==arrc[i])
      {
        cout<<"\n\n Duplicate product code. Please try again:)";
        goto m;
      }
     }
     c++;
     cout<<"\n\n Do you want to play another product? if yes then press y else no";
     cin>>choice;
   }
   while(choice =='y');
   cout<<"\n\n\t\t---------- RECEIPT ----------\n";
   cout<<"Product No\t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount\n";

   for(int i=0;i<c;i++)
   {
     data.open("database.txt",ios::in);
     data>>pcode>>pname>>price>>dis;
     while(!data.eof())
     {
      if(pcode=arrc[i])
      {
        amount=price*arrq[i];
        dis=amount-(amount*dis/100);
        total=total+dis;
        cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<dis; 
      }
      data>>pcode>>pname>>price>>dis;
     }
   }
   data.close();
  }
  cout<<"\n\n--------------------------------------------\n";
  cout<<"\t\t Total Amount :"<<total;
}
int main()
{
  shopping s;
  s.menu();
}

 
