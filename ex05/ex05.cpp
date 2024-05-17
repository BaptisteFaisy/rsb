#include "../def.hpp"

string check(string result, int j, char operand2, char operand1, string str)
{
	if (str[j] == '>')
	{
		result += operand2;
		result += '!';
		result += operand1;
		result += '|';
	}
	else if (str[j] == '=') // 3
	{
		result += operand2;
		result += operand1;
		result += '&';
		result += operand2;
		result += '!';
		result += operand1;
		result += '!';
		result += '&';
		result += '|';
	}
	else if (str[j] == '|' && str[j + 1] == '!') // 4
	{
		result += operand2;
		result += '!';
		result += operand1;
		result += '!';
		result += '&';
	}
	else if (str[j] == '&' && str[j + 1] == '!') // 4
	{
		result += operand2;
		result += '!';
		result += operand1;
		result += '!';
		result += '|';
	}
	else if () // 5
	return (result);
}

string negation_normal_form(const string &str)
{
    std::stack<char> operandStack;
	char operand2;
	char operand1;
	string	result;
	int i = 0;
    for (int j = 0; str[j]; j++) {
        if (!isalpha(str[j]) && str[j] != '!' && str[j] != '|' && str[j] != '&' && str[j] != '^' && str[j] != '>' && str[j] != '=') {
			cout << "Parsing error" << '\n';
			return (NULL);
		}
		else if (isalpha(str[j])) {
            operandStack.push(str[j] - '0');
			i++;
        }
		else
		{
			if (i > 0)
			{
				operand2 = operandStack.top();
				operandStack.pop();
				i--;
			}
			if (i > 0)
			{
				operand1 = operandStack.top();
				operandStack.pop();
				i--;
			}
			if (str[j] == '!' && str[j + 1] == '!')
				j++;
			result = check(result, j, operand2, operand1, str);
        }
		
    }
    return (result);
}