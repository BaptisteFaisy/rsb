#include "../def.hpp"

typedef struct s_struct 
{ 
	string result;
	int		i;
	std::deque<char>::iterator it;
	int i3 = 0;
} t_struct;

char find_next(string str, int i)
{
	i++;
	while (isalpha(str[i]))
		i++;
	return (str[i]);
}

string transform_or(string result, string str, int j)
{
	int i = j;
	result[i] = str[j];
	j++;
	i++;
	result[i] = '!';
	i++;
	result[i] = str[j];
	j++;
	i++;
	result[i] = '!';
	i++;
	result[i] = '&';
	j++;
	i++;
	result[i] = str[j];
	i++;
	result[i] = '!';
	i++;
	result[i] = '|';
	return (result);
}

// bool test(string str, int j) {while (str[j++]) {if (str[j] == '|' && (str[j + 1] == '!')) return 1; j++;} return (0);}
// bool test1(string str, int j) {
// 	while (str[j++])
// 	{
// 	if (str[j] == '&' && (str[j + 1] == '!')) 
// 		return 1; 
// 	j++;;}
// 	return (0);
// }

t_struct check(t_struct stock, int j, char operand2, char operand1, string str, std::deque<char> operandStack)
{
	char operand3;
	if (str[j] == '>') // 2
	{
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  '!';
		stock.result = stock.result +  operand1;
		stock.result = stock.result +  '|';
	}
	else if (str[j] == '=') // 3
	{
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  operand1;
		stock.result = stock.result +  '&';
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  '!';
		stock.result = stock.result +  operand1;
		stock.result = stock.result +  '!';
		stock.result = stock.result +  '&';
		stock.result = stock.result +  '|';
	}
	if (str[j] && !str.empty())
	{
		if (isalpha(str[j]) && isalpha(str[j + 1] && str[j + 2] == '|' && isalpha(str[j + 3] && str[j + 4] == '&' && str[j + 5] == '!'))) // 4 + 5
		{
			stock.result = transform_or(stock.result, str, j);
			// espect !((A | B) & C) >> ((!A & !B) | !C)
		}
	}
	// else if (str[j] == '&' && (str[j + 1] == '!')) // 4 + 5
	// {
	// 	stock.result = transform_and(stock.result, str, j);
	// 	// espect !((A | B) & C) >> ((!A & !B) | !C)
	// }
	else if (str[j] == '|' && find_next(str, j) == '&') // 5
	{
		operand3 = operandStack.front();
		operandStack.erase(stock.it);
		stock.i3++;
		stock.it++;
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  operand1;
		stock.result = stock.result +  '&';
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  operand3;
		stock.result = stock.result +  '&';
		stock.result = stock.result +  '|';
	}
	else if (str[j] == '&' && find_next(str, j) == '|') // 5
	{
		operand3 = operandStack.front();
		operandStack.erase(stock.it);
		stock.i3++;
		stock.it++;
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  operand1;
		stock.result = stock.result +  '|';
		stock.result = stock.result +  operand2;
		stock.result = stock.result +  operand3;
		stock.result = stock.result +  '|';
		stock.result = stock.result +  '&';
	}
	return (stock);
}

string negation_normal_form(const string &str)
{
    std::deque<char> operandStack;
	char operand2;
	char operand1;
	t_struct stock;
	stock.i = 0;
	stock.it = operandStack.begin();
	stock.i3 = 0;
    for (int j = 0; str[j]; j++) {
        if (!isalpha(str[j]) && str[j] != '!' && str[j] != '|' && str[j] != '&' && str[j] != '^' && str[j] != '>' && str[j] != '=') {
			cout << "Parsing error" << '\n';
			return (NULL);
		}
		else if (isalpha(str[j])) {
            operandStack.push_back(str[j]);
			stock.i++;
        }
		else
		{
			if (stock.i3 < stock.i)
			{
				operand2 = operandStack.front();
				operandStack.erase(stock.it);
				stock.i3++;
				stock.it++;
			}
			if (stock.i3 < stock.i)
			{
				operand1 = operandStack.front();
				operandStack.erase(stock.it);
				stock.i3++;
				stock.it++;
			}
			if (str[j] == '!' && str[j + 1] == '!')
			{
				stock.result = stock.result +  operand2;
				continue;
			}
			stock = check(stock, j, operand2, operand1, str, operandStack);
        }
    }
    return (stock.result);
}