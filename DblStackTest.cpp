#include <iostream>
#include "DblStack.h"
using namespace std;



int main()
{
/***********************************************************/
	cout << "Test creating and adding values to stacks via push function" << endl; 
	DblStack s1, s2, s4; 

	s1.push(12.0);
	s1.push(15.0); 

	for (double i = 1; i <= 20; i++)
	{
		s2.push(i); 
	}

/***********************************************************/
	cout << endl; 
	cout << "Testing out size funtion" << endl; 
	cout << s1.size() << endl; 
	cout << s2.size() << endl; 
	cout << s4.size() << endl;

/**********************************************************/

	cout << endl; 
	cout << "Test out isEmpty fucntion" << endl; 
	DblStack s3; 
	cout << s3.isEmpty() << endl; 

/********************************************************/

	cout << endl; 
	cout << "Test top function" << endl; 
	cout << s1.top() << endl; 
	cout << s2.top() << endl;

/*******************************************************/

	cout << endl; 
	cout << "Testing the pop function" << endl; 
	s2.pop();
	cout << s2.top() << endl;
	cout << s2.size() << endl;

/*****************************************************/

	cout << endl; 
	cout << "Testing Deconstructor" << endl;
	s1.~DblStack(); 
	cout << s1.size() << endl; 
/********************************************************/

	cout << endl; 
	cout << "Testing the assignment operator and copy constructor" << endl; 
	s4 = s2; 
	s4.pop();
	cout << s2.top() << endl; 
	cout << s4.top() << endl; 



	cout << "\n\npress enter to end pgm";
	char tt;
	tt = cin.get();


	return 0;

}