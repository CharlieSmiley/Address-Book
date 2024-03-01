//
//Program Title: Address Book
//Project File: Project_08_Fix.cpp
//Name: Charlie Smiley
//Course Section: CPE-211-02
//Lab Section: 1
//Due Date: 11/02/21
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <climits>
#include <cstdlib>

using namespace std;

//Person Struct
struct Person
{
	string firstName;
	string lastName;
	string phoneNumber;
};

//Address Struct
struct Address
{
	string street;
	string city;
	string state;
	int zip;
};

//Top LvL Struct
struct Resident
{
	Person person;
	Address address;
};

void OpenIn(ifstream& Infile);
void OpenOut(ofstream& Outfile);
void Header(ofstream& Outfile);
bool Input(ifstream& Infile, Resident Entry);
void Output(ofstream& Outfile, Resident Entry, int RN);

int main()
{
	//File Streams
	ifstream Infile;
	ofstream Outfile;

	//Varibles
	int RN;
  	RN = 1;
	Resident Entry;

	OpenIn(Infile); //Opening Input File

	OpenOut(Outfile); //Opening Output File

	Header(Outfile); //Calling Header Func

	cout << "Processing information. Please Wait...." << endl << endl;

	while(!Infile.eof())
	{
        if(Input(Infile, Entry) == true)
        {
            Output(Outfile, Entry, RN);
            RN++;
        }
        else
        {
          cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
          cout << "==> An error has occured while reading" << endl;
          cout << "==> the input file. Error in file content." << endl;
          cout << "==> Terminating program!!!" << endl;
          cout << string(47,'*') << endl << endl;
          break;
          }
	}
	if(Infile.eof())
	{
		Outfile << left << setw(7) << string(5,'-');
		Outfile << left << setw(20) << string(9,'-');
		Outfile << left << setw(15) << string(10,'-');
		Outfile << left << setw(20) << string(4,'-');
		Outfile << left << setw(12) << string(12,'-');

		cout << "Program has finished execution." << endl << endl;
	}
	Infile.close();
	Outfile.close();

	return 0;
}	

//Infile Func
void OpenIn(ifstream& Infile)
{
	//InFile Prompt
	string in;
	cout << endl;
	cout << "Enter the name of the input file: ";
	cin >> in;
	cout << in << endl << endl;
	Infile.open(in);

	//Infile Test
	while(Infile.fail())
	{
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Input File failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << in << endl;
		cout << "==> Please try again..." << endl;
		cout << string(47,'*') << endl << endl;

		cin.clear();
		Infile.clear();

		cout << endl;
		cout << "Enter the name of the input file: ";
		cin >> in;
		cout << in << endl << endl;
		Infile.open(in);
	}
}

//Outfile Func
void OpenOut(ofstream& Outfile)
{
	//OutFile Prompt
	string out;
	cout << endl;
	cout << "Enter the name of the output file: ";
	cin >> out;
	cout << out << endl << endl;
	Outfile.open(out);

	//Outfile Test
	while(Outfile.fail())
	{
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << out << endl;
		cout << "==> Please try again..." << endl;
		cout << string(47,'*') << endl << endl;

		cin.clear();
		Outfile.clear();

		cout << endl;
		cout << "Enter the name of the output file: ";
		cin >> out;
		cout << out << endl << endl;
		Outfile.open(out);
	}
}

//Header Func
void Header(ofstream& Outfile)
{
	Outfile << left << setw(7) << "Entry";
	Outfile << left << setw(20) << "Last Name";
	Outfile << left << setw(15) << "First Name";
	Outfile << left << setw(20) << "City";
	Outfile << left << setw(12) << "Phone Number" << endl;

	Outfile << left << setw(7) << string(5,'-');
	Outfile << left << setw(20) << string(9,'-');
	Outfile << left << setw(15) << string(10,'-');
	Outfile << left << setw(20) << string(5,'-');
	Outfile << left << setw(12) << string(12,'-') << endl;
}

bool Input(ifstream& Infile, Resident Entry)
{
	//Accessing Info
	getline(Infile, Entry.person.phoneNumber, '\n');
	
	getline(Infile, Entry.person.lastName, '\n');
	
	getline(Infile, Entry.address.street, '\n');
	
	getline(Infile, Entry.address.city, '\n');
	
	getline(Infile, Entry.address.state, '\n');
	
	Infile >> Entry.address.zip;
	Infile.ignore(INT_MAX, '\n');
	
	getline(Infile, Entry.person.firstName, '\n');
 
 if(Infile.good())
 {
 return true;
 }
 else
 {
 return false;
 }
}

void Output(ofstream& Outfile, Resident Entry, int RN)
{
	//Info Dump
	Outfile << left << setw(7) << RN;
	Outfile << left << setw(20) << Entry.person.lastName;
	Outfile << left << setw(15) << Entry.person.firstName;
	Outfile << left << setw(20) << Entry.address.city;
	Outfile << left << setw(12) << Entry.person.phoneNumber << endl;
}
