#include<math.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define PI 3.141592653589793238462643383279L;
#define e 2.718281828459045235360287471352L

double rad2deg(double phi){
    return phi*180/PI;
}

double deg2rad(double phi){
    double x = phi*PI;
    x = x/180L;
    return x;
}

#pragma region Complex n co 

class polar {
    public:
        double r = 0, arg = 0;
        polar(double re = 0, double ar = 0) {r = re; arg = ar;}
};

class complex {
    public:
        double real = 0, imaginary = 0;
    public:
        friend ostream& operator<<(ostream& os, const complex &obj);
        complex(double re = 0, double im = 0) {real = re; imaginary = im;}
        double cos(){
            return real/(std::pow(real,2) + std::pow(imaginary,2));   }

        double sin(){
            return imaginary/(std::pow(real,2) + std::pow(imaginary,2));  }
        double tan(){
            return imaginary/real;  }
        complex rot(double phi){
            phi = deg2rad(phi);
            double t = std::tan(phi);
            complex z;
            z.real = (real - (t*imaginary))/(1+std::pow(t,2));
            z.imaginary = (imaginary + (t*real))/(1+std::pow(t,2));
            return z;   }
        double abs(){
            return std::pow(std::pow(real,2) + std::pow(imaginary,2),0.5); }

        double arg(string t = "rad"){
            if(t == "deg" || t == "degrees" || t == "d"){
                return atan2l(imaginary, real)*180/PI;
            }
            return atan2l(imaginary, real); }

        complex operator + (complex const &obj){
            complex res;
            res.real = real + obj.real;
            res.imaginary = imaginary + obj.imaginary;
            return res; }

        complex operator * (complex const &obj){
            complex res;
            res.real = real*obj.real - imaginary*obj.imaginary;
            res.imaginary = real*obj.imaginary + imaginary*obj.real;
            return res; }
        complex operator * (int i){
            return complex(real*i,imaginary*i); }
        complex operator * (long i){
            return complex(real*i,imaginary*i); }
        complex operator * (float i){
            return complex(real*i,imaginary*i); }
        complex operator * (double i){
            return complex(real*i,imaginary*i); }

        complex operator / (int i){
            return complex(real/i,imaginary/i); }
        complex operator / (long i){
            return complex(real/i,imaginary/i); }
        complex operator/ (float i){
            return complex(real/i,imaginary/i); }
        complex operator / (double i){
            return complex(real/i,imaginary/i); }

        complex operator~() const{
            complex res;
            res.real = real;
            res.imaginary = -imaginary;
            return res; }

        complex operator!() const{
            complex res;
            res.real = real;
            res.imaginary = -imaginary;
            return res; }

        double operator&() const{
            return std::pow(std::pow(real,2) + std::pow(imaginary,2),0.5); }

        complex operator / (complex const &obj){
            complex res,z;
            double n;
            z = !obj;
            res = z*obj;
            n = res.real;
            res.real = (real*obj.real - (-imaginary*obj.imaginary))/n;
            res.imaginary = (real*(-obj.imaginary) + imaginary*obj.real)/n;
            return res; }

        complex pow(double n){
            complex z;
            double ac, as, ab;
            ab = std::pow(real,2) + std::pow(imaginary,2);
            ac = std::cos(n*arg());
            as = std::sin(n*arg());
            z.real = (std::pow(ab,n/2)) * ac;
            z.imaginary = (std::pow(ab,n/2)) * as;
            return z;   }
        
        complex operator^(double const &obj){
            complex z;
            double ac, as, ab,n;
            n = obj;
            ab = std::pow(real,2) + std::pow(imaginary,2);
            ac = std::cos(n*arg());
            as = std::sin(n*arg());
            z.real = (std::pow(ab,n/2)) * ac;
            z.imaginary = (std::pow(ab,n/2)) * as;
            return z;   }

        complex log(double n = e){
            complex z;
            z.real = std::log(abs())/std::log(n);
            z.imaginary = arg()/std::log(n);
            return z;   }

        polar pole(){
            polar z;
            z.r = abs();
            z.arg = arg();
            return z;   }
};

ostream& operator<<(ostream& os, const complex & obj){
    os << '(' << obj.real << ", " << obj.imaginary << "i)";
    return os;  
}

vector<string> split(string s, char x){
    vector<string> r;
    string k="";
    for (int i = 0;i<s.length();i++){
        if(s[i]==x){
            r.push_back(k);
            k="";
            continue;
        }
        k+=s[i];
    }
    r.push_back(k);
    return r;
}

complex parseComplex(string s){
    complex z;
    double r=0,im=0;
    vector<string> st;
    st = split(s,'+');
    if(st[0].find('i')==-1){
        for(int i = 0;i<st[0].length();i++){
            if(st[0][i]==' '){
                st[0] = st[0].erase(i,i);
            }
        }
        r+=stod(st[0]);
    }
    else {
        for(int i = 0;i<st[0].length();i++){
            if(st[0][i]==' ' || st[0][i]=='i'){
                st[0] = st[0].erase(i,i+1);
            }
        }
        im+=stod(st[0]);
    }

    if(st[1].find('i')==-1){
        for(int i = 0;i<st[1].length();i++){
            if(st[1][i]==' '){
                st[1] = st[1].erase(i,i);
            }
        }
        r+=stod(st[1]);
    }
    else {
        for(int i = 0;i<st[1].length();i++){
            if(st[1][i]==' ' || st[1][i]=='i'){
                st[1] = st[1].erase(i,i+1);
            }
        }
        im+=stod(st[1]);
    }
    z.real = r;
    z.imaginary = im;
    return z;
}

complex fromPolar(polar s){
    complex z;
    z.real = s.r*std::cos(s.arg);
    z.imaginary = s.r*std::sin(s.arg);
    return z;   
}

#pragma endregion

#pragma region Vector2

class Vector2 {
    public:
        long double x=0,y=0;
        Vector2(double x1=0, double y1=0){x=x1;y=y1;};
        friend ostream& operator<<(ostream& os, const Vector2 &obj);

        Vector2 operator+(Vector2 &obj){
            return Vector2(x+obj.x, y+obj.y);   }

        Vector2 operator-(Vector2 &obj){
            return Vector2(x-obj.x, y-obj.y);   }

        Vector2 operator*(double obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(long obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(int obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(float obj){
            return Vector2(x*obj, y*obj);   }
        
        Vector2 operator/(double obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(long obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(int obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(float obj){
            return Vector2(x/obj, y/obj);   
        }

        double sqmagnitude(){
            return pow(x,2) + pow(y,2); }

        double magnitude(){
            return pow(pow(x,2) + pow(y,2), 0.5);
        }

};

ostream& operator<< (ostream& os, const Vector2 &obj){
    os << '(' << obj.x << ", " << obj.y << ')';
    return os;
}
#pragma endregion

class list{
    public:
        vector<int> l;
        list (vector<int> l1 = {}) {l = l1;}
        void append(int i){
            l.push_back(i);
        }
        void print(){
            cout<<l[l.size()-1];
        }

};

/*int main(){
    Vector2 c(5,78), v(6,3);
    list l({3,4,45,3,2,5});
    l.append(4);
}*/
