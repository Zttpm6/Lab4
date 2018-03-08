// Lab4_strings.cpp
// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++11
//      or:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <string>

using namespace std;

// Complete the assignments stated in the comments.
int main()
{
// ****************************************************************************
// Declare and initialize four or five strings. Use different ways of
// initializing, as shown in Table 7.1 (Lecture 7).
// Try all the operations in Table 7.2 (Lecture 7) using the strings that
// you declared.
	// ****************************************************************************
	string s1("Dogs are ok");
	int choice = 1;
	string s2 (s1);
	string s3 = s1;
	string s4 = "Choose 1 to do again if not press any button but 1";
	string s5(5, '1');
	string s6;
	while (choice == 1)
	{
		cout << s1 << endl;

		while(s6.empty() == 1)
		{
			cin >> s6;
		}
		for(int i = 0; s6.size()> i; ++i)
		{
			cout << s6[i];
		}
		s6 = s6 + s1;
		cout << endl << s6 << endl;
		cout << s4 << endl;
		cin >> choice;
	}
	// -----------------------------------------------------------------------
	        string line;
	        int num = 0;
	        int alpha = 0;
	        int word;

	        cout << "\nEnter some text:" << endl;
	        cin >> line;
	        cout << line << endl << endl;
	        for(int i = 0; line.size()> i; ++i)
	        		{
	        			if(isalnum(line[i])==1)
	        			{
	        				num = num +1;

	        			}
	        			if(isalpha(line[i])==1)
	        			{
	        				alpha = alpha +1;
	        			}
	        		}
	        cout << "Amount of Numbers" << num << endl << "Amount of Letters" << alpha <<endl;


	// ****************************************************************************
	// Use "Range for" loops (L7_Ex6_Strings.cpp) and operations in table 7.3 to:
	// 1) Count the number of letters in your input line above;
	// 2) Count the number of digits;
	// 3) Count the number of words (may be separated by white spaces, dots, etc.);

	// 4) change the case of the letters (upper to lowercase and vice-versa).
	// 5) Replace any whitespace with a dot ('.').
	// Print the converted text in 4) and 5)
	// ****************************************************************************

	        return 0;
}
