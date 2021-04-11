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
