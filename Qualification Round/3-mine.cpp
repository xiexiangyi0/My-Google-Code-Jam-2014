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

class Board{
    public:
	char **cells;
	int **values;
	int row, col;
	int minesnum;

	void reset() {
	    cells = new  char* [row];
	    for (int i=0;i<row;++i){
		cells[i]= new char[col];           
		for (int j=0;j<col;++j){
		    cells[i][j]='.';                
		}
	    }
	    for (int i=0;i<row;++i){
		values[i]= new int[col];           
		for (int j=0;j<col;++j){
		    values[i][j]=0;                
		}
	    }
	}

	Board(int r,int c,int m){
	    row=r; 
	    col=c;
	    minesnum=m;

	    cells = new  char* [row];
	    for (int i=0;i<row;++i){
		cells[i]= new char[col];           
		for (int j=0;j<col;++j){
		    cells[i][j]='.';                
		}
	    }

	    values = new int*[row];
	    for (int i=0;i<row;++i){
		values[i]= new int[col];           
		for (int j=0;j<col;++j){
		    values[i][j]=0;                
		}
	    }
	}
	~Board(){
	    for(int i=0;i<row;++i){
		delete  [] cells[i];
	    }
	    delete  [] cells;
	    for(int i=0;i<row;++i){
		delete  [] values[i];
	    }
	    delete  [] values;
	}

	//spiral order1.
	void ConfigMine1() {
	    int beginX = 0, endX = col-1;
	    int beginY = 0, endY = row-1;

	    int mnum = minesnum;
	    int spiralnum=0;

	    while(mnum>0){
		// From left to right
		if(mnum>=(endX-beginX+1)){
		    for (int i = beginX; i <= endX; ++i){
			cells[beginY][i]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=beginX;
		    if((i+3)<=endX&&spiralnum>0){
			while((i+3)<=endX&&mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}	
		    }
		    else if((i+2)<=endX&&spiralnum==0){
			while((i+2)<=endX&&mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (++beginY > endY) break;


		// From top down
		if(mnum>=(endY-beginY+1)/*&&spiralnum>0*/){
		    for (int i = beginY; i <= endY; ++i){
			cells[i][endX]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=beginY;
		    if((i+3)<=endY&&mnum>0&&spiralnum>0){
			while((i+3)<=endY&&mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}	
		    }
		    else if((i+2)<=endY&&spiralnum==0){
			while((i+2)<=endY&&mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (--endX < beginX) break;

		// From right to left
		if(mnum>=(endX-beginX+1)){
		    for (int i = endX; i>= beginX; --i){
			cells[endY][i]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=endX;
		    if((i-3)>=beginX&&spiralnum>0){
			while((i-3)>=beginX&&mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}	
		    }
		    else if((i-2)>=beginX&&spiralnum==0){
			while((i-2)>=beginX&&mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (beginY > --endY) break;

		// From bottom up
		if(mnum>=(endY-beginY+1)){
		    for (int i = endY; i >= beginY; --i){
			cells[i][beginX]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=endY;
		    if((i-3)>=beginY&&spiralnum>0){
			while((i-3)>=beginY&&mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}	
		    }
		    else if((i-2)>=beginY&&spiralnum==0){
			while((i-2)>=beginY&&mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (++beginX > endX) break;

		spiralnum++;
	    }
	}
    
	//spiral order2
	void ConfigMine2() {
		reset();

	    int beginX = 0, endX = col-1;
	    int beginY = 0, endY = row-1;

	    int mnum = minesnum;
	    int spiralnum=0;

	    while(mnum>0){

		// From bottom up
		if(mnum>=(endY-beginY+1)){
		    for (int i = endY; i >= beginY; --i){
			cells[i][beginX]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=endY;
		    if((i-3)>=beginY&&spiralnum>0){
			while((i-3)>=beginY&&mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}	
		    }
		    else if((i-2)>=beginY&&spiralnum==0){
			while((i-2)>=beginY&&mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[i][beginX]='*';
			    --i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (++beginX > endX) break;

		// From left to right
		if(mnum>=(endX-beginX+1)){
		    for (int i = beginX; i <= endX; ++i){
			cells[beginY][i]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=beginX;
		    if((i+3)<=endX&&spiralnum>0){
			while((i+3)<=endX&&mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}	
		    }
		    else if((i+2)<=endX&&spiralnum==0){
			while((i+2)<=endX&&mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][endX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[beginY][i]='*';
			    ++i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (++beginY > endY) break;


		// From top down
		if(mnum>=(endY-beginY+1)/*&&spiralnum>0*/){
		    for (int i = beginY; i <= endY; ++i){
			cells[i][endX]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=beginY;
		    if((i+3)<=endY&&mnum>0&&spiralnum>0){
			while((i+3)<=endY&&mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}	
		    }
		    else if((i+2)<=endY&&spiralnum==0){
			while((i+2)<=endY&&mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
			if(mnum){
			    cells[endY][beginX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[i][endX]='*';
			    ++i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (--endX < beginX) break;

		// From right to left
		if(mnum>=(endX-beginX+1)){
		    for (int i = endX; i>= beginX; --i){
			cells[endY][i]='*';
			mnum-=1;
		    }
		}
		else{
		    int i=endX;
		    if((i-3)>=beginX&&spiralnum>0){
			while((i-3)>=beginX&&mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}
			if(mnum){
			    cells[beginY][endX]='*';
			    mnum--;
			}	
		    }
		    else if((i-2)>=beginX&&spiralnum==0){
			while((i-2)>=beginX&&mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
			if(mnum){
			    cells[beginY][beginX]='*';
			    mnum--;
			}
		    }
		    else{
			while(mnum>0){
			    cells[endY][i]='*';
			    --i;
			    mnum-=1;
			}
		    }
		    break;
		}
		if (beginY > --endY) break;

		spiralnum++;
	    }
	}

	//diag
	void ConfigMine3() {
	    reset();
	    int num = 0;
		
	    for(int i=0; i<=row+col-2; i++) {
		for(int j=i; j>=0; j--) {
		    if(j>=0 && j<row && i-j < col && i-j >=0) {
			if(num < minesnum) {
			    cells[j][i-j] = '*';
			    num++;
			}
		    }
		}
	    }
	}

	//row by row
	void ConfigMine4() {
	    reset();
		int mnum=minesnum;
		int flag=0;

	    for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
		    if(mnum) {
			cells[i][j] = '*';
			mnum--;
		    }
			else flag=1;
			if(flag)break;
		}
		if(flag)break;
	    }
	}

	//col by col
	void ConfigMine5() {
		reset();
		int mnum=minesnum;
		int flag=0;
	  
	    for(int i=0; i<col; i++) {
		for(int j=0; j<row; j++) {
		    if(mnum) {
			cells[j][i] = '*';
			mnum--;
		    }
			else flag=1;
			if(flag)break;
		}
		if(flag)break;
	    }
	}

	void ConfigMine6() {
	      for(int i=0; i<col; i++) {
		    for(int j=0; j<row; j++) {
			cells[j][i] = '*';
		    }
		  }
		  for(int i=0; i<2; i++) {
		    for(int j=0; j<2; j++) {
			  cells[j][i] = '.';
		    }
		  }
	}

	void computeval(int x,int y){
	    if((x-1)>=0&&cells[x-1][y]=='*') values[x][y]+=1;
	    if((x+1)<row&&cells[x+1][y]=='*') values[x][y]+=1;
	    if((y-1)>=0&&cells[x][y-1]=='*') values[x][y]+=1;
	    if((y+1)<col&&cells[x][y+1]=='*') values[x][y]+=1;
	    if((x-1)>=0&&(y-1)>=0&&cells[x-1][y-1]=='*') values[x][y]+=1;
	    if((x+1)<row&&(y-1)>=0&&cells[x+1][y-1]=='*') values[x][y]+=1;
	    if((x-1)>=0&&(y+1)<col&&cells[x-1][y+1]=='*') values[x][y]+=1;
	    if((x+1)<row&&(y+1)<col&&cells[x+1][y+1]=='*') values[x][y]+=1;
	}

	void setvalues(){
	    for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
		    if (cells[i][j]=='*'){
			values[i][j]=-1;
		    }
		    else if (cells[i][j]=='.'){
			computeval(i,j);
		    }
		}
	    }
	}

	bool check_all_visited() {
	    for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
		    if(values[i][j]!=-1)
			return false;
		}
	    }
	    return true;
	}

	void traverse_and_mark(int i, int j) {
	    if(values[i][j]==-1) return;
	    if(values[i][j]!=0) {values[i][j] = -1; return;}

	    values[i][j] = -1;
	    if((i-1)>=0) traverse_and_mark(i-1, j);
	    if((i+1)<row) traverse_and_mark(i+1, j);
	    if((j-1)>=0) traverse_and_mark(i, j-1);
	    if((j+1)<col) traverse_and_mark(i, j+1);
	    if((i-1)>=0&&(j-1)>=0) traverse_and_mark(i-1, j-1);
	    if((i+1)<row&&(j-1)>=0) traverse_and_mark(i+1, j-1);
	    if((i-1)>=0&&(j+1)<col) traverse_and_mark(i-1, j+1);
	    if((i+1)<row&&(j+1)<col) traverse_and_mark(i+1, j+1);
	    return;

	}

	bool checkpossible(){
	    for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
		    if(values[i][j]==0){
			traverse_and_mark(i, j);
			if(check_all_visited()) {
			    values[i][j] = 0;
			    return true;
			} else {
			    values[i][j] = 0;
			    return false;
			}
		    }
		}
	    }
	    return false;
	}

	void findc(){
	    int flag=0;
	    for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
		    if (cells[i][j]=='.'){
			if(values[i][j]==0){
			    cells[i][j]='c';
			    flag=1;
			    break;
			}
		    }
		}
		if(flag==1)break;
	    }
	}
	
	void findc2(){
		int flag=0;
	    for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
		    if (cells[i][j]=='.'){
			    cells[i][j]='c';
			    flag=1;
			    break;
		    }
		}
		if(flag==1)break;
	    }
	}

	string toPrint() {
	    stringstream s;
	    for(int i=0; i<row;i++) {
		for(int j=0; j<col; j++) {
		    s << cells[i][j];
		}
		s << endl;
	    }
	    string str= s.str();
	}
};

int main(int argc, const char* argv[]){
	ifstream infile;
	infile.open("C-small-attempt2.in");
    ofstream outfile;
	outfile.open("C-small222.out");
	
    int T;
    infile >> T;
  for(int i=0; i<T; i++) {
    int r, c, m;
	infile >> r >> c >> m;
	Board a(r,c,m);
	Board *b = &a;
	
	outfile <<"Case #" <<i+1<<":"<<endl;

	if(m>=0&&(m+1)==(r*c)){
	    b->ConfigMine1();
		b->findc2();  //
		outfile<< b->toPrint();
	}
	else if((r*c-m)==4&&m>=0){
		b->ConfigMine6();
        b->setvalues();
	    if(b->checkpossible()){
	      b->findc();
	      outfile << b->toPrint();
	    }else{
			outfile<<"Impossible"<<endl;
		}
	}
	else{
	  b->ConfigMine1();
      b->setvalues();
	  if(b->checkpossible()){
	    b->findc();
	    outfile << b->toPrint() ;
	  }else{
		b->ConfigMine2();
		b->setvalues();
        if(b->checkpossible()){
	        b->findc();
	        outfile << b->toPrint() ;
	    }else{
		    b->ConfigMine3();
		    b->setvalues();
            if(b->checkpossible()){
	            b->findc();
	            outfile << b->toPrint() ;
	        }else{
		        b->ConfigMine4();
		        b->setvalues();
                if(b->checkpossible()){
	               b->findc();
	               outfile << b->toPrint() ;
	            }else{
		            b->ConfigMine5();
		            b->setvalues();
                    if(b->checkpossible()){
	                    b->findc();
	                    outfile << b->toPrint() ;
	                 }else{
                        outfile << "Impossible" <<endl;
					}
				}
			}
		}
	  }
	}
	}
	
  /*
  while(true){
	
	int r, c, m;
	cin>> r >> c >> m;
	Board a(r,c,m);
	Board *b = &a;

	cout<<b->toPrint();
	cout<<"Solution:"<<endl;
	

	cout<<fixed;
	//cout<<"Case #" <<i+1<<":"<<endl;
	if(m>=0&&(m+1)==(r*c)){
	    b->ConfigMine1();
		b->findc2();  //
		cout<< b->toPrint();
	}
	else if((r*c-m)==4&&m>=0){
		b->ConfigMine6();
        b->setvalues();
	    if(b->checkpossible()){
	      b->findc();
	      cout << b->toPrint();
	    }else{
			cout<<"Impossible"<<endl;
		}
	}
	else{
	  b->ConfigMine1();
      b->setvalues();
	  if(b->checkpossible()){
	    b->findc();
	    cout << b->toPrint() ;
	  }else{
		b->ConfigMine2();
		b->setvalues();
        if(b->checkpossible()){
	        b->findc();
	        cout << b->toPrint() ;
	    }else{
		    b->ConfigMine3();
		    b->setvalues();
            if(b->checkpossible()){
	            b->findc();
	            cout << b->toPrint() ;
	        }else{
		        b->ConfigMine4();
		        b->setvalues();
                if(b->checkpossible()){
	               b->findc();
	               cout << b->toPrint() ;
	            }else{
		            b->ConfigMine5();
		            b->setvalues();
                    if(b->checkpossible()){
	                    b->findc();
	                    cout << b->toPrint() ;
	                 }else{
                        cout << "Impossible" <<endl;
					}
				}
			}
		}
	  }
	}
  }
  */
	return 0;	
}