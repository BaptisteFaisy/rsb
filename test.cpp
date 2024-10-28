
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
	// str = ("A!!");
	// cout << negation_normal_form(str) << '\n'; // pas bon
	// str = ("AB&!");
	// cout << negation_normal_form(str) << '\n';// 4
	// str ="AB|!";
	// cout << negation_normal_form(str) << '\n';// 4
	// str ="AB>";
	// cout << negation_normal_form(str) << '\n'; // 2
	// str ="AB=";
	// cout << negation_normal_form(str) << '\n'; // 3
	str = "ABC|&";
	cout << negation_normal_form(str) << "espected : AB|AC|&" << '\n'; // 5
	str = "ABC&|";
	cout << negation_normal_form(str) << "espected : AB&AC&|" << '\n'; // 5
	// str = "AB|C&!";
	// cout << negation_normal_form(str) << '\n'; // 4 avec 3 lettr
	// cout << "A!B!&C!|'\n";
	// str = "TEST";
	// cout << negation_normal_form(str) << '\n'; // 4 avec 3 lettre
	// str = ("AB&!");
	// cout << negation_normal_form(str) << '\n';
}
