//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/11/12
//  FILENAME   : HW05B038.CPP 
//  DESCRIPTION: as question described
//================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>

// it is for double !!
bool digIn(double &out){		//foolproof
	char c[100000]; int ok = 0; 
	while (!ok){
		ok = 1;
		if( scanf("%s", c) ==EOF)
			return 0;
		int dot = 0,mus=0;
		for (int i = 0; c[i] && ok && dot<=1 && mus<=1; ++i)
			if (isdigit(c[i]))
				continue;
			else if (c[i] == '-')
				++mus;
			else if (c[i] == '.')
				++dot;
			else
				ok = 0; 
		if (dot > 1 || mus >1)
			ok = 0; 
		if (!ok)
			puts("It is not n number !! Please redo it !!");
		else
			out = atof(c);
	}
	return 1;
}

int main(){
	puts("if finished  Enter ctrl+z to exit");
	double a;
	while(digIn(a)){
		if(!((int)a == a && (int)a%2==1)){
			puts("wrong input");
			continue;
		}
		//init 
		int n = (int)a;
		int c[n][n];
		memset(c,0,sizeof(c));
		int now=1,x=0,y=n>>1;
		// fill it
		while(now <= n*n  ){// all dig
			c[x][y]=now++;
			//printf("%d %d\n",x,y); // test
			int tx=(x-1+n)%n,ty=(y+1)%n;
			if(c[tx][ty]){// if it has dig
				x = (x+1)%n;
			}
			else {
				x =tx;
				y =ty;
			}
		}
		//output
		for(int i=0;i<n;++i,puts(""))
			for(int j=0;j<n;++j)
				printf("%3d ",c[i][j]);
	}
	return 0;
}
