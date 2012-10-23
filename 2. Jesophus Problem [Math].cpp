#include <iostream>
#include <math.h>
using namespace std;
/*
 *Jesophus problem
 *<Concrete Mathematics> P80
*/

int jesophus(int n){ //this is just for the 3rd person
	int N=3*n;
	while(N>n)
		cout<<(N=((N-n-1)>>1)+N-n)<<" ";
	cout<<endl;
	return N;
}

int jesophusN(int n,int q){//Jesus!!!
	int D=1;
	while(D<=(q-1)*n)
		D=ceil(q/(double)(q-1)*(double)D);
	return q*n+1-D;
}

int main(int argc, const char *argv[]){
	cout<<jesophusN(7,4)<<endl;
	return 0;
}
