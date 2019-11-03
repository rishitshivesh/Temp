#include <gui.h>
//#include<time.h>
void welcome();
void Customerlogin();
void CustomerSignUp();
void CustomerTime();
void CustomerHome();
void AdminLogin();
void AdminSignUp();
void AdminHome();
void about();
void SeatSelect();
void EditMovieName();
void EditMovieTime();
void EditMoviePrice();
void del()
{}
int CheckFile(char *username,char *password);
int AdminCheckID(char *username,char *password);

class MOVIE
{
	public:
	char MovieName[50], Timing[4], Price[4];
	char* Mn()
	{return MovieName;}
	void inputname(char *name);
	void inputtime(char *time);
	void inputprice(char *price);

}Choice;
class CUSTOMER
{
	char Password[50];
public:
	char Username[50];
	char Name[50], EMail[25];
	char Phone[10];

	//CUSTOMER(char *user,char *pass);
	void inputdata(char *name, char *username,char *password, char *email, char *phone);
	int CheckPassword(char *password);


};
class ADMIN
{
	char Password[50];
public:
	char Username[50];
	char Name[50], EMail[25];
	char Phone[10];
	void inputdata(char *name, char *username,char *password, char *email, char *phone);
	int CheckPassword(char *password);


};
int ADMIN::CheckPassword(char *password)
{
	if(strcmp(Password,password)==0)
		return 1;
	else{
		return 0;
	}
}
void ADMIN::inputdata(char *name, char *username,char *password, char *email, char *phone)
{
	strcpy(Name,name);
	strcpy(Username,username);
	strcpy(Password,password);
	strcpy(EMail,email);
	strcpy(Phone,phone);
}
int CUSTOMER::CheckPassword(char *password)
{
	if(strcmp(Password,password)==0)
		return 1;
	else{
		return 0;
	}
}
void CUSTOMER::inputdata(char *name, char *username,char *password, char *email, char *phone)
{
	strcpy(Name,name);
	strcpy(Username,username);
	strcpy(Password,password);
	strcpy(EMail,email);
	strcpy(Phone,phone);
}

Window *awelcome = new Window(10,10,630,480,"WELCOME");
Button *back = new Button(20,400,100,30,"BACK",1);
Button *next = new Button(500,400,100,30,"NEXT",2);
int LoginStatus=0;

void MOVIE::inputname(char *name)
{
	strcpy(MovieName,name);
}
void MOVIE::inputtime(char *time)
{
	strcpy(Timing,time);
}
void MOVIE::inputprice(char *price)
{
	strcpy(Price,price);
}

int AdminCheckID(char *username,char *password=" ")
{
	ADMIN Admin;
	fstream fil;
	int exists=0;
	fil.open("admin.dat",ios::binary|ios::in);
	while(fil.read((char *)&Admin,sizeof(Admin)))
	{
		if(strcmp(Admin.Username,username)==0&&Admin.CheckPassword(password))
			exists=1;

	}
	fil.close();
	return exists;
}

int CheckFile(char *username,char *password=" ")
{
	CUSTOMER Customer;
	fstream fil;
	int exists=0;
	fil.open("customer.dat",ios::binary|ios::in);
	while(fil.read((char *)&Customer,sizeof(Customer)))
	{
		if(strcmp(Customer.Username,username)==0 && Customer.CheckPassword(password))
			exists=1;
		else if(strcmp(Customer.Username,username)==0)
			exists=2;

	}

	fil.close();
	return exists;
}
void AdminHome()
{
	cleardevice();
	Window *pAHome = new Window(10,10,630,480,"Admin Home");
	Button *t1 = new Button(75,80,110,130,"Edit Timings",3);
	Button *t2 = new Button(205,80,110,130,"Edit Price",4);
	Button *t3 = new Button(335,80,110,130,"Edit Menu",5);
	Button *t4 = new Button(465,80,110,130,"Now Showing",6);
	Button *t5 = new Button(75,250,110,130,"Booking Status",7);
	Button *t6 = new Button(205,250,110,130,"Add A User",8);
	Button *t7 = new Button(335,250,110,130,"Book A Ticket",9);
	Button *t8 = new Button(465,250,110,130,"About",10);
	Button *t9 = new Button(510,420,110,30,"Sign Out",11);

	//Button *home = new Button(20,400,100,30,"Home",LEFT_TEXT,7);
	pAHome->Draw();
	t1->Draw();
	t2->Draw();
	t3->Draw();
	t4->Draw();
	t5->Draw();
	t6->Draw();
	t7->Draw();
	t8->Draw();
	t9->Draw();
/*	auto void del()
	{
		delete t1;
		delete t2;
		delete t3;
		delete t4;
		delete t5;
		delete t6;
		delete t7;
		delete t8;
		delete t9;
	}                       */
	// for(int i=1;i<=2;i++)
    // {
    // 	bwelcome[i]->Draw();
    // }
    while(1)
    {
		int Chk=LoginStatus;
		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		awelcome->EnableClickHandler();
		t1->EnableClickHandler();
		t2->EnableClickHandler();
		t3->EnableClickHandler();
		t4->EnableClickHandler();
		t5->EnableClickHandler();
		t6->EnableClickHandler();
		t7->EnableClickHandler();
		t8->EnableClickHandler();
		t9->EnableClickHandler();
   //  	for(int i=1;i<=2;i++)
			// bwelcome[i]->EnableClickHandler();
		if(ButtonId==3)
		{
			EditMovieTime();

		}
		else if(ButtonId==4)
		{
			EditMoviePrice();
		}
		else if(ButtonId==5)
		{

		}
		else if(ButtonId==6)
		{
			EditMovieName();
		}
		else if(ButtonId==7)
		{}
		else if(ButtonId==8)
		{	del();
			CustomerSignUp();
		}
		else if(ButtonId==9)
		{	del();
			CustomerHome();
		}
		else if(ButtonId==10)
		{
			del();
			about();
		}
		else if(ButtonId==11)
		{
			del();
			LoginStatus=0;
			welcome();
		}

  }

}
void AdminSignUp()
{
	cleardevice();
	int msgBtn = msgbox.MessageBox(200,150,"New","Welcome to The Program.         Admin Sign Up.",BLUE,jcOKOnly,jcInformation);
	Window *pSignUpWindow = new Window(10,10,630,480,"ADMIN SIGN UP");
	Label *page = new Label(200,70,243,30,"Administrator Sign Up",CENTER_TEXT);
	TextBox *pname = new TextBox(200,130,243,30,"NAME",LEFT_TEXT,1);
	TextBox *pusername = new TextBox(200,180,243,30,"USERNAME",LEFT_TEXT,2);
	TextBox *ppassword = new TextBox(200,230,243,30,"PASSWORD",LEFT_TEXT,3);
	TextBox *pphone = new TextBox(200,280,243,30,"PHONE NUMBER",LEFT_TEXT,4);
	TextBox *pemail = new TextBox(200,330,243,30,"EMAIL ID",LEFT_TEXT,5);

	pSignUpWindow->Draw();
	page->Draw();
	pname->Draw();
	pusername->Draw();
	ppassword->Draw();
	pphone->Draw();
	pemail->Draw();

    //back->Draw();
    next->Draw();
  /*  auto void del()
    {
	delete page;
	delete pname;
	delete pusername;
	delete ppassword;
	delete pphone;
	delete pemail;
	delete next;
    }*/
    ADMIN Admin;
    while(1)
    {

		Admin.inputdata(pname->GetText(),pusername->GetText(),ppassword->GetText(),pemail->GetText(),pphone->GetText());
		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		pSignUpWindow->EnableClickHandler();
		ppassword->EnableClickHandler();
		pname->EnableClickHandler();
		pusername->EnableClickHandler();
		ppassword->HideText(true);
		pphone->EnableClickHandler();
		pemail->EnableClickHandler();

		back->EnableClickHandler();
		next->EnableClickHandler();

		if(ButtonId==2)
		{
				fstream fil;
				fil.open("admin.dat",ios::binary|ios::app);
				fil.write((char*)&Admin,sizeof(Admin));
				fil.close();
				del();
				AdminLogin();
		}

	}

}

void AdminLogin()
{
	cleardevice();
	Window *pLogin = new Window(10,10,630,480,"ADMIN LOGIN");
	pLogin->Draw();
	TextBox *pusername = new TextBox(200,200,243,30,"USERNAME",LEFT_TEXT,1);
	TextBox *ppassword = new TextBox(200,240,243,30,"PASSWORD",LEFT_TEXT,2);
    pusername->Draw();
    ppassword->Draw();
    back->Draw();
    next->Draw();

	// for(int i=1;i<=2;i++)
	// {
	// 	standard[i]->Draw();
	// }
	while(1)
	{
		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		pLogin->EnableClickHandler();
		pusername->EnableClickHandler();
		ppassword->EnableClickHandler();
		ppassword->HideText(true);
		back->EnableClickHandler();
		next->EnableClickHandler();
		// for(int i=1;i<=2;i++)
		// {
		// 	standard[i]->EnableClickHandler();
		// }
		if(ButtonId==1)
	    {
		    welcome();
	    }
	    else if(ButtonId==2)
	    {
		if(AdminCheckID(pusername->GetText(),ppassword->GetText())==1)
		{
			LoginStatus=2;
			AdminHome();
		}
		else
		{
			int msgBtn = msgbox.MessageBox(200,200,"New","Incorrect Password or Username",BLUE,jcRetryCancel,jcCritical);
				if(msgBtn=jcRetry)
				{
					AdminLogin();
				}
			}
	    }
	}
}
void CustomerHome()
{
	cleardevice();
	fstream fil;
	fil.open("MOVIE.DAT",ios::binary|ios::in);
	MOVIE Movie[4];
	MOVIE Choice;
	fil.read((char*)&Movie[0],sizeof(Movie));
	fil.read((char*)&Movie[1],sizeof(Movie));
	fil.read((char*)&Movie[2],sizeof(Movie));
	fil.read((char*)&Movie[3],sizeof(Movie));
	Window *pAHome = new Window(10,10,630,480,"Now Playing");
	Button *m1 = new Button(175,80,90,130,Movie[0].MovieName,3);
	Button *m2 = new Button(305,80,90,130,Movie[1].MovieName,4);
	Button *m3 = new Button(175,250,90,130,Movie[2].MovieName,5);
	Button *m4 = new Button(305,250,90,130,Movie[3].MovieName,6);
	//Button *home = new Button(20,400,100,30,"Home",LEFT_TEXT,7);
	pAHome->Draw();
	m1->Draw();
	m2->Draw();
	m3->Draw();
	m4->Draw();
    back->Draw();
       /*	auto void del()
	{
		delete m1;
		delete m2;
		delete m3;
		delete m4;
		delete back;
		delete next;
	} */
	// for(int i=1;i<=2;i++)
    // {
    // 	bwelcome[i]->Draw();
    // }
    while(1)
    {

		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		awelcome->EnableClickHandler();
		m1->EnableClickHandler();
		m2->EnableClickHandler();
		m3->EnableClickHandler();
		m4->EnableClickHandler();
		back->EnableClickHandler();
		int chk=LoginStatus;
   //  	for(int i=1;i<=2;i++)
			// bwelcome[i]->EnableClickHandler();
		if(ButtonId==3)
		{
			strcpy(Choice.MovieName,m1->GetText());
			del();
			CustomerTime();
		}
		else if(ButtonId==4)
		{
			strcpy(Choice.MovieName,m2->GetText());
			del();
			CustomerTime();
		}
		else if(ButtonId==5)
		{
			strcpy(Choice.MovieName,m3->GetText());
			del();
			CustomerTime();
		}
		else if(ButtonId==6)
		{
			strcpy(Choice.MovieName,m4->GetText());
			del();
			CustomerTime();
		}
		else if(LoginStatus==0)
		{

			int msgBtn = msgbox.MessageBox(200,200,"Credentials Needed","Please Login to Proceed",BLUE,jcOKOnly,jcCritical);
			if(msgBtn=jcOK)
			{
				Customerlogin();
			}

		}
		else if(ButtonId==1&&LoginStatus==1)
		{
			int msgBtn = msgbox.MessageBox(200,200,"HOME","Are you sure you want to \n  Log Out",BLUE,jcYesNo,jcCritical);
				if(msgBtn=jcYes)
				{
					LoginStatus=0;
					Customerlogin();

				}
				else{del();CustomerHome();}

		}
		else if(ButtonId==1&&LoginStatus==2)
		{
			del();
			AdminHome();
		}
		else if(ButtonId==1&&LoginStatus==0)
		{
			del();
			welcome();
		}
		else
		{

		}
    }
	fil.close();

}
void CustomerTime()
{
	cleardevice();
	fstream fil;
	fil.open("MOVIE.DAT",ios::binary|ios::in);
	MOVIE Movie[4];
	fil.read((char*)&Movie[0],sizeof(Movie));
	fil.read((char*)&Movie[1],sizeof(Movie));
	fil.read((char*)&Movie[2],sizeof(Movie));
	fil.read((char*)&Movie[3],sizeof(Movie));
	Window *pTime = new Window(10,10,630,480,"Time Selection");
	Button *m1 = new Button(175,80,90,130,Movie[0].Timing,3);
	Button *m2 = new Button(305,80,90,130,Movie[1].Timing,4);
	Button *m3 = new Button(175,250,90,130,Movie[2].Timing,5);
	Button *m4 = new Button(305,250,90,130,Movie[3].Timing,6);
	//Button *home = new Button(20,400,100,30,"Home",LEFT_TEXT,7);
	pTime->Draw();
	m1->Draw();
	m2->Draw();
	m3->Draw();
	m4->Draw();
    back->Draw();

    while(1)
    {

		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		awelcome->EnableClickHandler();
		m1->EnableClickHandler();
		m2->EnableClickHandler();
		m3->EnableClickHandler();
		m4->EnableClickHandler();
		back->EnableClickHandler();
		if(ButtonId==3)
		{
			strcpy(Choice.Timing,m1->GetText());
			del();
			SeatSelect();
		}
		else if(ButtonId==4)
		{
			strcpy(Choice.Timing,m2->GetText());
			del();
			SeatSelect();
		}
		else if(ButtonId==5)
		{
			strcpy(Choice.Timing,m3->GetText());
			del();
			SeatSelect();
		}
		else if(ButtonId==6)
		{
			strcpy(Choice.Timing,m4->GetText());
			del();
			SeatSelect();
		}
		else if(ButtonId==1)
		{
			CustomerHome();
		}
		else
		{

		}
    }
	fil.close();

}

void CustomerSignUp()
{
	cleardevice();
	Window *pSignUpWindow = new Window(10,10,630,480,"CUSTOMER SIGN UP");
	Label *page = new Label(200,70,243,30,"Customer Sign Up",CENTER_TEXT);
	TextBox *pname = new TextBox(200,130,243,30,"NAME",LEFT_TEXT,1);
	TextBox *pusername = new TextBox(200,180,243,30,"USERNAME",LEFT_TEXT,2);
	TextBox *ppassword = new TextBox(200,230,243,30,"PASSWORD",LEFT_TEXT,3);
	TextBox *pphone = new TextBox(200,280,243,30,"PHONE NUMBER",LEFT_TEXT,4);
	TextBox *pemail = new TextBox(200,330,243,30,"EMAIL ID",LEFT_TEXT,5);

	pSignUpWindow->Draw();
	page->Draw();
	pname->Draw();
	pusername->Draw();
	ppassword->Draw();
	pphone->Draw();
	pemail->Draw();

    back->Draw();
    next->Draw();
    while(1)
    {

		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		pSignUpWindow->EnableClickHandler();
		ppassword->EnableClickHandler();
		pname->EnableClickHandler();
		pusername->EnableClickHandler();
		ppassword->HideText(true);
		pphone->EnableClickHandler();
		pemail->EnableClickHandler();

		back->EnableClickHandler();
		next->EnableClickHandler();

		if(ButtonId==1)
		{
			Customerlogin();
		}
		if(ButtonId==2)
		{
			CUSTOMER Customer;

			Customer.inputdata(pname->GetText(),pusername->GetText(),ppassword->GetText(),pemail->GetText(),pphone->GetText());
			if(CheckFile(pusername->GetText())==2)
			{
				int msgBtn = msgbox.MessageBox(200,200,"Sign Up","User Exists. Please Login!",BLUE,jcOKOnly,jcCritical);
					if(msgBtn=jcOK)
					{
						Customerlogin();
						//fil.close();
					}
			}
			else
			{
				fstream fil;
				fil.open("customer.dat",ios::binary|ios::app);
				fil.write((char *)&Customer,sizeof(Customer));
				fil.close();
				Customerlogin();
			}

		}
    }
}
void Customerlogin()
{
	cleardevice();
	Window *pLogin = new Window(10,10,630,480,"CUSTOMER LOGIN");
	Button *pCustomerSignUp = new Button(200,400,243,30,"New Here, SIGN UP",5);
	pLogin->Draw();
	TextBox *pusername = new TextBox(200,200,243,30,"USERNAME",LEFT_TEXT,2);
	TextBox *ppassword = new TextBox(200,240,243,30,"PASSWORD",LEFT_TEXT,3);
    pusername->Draw();
    ppassword->Draw();
    pCustomerSignUp->Draw();
    back->Draw();
    next->Draw();

    while(1)
	{
		CUSTOMER Customer;
		mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
	pLogin->EnableClickHandler();
		pusername->EnableClickHandler();
		ppassword->EnableClickHandler();
		ppassword->HideText(true);
		pCustomerSignUp->EnableClickHandler();
		back->EnableClickHandler();
		next->EnableClickHandler();
		// for(int i=1;i<=2;i++)
		// {
		// 	standard[i]->EnableClickHandler();
		// }
		if(ButtonId==1)
	    {
	    welcome();
	    }
	    if(ButtonId==2)
	    {
			if(CheckFile(pusername->GetText(),ppassword->GetText())==1)
			{
				LoginStatus=1;
				CustomerHome();
			}
			else
			{
				int msgBtn = msgbox.MessageBox(200,200,"New","Incorrect Password or Username",BLUE,jcRetryCancel,jcCritical);
					if(msgBtn=jcRetry){
						Customerlogin();
						//fil.close();
					}
			}

	    }
	    if(ButtonId==5)
	    {
		CustomerSignUp();
	    }
	}


}
void welcome()
{
	cleardevice();
	Button *admin = new Button(200,180,243,30,"ADMIN",3);
	Button *customer = new Button(200,220,243,30,"CUSTOMER",4);
	Button *guest = new Button(200,260,243,30,"NOW SHOWING",5);
	awelcome->Draw();
	admin->Draw();
	guest->Draw();
	customer->Draw();

    // for(int i=1;i<=2;i++)
    // {
    // 	bwelcome[i]->Draw();
    // }
    while(1)
    {
	mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
		awelcome->EnableClickHandler();
		admin->EnableClickHandler();
		customer->EnableClickHandler();
		guest->EnableClickHandler();
   //  	for(int i=1;i<=2;i++)
			// bwelcome[i]->EnableClickHandler();
		if(ButtonId==3&&LoginStatus==0)//Admin
			AdminLogin();
		else if(ButtonId==4&&LoginStatus==0)//Customer
			Customerlogin();
		else if(ButtonId==5)
			CustomerHome();
		else if(ButtonId==3&&LoginStatus==2)
			AdminHome();
		else if(ButtonId==4&&LoginStatus==1)
			CustomerHome();


    }
}
void CustConfirm()
{
	cleardevice();
	Window *pConfirm = new Window(10,10,630,480,"CONFIRM BOOKING");
	pConfirm->Draw();
	back->Draw();
	next->Draw();

    while(1)
	{
		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		pConfirm->EnableClickHandler();
		back->EnableClickHandler();
		next->EnableClickHandler();
		if(ButtonId==1)
		{
			SeatSelect();
		}
		if(ButtonId==2)
		{
			CustConfirm();
		}

	 }

}
void SeatSelect()
{
	cleardevice();
	Window *pSeat = new Window(10,10,630,480,"SELECT SEATS");
	pSeat->Draw();
	back->Draw();
	next->Draw();

    while(1)
	{
		mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
		pSeat->EnableClickHandler();
		back->EnableClickHandler();
		next->EnableClickHandler();
		if(ButtonId==1)
		{
			CustomerTime();
		}
	    if(ButtonId==2)
	    {
		CustConfirm();
	    }

	 }
}
void EditMovieName()
{
	cleardevice();
	Window *pEditMName = new Window(10,10,630,480,"EDIT MOVIE NAME");
	Label *page = new Label(200,70,243,30,"Edit Movie Name",CENTER_TEXT);
	pEditMName->Draw();
	page->Draw();
	TextBox *m1 = new TextBox(200,130,243,30,"Movie 1",LEFT_TEXT,1);
	TextBox *m2 = new TextBox(200,180,243,30,"Movie 2",LEFT_TEXT,2);
	TextBox *m3 = new TextBox(200,230,243,30,"Movie 3",LEFT_TEXT,3);
	TextBox *m4 = new TextBox(200,280,243,30,"Movie 4",LEFT_TEXT,4);
	pEditMName->Draw();
	page->Draw();
	m1->Draw();
	m2->Draw();
	m3->Draw();
	m4->Draw();

    back->Draw();
    next->Draw();
    fstream fil;
    while(1)
    {

	fil.open("MOVIE.DAT",ios::binary|ios::in);
	MOVIE Movie[4];
	fil.read((char*)&Movie[0],sizeof(Movie));
	fil.read((char*)&Movie[1],sizeof(Movie));
	fil.read((char*)&Movie[2],sizeof(Movie));
	fil.read((char*)&Movie[3],sizeof(Movie));
	fil.close();
	mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
	pEditMName->EnableClickHandler();
	m1->EnableClickHandler();
	m2->EnableClickHandler();
	m3->EnableClickHandler();
	m4->EnableClickHandler();
	back->EnableClickHandler();
	next->EnableClickHandler();
	//while(fil.read((char*)&Movie,sizeof(Movie)))
	//{
	Movie[0].inputname(m1->GetText());
	Movie[1].inputname(m2->GetText());
	Movie[2].inputname(m3->GetText());
	Movie[3].inputname(m4->GetText());
	//}

		if(ButtonId==2)
		{
				fil.open("MOVIE.DAT",ios::binary|ios::out);
				fil.seekg(0,ios::beg);
				fil.write((char*)&Movie[0],sizeof(Movie));
				fil.write((char*)&Movie[1],sizeof(Movie));
				fil.write((char*)&Movie[2],sizeof(Movie));
				fil.write((char*)&Movie[3],sizeof(Movie));
				fil.close();
				del();
				AdminHome();

			}
		else if(ButtonId==1)
		{

			AdminHome();
		}

	}
	//getch();

}

void EditMovieTime()
{
	cleardevice();
	Window *pEditMTime = new Window(10,10,630,480,"EDIT MOVIE TIME");
	Label *page = new Label(200,70,243,30,"Edit Movie Time",CENTER_TEXT);
	pEditMTime->Draw();
	page->Draw();
	TextBox *m1 = new TextBox(200,130,243,30,"Movie 1 Timing",LEFT_TEXT,1);
	TextBox *m2 = new TextBox(200,180,243,30,"Movie 2 Timing",LEFT_TEXT,2);
	TextBox *m3 = new TextBox(200,230,243,30,"Movie 3 Timing",LEFT_TEXT,3);
	TextBox *m4 = new TextBox(200,280,243,30,"Movie 4 Timing",LEFT_TEXT,4);
	pEditMTime->Draw();
	page->Draw();
	m1->Draw();
	m2->Draw();
	m3->Draw();
	m4->Draw();

    back->Draw();
    next->Draw();
    fstream fil;
    while(1)
    {

	fil.open("MOVIE.DAT",ios::binary|ios::in);
	MOVIE Movie[4];
	fil.read((char*)&Movie[0],sizeof(Movie));
	fil.read((char*)&Movie[1],sizeof(Movie));
	fil.read((char*)&Movie[2],sizeof(Movie));
	fil.read((char*)&Movie[3],sizeof(Movie));
	fil.close();
	mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
	pEditMTime->EnableClickHandler();
	m1->EnableClickHandler();
	m2->EnableClickHandler();
	m3->EnableClickHandler();
	m4->EnableClickHandler();
	back->EnableClickHandler();
	next->EnableClickHandler();
	//while(fil.read((char*)&Movie,sizeof(Movie)))
	//{
	Movie[0].inputtime(m1->GetText());
	Movie[1].inputtime(m2->GetText());
	Movie[2].inputtime(m3->GetText());
	Movie[3].inputtime(m4->GetText());
	//}

		if(ButtonId==2)
		{
				fil.open("MOVIE.DAT",ios::binary|ios::out);
				fil.seekg(0,ios::beg);
				fil.write((char*)&Movie[0],sizeof(Movie));
				fil.write((char*)&Movie[1],sizeof(Movie));
				fil.write((char*)&Movie[2],sizeof(Movie));
				fil.write((char*)&Movie[3],sizeof(Movie));
				fil.close();
				del();
				AdminHome();

			}
		else if(ButtonId==1)
		{

			AdminHome();
		}

	}
	//getch();

}
void EditMoviePrice()
{
	cleardevice();
	Window *pEditMPrice = new Window(10,10,630,480,"EDIT MOVIE PRICE");
	Label *page = new Label(200,70,243,30,"Edit Movie Price",CENTER_TEXT);
	pEditMPrice->Draw();
	page->Draw();
	TextBox *m1 = new TextBox(200,130,243,30,"Movie 1 Price",LEFT_TEXT,1);
	TextBox *m2 = new TextBox(200,180,243,30,"Movie 2 Price",LEFT_TEXT,2);
	TextBox *m3 = new TextBox(200,230,243,30,"Movie 3 Price",LEFT_TEXT,3);
	TextBox *m4 = new TextBox(200,280,243,30,"Movie 4 Price",LEFT_TEXT,4);
	pEditMPrice->Draw();
	page->Draw();
	m1->Draw();
	m2->Draw();
	m3->Draw();
	m4->Draw();

    back->Draw();
    next->Draw();
    fstream fil;
    while(1)
    {

	fil.open("MOVIE.DAT",ios::binary|ios::in);
	MOVIE Movie[4];
	fil.read((char*)&Movie[0],sizeof(Movie));
	fil.read((char*)&Movie[1],sizeof(Movie));
	fil.read((char*)&Movie[2],sizeof(Movie));
	fil.read((char*)&Movie[3],sizeof(Movie));
	fil.close();
	mouse.ShowMouse(); // To show mouse
	mouse.GetMouseStatus(); // To get position of mouse
	pEditMPrice->EnableClickHandler();
	m1->EnableClickHandler();
	m2->EnableClickHandler();
	m3->EnableClickHandler();
	m4->EnableClickHandler();
	back->EnableClickHandler();
	next->EnableClickHandler();
	//while(fil.read((char*)&Movie,sizeof(Movie)))
	//{
	Movie[0].inputprice(m1->GetText());
	Movie[1].inputprice(m2->GetText());
	Movie[2].inputprice(m3->GetText());
	Movie[3].inputprice(m4->GetText());
	//}

		if(ButtonId==2)
		{
				fil.open("MOVIE.DAT",ios::binary|ios::out);
				fil.seekg(0,ios::beg);
				fil.write((char*)&Movie[0],sizeof(Movie));
				fil.write((char*)&Movie[1],sizeof(Movie));
				fil.write((char*)&Movie[2],sizeof(Movie));
				fil.write((char*)&Movie[3],sizeof(Movie));
				fil.close();
				del();
				AdminHome();

			}
		else if(ButtonId==1)
		{

			AdminHome();
		}

	}
	//getch();

}

void about()
{
	char ch;
	Window *pAbout = new Window(10,10,630,480,"ABOUT US");
	pAbout->Draw();
	back->Draw();
	for(int i=100;i<=150;i++)
	{
		line(i,100,i,300);
		delay(20);
	}
	for(int j=0;j<=50;j++)
	{
		line(i+j,100+j,i+j,150+j);
		delay(20);
	}
	for(int k=0;k<=50;k++)
	{
		line(i+j+k,100+j-k,i+j+k,150+j-k);
		delay(20);
	}
	for(int l=0;l<=50;l++)
	{
		line(i+j+k+l,100,i+j+k+l,300);
		delay(20);
	}
	i+=30;
	for(int m=0;m<=60;m++)
	{
		line(i+j+k+l+m,100,i+j+k+l+m,150);
		delay(20);
	}
	for(int n=0;n<=50;n++)
	{
		line(i+j+k+l+m+n,100,i+j+k+l+m+n,300);
		delay(20);
	}
	for(n=0;n<=60;n++)
	{
		line(i+j+k+l+m+50+n,100,i+j+k+l+m+50+n,150);
		delay(20);
	}
	char text[]={'M','o','v','i','e',' ','T','i','m','e'};
	char cred[]={'P','r','e','s','e','n','t','e','d',' ','b','y',' ','S','h','a','u','r','y','a',' ','a','n','d',' ','R','i','s','h','i','t'};
	char t[]={"M"};
	for(i=0;i<10;i++)
	{
		t[0]=text[i];
		outtextxy(300+10*i,310,t);
		delay(90);
	}
	for(j=0;j<31;j++)
	{
		t[0]=cred[j];
		outtextxy(200+10*j,330,t);
		delay(80);
	}
//	back->Draw();
	outtextxy(285,350,"Press Back to Return");
	 while(1)
	   {
		mouse.ShowMouse(); // To show mouse
		mouse.GetMouseStatus(); // To get position of mouse
		pAbout->EnableClickHandler();
		back->EnableClickHandler();
		if(ButtonId==1)
			AdminHome();
	   }
}
void chkadmin()
{
	fstream fil;
	fil.open("Admin.dat",ios::binary|ios::in|ios::out);
	fil.seekg(0,ios::end);
	if(fil.tellg()==0)
	{
	   fil.close();
	   setcolor(RED);
	   rectangle(40,200,600,220);
	   for(int i=0; i<560;i++)
	   {
		setcolor(WHITE);
		rectangle(41,201,40+i,219);
		delay(10);
	   }
	   AdminSignUp();
	}
	else
	{
	   fil.close();
	   welcome();
	}
}
void main()
{
	clrscr();
	int gd = DETECT,gm,errorcode;
	char ch;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");

		// read result of initialization
		errorcode = graphresult();

		if (errorcode != grOk)// an error occurred
		{
			cout<<"Graphics error :: "<<grapherrormsg(errorcode);
			cout <<"\n press any key to halt: ";
			getch();
			exit(1);// terminate with an error code
		}


    while(true)
    {
	chkadmin();


		while(kbhit())
		{
		 ch = getch();
		 if(ch==27)
		  exit(0);
		}
    }
    getch();

}
