/************************************************************************
 *
 *  Author:           Fatima Marquez
 *  Email:            fnmarquez0414@my.msutexas.edu
 *  Label:            P01
 *  Title:            Fraction Class
 *  Course:           CMPS 2143
 *  Semester:         Fall 2024
 *
 *  Description:
 *        This program implements a class called Fraction that includes
 *        overloaded operators ( + - * / ) to do between fractions. It
 *        uses GCD, LCD, and LCM to simplify the fractions and also shows
 *        how private and public methods are implemented. It also includes
 *        a parse function that I learned outside of class to help convert
 *        my string into fractions.
 *  Code Help:
 *  https://stackoverflow.com/questions/40009563/
 *  how-to-split-a-fraction-into-two-integers-c
 *
 *  Files:
 *       main.cpp    : driver program
 *       data.txt    : input file
 *************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // Used to parse fractions
using namespace std;

class Fraction {
private:
  int numerator;
  int denominator;

public:
  // Constructor
  Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
      cout << "Error: Denominator cannot be zero." << endl;
    }
  }

  // Overloaded addition operator
  Fraction operator+(const Fraction &other) {
    // code in class
    // return Fraction(this->numerator + other.numerator,
    // this->denominator + other.denominator);
    // TODO: Use LCM and LCD to add fractions correctly
    // 1. Find the least common denominator (LCD)
    int commonDen = lcd(this->denominator, other.denominator);
    // 2. Adjust both fractions to have this denominator
    int adjustedNum1 = this->numerator * (commonDen / this->denominator);
    int adjustedNum2 = other.numerator * (commonDen / other.denominator);
    // 3. Add the numerators
    int sumNum = adjustedNum1 + adjustedNum2;
    // 4. Return the result as a new fraction
    return Fraction(sumNum, commonDen);
  }

  // Overloaded subtraction operator
  Fraction operator-(const Fraction &other) {
    // code in class
    // return Fraction(this->numerator - other.numerator,
    // this->denominator - other.denominator);
    // TODO: Use LCM and LCD to add fractions correctly
    // 1. Find the least common denominator (LCD)
    int commonDen = lcd(this->denominator, other.denominator);
    // 2. Adjust both fractions to have this denominator
    int adjustedNum1 = this->numerator * (commonDen / this->denominator);
    int adjustedNum2 = other.numerator * (commonDen / other.denominator);
    // 3. Add the numerators
    int diffNum = adjustedNum1 - adjustedNum2;
    // 4. Return the result as a new fraction
    return Fraction(diffNum, commonDen);
  }

  // Overloaded multiplication operator
  Fraction operator*(const Fraction &other) {
    // TODO: Implement the multiplication logic
    return Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
  }

  // Overloaded division operator
  Fraction operator/(const Fraction &other) {
    // TODO: Implement the division logic
    //same as multiple but switch num and den
    return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);
  }

  // Overloaded equality operator (==)
  bool operator==(const Fraction &other) const {
    // Check if two fractions are equal by comparing num and den
    return numerator == other.numerator && denominator == other.denominator;
  }

  // Overload output operator (<<) for printing fractions
  friend ostream &operator<<(ostream &os, const Fraction &frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
  }

  // Function to calculate Greatest Common Divisor (GCD)
  // Created to help implement the LCM
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

  // Function to calculate Least Common Multiple (LCM)
  // Uses the greatest common divisor (GCD) to calculate the LCM
  int lcm(int a, int b) { return (a * b) / gcd(a, b); }

  // Function to calculate Least Common Denominator (LCD)
  // similar to lcm for determing the least common denominator
  int lcd(int a, int b) { return lcm(a, b); }
};

Fraction parseFraction(const string &line) {
  // You'll need to read from this file and parse each line to:
  // Extract the fractions.
  // Code help for parsing fractions
  istringstream iss(line);
  string numeratorStr, denominatorStr;
  //read the fractions until /
  getline(iss, numeratorStr, '/');
  //reads after the /
  getline(iss, denominatorStr);
  //converts strings to ints
  return Fraction(stoi(numeratorStr), stoi(denominatorStr));
}

int main() {
  // Perform the correct operation using their overloaded operators.
  
  // Create an ifstream object to read from the file
  ifstream inputFile("data.txt");
  // Read from file
  string line;
  while (getline(inputFile, line)) {
    //declaration
    istringstream iss(line);
    //extraction
    string num1Str, op, num2Str;
    iss >> num1Str >> op >> num2Str;

    //converts to fractions
    Fraction fraction1 = parseFraction(num1Str);
    Fraction fraction2 = parseFraction(num2Str);

    // Identify the operator (+, -, *, /).
      Fraction result(0,1); // default values
      if (op == "+") {
        // Addition
        result = fraction1 + fraction2;
      } else if (op == "-") {
        // Subtraction
        result = fraction1 - fraction2;
      } else if (op == "*") {
        // Multiplication
        result = fraction1 * fraction2;
      } else if (op == "/") {
        // Division
        result = fraction1 / fraction2;
      }    
      cout << result << endl;
    
  }
}
