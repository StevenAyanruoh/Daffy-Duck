// File name: PolyTest.cpp
// // Author: Steven Ayanruoh	
// VUnetid: ayanrus
// Email: steven.ayanruoh@vanderbilt.edu
// Class: CS201
// Honor statement: I have neither given nor received unauthorized help on this assignment.
// Date: 9-4-2014
// Assignment Number: 1
// Description: Exercise the Poly class                 
//
//
// Last Changed: 9/9/2014


#include <iostream>
#include <stdexcept>
#include "Poly_Project_1.h"
using namespace std;
const string PASS("pass");
const string FAIL("fail");


	void testDefault_Constructor(ostream&out);
	void testSetCoeff(ostream & out);
	void testDegree(ostream&out);
	void testRetrieveCoeff(ostream&out);
	void testIncrementCoeff(ostream&out);
	void testToString(ostream&out);
	void testNumOfTerms(ostream &out);
	void testEvaluate(ostream&out);
	void testAdd(ostream&out);
	void testAdditionOpperator(ostream&out);
	void testEquals(ostream&out);
	void testDerivative(ostream&out);
	void polyObjectTest(ostream &out);
	
	int main()
	{



		polyObjectTest(cout);
		

		cout << "Done testing" << endl;
		cout << "Press enter to end pgm" << endl;
		char tt;
		tt = cin.get();


		return 0;

	}

	void polyObjectTest(ostream & out) {
		testDefault_Constructor(cout);
		testSetCoeff(cout);
		testDegree(cout);
		testRetrieveCoeff(cout);
		testIncrementCoeff(cout);
		testToString(cout);
		testNumOfTerms(cout);
		testEvaluate(cout);
		testAdd(cout);
		testAdditionOpperator(cout);
		testEquals(cout);
		testDerivative(cout);

	}

	void testDefault_Constructor(ostream&out)
	{

		out << "This test is to determine whether or not the defualt constructor " << endl;
		out << "properly initializes a poly object to zero." << endl;
		Poly poly_empty;
		out << "This polynomial should not have a non zero value: " << poly_empty << endl;
		out << "Deafult Constructor test: " << PASS << endl;
		out << endl;
		out << endl;
		out << endl;
	}

	void testSetCoeff(ostream & out)
	{
		Poly p1, p2, p3, p4;


		out << "The follwing test is to determine what is an accepted coefficient value" << endl;
		out << "for a poly object." << endl;
		out << endl;
		//This polynomial shows off negative and positive coefficents
		p1.setCoeff(-500.0, 6); p1.setCoeff(20.0, 2);
		out << "This polynomial contains both positive and negative coefficients:\n " << p1 << endl;
		out << "Set Coefficient test: " << PASS << endl;
		out << endl;


		out << "This polynomial was created using an integer rather than a double value:\n" << p4 << endl;
		// This creates a coefficent using an int rather than a double 
		p4.setCoeff(-29888, 5);
		out << "Set Coefficient test: " << PASS << endl;
		out << endl;


		out << "This test tries to create a polynomial with a negative exponent: \n" << endl;
		// This tries to create a polynomial with a negative exponet 
		try {
			cout << "Expect an \"out_of_range\" exception" << endl;
			p2.setCoeff(-29888.0, -5);  // This statement will throw an exception
			cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;

		}
		catch (std::out_of_range& excpt) {
			cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
			out << "Set Coefficient test: " << FAIL << endl;
			out << endl;
		}


		out << "This test tries to create a polynomial with an exponent larger than MAXPOLY: \n" << endl;
		// This tries to create a polynomial with an exponent larger than MAXPOLY
		try {
			cout << "Expect an \"out_of_range\" exception" << endl;
			p3.setCoeff(25.0, 500);  // This statement will throw an exception
			cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
		}
		catch (std::out_of_range& excpt) {
			cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
			out << "Set Coefficient test: " << FAIL << endl;
			out << endl;
		}

	}

	void testDegree(ostream & out)
	{
		Poly p1, p2;

		p1.setCoeff(13.0, 25);
		p2.setCoeff(-96.0, 49);
		p2.setCoeff(56.0, 6);

		out << "These test are to determine what the degree of the poly object is. \n" << endl;
		out << endl;

		size_t p1_real = 25;
		out << "This polynomial should be of power " << p1_real << ": \n " << p1 << endl;


		if (p1.degree() == p1_real) {
			out << "Get Degree test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Set Coefficient test: " << FAIL << endl;
		}

		size_t p2_real = 49;
		out << "This polynomial should be of power " << p2_real << ": \n " << p2 << endl;

		if (p2.degree() == p2_real) {
			out << "Get Degree test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Set Coefficient test: " << FAIL << endl;
		}



	}

	void testRetrieveCoeff(ostream& out) {

		out << "The following test are to determine what the coefficeint of a poly object is\n based on it's degree. \n" << endl;
		out << endl;
		Poly p3, p4, p5;

		p3.setCoeff(25.0, 6);
		p4.setCoeff(65.0, 26);
		p5.setCoeff(25.0, 5);


		out << "This test retrieves a zero coefficeint value of a polynomial: " << p5 << endl;
		if (p5.retrieveCoeff(6) == 0) {
			out << "Retrieved Coefficient: " << p5.retrieveCoeff(6) << endl;
			out << "Retrieve Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Retrieve Coefficient test: " << FAIL << endl;
			out << endl;
		}

		out << "This test retrieves a non zero coefficeint value of a polynomial: " << p4 << endl;
		if (p4.retrieveCoeff(26) == 65) {
			out << "Retrieved Coefficient: " << p4.retrieveCoeff(26) << endl;
			out << "Retrieve Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Retrieve Coefficient test: " << FAIL << endl;
			out << endl;
		}

		out << "This test tries to retrieve a coefficeint value of a polynomial\nusing a degree greater than 49:  " << p5 << endl;
		if (p3.retrieveCoeff(63) == 0) {
			out << "Retrieved Coefficient: " << p3.retrieveCoeff(63) << endl;
			out << "Retrieve Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Retrieve Coefficient test: " << FAIL << endl;
			out << endl;
		}


	}

	void testIncrementCoeff(ostream&out) {
		out << "The following test are to test adding coefficients to exisitng\npolynomial coefficeints." << endl;
		out << endl;
		Poly p1, p2, p5, p4;

		p1.setCoeff(12.0, 6);
		p2.setCoeff(96.23, 9);
		p4.setCoeff(1.0, 2);

		out << "Original Coeffient: " << p4.retrieveCoeff(2) << endl;
		p4.incrementCoeff(-2, 2);
		if (p4.retrieveCoeff(2) == -1) {
			out << "Incremented Coefficient: " << p4.retrieveCoeff(2) << endl;
			out << "Increment Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Incremented Coefficient: " << p4.retrieveCoeff(2) << endl;
			out << "Increment Coefficient test: " << FAIL << endl;
			out << endl;
		}


		out << "Original Coeffient: " << p1.retrieveCoeff(6) << endl;
		p1.incrementCoeff(-2, 6);
		if (p1.retrieveCoeff(6) == 10){
			out << "Incremented Coefficient: " << p1.retrieveCoeff(6) << endl;
			out << "Increment Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Incremented Coefficient: " << p1.retrieveCoeff(6) << endl;
			out << "Increment Coefficient test: " << FAIL << endl;
			out << endl;
		}

		out << "Original Coeffient: " << p2.retrieveCoeff(9) << endl;
		p2.incrementCoeff(+2, 9);
		if (p2.retrieveCoeff(9) == 98.23){
			out << "Incremented Coefficient: " << p2.retrieveCoeff(9) << endl;
			out << "Increment Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Incremented Coefficient: " << p2.retrieveCoeff(9) << endl;
			out << "Increment Coefficient test: " << FAIL << endl;
			out << endl;
		}

		out << "Original Coeffient: " << p2.retrieveCoeff(10) << endl;
		p2.incrementCoeff(+2, 10);
		if (p2.retrieveCoeff(10) == 2){
			out << "Incremented Coefficient: " << p2.retrieveCoeff(10) << endl;
			out << "Increment Coefficient test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Incremented Coefficient: " << p2.retrieveCoeff(10) << endl;
			out << "Increment Coefficient test: " << FAIL << endl;
			out << endl;
		}



		try {
			cout << "Expect an \"out_of_range\" exception" << endl;
			p5.incrementCoeff(25.0, 100); p5.setCoeff(-0.0562, 100);  // This statement will throw an exception
			cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
		}
		catch (std::out_of_range& excpt) {
			cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
			out << "Increment Coefficient test: " << FAIL << endl;
			out << endl;
		}


	}

	void testToString(ostream&out) {
		out << "The following test are to see how well the toString functions works." << endl;
		out << endl;


		Poly p1, p2, p3, p4;

		p1.setCoeff(10.0, 0);
		p1.setCoeff(20.0, 1);
		p1.setCoeff(5.0, 2);

		p2.setCoeff(17.25, 0);
		p2.setCoeff(-27.0, 1);
		p2.setCoeff(2.0, 2);

		p3.setCoeff(-105.0, 0);
		p3.setCoeff(-14.0, 1);
		p3.setCoeff(5.0, 3);


		string p1_test = " +5*X^2 +20*X^1 +10";
		out << "Test String: " << p1_test << endl;

		if (p1.toString().compare(p1_test) == 0) {
			out << "Original String: " << p1 << endl;
			out << "String test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "String test: " << FAIL << endl;
			out << endl;
		}


		string p2_test = " +2*X^2 -27*X^1 +17.25";
		out << "Test String: " << p2_test << endl;
		if (p2.toString().compare(p2_test) == 0) {
			out << "Original String: " << p2 << endl;
			out << "String test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "String test: " << FAIL << endl;
			out << endl;
		}


		string p3_test = " +50000*X^-2 -14*X^1 -108";
		out << "Test String: " << p3_test << endl;
		if (p3_test.compare(p3.toString()) == 0) {
			out << "Original String: " << p3 << endl;
			out << "String test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "String test: " << FAIL << endl;
			out << endl;
		}

	}

	void testNumOfTerms(ostream &out) {
		out << "The following test are to determine how many terms are in a poly object." << endl;
		out << endl;
		Poly p1, p2, p3;


		double j = 0.0;
		p1.setCoeff(0.0, 0);
		for (size_t i = 1; i < MAXPOLY; i++) {
			j++;
			p1.setCoeff(j, i);
		}


		double k = 0.0;
		p2.setCoeff(0.0, 0);
		for (size_t i = 1; i < MAXPOLY; i += 2) {
			k = k + 2;
			p2.setCoeff(0.0, i);
		}

		double l = 10.0;
		p3.setCoeff(0.0, 0);
		for (size_t i = 1; i < MAXPOLY; i += 3) {
			l = l * 2;
			p3.setCoeff(l, i);
		}

		size_t one = 49;
		out << "Actual Size: " << one << endl;
		if (p1.numOfTerms() == one) {
			out << "Returned Value: " << p1.numOfTerms() << endl;
			out << "NUmber of Terms test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Number of Terms test: " << FAIL << endl;
			out << endl;
		}

		size_t three = 17;
		out << "Actual Size: " << three << endl;
		if (p3.numOfTerms() == 17) {
			out << "Returned Value: " << p3.numOfTerms() << endl;
			out << "NUmber of Terms test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Number of Terms test: " << FAIL << endl;
			out << endl;
		}


		size_t two = 0;
		out << "Actual Size: " << two << endl;
		if (p2.numOfTerms() == 0) {
			out << "Returned Value: " << p2.numOfTerms() << endl;
			out << "NUmber of Terms test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Number of Terms test: " << FAIL << endl;
			out << endl;

		}
	}

	void testEvaluate(ostream&out){
		out << "The following test are to determine how well polynomials are evaluated." << endl;
		out << endl;
		Poly p1, p2, p3;

		p1.setCoeff(1.0, 4);
		p2.setCoeff(2.0, 2);
		p2.setCoeff(-5.0, 1);
		p3.setCoeff(-4.0, 2);




		out << "Polynomial: " << p1 << endl;
		out << "X-value: 2.0 " << endl;
		if (p1.evaluate(2.0) == 16) {
			out << "Returned Value: " << p1.evaluate(2.0) << endl;
			out << "Evaluate test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Evaluate test: " << FAIL << endl;
			out << endl;
		}

		out << "Polynomial: " << p2 << endl;
		out << "X-value: -10.0 " << endl;
		if (p2.evaluate(-10) == 250) {
			out << "Returned Value: " << p2.evaluate(-10.0) << endl;
			out << "Evaluate test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Evaluate test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial: " << p3 << endl;
		out << "X-value: 1.0 " << endl;
		if (p3.evaluate(1.0) == -4) {
			out << "Returned Value: " << p3.evaluate(1.0) << endl;
			out << "Evaluate test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Evaluate test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial: " << p1 << endl;
		out << "X-value: 0.0 " << endl;
		if (p1.evaluate(0) == 0) {
			out << "Returned Value: " << p1.evaluate(0.0) << endl;
			out << "Evaluate test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Evaluate test: " << FAIL << endl;
			out << endl;
		}




	}

	void testAdd(ostream&out){

		out << "The following test are to determine how well one polynomial gets\nadded to another" << endl;
		Poly p1, p2, p3, p4;

		p1.setCoeff(1.0, 4);
		p1.setCoeff(18.0, 44);
		p1.setCoeff(0.253, 2);

		p2.setCoeff(2.0, 2);
		p2.setCoeff(-5.0, 1);

		p3.setCoeff(-4.0, 2);
		p3.setCoeff(12.0, 6);
		p4.setCoeff(-96.23, 9);
		p4.setCoeff(1.0, 2);

		string p12_ans = " +18*X^44 +1*X^4 +2.253*X^2 -5*X^1";
		out << "Polynomial 1: " << p1 << endl;
		out << "Polynomial 2: " << p2 << endl;
		out << "Correct Answer: " << p12_ans << endl;
		p1.add(p2);
		if (p1.toString().compare(p12_ans) == 0) {
			out << "Returned Answer: " << p1 << endl;
			out << "Addition test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Addition test: " << FAIL << endl;
			out << endl;
		}
		string p34_ans = " -96.23*X^9 +12*X^6 -3*X^2";
		out << "Polynomial 1: " << p3 << endl;
		out << "Polynomial 2: " << p4 << endl;
		out << "Correct Answer: " << p34_ans << endl;
		p3.add(p4);
		if (p3.toString().compare(p34_ans) == 0) {
			out << "Returned Answer: " << p3 << endl;
			out << "Addition test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Addition test: " << FAIL << endl;
			out << endl;
		}




	}

	void testAdditionOpperator(ostream&out) {
		out << "The following test are to determine how well the addition operator works." << endl;
		out << endl;
		Poly p1, p2, p3, p4;


		p1.setCoeff(1.0, 4);
		p1.setCoeff(18.0, 44);
		p1.setCoeff(0.253, 2);


		p2.setCoeff(5.0, 1);
		p2.setCoeff(4.0, 2);
		p2.setCoeff(12.0, 6);

		p3.setCoeff(96.23, 9);
		p3.setCoeff(1.0, 2);
		p3.setCoeff(1.0, 4);


		p4.setCoeff(-5.0, 1);
		p4.setCoeff(-4.0, 2);




		string p14 = " +18*X^44 +1*X^4 -3.747*X^2 -5*X^1";
		out << "Correct Polynomial: " << p14 << endl;
		if ((p1 + p4).toString().compare(p14) == 0) {
			out << "Returned Polynomial: " << p1 + p4 << endl;
			out << "Addition Operator test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Addition Operator test: " << FAIL << endl;
			out << endl;
		}

		string p23 = " +96.23*X^9 +12*X^6 +1*X^4 +5*X^2 +5*X^1";
		out << "Correct Polynomial: " << p23 << endl;
		if ((p2 + p3).toString().compare(p23) == 0) {
			out << "Returned Polynomial: " << p2 + p3 << endl;
			out << "Addition Operator test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Addition Operator test: " << FAIL << endl;
			out << endl;
		}


	}

	void testEquals(ostream&out){
		out << "The following test are to see if poly objectd are the same." << endl;
		out << endl;

		Poly p1, p2, p3, p4, p5, p6, p7, p8;

		p1.setCoeff(1.0, 4);
		p2.setCoeff(18.0, 44);
		p3.setCoeff(0.253, 2);
		p4.setCoeff(5.0, 1);
		p4.setCoeff(4.0, 2);
		p3.setCoeff(12.0, 6);
		p2.setCoeff(96.23, 9);
		p1.setCoeff(1.0, 2);
		p2.setCoeff(1.0, 4);
		p3.setCoeff(-5.0, 1);
		p4.setCoeff(-4.0, 2);

		p5 = p1;
		p6 = p2;
		p7 = p3;
		p8 = p4;


		out << "Polynomial 1: " << p1 << endl;
		out << "Polynomial 2: " << p7 << endl;
		if (p1.equals(p7)) {
			out << "Boolean result: " << p1.equals(p7) << endl;
			out << "Equals test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Equals test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial 1: " << p3 << endl;
		out << "Polynomial 2: " << p4 << endl;
		if (p3 != p4) {
			out << "Boolean result: " << (p3 != p4) << endl;
			out << "Inequality test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Inequality test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial 1: " << p2 << endl;
		out << "Polynomial 2: " << p5 << endl;
		if (p2 == p5) {
			out << "Boolean result: " << (p2 == p5) << endl;
			out << "Equality Operator test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Equality Operator test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial 1: " << p2 << endl;
		out << "Polynomial 2: " << p6 << endl;
		if (p2 == p6) {
			out << "Boolean result: " << (p2 == p6) << endl;
			out << "Equality Operator test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Equality Operator test: " << FAIL << endl;
			out << endl;
		}







	}

	void testDerivative(ostream&out) {
		out << "The following test are to check derivaties of polynomials." << endl;
		out << endl;

		Poly p1, p2, p3, p4;

		p1.setCoeff(1.0, 2);
		p2.setCoeff(-8.0, 4);
		p2.setCoeff(5.0, 3);
		p3.setCoeff(-17.0, 0);
		p4.setCoeff(-1.0, 49);

		out << "Polynomial: " << p3 << endl;
		p3.derivative();
		if (p3.toString() == " +0") {
			out << "Derivative result: " << p3 << endl;
			out << "Derivative test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Derivative test: " << FAIL << endl;
			out << endl;
		}

		out << "Polynomial: " << p2 << endl;
		p2.derivative();
		if (p2.toString() == " -32*X^3 +15*X^2") {
			out << "Derivative result: " << p2 << endl;
			out << "Derivative test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Derivative test: " << FAIL << endl;
			out << endl;
		}


		out << "Polynomial: " << p1 << endl;
		p1.derivative();
		if (p1.toString() == " +2*X^1") {
			out << "Derivative result: " << p1 << endl;
			out << "Derivative test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Derivative test: " << FAIL << endl;
			out << endl;
		}

		out << "Polynomial: " << p4 << endl;
		p4.derivative();
		if (p4.toString() == " -49*X^48") {
			out << "Derivative result: " << p4 << endl;
			out << "Derivative test: " << PASS << endl;
			out << endl;
		}
		else {
			out << "Derivative test: " << FAIL << endl;
			out << endl;
		}
	}








