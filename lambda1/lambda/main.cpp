#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//lambda基础
void lambda_one();
//sort中lambda实例
void lambda_two();
//lambda函数递归
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
	cout<<endl <<"------------没有函数参数的lambda---------------------"<<endl;
	auto fun = [](){};
	auto fun1 = [](){cout <<"fun1"<<endl;};
	fun1();

	cout<<endl <<"------------for_each中使用简单的lambda----------------"<<endl;	
	std::vector<int>  v(3,5);
	for_each(v.begin(),v.end(),[](int num){ cout << num << "\t";});

	cout<<endl <<"------------设置lambda的返回值类型--------------------"<<endl;	
	cout <<[](double a, double b){return a + b;}(1.4,2.5)<<endl;	
	cout <<[](double a, double b)->int{return a + b;}(1.4,2.5)<<endl;

	cout<<endl <<"------------lambda中的传值----------------------------"<<endl;
	int x = 10;
	int y = 100;
	[=](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;

	cout<<endl <<"------------lambda中的传引用--------------------------"<<endl;
	[&x,&y](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;

	cout<<endl <<"------------lambda中的传引用和引用传递------------------"<<endl;
	//等号必须写在前面，或者也可以[x,&y].
	//=表示，除了&y，其他所有的外部变量都可以按照值传递进行访问。
	[=,&y](double a, double b)mutable->int
	{
		cout <<"lambda:"<<(x = 100) << "\t" <<(y = 10)<<endl;
		return a + b;
	}(1.4,2.5);
	cout<<"main:" << x <<"\t"<< y <<endl;
}

void lambda_two()
{
	//1.sort排序
	cout <<endl<<"------------sort排序中使用lambda------------------------"<<endl;
	int  a[8] = {6,8,3,4,9,2,7,1};
	sort(begin(a),end(a),[](const int &a ,const int &b)->bool{return a < b;});
	for_each(begin(a),end(a),[](const int &num){cout << num << "\t";});

	cout <<endl<<"---------------------------------------------------------"<<endl;

}

void lambda_three()
{
	//2. (lambda递归)3个数返回最大的两个数的和
	cout <<endl<<"------------lambda递归-----------------------------------"<<endl;
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