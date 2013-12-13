/*
 *          Complex Number Class 
 *          Author: The Alex Camejo
 *          Last Modified: 12/2/2013 8:30AM
 *
 *
 */

#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <cmath> //needed for sin() and cos()
#include <string>
#include <iostream>



class Complex{
		
		//member variables
		int realNum;
		int imgNum;
	    
public:
		
	//constructors
	Complex():realNum(0) , imgNum(0){} //default
	Complex(int r):realNum(r),imgNum(0){} 
	Complex(double r):realNum(r) , imgNum(0){}
	Complex(int r , int i):realNum(r) , imgNum(i){}
	Complex(const Complex&){}; //copy constructor
	Complex(const Complex&&){};//move constructor
	
	// member methods
	Complex complexFromPolar(double rho , double theta); 
	Complex operator+ (Complex &n); 
	friend Complex operator- (Complex &left , Complex &right);
	Complex operator* (Complex &n); 
	friend Complex operator/ (Complex &top , Complex &bot);
	Complex operator+= (Complex &n); 
	Complex operator-= (Complex &n);
	Complex operator*= (Complex &n); 
	Complex operator/= (Complex &n); 
	bool operator==(Complex &n);
	bool operator!=(Complex &n); 
	friend bool operator<(Complex &left, Complex &right); 
	friend bool operator<=(Complex &left, Complex &right); 
	friend bool operator>(Complex &left , Complex &right);
	friend bool operator>=(Complex &left , Complex &right);

	int real();
	int img(); 
	double rho();
	double theta();

	

	std::string string(); 
	std::string stringCart(); 
	std::string stringPolar(); 

	std::ostream & operator<<(std::ostream & stream); 
	friend std::istream & operator>> (std::istream & stream ,  Complex &n);
};


#endif //_COMPLEX_H
