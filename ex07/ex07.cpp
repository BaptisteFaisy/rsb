#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool sat(const string& formula) {
    // First, validate the input
    set<char> variables_set;
    for (char c : formula) {
        if (c >= 'A' && c <= 'Z') {
            variables_set.insert(c);
        } else if (c != '!' && c != '&' && c != '|' && c != '^') {
            // Invalid character found
            return false;
        }
    }
    
    vector<char> variables(variables_set.begin(), variables_set.end());
    unordered_map<char, size_t> var_to_index;  // Changed to size_t
    for (size_t i = 0; i < variables.size(); ++i) {  // Changed to size_t
        var_to_index[variables[i]] = i;
    }
    
    size_t n = variables.size();  // Changed to size_t
    size_t num_assignments = pow(2, n);  // Changed to size_t
    
    for (size_t i = 0; i < num_assignments; ++i) {  // Changed to size_t
        vector<bool> assignment(n);
        for (size_t j = 0; j < n; ++j) {  // Changed to size_t
            assignment[j] = (i >> j) & 1;
        }
        
        stack<bool> stk;
        for (char c : formula) {
            if (c >= 'A' && c <= 'Z') {
                stk.push(assignment[var_to_index[c]]);
            } else {
                if (c == '!') {
                    if (stk.size() < 1) return false; // Not enough operands
                    bool a = stk.top(); stk.pop();
                    stk.push(!a);
                } else {
                    if (stk.size() < 2) return false; // Not enough operands
                    bool b = stk.top(); stk.pop();
                    bool a = stk.top(); stk.pop();
                    if (c == '&') {
                        stk.push(a && b);
                    } else if (c == '|') {
                        stk.push(a || b);
                    } else if (c == '^') {
                        stk.push(a != b);
                    }
                }
            }
        }
        if (stk.size() != 1) return false; // Malformed expression
        
        if (stk.top()) {
            return true;
        }
    }
    
    return false;
}