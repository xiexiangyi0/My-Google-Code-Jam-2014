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

using namespace std;

 int Lottery(unsigned int a, unsigned int b, unsigned int k){
	 int count=0;
	 if(a<k || b<k)
		 return a*b;

	 int q=k;
	 int n=1;
	 while(q>>n){
		 n++;
	 }
	 
	 unsigned int w1=0;
	 while(((a-w1)& k)!= k){
		 w1++;
	 }
	 unsigned int w2=0;
	 while(((b-w2)& k)!= k){
		 w2++;
	 }

	 count= a*b - (((a-w1-k)>>n)+1) * (((b-w2-k)>>n)+1);
	 return count;
 }

int main(int argc, const char* argv[]){
	ifstream infile;
	infile.open("B-small-attempt0.in");
    ofstream outfile;
	outfile.open("B-smalltest0.out");
	
    int T;
    infile >> T;
  for(int i=0; i<T; i++) {
    int a, b, k;
	infile >> a >> b >> k;
	int num = Lottery(a,b,k);
	
	outfile <<"Case #" <<i+1<<": "<<num<<endl;
  }
}