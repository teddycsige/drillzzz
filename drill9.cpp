#include "std_lib_facilities.h"
struct Date
{
	int y, m, d;
};
void date_today(Date& date, int y, int m, int d)
{
	if(y>0)
	{
		date.y=y;
	}
	else
	{
		error("invalid year");
	}
	
	if(m<=12 && m>0)
	{
		date.m=m;
	}
	else
	{
		error("invalid month");
	}
	
	if(d<= 31 && d>0)
	{
		date.d=d;
	}
	else
	{
		error("invalid day");
	}
}
void add_day(Date& date, int t)
{
	 date.d += t;
	 
	 if(date.d>31)
	 {
	 	date.m++;
	 	date.d -= 31;
	 	if(date.m >12)
	 	{
	 		date.y++;
	 		date.m -=12;
	 	}
	 }
}
int main()
{
try
{
	//Date today;
	//today.y = 1978;
	//today.m = 6;
	//today.d = 25;
	//cout << "Date: " << today.y << '.' << today.m << '.' << today.d << '.' << endl;
	Date x;
	date_today(x,1978, 6, 25);
	cout << "Today's date: " << x.y << '.' << x.m << '.' << x.d << '.' << endl;
	
	add_day(x, 1);
	cout << "Tomorrow's date: " << x.y << '.' << x.m << '.' << x.d << '.' << endl;
	
return 0;
}
catch(exception& e)
{
	cout << e.what() << endl;
	return 1;
}
}
