#include <iostream>
#include <string>

using namespace std;

int kmp(char *s,char *t,int pos){
	//求 模式串T 在主串S 中第pos后第一次匹配成功的位置
	//KMP   1<=pos<=strlen(S)
	
	int i=0,j=-1,sl=strlen(s),tl=strlen(t),*nextval=new int[tl];
	nextval[0]=-1;
	while(i<tl){
		if(-1==j||t[i]==t[j]){
			i++;
			j++;
			if(t[i]!=t[j])
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}//求模式串 T 的nextval函数
	
	for(i=0;i<tl;i++)
		cout<<nextval[i]<<" ";
	cout<<endl;
	i=pos;
	j=0;
	while(i<sl&&j<tl){
		if(-1==j||s[i]==t[j]){
			i++;
			j++;
		}
		else
			j=nextval[j];
	}
	if(j>tl-1)
		return i-tl;
	else
		return 0;
}

int main(){
	//demo
	char *s,*t;
	s=new char[30];
	t=new char[10];
	cout<<"Puts S"<<endl;
	cin>>s;
	cout<<"Puts T"<<endl;
	cin>>t;
	cout<<kmp(s,t,0)<<endl;

	return 0;
}
