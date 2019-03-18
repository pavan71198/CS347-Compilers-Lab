
#include<iostream> 
using namespace std; 
  
class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
    void print() { cout << real << " + i" << imag << endl; } 
  
// The global operator function is made friend of this class so 
// that it can access private members 
friend Complex operator + (Complex const &, Complex const &); 
}; 
  
  
Complex::operator + (Complex const &c1, Complex const &c2) 
{ 
     return Complex(c1.real + c2.real, c1.imag + c2.imag); 
} 

class complx
{
	double real,
		 imag;
public:
	complx( double real = 0., double imag = 0.); // constructor
	complx operator+(const complx&) const;       // operator+()
};

// define constructor
complx::complx( double r, double i )
{
	real = r; imag = i;
}

// define overloaded + (plus) operator
complx complx::operator+ (const complx& c) const
{
	complx result;
	result.real = (this->real + c.real);
	result.imag = (this->imag + c.imag);
	return result;
}

int main()
{
	
}
  
int main() 
{ 
	Complex c1(10, 5); 
	Complex c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();
	complx x(4,4);
	complx y(6,6);
	complx z = x + y; // calls complx::operator+()
	return 0; 
} 

