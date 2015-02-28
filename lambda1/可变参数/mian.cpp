#include <iostream>

#include <cstdarg>

using namespace  std;

void showint(int n ,...)
{
	va_list va_ptr;
	va_start(va_ptr,n);

	for (int i = 0 ; i < n ; ++ i)
	{
		cout << va_arg(va_ptr,int)<<endl;
	}

	va_end(va_ptr);
}

int main()
{

	showint(5,1,2,3,4,5);

	showint(4,1,5,3,4);

	cin.get();
	return 0;
}