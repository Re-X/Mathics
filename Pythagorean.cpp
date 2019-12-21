#include<math.h>
#include<iostream>
#include<string>

using namespace std;

int i,j,x,y,m;
string n;
char ss2 = 253;

void Update(){
    cout<<"\n\nEnter Limit >>> ";
        cin>>n;
        if(n == "kill"||n=="stop"||n=="quit"||n=="exit")
            exit(true);
        else if(n == "cls"|| n == "clear")
            system("CLS");
            
        else
        {
            m = int(stoi(n));
        
            for (i=2; i<=m;i++){
                for (j=1;j<i;j++){
                    x = pow(i,2) - pow(j,2);
                    y = 2*i*j;
                    cout<<x<<ss2<<"+ "<<y<<ss2<<" = "<< pow(pow(x,2) + pow(y,2),0.5)<<ss2 <<endl;
                }
            }
        }
}

int main(){
    while (1==1){
        Update();
    }
}