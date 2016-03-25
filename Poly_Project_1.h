// File name: Poly.h
// Author: Steven Ayanruoh	
// VUnetid: ayanrus
// Email: steven.ayanruoh@vanderbilt.edu
// Class: CS201
// Honor statement: I have neither given nor received unauthorized help on this assignment.
// Date: 9-4-2014
// Assignment Number: 1
// Description: This will be a representation of a polynomial implemented 
//               with a static array of chars.



// Change the following line as appropriate -- this is the only line you should change 
// in this file besides filling in the comment header above.
#define GRAD_STUDENT 0   // if you are a grad student, set this to 1, otherwise set it to 0


#ifndef POLY_H
#define POLY_H

#include <string>
using namespace std;


// size of our static coefficient array
const size_t MAXPOLY = 50;    

class Poly
{

private:
	// Data members   [implementation of ADT's data object]

	// array for holding the coefficients of the poly
	double coeff[MAXPOLY];               


public:

	// Default Class constructor
	// Initializes a polynomial to the constant 0
	// post: all array elements of coeff[] are set to 0.0  
	Poly ();

	// degree
	// Finds the degree of a polynomial (the highest power with a
	//    non-zero coefficient)
	// pre: Class object exists
	// post: Returns the degree of the polynomial object.
	size_t degree () const;

	// setCoeff
	// Sets a term, value*x^i, in a polynomial
	// pre: Class object has been initialized. 0 <= i < MAXPOLY.
	// post: In the polynomial, the term with power i has coefficient
	//       value. 
	// Throws <std::out_of_range> if index i does not meet the precondition.
	void setCoeff (double value, size_t i);

	// retrieveCoeff
	// Finds the coefficient of the x^i term in poly
	// pre: Class object has been initialized. 0 <= i
	// post: Returns the value of the coefficient of the term with power i
	// note: If the object does not contain a term with power i (e.g., 
	//       i>=MAXPOLY), a coefficient value of zero is returned.
	// Throws <std::out_of_range> if index i does not meet the precondition.
	double retrieveCoeff (size_t i) const;

	// incrementCoeff
	// Changes a term, value*x^i, in a polynomial
	// pre: Class object has been initialized. 0 <= i < MAXPOLY.
	// post: In the Class object the term with power i has its coefficient
	//       incremented by the given value. 
	// Throws <std::out_of_range> if index i does not meet the precondition.
	void incrementCoeff(double value, size_t i);


	// toString  
	// Produce a string representation of a Poly object
	// pre: The class object has been initialized.
	// post: A string representation is returned.
	// dependencies: This function requires that the degree() and 
	//  retrieveCoeff() functions are implemented.
	// note: This function has been provided for you -- DO NOT CHANGE IT!
	string toString() const;

	// numOfTerms
	// Returns the number of terms in the polynomial.
	// pre: The class object has been initialized.
	// post: The number of non-zero terms of the polynomial is returned.
	size_t numOfTerms () const;

	// evaluate
	// Evaluate a polynomial for a specified value of X
	// pre: The class object has been initialized
	// post: The polynomial will be evaluated for the value of
	//       X received as an argument. The resulting value is
	//       returned.
	double evaluate (double x) const;

	// add
	// Add one polynomial to another
	// pre: The class object has been initialized. The received
	//       argument is also an initialized poly object.
	// post: The argument polynomial is added to the object polynomial.
	//       The object polynomial is changed to hold the sum.
	void add (const Poly& aPoly);

	// addition operator
	// Add two polynomials together and return a new polynomial that is the result
	// pre: The class object has been initialized. The received
	//       argument is also an initialized poly object.
	// post: The argument polynomial is added to the object polynomial, and the
	//       result is stored in a new polynomial which is returned.
	//       The object polynomial is not changed.
	// note: This function has been provided for you -- DO NOT CHANGE IT!
	Poly operator+ (const Poly& rhs) const;

	// equals
	// Determine if two polynomials are equal
	// pre: The class object has been initialized. The received
	//       argument is also an initialized poly object.
	// post: Returns true if the two polynomials are equal, false otherwise.
	bool equals (const Poly& aPoly) const;

	// Equality/inequality operators
	// note: These functions have been provided for you -- DO NOT CHANGE IT!
	bool operator== (const Poly& rhs) const;
	bool operator!= (const Poly& rhs) const;


	// derivative
	// Compute the derivative of a polynomial
	// pre: The class object has been initialized.
	// post: The polynomial has been changed to represent its
	//       derivative.
	void derivative ();


	// insertion operator for output
	// note: This function has been provided for you -- DO NOT CHANGE IT!
	friend ostream& operator<< (ostream& os, const Poly &p);



	///////////////////////////////////////////////////
	// THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1

	// negate
	// Negate a polynomial
	// pre: The class object has been initialized.
	// post: The polynomial has been changed to represent its
	//       multiplication by -1.0.
	void negate ();

	// multByConst
	// Multiply a polynomial by a constant
	// pre: The class object has been initialized.
	// post: The polynomial has been changed to represent its
	//       multiplication by the value of argument val.
	void multByConst (double val);


#endif

	// END GRAD STUDENT ONLY METHODS
	///////////////////////////////////////////////////


};	

#endif

