#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
using namespace std;
class Employee
 { double empno,tp;
   char name[20],loaname[100];
   float salary,bonus,epf,ppf,tf,gramt,amnt,taxg,msalary,losspy,gain,gaintax;
   float TAX,incm,taxg1,taxg2,taxg3,pcntm,pcnta,Tb;
   public:
   Employee() {bonus=0.0; gramt=0.0;}
   char any;


   void inst(int m)
     { if(m==0)
	 {cout<<"Enter Employee no.                     : ";         cin>>empno;
	  cout<<"Enter Name                             : ";         gets(name);
	 }
       else if(m==1)
	      { cout<<"\n---------------------------------------------------------------------------\n";
		cout<<"Name: "<<name<<setw(50)<<"Emp. no.: "<<empno<<endl;
		cout<<"---------------------------------------------------------------------------\n";
		cout<<"\nEnter NEW details :- \n";
	      }

       cout<<"Enter Salary per month                 : ";            cin>>msalary;
       salary=(msalary*12);
       taxg=salary;

       cout<<"Got any Bonus(Y/N)                     : ";            cin>>any;
       any=toupper(any);
       if(any=='Y')
	 { cout<<"-> Enter amount                        : ";        cin>>bonus;
	 }
       taxg=(taxg+bonus);
       Tb=taxg;


       cout<<"Have taken any loan(Y/N)               : ";            cin>>any;
       any=toupper(any);
       if(any=='Y')
	 { int p=0;
	   cout<<"-> Name your loan                      : ";        gets(loaname);
	   do
	    { if(p!=0)
		{cout<<endl<<pcntm<<" % is not valid.........Try again\n\n";
		}
	      cout<<"-> Rate of interest(%) per annum       : ";     cin>>pcntm;
	      p++;
	    }while(pcntm>100);
	   losspy=(salary*pcntm)/100;
	 }
       taxg=(taxg-losspy);
       taxg1=taxg;


       cout<<"Do you have any Fixed Deposit(Y/N)     : ";            cin>>any;
       any=toupper(any);
       if(any=='Y')
	 { int p=0;
	   cout<<"-> Enter time period(in years)         : ";        cin>>tp;
	   cout<<"-> Enter amount                        : ";        cin>>amnt;
	   do
	   { if(p!=0)
	       { cout<<endl<<pcnta<<" % is not valid.........Try again\n\n";
	       }
	     cout<<"-> Rate of interest(%) per annum       : ";      cin>>pcnta;
	     p++;
	   }while(pcnta>100);
	   gain=(amnt*pcnta)/100;
	   if(tp>2)
	     { gaintax=(gain*5)/100;
	     }
	 }
       taxg=(taxg+gaintax);
       taxg2=taxg;


       cout<<"Want to show any savings(Y/N)          : ";            cin>>any;
       any=toupper(any);
       if(any=='Y')
	 { int w=0;
	   cout<<"\n\t\tDeduction Managment System\n";
	   cout<<"\nNote: Aggregate amount deductible shall not exceed 1,50,000 rupees\n";
	   cout<<"CLICK to continue...\n\n";
	   getch();
	   do
	    {if(w!=0)
	       {cout<<"\n\t\t       WARNING !!!\n\n";
		cout<<"Rs "<<gramt<<" is more than 1,50,000 rupees\n";
		cout<<"Want to enter again(Y/N)               : ";   cin>>any;
		any=toupper(any);
		if(any=='Y')
		  { w=0;
		    cout<<endl;
		  }
		else{ gramt=0;
		      cout<<"\nSavings shown by you will NOT be counted\n";
		      cout<<"CLICK to continue...\n";
		      getch();
		    }
	       }
	     if(w==0)
	       { cout<<"-> Employee Provident fund(if any)     : ";  cin>>epf;
		 cout<<"-> Public Provident fund(if any)       : ";  cin>>ppf;
		 cout<<"-> Tuition fee(if any)                 : ";  cin>>tf;
		 gramt=epf+ppf+tf;
	       }
	     w++;
	    }while(gramt>150000);
	 }
       taxg=taxg-gramt;
       taxg3=taxg;


       if(taxg<=280000)
	 {TAX=0;
	  incm=taxg;
	 }
       else{ if(taxg<=500000)
	       {taxg=taxg-280000;
		TAX=(taxg*10)/100;
		incm=taxg+280000-TAX;
	       }
	     else{ if(taxg<=1000000)
		     { taxg=taxg-500000;
		       TAX=(taxg*20)/100;
		       TAX=TAX+22000;
		       incm=taxg+500000-TAX;
		     }
		   else{ taxg=taxg-1000000;
			 TAX=(taxg*30)/100;
			 TAX=TAX+22000+100000;
			 incm=taxg+1000000-TAX;
		       }
		 }
	   }
     }


   void disp()
      { cout<<"Name: "<<name<<setw(50)<<"Emp. no.: "<<empno<<endl<<endl;
	cout<<"Details of salary paid and any"<<setw(39)<<"INR"<<endl;
	cout<<"other income and tax deducted\n";

	cout<<endl<<"1. Gross Salary\n";
	cout<<"   (a) Salary as per provisions"<<setw(40)<<salary<<endl;
	cout<<"   (b) Profits in lieu of salary(BONUS)"<<setw(32)<<bonus;
	cout<<endl<<"   (c) Total"<<setw(59)<<Tb<<endl;

	cout<<endl<<"2. Less:\n";
	cout<<"   Allowance to the loan: "<<loaname<<endl;
	cout<<"   Rate of interest: "<<pcntm<<"%"<<endl;
	cout<<"   Interest paid"<<setw(55)<<losspy<<endl;

	cout<<endl<<"3. Balance(1-2)"<<setw(56)<<taxg1<<endl;

	cout<<endl<<"4. Add:\n";
	cout<<"   Income gained from: fixed deposit(FD)\n";
	cout<<"   Time period: "<<tp<<" years\n";
	cout<<"   Rate of interest: "<<pcnta<<" %"<<endl;
	cout<<"   FD Amount"<<setw(59)<<amnt<<endl;
	cout<<"   Interest recieved"<<setw(51)<<gaintax<<endl;

	cout<<endl<<"5. Balance(3+4)"<<setw(56)<<taxg2<<endl;
    
	cout<<endl<<"6. Deductions:\n";
	cout<<"   (a) Employee Provident Fund"<<setw(41)<<epf<<endl;
	cout<<"   (b) Public Provident Fund"<<setw(43)<<ppf<<endl;
	cout<<"   (c) Tuition fee"<<setw(53)<<tf<<endl;
	cout<<"   (d) Total"<<setw(59)<<gramt<<endl;

	cout<<endl<<"7. Total Income(5-6)"<<setw(51)<<taxg3<<endl;

	cout<<endl<<"8. Tax on total income"<<setw(49)<<TAX<<endl;

	cout<<"---------------------------------------------------------------------------\n";
      }
   int retemp()
      { return empno;
      }
 };


void insert()
    { int n;
      Employee data[20];
      do
       { cout<<"\nEnter no. of registrations (<=10) you want to have: ";
	 cin>>n;
       }while(n>10);
      fstream f;
      f.open("employee.dat",ios::binary|ios::app|ios::out);
      for(int i=0;i<n;i++)
	 { cout<<"\n# Enter data for "<<i+1<<" Employee\n";
	   data[i].inst(0);
	   f.write((char*)&data[i],sizeof(data[i]));
	 }
      cout<<"\n\t\t\tData has been entered........";
      f.close();
      getch();
    }

void display()
   { Employee E;
     fstream f;
     int i=0,x=1,Emp;
     f.open("employee.dat",ios::binary|ios::in);
     cout<<"\nEnter Employee no.: ";
     cin>>Emp;
     while(f.read((char*)&E,sizeof(E)))
	  { x=0;
	    i++;
	    if(E.retemp()==Emp)
	      { cout<<"---------------------------------------------------------------------------\n";
		E.disp();
		x++;
		break;
	      }
	  }
     if(i==0)
       { cout<<"\n\t\t\tNo Details have been Found\n";
       }
     if(x==0)
       { cout<<"\nEmployee no. "<<Emp<<" do NOT exist"<<endl;
       }
     f.close();
     getch();
   }

void search(int Emp)
  { Employee E;
    fstream f;
    int i=0;
    f.open("employee.dat",ios::binary|ios::in);
    while(f.read((char*)&E,sizeof(E)))
	 { if(E.retemp()==Emp)
	     { cout<<"\nSearch Complete...\n";
	       cout<<"CLICK to continue...\n"<<endl;
	       getch();
	       cout<<"---------------------------------------------------------------------------\n";
	       E.disp();
	       i++;
	     }
	 }
    if(i==0)
      {cout<<"\nSEARCH FAILED........\n";
      }
    f.close();
    getch();
  }

void delet(int Emp)
     { Employee E;
       fstream f1,f2;
       int i=0;
       f1.open("employee.dat",ios::binary|ios::out|ios::in);
       f2.open("temp.dat",ios::binary|ios::out|ios::in);
       while(f1.read((char*)&E,sizeof(E)))
	    { if(E.retemp()==Emp)
		{ cout<<"\nEmployee Found\n";
		  cout<<"CLICK to continue...\n";
		  getch();
		  i++;
		  cout<<"\n\t\t\tDetails has been deleted........\n";
		}
	      if(E.retemp()!=Emp)
		{ f2.write((char*)&E,sizeof(E));
		}
	    }
       if(i==0)
	 { cout<<"\nEmployee no. "<<Emp<<" do NOT exist"<<endl;
	 }
       f1.close();
       f2.close();
       remove("employee.dat");
       rename("temp.dat","employee.dat");
       getch();
     }


void modify(int Emp)
    { Employee E;
      fstream f;
      int found=0,m=1,i=0;
      f.open("employee.dat",ios::binary|ios::in|ios::out);
      while(f.read((char*)&E,sizeof(E)) && found==0)
	   { if(E.retemp()==Emp)
	       { cout<<"\nEmployee Found\n";
		 cout<<"CLICK to continue...\n";
		 getch();
		 E.inst(m);
		 cout<<"\n\t\t\tDetails has been entered........";
		 int pos= (-1*sizeof(E));
		 f.seekp(pos,ios::cur);
		 f.write((char*)&E,sizeof(E));
		 found=1;
		 i++;
	       }
	   }
      if(i==0)
	{ cout<<"\nEmployee no. "<<Emp<<" do NOT exist"<<endl;
	}
      getch();
    }


void main()
{ clrscr();
  int ch,Emp;
  do
   { cout<<"\nMain Menu\n";
     cout<<"1. Register Employee Details\n";
     cout<<"2. Show Details of Salary paid and Tax Deducted for an Employee\n";
     cout<<"3. Search Employee Details\n";
     cout<<"4. Delete Employee\n";
     cout<<"5. Modify Employee Details\n";
     cout<<"6. EXIT\n";
     cout<<"Enter your choice: ";
     cin>>ch;
     switch(ch)
	   { case 1 : insert();
		      break;

	     case 2 : display();
		      break;

	     case 3 : cout<<"\nEnter Employee no. you want to search: ";
		      cin>>Emp;
		      search(Emp);
		      break;

	     case 4 : cout<<"\nEnter Employee no. you want to delete: ";
		      cin>>Emp;
		      delet(Emp);
		      break;

	     case 5 : cout<<"\nEnter Employee no. you want to modify: ";
		      cin>>Emp;
		      modify(Emp);
		      break;

	     case 6 : exit(0);

	     default: cout<<endl<<setw(45)<<"Wrong Choice!!!\n";
	   }
   }while(ch!=6);
}
/*
SAMPLE OUTPUT
Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 2

Enter Employee no.: 110

			No Details have been Found

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 1

Enter no. of registrations (<=10) you want to have: 10

# Enter data for 1 Employee
Enter Employee no.                     : 110
Enter Name                             : Shivam Sharma
Enter Salary per month                 : 100000
Got any Bonus(Y/N)                     : y
-> Enter amount                        : 10000
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : y
-> Enter time period(in years)         : 3
-> Enter amount                        : 100000
-> Rate of interest(%) per annum       : 101

101 % is not valid.........Try again

-> Rate of interest(%) per annum       : 10
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 100000
-> Public Provident fund(if any)       : 100000
-> Tuition fee(if any)                 : 100000

		       WARNING !!!

Rs 300000 is more than 1,50,000 rupees
Want to enter again(Y/N)               : y

-> Employee Provident fund(if any)     : 60000
-> Public Provident fund(if any)       : 40000
-> Tuition fee(if any)                 : 50000

# Enter data for 2 Employee
Enter Employee no.                     : 111
Enter Name                             : Shivali Sharma
Enter Salary per month                 : 30000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : y
-> Name your loan                      : Housing
-> Rate of interest(%) per annum       : 8
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 50000
-> Public Provident fund(if any)       : 0
-> Tuition fee(if any)                 : 0

# Enter data for 3 Employee
Enter Employee no.                     : 112
Enter Name                             : Parmod Sharma
Enter Salary per month                 : 200000
Got any Bonus(Y/N)                     : y
-> Enter amount                        : 20000
Have taken any loan(Y/N)               : y
-> Name your loan                      : Car
-> Rate of interest(%) per annum       : 2
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 100000
-> Public Provident fund(if any)       : 200000
-> Tuition fee(if any)                 : 100000

		       WARNING !!!

Rs 400000 is more than 1,50,000 rupees
Want to enter again(Y/N)               : n

Savings shown by you will NOT be counted
CLICK to continue...

# Enter data for 4 Employee
Enter Employee no.                     : 113
Enter Name                             : Mamta Verma
Enter Salary per month                 : 20000
Got any Bonus(Y/N)                     : y
-> Enter amount                        : 1000
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : y
-> Enter time period(in years)         : 2
-> Enter amount                        : 80000
-> Rate of interest(%) per annum       : 9
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 0
-> Public Provident fund(if any)       : 80000
-> Tuition fee(if any)                 : 0

# Enter data for 5 Employee
Enter Employee no.                     : 114
Enter Name                             : Gagan Kumar
Enter Salary per month                 : 45000
Got any Bonus(Y/N)                     : y
-> Enter amount                        : 2000
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : y
-> Enter time period(in years)         : 1
-> Enter amount                        : 50000
-> Rate of interest(%) per annum       : 4
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 20000
-> Public Provident fund(if any)       : 30000
-> Tuition fee(if any)                 : 45000

# Enter data for 6 Employee
Enter Employee no.                     : 115
Enter Name                             : Ronak Singh
Enter Salary per month                 : 100000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 10000
-> Public Provident fund(if any)       : 15000
-> Tuition fee(if any)                 : 2000

# Enter data for 7 Employee
Enter Employee no.                     : 116
Enter Name                             : Ram Kumar
Enter Salary per month                 : 70000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : y
-> Name your loan                      : Personal
-> Rate of interest(%) per annum       : 10
Do you have any Fixed Deposit(Y/N)     : y
-> Enter time period(in years)         : 2
-> Enter amount                        : 200000
-> Rate of interest(%) per annum       : 15
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 40000
-> Public Provident fund(if any)       : 0
-> Tuition fee(if any)                 : 0

# Enter data for 8 Employee
Enter Employee no.                     : 117
Enter Name                             : Parag Garg
Enter Salary per month                 : 50000
Got any Bonus(Y/N)                     : y
-> Enter amount                        : 5000
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 0
-> Public Provident fund(if any)       : 90000
-> Tuition fee(if any)                 : 30000

# Enter data for 9 Employee
Enter Employee no.                     : 118
Enter Name                             : Nipun Goel
Enter Salary per month                 : 25000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : y
-> Enter time period(in years)         : 1
-> Enter amount                        : 50000
-> Rate of interest(%) per annum       : 10
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 20000
-> Public Provident fund(if any)       : 9000
-> Tuition fee(if any)                 : 40000

# Enter data for 10 Employee
Enter Employee no.                     : 119
Enter Name                             : Nitin Kumar
Enter Salary per month                 : 90000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : y
-> Name your loan                      : Housing
-> Rate of interest(%) per annum       : 5
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : y

		Deduction Managment System

Note: Aggregate amount deductible shall not exceed 1,50,000 rupees
CLICK to continue...

-> Employee Provident fund(if any)     : 30000
-> Public Provident fund(if any)       : 50000
-> Tuition fee(if any)                 : 6000

			Data has been entered........

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 2

Enter Employee no.: 116
---------------------------------------------------------------------------
Name: Ram Kumar                                        Emp. no.: 116

Details of salary paid and any                                    INR
other income and tax deducted

1. Gross Salary
   (a) Salary as per provisions                                  840000
   (b) Profits in lieu of salary(BONUS)                               0
   (c) Total                                                     840000

2. Less:
   Allowance to the loan: Personal
   Rate of interest: 10%
   Interest paid                                                  84000

3. Balance(1-2)                                                  756000

4. Add:
   Income gained from: fixed deposit(FD)
   Time period: 2 years
   Rate of interest: 15 %
   FD Amount                                                     200000
   Interest recieved                                                  0

5. Balance(3+4)                                                  756000

6. Deductions:
   (a) Employee Provident Fund                                    40000
   (b) Public Provident Fund                                          0
   (c) Tuition fee                                                    0
   (d) Total                                                      40000

7. Total Income(5-6)                                             716000

8. Tax on total income                                            65200
---------------------------------------------------------------------------

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 2

Enter Employee no.: 166

Employee no. 166 do NOT exist

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 5

Enter Employee no. you want to modify: 100

Employee no. 100 do NOT exist

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 5

Enter Employee no. you want to modify: 110

Employee Found
CLICK to continue...

---------------------------------------------------------------------------
Name: Shivam Sharma                                        Emp. no.: 110
---------------------------------------------------------------------------

Enter NEW details :-
Enter Salary per month                 : 50000
Got any Bonus(Y/N)                     : n
Have taken any loan(Y/N)               : n
Do you have any Fixed Deposit(Y/N)     : n
Want to show any savings(Y/N)          : n

			Details has been entered........
Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 2

Enter Employee no.: 110
---------------------------------------------------------------------------
Name: Shivam Sharma                                        Emp. no.: 110

Details of salary paid and any                                    INR
other income and tax deducted

1. Gross Salary
   (a) Salary as per provisions                                  600000
   (b) Profits in lieu of salary(BONUS)                               0
   (c) Total                                                     600000

2. Less:
   Allowance to the loan:
   Rate of interest: 0%
   Interest paid                                                      0

3. Balance(1-2)                                                  600000

4. Add:
   Income gained from: fixed deposit(FD)
   Time period: 0 years
   Rate of interest: 0 %
   FD Amount                                                          0
   Interest recieved                                                  0

5. Balance(3+4)                                                  600000

6. Deductions:
   (a) Employee Provident Fund                                        0
   (b) Public Provident Fund                                          0
   (c) Tuition fee                                                    0
   (d) Total                                                          0

7. Total Income(5-6)                                             600000

8. Tax on total income                                            42000
---------------------------------------------------------------------------

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 3

Enter Employee no. you want to search: 121

SEARCH FAILED........

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 3

Enter Employee no. you want to search: 114

Search Complete...
CLICK to continue...

---------------------------------------------------------------------------
Name: Gagan Kumar                                        Emp. no.: 114

Details of salary paid and any                                    INR
other income and tax deducted

1. Gross Salary
   (a) Salary as per provisions                                  540000
   (b) Profits in lieu of salary(BONUS)                            2000
   (c) Total                                                     542000

2. Less:
   Allowance to the loan:
   Rate of interest: 0%
   Interest paid                                                      0

3. Balance(1-2)                                                  542000

4. Add:
   Income gained from: fixed deposit(FD)
   Time period: 1 years
   Rate of interest: 4 %
   FD Amount                                                      50000
   Interest recieved                                                  0

5. Balance(3+4)                                                  542000

6. Deductions:
   (a) Employee Provident Fund                                    20000
   (b) Public Provident Fund                                      30000
   (c) Tuition fee                                                45000
   (d) Total                                                      95000

7. Total Income(5-6)                                             447000

8. Tax on total income                                            16700
---------------------------------------------------------------------------

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 4

Enter Employee no. you want to delete: 101

Employee no. 101 do NOT exist

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 4

Enter Employee no. you want to delete: 110

Employee Found
CLICK to continue...

			Details has been deleted........

Main Menu
1. Register Employee Details
2. Show Details of Salary paid and Tax Deducted for an Employee
3. Search Employee Details
4. Delete Employee
5. Modify Employee Details
6. EXIT
Enter your choice: 6

 */


