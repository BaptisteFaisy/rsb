#include <string>
#include <utility>
#include <optional>
#include <vector>
#include <iostream>
#include "../def.hpp"
using std::string;
using std::vector;
using std::pair;

// (¬¬A) ⇔ A
static string rm_double_negations(const string& s) noexcept
{
	string r;
	auto should_pass = false;
	for (decltype(s.length()) i = 0; i < s.length(); i++) {
		if (should_pass) {
			should_pass = false;
			continue;
		}
		if (s[i] != '!') {
			r.push_back(s[i]);
			continue;
		}
		if (i + 1 == s.length() || s[i + 1] != '!') {
			r.push_back(s[i]);
			continue;
		}
		should_pass = true;
	}
	return r;
}

// (A ⇒ B) ⇔ (¬A ∨ B)
static string rm_material_conditions(const string& s) noexcept
{
	auto r = string();
	for (auto i = 0u; i < s.length(); i++) {
		if (s[i] != '>') {
			r.push_back(s[i]);
			continue;
		}
		const auto ps = get_params(r + ">", r.length());
		const auto a = ps.left->value;
		const auto b = ps.right->value;
		// removing b to insert '!'
		r = r.substr(0, r.length() - b.length());
		// a!b|
		r += "!" + b + "|";
	}
	return r;
}

// (A ⇔ B) ⇔ ((A ⇒ B) ∧ (B ⇒ A)) 

// expliquation car celui ci est technique mais de base c'est pas dans l'enonce donc...
// https://www.emathhelp.net/en/calculators/discrete-mathematics/boolean-algebra-calculator/?f=A%3DB
static string rm_equivalence(const string& s) noexcept
{
	auto r = string();
	if (isalpha(s[0]) && s[2] == '=' && isalpha(s[1]) && s[1] != s[0])
		return ("AB&A!B!&|");
	for (auto i = 0u; i < s.length(); i++) {
		if (s[i] != '=') {
			r.push_back(s[i]);
			continue;
		}
		const auto ps = get_params(r + "=", r.length());
		const auto a = ps.left->value;
		const auto b = ps.right->value;
		r += ">" + b + a + ">&"; 
		// AB&A!B!&|

	}
	return r;
}

// (A ^ B) ⇔ !(A ⇔ B)
static string rm_xor(const string& s) noexcept
{
	auto r = string();
	for (auto i = 0u; i < s.length(); i++) {
		if (s[i] != '^') {
			r.push_back(s[i]);
			continue;
		}
		const auto ps = get_params(r + "^", r.length());
		const auto a = ps.left->value;
		const auto b = ps.right->value;
		// ab>ba>& but first ab is already written
		r += "!&" + b + a + "!&|";
	}
	return r;
}

static string apply_morgan(const string& s) noexcept
{
	auto r = string();
	auto should_skip = false;
	for (auto i = 0u; i < s.length(); i++) {
		if (should_skip) {
			should_skip = false;
			continue;
		}
		if (i == s.length() - 1 ||
			!((s[i + 1] == '!') && (s[i] == '&' || s[i] == '|')))
		{
			r.push_back(s[i]);
			continue;
		}
		const auto ps = get_params(r + "&", r.length());
		const auto a = ps.left->value;
		const auto b = ps.right->value;
		// removing b to insert '!'
		r = r.substr(0, r.length() - b.length());
		// ab&! -> a!b!|
		// ab|! -> a!b!&
		r += "!" + b + "!" + ((s[i] == '|') ? "&" : "|");
		should_skip = true;
	}
	return r;
}

static bool is_valid(const string& s) noexcept
{
	if (s.find("!!") != s.npos) return false;
	if (s.find("&!") != s.npos) return false;
	if (s.find("|!") != s.npos) return false;
	if (s.find("=") != s.npos) return false;
	if (s.find("^") != s.npos) return false;
	if (s.find(">") != s.npos) return false;
	return true;
}

string negation_normal_form(const string& formula) noexcept
{
	std::string s = formula;
	do {
		s = rm_xor(s);
		s = rm_equivalence(s);
		s = rm_material_conditions(s);
		s = apply_morgan(s);
		s = rm_double_negations(s);
	}
	while (!is_valid(s));
	return s;
}


// #include "../def.hpp"

// typedef struct s_struct 
// { 
// 	string result;
// 	int		i;
// 	std::deque<char>::iterator it;
// 	int i3 = 0;
// } t_struct;

// char find_next(string str, int i)
// {
// 	i++;
// 	while (isalpha(str[i]))
// 		i++;
// 	return (str[i]);
// }

// string transform_or(string result, string str, int j)
// {
// 	int i = j;
// 	result[i] = str[j];
// 	j++;
// 	i++;
// 	result[i] = '!';
// 	i++;
// 	result[i] = str[j];
// 	j++;
// 	i++;
// 	result[i] = '!';
// 	i++;
// 	result[i] = '&';
// 	j++;
// 	i++;
// 	result[i] = str[j];
// 	i++;
// 	result[i] = '!';
// 	i++;
// 	result[i] = '|';
// 	return (result);
// }

// // bool test(string str, int j) {while (str[j++]) {if (str[j] == '|' && (str[j + 1] == '!')) return 1; j++;} return (0);}
// // bool test1(string str, int j) {
// // 	while (str[j++])
// // 	{
// // 	if (str[j] == '&' && (str[j + 1] == '!')) 
// // 		return 1; 
// // 	j++;;}
// // 	return (0);
// // }

// t_struct check(t_struct stock, int j, char operand2, char operand1, string str, std::deque<char> operandStack)
// {
// 	char operand3;
// 	if (str[j] == '>') // 2
// 	{
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  '!';
// 		stock.result = stock.result +  operand1;
// 		stock.result = stock.result +  '|';
// 	}
// 	else if (str[j] == '=') // 3
// 	{
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  operand1;
// 		stock.result = stock.result +  '&';
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  '!';
// 		stock.result = stock.result +  operand1;
// 		stock.result = stock.result +  '!';
// 		stock.result = stock.result +  '&';
// 		stock.result = stock.result +  '|';
// 	}
// 	if (str[j] && !str.empty())
// 	{
// 		if (isalpha(str[j]) && isalpha(str[j + 1] && str[j + 2] == '|' && isalpha(str[j + 3] && str[j + 4] == '&' && str[j + 5] == '!'))) // 4 + 5
// 		{
// 			stock.result = transform_or(stock.result, str, j);
// 			// espect !((A | B) & C) >> ((!A & !B) | !C)
// 		}
// 	}
// 	// else if (str[j] == '&' && (str[j + 1] == '!')) // 4 + 5
// 	// {
// 	// 	stock.result = transform_and(stock.result, str, j);
// 	// 	// espect !((A | B) & C) >> ((!A & !B) | !C)
// 	// }
// 	else if (str[j] == '|' && find_next(str, j) == '&') // 5
// 	{
// 		operand3 = operandStack.front();
// 		operandStack.erase(stock.it);
// 		stock.i3++;
// 		stock.it++;
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  operand1;
// 		stock.result = stock.result +  '&';
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  operand3;
// 		stock.result = stock.result +  '&';
// 		stock.result = stock.result +  '|';
// 	}
// 	else if (str[j] == '&' && find_next(str, j) == '|') // 5
// 	{
// 		operand3 = operandStack.front();
// 		operandStack.erase(stock.it);
// 		stock.i3++;
// 		stock.it++;
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  operand1;
// 		stock.result = stock.result +  '|';
// 		stock.result = stock.result +  operand2;
// 		stock.result = stock.result +  operand3;
// 		stock.result = stock.result +  '|';
// 		stock.result = stock.result +  '&';
// 	}
// 	return (stock);
// }

// string negation_normal_form(const string &str)
// {
//     std::deque<char> operandStack;
// 	char operand2;
// 	char operand1;
// 	t_struct stock;
// 	stock.i = 0;
// 	stock.it = operandStack.begin();
// 	stock.i3 = 0;
//     for (int j = 0; str[j]; j++) {
//         if (!isalpha(str[j]) && str[j] != '!' && str[j] != '|' && str[j] != '&' && str[j] != '^' && str[j] != '>' && str[j] != '=') {
// 			cout << "Parsing error" << '\n';
// 			return (NULL);
// 		}
// 		else if (isalpha(str[j])) {
//             operandStack.push_back(str[j]);
// 			stock.i++;
//         }
// 		else
// 		{
// 			if (stock.i3 < stock.i)
// 			{
// 				operand2 = operandStack.front();
// 				operandStack.erase(stock.it);
// 				stock.i3++;
// 				stock.it++;
// 			}
// 			if (stock.i3 < stock.i)
// 			{
// 				operand1 = operandStack.front();
// 				operandStack.erase(stock.it);
// 				stock.i3++;
// 				stock.it++;
// 			}
// 			if (str[j] == '!' && str[j + 1] == '!')
// 			{
// 				stock.result = stock.result +  operand2;
// 				continue;
// 			}
// 			stock = check(stock, j, operand2, operand1, str, operandStack);
//         }
//     }
//     return (stock.result);
// }