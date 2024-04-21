
#include "def.hpp"

int main(void)
{
	uint32_t i = 0;
	cout << adder(3 , 3) << '\n';
	cout << Multiplier(5, 4) << '\n';
	while (i != 9)
		cout << gray_code(i++) << '\n';
	std::string str = "10&";
	cout << eval_formula(str) << '\n';
	str = ("10|");
	cout << eval_formula(str) << '\n';
	str = ("11>");
	cout << eval_formula(str) << '\n';
	str = ("10=");
	cout << eval_formula(str) << '\n';
	str = ("1011||=");
	cout << eval_formula(str) << '\n';
	str = ("11^");
	cout << eval_formula(str) << '\n';
	str = ("1!");
	cout << eval_formula(str) << '\n';
	print_truth_table("AB&C|");
	print_truth_table("ABCDEF||T=X|");
	str = ("111000||0=1|");
	cout << "test doit etre = 1 et c'est = " << eval_formula(str)  <<  '\n';

}
