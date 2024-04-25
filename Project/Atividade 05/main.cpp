#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<string> tokenization(string& x);
int precedence (string i);
vector<string> to_postfix(vector<string>& tokens);
float xEval(string x, map<string, float> &m);