#include<iostream>
#include<stack>
#include<string>

 using namespace std;
 class calculator {
 	private:
 		stack<char>potr;
 		stack<
 };
int main(){
	char ch='#';
	stack <int> opnd ;
	stack <char> optr ;
	optr.push('#');
	string s="4#";
	ch= s.at(0);		
	
	for(int i=0;ch!='#'&&i<=s.length();i++){
		if(ch>=48 &&ch<=58){
			opnd.push((int)ch-48);

		}
		else
		{
		
		}
		ch=s.at(i);
	}
	cout<< opnd.top() ;
	

}
