#include <iostream>
using namespace std;

class rational
{
public:
	rational();
	rational(int);
	rational(int, int);
	~rational();
	rational reduction() const;
	friend ostream& operator <<(ostream& rout, const rational& obj);
	friend istream& operator >>(istream& rin, rational& obj);
	//未提供get出口，我只能使用友元函数重载操作符。
	friend rational operator + (const rational&, const rational&);
	friend rational operator - (const rational&, const rational&);
	friend rational operator * (const rational&, const rational&);
	friend rational operator / (const rational&, const rational&);
	friend bool operator ==(const rational&, const rational&);
	friend bool operator > (const rational&, const rational&);
	friend bool operator < (const rational&, const rational&);
	friend bool operator >= (const rational&, const rational&);
	friend bool operator <= (const rational&, const rational&);

private:
	int numerator;
	int denominator;

//	void reduction();
	
	int gcb(int large, int small) const;
};

rational::rational()
{
	numerator = 0;
	denominator = 1;
}

rational::rational(int wholeNumber)
{
	numerator = wholeNumber;
	denominator = 1;
}

rational::rational(int n, int d)
{
	numerator = n;
	denominator = d;
	*this=reduction();
}

rational::~rational()
{
}

//void rational::reduction()
//{
//	if (numerator==0)
//	{
//		denominator = 1;
//		return;
//	}
//	numerator = denominator*numerator / abs(denominator);
//	denominator = abs(denominator);
//	int temp = gcb(denominator, numerator);
//	denominator /= temp;
//	numerator /= temp;
//	
//	return;
//}

rational rational::reduction() const
{
	if (numerator==0)
	{
		return rational(0, 1);
	}
	int temp = gcb(denominator, numerator);
	rational tempr;
	tempr.numerator = denominator*numerator / (abs(denominator)) / temp;
	tempr.denominator = (abs(denominator)) / temp;
	return tempr;
}

int rational::gcb(int large, int small) const
{
	if (large<0)
	{
		large *= -1;
	}
	if (small<0)
	{
		small *= -1;
	}

	if (large==small)
	{
		return large;
	}
	//if (large%small == 0)
	//{
	//	return small;
	//}
	else if (large<small)
	{
		gcb(small, large);
	}
	else
	{
		if (!(large&1) && !(small&1))
		{
			return (gcb(large >> 1, small >> 1)<<1);
		}
		else if (!(large&1) && small&1)
		{
			return gcb(large >> 1, small);
		}
		else if (large&1 && !(small&1))
		{
			return gcb(large, small >> 1);
		}
		else return gcb(small, large - small);
	}

	
}

ostream & operator<<(ostream & rout, const rational & obj)
{
	rout << obj.numerator << "/" << obj.denominator;
	return rout;
}

istream & operator>>(istream & rin, rational & obj)
{
	char temp='\0';
	rin >> obj.numerator;
	rin >> temp;
	if (temp!='/')
	{
		cout << "illegal input!" << endl;
		exit(1);
	}
	rin >> obj.denominator;
	obj=obj.reduction();
	return rin;
}

bool operator==(const rational & r1, const rational & r2)
{
	return !((r1.denominator*r2.numerator)^(r1.numerator*r2.denominator));
}

bool operator>(const rational &r1, const rational &r2)
{
	rational t1 = r1.reduction();
	rational t2 = r2.reduction();
	return (t1.numerator*t2.denominator > t1.denominator*t1.numerator);

}

bool operator<(const rational &r1, const rational &r2)
{
	rational t1 = r1.reduction();
	rational t2 = r2.reduction();
	return (t1.numerator*t2.denominator < t1.denominator*t1.numerator);
}

bool operator>=(const rational &r1, const rational &r2)
{
	return (r1 > r2 || r1 == r2);
}

bool operator<=(const rational &r1, const rational &r2)
{
	return (r1 < r2 || r1 == r2);
}

rational operator+(const rational &r1, const rational &r2)
{
	int num = r1.numerator*r2.denominator + r2.numerator*r1.denominator;
	int den = r1.denominator*r2.denominator;
	return rational(num, den);
}

rational operator-(const rational &r1, const rational &r2)
{
	int num = r1.numerator*r2.denominator - r2.numerator*r1.denominator;
	int den = r1.denominator*r2.denominator;
	return rational(num, den);
}

rational operator*(const rational &r1, const rational &r2)
{
	int num = r1.numerator*r2.numerator;
	int den = r1.denominator*r2.denominator;
	return rational(num, den);
}

rational operator/(const rational &r1, const rational &r2)
{
	int num = r1.numerator*r2.denominator;
	int den = r1.denominator*r2.numerator;
	return rational(num, den);
}

int main()
{
	rational obj1(1,9),obj2(5,22);
//	cin >> obj1;
	cout << obj1<<endl;
//	cin >> obj2;
	cout << obj2;
	cout << endl << (obj1 == obj2)<<endl;
	cout << endl << (obj1 < obj2) << endl;
	cout << endl << (obj1 > obj2) << endl;
	cout << endl << (obj1 <= obj2) << endl;
	cout << endl << (obj1 >= obj2) << endl;
	cout << endl << (obj1 + obj2) << endl;
	cout << endl << (obj1 - obj2) << endl;
	cout << endl << (obj1 * obj2) << endl;
	cout << endl << (obj1 / obj2) << endl;

	

	return 0;
}