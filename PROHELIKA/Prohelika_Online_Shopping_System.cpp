//**************************************************
//LIBRARY HEADERS
//**************************************************
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
#include<windows.h>
#include<direct.h>
#include<sstream>

using namespace std;


//**************************************************
//BASE CLASS
//**************************************************

class System{


public :

int open();                        ///cover page

int mainmenu();                    ///Main menu

void createaccount();               ///Creating account

void depositamnt();                 ///Deposit amount

void loading();                     ///Loading screen1

void loading2();                    ///Loading screen2

void modify();                      ///Modify user account

void searchpro();                   ///Search products

void deliveryinfo();                ///Show delivery info

void neworder();                    ///Place a new order

void modifyorder();                 ///Modify the order placed

void cancelorder();                   ///Cancel order already placed

void se_products(string i,int n);      ///Select product from database

static void passname(string s);         ///pass the current user name

void passpassword(string n);             ///pass the current password

void passid(string i);                   ///pass the id

void passnum(string u);                  ///pass the number

void arrowpos(int rp,int ap);

void DeliveryServices();

bool signin();

int positionmenu();

int adminmenu();

int itemenu();

int emplyeemenu();

int paymenu();

int timemenu();

string confirmationmenu(string msg);

int deliverydays();

int placemenu();

int deliveryservice();

int country();

int productype(string c);

int modifymenu();

int modifyordermenu();

void verify();

void Logout();

void registar();

bool passexist(string p);

bool idexists(string i);

bool indexcheck(string f,string i);

bool checkname(string n);

void forgotpass();

protected:                       ///Private class variables

    static string pass;         ///variable for storing password

    static int amount;          ///variable for storing amount

    string age;

    string num;

    static string id;

    static string name;

    static string paymethod;

    static int proindex;

    string day,time,place,deli;

    static string filename;

    string prono;

    string productname;              ///variable for storing product name

    string price;                    ///variable for storing price

    static string cur;

    static int highcur;

    static int lowcur;

    string employeepos;

    string employeename;

    string employeeage;

    string employeeid;

    static float workexp;

    static int paycheck;
};


//**************************************************
//DERIVED CLASS
//**************************************************

class Country:public System{

public:


    void Product(string file,string c);                      ///Show product catalog
    void Product(string file,string c,string type);      ///Search product catalog



};


void Country::Product(string file,string c){
cur = c;

filename = file;
ifstream product;

product.open(file.c_str());

if(!product.is_open()){
    cout<<"CANNOT OPEN FILE";
}
else{
while(getline(product,prono,':'))
{
    getline(product,productname,':');
    getline(product,price,'\n');

    cout<<"\t\t\t\t\t----------------------------------------------\n";
    cout<<"\t\t\t\t\t"<<prono<<"."<<productname<<":"<<price<<cur<<"\n";
    cout<<"\t\t\t\t\t----------------------------------------------\n";

}
}
product.close();
}


void Country::Product(string file,string c,string type){
loop:
system("cls");
cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
cout<<"\t\t\t\t\tSHOWING "<<type<<" : \n";
cout<<"\t\t\t\t\t======================================\n";
string i,j,k;
int a,b;
int m,n;
cur = c;
filename = file;
ifstream product;
ifstream product1;
product.open(file.c_str());
product1.open(file.c_str());
if(!product.is_open()){
    cout<<"CANNOT OPEN FILE";
}
if(!product1.is_open()){
    cout<<"CANNOT OPEN FILE";
}



for(m=1;getline(product1,i,':');m++)
{
        getline(product1,j,':');
        getline(product1,k,'\n');
        n=m;
        if(i=="1"){
            lowcur = atoi(k.c_str());
        }
        if(n=atoi(i.c_str())){
            highcur = atoi(k.c_str());
        }
}

cout<<"\t\t\t\t\tEnter a price within range "<<lowcur<<" to "<<highcur<<cur<<"\n";
cout<<"\t\t\t\t\tEnter first range :";
cin>>a;
cout<<"\t\t\t\t\tEnter second range :";
cin>>b;

if(a>=lowcur && b <=highcur){
while(getline(product,prono,':'))
{

    getline(product,productname,':');
    getline(product,price,'\n');


    int i=atoi(price.c_str());
    if(i>=a && i<=b){
        cout<<"\t\t\t\t\t---------------------------------------\n";
        cout<<"\t\t\t\t\t|"<<prono<<"."<<productname<<":"<<price<<cur<<"|\n";
        cout<<"\t\t\t\t\t---------------------------------------\n";
    }
}
}
else{

    goto loop;
}


product.close();
product1.close();

}







class Catalog:public Country{

public:
    void catalog(int b);
    void neworder();

    void BuyProduct(string f1,string c);

    void show_and_buyproduct();
    void search_and_buyproduct();
    void admin();
    void updatefile(string file,string c);
    void addemployee();
    void showemployee();
    void removeitem();

};

//**************************************************
//FUNCTIONS
//**************************************************
bool System::indexcheck(string f,string i){
string a,b,c;
int found = 0;
ifstream file;
file.open(f.c_str());

while(getline(file,a,':')){
    getline(file,b,':');
    getline(file,c,'\n');
    if(a==i){
        found=1;
    }
}
if(found==1){
    return true;
}else{
    return false;
}
}



void Catalog::updatefile(string file,string c){

filename =file;
cur = c;
string i,j,k,no;
ofstream outfile;
outfile.open(file.c_str(),ios::app);
loop:
system("cls");
cout<<"\n\t\tEnter a new product index :";
cin>>i;
if(indexcheck(file,i)){
    cout<<"\n\t\t A Product at that index already exist ";
    getch();
    goto loop;
}else{
    no=i;
}
cout<<"\n\t\tEnter new product name :";
cin.ignore();
getline(cin,j);
cout<<"\n\t\tEnter the price :";
cin>>k;
outfile<<no<<":"<<j<<" : "<<k<<endl;
cout<<"\n\t\tProduct added successfully !!";

}

void System::arrowpos(int rp,int ap){
if(ap==rp){
    cout<<"\t\t\t\t ==>";

}else{
    cout<<"\t\t\t\t";
}

}

void System::verify(){
    system("cls");
    char c[]={'-','\\','|','/','-'};
    cout << "\n\n\n\n\n\t\t\t\t\t\tVERIFYING.....";
    cout.flush();
    for (int j=0;j<3;j++) {
        for (int i = 0;i<5; i++) {

            cout<<c[i]<<"\b";
            cout.flush();
            Sleep(100);
        }

    }

}

void System::Logout(){
    system("cls");
    char c[]={'-','\\','|','/','-'};
    cout << "\n\n\n\n\n\t\t\t\t\t\tLOGGING OUT.....";
    cout.flush();
    for (int j=0;j<3;j++) {
        for (int i = 0;i<5; i++) {
            cout<<c[i]<<"\b";
            cout.flush();
            Sleep(100);
        }

    }
    cout<<"\n\n\n\t\t\t\t\t\tPress any key to continue !!";
    getch();
    cin.ignore();
}


void System::registar(){
    system("cls");
    char c[]={'-','\\','|','/','-'};
    cout << "\n\n\n\n\n\t\t\t\t\t\tREGISTERING.....";
    cout.flush();
    for (int j=0;j<3;j++) {
        for (int i = 0;i<5; i++) {
            cout<<c[i]<<"\b";
            cout.flush();
            Sleep(100);
        }

    }
    cout<<"\n\n\n\t\t\t\t\t\tREGISTRATION SUCESSFUL!!";
    getch();
    cin.ignore();
}


int System::positionmenu()
{
    char keyps = 0;
    int pointerps = 1;
    int maxpos = 6;
    while(keyps!=13){
        system("cls");
        cout<<"\t\t\t\t\t\tSELECT POSITION\n\n\n";
       arrowpos(1,pointerps); cout<<"\t1.Delivery Person\n";
       arrowpos(2,pointerps); cout<<"\t2.Product Manager\n";
       arrowpos(3,pointerps); cout<<"\t3.Store Manager\n";
       arrowpos(4,pointerps); cout<<"\t4.Merchandiser\n";
       arrowpos(5,pointerps); cout<<"\t5.Stocking Associate\n";
       arrowpos(6,pointerps); cout<<"\t6.Customer Service Associate\n";

       keyps = getch();
       if(keyps == 80 && pointerps != maxpos){
        pointerps++;
       }else if(keyps == 72 && pointerps != 1){
        pointerps--;
       }else{
        pointerps=pointerps;
       }

       if(keyps == 13){
        return pointerps;
        break;
       }

    }
    getch();
}

int System::modifyordermenu(){
int keyps = 0;
int pointerps =1;
int maxps = 5;
while(keyps!=13){
    system("cls");
    cout<<"\n\n\t\t\t\tWhat do you want to change ?\n\n";
    arrowpos(1,pointerps);cout<<"1.Payment method\n";
    arrowpos(2,pointerps);cout<<"2.Delivery Service\n";
    arrowpos(3,pointerps);cout<<"3.Delivery Day\n";
    arrowpos(4,pointerps);cout<<"4.Delivery Time\n";
    arrowpos(5,pointerps);cout<<"5.Delivery Place\n";
    keyps=getch();
    if(keyps==80 && pointerps!=maxps){
        pointerps++;
    }else if(keyps==72 && pointerps!=1){
        pointerps--;

    }
    else{
        pointerps=pointerps;

    }

    if(keyps==13){
        return pointerps;
        break;
    }

}
getch();
}


int System::country(){
int keyps=0;
int pointerps=1;
int maxps=3;
while(keyps!=13){
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t\tCHOOSE YOUR COUNTRY...\n";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(1,pointerps);cout<<"\t  |\t   1.BANGLADESH          |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(2,pointerps);cout<<"\t  |\t     2.CHINA             |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(3,pointerps);cout<<"\t  |\t    3.AMERICA            |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    keyps=getch();
    if(keyps==80 && pointerps!=maxps){
        pointerps++;
    }else if(keyps==72 && pointerps!=1){
        pointerps--;
    }
    else{
        pointerps=pointerps;

    }
    if(keyps==13){
        return pointerps;
        break;
    }


}
    getch();
}



int System::itemenu(){

int keyps=0;
int pointerps =1;
int maxps = 2;
while(keyps!=13){
     system("cls");
        cout<<"\n\n\n\t\t\t\t====================================================\n";
        cout<<"\t\t\t\t|                  MODIFY ITEMS                    |"<<endl;
        cout<<"\t\t\t\t====================================================";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(1,pointerps);cout<<"\t  |\t  1.ADD ITEM             |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(2,pointerps);cout<<"\t  |\t  2.REMOVE ITEM          |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        keyps = getch();
        if(keyps==80 && pointerps != maxps){
            pointerps++;
        }else if(keyps == 72 && pointerps != 1){
            pointerps--;
        }else{
            pointerps=pointerps;
        }

        if(keyps==13){
            return pointerps;
            break;
        }

}
getch();

}

int System::modifymenu(){
int keyps = 0;
int pointerps =1;
int maxps = 5;
while(keyps!=13){
system("cls");
cout<<"\n\t\t\t\t\t  ================================";
cout<<"\n\t\t\t\t\t  |         MODIFY INFO          |";
cout<<"\n\t\t\t\t\t  ================================\n";

cout<<"\n\t\t\t\t\t  --------------------------------\n";
arrowpos(1,pointerps);cout<<"\t  |\t1.CHANGE NAME            |";
cout<<"\n\t\t\t\t\t  --------------------------------\n";
arrowpos(2,pointerps);cout<<"\t  |\t2.CHANGE PASSWORD        |";
cout<<"\n\t\t\t\t\t  --------------------------------\n";
arrowpos(3,pointerps);cout<<"\t  |\t3.CHANGE AGE             |";
cout<<"\n\t\t\t\t\t  --------------------------------\n";
arrowpos(4,pointerps);cout<<"\t  |\t4.CHANGE MOBILE NUMBER   |";
cout<<"\n\t\t\t\t\t  --------------------------------\n";
arrowpos(5,pointerps);cout<<"\t  |\t5.CHANGE CARD NO         |";
cout<<"\n\t\t\t\t\t  --------------------------------\n";
    keyps=getch();
    if(keyps==80 && pointerps!=maxps){
        pointerps++;
    }else if(keyps==72 && pointerps!=1){
        pointerps--;
    }else{
        pointerps=pointerps;
    }

    if(keyps==13){
        return pointerps;
        break;
    }

}
getch();
}


int System::adminmenu(){
char keyps =0;
int pointerps =1;
int maxps = 5;
while(keyps!=13){
     system("cls");

        cout<<"\n\n\n\t\t\t\t\t  ********************************";
        cout<<"\n\t\t\t\t\t  **********ADMIN PANEL***********";
        cout<<"\n\t\t\t\t\t  ********************************\n";

        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(1,pointerps);cout<<"\t  |\t  1.MODIFY ITEM          |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(2,pointerps);cout<<"\t  |\t  2.CUSTOMER LIST        |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(3,pointerps);cout<<"\t  |\t  3.ORDER LIST           |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(4,pointerps);cout<<"\t  |\t  4.MANAGE EMPLOYEES     |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(5,pointerps);cout<<"\t  |\t  5.LOGOUT               |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";

        keyps=getch();

        if(keyps==80 && pointerps!=maxps){
            pointerps++;
        }else if(keyps==72 && pointerps!=1){
            pointerps--;
        }else{
            pointerps=pointerps;
        }

        if(keyps==13){
            return pointerps;
            break;
        }

}
    getch();

}

int System::emplyeemenu(){
    int keyps = 0;
    int pointerps =1;
    int maxpos =2;
while(keyps != 13){

     system("cls");
        cout<<"\n\n\t\t\t\t=========================================================\n";
        cout<<"\t\t\t\t|                   MANAGE EMPLOYEES                    |"<<endl;
        cout<<"\t\t\t\t=========================================================\n";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(1,pointerps);cout<<"\t |\t 1.ADD EMPLOYEE INFO     |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        arrowpos(2,pointerps);cout<<"\t |\t  2.EMPLOYEES LIST       |";
        cout<<"\n\t\t\t\t\t  --------------------------------\n";
        keyps=getch();
        if(keyps == 80 && pointerps != maxpos){
            pointerps++;
        }else if(keyps == 72 &&  pointerps != 1){
            pointerps--;
        }
        else{
            pointerps = pointerps;

        }

        if(keyps == 13){
            return pointerps;
            break;
        }


}

getch();
}

int System::deliveryservice(){
int keyps=0;
int pointerps = 1;
int maxps =3;
while(keyps!=13){
    system("cls");
    cout<<"\n\t\t\t\tSelect a delivery service :\n\n";
    arrowpos(1,pointerps);cout<<"1.DHL\n";
    arrowpos(2,pointerps);cout<<"2.Fed Ex\n";
    arrowpos(3,pointerps);cout<<"3.UPS\n";
    keyps=getch();
    if(keyps==80 && pointerps!=maxps){
        pointerps++;
    }else if(keyps==72 && pointerps!=1){
        pointerps--;
    }else{
        pointerps=pointerps;
    }

    if(keyps==13){
        return pointerps;
        break;
    }
}
getch();

}

int System::deliverydays(){
int keypos = 0;
int pointerps =1;
int maxpos = 4;
while(keypos!= 13){
        system("cls");
      cout<<"\n\t\t\t\t Days available for delivery :\n";
      arrowpos(1,pointerps);cout<<"1.Sunday\n";
      arrowpos(2,pointerps);cout<<"2.Tuesday\n";
      arrowpos(3,pointerps);cout<<"3.Thursday\n";
      arrowpos(4,pointerps);cout<<"4.Saturday\n";
        keypos=getch();
        if(keypos==80 && pointerps!= maxpos){
            pointerps++;
        }
        else if(keypos==72 && pointerps!=1){
            pointerps--;
        }
        else{
            pointerps=pointerps;
        }

        if(keypos==13){
            return pointerps;
            break;
        }
}
getch();

}

string System::confirmationmenu(string msg){
int keyps=0;
int pointerps=1;
int maxps=2;
while(keyps!=13){
        system("cls");
     cout<<"\n\n\n\t\t\t"<<msg<<"\n\n";
            arrowpos(1,pointerps);cout<<"YES";arrowpos(2,pointerps);cout<<"NO";
            keyps=getch();
            if(keyps==77&&pointerps!=maxps){
                pointerps++;
            }else if(keyps==75&& pointerps!=1){
                pointerps--;
            }else{
                pointerps=pointerps;
            }

            if(keyps==13){
                if(pointerps==1){
                    return "y";
                    break;
                }else if(pointerps==2){
                    return "n";
                    break;
                }
            }
}
getch();
}

int System::timemenu(){

int keyps = 0;
int pointerps=1;
int maxps=4;
while(keyps!=13){
    system("cls");
    cout<<"\n\t\t\t\tTimes available for delivery :\n";
    arrowpos(1,pointerps);cout<<"1.9:30 AM\n";
    arrowpos(2,pointerps);cout<<"2.12:30 PM\n";
    arrowpos(3,pointerps);cout<<"3.3:30 PM\n";
    arrowpos(4,pointerps);cout<<"4.5:30 PM\n";
    keyps=getch();
    if(keyps==80 && pointerps != maxps){
        pointerps++;
    }else if(keyps==72 && pointerps != 1){
        pointerps--;
    }else{
        pointerps=pointerps;
    }

    if(keyps==13){
        return pointerps;
        break;
    }

}
getch();
}

int System::paymenu(){
int keyps = 0;
int pointerps = 1;
int maxpos =2;
while(keyps!=13){
            system("cls");
            cout<<"\n\n\t\t\t\tHow do you want to pay ?:\n";
            arrowpos(1,pointerps);cout<<"1.Your Credit Amount\n";
            arrowpos(2,pointerps);cout<<"2.Cash on Delivery\n";
            keyps=getch();
            if(keyps==80 && pointerps != maxpos){
                pointerps++;
            }else if(keyps == 72 && pointerps != 1){
                pointerps--;
            }else{
                pointerps=pointerps;
            }

            if(keyps==13){
                return pointerps;
                break;
            }

}
getch();
}

int System::placemenu(){
int keyps=0;
int pointerps = 1;
int maxps=3;
while(keyps!=13){
    system("cls");
    cout<<"\n\t\t\t\tAvailable places for delivery :\n";
    arrowpos(1,pointerps);cout<<"1.Uttara,Dhaka\n";
    arrowpos(2,pointerps);cout<<"2.Mirpur,Dhaka\n";
    arrowpos(3,pointerps);cout<<"3.Gulshan,Dhaka\n";
    keyps = getch();
    if(keyps==80 && pointerps!=maxps){
        pointerps++;
    }else if(keyps==72 && pointerps != 1){
        pointerps--;
    }else{
        pointerps=pointerps;
    }

    if(keyps == 13){
        return pointerps;
        break;
    }

}
getch();

}

void System::forgotpass(){
string n,id,s;
ifstream file;
file.open("userdata.txt");
cout<<"\n\n\n\n\t\t\t\tEnter you user name :";
getline(cin,n);
if(!file.is_open()){
    cout<<"\n\n\n\t\t\t\tUSER DOESN'T EXIST";
}
else{
    while(getline(file,name,':')){
        getline(file,pass,':');
        getline(file,age,':');
        getline(file,num,':');
        getline(file,id,':');
        getline(file,s,'\n');
        if(n.find(name,0)!=string::npos){
            cout<<"\n\n\n\n\t\t\t\tYour password :"<<pass;
        }
    }

}


}

int System::productype(string c){
int keyps=0;
int pointerps=1;
int maxps=4;
while(keyps!=13){
     system("CLS");
    cout<<"\n\n\n\t\t\t\t\t SHOWING RESULTS FOR "<<c<<endl;
    cout<<"\n\t\t\t\t\t  ---------------------------\n";
    arrowpos(1,pointerps);cout<<"\t  |     1.MOBILE PHONE      |";
    cout<<"\n\t\t\t\t\t  ---------------------------\n";
    arrowpos(2,pointerps);cout<<"\t  |     2.LAPTOP            |";
    cout<<"\n\t\t\t\t\t  ---------------------------\n";
    arrowpos(3,pointerps);cout<<"\t  |     3.MONITOR           |";
    cout<<"\n\t\t\t\t\t  ---------------------------\n";
    arrowpos(4,pointerps);cout<<"\t  |    4.TELEVISION         |";
    cout<<"\n\t\t\t\t\t  ---------------------------\n";
    keyps=getch();
    if(keyps==80 && pointerps!=maxps ){
        pointerps++;
    }else if(keyps == 72 && pointerps!=1){
        pointerps--;
    }else {
        pointerps=pointerps;
    }

    if(keyps==13){
        return pointerps;
        break;
    }
}
getch();


}

void Catalog::addemployee(){
char a;
string b;
int p;
ofstream file;
file.open("employee.txt",ios::app);

a='0'+positionmenu();
switch(a){
case '1':
    employeepos ="Delivery Person";
    break;
case '2':
    employeepos ="Product Manager";
    break;
case '3':
    employeepos ="Store Manager";
    break;
case '4':
    employeepos="Merchandiser";
    break;
case '5':
    employeepos="Stocking Associate";
    break;
case '6':
    employeepos="Customer Service Associate";
    break;
default:
    cout<<"\a";
}
loop:
system("cls");
cout<<"\n Enter employee name :";
cin.ignore();
getline(cin,employeename);

cout<<"\n Enter employee id(max 8 characters) :";
cin>>employeeid;
if(employeeid.length() <=0 || employeeid.length()>8){
    cout<<"\n Enter id correctly !";
    getch();
    goto loop;
}
cout<<"\n Enter the age of employee :";
cin>>employeeage;
cout<<"\n Enter the years of work experience :";
cin>>workexp;
cout<<"\n Set the employees monthly paycheck :";
cin>>paycheck;


if(workexp>0){
    paycheck = paycheck + (workexp/10 * paycheck);
}
system("cls");
cout<<"Employee info :";
cout<<"\nName           :"<<employeename;
cout<<"\nID             :"<<employeeid;
cout<<"\nAge            :"<<employeeage;
cout<<"\nPosition       :"<<employeepos;
cout<<"\nWork experience:"<<workexp<<" years";
cout<<"\nMonthly Salary :"<<paycheck<<" TK";
cout<<"\nYearly Salary  :"<<paycheck*12<<" TK";
b=confirmationmenu("Do you want to confirm ? :");
if(b=="y"){
    file<<employeename<<":"<<employeeid<<":"<<employeeage<<":"<<employeepos<<":"<<workexp<<":"<<paycheck<<endl;
    cout<<"\nRecord Updated";

}
else if(b=="n"){
    cout<<"\nNo record updated";

}


file.close();
}


void Catalog::showemployee()
{
    string w,p;
    int i=1;
    ifstream file;
    file.open("employee.txt");
    if(!file.is_open()){
        cout<<"No employee data recorded currently";

    }
    else{
    cout<<"\n===========================================================\n";
    cout<<"|                     EMPLOYEE LIST                       |"<<endl;
    cout<<"===========================================================\n";
    while(getline(file,employeename,':')){
        getline(file,employeeid,':');
        getline(file,employeeage,':');
        getline(file,employeepos,':');
        getline(file,w,':');
        getline(file,p,'\n');
        cout<<" EMPLOYEE NAME   : "<<employeename<<endl;
        cout<<" EMPLOYEE ID     : "<<employeeid<<endl;
        cout<<" EMPLOYEE AGE    : "<<employeeage<<endl;
        cout<<" POSITION        : "<<employeepos<<endl;
        cout<<" EXPERIENCE      : "<<w<<" years"<<endl;
        cout<<" MONTHLY INCOME  : "<<p<<"TK"<<endl;
        cout<<" YEARLY INCOME   : "<<atoi(p.c_str())*12<<" TK"<<endl;
        cout<<"===========================================================\n";
    }
    }
    file.close();
}

void Catalog::removeitem(){
string n,i;
ifstream file;
ofstream tempfile;
file.open(filename.c_str());
tempfile.open("temp.txt",ios::app);
if(!file.is_open()){
    cout<<"No such product file ";
}
cout<<"\n\n\n\t\t\t\tEnter the product no. you wish to remove :";
cin>>n;
while(getline(file,prono,':'))
{
    getline(file,productname,':');
    getline(file,price,'\n');
    if(prono==n){
        system("cls");
        cout<<"\n\t\t\t\t"<<prono<<"."<<productname<<" : "<<price<<cur;

        getch();
        i=confirmationmenu("Do you wish to remove this product ? :");
        if(i=="y"){
            cout<<"\n\n\n\t\t\t\tProduct removed !!!";
            continue;

        }
        else if(i=="n"){
            cout<<"\n\n\n\t\t\t\tNo product removed !!";
            goto loop1;

        }
    }
loop1:
tempfile<<prono<<":"<<productname<<":"<<price<<endl;
}
file.close();
tempfile.close();
remove(filename.c_str());
rename("temp.txt",filename.c_str());
}



//**************************************************
//INITIALIZING
//**************************************************
string System::name;
string System::pass;
string System::id;
string System::filename;
string System::cur;
string System::paymethod;
int System::proindex;
int System::amount = 0;
int System::highcur =0;
int System::lowcur =0;
float System::workexp =0;
int System::paycheck=0;
//**************************************************
//COVER PAGE
//**************************************************



int System::open()
{

    char keyps = 0;
    int pointerps = 1;
    int maxps = 5;
    while(keyps!=13){
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
	cout<<"\t\t\t\t\t | PROHELIKA ONLINE SHOPPING SYSTEM |\n";
	cout<<"\t\t\t\t\t======================================\n\n\n";

	cout<<"\t\t\t\t  -------------------------------------------------\n";
	arrowpos(1,pointerps);cout<<"  |\t       1. LOGIN          \t\t  |\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	arrowpos(2,pointerps);cout<<"  |\t       2. REGISTER       \t\t  |\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	arrowpos(3,pointerps);cout<<"  |\t       3. FORGOT PASSWORD\t\t  |\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	arrowpos(4,pointerps);cout<<"  |\t       4. ADMIN PANEL     \t\t  |\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n";
	arrowpos(5,pointerps);cout<<"  |\t       5. EXIT \t\t\t\t  |\n";
	cout<<"\t\t\t\t  -------------------------------------------------\n\n";
	keyps = getch();

	if(keyps==80&&pointerps != maxps){
        pointerps++;
	}
	else if(keyps==72&&pointerps != 1){
        pointerps--;
	}else{
        pointerps=pointerps;
	}

    if(keyps==13){
        return pointerps;
    }


    }
    getch();

}
//**************************************************
//MAIN MENU
//**************************************************



int System::mainmenu()
{
    int keypos=0;
    int pointerpos = 1;
    int maxpos = 9;
    while(keypos != 13){
    system("CLS"); ///Clear screen function
    cout<<"\n\t\t\t\t\t ================================\n";
    cout<<"\t\t\t\t\t |\t    MAIN MENU           |";
    cout<<"\n\t\t\t\t\t ================================\n";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(1,pointerpos);cout<<"\t |\t1.MODIFY ACCOUNT         |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(2,pointerpos);cout<<"\t |\t2.  AMOUNT         |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(3,pointerpos);cout<<"\t |\t3.SHOW CATALOG           |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(4,pointerpos);cout<<"\t |\t4.SEARCH PRODUCTS        |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(5,pointerpos);cout<<"\t |\t5.SHOW DELIVERY INFO     |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(6,pointerpos);cout<<"\t |\t6.ADD NEW ORDER          |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(7,pointerpos);cout<<"\t |\t7.MODIFY ORDER INFO      |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(8,pointerpos);cout<<"\t |\t8.CANCEL ORDER           |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    arrowpos(9,pointerpos);cout<<"\t |\t9.LOG OUT                |";
    cout<<"\n\t\t\t\t\t  --------------------------------\n";
    keypos=getch();
    if(keypos==80 && pointerpos != maxpos){
        pointerpos++;
    }else if(keypos==72 && pointerpos != 1){
        pointerpos--;
    }else{
        pointerpos=pointerpos;
    }
    if(keypos == 13){
        return pointerpos;
    }
    }


    getch();

}

bool System::passexist(string p){
string id,s;
ifstream file;
int found = 0;
file.open("userdata.txt");

if(!file.is_open()){
    return false;
}
else{
while(getline(file,name,':'))
{
    getline(file,pass,':');
    getline(file,age,':');
    getline(file,num,':');
    getline(file,id,':');
    getline(file,s,'\n');
    if(p==pass){
        found=1;
    }

}
if(found==1){
    return true;
}
else{
    return false;
}
}
file.close();
}

bool System::idexists(string i){
string id,s;
int found = 0;
ifstream file;
file.open("userdata.txt");

if(!file.is_open()){
    return false;
}
else{
 while(getline(file,name,':'))
{
    getline(file,pass,':');
    getline(file,age,':');
    getline(file,num,':');
    getline(file,id,':');
    getline(file,s,'\n');
    if(i==id){
        found=1;
    }
}
if(found==1){
return true;
}else{
return false;
}
}
file.close();
}

bool System::checkname(string n){
string id,s;
ifstream file;
int found = 0;
file.open("userdata.txt");
if(!file.is_open()){
    return false;
}
else{
    while(getline(file,name,':')){
        getline(file,pass,':');
        getline(file,age,':');
        getline(file,num,':');
        getline(file,id,':');
        getline(file,s,'\n');
        if(name==n){
            found=1;
        }

    }
    if(found==1){
        return true;
    }else {
        return false;
    }
}
file.close();
}

//**************************************************
//CREATE ACCOUNT
//**************************************************
void System::createaccount(){
string p,q,n,g;
int i;
ofstream file;
file.open("userdata.txt",ios::app);
again:
system("CLS");
cout<<"\n\t\t\t\tENTER NAME :";              ///Ignoring the first character
getline(cin,n);                             ///Get full name
if(checkname(n)){
    cout<<"\n\t\t\t\tNAME ALREADY EXIST";
    getch();
    cin.ignore();
    goto again;
}
cout<<"\n\t\t\t\tENTER PASSWORD(MAX 4 CHARACTERS) :";
cin>>p;


if(p.length()>4){            ///Checking if password length is within 4 characters
    cout<<"\n\t\t\t\tMAX 4 CHARACTERS";
    getch();
    cin.ignore();
    goto again;
}
else if(passexist(p)){
    cout<<"\n\t\t\t\tPASSWORD ALREADY EXIST";
    getch();
    cin.ignore();
    goto again;
}

cout<<"\n\t\t\t\tENTER YOUR AGE:";
cin>>g;
cout<<"\n\t\t\t\tENTER YOUR MOBILE NUMBER:";
cin>>q;
if(q.length()>11){
    cout<<"\n\t\t\t\tINVALID NUMBER";
    getch();
    cin.ignore();
    goto again;
}
else if(q.length()<11){
    cout<<"\n\t\t\t\tINVALID NUMBER";
    getch();
    cin.ignore();
    goto again;
}
else if(q>="a"&& q<="z"|| q>="A"&& q<="Z"){
    cout<<"\n\t\t\t\tINVALID NUMBER";
    getch();
    cin.ignore();
    goto again;
}

cout<<"\n\tENTER YOUR VISA OR MASTERCARD NUMBER(MAX 12 CHARACTERS):";
cin>>id;
if(id.length()>12){
    cout<<"\n\t\t\t\tENTER 12 CHARACTER";
    getch();
    cin.ignore();
    goto again;
}
else if(id.length()<12){
    cout<<"\n\t\t\t\tENTER 12 CHARACTER";
    getch();
    cin.ignore();
    goto again;
}

else if(idexists(id)){
    cout<<"\n\t\t\t\tID ALREADY EXIST";
    getch();
    cin.ignore();
    goto again;
}

amount = 0;

file<<n<<":"<<p<<":"<<g<<":"<<q<<":"<<id<<":"<<amount<<endl;
file.close();


}
//**************************************************
//LOADING
//**************************************************
void System::loading(){
system("color 0b");

cout<<"\n\n\n\n\n\n\n\n\t\tPlease Wait While loading...\n\n";

char a=177,b=219;
cout<<"\t\t";
for(int i=0;i<=80;i++)

cout<<a;
cout<<"\r";
cout<<"\t\t";

for(int i=0;i<=80;i++){

    cout<<b;
    for(int j=0;j<=1e7;j++);
}
cout<<"\n\n\t\tPress Any Key To Continue...";
getch();
}

//**************************************************
//Loading 2
//**************************************************
void System::loading2(){
    cout<<"\t\t\t\t\t                  ##"<<endl;
    cout<<"\t\t\t\t\t               ########"<<endl;
    cout<<"\t\t\t\t\t          ##################"<<endl;
    cout<<"\t\t\t\t\t     ############################"<<endl;
    cout<<"\t\t\t\t\t#######################################"<<endl;
    cout<<"\n\t\t\t\t\t WELCOME TO THE PROJECT OF TEAM MEGABYTE\n"<<endl;;
    cout<<"\t\t\t\t\t#######################################"<<endl;
    cout<<"\t\t\t\t\t     ############################"<<endl;
    cout<<"\t\t\t\t\t          ##################"<<endl;
    cout<<"\t\t\t\t\t               ########"<<endl;
    cout<<"\t\t\t\t\t                  ##"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t======================================\n";
	cout<<"\t\t\t\t\t | PROHELIKA ONLINE SHOPPING SYSTEM |\n";
	cout<<"\t\t\t\t\t======================================\n\n\n";

    cout<<"\t\t\t\t\t**************************************"<<endl;
    cout<<"\t\t\t\t\t**************CREATED BY**************"<<endl;
    cout<<"\t\t\t\t\t*** BIVAS ***************** JIDAN ****"<<endl;
    cout<<"\t\t\t\t\t*** MAHIR ***************** SADIB ****"<<endl;
    cout<<"\t\t\t\t\t**************************************"<<endl;


getch();

}
//*************************************
//***************ADMIN PANEL************
//*************************************
void Catalog::admin(){
string username,userpass;
userpass = "";
char ch,b,c;
int a;
system("cls");
cout<<"\n";
    	cout<<"\t\t\t\t====================================================\n";
    	cout<<"\t\t\t\t|\t            ADMIN LOGIN              \t   |\n";
    	cout<<"\t\t\t\t====================================================\n\n";
    	cout << "\n\n\t\t\tPLEASE ENTER THE USER NAME: ";
    	cin >> username;
    	cout << "\n\n\t\t\tPLEASE ENTER THE USER PASSWORD: ";
    	ch = _getch();
    	while(ch != 13){
            userpass.push_back(ch);
            cout<<"*";
            ch = _getch();
    	}
    	if(username=="admin" && userpass=="pass")
        {
            do{

        a=adminmenu();

        if(a==1)
        {

        c='0'+itemenu();
        switch(c){
        case '1':
        catalog(0);
        getch();
        updatefile(filename,cur);
        break;
        case '2':
        catalog(0);
        removeitem();
        break;
        default:
            cout<<"\a";

        }
        getch();
        }

        else if(a==2)
        {
        string j,a;
        ifstream file2;
        file2.open("userdata.txt",ios::app);
        system("CLS");
        cout<<"\n===========================================================\n";
        cout<<"|                     CUSTOMER LIST                       |"<<endl;
        cout<<"===========================================================\n";
        while(getline(file2,j,':')){
        getline(file2,pass,':');
        getline(file2,age,':');
        getline(file2,num,':');
        getline(file2,id,':');
        getline(file2,a,'\n');
        cout<<" NAME         : "<<j<<endl;
        cout<<" AGE          : "<<age<<endl;
        cout<<" MOBILE NUMBER: "<<num<<endl;
        cout<<" CARD NUMBER  : "<<id<<endl;
        cout<<"===========================================================\n";
        }
        getch();
        }
        else if(a==3)
    {
        string n,i,p;
        system("CLS");
        ifstream file;
        file.open("delivery.txt");
        cout<<"\n===========================================================\n";
        cout<<"|                        ORDER LIST                       |"<<endl;
        cout<<"===========================================================\n";
        while(getline(file,n,':')){
            getline(file,i,':');
            getline(file,productname,':');
            getline(file,p,':');
            getline(file,cur,':');
            getline(file,paymethod,':');
            getline(file,deli,':');
            getline(file,day,':');
            getline(file,time,'|');
            getline(file,place,'\n');
        cout<<"\nCustomer name    :"<<n;
        cout<<"\nProduct name     :"<<productname;
        cout<<"\nPrice            :"<<p<<" "<<cur;
        cout<<"\nPayment method   :"<<paymethod;
        cout<<"\nDelivery Service :"<<deli;
        cout<<"\nDay of delivery  :"<<day;
        cout<<"\nTime of delivery :"<<time;
        cout<<"\nPlace to deliver :"<<place;

        cout<<"\n===========================================================\n";
    }
      file.close();
      getch();
    }
        else if(a==4){


        b='0'+emplyeemenu();
        switch(b){
        case '1':
            system("cls");
            addemployee();
            break;
        case '2':
            system("cls");
            showemployee();
            break;

        default:
            cout<<"\a";

        }
        getch();
        }
            }while(a!=5);{Logout();}
  }
   else
    {
     system("cls");
      cout<<"\n\n\n\t\tWRONG USERNAME AND PASSWORD OF ADMIN AND TRY AGAIN !!!";
    }

}
//**************************************************
//DELIVERY SERVICES
//**************************************************
void System::DeliveryServices(){
string n,s;
ifstream rfile;
rfile.open("deliservice.txt");

while(getline(rfile,n,':')){
    getline(rfile,s,'\n');
    cout<<"\n\t\t\t"<<n<<"."<<s<<endl;
}

rfile.close();
}

//**************************************************
//BUY PRODUCT
//**************************************************


void Catalog::BuyProduct(string f1,string c){
cur = c;
string s,n,i,a,j;
char k,f,b,q;
int p;
int m;
ifstream file1;
ifstream file2;
ofstream file4;
ofstream file5;

file1.open("userdata.txt");
file2.open(f1.c_str());
file5.open("temp.txt",ios::app);

if(!file1.is_open()){
    cout<<"Couldn't find user file";

}
if(!file2.is_open()){
    cout<<"Couldn't find product file";
}


while(getline(file1,n,':')){
        getline(file1,pass,':');
        getline(file1,age,':');
        getline(file1,num,':');
        getline(file1,id,':');
        getline(file1,a,'\n');
if(name.find(n,0)!= string::npos){
    cout<<"\n\n\t\tEnter list index to select product: ";
    cin>>s;



    while(getline(file2,prono,':')){

            getline(file2,productname,':');
            file2>>price;
        if(prono.find(s,0)!= string::npos){
            if(cur==" TK"){
            system("cls");
            cout<<"\n\n\n\t\t\t\tSelected product :\n\n";
            cout<<"\t\t\t\t"<<productname<<":"<<price<<" "<<" TK\n\n";
            cout<<"\t\t\t\tPress enter to continue...\n\n";
            getch();
            p = atoi(price.c_str());
            }
            else if(cur==" USD"){
            system("cls");
            cout<<"\n\n\n\t\t\t\tSelected product :\n\n";
            cout<<"\t\t\t\t"<<productname<<":"<<price<<" "<<cur<<"\n\n";
            p = atoi(price.c_str());
            p = p * 84.80;
            cout<<"\t\t\t\tPrice in taka :"<<p<<" "<<" TK\n\n";
            cout<<"\t\t\t\tPress enter to continue...\n\n";
            getch();
            }
            else if(cur==" CNY"){
            system("cls");
            cout<<"\n\n\n\t\t\t\tSelected product :\n\n";
            cout<<"\t\t\t\t"<<productname<<":"<<price<<" "<<cur<<"\n\n";
            p = atoi(price.c_str());
            p = p * 11.96;
            cout<<"\t\t\t\tPrice in taka :"<<p<<" "<<" TK\n\n";
            cout<<"\t\t\t\tPress enter to continue...\n\n";
            getch();
            }
            m = paymenu();
            if(m==1){
            paymethod = "Credit card";
            cout<<"\n\t\t\tYour amount :"<<a<<" TK";
            amount = atoi(a.c_str());
            if(amount >= p){
            amount = amount - p;
            cout<<"\n\t\t\tDeducted amount will be :"<<amount<<" TK";
            getch();
            i=confirmationmenu("Do you want to confirm ? :");
            break;
            }else{
                cout<<"\n\t\t\tPlease Deposit more amount";
                getch();
                goto loop1;
                }
            }
            else if(m==2){
                paymethod = "Cash on Delivery";
                goto loop3;
            }else{
                cout<<"\a";
            }
        }
    }

    if(i=="y"){
                loop3:
                    q='0'+deliveryservice();
                    switch(q){
                    case '1':
                    deli="DHL";
                    break;
                    case '2':
                    deli="Fed Ex";
                    break;
                    case '3':
                    deli="UPS";
                    break;
                    default:
                    cout<<"\a";
                    }

                    k='0'+deliverydays();

                    switch(k){
                    case '1':
                        day="Sunday";
                        break;
                    case '2':
                        day="Tuesday";
                        break;
                    case '3':
                        day="Thursday";
                        break;
                    case '4':
                        day="Saturday";
                        break;
                    default:
                        cout<<"\a";

                    }

                    f='0'+ timemenu();
                    switch(f){
                    case '1':
                        time = "9:30 AM";
                        break;
                    case '2':
                        time = "12:30 PM";
                        break;
                    case '3':
                        time = "3:30 PM";
                        break;
                    case '4':
                        time = "5:30 PM";
                        break;
                    default:
                        cout<<"\a";

                    }
                    system("cls");

                    b='0'+placemenu();
                    switch(b){
                    case '1':
                        place = "Uttara,Dhaka";
                        break;
                    case '2':
                        place = "Mirpur,Dhaka";
                        break;
                    case '3':
                        place = "Gulshan,Dhaka";
                        break;
                    default:
                        cout<<"\a";

                    }
                    system("cls");

                    cout<<"\t\t\t-------------------------------------------";
                    cout<<"\n\t\t\tYour Cart";
                    cout<<"\n\t\t\tName             :"<<name;
                    cout<<"\n\t\t\tProduct name     :"<<productname;
                    cout<<"\n\t\t\tPrice            :"<<price<<" "<<cur;
                    cout<<"\n\t\t\tPayment method   :"<<paymethod;
                    cout<<"\n\t\t\tDelivery Service :"<<deli;
                    cout<<"\n\t\t\tDay of delivery  :"<<day;
                    cout<<"\n\t\t\tTime of delivery :"<<time;
                    cout<<"\n\t\t\tDelivering to    :"<<place;
                    cout<<"\n\t\t\t-------------------------------------------";
                    getch();
                    j=confirmationmenu("Do you want to confirm ?:");
                    if(j=="y"){
                            proindex++;
                            stringstream ss;
                            ss<<amount;
                            a=ss.str();
                        file4.open("delivery.txt",ios::app);
                        file4<<name<<":"<<proindex<<":"<<productname<<":"<<price<<":"<<cur<<":"<<paymethod<<":"<<deli<<":"<<day<<":"<<time<<"|"<<place<<endl;
                        file4.close();
                        cout<<"\n\n\n\t\t\t\t THANKS FOR BUYING !";
                        goto loop1;
                    }else if(j=="n"){
                        cout<<"\n\n\n\t\t\t\t PLEASE COME AGAIN !";
                        goto loop1;

                    }




            }
        else if(i=="n"){
            cout<<"\n\n\n\t\t\t\t PLEASE COME AGAIN !";
            goto loop1;

        }else{

            system("cls");
            cout<<"\t\t\tWrong input";

            getch();
            goto loop1;
        }


}
loop1:
file5<<n<<":"<<pass<<":"<<age<<":"<<num<<":"<<id<<":"<<a<<endl;
}

file1.close();
file2.close();
file5.close();

remove("userdata.txt");
rename("temp.txt","userdata.txt");

}





//**************************************************
//PASS NAME
//**************************************************
void System::passname(string s){

    name=s;
}
//**************************************************
//PASS PASSWORD
//**************************************************
void System::passpassword(string n){

    pass=n;
}
void System::passid(string i){

   id=i;
}
void System::passnum(string u){
     num=u;
}
//**************************************************
//DISPLAY ACCOUNT
//**************************************************
void System::modify(){
string n,s,k,j,p;
int i;
ifstream infile;
ifstream infile1;
ofstream outfile;
ofstream outfile1;
infile.open("userdata.txt",ios::app);
infile1.open("delivery.txt");
if(!infile)
{
    cout<<"File could not be open";
    return;
}
outfile.open("temp.txt",ios::app);
outfile1.open("delitemp.txt",ios::app);
while(getline(infile,n,':')){
        getline(infile,pass,':');
        getline(infile,age,':');
        getline(infile,num,':');
        getline(infile,id,':');
        getline(infile,s,'\n');



if(n.find(name,0)!=string::npos){
        system("cls");

        cout<<"\n\n\n\n\t\t\t\t-------------------------------------------\n";
        cout<<"\t\t\t\t      ACCOUNT OVERVIEW "<<endl;
        cout<<"\t\t\t\tName   :"<<n<<endl;
        cout<<"\t\t\t\tAge    :"<<age<<endl;
        cout<<"\t\t\t\tNumber :"<<num<<endl;
        cout<<"\t\t\t\tAmount :"<<s<<endl;
        cout<<"\t\t\t\t-------------------------------------------";
        cin.ignore();
        getch();
i=modifymenu();
switch(i)
{
case 1:
    cout<<"\n\t\tENTER NEW NAME:";
              ///Ignoring the first character
    getline(cin,n);
    while(getline(infile1,k,':')){
    getline(infile1,j,':');
    getline(infile1,productname,':');
    getline(infile1,p,':');
    getline(infile1,cur,':');
    getline(infile1,paymethod,':');
    getline(infile1,deli,':');
    getline(infile1,day,':');
    getline(infile1,time,'|');
    getline(infile1,place,'\n');

if(name.find(k,0)!= string::npos){
    k=n;
    }
    outfile1<<k<<":"<<j<<":"<<productname<<":"<<p<<":"<<cur<<":"<<paymethod<<":"<<deli<<":"<<day<<":"<<time<<"|"<<place<<endl;

    }
    infile1.close();
    outfile1.close();
    remove("delivery.txt");
    rename("delitemp.txt","delivery.txt");
    name = n;
    cout<<"\n\t\tRECORD UPDATED";
    break;
    case 2:
    cout<<"\n\t\tENTER NEW PASSWORD:";
    cin>>pass;
    cout<<"\n\t\tRECORD UPDATED";
    break;
    case 3:
    cout<<"\n\t\tENTER NEW AGE:";
    cin>>age;
    cout<<"\n\t\tRECORD UPDATED";
    break;
    case 4:
    cout<<"\n\t\tENTER NEW MOBILE NUMBER:";
    cin>>num;
    cout<<"\n\t\tRECORD UPDATED";
    break;
    case 5:
    cout<<"\n\t\tENTER NEW CARD NUMBER:";
    cin>>id;
    cout<<"\n\t\tRECORD UPDATED";
    break;
    default:
        cout<<"\n\t\tINVALID OPTION"<<endl;



}
}
outfile<<n<<":"<<pass<<":"<<age<<":"<<num<<":"<<id<<":"<<s<<endl;


}





infile.close();

outfile.close();

remove("userdata.txt");
rename("temp.txt","userdata.txt");




}

//**************************************************
//DEPOSIT AMOUNT
//**************************************************
void System::depositamnt()
{
    string n,s,i;
    string a;
    ifstream opfile;
    ofstream wfile;
    opfile.open("userdata.txt");
    wfile.open("temp.txt",ios::app);
    if(!opfile.is_open()){
        cout<<"\nCouldn't open file";
    }
    cout<<"\n\t\t\t\t\t-------------------------------\n";
    cout<<"\t\t\t\t\t|       DEPOSIT MENU          |\n";
    cout<<"\t\t\t\t\t-------------------------------\n";
    cout<<"\n\t\t\t\t\tEnter your credit no. :";
    cin>>s;

    while(getline(opfile,n,':')){
        getline(opfile,pass,':');
        getline(opfile,age,':');
        getline(opfile,num,':');
        getline(opfile,id,':');
        getline(opfile,i,'\n');
    if(n.find(name,0)!=string::npos){
    if(id==s){
        cout<<"\n\t\t\t\t\tYour current amount :"<<i<<" TK";
        amount = atoi(i.c_str());               //const char*
        cout<<"\n\n\t\t\t\t\tEnter new amount(Max 5000000 TK):";
        cin>>a;
        if(a>="a"&&a<="z"||a>="A"&&a<="Z"){
            cout<<"\n\t\t\t\t\tEnter amount correctly !!";
            stringstream ss;
            ss<<amount;
            i=ss.str();
            goto loop;
        }else if(atoi(a.c_str())>5000000 || amount>5000000){
            cout<<"\n\t\t\t\t\tMax amount exceeded !!";
            stringstream ss;
            ss<<amount;
            i=ss.str();
            goto loop;

        }
        else{
        amount = amount + atoi(a.c_str());
        stringstream ss;
        ss<<amount;
        i=ss.str();
        cout<<"\n\t\t\t\t\tAmount deposited sucessfully !!!";
        goto loop;
        }
    }else{
    cout<<"\n\t\t\t\t\tInvalid credit id\n\n";

    }
    }

    loop:
    wfile<<n<<":"<<pass<<":"<<age<<":"<<num<<":"<<id<<":"<<i<<endl;

    }
    opfile.close();
    wfile.close();
    remove("userdata.txt");
    rename("temp.txt","userdata.txt");

}






//**************************************************
//SHOW CATALOG
//**************************************************

void Catalog::catalog(int b){
    int n,x,a;
    a=b;
    n=country();
    switch(n)
    {
        case 1:
    //*********************************************************
                            //BANGLADESH
    //*********************************************************


    x=productype("BANGLADESH");
    if(x==1)
    {


        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MOBILE PHONES"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("mobileb.txt"," TK");
        }
        else if(a==1){
        Product("mobileb.txt"," TK","MOBILE PHONES");

        }


}
else if(x==2)
    {


        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING LAPTOPS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("laptopb.txt"," TK");
        }
        else if(a==1){
        Product("laptopb.txt"," TK","LAPTOPS");

        }

        }


 else if(x==3)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MONITORS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";

        Product("monitorb.txt"," TK");
        }
        else if(a==1){
        Product("monitorb.txt"," TK","MONITORS");
        }

        }

else if(x==4)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING TV"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";

        Product("tvb.txt"," TK");
        }
        else if(a==1){
        Product("tvb.txt"," TK","TV");
        }


        }
    break;

        case 2:
    //***************************************************************
                            //CHINA
    //*************************************************************

    x=productype("CHAINA");
    if(x==1)
    {


        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MOBILE PHONES"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";;

        Product("mobilec.txt"," CNY");
        }
        else if(a==1){
        Product("mobilec.txt"," CNY","MOBILE PHONES");
        }
        }

 else if(x==2)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING LAPTOPS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("laptopc.txt"," CNY");
        }
        else if(a==1){
        Product("laptopc.txt"," CNY","LAPTIOPS");
        }

        }


 else if(x==3)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MONITORS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("monitorc.txt"," CNY");
        }
        else if(a==1){
        Product("monitorc.txt"," CNY","MONITORS");
        }
        }
else if(x==4)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING TV"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("tvc.txt"," CNY");
        }else if(a==1){
        Product("tvc.txt"," CNY","TV");
        }
        }
        //***********************************************************

    break;
        case 3:

    //*************************************************************
                        //AMERICA
    //************************************************************
   system("CLS");
   x=productype("AMERICA");
    if(x==1)
    {   if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MOBILE PHONES"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("mobilea.txt"," USD");
        }else if(a==1){
        loop:
        Product("mobilea.txt"," USD","MOBILE PHONES");
        }

        }

 else if(x==2)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING LAPTOPS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("laptopa.txt"," USD");
        }
        else if(a==1){
        Product("laptopa.txt"," USD","LAPTOPS");

        }
        }


 else if(x==3)
    {

        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING MONITORS"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("monitora.txt"," USD");
        }
        else if(a==1){
        Product("monitora.txt"," USD","MONITORS");
        }


    }
else if(x==4)
    {
        if(a==0){
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t======================================\n";
        cout<<"\t\t\t\t\t\tSHOWING TV"<<" : \n";
        cout<<"\t\t\t\t\t======================================\n";
        Product("tva.txt"," USD");
        }
        else if(a==1){
        Product("tva.txt"," USD","TV");

        }

        }
    break;

    default:

            cout<<"\a";

    }

    //*************************************************************


}


//**************************************************
//SHOW DELIVERY INFO
//**************************************************
void System::deliveryinfo(){
    string s,n,p;
    ifstream file;
    file.open("delivery.txt");
    cout<<"\n\t\t\t\tShowing "<<name<<" Cart :";
    if(!file.is_open()){
        cout<<"\n\t\t\tNo Products available in cart. Please purchase a product !!";

    }

    while(getline(file,s,':')){
            getline(file,n,':');
            getline(file,productname,':');
            getline(file,p,':');
            getline(file,cur,':');
            getline(file,paymethod,':');
            getline(file,deli,':');
            getline(file,day,':');
            getline(file,time,'|');
            getline(file,place,'\n');

        if(name.find(s,0)!=string::npos){
            cout<<"\n\t\t\tOrder no "<<n<<" -----------------------";

                    cout<<"\n\t\t\tProduct name     :"<<productname;
                    cout<<"\n\t\t\tPrice            :"<<p<<" "<<cur;;
                    cout<<"\n\t\t\tPayment method   :"<<paymethod;
                    cout<<"\n\t\t\tDelivery Service :"<<deli;
                    cout<<"\n\t\t\tDay of delivery  :"<<day;
                    cout<<"\n\t\t\tTime of delivery :"<<time;
                    cout<<"\n\t\t\tDelivering to    :"<<place;
            cout<<"\n\t\t\t---------------------------------------";
        }

    }
file.close();
}


void Catalog::show_and_buyproduct(){
catalog(0);
BuyProduct(filename,cur);


}

void Catalog::search_and_buyproduct(){
catalog(1);
BuyProduct(filename,cur);
}
//**************************************************
//SEARCH PRODUCTS
//**************************************************



void Catalog::neworder(){
string n,i,p,k;
int a,b;
ifstream file;

file.open("delivery.txt");


cout<<"\n\t\t\tCurrent orders being delivered :";
if(!file.is_open()){
    cout<<"\n\t\t\tNo orders currently";

}
while(getline(file,n,':'))
{
            getline(file,i,':');
            getline(file,productname,':');
            getline(file,p,':');
            getline(file,cur,':');
            getline(file,paymethod,':');
            getline(file,deli,':');
            getline(file,day,':');
            getline(file,time,'|');
            getline(file,place,'\n');
if(name.find(n,0) != string::npos){

cout<<"\n\t\t\t--------------------------------";
cout<<"\n\t\t\tOrder no "<<i;
cout<<"\n\t\t\tPoduct name :"<<productname;
cout<<"\n\t\t\t---------------------------------";

}
}
getch();
k=confirmationmenu("Do you want to order more products ?:");
if(k=="y"){
    system("cls");
    cout<<"\t\t\tEnter the number of products you want to order (max 3 at a time):";
    cin>>a;
    if(a<=3){

        for(b=1;b<=a;b++){
            system("cls");
            cout<<"\n\t\t\tFor "<<b<<" no "<<" product";
            show_and_buyproduct();
            getch();
            Sleep(100);

        }
    }else{
        cout<<"\n\t\t\tMax number of products crossed";
    }

}

}
void System::modifyorder(){
string n,i,p,s,j,id,k;
int q,b,d,c,f,y;

char a;
ifstream file;
ifstream file2;
ofstream file1;
ofstream file3;
    file.open("delivery.txt");

cout<<"\n\t\t\tCurrent orders being delivered :";
//if(!file.is_open()){
//    cout<<"\nNo orders currently";
//
//}
file1.open("delitemp.txt",ios::app);

deliveryinfo();
cout<<"\n\t\t\tEnter the order index to select product :";
cin>>k;
while(getline(file,n,':'))
{
            getline(file,i,':');
            getline(file,productname,':');
            getline(file,p,':');
            getline(file,cur,':');
            getline(file,paymethod,':');
            getline(file,deli,':');
            getline(file,day,':');
            getline(file,time,'|');
            getline(file,place,'\n');
if(n.find(name,0) != string::npos){
if(i.find(k,0)!= string::npos){
    system("cls");
cout<<"\n\t\t\t--------------------------------";
cout<<"\n\t\t\tOrder no "<<i;
cout<<"\n\t\t\tPoduct name      :"<<productname;
cout<<"\n\t\t\tPrice            :"<<p<<" "<<cur;
cout<<"\n\t\t\tPayment method   :"<<paymethod;
cout<<"\n\t\t\tDelivery Service :"<<deli;
cout<<"\n\t\t\tDay of delivery  :"<<day;
cout<<"\n\t\t\tTime of delivery :"<<time;
cout<<"\n\t\t\tPlace to deliver :"<<place;
cout<<"\n\t\t\t---------------------------------";
getch();

a='0'+modifyordermenu();
switch(a){
case '1':
    system("cls");
    file2.open("userdata.txt");
    file3.open("temp.txt",ios::app);
    b=paymenu();
    while(getline(file2,j,':')){
            getline(file2,pass,':');
            getline(file2,age,':');
            getline(file2,num,':');
            getline(file2,id,':');
            getline(file2,s,'\n');
        if(name.find(j,0)!=string::npos){
            amount =  atoi(s.c_str());

    if(b==1){
        if(paymethod == "Cash on Delivery"){
            paymethod = "Credit card";
            if(cur == " TK"){
                q = atoi(p.c_str());

            }else if(cur == " CNY" ){
                q = atoi(p.c_str());
                q = q * 11.96;
            }else if(cur == " USD"){
                q = atoi(p.c_str());
                q = q * 84.80;
            }
            cout<<"\n\t\t\tYour Current amount:"<<amount<<" TK";
            cout<<"\n\t\t\tPrice of product :"<<p<<cur;
            amount = amount - q;
            cout<<"\n\t\t\tAmount to be deducted :"<<q<<" TK";
            cout<<"\n\t\t\tUpdated amount will be :"<<amount<<" TK";
        }else if(paymethod=="Credit card"){
            paymethod="Credit card";
            cout<<"\n\t\t\tYou already paid for this product";
        }
        }

    else if(b==2){
        if(paymethod =="Credit card" ){
            paymethod="Cash on Delivery";
                 if(cur == " TK"){
                q = atoi(p.c_str());
            }else if(cur == " CNY" ){
                q = atoi(p.c_str());
                q = q * 11.96;
            }else if(cur == " USD"){
                q = atoi(p.c_str());
                q = q * 84.80;
            }
            cout<<"\n\t\t\tYour Current amount:"<<amount<<" TK";
            cout<<"\n\t\t\tPrice of product :"<<p<<cur;
            amount = amount + q;
            cout<<"\n\t\t\tAmount to be added :"<<q<<" TK";
            cout<<"\n\t\t\tUpdated amount will be :"<<amount<<" TK";
        }else if(paymethod=="Cash on Delivery"){
            paymethod="Cash on Delivery";
            cout<<"\n\t\t\tIt's already on Cash on Delivery mode";
        }

        }
            stringstream ss;
            ss<<amount;
            s = ss.str();

        }
        file3<<j<<":"<<pass<<":"<<age<<":"<<num<<":"<<id<<":"<<s<<endl;




    }
        file2.close();
        file3.close();
        remove("userdata.txt");
        rename("temp.txt","userdata.txt");
        cout<<"\n\t\t\tRecord Updated";
        break;
case '2':

    d=deliveryservice();
    if(d==1){
        deli = "DHL";
    }else if(d==2){
        deli = "Fed Ex";
    }else if(d==3){
        deli = "UPS";
    }else{
        cout<<"\a";
    }
    cout<<"\n\t\t\tRecord Updated";
    break;

case '3':
    system("cls");

    c=deliverydays();
    if(c==1){
        day = "Sunday";
    }else if(c==2){
        day = "Tuesday";
    }else if(c==3){
        day = "Thursday";
    }else if(c==4){
        day = "Saturday";
    }else{
        cout<<"\a";
    }
    cout<<"\nRecord Updated";
    break;
case '4':

    f=timemenu();

    if(f==1){
    time = "9:30 AM";
    }
    else if(f==2){


    time = "12:30 PM";
    }
    else if(f==3){
    time = "3:30 PM";
    }
    else if(f==4){
    time = "5:30 PM";
    }
    else{
        cout<<"\a";
    }

cout<<"\nRecord Updated";
break;
case '5':
y=placemenu();
if(y==1){
place = "Uttara,Dhaka";
}
else if(y==2){
place = "Mirpur,Dhaka";
}
else if(y==3){
place = "Gulshan,Dhaka";
}
else{
cout<<"\a";
}

cout<<"\n\t\t\tRecord Updated";
break;

default:
        cout<<"\a";
}


}
}

file1<<n<<":"<<i<<":"<<productname<<":"<<p<<":"<<cur<<":"<<paymethod<<":"<<deli<<":"<<day<<":"<<time<<"|"<<place<<endl;
}
file.close();

file1.close();

remove("delivery.txt");
rename("delitemp.txt","delivery.txt");

}



void System::cancelorder(){
string n,i,p,m,f,j,s,c,n1,p1,i2;
int q;
char k;

ifstream file;
ofstream file1;
ifstream file2;
ofstream file3;
file.open("delivery.txt");
file1.open("delitemp.txt",ios::app);



    system("cls");
    deliveryinfo();
    cout<<"\n\t\t\tEnter the product index you wish to remove :";
    cin>>m;
    file2.open("userdata.txt");
    file3.open("temp.txt",ios::app);
    while(getline(file,n,':'))
{
            getline(file,i,':');
            getline(file,productname,':');
            getline(file,p,':');
            getline(file,cur,':');
            getline(file,paymethod,':');
            getline(file,deli,':');
            getline(file,day,':');
            getline(file,time,'|');
            getline(file,place,'\n');
        if(n.find(name,0)!= string::npos){
            proindex = atoi(i.c_str());
        }
    if(name ==n && i==m){

            system("cls");
cout<<"\n\t\t\t--------------------------------";
cout<<"\n\t\t\tOrder no "<<i;
cout<<"\n\t\t\tPoduct name      :"<<productname;
cout<<"\n\t\t\tPrice            :"<<p<<" "<<cur;
cout<<"\n\t\t\tPayment method   :"<<paymethod;
cout<<"\n\t\t\tDelivery Service :"<<deli;
cout<<"\n\t\t\tDay of delivery  :"<<day;
cout<<"\n\t\t\tTime of delivery :"<<time;
cout<<"\n\t\t\tPlace to deliver :"<<place;
cout<<"\n\t\t\t---------------------------------";
    getch();
    f=confirmationmenu("Do you want to confirm ?:");
    if(f=="y"){
        while(getline(file2,j,':')){
            getline(file2,pass,':');
            getline(file2,age,':');
            getline(file2,num,':');
            getline(file2,id,':');
            getline(file2,s,'\n');
        if(name.find(j,0)!=string::npos){
            amount =  atoi(s.c_str());
            if(paymethod=="Credit card"){
            if(cur == " TK"){
                q= atoi(p.c_str());

            }else if(cur == " CNY" ){
                q = atoi(p.c_str());
                q = q * 11.96;
            }else if(cur == " USD"){
                q = atoi(p.c_str());
                q =  q* 84.80;
            }
            amount = amount + q;
            cout<<"\n\t\t\tAmount updated !!";
            }
            stringstream ss;
            ss<<amount;
            s = ss.str();

        }
                file3<<j<<":"<<pass<<":"<<age<<":"<<num<<":"<<id<<":"<<s<<endl;


        }
        file2.close();
        file3.close();
        remove("userdata.txt");
        rename("temp.txt","userdata.txt");

        cout<<"\n\t\t\tOrder canceled sucessfully";


        continue;

    }else if(f=="n"){
        file2.close();
        file3.close();
        remove("temp.txt");
         cout<<"\n\t\t\tOrder wasn't canceled!!";
        goto loop1;

    }


    }
    loop1:
    file1<<n<<":"<<i<<":"<<productname<<":"<<p<<":"<<cur<<":"<<paymethod<<":"<<deli<<":"<<day<<":"<<time<<"|"<<place<<endl;



}
file.close();
file1.close();
remove("delivery.txt");
rename("delitemp.txt","delivery.txt");








}







//***********************************************************
//SIGN IN
//***********************************************************

bool System::signin(){
string s, j,m,p,q;
char ch;
string n ="";
string user,pass;
int i,k=0;
int found = 0;
System sys1;
ifstream file;
ifstream file1;
file.open("userdata.txt");
file1.open("delivery.txt");
if(!file1.is_open()){
    proindex = 0;

}
if(!file.is_open()){
    cout<<"\n\n\t\t\t\t USER DOESNOT EXIST";
    getch();
    return false;

}

else{
    cout<<"\n\n\n\n\n\n\t\t\t\tENTER USER NAME :";
    getline(cin,s);
    cout<<"\n\n\t\t\t\tENTER PASSWORD :";
    ch = _getch();

    while(ch!=13){
        n.push_back(ch);
        cout<<"*";
        ch = _getch();
    }
    verify();
sys1.passname(s);
sys1.passpassword(n);
while(!file.eof()){
    getline(file,user,':');
    getline(file,pass,':');
    getline(file,age,':');
    getline(file,num,':');
    getline(file,id,':');
    getline(file,q,'\n');
    if(user==s){
        if(user.length()==s.length()){

            if(pass==n)
                {
            found = 1;
            }
        }
    }
}
 proindex = 0;
while(getline(file1,j,':'))
{
getline(file1,m,':');
getline(file1,productname,':');
getline(file1,p,':');
getline(file1,cur,':');
getline(file1,paymethod,':');
getline(file1,deli,':');
getline(file1,day,':');
getline(file1,time,'|');
getline(file1,place,'\n');
    if(name.find(j,0)!= string::npos){
        k = atoi(m.c_str());
        proindex = k;
}
}


file.close();
file1.close();
if(found == 1){
system("cls");
cout<<"\n\n\n\n\n\t\t\t\tLOGIN SUCESSFUL\n\n\n";
getch();
cout<<"\t\t\t\tWELCOME "<<s<<"\n";
getch();
return true;
}else{

return false;
}


}
}






















//**************************************************************
//MAIN FUNCTION
//***********************************************************
int main()
{
char a;
int k;
///Main Loop
Catalog pro1;         ///Creating system object
system("CLS");      ///Clearing screen
pro1.loading();
system("cls");
pro1.loading2();

do{

///calling open function
loop:
system("cls");
a='0'+pro1.open();


system("CLS");
switch(a){
case '1':
    if(pro1.signin()){

           char b;
            do{


    Catalog pro;
   b = '0'+pro.mainmenu();


    system("CLS");
    switch(b){
case '1':
    pro.modify();
    getch();
    break;
case '2':
    pro.depositamnt();
    getch();
    break;
case '3':
    pro.show_and_buyproduct();
    getch();
    break;
case '4':
    pro.search_and_buyproduct();
    getch();
    break;
case '5':
    pro.deliveryinfo();
    getch();
    break;
case '6':
    pro.neworder();
    getch();
    break;
case '7':
    pro.modifyorder();
    getch();
    break;
case '8':
    pro.cancelorder();
    getch();
    break;
case '9':
    pro.Logout();
    goto loop;

default:
    cout<<"\a";
    }
    }while(b!='\0');
}else{
    system("cls");
    cout<<"\n\n\t\t\t\tUSER NAME OR PASSWORD INVALID";
    getch();
    break;

}

case '2':
    pro1.createaccount();
    pro1.registar();
    getch();
    break;
case '3':
    pro1.forgotpass();
    getch();
    break;
case '4':
    pro1.admin();
    getch();
    break;
case '5':
    cout<<"\n\n\n\t\t\t\tTHANKS FOR USING PROHELIKA ONLINE SHOPPING SYSTEM\n\n\n";
    return 0;
    break;
default:
    cout<<"\a";
}

}while(a!='\0');

return 0;

}
