#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<ctype.h>
#include<dos.h>

//******************************END OF HEADER*************************************
void BookIssue();
void BookDeposit();
void AdminMenu();
void WriteStudent();
void DisplayAllStudents();
void SearchStudent(char*);
void DeleteStudent();
void EnterBook();
void DisplayAllBook();
void SearchBook(char*);
void ModifyBook();
void DeleteBook();
void chkadmin();
void AdminSignUp();
void AdminLogin();
//*************************END OF FUNCTION PROTOTYPES******************************
//**************************CLASS DEFINITIONS**************************************
class BOOK
{
	char BookNo[6];
	char BookName[50];
	char AuthorName[20];
  public:
	void CreateBook()
	{
        gotoxy(25,1);
        cout<<"ENTER NEW BOOK\n";
        cout<<"\nEnter The book no.";
        cin>>BookNo;
        cout<<"\n\nEnter The Name of The Book ";
        gets(BookName);
        cout<<"\n\nEnter The Author's Name ";
        gets(AuthorName);
        cout<<"\n\n\nBook "<<BookNo<<" Created..";
    }

    void ShowBook()
    {
        cout<<BookName<<" ("<<BookNo<<") by -"<<AuthorName;    
    }

    void ModifyBook()
    {
        cout<<"\n\nBook no. : "<<BookNo;
        cout<<"\nModified Book Name : ";
        gets(BookName);
        cout<<"\nModifies Author Name: ";
        gets(AuthorName);
    }

    char* rbno()
    {
        return BookNo;
    }
    char *rname()
    {
        return BookName;
    }
    void report()
    {cout<<BookNo<<setw(30)<<BookName<<setw(30)<<AuthorName<<endl;}


};         

class STUDENT
{
    char AdmNo[6];
    char name[20];
    char IssueBookNo[6];
    int token;
    public:
    void CreateStudent()
    {
        clrscr();
        gotoxy(25,1);
        cout<<"Register New Student";
        cout<<"\nEnter The admission no. ";
        cin>>AdmNo;
        cout<<"\nEnter The Name of The Student ";
        gets(name);
        token=0;
        IssueBookNo[0]='/0';
        cout<<"\n\nStudent Record Created..\n";
    }

    void ShowStudent()
    {
        clrscr();
        cout<<"\nAdmission no. : "<<AdmNo;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book(s) issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<IssueBookNo;
    }

    void ModifyStudent()
    {
        clrscr();
        cout<<"\nAdmission no. : "<<AdmNo;
        cout<<"\nModify Student Name : ";
        gets(name);
    }

    char* radmno()
    {
        return AdmNo;
    }

    char* rstat()
    {
        return IssueBookNo;
    }

    char* rname()
    {
        return name;
    }
    int rtoken()
    {
        return token;
    }

    void AddToken()
    {token=1;}

    void ResetToken()
    {token=0;}

    void getIssueBookNo(char t[])
    {
        strcpy(IssueBookNo,t);
    }

    void report()
    {cout<<"\t"<<AdmNo<<setw(20)<<name<<setw(10)<<token<<endl;}

}; 
struct ADMIN
{
    char Username[20], Password[20];
}Admin;
//*****************************END OF CLASS DEFINITIONS***************************************
	
    STUDENT Student;
	BOOK Book;
	fstream fil1,fil2;

//****************************FUNCTION DEFINITIONS START*************************************

//****************************ADMIN MENU DEFINITION STARTS***********************************
void AdminMenu()
{
    clrscr();
    int ch;
    gotoxy(25,1);
    cout<<"ADMINISTRATOR MENU";
    cout<<"\n1.Register Student";
    cout<<"\n2.Display All Student Records";
    cout<<"\n3.Search Student ";
    cout<<"\n4.Delete Student Record";
    cout<<"\n5.Add Book";
    cout<<"\n6.Display All Books";
    cout<<"\n7.Search Books";
    cout<<"\n8.Modify Book Record";
    cout<<"\n9.Delete Book Record";
    cout<<"\n10.Return To Main Menu";
    cout<<"\n\nPlease Enter Your Choice (1-11) ";
    cin>>ch;
    switch(ch)
    {
	    case 1: clrscr();
		    WriteStudent();
		    break;
	    case 2: DisplayAllStudents();
		    break;
	    case 3:
		   char search[6];
		   clrscr();
		   cout<<"\n\n\tPlease Enter The Admission No. ";
		   cin>>search;
		   SearchStudent(search);
		   break;
	    case 4: DeleteStudent();
		    break;
	    case 5: clrscr();
		    EnterBook();
		    break;
	    case 6: DisplayAllBook();
		    break;
	    case 7:
		   char bno[6];
		   clrscr();
		   cout<<"\n\nPlease Enter The book No. :";
		   cin>>bno;
		   SearchBook(bno);
		   break;
	      case 8:ModifyBook();
		     break;
	      case 9:DeleteBook();
		     break;
	      case 10: return;
	      default:cout<<"\nInvalid";
       }
       AdminMenu();
}
//******************************ADMIN MENU DEFINITION ENDS***********************************
//*********************************ADMIN MENU FUNCTIONS**************************************
void WriteStudent()
{
    char ch;
    fil1.open("STUDENT.dat",ios::out|ios::app|ios::binary);
    do
    {
        Student.CreateStudent();
        fil1.write((char*)&Student,sizeof(Student));
        cout<<"\nAdd more record... (y/n)?";
        cin>>ch;
    }while(toupper(ch)=='Y');
    fil1.close();
}

void DisplayAllStudents()
{
    clrscr();
    fil1.open("STUDENT.dat",ios::in|ios::binary);
    int found;     
    gotoxy(25,1);
    cout<<"All Registered Students\n";
    cout<<"\n  Admission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    while(fil1.read((char*)&Student,sizeof(STUDENT)))
    {
        Student.report();
        found++;
    }
         
    fil1.close();
    cout<<"\n\nPress Any Key To Return\n\n";
    getch();
}

void SearchStudent(char s[])
{
    gotoxy(25,1);
    cout<<"Search Student\n";
    int found=0;
    fil1.open("STUDENT.dat",ios::in|ios::binary);
    while((!found)&&(fil1.read((char*)&Student,sizeof(STUDENT))))
    {
        if((strcmpi(Student.radmno(),s)==0))
        {
            Student.ShowStudent();
            found=1;
        }
    }
    fil1.close();
    if(found==0)
        cout<<"\n\nStudent not found";
     getch();
}

void DeleteStudent()
{
    char n[6];
    int flag=0;    
    clrscr();
    gotoxy(25,1);
    cout<<"Delete Student Record";
    cout<<"\n\nEnter The Admission Number: ";
    cin>>n;
    fil1.open("STUDENT.dat",ios::in|ios::out|ios::binary);
    fil2.open("Temp.dat",ios::out|ios::binary);
    fil1.seekg(0,ios::beg);
    while(fil1.read((char*)&Student,sizeof(STUDENT)))
    {
        if(strcmpi(Student.radmno(),n)!=0)
            fil2.write((char*)&Student,sizeof(STUDENT));
        else
            flag=1;
    } 
    fil2.close();
    fil1.close();
    remove("STUDENT.dat");
    rename("Temp.dat","STUDENT.dat");
    if(flag==1)
      cout<<"\nRecord "<<Student.radmno()<<" Deleted successfully";
    else
      cout<<"\nRecord not found\n";
    getch();
}

void EnterBook()
{
    char ch;
    fil1.open("book.dat",ios::out|ios::app);
    do
    {
        clrscr();
        gotoxy(25,1);
        cout<<"Enter New Book\n";
        Book.CreateBook();
	fil1.write((char*)&Book,sizeof(Book));
        cout<<"\nMore Entries...(y/n)?";
        cin>>ch;
    }while(toupper(ch)=='Y');
    fil1.close();
}

void DisplayAllBook()
{
    clrscr();
    fil1.open("book.dat",ios::in);
    gotoxy(25,1);
    cout<<"All Registered Books\n";
    cout<<"\nBook Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n\n";

    while(fil1.read((char*)&Book,sizeof(Book)))
    {
	Book.report();
    }
    fil1.close();
    getch();
}

void SearchBook(char s[])
{
    clrscr();
    gotoxy(25,1);
    cout<<"Search Book\n";
    int found=0;
    fil1.open("book.dat",ios::in|ios::binary);
    while(fil1.read((char*)&Book,sizeof(Book)))
    {
	if(strcmpi(Book.rbno(),s)==0)
	{
	    Book.ShowBook();
	    found=1;
	}
    }
    fil1.close();
    if(found==0)
	cout<<"\nBook record not found";
    getch();
}

void ModifyBook()
{
    char s[6];
    int found=0;
    clrscr();
    gotoxy(25,1);
    cout<<"Edit Book Record\n";
    cout<<"\nEnter The Book Number: ";
    cin>>s;
    fil1.open("book.dat",ios::in|ios::out|ios::binary);
    while(fil1.read((char*)&Book,sizeof(Book)) && found==0)
    {
	if(strcmpi(Book.rbno(),s)==0)
	{
	    Book.ShowBook();
	    cout<<"\nEnter The Rectified Information\n"<<endl;
	    Book.ModifyBook();
	    fil1.seekp(fil1.tellg()-sizeof(Book),ios::beg);
		fil1.write((char*)&Book,sizeof(Book));
		cout<<"\nRecord Sucessfully Updated\n";
		found=1;
	}
    }

    fil1.close();
    if(found==0)
	cout<<"\nRecord Not Found ";
    getch();
}

void DeleteBook()
{
    char n[6];
    clrscr();
    gotoxy(25,1);
    cout<<"Delete A Book";
    cout<<"\n\nEnter The Book Number: ";
    cin>>n;
    fil1.open("book.dat",ios::in|ios::out|ios::binary);
    fstream f2;
    f2.open("Temp.dat",ios::out|ios::binary);
    fil1.seekg(0,ios::beg);
    while(fil1.read((char*)&Book,sizeof(Book)))
    {
	if(strcmpi(Book.rbno(),n)!=0)
	{
	    f2.write((char*)&Book,sizeof(Book));
	}
    }

	f2.close();
	fil1.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<"\nRecord "<<Book.rbno()<<" Deleted successfully";
	getch();
}
//**************************END OF ADMIN MENU FUNCTIONS*************************************

//**************************BOOK ISSUE/DEPOSIT FUNCTIONS************************************
void BookIssue()
{
    char StudentNumber[6],BookNumber[6];
    int found=0,flag=0;
    clrscr();
    gotoxy(25,1);
    cout<<"Issue A Book\n";
    cout<<"\nEnter The Student Admission Number : ";
    cin>>StudentNumber;
    fil1.open("STUDENT.dat",ios::in|ios::out|ios::binary);
    fil2.open("book.dat",ios::in|ios::out|ios::binary);
    while((found==0)&&fil1.read((char*)&Student,sizeof(STUDENT)))
      {
	if(strcmpi(Student.radmno(),StudentNumber)==0)
	{
	    found=1;
	    if(Student.rtoken()==0)
	    {
		cout<<"\nEnter the Book Number. ";
		cin>>BookNumber;
		while((flag==0)&&fil2.read((char*)&Book,sizeof(Book)))
		{
		    if(strcmpi(Book.rbno(),BookNumber)==0)
		    {
			Book.ShowBook();
			flag=1;
			Student.AddToken();
			Student.getIssueBookNo(Book.rbno());
			//int pos=-1*sizeof(Student);
				    fil1.seekp(fil1.tellg()-sizeof(Student),ios::beg);
			fil1.write((char*)&Student,sizeof(STUDENT));
				    cout<<"\n\nBook "<<Book.rname()<<" has been issued successfully to "<<Student.rname()<<endl;
		    }
		}
		if(flag==0)
		    cout<<"\nBook does not exist\n";
	    }
	    else
		cout<<"\nPlease Return The Last Book!\n";

	}
    }
    if(found==0)
	cout<<"\nStudent not found...\n";
    getch();
    fil1.close();
    fil2.close();
}

void BookDeposit()
{
    char StudentNumber[6],BookNumber[6];
    int found=0,flag=0;
    fstream fil3,fil4;
    clrscr();
    gotoxy(25,1);
    cout<<"Deposit A Book";
    cout<<"\nEnter The Student Admission No.";
    cin>>StudentNumber;
    fil3.open("STUDENT.dat",ios::in|ios::out|ios::binary);
    fil4.open("book.dat",ios::in|ios::out|ios::binary);
    while((found==0)&&fil3.read((char*)&Student,sizeof(STUDENT)))
       {
	if(strcmpi(Student.radmno(),StudentNumber)==0)
	{
	    found=1;
	    if(Student.rtoken()==1)
	    {
	    while((flag==0)&&fil4.read((char*)&Book,sizeof(Book)))
	    {
		if(strcmpi(Book.rbno(),Student.rstat())==0)
		{
		    Book.ShowBook();
		    flag=1;
		}
		Student.ResetToken();
		//int pos=-1*sizeof(Student);
		fil3.seekp(fil3.tellg()-sizeof(Student),ios::beg);
		fil3.write((char*)&Student,sizeof(STUDENT));
		cout<<"\n\nBook "<<Book.rname()<<" has been deposited successfully by "<<Student.rname()<<endl;
	    }
	    }
		if(flag==0)
		    cout<<"\nBook does not exist";
	}
	else
	  cout<<"\nNo Book Has Been Issued to "<<Student.radmno();
	}

      //if(found==0)
    //cout<<"\nStudent does not exist...";
    getch();
  fil3.close();
  fil4.close();
}
//******************************END OF ISSUE/DEPOSIT FUNCTIONS******************************************
void outro()
{
    clrscr();
    char e[5]={'E','D','I','T','H'};
    gotoxy(30,12);
    for(int i=0;i<5;i++)
    {
	cout<<" "<<e[i]<<" ";
	delay(250);
    }
    cout<<"\n\nSanket Deb Rox";
    getch();
}
//*******************************END OF FUNCTION DEFINITIONS*********************************

void chkadmin()
{
    fstream fil;
    fil.open("libadmin.dat",ios::binary|ios::in|ios::out);
    fil.seekg(0,ios::end);
    if(fil.tellg()==0)
    {
       fil.close();
       AdminSignUp();
    }
    else
    {
       fil.close();
       return;
    }
    //fil.close();
}

void AdminSignUp()
{
    clrscr();
    gotoxy(25,1);
    cout<<"Admin Sign Up\n";
    cout<<"\n\nEnter Username: ";
    cin>>Admin.Username;
    cout<<"\nEnter Password: ";
    cin>>Admin.Password;
    fil1.open("libadmin.dat",ios::binary|ios::out);
    fil1.write((char*)&Admin,sizeof(Admin));
    fil1.close();
    return;
}

void AdminLogin()
{
    clrscr();
    char Username[20],Password[20];
    gotoxy(25,1);
    cout<<"Admin Login\n";
    cout<<"\nEnter Username: ";
    cin>>Username;
    cout<<"\nEnter Password: ";
    char r;
    int k=0;
    do
    {
	    r=getch();
    	Password[k]=r;
	    if(int(r)!=13)
		printf("*");
    	k++;
    }while(int(r)!=13);
    Password[k-1]='\0';
    //cin>>Password;
    fil1.open("libadmin.dat",ios::binary|ios::in);
    fil1.read((char*)&Admin,sizeof(Admin));
    if((strcmp(Admin.Username,Username)==0)&&(strcmp(Admin.Password,Password)==0))
    {
        clrscr();
        fil1.close();
        AdminMenu();
    }
    else
    {
        fil1.close();
        cout<<"\nError! Try Again...";
        getch();
        return;
    }
    
}

//***********************************MAIN FUNCTION*******************************************
void main()
{
    chkadmin();
    char ch;
    do
    {
      clrscr();
      gotoxy(25,1);
      cout<<"Library Management";
	  cout<<"\n\n01. Issue Book";
	  cout<<"\n02. Deposit Book";
	  cout<<"\n03. Admin Menu";
	  cout<<"\n04. Exit";
	  cout<<"\n\nPlease Select Your Option (1-4) ";
	  ch=getch();
	  switch(ch)
	  {
	    case '1':clrscr();
		     DisplayAllBook();
		     BookIssue();
			 break;
	    case '2':BookDeposit();
			 break;
	    case '3':AdminLogin();//AdminMenu();
			break;
	    case '4':clrscr();
		     cout<<"Thank You For Using Library Management By Sanket Deb!!";
		     getch();
	     outro();
		     exit(0);
	    default :cout<<"\nInvalid";
	}
	}while(ch!='4');
}
