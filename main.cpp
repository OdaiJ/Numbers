// بسم الله الرحمن الرحيم

// Todos - بإذن الله تعالى
// 1- Add polar form.
// 2- Overload *= operator and its family

#include <iostream>
using namespace std;

class Number
{
	float real;
	float imag;
public:
	// Constructor
	Number(float real = 0.0f, float imag = 0.0f);
	// Magnitude squared
	float magSq();

	// Getters
	float getReal();
	float getImag();

	// + operator overload
	friend Number operator+ (Number const&, Number const&);      // Addition
	friend Number operator+ (Number const&);                     // To support `num2 = +num1;`
	// - operator overload								        
	friend Number operator- (Number const&, Number const&);      // Subtraction
	friend Number operator- (Number const&);                     // Negation
	// * operator overload								        
	friend Number operator* (Number const&, Number const&);      // Multiplication
	friend Number operator* (Number const&);                     // Conjugate
	// / operator overload								        
	friend Number operator/ (Number const&, Number const&);      // Division
	// ^ operator overload								        
	friend Number operator^ (Number const&, int const&);         // Exponentiation
	// == operator overload
	friend bool operator== (Number const&, Number const&);       // Equality
	// << operator overload
	friend ostream& operator<< (ostream& output, Number const&); // Printing
};

// Constructor
Number::Number(float real, float imag)
{
	this->real = real;
	this->imag = imag;
}

// returns the magnitude squared of the complex number
float Number::magSq()
{
	return this->real * this->real + this->imag * this->imag;
}

// returns the real part of the complex number
float Number::getReal()
{
	return this->real;
}
// returns the imaginary part of the complex numer
float Number::getImag()
{
	return this->imag;
}

// returns num1 added to num2
Number operator+ (Number const& num1, Number const& num2)
{
	Number result;
	result.real = num1.real + num2.real;
	result.imag = num1.imag + num2.imag;
	return result;
}

// returns num itself
Number operator+ (Number const& num)
{
	return num;
}

// returns num1 take away num2
Number operator- (Number const& num1, Number const& num2)
{
	Number result;
	result.real = num1.real - num2.real;
	result.imag = num1.imag - num2.imag;
	return result;
}

// returns negated num
Number operator- (Number const& num)
{
	return Number(-num.real, -num.imag);
}

// returns the product of num1 with num2
Number operator* (Number const& num1, Number const& num2)
{
	Number result;
	result.real = num1.real * num2.real - num1.imag * num2.imag;
	result.imag = num1.real * num2.imag + num2.real * num1.imag;
	return result;
}

// returns the conjugate of num
Number operator* (Number const& num)
{
	return Number(num.real, -num.imag);
}

// returns num1 divided by num2
Number operator/ (Number const& num1, Number const& num2)
{
	float real = (num1.real * num2.real + num1.imag * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag);
	float imag = (-num1.real * num2.imag + num2.real * num1.imag) / (num2.real * num2.real + num2.imag * num2.imag);
	return Number(real, imag);
}	

// returns num raised to exponent (int only for now)
Number operator^ (Number const& num, int const& exponent)
{
	Number result = num;
	for (int i = 1; i < exponent; i++)
		result = result * num;
	return result;
}


// returns the equality value between num1 and num2
bool operator== (Number const& num1, Number const& num2)
{
	return ((num1.real == num2.real) && (num1.imag == num2.imag));
}

// prints the Cartesian form of num to the screen
ostream& operator<< (ostream& output, Number const& num)
{
	if (num.imag >= 0)
		output << "(" << num.real << " + " << num.imag << "i)";
	else
		output << "(" << num.real << " - " << -num.imag << "i)";
	return output;
}

int main()
{
	// Example
	Number x(1, 1);
	Number y(1, -1);
	Number a(1, 2);
	Number b(2, 2);
	Number c(3, -1);
	Number d(1, 1);

	Number expr1 = x / y - a * b + c / d; // 3 - 7i
	cout << expr1 << " is your answer.";

	return 0;
}