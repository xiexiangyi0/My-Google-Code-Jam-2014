#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

/*C,F,X,    X/2+N*F < C/2+N*F + X/2+N*F+F     => N=?*/
using namespace std;

double besttime(double c, double f, double x){
	int n=0;
	/*
	while(true){
		double time1= x/(2+n*f);
		double time2= c/(2+n*f) + x/(2+n*f+f);
		if(time1<=time2)break;
		else ++n;
	}
	*/

	n = ceil(x/c - 2./f -1);
	if(n < 0) n = 0;

	double time = 0.000000;
	for(int i=0;i<n;++i){
		double ti= c/(2+i*f);
		time+=ti;
		//if(ti < 1e-6) break;
	}
	time+= x/(2+n*f);
	return time;


}

int main(int argc, const char* argv[]){
	ifstream infile;
	int testcasenum;
	ofstream outfile;
	outfile.open("B-small-practice2.out");
	infile.open("B-small-attempt2.in");

	infile >> testcasenum;
	for(int i=0; i< testcasenum; i++) {
	    double c, f, x;
	    infile >> c >> f >> x;
	    outfile << fixed;
	    outfile<<"Case #"<<i+1<<": "<<setprecision(7)<<besttime(c,f,x)<<endl;

	}
    infile.close();
	outfile.close();
	return 0;
}