#include "std_lib_facilities.h"

vector<int>gv={1,2,4,8,16,32,64,128,256,512};

void f(vector<int> a)
{
	vector<int>lv(a.size());
	for(int i=0; i<gv.size(); i++)
	{
		lv[i]=gv[i];
	}
	for(int i=0; i<lv.size();i++)
	{
		cout << lv[i] << endl;
	}
	
	vector<int> lv2(a.size());
	for(int i=0; i<lv2.size(); i++)
	{
		lv2[i]=a[i];
	}
	for(int i=0; i < lv2.size(); i++)
	{
		cout << lv2[i] << endl;
	}
}

int main()
{

	f(gv);
	vector<int>vv;
	for(int i=1; i < 11; i++)
	{
		int val=i;
		for(int j=i-1; j>0; j--)
		{
			val *= j;
		}
		vv.push_back(val);
	}
	f(vv);

return 0;
}
