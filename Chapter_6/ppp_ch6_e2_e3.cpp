//[e2] add {}. These should act as ()
//[e3] add !. This is the factorial operation 

#include "../std_lib_facilities.h"

class Token {
	public:
		char kind;
		double value;
		Token(char ch)    // make a Token from a char
        	:kind(ch), value(0) { }
		Token(char ch, double val)     // make a Token from a char and a double
	        :kind(ch), value(val) { }
};

class Token_Stream {
	public: 
		Token get();
		void putback(Token t);
	private:
		bool full {false};
		Token buffer {0};
};

void Token_Stream::putback(Token t)
{
	buffer = t;
	full = true;
}

Token Token_Stream::get() 
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
		case ';':
		case 'q':
		case '(': case ')': case '{': case '}':
		case '+': case '-': case '*': case '/': case '!':
			return Token {ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{	cin.putback(ch);
		 	double val;
		 	cin >> val;
		 	return Token('8', val);
		}
		default: 
			cout << ch << "\n";
			error("Token problem TT");
	}
}

Token_Stream ts;
double expression();
double term();
double primary();
double factorial(double x) {
	if (x < 0) error("Cannot conduct factorial for numbers less than 0");
	int fact = int(x);
	int ans = 1;
	for (; fact > 0; fact--) {
		ans *= fact;
	}
	//cout << "Factorial for " << x << " is " << fact << "\n";
	return double(ans);
}

int main() {
	cout << "Welcome to our simple calculator.\n"
		 << "Please enter expressions using floating-point numbers.\n";
	cout << "Available operators are +, -, *, /\n"
		 << "Press ; to print, q to exit\n";
	double val;
	try {
		while (cin) {
			Token t = ts.get();
			if (t.kind == 'q') break; //'q for "quit"
			if (t.kind == ';') 
				cout << "=" << val << '\n'; 
			else 
				ts.putback(t);
			val = expression();
		}
			
		keep_window_open("~0");
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		keep_window_open("~1");
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		keep_window_open("~2");
		return 2;
	}
}

/**
 Expression: 
 	Term
	Expression '+' Term
	Expression '-' Term
	Expression '!'
*/
double expression() {
	double left = term();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			case '!':
				left = factorial(left);
				t = ts.get();
				break;
			default: 
				ts.putback(t);
				return left; 
		}
	}
}

/**
 Term:
 	Primary
	Term '*' Primary
	Term '/' Primary 
	Term '%' Primary 
*/
double term(){
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
				{double d = primary();
				 if (d == 0) error ("divide by zero");
				 left /= d;
				 t = ts.get();
				 break;}
			default:
				ts.putback(t);
				return left;
		}
	}
}

/**
 Primary:
 Number
 '(' Expression ')' 
*/
double primary(){
	Token t = ts.get();
	switch(t.kind) {
		case '(': 
		{	double d = expression();
			t = ts.get();
			if (t.kind != ')') error ("'(' expected");
			return d;}
		case '{': 
		{	double d = expression();
			t = ts.get();
			if (t.kind != '}') error ("'{' expected");
			return d;}
		case '8': //8 indicates literal 
			return t.value;
		default: //no match, wrong
			error("Primary expected");
	}
}