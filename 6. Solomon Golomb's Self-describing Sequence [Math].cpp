#include <iostream>
using namespace std;
/*Solomon Golomb's Self-describing Sequence
g(n): largest integer m such that f(m)=n
<Concrete Mathematics> P66,36*/

int gSeq[1000000]/*g(n)*/,n=3,M=1000000000;

int fn(int n){ //search for f(n)
	int i=0;
	while(gSeq[++i]<n);
	return i;
}

int main(int argc, const char *argv[]){
	gSeq[1]=1;
	gSeq[2]=3;
	while(gSeq[n-1]<M){
		gSeq[n]=gSeq[n-1]+fn(n);
		++n;
	}
	// now search for answers
	cout<<fn(M)<<endl;
	cout<<fn(9999)<<endl;
	cout<<fn(123456)<<endl;
	cout<<fn(100)<<endl;
	return 0;
}
