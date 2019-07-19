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

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return (lhs-rhs).num >= 0;
}

Fraction f_1(1, 1);

int count_lattices(Fraction k, Fraction b, f_type n) {
    auto fk = (f_type)k;
    auto fb = (f_type)b;
    auto cnt = 0LL;
    
    if (k >= f_1 || b >= f_1) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= Fraction(fk, 1);
        b -= Fraction(fb, 1);
    }
    auto t = k * Fraction(n, 1) + b;
    auto ft = (f_type)t;
    if (ft >= 1) {
        cnt += count_lattices(f_1 / k, (t - Fraction((f_type)t, 1)) / k, (f_type)t);
    }
    return cnt;
}

int main() {    
    f_type k, b, n;
    cin >> k >> b >> n;

	cout << count_lattices(Fraction(k, 1), Fraction(b, 1), n) << endl;	
	
    return 0;
}
