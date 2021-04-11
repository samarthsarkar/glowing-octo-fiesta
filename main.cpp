// This c++ program detects the diseases cholera, malaria, influenza & typhoid
// on the basis of the symptoms experianced by the patient.

// Aim: The project aims to computerize real world hospital diagnosis so that
//     people living in the remotest parts of the world can access it free of
//     cost and avail its benefits

// Header files used in the program

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iomanip.h>

//CLASS OF THE PROGRAM********************************************************

class patient
{
	private:

	char name[20],gender[20];
	int age;
	float id;
	char condition;

	public:
	float retid()                   //Function returns ID of patient
	{
		 return id;
	}
	void input();                   //Function to input details
	void display();
	void dispcond();
	int prel_anal();
	int adv_anal();
	void choltyph();
	int malaria();
	void cholflu();
	void flutyph();
	void analysis();
};
//FUNCTIONS INCLUDED IN THE CLASS*********************************************

void patient::input()                                //inputs details
{
	cout<<"\n Enter the name of the patient:";
	gets(name);
	cout<<"\n Enter gender of the patient:";
	gets(gender);
	cout<<"\n Enter the age:";
	cin>>age;
	cout<<"\n Enter patient ID:";
	cin>>id;
}


void patient::display()                               //displays details
{
	cout<<"\n| name: "<<name;
	cout<<"  | gender: "<<gender;
	cout<<"  | age: "<<age;
	cout<<"  | id: "<<id;
	cout<<"  | condition: ";
	dispcond();
	cout<<" |";
}

//Functions Required for the program*************************************************

int patient::prel_anal()				//Performs preliminary analysis
{ 	char p1='n',p2='n';
	cout<<"\n Please answer the following questions for preliminary analysis :";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n\n Presence of mild and/or severe(high) fever: ";
	cin>>p1;
	cout<<"\n Sensation of mild or severe fatigue: ";
	cin>>p2;
	if(((p1=='y')||(p1=='Y'))&&((p2=='y')||(p2=='Y')))
	return(1);
	else
	return(0);
}

int patient::adv_anal()                          //Performs advanced analysis
{       int r=0,flag=0;
	char ch,a1='n',a2='n',a3='n',a4='n',a5='n';
	cout<<"\n Please answer the following questions for advanced analysis :";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n\n Instances of - ";
	cout<<"\n Vomitting: ";
	cin>>a1;
	cout<<"\n Diarrhea: ";
	cin>>a2;
	cout<<"\n Abdominal pain/cramps: ";
	cin>>a3;
	cout<<"\n Muscle pain: ";
	cin>>a4;
	cout<<"\n Cough,Sneezing or Sore throat: ";
	cin>>a5;
	if((a1=='y')||(a1=='Y'))
	{	if((a2=='y')||(a2=='Y'))
		flag=1;
		else if((a3=='y')||(a3=='Y'))
		flag=1;
		else
		flag=2;
	}
	if(flag==1)
		r=1;               //cholera and typhoid
	else if(flag==2)
		r=2;               //cholera typhoid and malaria
	else if(flag==0)
	{
		if((a4=='y')||(a4=='Y'))
			r=3;       //cholera and flu
		else if((a5=='y')||(a5=='Y'))
			r=4;       //flu and typhoid
		else
		{
			r=0;
			cout<<"\n No symptoms matched.";
		}
	}
	return(r);
}

void patient::choltyph()                          //Confirmatory analysis for cholera and typhoid
{
	patient P;
	char ch1='n',ch2='n',ty1='n',ty2='n',cd[20];

	cout<<"\n Please answer the following questions for confirmatory analysis :";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n Does patient experiance severe or prolonged dehydration : ";
	cin>>ch1;
	cout<<"\n Does patient experiance muscle cramps : ";
	cin>>ch2;
	cout<<"\n Does patient experiance severe headaches : ";
	cin>>ty1;
	cout<<"\n Have there been instances of blood in stool or urine : ";	//Intestinal bleeding
	cin>>ty2;
	if((((ch1=='y')||(ch1=='Y'))||((ch2=='y')||(ch2=='Y')))&&(((ty1=='n')||(ty1=='N'))&&((ty2=='n')||(ty2=='N'))))
	{
		condition='c';
	}
	else if((((ty1=='y')||(ty1=='Y'))||((ty2=='y')||(ty2=='Y')))&&(((ch1=='n')||(ch1=='N'))&&((ch2=='n')||(ch2=='N'))))
	{
		condition='t';
	}
	else
		cout<<"\n Condition does not match.";
}
int patient::malaria()                           //Confirmatory for Malaria
{
	patient P;
	char ml='n',cd[20];
	int r=0;
	cout<<"\n Please answer the following questions for confirmatory analysis :";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n Is the patient Anemic :";
	cin>>ml;
	if((ml=='y')||(ml=='Y'))
	{
		condition='m';
		r=1;
	}
	return(r);
}

void patient::cholflu()                           //Confirmatory for Cholera and Flu
{
	patient P;
	char ch1='n',ch2='n',fl1='n',fl2='n',cd[20];
	cout<<"\n Please answer the following questions for confirmatory analysis :";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n Does patient experiance severe or prolonged dehydration : ";
	cin>>ch1;
	cout<<"\n Does the patient have rapid heart rate :";
	cin>>ch2;
	cout<<"\n Does the patient experiance frequent coughing or sneezing :";
	cin>>fl1;
	cout<<"\n Does the patient experiance soreness of the throat or chest pain :";
	cin>>fl2;
	if((((ch1=='y')||(ch1=='Y'))||((ch2=='y')||(ch2=='Y')))&&(((fl1=='n')||(fl1=='N'))&&((fl2=='n')||(fl2=='N'))))
	{
		condition='c';
	}
	else if((((fl1=='y')||(fl1=='Y'))||((fl2=='y')||(fl2=='Y')))&&(((ch1=='n')||(ch1=='N'))&&((ch2=='n')||(ch2=='N'))))
	{
		condition='f';
	}
	else
		cout<<"\n Condition does not match.";
}

void patient::flutyph()                           //Confirmatory for Flu and Typhoid
{
	patient P;
	char fl1='n',fl2='n',ty1='n',ty2='n',cd[20];
	cout<<"\n Please answer the following questions for confirmatory analysis";
	cout<<"\n\n Answer with Y for a positive answer and N for a negative answer";
	cout<<"\n Does the patient experiance soreness of the throat or chest pain :";
	cin>>fl1;
	cout<<"\n Any instance of muscle cramping/pain: ";
	cin>>fl2;
	cout<<"\n Does the patient experiance severe appetite loss: ";
	cin>>ty1;
	cout<<"\n Have there been instances of blood in stool or urine : ";	//Intestinal bleeding
	cin>>ty2;
	if((((fl1=='y')||(fl1=='Y'))||((fl2=='y')||(fl2=='Y')))&&(((ty1=='n')||(ty1=='N'))&&((ty2=='n')||(ty2=='N'))))
	{
		condition='f';
	}
	else if((((ty1=='y')||(ty1=='Y'))||((ty2=='y')||(ty2=='Y')))&&(((fl1=='n')||(fl1=='N'))&&((fl2=='n')||(fl2=='N'))))
	{
		condition='t';
	}
	else
		cout<<"\n Condition does not match.";
}

void patient::analysis()
{
	int pr,m,r;
	char cd[20];
	pr=prel_anal();
	if(pr==1)
	{
		r=adv_anal();
		switch(r)
		{
			case 0: cout<<"\n conditions do not match";
				condition='o';
				break;
			case 1: cout<<"\n Probability of Cholera and Typhoid ";
				choltyph();
				break;
			case 2: cout<<"\n Probabilty of Cholera , Typhoid and Malaria ";
				m=malaria();
				if(m!=1)
				choltyph();
				break;
			case 3: cout<<"\n Probability of Cholera anf Influenza ";
				cholflu();
				break;
			case 4: cout<<"\n Probabilty of Influenza and Typhoid ";
				flutyph();
				break;
		}
	}
	cout<<"\n Detail input for select patient complete.";
}

void patient::dispcond()
{
	switch(condition)
	{
		case 'c':cout<<"Cholera";
			 break;
		case 'f':cout<<"Influenza";
			 break;
		case 'm':cout<<"Malaria";
			 break;
		case 't':cout<<"Typhoid";
			 break;
		case 'o':cout<<"Unidentifiable";
			 break;
		default :cout<<"Out of scope";
	}
}

char intro()
{
	char c;
	cout<<"\t\t WELCOME TO THE PORTABLE DISEASE ANALYISIS SYSTEM";
	cout<<"\n This c++ program detects the diseases cholera, malaria, influenza & typhoid";
	cout<<" on the basis of the symptoms experianced by the patient.";
	cout<<"\n Start program ?(y/n): ";
	cin>>c;
	return(c);
}

void create()
{
	patient P;
	int n,i,a1;
	fstream fout;
	fout.open("patient.dat",ios::out|ios::binary);
	cout<<"\n Enter the number of records you wish to list:";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		P.input();
		P.analysis();
		fout.write((char*)&P,sizeof(P));
	}
	fout.close();
}

void Delete()
{
	fstream fin,fout;
	int flag=0;
	patient P;
	float id1;
	fin.open("patient.dat",ios::in|ios::binary);
	fout.open("temp.dat",ios::out|ios::binary);
	if(!fin)
	{
		cout<<"\n File can not be found";
		exit(0);
	}
	cout<<"\n Enter the ID number you wish to delete:";
	cin>>id1;
	while(fin.read((char*)&P,sizeof (P)))
	{
		if(id1!=P.retid())
		{
			fout.write((char*)&P,sizeof (P));
		}
		else
		{
			cout<<"\n Record deleted.";
			flag=1;
		}
	}

	if(flag==0)
	cout<<"\n Record not found.";
	fin.close();
	fout.close();
	remove("patient.dat");
	rename("temp.dat","patient.dat");
}

void search()
{
	patient P;
	int t=0, pno;
	fstream fin;
	fin.open("patient.dat",ios::in|ios::binary);
	cout<<"\n Enter patient ID to be searched:";
	cin>>pno;
	if(!fin)
	{
		cout<<"\n File could not be opened";
		exit(0);
	}
	while(fin.read((char*)&P,sizeof(P)))
	{
		if(P.retid()==pno)
		{	P.display();
			t=1;
		}
		break;
	}
	if(t!=1)
	{
		cout<<"\n Record not found";
		fin.close();
	}
}

void display()
{
	fstream fin;
	patient P;
	fin.open("patient.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\nfile not found";
		exit(0);
	}
	while(fin.read((char*)&P,sizeof(P)))
	{
		P.display();
	}
	fin.close();
}

void insert()
 {	fstream fin,fout;
	fin.open("patient.dat",ios::in|ios::binary);
	fout.open("temp.dat",ios::out|ios::binary);
	if(!fin||!fout)
	{
		cout<<"\nerror - file could not be opened";
		exit(0);
	}
	patient P,T;
	cout<<"\nEnter details of new patient"<<endl;
	T.input();
	T.analysis();
	while(fin.read((char*)&P,sizeof(P)))
	{	if(P.retid()>T.retid())
		{	fout.write((char*)&T,sizeof(T));
			fout.write((char*)&P,sizeof(P));
			break;
		}
		else
		{	fout.write((char*)&P,sizeof(P));
		}
	}
	while(fin.read((char*)&P,sizeof(P)))
		fout.write((char*)&P,sizeof(P));
	fin.close();
	fout.close();
	remove("patient.dat");
	rename("temp.dat","patient.dat");
 }

void modify()
{
	patient P;
	float id,t=0;
	cout<<"\n Enter patient ID of patient to be modified:";
	cin>>id;
	fstream f;
	f.open("patient.dat",ios::in|ios::out|ios::binary|ios::ate);
	if(!f)
	{
		cout<<"\n error - file could not be opened";
		exit(0);
	}
	while(f.read((char*)&P,sizeof(P)))
	{	if(P.retid()==id)
		{	cout<<"\n enter new values;";
			P.input();
			P.analysis();
			f.seekp(-1*sizeof(P),ios::cur);
			f.write((char*)&P,sizeof(P));
			t=1;
			break;
		}
	}
	if(t==0)
		cout<<"\n record not found";
	f.close();
}

void append()
{
	patient P;
	char ans='y';
	ofstream fout("patient.dat",ios::binary|ios::app);
	if(!fout)
	{
		cout<<"\n File could not be opened.";
		exit(0);
	}
	while(ans=='y'||ans=='Y')
	{
		P.input();
		P.analysis();
		fout.write((char*)&P,sizeof(P));
		cout<<"\n Record created";
		cout<<"\n Do you wish to enter more data ?";
		cin>>ans;
	}
	fout.close();
	cout<<"\n Appending complete.";
}
