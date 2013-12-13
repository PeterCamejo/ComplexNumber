#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "Complex.h"

//More-difficult math was computed using Wolfram Alpha

Complex c1(2,3);
Complex c2(3,3);
Complex c4(-1 , 5);
Complex c5(5); //img == 0;

TEST_CASE("real() and img() are tested" , "[real()] , [img()]"){
  REQUIRE(c1.real() == 2);
  REQUIRE(c1.img() == 3);
  REQUIRE(c4.real() == -1);
  REQUIRE(c4.img() == 5);
  REQUIRE(c5.real() == 5);
  REQUIRE(c5.img() == 0);
}


TEST_CASE("Addition is tested" , "[operator+]"){
  Complex c = c1 + c2;
  REQUIRE(c.real() == 5);
  REQUIRE(c.img() == 6);
  c = c2 + c1;
  REQUIRE(c.real() == 5);
  REQUIRE(c.img() == 6);
}

TEST_CASE("Add Assign is tested", "[operator+=]"){
  Complex c3(2,3);
  c3 += c2;
  REQUIRE(c3.real() == 5);
  REQUIRE(c3.img() == 6);
  c3 += c4;
  REQUIRE(c3.real() == 4);
  REQUIRE(c3.img() == 11);
}

TEST_CASE("Subtract is tested" , "[operator-]"){
  Complex c = c2 - c1;
  REQUIRE(c.real() == 1);
  REQUIRE(c.img() == 0);
  c = c1 - c2;
  REQUIRE(c.real() == -1);
  REQUIRE(c.img() == 0);
}

TEST_CASE("Subtract Assign is tested" , "[operator-=]"){
  Complex c(2,3);
  c -= c2;
  REQUIRE(c.real() == -1);
  REQUIRE(c.img() == 0);
  c -= c4;
  REQUIRE(c.real() == 0);
  REQUIRE(c.img() == -5);
}

TEST_CASE("Muliplication is tested" , "[operator*]"){
  Complex c  = c1 * c4;
  REQUIRE( c.real() == -17);
  REQUIRE(c.img() == 7);
}


TEST_CASE("Muliplication Assign is tested" , "[operator*=]"){
  Complex c(2,3);
  c*= c2;
  REQUIRE( c.real() == -3);
  REQUIRE( c.img() == 15 );
  c*=c5;
  REQUIRE(c.real() == -15);
  REQUIRE(c.img() == 75);
}

TEST_CASE("Division is tested" , "[operator/]"){
  Complex c = c1 / c4;
  REQUIRE(c.real() == 0); // 1/2
  REQUIRE(c.img() == 0); // -1/2
}

TEST_CASE("Divison assign is tested" , "[operator/=]"){
  Complex c(2,3);
  c/=c4;
  REQUIRE(c.real() == 0); // 1/2
  REQUIRE(c.img() == 1); // -1/2
  c/=c2;
  REQUIRE(c.real() == 0); // 0
  REQUIRE(c.img() == 0 ) ; //-0.1666667..
}

TEST_CASE("String is tested" , "[string()]"){
  Complex c(2,3);
  Complex cc(2,-3);
  REQUIRE(c.string() == "2 + 3i");
  REQUIRE(cc.string() == "2 - 3i");
}

TEST_CASE("Cartesian String is tested" , "[stringCart()]"){
  Complex c(2,3);
  Complex cc(2,-3);
  REQUIRE(c.stringCart() == "(2, 3)");
  REQUIRE(cc.stringCart() == "(2, -3)");
}

TEST_CASE("Equality is tested" , "[operator==]"){
  Complex c(2,3);
  Complex cc(2,3);
  Complex ccc(3,2);
  bool test1 =( c == cc);
  bool test2 =( c == ccc);
  REQUIRE(test1 == true);
  REQUIRE(test2 == false);
}

TEST_CASE("Inequality is tested" , "[operator!=]"){
  Complex c(2,3);
  Complex cc(2,3);
  Complex ccc(3,2);
  bool test1= (c != ccc);
  bool test2= (c != cc);
  REQUIRE(test1 == true);
  REQUIRE(test2 == false);
}

//Inequality testing will use the same Complex instances whose Rho and Theta
//values are calculated in the testing for operator< below

TEST_CASE("LessThan is tested" , "[operator < ]"){
  Complex c(2,3); // Rho: 3.60 Theta .983 rad
  Complex cc(34,3); // Rho: 34.13 Theta 1.482
  Complex ccc(3,2); //Rho: 3.60 Theta .588 rad
  bool test1 = (c < cc);
  bool test2 = (ccc < c);
  REQUIRE(test1 == true);
  REQUIRE(test2 == true);
}

TEST_CASE("LessThanEqual is tested", "[operator<=]"){
  Complex c(2,3); // Rho: 3.60 Theta .983 rad
  Complex cc(34,3); // Rho: 34.13 Theta 1.482
  Complex ccc(3,2); //Rho: 3.60 Theta .588 rad
  Complex cccc(2,3);
  bool test1 = (c <= cc);
  bool test2 = (ccc <= c);
  bool test3 = (c <= cccc);
  REQUIRE(test1 == true);
  REQUIRE(test2 == true);
  REQUIRE(test3 == true);
}

TEST_CASE("GreaterThan is tested" , "[operator>]"){
  Complex c(2,3); // Rho: 3.60 Theta .983 rad
  Complex cc(34,3); // Rho: 34.13 Theta 1.482
  Complex ccc(3,2); //Rho: 3.60 Theta .588 rad
  bool test1 = (c > cc);
  bool test2 = (ccc > c);
  REQUIRE(test1 == false);
  REQUIRE(test2 == false);
}

TEST_CASE("GreaterThanEquals is tested" , "[operator>=]"){
  Complex c(2,3); // Rho: 3.60 Theta .983 rad
  Complex cc(34,3); // Rho: 34.13 Theta 1.482
  Complex ccc(3,2); //Rho: 3.60 Theta .588 rad
  Complex cccc(2,3);
  bool test1 = (c >= cc);
  bool test2 = (ccc >= c);
  bool test3 = (c >= cccc);
  REQUIRE(test1 == false);
  REQUIRE(test2 == true);
  REQUIRE(test3 == true);
}


TEST_CASE("complexFromPolar is tested" , "[complexFromPolar]"){
  Complex c;
  c = c.complexFromPolar(3.6055 , .9828);
  REQUIRE(c.real() == 2);
  REQUIRE(c.img() == 3);
}

TEST_CASE("stringPolar is tested" , "[stringPolar]"){
  Complex c(2,3);
  REQUIRE(c.stringPolar() == "(3.605551, 0.982794)");
}

TEST_CASE("Rho and Theta are tested" , "[rho]&& [theta]"){
  Complex c(2,3);
  REQUIRE(std::to_string(c.rho()) == "3.605551"); //to_string used so the value of 
                                                   //rho and theta can be compared;
  REQUIRE(std::to_string(c.theta()) == "0.982794");
}
