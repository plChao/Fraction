#include "Fraction.h"

#include <iostream>
#include <cmath>

using namespace std;

Fraction::Fraction(){
    numerator = 1;
    denominator = 1;
}
Fraction::Fraction(int a, int b){
    numerator = a;
    denominator = b;
    this->reduction();
}
Fraction operator * (Fraction const &a, Fraction const &b){
    Fraction result(a.numerator * b.numerator, a.denominator * b.denominator);
    result.reduction();
    return result;
}
Fraction operator - (Fraction const &a, Fraction const &b){
    Fraction result(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
    return result;
}
Fraction operator + (Fraction const &a, Fraction const &b){
    Fraction result(a.numerator*b.denominator + b.numerator*a.denominator, a.denominator*b.denominator);
    return result;
}
Fraction operator / (Fraction const &a, Fraction const &b){
    Fraction result(a.numerator * b.denominator, a.denominator*b.numerator);
    return result;
}
bool operator == (Fraction const &a, Fraction const &b){
    return (a.numerator == b.numerator) && (a.denominator == b.denominator);
}
void Fraction::defactor(){
    int tmp = numerator;
    for(int i=2;i<=numerator;i++){
        if(tmp == 1){
            break;
        }
        if(tmp % i == 0){
            num_frac[i] = 1;
            tmp /= i;
            while( tmp % i == 0){
                num_frac[i] += 1;
                tmp /= i;
            }
        }
    }
    // for(auto iter = num_frac.begin(); iter != num_frac.end(); iter++){
    //     cout<<iter->first<<" "<<iter->second<<endl;
    // }
    tmp = denominator;
    for(int i=2;i<=denominator;i++){
        if(tmp == 1){
            break;
        }
        if(tmp % i == 0){
            den_frac[i] = 1;
            tmp /= i;
            while( tmp % i == 0){
                den_frac[i] += 1;
                tmp /= i;
            }
        }
    }
}
void Fraction::reduction(){
    this->defactor();
    int reduct_num = 1;
    for(auto iter = num_frac.begin(); iter != num_frac.end(); iter++){
        auto diter = den_frac.find(iter->first);
        if(diter != den_frac.end()){
            // can do reduction
            int times = min(diter->second, iter->second);
            iter->second -= times;
            diter->second -= times;
            reduct_num *= pow(iter->first, times);
        }
    }
    numerator /= reduct_num;
    denominator /= reduct_num;
}

double Fraction::getvalue(){
    double a;
    a = (1.0)*numerator;
    a = a / denominator;
    return a;
}

ostream & operator << (ostream &out, const Fraction &f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}
 
istream & operator >> (istream &in,  Fraction &f)
{
    cout << "Enter numerator: ";
    in >> f.numerator;
    cout << "Enter denominator: ";
    in >> f.denominator;
    return in;
}

Fraction::~Fraction(){

}