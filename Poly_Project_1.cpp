// File name: Poly.cpp
// Author: Steven Ayanruoh	
// VUnetid: ayanrus
// Email: steven.ayanruoh@vanderbilt.edu
// Class: CS201
// Honor statement: I have neither given nor received unauthorized help on this assignment.
// Date: 9-4-2014
// Assignment Number: 1
// Description:  Specifications for Polynomial ADT
//    data object: a polynomial (with nonnegative powers)
//    operations : create, find degree, set coefficient, retrieve coefficient
//                 increment coeff, toString, number of terms, evaluate, add, equals,
//                 and derivative
//                 
//
// Last Changed: 9/9/2014



#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>   // includes a pow() function for computing powers [see page C5 of text]
#include "Poly_Project_1.h"
using namespace std;



// Class constructor
// Initializes a polynomial to the constant 0
// post: Class object is initialized to degree-0 polynomial of 0
Poly::Poly()
{
	for (int i = 0; i < MAXPOLY; i++)
	{
		coeff[i] = 0;
	}
}
  

//////////////////////////////////////////////////
//
// Member functions   [specs for ADT's operations]
//
//////////////////////////////////////////////////

// degree
// Finds the degree of a polynomial (the highest power with a
//    non-zero coefficient)
// pre: Class object exists
// post: Returns the degree of the polynomial object.
size_t Poly::degree() const
{
	// Check that object exists 
	
	size_t degree = 0; 
	
	for (int i = 0; i < MAXPOLY; i++)
	{
		if (coeff[i] != 0)
		{
			degree = i; 
		}
	}

  return degree;   // REPLACE WITH YOUR CODE
}

// setCoeff
// Sets a term, value*x^i, in a polynomial
// pre: Class object has been initialized. 0 <= i < MAXPOLY.
// post: In the polynomial, the term with power i has coefficient
//       value. 
// Throws <std::out_of_range> if index i does not meet the precondition.
void Poly::setCoeff (double value, size_t i)
{
	if (i >= MAXPOLY || i < 0)
	{
		throw std::out_of_range("The values you have entered are out of range.");
	}
	else
	{
		coeff[i] = value;
	}
}

// retrieveCoeff
// Finds the coefficient of the x^i term in poly
// pre: Class object has been initialized. 0 <= i
// post: Returns the value of the coefficient of the term with power i
// note: If the object does not contain a term with power i (e.g., 
//       i>=MAXPOLY), a coefficient value of zero is returned.
// Throws <std::out_of_range> if index i does not meet the precondition.
double Poly::retrieveCoeff (size_t i) const
{
	double coefficent;
	if (i < 0)
	{
		throw std::out_of_range("The value you have entered is out of range.");
	}
	else if (i >= MAXPOLY)
	{
		coefficent = 0;
	} else 
	{
		coefficent = coeff[i];
	}
	 
	return coefficent;    // REPLACE WITH YOUR CODE
}

// incrementCoeff
// Changes a term, value*x^i, in a polynomial
// pre: Class object has been initialized. 0 <= i < MAXPOLY.
// post: In the Class object the term with power i has its coefficient
//       incremented by the given value. 
// Throws <std::out_of_range> if index i does not meet the precondition.
void Poly::incrementCoeff(double value, size_t i)
{
	if (i >= MAXPOLY || i < 0)
	{
		throw std::out_of_range("The values you have entered are not valid values.");
	}
	else
	{
		coeff[i] = coeff[i] + value;
	}
	
}


// toString  
// Produce a string representation of a Poly object
// pre: The class object has been initialized.
// post: A string representation is returned.
// dependencies: This function requires that the degree() and 
//  retrieveCoeff() functions are implemented.
// NOTE: This function has been provided for you -- DO NOT CHANGE IT!
string Poly::toString() const
{
    ostringstream result;
    bool printedSomething = false;
    for (int i=(int)degree(); i>=0; i--) 
	{
      double c = retrieveCoeff(i);
      if (c != 0.0) 
	  {
	    printedSomething = true;
	    if (i == 0) 
		{
	      result.setf(ios::showpos);
	      result << " " << c;
	      result.unsetf(ios::showpos);
		}
	    else 
		{
	      result.setf(ios::showpos);
	      result << " " << c;
	      result.unsetf(ios::showpos);
	      result << "*X^" << i;
	    }
      }
    }
    if (!printedSomething) 
	{
      result.setf(ios::showpos);
      result << " " << 0;
      result.unsetf(ios::showpos);
    }
    return result.str();

}


// numOfTerms
// Returns the number of terms in the polynomial.
// pre: The class object has been initialized.
// post: The number of non-zero terms of the polynomial is returned.
size_t Poly::numOfTerms () const
{
	size_t numOfTerms = 0;
	for (size_t i = 0; i < MAXPOLY; i++)
	{
		if (coeff[i] != 0)
		{
			numOfTerms++;
		}
	}
	return numOfTerms;   
}

// evaluate
// Evaluate a polynomial for a specified value of X
// pre: The class object has been initialized
// post: The polynomial will be evaluated for the value of
//       X received as an argument. The resulting value is
//       returned.
double Poly::evaluate (double x) const
{
	double sum = coeff[0]; 
	for (int i = 1; i < MAXPOLY; i++)
	{
		double exp_value = pow(x, i);
		double value  = coeff[i] * exp_value; 
		sum = value + sum ; 
	}
	return sum;   // REPLACE WITH YOUR CODE
}


// add
// Add one polynomial to another
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is added to the object polynomial.
//       The object polynomial is changed to hold the sum.
void Poly::add (const Poly& aPoly)
{
	
	for (size_t i = 0; i < MAXPOLY; i++)
	{
			double result = coeff[i] + aPoly.retrieveCoeff(i);
			coeff[i] = result; 
	}
}


// addition operator
// Add two polynomials together and return a new polynomial that is the result
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is added to the object polynomial, and the
//       result is stored in a new polynomial which is returned.
//       The object polynomial is not changed.
// Provided for you -- DO NOT CHANGE
Poly Poly::operator+ (const Poly& rhs) const
{
	Poly result;
	result.add(*this);
	result.add(rhs);
	return result;
}


// equals
// Determine if two polynomials are equal
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: Returns true if the two polynomials are equal, false otherwise.
bool Poly::equals (const Poly& aPoly) const
{
	bool result;
	for (int i = 0; i < MAXPOLY; i++)
	{
		if (coeff[i] == aPoly.retrieveCoeff(i))
		{
			result = true; 
		}
		else 
		{
			result = false;
			return result;
		}
	}
   return result;   
}

// Equality/inequality operators
// Provided for you -- DO NOT CHANGE
bool Poly::operator== (const Poly& rhs) const
{
   return equals(rhs);
}

bool Poly::operator!= (const Poly& rhs) const
{
   return !equals(rhs);
}


// derivative
// Compute the derivative of a polynomial
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       derivative.
void Poly::derivative ()
{
	for (int i = 0; i < MAXPOLY; i++)
	{
		 if (i > 0 )
		{
			coeff[i - 1] = coeff[i] * (i);
		}
	}
	
		setCoeff(0, MAXPOLY-1);
}


// Friend operator for printing a Poly object.
// Provided for you.
ostream & operator << (ostream &out, const Poly& p)
{
    out << p.toString();
    return out;
}


   ///////////////////////////////////////////////////
   // THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1


// negate
// Negate a polynomial
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       multiplication by -1.0.
void Poly::negate ()
{
	// ADD YOUR CODE HERE
}

// multByConst
// Multiply a polynomial by a constant
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       multiplication by the value of argument val.
void Poly::multByConst (double val)
{
	// ADD YOUR CODE HERE
}


#endif

   // END GRAD STUDENT ONLY METHODS
   ///////////////////////////////////////////////////
