#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

void print_double_array(vector<double> & arr) {
    for(unsigned i=0; i<arr.size(); i++) {
	cout << arr[i] << " " ;
    }
    cout << endl;
}

int main(int argc, char * argv[]) {

    ifstream infile("D-large.in");
    ofstream ofile("D-large0.out");

    int T;
    infile >> T;

    for(int i=0; i<T; i++) {
	int num_of_blocks;
	infile >> num_of_blocks;

	vector<double> naomi(num_of_blocks);
	vector<double> ken(num_of_blocks);

	for(int j=0; j<num_of_blocks; j++) {
	    infile >> naomi[j];
	}
	for(int j=0; j<num_of_blocks; j++) {
	    infile >> ken[j];
	}

	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());

	int y = 0;
	int z = 0;

	for(int j=0, k=0; j<num_of_blocks; j++) {
	    if(naomi[j] > ken[k]) {
		y++;
		k++;
	    }
	}

	for(int j= num_of_blocks-1, k=num_of_blocks-1; j>=0; j--) {
	    if(naomi[j] > ken[k]) {
		z++;
	    } else {
		k--;
	    }
	}

	ofile << "Case #" << i+1 << ": ";
	ofile << y << " " << z << endl;

	//print_double_array(naomi);
	//print_double_array(ken);
    }
    return 0;
}
