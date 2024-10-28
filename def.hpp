#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <iostream>
#include <memory>

struct Params {
	std::unique_ptr<Params> left = nullptr;
	std::unique_ptr<Params> right = nullptr;
	std::string value = "";
	friend std::ostream& operator<<(std::ostream& os, const Params& p) noexcept;
};
std::ostream& operator<<(std::ostream& os, const Params& p) noexcept;
Params get_params(const std::string& s, const int i) noexcept;
vector<vector<bool>> get_list(const string& formula, const vector<char>& vars,
					 vector<bool> r = vector<bool>(),
					vector<vector<bool>> ret = vector<vector<bool>>());


uint32_t adder(uint32_t a, uint32_t b) noexcept ;
uint32_t Multiplier(uint32_t a, uint32_t b) noexcept ;
uint32_t gray_code(uint32_t nbr)noexcept ;
int eval_formula(const std::string& expression);
int print_truth_table(const std::string &str);
string negation_normal_form(const std::string& formula) noexcept;
string conjunctive_normal_form(const string& formula);

