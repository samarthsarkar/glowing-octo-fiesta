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
