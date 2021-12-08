#include "std_lib_facilities.h"
void print_array10(ostream& os, int*a)
{
	for(int i=0; i<10;i++)
	{
		os << a[i] << endl;
	}
}

void print_array(ostream& os, int* a, int n)
{
	for(int i=0; i<n; i++)
	{
		os << a[i] << endl;
	}
}

void print_vector(ostream& os, vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	{
		os << v[i] << endl;
	}
}
int main()
{
	int a = 7;
	int* p1= &a; 
	cout<< "p1: " << *p1 << " " << "*p1: " << *p1 << endl;

	int* p2 = new int[7];
	for(int i=0; i<7; i++)
		{
			p2[i]=pow(2,i);	
		}
	//cout << p2 << endl;
	print_array(cout, p2, 7);
	
	int* p3=p2;
	p2=p1;
	p2=p3;
	cout << "p1: " << p1 << ' ' << "*p1: " << *p1 << endl;
	cout << "p2: " << p2 << ' ' << "*p2: " << *p2 << endl;
	delete[] p1;
	delete[] p2;
	
	p1 = new int[10];
	for(int i=0; i < 10; i++)
	{
		p1[i]=pow(2,i);
	}
	
	p2 = new int[10];
	for(int i=0; i < 10; i++)
	{
		p2[i] = p1[i];
	}
	delete[] p1;
	delete[] p2;
	
	vector<int> v1;
	for(int i=0; i<10;i++)
	{
		v1.push_back(pow(2,i));
	}
	
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v2.push_back(v1[i]);
	}
	print_vector(cout, v1);
	print_vector(cout, v2);

return 0;
}
