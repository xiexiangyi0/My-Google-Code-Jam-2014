// round1bt2.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<assert.h>
#include<algorithm>

using namespace std;

int min_step(const vector<string> & words) {
    int N = words.size();
    vector<int> idxs(N, 0);
    int min = 0;
    while(idxs[0] < (int)words[0].size()) {
	char next_char = words[0][idxs[0]];
	vector<int> dups(N, 0);
	for(int i=0; i<N; i++) {
	    if(idxs[i] >= words[i].size()) return -1;
	    if(words[i][idxs[i]] != next_char) return -1;
	    int length = 0;
	    while(words[i][idxs[i]] == next_char) {
		idxs[i]++;
		length++;
	    }
	    dups[i] = length;
	}
	sort(dups.begin(), dups.end());
	int last = dups[0];
	for(int i=1; i<N; i++) {
	    int delta = dups[i] - dups[i-1];
	    if(i < N-i) {
		min += (delta*i);
	    } else {
		min += (delta*(N-i));
	    }
	}
    }
    for(int i=0; i<N; i++) {
	if(idxs[i] < words[i].size()) return -1;
    }
    return min;
}

int main() {
    ifstream infile("A-large.in");
    ofstream outfile("A-large.out");
    int T;
    infile >> T;
    for(int i=0; i<T; i++) {
	int N;
	infile >> N;
	vector<string> words(N, "");
	for(int j=0; j<N; j++) {
	    infile >> words[j];
	}
	int min = -1;
	min = min_step(words);
	outfile << "Case #" << i+1 << ": ";
	if(min == -1) {
	    outfile << "Fegla Won";
	} else {
	    outfile << min;
	}
	outfile << endl;
    }
    return 0;
}


