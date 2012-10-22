#include<iostream.h>

class ff{		//������
	long int mg(long int a,long int b){	//�����Լ��
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
void sh(ff **a,int n){
	for(int i=0;i<2*n;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}
	
}

int main(){
	int i,j,k,n,l;
	ff key;
	char ch;
	cout<<"************************************"<<endl;
	cout<<"*       �����ͻ���׼�� ---By CG    *"<<endl;
	//cout<<"*       �����  ����ʽ  �����     *"<<endl;
	cout<<"************************************"<<endl;
	while(ch!='n'&&ch!='N'){
		do{
			cout<<"��������� Ԫ�� ?"<<endl;
			cin>>n;
		
			if(n<2){
				cout<<"*******************************"<<endl;
				cout<<"*   �������! ����������...   *"<<endl;
				cout<<"*******************************"<<endl;
			}
		}while(n<2);
		
		ff **a;

		a=new ff*[2*n];
		for(i=0;i<2*n;i++)
			a[i]=new ff[n];
		
		cout<<"**************************************************"<<endl;
		cout<<"*         �������ݣ� ���Ϊ������ֱ������        *"<<endl;
		cout<<"*         ������������÷�����ʽ����  'x/y'      *"<<endl;   
		cout<<"**************************************************"<<endl;
		for(i=0;i<n;i++){		//��������
			cout<<"����X"<<i+1<<"^2  ϵ��"<<endl;
			cin>>a[i][i];
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
					cout<<"����X"<<i+1<<"*X"<<j+1<<" ϵ��"<<endl;
					cin>>a[i][j];
					a[j][i]=a[i][j]/ff(2,1);
					a[i][j]=a[j][i];
			}
			a[i+n][i]=ff(1,1);		//��ʼ����λ��
		}		

				
		cout<<"     *�����;���:"<<endl;
		cout<<"***********************************"<<endl;

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}

		cout<<endl;
		j=0;
		while(j<n){
			for(j=0;j<n;j++){   //���л���
				k=j;
				while(k<n&&!a[k][j].to_double()){ //���Ҹ��з���Ԫ��
					k++;
				}	
				if(k==n)
					continue;
				if(k!=j){			//�����¶Խǵ�һ��  ��Ϊ����
					for(i=0;i<n;i++)
						a[j][i]=a[j][i]+a[k][i];
					for(i=0;i<2*n;i++)
						a[i][j]=a[i][j]+a[i][k];
				}
				for(i=0;i<n;i++){		//����
					l=j;
					if(!(a[i][l].to_double())||i==j)
							continue;
					ff tip=a[i][j]/a[j][j];
					for(l=0;l<n;l++){
						a[i][l]=a[i][l]-tip*a[j][l];
					}
					for(l=0;l<2*n;l++){
						a[l][i]=a[l][i]-tip*a[l][j];
					}
				}

			}
			
		}

		cout<<endl;cout<<endl;
		cout<<"   �����ͱ�׼��:"<<endl;
		cout<<"=========================================="<<endl;
		k=0;
		for(i=0;i<2*n;i++){
			for(j=0;j<n;j++){
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
			if(i==n-1){
				cout<<"\n*****************************************"<<endl;
				cout<<"   ����任����:"<<endl;
			}
			if(a[i][i].to_double()&&i<n)
				k++;
		}
		cout<<"\n\n   *��Ϊ��"<<k<<endl;
		cout<<"=========================================="<<endl;
		cout<<"   ������ F = ";
		int flag=0;
		for(i=0;i<n;i++){
			
			if(a[i][i].to_double()){
				if(a[i][i].to_double()>0&&flag)
					cout<<" +";
				if(a[i][i].to_double()!=1&&a[i][i].to_double()!=-1)
					cout<<" "<<a[i][i];
				else if(a[i][i].to_double()==-1)
					cout<<" -";
				cout<<" Y"<<i+1<<"^2";
				flag++;
			}
		}
		cout<<"\n   ���Ա任Ϊ��\n"<<endl;
		for(i=0;i<n;i++){
			int flag=0;		
			cout<<" | X"<<i+1<<" = ";
			for(j=0;j<n;j++){
				if(a[i+n][j].to_double()){
					if(a[i+n][j].to_double()>0&&flag)
						cout<<" +";
					if(a[i+n][j].to_double()!=1&&a[i+n][j].to_double()!=-1)
						cout<<a[i+n][j];
					else if(a[i+n][j].to_double()==-1)
						cout<<"-";
					cout<<" Y"<<j+1<<" ";
					flag++;
				}
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		int f=0;
		do{
			if(!f){
				cout<<"*********************"<<endl;
				cout<<"*     ����?  <y/n>  *"<<endl;
				cout<<"*********************"<<endl;
			}
			else{				
				cout<<"*******************************"<<endl;
				cout<<"*   ��TM���׼�����?  <y/n>  *"<<endl;
				cout<<"*******************************"<<endl;
			}
			cin>>ch;
			f++;
		}while(ch!='y'&&ch!='n'&&ch!='Y'&&ch!='N');
		
	}
	return 0;
}