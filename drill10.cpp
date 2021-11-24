#include "std_lib_facilities.h"

struct Point
{
public:
	int x;
	int y;
	int a;
	int b;
};

int main()
{
try{
	cout << "Please enter 7 x and y:" << endl;
	vector <Point> original_points;
	
	int x;
	int y;
	
	for(int i=0; i<7; i++)
	{
		cin >> x >> y;
		original_points.push_back(Point{x,y});
		//cout << "X is: " << x << " " << "Y is: " << y << endl;
	}
	
	for(const auto& Point:original_points)
	{
		cout << Point.x << ',' << Point.y << endl;
	}
	
	ofstream ofile{"mydata.txt"};
		for(const auto& Point:original_points)
		{
			ofile << Point.x << ',' << Point.y << endl;
		}
	ofile.close();
	
	vector <Point> processed_points;
	ifstream ifile{"mydata.txt"};
		int a;
		int b;
		while(ifile >> a >> b)
		{
		processed_points.push_back(Point{x,y});
		}
	ifile.close();
	
	for(const auto& Point:processed_points)
	{
		cout << Point.a << ',' << Point.b << endl;
	}
		
	
	if(original_points.size() == processed_points.size())
	{
		for(int i=0; i<7;i++)
		{
			if(original_points[i].x == processed_points[i].x || original_points[i].y == processed_points[i].y)
			{
					cout << "Jól csináltad báttya" << endl;
			}
			else
			{
				cout << "Something's wrong!" << endl;
			}
		}
	}
	else
	{
		cout << "Vector size different" << endl;
	}
	
return 0;
}
catch(runtime_error& e)
{
	cerr << "Error: " << e.what() << endl;
	return 1;
}
}
