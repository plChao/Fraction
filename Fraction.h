#ifndef _Fraction_
#define _Fraction_

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Fraction
{
public:
    Fraction();
    Fraction(int , int);
    Fraction(Fraction &&) = default;
    Fraction(const Fraction &) = default;
    Fraction &operator=(Fraction &&) = default;
    Fraction &operator=(const Fraction &) = default;
    friend Fraction operator * (Fraction const &, Fraction const &);
    friend Fraction operator - (Fraction const &, Fraction const &);
    friend Fraction operator + (Fraction const &, Fraction const &);
    friend Fraction operator / (Fraction const &, Fraction const &);
    friend bool operator == (Fraction const &, Fraction const &);
    ~Fraction();
    void reduction();
    double getvalue();
    void defactor();
    friend ostream & operator << (ostream &, const Fraction &);
    friend istream & operator >> (istream &,  Fraction &);
    int numerator = 1;
    int denominator = 1;
    vector<int> num_frac_rec;
    map<int, int> num_frac;
    map<int, int> den_frac;
    
private:
    
};

#endif
