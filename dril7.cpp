 /*
calculator08buggy.cpp
Helpful comments removed.
We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/
#include "std_lib_facilities.h"
//define a type to hold the name-value pair, so they can be used in the calculator
struct Token {
char kind;
double value;
string name;
Token(char ch) :kind(ch), value(0) { }
Token(char ch, double val) :kind(ch), value(val) { }
};
//define a type that handles the items from input
class Token_stream {
bool full;
Token buffer;
public:
Token_stream() :full(0), buffer(0) { }
Token get();
void unget(Token t) { buffer=t; full=true; }
void ignore(char);
};
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareR = "s";
const char findPow = "p";
const string sqrtkey = 'sqrt';
const string powkey = 'pow';
const string declKey = "#";
const string quitKey = "exit";
//evaluate the chars in the stream and decide on what they are
Token Token_stream::get()
{
if (full) { full=false; return buffer; } //checks if we have a token ready
char ch;
cin >> ch;
switch (ch) {
case '(':
case ')':
case '+':
case '-':
case '*':
case '/':
case '%':
case ';':
case '=':
case 'i':
return Token(ch);
case '.':
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
{	cin.unget(); //puts the digit back into the input stream
double val;
cin >> val; //read in a floating-point number
return Token(number,val); //returns the number
}
//Change the “declaration keyword” from let to #
case '#': return Token(let);
case 'exit': return Token(quit);
default: //if ch is a letter, do this
if (isalpha(ch)) {
string s;
s += ch;
while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s=ch; //while cin still has chars in it, read them into s
cin.unget();
//if the string is equal to any of the commands below, returns them
if (s == "let") return Token(let);
if (s == "quit") return Token(quit); //TOKEN SHOULD RETURN QUIT, NOT NAME
if (s == 'sqrtkey') return Token(squareR);
if (s == 'powkey') return Token(findPow);
return Token(name); //ERROR1
}
//if the char doesn't fin any of the above, returns an error message
error("Bad token");
}
return 0;
}
//discards characters and includes a c (c represents the kind of the token)
void Token_stream::ignore(char c)
{
//first checks buffer
if (full && c==buffer.kind) {
full = false;
return;
}
full = false;
//searches input
char ch;
while (cin>>ch)
if (ch==c) return;
}
//builds a structure named "Variable", so the name and valie can be handled together
struct Variable {
string name;
double value;
Variable(string n, double v) :name(n), value(v) { }
};
//creates a Variable type vector
vector<Variable> names;
//returns the value of the s variable
double get_value(string s)
{
for (int i = 0; i<names.size(); ++i)
if (names[i].name == s) return names[i].value;
error("get: undefined name ",s); //if can't find value for s, returns error
return 0;
}
//set the s Variable to d
void set_value(string s, double d)
{
for (int i = 0; i<=names.size(); ++i)
if (names[i].name == s) {
names[i].value = d;
return;
}
error("set: undefined name ",s);
}
//checks if the variable is already declared
bool is_declared(string s)
{
for (int i = 0; i<names.size(); ++i)
if (names[i].name == s) return true;
return false;
}
Token_stream ts;
double expression();
//check tokenstream for the char we want to use next
Token checkForChar(Token t, char ch)
{
//convert ch to string for error message
string chstring = "";
chstring += ch;
error("'" + chstring + "' expected");
}
double primary()
{
//get character from stream
Token t = ts.get();
switch (t.kind)
//solve expression
{
case '(':
{	double d = expression();
t = ts.get();
if (t.kind != ')') error("')' expected"); //ERROR SHOULD RETURN "EXPECTED ')'"
return d; //MISSING BREAK OR RETURN
}
//solve -primary
case '-':
return - primary();
//solve number
case number:
return t.value;
//solve name 
case name:
return get_value(t.name);
//solve "sqrt(expression)"
case squareR:
{
//gets next char after 'sqrt' 
t = ts.get();
checkForChar(t, '(');
double d = expression();
if (d < 0) //checks if expression is negative
error("Cannot squareroot negative integers");
t = ts.get();
checkForChar(t, ')');
return sqrt(d); // return square root of the expression
}
//solve "pow(expression, expression)"
case findPow:
{
//gets next char after 'pow'
t = ts.get();
checkForChar(t, '(');
double d = expression();
t = ts.get();
checkForChar(t, ',');
//get the expression after ','
double i = expression();
t = ts.get();
checkForChar(t, ')');
return pow(d, i);// return expression using pow()
}
default:
error("primary expected");
}
return 0;
}
//read in values to come after primary
double term()
{
double left = primary();
while(true) {
Token t = ts.get();
switch(t.kind) {
case '*':
left *= primary();
break;
case '/':
{	double d = primary();
if (d == 0) error("divide by zero");
left /= d;
break;
}
default:
ts.unget(t);
return left;
}
}
}
//can be used before primary
double expression()
{
double left = term();
while(true) {
Token t = ts.get();
switch(t.kind) {
case '+':
left += term();
break;
case '-':
left -= term();
break;
default:
ts.unget(t);
return left;
}
}
}
//check for name errors
double declaration()
{
Token t = ts.get();
if (t.kind != 'a') error ("name expected in declaration");
string name = t.name;
if (is_declared(name)) error(name, " declared twice");
Token t2 = ts.get();
if (t2.kind != '=') error("= missing in declaration of " ,name);
double d = expression();
names.push_back(Variable(name,d));
return d;
}
double statement()
{
Token t = ts.get();
switch(t.kind) {
case let:
return declaration();
default:
ts.unget(t);
return expression();
}
}
void clean_up_mess()
{
ts.ignore(print);
}
const string prompt = "> ";
const string result = "= ";
void calculate()
{
while(true) try {
cout << prompt;
Token t = ts.get();
while (t.kind == print) t=ts.get();
if (t.kind == quit) return;
ts.unget(t);
cout << result << statement() << endl;
}
catch(runtime_error& e) {
cerr << e.what() << endl;
clean_up_mess();
}
}
int main()
try {
define name("k",1000);
calculate();
return 0;
}
catch (exception& e) {
cerr << "exception: " << e.what() << endl;
char c;
while (cin >>c&& c!=';') ;
return 1;
}
catch (...) {
cerr << "exception\n";
char c;
while (cin>>c && c!=';');
return 2;
}

