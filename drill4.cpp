#include "std_lib_facilities.h"
#include <limits.h>
double change(int a, string b)
{
double r;					//átváltások
	if(b=="cm")
	{
		r=a*0.01;
	}
	else
	{
		if(b=="ft")
		{
			r=a*0.3048;
		}
		else
		{
			if(b=="in")
			{
				r=a*0.0254;
			}
			else
			{
				r=a;
			}
		}
		return r;
	}

}

int main(){
double a, b;
int min=INT_MAX;
int max=0;
	cout<<"Please enter a number: " << endl;
while((cin>> a)&&(a!='|'))					//ha | akkor kilép
{
	cout << a << endl;
	if(a>max)
	{
		max=a;						//max felveszi a értékét
		cout<<"The laergest so far" << endl;
	}
	else if(a<min)
	{
		min=a;						//min felveszi a értékét
		cout<<"The smallest so far" << endl;
	}
	if(a>b)
	{
		cout<<"The smaller value is: " << b << endl;   
		cout <<"The larger value is: " << a << endl;
	}
	else if(a<b)
	{
		cout<< "The smaller value is: " << a << endl;
		cout<< "The larger value is: " << b << endl;
	}
	if(a-b<=1.0/100)
	{
		cout<< "The numbers are almost equal" << endl;
	}
}
cout<<"Please enter a number an unit (cm, m, ft, in)"<<endl;
double e;
string me;
double sum=0;
double min=INT_MAX;
double max=0;
int db=0;
vector<double>ertek;

while(cin>> e >> me )
{
	if((me=="cm" || me=="m" || me=="ft" || me=="in") && e>=0)			//ha nem a megfelelő m.é akkor kidobja, különben műveleteket végez
	{
		cout<< e <<me << endl;
		double e1= change(e, me);						//m.é. váltás
		cout<< e1 << "m"<< endl;
		db++;
		ertek.push_back(e1);							//vektorba teszi az értéket
		sum=sum+e1;
		if(e1>max)
		{
			max=e1;							//a max felveszi az e1 értékét
		}
		if(e1<min)
		{
			min=e1;							//a min felveszi az e1 értékét
		}
	}	
	else
	{
	
		cout<< "illegal" << endl;						
	}
}
	if(db==0)									//ha a darabszám 0 akkor nem fut le
	{
		cout<<"Wrong"<<endl;
	}

	else
	{
	cout<<"Number of values: " << db << endl;
	cout<<"Sum of the values: " << sum << endl;
	cout<<"Max: " << max << endl;
	cout<<"Min: " << min << endl;
		sort(ertek);								//rendezés
		for(int i=0; i<ertek.size();i++)
		{
			cout<<ertek[i]<<endl;
		}
	}

return 0;
}
