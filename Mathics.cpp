#include<math.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

#pragma region  Input System

string input(string o = ""){
    string x;
    cout<<o;
    getline(cin,x);
    return x;
}

#pragma endregion

#pragma region Constants

struct Constants{
    //The Pi constant.
    const long double PI = 3.141592653589793238462643383279L;
    //The euler constant.
    const long double e = 2.718281828459045235360287471352L;
    //Radian to Degree conversion const : 57.2957795131
    const long double Rad2Deg = 57.2957795131L;
    //Degree to Radian conversion const : 0.01745329251
    const long double Deg2Rad = 0.01745329251L;
};

Constants Const;

#pragma endregion

//Convert radians to degrees.
double rad2deg(double phi){
    return phi*180/Const.PI;
}
//Convert degrees to radians.
double deg2rad(double phi){
    double x = phi*Const.PI;
    x = x/180L;
    return x;
}

#pragma region Complex Number 

class polar {
    public:
        double r = 0, arg = 0;
        polar(double re = 0, double ar = 0) {r = re; arg = ar;}
};

class complex {
    public:
        //Real part of the complex number.
        double real = 0;
        //Imaginary part of the complex number.
        double imaginary = 0;
    public:
        friend ostream& operator<<(ostream& os, const complex &obj);
        complex(double re = 0, double im = 0) {real = re; imaginary = im;}
        
        //Cosine of the complex number.
        double cos(){
            return real/(std::pow(real,2) + std::pow(imaginary,2));   }
        //Sine of the complex number.
        double sin(){
            return imaginary/(std::pow(real,2) + std::pow(imaginary,2));  }
        //Tangent of the complex number.
        double tan(){
            return imaginary/real;  }
        //Returns this complex number rotated by phi degrees.
        complex rot(double phi){
            phi = deg2rad(phi);
            double t = std::tan(phi);
            complex z;
            z.real = (real - (t*imaginary))/(1+std::pow(t,2));
            z.imaginary = (imaginary + (t*real))/(1+std::pow(t,2));
            return z;   }
        //Returns absolute value of this complex number.
        double abs(){
            return std::pow(std::pow(real,2) + std::pow(imaginary,2),0.5); }
        //Returns the argument of this complex number.
        double arg(string t = "rad"){
            if(t == "deg" || t == "degrees" || t == "d"){
                return atan2l(imaginary, real)*180/Const.PI;
            }
            return atan2l(imaginary, real); }

        complex operator + (complex const &obj){
            complex res;
            res.real = real + obj.real;
            res.imaginary = imaginary + obj.imaginary;
            return res; }

        complex operator* (complex const &obj){
            complex res;
            res.real = real*obj.real - imaginary*obj.imaginary;
            res.imaginary = real*obj.imaginary + imaginary*obj.real;
            return res; }
        void operator*= (complex const &obj){
            real = real*obj.real - imaginary*obj.imaginary;
            imaginary = real*obj.imaginary + imaginary*obj.real;    }
        complex operator * (int i){
            return complex(real*i,imaginary*i); }
        complex operator * (long i){
            return complex(real*i,imaginary*i); }
        complex operator * (float i){
            return complex(real*i,imaginary*i); }
        complex operator * (double i){
            return complex(real*i,imaginary*i); }
        
        void operator*= (int i){
            real*=i; imaginary*=i; }
        void operator*= (long i){
            real*=i; imaginary*=i; }
        void operator*= (float i){
            real*=i; imaginary*=i; }
        void operator*= (double i){
            real*=i; imaginary*=i; }

        complex operator / (int i){
            return complex(real/i,imaginary/i); }
        complex operator / (long i){
            return complex(real/i,imaginary/i); }
        complex operator/ (float i){
            return complex(real/i,imaginary/i); }
        complex operator / (double i){
            return complex(real/i,imaginary/i); }
        
        void operator/= (int i){
            real/=i; imaginary/=i; }
        void operator/= (long i){
            real/=i; imaginary/=i; }
        void operator/= (float i){
            real/=i; imaginary/=i; }
        void operator/= (double i){
            real/=i; imaginary/=i; }

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

        //Returns the magnitude of this complex number.
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

        void operator^=(double const &obj){
            double ac, as, ab,n;
            n = obj;
            ab = std::pow(real,2) + std::pow(imaginary,2);
            ac = std::cos(n*arg());
            as = std::sin(n*arg());
            real = (std::pow(ab,n/2)) * ac;
            imaginary = (std::pow(ab,n/2)) * as;    }

        //Returns a complex number raised to a power n.
        complex pow(double n){
            complex z;
            double ac, as, ab;
            ab = std::pow(real,2) + std::pow(imaginary,2);
            ac = std::cos(n*arg());
            as = std::sin(n*arg());
            z.real = (std::pow(ab,n/2)) * ac;
            z.imaginary = (std::pow(ab,n/2)) * as;
            return z;   }

        //Returns the logarithm of this complex with base n.
        //Default base is e.
        complex log(double n = Const.e){
            complex z;
            z.real = std::log(abs())/std::log(n);
            z.imaginary = arg()/std::log(n);
            return z;   }

        //Returns polar form of this complex number.
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
        //x co-ordinate of this vector2.
        long double x=0;
        //y co-ordinate of this vector2.
        long double y=0;

        Vector2(double x1=0, double y1=0){
            x=x1;
            y=y1;
            }
        friend ostream& operator<<(ostream& os, const Vector2 &obj);
        
        //Angle of this vector2 from x-axis (in radians).
        double angle(){
            return std::atan(y/x);  }
        //Angle of this vector2 with respect to another (in radians).
        double angleWith(Vector2 v){
            return -v.angle()-angle(); }
        Vector2 operator+(Vector2 &obj){
            return Vector2(x+obj.x, y+obj.y);   }
        
        Vector2 operator-(Vector2 &obj){
            return Vector2(x-obj.x, y-obj.y);   }
        
        void operator+=(Vector2 &obj){
            x+=obj.x; y+=obj.y;   }

        void operator-=(Vector2 &obj){
            x-=obj.x; y-=obj.y;   }

        Vector2 operator*(double obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(long obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(int obj){
            return Vector2(x*obj, y*obj);   }
        Vector2 operator*(float obj){
            return Vector2(x*obj, y*obj);   }
        
        void operator*=(double obj){
            x*=obj; y*=obj;   }
        void operator*=(long obj){
            x*=obj; y*=obj;   }
        void operator*=(int obj){
            x*=obj; y*=obj;   }
        void operator*=(float obj){
            x*=obj; y*=obj;   }
        
        Vector2 operator/(double obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(long obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(int obj){
            return Vector2(x/obj, y/obj);   }
        Vector2 operator/(float obj){
            return Vector2(x/obj, y/obj);   }
        
        void operator/=(double obj){
            x/=obj; y/=obj;   }
        void operator/=(long obj){
            x/=obj; y/=obj;   }
        void operator/=(int obj){
            x/=obj; y/=obj;   }
        void operator/=(float obj){
            x/=obj; y/=obj;  
        }
        
        bool operator==(Vector2 &obj){
            return (x==obj.x && y==obj.y);  }
        //Vector2 of magnitude 1 in the direction of this vector's direction.
        Vector2 normalize(){
            return Vector2(x/magnitude(), y/magnitude());   }
        //Squared magnitude of this vector2.
        double sqmagnitude(){
            return pow(x,2) + pow(y,2); }
        //Magnitude of this vector2.
        double magnitude(){
            return pow(pow(x,2) + pow(y,2), 0.5);   }
        //Dot product of this vector2 with another.
        double dot(Vector2 v){
            return (x*v.x) + y*v.y; }
        //Projection on another vector2.
        Vector2 project(Vector2 v){
            double x = dot(v)/v.magnitude();
            return v.normalize()*x; }
        
        //Returns distance between two vectors.
        double distance(Vector2 v){
            return (Vector2(x,y)-v).magnitude();
        }
   
};

ostream& operator<< (ostream& os, const Vector2 &obj){
    os << '(' << obj.x << ", " << obj.y << ')';
    return os;
}
#pragma endregion

#pragma region Vector3
class Vector3 {
    public:
        //x component of this vector3.
        long double x=0;
        //y component of this vector3.
        long double y=0;
        //z component of this vector3.
        long double z=0;

        Vector3(double x1=0, double y1=0, double z1=0){
            x=x1;
            y=y1;
            z=z1;
        }
        friend ostream& operator<<(ostream& os, const Vector3 &obj);
        
        //Angle of this vector3 with respect to another (in radians).
        double angleWith(Vector3 v){
            return std::acos(dot(v)/(magnitude()*v.magnitude())); }
        Vector3 operator+(Vector3 &obj){
            return Vector3(x+obj.x, y+obj.y, z+obj.z);   }
        
        Vector3 operator-(Vector3 &obj){
            return Vector3(x-obj.x, y-obj.y, z-obj.z);   }
        
        void operator+=(Vector3 &obj){
            x+=obj.x; y+=obj.y; z+=obj.z;   }

        void operator-=(Vector3 &obj){
            x-=obj.x; y-=obj.y; z-=obj.z;   }

        Vector3 operator*(double obj){
            return Vector3(x*obj, y*obj, z*obj);   }
        Vector3 operator*(long obj){
            return Vector3(x*obj, y*obj, z*obj);   }
        Vector3 operator*(int obj){
            return Vector3(x*obj, y*obj, z*obj);   }
        Vector3 operator*(float obj){
            return Vector3(x*obj, y*obj, z*obj);   }
        
        void operator*=(double obj){
            x*=obj; y*=obj; z*=obj;   }
        void operator*=(long obj){
            x*=obj; y*=obj; z*=obj;   }
        void operator*=(int obj){
            x*=obj; y*=obj; z*=obj;   }
        void operator*=(float obj){
            x*=obj; y*=obj; z*=obj;   }
        
        Vector3 operator/(double obj){
            return Vector3(x/obj, y/obj, z/obj);   }
        Vector3 operator/(long obj){
            return Vector3(x/obj, y/obj, z/obj);   }
        Vector3 operator/(int obj){
            return Vector3(x/obj, y/obj, z/obj);   }
        Vector3 operator/(float obj){
            return Vector3(x/obj, y/obj, z/obj);   }
        
        void operator/=(double obj){
            x/=obj; y/=obj; z/=obj;   }
        void operator/=(long obj){
            x/=obj; y/=obj; z/=obj;   }
        void operator/=(int obj){
            x/=obj; y/=obj; z/=obj;   }
        void operator/=(float obj){
            x/=obj; y/=obj; z/=obj;   
        }
        
        bool operator==(Vector3 &obj){
            return (x==obj.x && y==obj.y && z==obj.z);  }
        //Vector3 of magnitude 1 in the direction of this vector.
        Vector3 normalize(){
            return Vector3(x/magnitude(), y/magnitude(), z/magnitude());   }
        //Squared magnitude of this vector3.
        double sqmagnitude(){
            return pow(x,2) + pow(y,2) + pow(z,2); }
        //Magnitude of this vector3.
        double magnitude(){
            return pow(pow(x,2) + pow(y,2) + pow(z,2), 0.5);   }
        //Dot product of this vector3 with another.
        double dot(Vector3 v){
            return (x*v.x) + (y*v.y) + (z*v.z); }
        //Projection on another vector3.
        Vector3 project(Vector3 v){
            double x = dot(v)/v.magnitude();
            return v.normalize()*x; }
        //Returns distance between two vectors.
        double distance(Vector3 v){
            return (Vector3(x,y,z)-v).magnitude();
        }
};

ostream& operator<< (ostream& os, const Vector3 &obj){
    os << '(' << obj.x << ", " << obj.y << ", " << obj.z << ')';
    return os;
}

#pragma endregion

#pragma region Strings

struct i_format : public exception {
   const char * what () const throw () {
      return "string not in correct format!";
   }
};

class str{
    private: std::string String;
	public:
		str() {}
		template <class dataType>
		str(dataType charString) { String = charString; }
        friend ostream& operator<<(ostream& os, const str &obj);
    public:
        str operator[](int i){
            return String[i];   }
        str operator*(int x){
            string res = "";
            for (int i = 0; i<x; i++){
                res += String;
            }
            return str(res);    }

        str operator+(str s){
            return str(String+s.String);    }
        void operator*=(int x){
            string res = "";
            for (int i = 0; i<x; i++){
                res += String;
            }
            String = res;   }
        void operator+=(str s){
            String+=s.String;
        }
        //Returns the length of the string.
        int len(){
            return String.length(); }
        //Return the position of fist occurence of a substring.
        int find(str c){
            return String.find(c.String);   }
        //Return frequency of occurence of a substring.
        int count(str c){
            string z = String;
            int x = z.find(c.String), i=0;
            while (x!=-1){
                i++;
                z.erase(0,x+c.len());
                x = z.find(c.String);
            }
            return i;
        }
        //Returns integer of the string.
        long long int toInt(){
            try{
                return stoull(String);
            }
            catch(exception e){
                throw i_format();
            }   }
        //Returns decimal double of the string.
        long double toDouble(){
            try{
                return stold(String);
            }
            catch(exception e){
                throw i_format();
            }   }
};

ostream& operator<< (ostream& os, const str &obj){
    os << obj.String;
    return os;
}

#pragma endregion

/*
int main(){
    Vector2 c(4,3), v(0,0);
    Vector3 x(1,5,3);
    complex m(2,1);
    cout<<x.normalize()<<endl;
    cout<<c.angle()*Const.Rad2Deg<<endl;
}
*/