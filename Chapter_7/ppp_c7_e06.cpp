#include "../std_lib_facilities.h"

const char print = ';';
const char quit = 'q';
const char help = 'h';
const char helpUpper = 'H';

class Token {
	public:
		char kind;
		double value;
		string name;
		bool is_const = false; 
		Token(char ch)    // make a Token from a char
        	:kind(ch), value(0) { }
		Token(char ch, double val)     // make a Token from a char and a double
	        :kind(ch), value(val) { }
		Token(char ch, string n)
			:kind{ch}, name{n} {}
		Token(char ch, string n, bool c)
			:kind{ch}, name{n},  is_const {c} {}
};

class Variable {
	public:
		string name;
		double value;
		bool is_const;
};

class Symbol_table {
	public: 
		vector<Variable> var_table;
		double get (string s);
		void set (string s, double d);
		bool is_declared(string var);	
		bool is_var_const(string var);
		double define_name(string var, double val, bool isconst);
};

class Token_Stream {
	public: 
		Token get();
		void putback(Token t);
		void ignore(char c); //discard up to, and including [c] 
	private:
		bool full {false};
		Token buffer {0};
};

void Token_Stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}
	
void Token_Stream::putback(Token t)
{
	buffer = t;
	full = true;
}

const char name = 'a';		  	//name token 
const char constToken = 'C';	//const declaration token 
const char let = 'L';		  	//declaration token
const char newlineToken = ';';	//newline and print the same. print is ;
const string declkey = "let"; 	//declaration keyword
const string constkey = "const"; //const declaration keyword 


Token Token_Stream::get() 
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	//cout << "ch received: " << ch << "\n";

	switch (ch) {
		case print:
		case quit:
		case help: case helpUpper:
		case '(': case ')': case '+': case '-': case '*': case '/': case '=':
			return Token {ch};
		case '\n':
			cout << "Caught newline\n";
			return Token {newlineToken};
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{	cin.putback(ch);
		 	double val;
		 	cin >> val;
		 	return Token('8', val);
		}
		default: 
			if (isalpha(ch)) {
				string s;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
				cin.putback(ch); //first character that isn't alphabet or digit. 
				if (s==declkey) return Token{let};
				if (s==constkey) return Token{constToken};
				return Token{name, s};
			}
			error("Bad token ", ch);
	}
}

Symbol_table st;
Token_Stream ts;
double expression();
double term();
double primary();

double Symbol_table::get (string s) {
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable ", s);
}

void Symbol_table::set (string s, double d) {
	for (Variable& v : var_table) {
		if (v.name == s) {
			v.value = d;
			return;
		}
	}
	error("set: undefined variable ", s);
}

//check if var is already in var_table
bool Symbol_table::is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

//check if var is a const. should be done after is_declared()
bool Symbol_table::is_var_const(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var && v.is_const == true) return true;
	return false;
}

double Symbol_table::define_name(string var, double val, bool isconst)
{
	if (st.is_declared(var)) error (var, "Declared twice");
	var_table.push_back(Variable{var, val, isconst});
	return val; 
}


//parameter is_const checks whether the declaration is a 
//const declaration or not. 
double declaration(bool is_const)
{
	//assume we have [let|const]
	// handle: [name] [=] [expr]
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	
	double d = expression();
	if (is_const)
		st.define_name(var_name, d, true);
	else 
		st.define_name(var_name, d, false);
	return d;
}

double assignment(string name) 
{
	//asume we have [name] [=]
	//handle new assignment value. 
	if (st.is_var_const(name)) error ("cannot assign new value to const");
	double d = expression();
	st.set(name, d);
	return d;
	
}

double statement()
{
	Token t= ts.get();
	switch(t.kind){
		case let:
			return declaration(false);
		case constToken: 
			return declaration(true);
		case name:
			{char u_in;
			 cin >> u_in;
			 if (u_in == '='){ //is an assignment 
				 //check whether name is a const name or not. 
				 return assignment(t.name);//an assignment operation
			 }
			 cin.putback(u_in); //make it fall through default, no breaks!
			}
		default:
			ts.putback(t);
			return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate() 
{
	while (cin) {
		try {
			cout << "> "; //print prompt
			Token t = ts.get();
			while (t.kind ==  ';') t = ts.get();
			if (t.kind == quit) {
				keep_window_open();
				return;
			} 
			if (t.kind == help || t.kind == helpUpper) {
				cout << "This is a simple calculator\n"
					 << "Allowed operations is +, -, *, /, and %\n" 
					 << "To declare a variable, use [let x = 5;] or [const x = 5;]\n"
					 << "All statments MUST END WITH A [;]\n";
				return;
			}
			ts.putback(t);
			cout << "= " << statement() << "\n";
		} catch (exception& e) {
			cerr << e.what() << "\n";
			clean_up_mess();
		}
 
	}
}

int main() {
	double val;
	try {
		calculate();
		keep_window_open("~0");
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		cout << "Please enter the character ~ to close the window\n";
		for (char ch; cin >> ch; )
			if (ch=='~') return 1;
		return 1;
	}
	catch (exception& e) {
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
		case name:
            return st.get(t.name); // return the variable's value
        case '-':
            return -primary();
        case '+':
            return primary();
		case '8': //8 indicates literal 
			return t.value;
		default: //no match, wrong
			error("Primary expected");
	}
}