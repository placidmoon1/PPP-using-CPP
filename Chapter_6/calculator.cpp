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
		case '(': case ')': case '+': case '-': case '*': case '/':
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
			error("Bad token");
	}
}

Token_Stream ts;
double expression();
double term();
double primary();
Token get_token();

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}


int main() {
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
		case '8': //8 indicates literal 
			return t.value;
		default: //no match, wrong
			error("Primary expected");
	}
}