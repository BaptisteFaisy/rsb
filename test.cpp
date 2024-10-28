
#include "def.hpp"

int main(void)
{
	string str;
	// uint32_t i = 0;
	// cout << adder(3 , 3) << '\n';
	// cout << Multiplier(5, 4) << '\n';
	// while (i != 9)
	// 	cout << gray_code(i++) << '\n';
	// str = "10&";
	// cout << eval_formula(str) << '\n';
	// str = ("10|");
	// cout << eval_formula(str) << '\n';
	// str = ("11>");
	// cout << eval_formula(str) << '\n';
	// str = ("10=");
	// cout << eval_formula(str) << '\n';
	// str = ("1011||=");
	// cout << eval_formula(str) << '\n';
	// str = ("11^");
	// cout << eval_formula(str) << '\n';
	// str = ("1!f");
	// cout << eval_formula(str) << '\n';
	// print_truth_table("AB&C|");
	// print_truth_table("ABCDEF||T=X|");
	// str = ("111000||0=1|");
	// cout << "test doit etre = 1 et c'est = " << eval_formula(str)  <<  '\n';
	// ex 05
	// str = ("AB&!");
	// cout <<  negation_normal_form(str).compare("A!B!|")<< '\n';// 4 OK
	// str ="AB|!";
	// cout << negation_normal_form(str).compare("A!B!&") << '\n';// 4 OK
	// str ="AB>";
	// cout << negation_normal_form(str).compare("A!B|") << '\n'; // 2 OK
	// str ="AB=";
	// cout << negation_normal_form(str) << '\n'; // 3 OK
	// str = "AB|C&!";
	// cout << negation_normal_form(str).compare("A!B!&C!|") << '\n'; // 5 OK
	// str = "AB&!";
	// cout <<  conjunctive_normal_form(str).compare("A!B!|") << endl; // OK
	// str = "AB|!";
	// cout <<  conjunctive_normal_form(str).compare("A!B!&") << endl; // OK
	// str = "AB|C&";
	// cout << conjunctive_normal_form(str).compare("AB|C&") << endl; // OK
	str = "AB|C|D|";
	cout << conjunctive_normal_form(str).compare("ABCD|||") << endl; // KO pas bonnnnnnnnnnn
}
