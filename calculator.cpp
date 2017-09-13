#include<iostream>
#include<stack>
#include<string>

 using namespace std;
 class calculator {
 	private:
 		stack<char> optr;
 		stack<double> opnd;
 		double value;
 		string s="4#";
 	public:
 		calculator(){
// 			optr.setnull();
// 			opnd.setnull();
 			optr.push('#');
		 }
		 void run ();
		 void evaluate();
		 void clear(); 
		 
		 private:
		 	int lp( char op);
		 	int rp(char op);
		 	double operate(char theta, double a,double b);
		 	
 };
 double calculator::operate(char theta,double a,double b){
 	double ret;
 	switch(theta){
 		case '+':ret=a+b;break;
		case '-':ret=a-b;break;
		case '*':ret=a*b;break;
		case '/':ret=a/b;break;
			
 		
	 }
	 return ret;
	 
 }
 int calculator::lp(char ch){
 	switch(ch){
 		case '+':3;break;
		case '-':3;break;
		case '*':5;break;
		case '/':5;break;
		case '(':1;break;
		case ')':6;break;
		case '#':1;break; 		
 		
	 }
 	
 } 
 int calculator::rp(char ch){
 	switch(ch){
 		case '+':2;break;
		case '-':2;break;
		case '*':4;break;
		case '/':5;break;
		case '(':6;break;
		case ')':1;break;
		case '#':0;break; 		
 		
	 }
 	
 }
 void calculator::clear(){
// 		opnd.setnull();
		while(opnd.empty()==false)opnd.pop();
		optr.push('#');
 } 
  void calculator::evaluate(){
  	char ch, op ,theta;
  	double val,a,b;
  	
  	ch= s.at(0);		

//  	while((ch!='#')||(op!='#'))	
	  for(int i=0;ch!='#'&&i<=s.length();i++){
  		if(isdigit(ch)){
//  			cin.putback(ch);
//  			cin>>val;
  				opnd.push((int)ch-48);
		  }
		  else if(lp(op)<rp(ch)) 
		  {
		  optr.push(ch);
		cin>>ch;
		  	
			  }else if(lp(op)==rp(ch)){
			  	optr.pop();
			  	cin>>ch;
			  	
			  }else{
			  	theta=optr.pop();
			  	b=opnd.pop();
			  	a=opnd.pop();
			  	opnd.push(operate(theta,a,b));
			  	
			  }
		  	op=optr.top();
		  	
		  }
		  cout<<'=' ;
		  opnd.top();
		  
	  }
  
  
int main(){
	

}
