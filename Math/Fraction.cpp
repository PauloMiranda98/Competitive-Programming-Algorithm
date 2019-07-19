#include <bits/stdc++.h>

using namespace std;

typedef long long f_type;

struct Fraction {
	f_type num, den;

	Fraction() {
		num = 0;
		den = 1;
	}

	Fraction(f_type _num, f_type _den) {
		f_type tmp = __gcd(_num, _den);
		num = _num/tmp;
		den = _den/tmp;
		
		if(den < 0){
			den = -den;
			num = -num;
		}
	}
	f_type floor(){
		return (num+den-1)
	}
	operator f_type() {return num/den;}
	operator float() {return ((float)num)/den;}
	operator double() {return ((double)num)/den;}
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {    
    return Fraction(lhs.num*rhs.den + rhs.num*lhs.den, lhs.den*rhs.den);
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    return lhs = Fraction(lhs.num*rhs.den + rhs.num*lhs.den, lhs.den*rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {    
    return Fraction(lhs.num*rhs.den - rhs.num*lhs.den, lhs.den*rhs.den);
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    return lhs = Fraction(lhs.num*rhs.den - rhs.num*lhs.den, lhs.den*rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num*rhs.num, lhs.den*rhs.den);
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    return lhs = Fraction(lhs.num*rhs.num, lhs.den*rhs.den);
}

Fraction operator*(int lhs, const Fraction& rhs) {
    return Fraction(lhs*rhs.num, rhs.den);
}

Fraction operator*(const Fraction& rhs, int lhs) {
    return Fraction(lhs*rhs.num, rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num*rhs.den, lhs.den*rhs.num);
}

Fraction operator/=(Fraction& lhs, const Fraction& rhs) {
    return lhs = Fraction(lhs.num*rhs.den, lhs.den*rhs.num);
}

int main() {
    Fraction a(3,5);
    Fraction b(7,10);
    Fraction c;

    c = a + b;
    cout << c.num << "/" << c.den << endl;

    c = a - b;
    cout << c.num << "/" << c.den << endl;

    c = a * b;
    cout << c.num << "/" << c.den << endl;

    c = a / b;
    cout  << c.num << "/" << c.den << endl;

    c = -1 * b;
    cout << c.num << "/" << c.den << endl;

    c = b * (-1);
    cout << c.num << "/" << c.den << endl;

    c = Fraction(-100,3);

    cout <<    (f_type)c << endl;
    cout <<  (float)c << endl;
    cout << (double)c << endl;

    a -= b;
    cout  << a.num <<"/" << a.den << endl;

    return 0;
}
