#include<iostream>
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int main(){
	int a,b;
	while(cin>>a>>b)
		cout << "gcd:"<<gcd(a,b)
			 <<"\nlcm:"<<lcm(a,b)<<endl;

	return 0;
}
