 #include "std_lib_facilities.h"
 
int main(){
/*int res = 7;
vector<int> v(10);
v[5] = res;*/
/*vector<int> v(10);
v[5] = 7;*/
//bool c=false;
//string s = "ape"; 
//bool c = "fool"<s;
//string s = "ape";
//string s= "ape";
//string s= "ape";
//vector<char> v(5);
//vector<char> v(5);
//string s = "Success!\n";
//int x = 2000;
//int c = x;
//string s = "Success!\n";
//vector<int> v(5);
//int i=0;
//int j = 9;
//int x = 2;
//double d = 5/2;
//string s = "Success!\n";
//int i=0;
//int j=8;
//int x = 4;
//double d = 5/x;
try
{
        // cout << "Success!\n";			//1: Cout , cout
        //cout << "Success!\n";			//2: missing " after \n
        //  cout << "Success" << "!\n";		//3: missing " before !, ; expected
        //cout << "success "<< '\n';			//4: "success"
        //  cout << "Success!\n";   			//5: string --> int
        /* if(v[5]==7)					//6: [] 
         {
         	cout << "Success!\n";
         }*/
        /* if (true)					//7: cond --> true
         {
         /	cout << "Success!\n"; 
         }
    
         else 
         {
         	cout << "Fail!\n";
         }*/
        /* if (!c) 					//8: ! missing --> if(c)... --> fail
         {
         	cout << "Success!\n";
         }
         else 
         {
         	cout << "Fail!\n";
         }*/
        /* if (!c)					//9: boo --> bool, !c
         {
         	cout << "Success!\n";
         }*/
         /*if (s!="fool") 				//10: insteod of ==, !=
         {
         	cout << "Success!\n";
         }*/
         /*if (s!="fool") 				//11: < missing, !=
         {
         	cout << "Success!\n";
         }*/
         /*if (s!="fool") 				//12: instead of +, !=, missing <
         {
         	cout << "Success!\n";
         }*/
         /*for (int i=0; i<v.size(); ++i);		//13: instead of 0, i
         	cout << "Success!\n";*/
         /*for (int i=0; i<=v.size(); ++i);		//14:
         	cout << "Success!\n";*/
          /*for (int i=0; i<s.size(); ++i) 		//15: instead of 6, s.size()
          cout << s[i];*/	
         /*if (true)					//16: no then
         {
         	cout << "Success!\n";
         }
         else
         {
         	cout << "Fail!\n";
         }*/
         /*if (c==2000) 				//17: instead of char, int c=x
         {
         	cout << "Success!\n";
         }*/
         /*for (int i=0; i<s.size(); ++i)		//18: instead of 10, s,size()
         {
         	cout << s[i];
         }*/
         /*for (int i=0; i<=v.size(); ++i) ; 		//19: <int> missing
         cout << "Success!\n";*/
         /*while (i<10) i++; 				//20: instead of j++, i++
         if (j<i) 
         {
         	cout << "Success!\n";
         }*/
         /*if (d!=2*x+0.5)				//21: 5/(2-2) --> 5/0 --> d=5/2 || d=5, d!=2*x+0,5
         {
         	cout << "Success!\n";
         }*/
         /*for (int i=0; i<=s.size(); ++i) 		//22: instead of 10, s.size(), no need <char>
         {
         	cout << s[i];
         }*/
         /*while (i<10) ++i; 				//23: j++, i++, int j=8
         if (j<i) 
         {
         	cout << "Success!\n";
         }*/
         /*if (d!=2*x+0.5) 				//24: != , 5/x
         {
         	cout << "Success!\n";
         }*/
         cout << "Success!\n";			//25: cout instead of cin
       
          keep_window_open();
          return 0;
}
catch (exception& e)
{
          cerr << "error: " << e.what() << '\n';
          keep_window_open();
          return 1;
}
catch (...)
{
          cerr << "Oops: unknown exception!\n";
          keep_window_open();
          return 2;
}
}
