//============================================================================
// Name        : Lab4.cpp
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
using namespace std;

int main(int argc, const char *argv[])
{
	int getstats, getcen, getnorm = 0;
	float total, max = 0;
	float avg = 0;
	char name[30];
	int recheck = 0;
	string rename ="Default";
	int filenum = 0;
	float data[10000];
	float offset = 0;
	float scale = 0;
	int max1, leng;
	int j = 0;
	ofstream outFS;
	if(argc < 2)
	{
		cout << "-n:   File number (vchar myfile [30]alue needed)" << endl
		<< "-o:   offset value (value needed)" << endl
		<<"-s:   scale factor (value needed)" << endl
		<<"-r:   Rename files (name needed)" << endl
		<<"-h:   Help (display how the program should be called,"
		<<"including the different input options)" << endl;
		return 0;
	}
	for(int i = 0; i < argc; i++)
	{
		//cout << argv[i] << endl; use to check input
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
		            cout<<"Invalid input"<<endl;
		            return 0;
		        }

		        filenum = atoi(argv[i+1]); // take in data from origin file
		       	sprintf(name, "Raw_data_%02d.txt",filenum);
		       	ifstream input;
		       	input.open(name);
		       	if(!input.is_open())
		       	{
		       		cerr << "Unable to open file when writing" << endl;
		       		return 0;
		       	}
		       	input >> leng;
	        	input >> max1;
	        	cout<< "\t " << leng << " " << max1 << endl; //print length and max
		        while(j < leng)
		        {
		        	input >> data[j];
		        	cout << "\t" << data[j]<< endl;
		        	j++;
		        }
		        input.close();

		}
		if(!strcmp(argv[i],"-o"))// get offset
		{
			 if(argv[i+1] == NULL) // check to make sure a number is given
			 {
				 cout<<"Invalid input"<<endl;
				 return 0;
			 }
			 offset = atoi(argv[i+1]);
			 //cout << endl << offset << " Thats the offset nerd" << endl; //use to check offset input
		}
		if(!strcmp(argv[i],"-s")) //get scale
		{
			if(argv[i+1] == NULL)
			{
				cout << "Invalid input" << endl;
				return 0;
			}
			scale = atoi(argv[i+1]);
			//cout << endl << scale << " Thats the scale nerd" << endl;
		}
		if(!strcmp(argv[i],"-r")) //get rename
		{
			 if(argv[i+1] == NULL) // check to make sure a number is given
			 {
				 	 cout<<"Invalid input"<<endl;
				 	 return 0;
			 }
			 recheck = 1;
			 rename = atoi(argv[i+1]);

		}
		if(!strcmp(argv[i],"-h"))
		{
			cout << "-n:   File number (value needed)" << endl
					<< "-o:   offset value (value needed)" << endl
					<<"-s:   scale factor (value needed)" << endl
					<<"-r:   Rename files (name needed)" << endl
					<<"-h:   Help (display how the program should be called,"
					<<"including the different input options)" << endl;
			return 0;
		}
	}
	for(int i = 0; i<=leng; i++)
	{
		total = data[i] + total;
		if(data[i] > max)
		{
			max = data[i];
		}
	}
	avg = (float) total / leng;
	if( getstats == 1)
	{
		string file = "Statistics_data_0" + to_string(filenum) + ".txt";
		outFS.open(file);
		outFS << avg << " " << max;
		outFS.close();
	}
	if(getnorm == 1)
	{

		string file = "Normalized_data_0" + to_string(filenum) + ".txt";
		outFS.open(file);

		for(int i= 0; i <=leng; i++)
		{
			float placehold = (float) data[i] / max1;
			outFS << placehold << endl;

		}
		outFS.close();

	}
	if(getcen == 1)
	{
		string file = "Centered_data_0" + to_string(filenum) + ".txt";
		outFS.open(file);
		for(int i= 0; i <=leng; i++)
				{
					float placehold = (float) data[i] - avg;
					outFS << placehold << endl;

				}
		outFS.close();
	}

	for(int i = 0; i <= leng; i++)
	{
		if(scale != 0)
		{
			float placehold = data[i];
			data[i] = placehold * scale;
		}
		if(offset != 0)
		{
			float placehold = data[i];
			data[i] = placehold + offset;
		}
		cout << endl << data[i];
	}
	if(scale != 0)
	{
		string file = "Scaled_data_0" + to_string(filenum) + ".txt";
		outFS.open(file);
		for(int i= 0; i <leng; i++)
		{

			outFS << data[i] << endl;

		}
		outFS.close();
	}
	if(offset != 0)
	{
		string file = "Offset_data_0" + to_string(filenum) + ".txt";
		outFS.open(file);
		for(int i=0; i <leng; i++)
		{
			outFS << data[i] << endl;
		}
		outFS.close();
	}
	if(recheck == 0)
	{
		char myfile[30] = "Lab4_writeC++_0.txt";
		outFS.open(myfile);
		if(!outFS.is_open())
		{
		     cerr << "Could not open file " << myfile << endl;
		     return 0;
		}
		for(int i=0; i < leng; i++)
		{
			outFS << data[i] << endl;
		}
		outFS.close();
	}
	string myfile = "Lab4" + rename + ".txt";
	outFS.open(myfile);
	if(!outFS.is_open())
	{
	     cerr << "Could not open file " << myfile << endl;
	     return 0;
	}
	for(int i=0; i <leng; i++)
	{
		outFS << data[i] << endl;
	}
	outFS.close();
	//cout << rename;
	cout << "The average of the original is " << avg << endl;
	cout << "The Max of the original is " << max << endl;
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
