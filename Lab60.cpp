//============================================================================
// Name        : Lab5.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;
class Signal{
private:

public:
	int length;
	int maximumvalue;
	int minimumvalue;
	float average;
	vector <float> rawdata;
	vector <float> moddata;

	Signal();
	Signal(int filenum);
	Signal(string filename);
	~Signal();
	void offset(int off, Signal s);
	void scale(int scal,Signal s);
	void center(Signal s);
	void normalize(Signal s);
	void Statistics(Signal s);
	void Sig_info(Signal s);
	void Save_file(Signal s);
	void Help();
	void operator +(double num);
	void operator *(double multi);
};
void Signal::operator +(double num)
{
	for(int i = 0; i < length; i++)
	{
		moddata[i] = (rawdata[i]+num);
	}
}
void Signal::operator *(double multi)
{
	for(int i =0; i < length; i++)
	{
		moddata[i] = (rawdata[i] * multi);
	}
}
Signal::~Signal()
{
}
Signal::Signal(int filenum)
{
	char name[30];
	int placehold;
	ifstream input;
	if(!input.is_open())
	{
		//cerr << "Unable to open file when writing" << endl;
	}
	sprintf(name, "Raw_data_%02d.txt",filenum);
	input.open(name);
	input >> length;
	input >> maximumvalue;
	cout<< "\t" << length << " " << maximumvalue << endl; //print length and max
	for(int j = 0; j < length; j++)
	{
		input >> placehold;
		rawdata.push_back(placehold);
		moddata.push_back(placehold);
		cout << j << "\t" << placehold << endl;

	}
	input.close();

}
Signal::Signal()
{
	char name[30];
	int placehold;
	ifstream input;
	sprintf(name, "Raw_data_01.txt");
	input.open(name);
	input >> length;
	input >> maximumvalue;
	cout <<"\t" << length << " " << maximumvalue << endl; //print length and max
	for(int i = 0; i < length; i++)
	{
		input >> placehold;
		rawdata.push_back(placehold);
		moddata.push_back(placehold);
		cout << "\t" << placehold << endl;

	}
}
void Signal::offset(int off, Signal s)
{
	for(int i = 0; i < s.rawdata.size(); i++ )
	{
		int placehold = moddata[i];
		placehold = placehold + off;
		cout << "\t" << placehold << endl;
		moddata[i] = placehold;
	}
}
void Signal::scale(int scal,Signal s)
{
	for(int i = 0; i < rawdata.size(); i++ )
	{
		int placehold = moddata[i];
		placehold = placehold * scal;
		cout << "\t" << placehold << endl;
		moddata[i] = placehold;
	}
}
void Signal::Help()
{
	cout << "-n:   File number (value needed)" << endl;
	cout << "-o:   offset value (value needed)" << endl;
	cout << "-s:   scale factor (value needed)" << endl;
	cout << "-r:    Rename files (name needed)" << endl;
	cout << "-h:   Help (display how the program should be called" << endl;
	cout << "Example /My_Lab4_program -n 3 -o 2.5" << endl;

}
void Signal::center(Signal s)
{
	//float placehold = 0;
	//for(int i = 0; i <s.moddata.size(); i++)
	//{
	//	placehold = (float) rawdata[i] - (float) average;
	//	moddata[i] = placehold;
	//}
	operator+(-average);
}
void Signal::Statistics(Signal s)
{
	double total = 0;
	double max = 0;
	double min = 1000;
	for(int i = 0; i <s.rawdata.size(); i++)
	{
		total = rawdata[i] + total;
		if(rawdata[i] > max)
		{
			max = rawdata[i];
		}
		if(rawdata[i] < min)
		{
			min = rawdata[i];
		}
	}
	average = (double) total / s.length;
	maximumvalue = (int) max;
	minimumvalue = (int) min;
	cout << "The maximum value for the origianl is " << max << endl;
	cout << "The minimum value for the original is " << min << endl;
	cout << "The average for the original is " << average << endl;
}
void Signal::normalize(Signal s)
{
	//float placehold = 0;
	//for(int i = 0; i <s.moddata.size(); i++)
	//{
	//	placehold = (float) s.moddata[i] / s.maximumvalue;
	//	moddata[i] = placehold;
	//	cout << s.moddata[i] << endl;;
	//}
	operator*((double)1/maximumvalue);
}
void Signal::Sig_info(Signal s)
{
	float total = 0;
	float max = 0;
	float min = 1000;
	float avg;
	for(int i = 0; i < s.moddata.size() ; i++)
	{
		cout << s.moddata[i] << endl;
		total = s.moddata[i] + total;
		if(s.moddata[i] > max)
		{
			max = s.moddata[i];
		}
		if(s.moddata[i] < min)
		{
			min = s.moddata[i];
		}

	}
	cout << "The max for the mod is " << max << endl;
	cout << "The minimum for the mod is " << min << endl;
	avg = (float) total / (float) length;
	cout << "The average for the mod is " << avg << endl;
}
void Signal::Save_file(Signal s)
{
	ofstream outFS;
	char myfile[30] = "Lab5_writeC++_0.txt";
	outFS.open(myfile);
	if(!outFS.is_open())
	{
		cerr << "Could not open file " << myfile << endl;
	}
	for(int i=0; i < s.moddata.size(); i++)
	{
		outFS << s.moddata[i] << "   " << endl;
	}
	outFS.close();
}
Signal operator+(Signal s, Signal s2)
{
	if(s.length != s2.length)
	{
		cout << "These files don't contain the same length" << endl;
		return s;
	}
	if(s.maximumvalue < s2.maximumvalue)
	{
		s.maximumvalue = s2.maximumvalue;
	}
	if(s.minimumvalue > s2.minimumvalue)
	{
		s.minimumvalue = s2.minimumvalue;
	}
	for(int i = 0; i < s.length; i++)
	{
		s.rawdata[i] = s.rawdata[i] + s2.rawdata[i];
		s.moddata[i] = s.moddata[i] + s2.rawdata[i];
	}
	s.Sig_info(s);
	return s;

}
int main(int argc, const char *argv[])
{
	int choice;
	int choice1 , choice2;
	int exit = 0;
	int filenum = 0, off = 0, scale = 0, save = 0; //Input options
	int Default = 0; //Checks to see if a non-default is chosen
	int getstats = 0, getcen = 0, getnorm = 0; //Options
	int helpo = 0;
	for(int i = 0; i < argc; i++)
	{
		if(!strcmp(argv[i], "-S"))
		{
			getstats =1;
		}
		if(!strcmp(argv[i], "-C"))
		{
			getcen = 1;
		}
		if(!strcmp(argv[i], "-N"))
		{
			getnorm = 1;
		}
		if(!strcmp(argv[i],"-n"))
		{
			if(argv[i+1] == NULL) // check to make sure a number is given
			{
				Default = 0;
			}
			else
			{

				filenum = atoi(argv[i+1]);
				Default = 1;
			}
		}
		if(!strcmp(argv[i],"-o"))
		{
			if(argv[i+1] == NULL)
			{
				cout << "This is an incorrect input" << endl;
			}
			off = atoi(argv[i+1]);
		}
		if(!strcmp(argv[i],"-s"))
		{
			if(argv[i+1] == NULL)
			{
				cout << "This is an incorrect input" << endl;
			}
			scale = atoi(argv[i+1]);
		}
		if(!strcmp(argv[i],"-h"))
		{
			helpo = 1;
		}

	}
	if(Default != 0)
	{
		Signal S1(filenum);
		while(exit !=1)
		{
			if(off != 0)
			{
				S1.offset(off,S1);
			}
			if(scale !=0)
			{
				S1.scale(scale, S1);
			}
			if(helpo!=0)
			{
				S1.Help();
			}
			S1.Statistics(S1);
			if(getcen !=0)
			{
				S1.center(S1);
			}
			if(getnorm != 0)
			{
				S1.normalize(S1);
			}
			if(getstats !=0)
			{
				S1.Sig_info(S1);
			}
			if(save !=0)
			{
				S1.Save_file(S1);
			}
			cout << "Menu" << endl << "1.Offset" << endl << "2.Scale" << endl;
			cout << "3.Center" << endl << "4.Normalize" << endl << "5.Stats" << endl;
			cout << "6.Save File" << endl << "7.Exit" << endl;
			cin >> choice;
			filenum = 0;
			off = 0;
			scale = 0;
			getstats = 0;
			getcen = 0;
			getnorm = 0;
			if(choice == 1)
			{
				cout << "How much would you like to offset?" << endl;
				cin >> off;
			}
			if(choice == 2)
			{
				cout << "How much would you like to scale?" << endl;
				cin >> scale;
			}
			if(choice == 3)
			{
				getcen = 1;
			}
			if(choice == 4)
			{
				getnorm = 1;
			}
			if(choice == 5)
			{
				getstats = 1;
			}
			if(choice == 6)
			{
				save = 1;
			}
			if(choice == 7)
			{
				exit = 1;
			}
		}
	}

	else
	{
		Signal S2(1);
		while(exit !=1)
		{
			if(off != 0)
			{
				S2.offset(off,S2);
			}
			if(scale !=0)
			{
				S2.scale(scale, S2);
			}
			if(helpo!=0)
			{
				S2.Help();
			}
			S2.Statistics(S2);
			if(getcen !=0)
			{
				S2.center(S2);
			}
			if(getnorm != 0)
			{
				S2.normalize(S2);
			}
			S2.Sig_info(S2);
			S2.Save_file(S2);
			cout << "Menu" << endl << "1.Offset" << endl << "2.Scale" << endl;
			cout << "3.Center" << endl << "4.Normalize" << endl << "5.Stats" << endl;
			cout << "6.Save File" << endl << "7.Exit" << endl;
			cin >> choice;
			filenum = 0;
			off = 0;
			scale = 0;
			getstats = 0;
			getcen = 0;
			getnorm = 0;
			if(choice == 1)
			{
				cout << "How much would you like to offset?" << endl;
				cin >> off;
			}
			if(choice == 2)
			{
				cout << "How much would you like to scale?" << endl;
				cin >> scale;
			}
			if(choice == 3)
			{
				getcen = 1;
			}
			if(choice == 4)
			{
				getnorm = 1;
			}
			if(choice == 5)
			{
				getstats = 1;
			}
			if(choice == 6)
			{
				save = 1;
			}
			if(choice == 7)
			{
				exit = 1;
			}
		}
	}
cout << "Choose 2 files to add together" << endl;
cin >> choice1 >> choice2;
Signal s1(choice1);
Signal s2(choice2);
Signal s3 = s1 + s2;
s3.Sig_info(s3);
return 0;
}

