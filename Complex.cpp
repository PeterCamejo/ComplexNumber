/*
 *          Complex Number Class 
 *          Author: The Alex Camejo
 *          Last Modified: 12/2/2013 8:30AM
 *
 *
 */



#include "Complex.h"


Complex Complex::complexFromPolar(double rho , double theta){
  int real = round( rho*cos(theta));
  int img = round(rho*sin(theta));
  return Complex(real , img);
}

// ==================Operators=========================

Complex Complex::operator+(Complex &n){
		int returned_real = n.realNum + realNum;
		int returned_img = n.imgNum + imgNum;
		return Complex(returned_real , returned_img);
}

Complex Complex::operator+=(Complex &n){
  realNum = realNum + n.realNum;
  imgNum = imgNum + n.imgNum;
  return Complex(realNum , imgNum);
}

Complex Complex::operator-=(Complex &n){
  realNum = realNum - n.realNum;
  imgNum = imgNum - n.imgNum;
  return Complex(realNum, imgNum);
  
}

Complex Complex::operator*(Complex &n){
	int returned_real = realNum*n.realNum - n.imgNum*imgNum;
	int returned_img = realNum*n.imgNum + imgNum * n.realNum;
	return Complex(returned_real , returned_img);
}

Complex Complex::operator*=(Complex &n){
  int temp = realNum;
  realNum = realNum * n.realNum - imgNum*n.imgNum;
  imgNum = temp*n.imgNum + imgNum * n.realNum;
  return Complex(realNum , imgNum);
}

bool Complex::operator==(Complex &n){
	if(realNum == n.realNum && imgNum == n.imgNum){
		return true;
	}
	else{
		return false;
	}
}
		
bool Complex::operator!=(Complex &n){
	if(realNum != n.realNum && imgNum != n.imgNum){
		return true;
	}
	else{
		return false;
	}
}

//FRIEND FUNCTION
bool operator<(Complex &left, Complex &right){
  if((left.rho() < right.rho()) || ((left.rho() == right.rho()) && (left.theta() < right.theta()))){
    return true;
  }
  else{
    return false;
  }
}

//FRIEND FUNCTION
bool operator<=(Complex &left, Complex &right){
  if((left.rho() <= right.rho()) || ((left.rho() == right.rho()) && (left.theta() <= right.theta()))){
    return true;
  }
  else{
    return false;
  }
}

//FRIEND FUNCTION
bool operator>(Complex &left, Complex &right){
  if((left.rho() > right.rho()) || ((left.rho() == right.rho()) && (left.theta() > right.theta()))){
    return true;
  }
  else{
    return false;
  }
}

//FRIEND FUNCTION
bool operator>=(Complex &left, Complex &right){
  if((left.rho() >= right.rho()) || ((left.rho() == right.rho()) && (left.theta() >= right.theta()))){
    return true;
  }
  else{
    return false;
  }
}


//FRIEND FUNCTION
Complex operator- (Complex &left , Complex &right){
  int finalReal = left.realNum - right.realNum;
  int finalImg = left.imgNum - right.imgNum;
  return Complex(finalReal , finalImg);
}

//FRIEND FUNCTION
Complex operator/ (Complex &top , Complex &bot){
  //Numerator Operations
  int real = (top.realNum * bot.realNum) + -(top.imgNum * bot.imgNum);
  int img = (top.realNum * bot.imgNum) + (bot.realNum * top.imgNum);

  //Denominator Operations
  int den = (bot.realNum * bot.realNum) + (bot.imgNum * bot.imgNum);

  return Complex(real/den , img/den);
}

Complex Complex::operator/= (Complex &n){
  //Denominator Operations
  int den = (n.realNum * n.realNum) + (n.imgNum*n.imgNum);
  //Numerator Operations
  realNum = ((realNum * n.realNum) + -(imgNum * n.imgNum))/den;
  imgNum = ((imgNum * n.imgNum) + (imgNum * n.imgNum))/den;

  return Complex(realNum , imgNum);
}
  
//FRIEND FUNCTION
std::ostream & Complex::operator<<(std::ostream & stream){
  stream << string();
  return stream;
}


//FRIEND FUNCTION
std::istream & operator>>(std::istream & stream, Complex & n ){
  stream >> n.realNum;
  stream >> n.imgNum;
  return stream;
}


  
//=================Gets and toStrings===========================

int Complex::real(){
	return realNum;
}

int Complex::img(){
	return imgNum;
}

double Complex::theta(){
  return atan2(imgNum, realNum);
}

double Complex::rho(){
	return sqrt(pow(imgNum, 2) + pow(realNum , 2));
}

std::string Complex::string(){
	if(imgNum < 0){
	  return std::to_string(realNum) + " - " + std::to_string(-imgNum) + "i";
	}
	else{
	  return std::to_string(realNum)+" + "+std::to_string(imgNum)+"i";
	}
}

std::string Complex::stringCart(){
        return "(" + std::to_string(realNum) +", "+std::to_string(imgNum)+")";
}

std::string Complex::stringPolar(){
  double rh = rho();
  double thet = theta();
  return "(" + std::to_string(rh) + ", " + std::to_string(thet)+ ")";
}



