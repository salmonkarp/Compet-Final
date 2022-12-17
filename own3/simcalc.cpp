#include <bits/stdc++.h>

using namespace std;

int priority(char c)
{
	if(c=='+'||c=='-')
		return 1;
	else if(c=='*'||c=='/'||c=='^')
		return 2;
	else
		return 0;
}
float calculate(float num1, char op, float num2)
{
	if(op=='+')
		return num1 + num2;
	if(op=='-')
		return num1 - num2;
	if(op=='*')
		return num1 * num2;
	if(op=='/')
		return float(num1) / float(num2);
	else
		return float(pow(num1,num2));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin >> s;
		stack<char> ops;
		stack<float> nums;
		// cout << s << endl;
		for(int i=0; i<s.size(); i++)
		{
			if(isdigit(s[i]))
				nums.push(int(s[i])-48.0);
			if(priority(s[i])>0)
			{
				while(!ops.empty() && priority(s[i]) <= priority(ops.top()))
				{
					char t_op = ops.top();
					ops.pop();
					float t_num2 = nums.top();
					nums.pop();
					float t_num1 = nums.top();
					nums.pop();

					float temp = calculate(t_num1,t_op,t_num2);
					// cout << "temp: " << temp << endl;
					nums.push(temp);
				}
				ops.push(s[i]);
			}
		}
		while(!ops.empty())
		{
			char t_op = ops.top();
			ops.pop();
			float t_num2 = nums.top();
			nums.pop();
			float t_num1 = nums.top();
			nums.pop();

			float temp = calculate(t_num1,t_op,t_num2);
			// cout << "temp: " << temp << endl;
			nums.push(temp);
		}

		int res = nums.top();
		if(res==nums.top())
			printf("%g\n",nums.top());
		else
			printf("%.2f\n",nums.top());
	}
}