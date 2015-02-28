#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//lambda����
void lambda_one();
//sort��lambdaʵ��
void lambda_two();
//lambda�����ݹ�
void lambda_three();

int main()
{
	lambda_one();
	lambda_two();
	lambda_three();
	getchar();
	return 0;
}


void lambda_one()
{
	cout<<endl <<"------------û�к���������lambda---------------------"<<endl;
	auto fun = [](){};
	auto fun1 = [](){cout <<"fun1"<<endl;};
	fun1();

	cout<<endl <<"------------for_each��ʹ�ü򵥵�lambda----------------"<<endl;	
	std::vector<int>  v(3,5);
	for_each(v.begin(),v.end(),[](int num){ cout << num << "\t";});

	cout<<endl <<"------------����lambda�ķ���ֵ����--------------------"<<endl;	
	cout <<[](double a, double b){return a + b;}(1.4,2.5)<<endl;	
	cout <<[](double a, double b)->int{return a + b;}(1.4,2.5)<<endl;

	cout<<endl <<"------------lambda�еĴ�ֵ----------------------------"<<endl;
	int x = 10;
	int y = 100;
	[=](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;

	cout<<endl <<"------------lambda�еĴ�����--------------------------"<<endl;
	[&x,&y](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;

	cout<<endl <<"------------lambda�еĴ����ú����ô���------------------"<<endl;
	//�Ⱥű���д��ǰ�棬����Ҳ����[x,&y].
	//=��ʾ������&y���������е��ⲿ���������԰���ֵ���ݽ��з��ʡ�
	[=,&y](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;
}

void lambda_two()
{
	//1.sort����
	cout <<endl<<"------------sort������ʹ��lambda------------------------"<<endl;
	int  a[8] = {6,8,3,4,9,2,7,1};
	sort(begin(a),end(a),[](const int &a ,const int &b)->bool{return a < b;});
	for_each(begin(a),end(a),[](const int &num){cout << num << "\t";});

	cout <<endl<<"---------------------------------------------------------"<<endl;

}

void lambda_three()
{
	//2. (lambda�ݹ�)3�������������������ĺ�
	cout <<endl<<"------------lambda�ݹ�-----------------------------------"<<endl;
	function<int(int,int,int)> f = [&f](int a,int b,int c)->int
	{
		if (a<= b && a <= c)
		{
			return b + c;
		}
		return f(b,c,a);
	};

	cout << f(4,5,6)<<endl;
}