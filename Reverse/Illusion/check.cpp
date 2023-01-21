#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s = "BUET{}tRy69tim3sToHackm3";
	for (int i=0;i<s.size();i++){
	    int n = s[i]-'0';
	    cout << "n[" << i  << "] - \'0\'; " << s[i] <<  " = " << n << endl;
	}
	
	return 0;
}
