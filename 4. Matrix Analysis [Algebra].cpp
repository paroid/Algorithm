#include<iostream.h>
class ff{		//分数类
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
int main(){
	int i,j,k,n,l;
	ff key;
	char ch;
	cout<<"************************************"<<endl;
	cout<<"*            矩阵分析  ---By CG    *"<<endl;
	cout<<"*       最简型  行列式  逆矩阵     *"<<endl;
	cout<<"************************************"<<endl;
	while(ch!='n'&&ch!='N'){
		do{
			cout<<"输入方阵维数"<<endl;
			cin>>n;
		
			if(n<1){
				cout<<"*******************************"<<endl;
				cout<<"*   输入错误!  请重新输入...  *"<<endl;
				cout<<"*******************************"<<endl;
			}
		}while(n<1);
		
		ff **a;

		a=new ff*[n];
		for(i=0;i<n;i++)
			a[i]=new ff[2*n];
		
		cout<<"**************************************************"<<endl;
		cout<<"*         输入数据， 如果为整数请直接输入        *"<<endl;
		cout<<"*         如果不是整数用分数格式输入  'x/y'      *"<<endl;   
		cout<<"**************************************************"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
					cout<<"输入("<<i+1<<","<<j+1<<")"<<endl;
					cin>>a[i][j];
			}
			a[i][i+n]=ff(1,1);
		}
				
		cout<<"A:"<<endl;
		cout<<"***********************************"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<endl;
		j=0;
		while(j<n-1){
			for(j=0;j<n;j++){   //以列化简
				k=j;
				while(k<n&&!a[k][j].to_double()){ //查找该列非零元素
					k++;
				}	
				if(k==n){			//若对角以下全为零  行列式为零
					continue;
				}
				if(k!=j){			//不是下对角第一个  进行交换到第一位置
					for(i=0;i<2*n;i++)
						a[j][i]=a[j][i]+a[k][i];
				}
				for(i=0;i<n;i++){		//化简
					l=j;
					if(!(a[i][l].to_double())||i==j)
							continue;
					ff tip=a[i][j]/a[j][j];
					for(l=j;l<2*n;l++){
						a[i][l]=a[i][l]-tip*a[j][l];
					}
				}
			}
		}

			key=ff(1,1);
			for(i=0;i<n;i++)
				key=key*a[i][i];


		cout<<endl;cout<<endl;
		cout<<"   行最简形:"<<endl;
		cout<<"=========================================="<<endl;
		k=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
			if(a[i][i].to_double())
				k++;
		}
		cout<<"\n\n   *秩为："<<k<<endl;
		cout<<"=========================================="<<endl;
		cout<<"\n"<<endl;
		cout<<"  *行列式值:   "<<key<<endl;
		cout<<"  *转为浮点约为:   "<<key.to_double()<<endl;
		if(key.to_double()){
			for(i=0;i<n;i++){
				if(a[i][i].to_double()!=1){
					ff temp=a[i][i];
					for(j=0;j<2*n;j++){
						a[i][j]=a[i][j]/temp;
					}
				}
			}
			cout<<"\n\n======================================="<<endl;
			cout<<"     逆矩阵："<<endl;
			for(i=0;i<n;i++){
				for(j=n;j<2*n;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		else{
			cout<<"\n\n    *无逆矩阵*"<<endl;
		}
		int flag=0;
		do{
			if(!flag){
				cout<<"*********************"<<endl;
				cout<<"*     继续?  <y/n>  *"<<endl;
				cout<<"*********************"<<endl;
			}
			else{				
				cout<<"*******************************"<<endl;
				cout<<"*   你TM到底继续伐?  <y/n>  *"<<endl;
				cout<<"*******************************"<<endl;
			}
			cin>>ch;
			flag++;
		}while(ch!='y'&&ch!='n'&&ch!='Y'&&ch!='N');
	}
	return 0;
}