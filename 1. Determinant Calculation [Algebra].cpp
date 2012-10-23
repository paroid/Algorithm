#include<iostream.h>
//using namespace std;

long int mg(long int a,long int b){	//求最大公约数
	long int t;
	if(b>a){
		t=a;
		a=b;
		b=t;
	}
	while(b){
		t=a;
		a=b;
		b=t%b;
	}
	return a;
}

class ff{		//分数类
public:
	ff(long int xx=0,long int yy=1){
		x=xx/mg(xx,yy);
		y=yy/mg(xx,yy);
	}
	friend ff operator+(const ff &a,const ff &b);
	friend ff operator-(const ff &a,const ff &b);
	friend ff operator*(const ff &a,const ff &b);
	friend ff operator/(const ff &a,const ff &b);
	double to_double(){
		return (double)x/y;
	}
	friend ostream& operator<<(ostream& out,const ff& a);
	friend istream& operator>>(istream& in,ff& a);
	void show(){
		cout<<x<<"/"<<y<<endl;
	}
private:
	long int x,y;
};

ff operator+(const ff &a,const ff &b){
	return ff(a.x*b.y+b.x*a.y,a.y*b.y);
}
ff operator-(const ff &a,const ff &b){
	return ff(a.x*b.y-b.x*a.y,a.y*b.y);
}
ff operator*(const ff &a,const ff &b){
	return ff(a.x*b.x,a.y*b.y);
}
ff operator/(const ff &a,const ff &b){
	return ff(a.x*b.y,a.y*b.x);
}

ostream& operator<<(ostream& out,const ff& a){
	if(a.y<0)
		out<<"-";
	out<<a.x;
	if(a.y!=1&&a.y!=-1){
		out<<"/";
		if(a.y<0)
			out<<-a.y;
		else
			out<<a.y;
	}
	return out;
}

istream& operator>>(istream& in,ff& a){
	char c;
	in>>a.x;
	cin.get(c);
	if(c=='/')
	in>>a.y;
	return in;
}

template<class type>
void Perm(type list[],int k,int m,ff& key,ff **a){   
    if(k==m){//输出在这里啦。。。哈哈哈
		ff c(1,1);
		int count=0;
		for(int i=0;i<=m;i++)
			for(int j=i+1;j<=m;j++){
				if(list[i]>list[j])
					count++;
			}
        for(i=0;i<=m;i++){
                c=c*a[i][list[i]];
        }
		if(count%2){
			key=key-c;
		}
		else{
			key=key+c;
		}
        
    }
    else{
        for(int i=k;i<=m;i++){
                Swap(list[k],list[i]);
                Perm(list,k+1,m,key,a);
                Swap(list[k],list[i]);
        }
    }
}

template<class type>
inline void Swap(type& a,type& b){
    type temp=a;
    a=b;
    b=temp;
}

int main(){
	int i,j,n;
	ff key;
	char ch;
	cout<<"************************************"<<endl;
	cout<<"*      Calculate 行列式---By CG    *"<<endl;
	cout<<"************************************"<<endl;
	while(ch!='n'&&ch!='N'){
		do{
			cout<<"matrix A is  n  x  n ?(size)"<<endl;
			cin>>n;
		
			if(n<1){
				cout<<"*******************************"<<endl;
				cout<<"*   Data Error!  Input Again  *"<<endl;
				cout<<"*******************************"<<endl;
			}
		}while(n<1);
		
		ff **a;

		a=new ff*[n];
		for(i=0;i<n;i++)
			a[i]=new ff[n];
		
		cout<<"**************************************************"<<endl;
		cout<<"* Input data if it's a integer input immediatly  *"<<endl;
		cout<<"*   if it's not a integer input like this  'x/y' *"<<endl;   
		cout<<"**************************************************"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<"Input A("<<i+1<<","<<j+1<<")"<<endl;
				cin>>a[i][j];
			}
		}
				
		cout<<"A:"<<endl;
		cout<<"***********************************"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}
		int *p=new int[n];
		for(i=0;i<n;i++)
			p[i]=i;
		key=ff(0,1);
		Perm(p,0,n-1,key,a);


		cout<<"=========================================="<<endl;
		cout<<"\n"<<endl;
		cout<<"The Answer:   "<<key<<endl;
		cout<<"The  Answer To Double:   "<<key.to_double()<<endl;
		do{
			cout<<"*********************"<<endl;
			cout<<"* Continue?  <y/n>  *"<<endl;
			cout<<"*********************"<<endl;
			ch=cin.get();
		}while(ch!='y'&&ch!='n'&&ch!='Y'&&ch!='N');
	}
	return 0;
}