#include<iostream>
#include<stack>
using namespace std;
 const int maxstack =100;
class stackchar{
	
	public:
		stackchar();
		bool empty() const;
		int push(const int &item);
		int top(); 
		int pop();
	private:
		char entry[maxstack];
		int count;
			
};
stackchar::stackchar(){
   	stackchar::count=0;
	}
int stackchar::push(const int & item){
	entry[count++]=item;
	return 0;
}
int stackchar::pop(){
	--count;
	return 0;
}
int stackchar::top()
{	char item;
	item=entry[count-1];
	return item;
}
class stackdouble{
	public:
		stackdouble();
		bool empty() const;
		int push(const int &item);
		int top();
		int pop();
	private:
		char entry[maxstack];
		int count1;
};
stackdouble::stackdouble(){
	stackdouble::count1=0;
} 
int stackdouble::push(const int & item){
	entry[count1++]=item;
	return 0;

}
int stackdouble::pop() {
	--count1;
	return 0;
}
int stackdouble::top() {
		char item;
	item=entry[count1-1];
	return item;
}

class calculator{
	private:
		stackchar optr;
		stackdouble opnd;
		double value;
		public:
			calculator(){
				opnd.push(0); 
				optr.push('#');
			}
			void run();
			void evaluate();
			void clear();
			private:
				int lp(char op);
				int rp(char op);
				double operate(char theta,double a,double b);
				
				
			
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
 	int ret;
 	switch(ch){
 		case '+':ret=3;break;
		case '-':ret=3;break;
		case '*':ret=5;break;
		case '/':ret=5;break;
		case '(':ret=1;break;
		case ')':ret=6;break;
		case '#':ret=0;break; 		
 		
	 }
 	return ret;
 } 
 int calculator::rp(char ch){
 	int ret;
 	switch(ch){
 		case '+':ret=2;break;
		case '-':ret=2;break;
		case '*':ret=4;break;
		case '/':ret=4;break;
		case '(':ret=6;break;
		case ')':ret=1;break;
		case '#':ret=0;break; 		
 		
	 }
 	return ret;
 }
void calculator::evaluate(){
	char ch,op,theta;
	double val,a,b;
	cin>>ch;
	op='#';
	while((ch!='#')||(op!='#')){
		if(isdigit(ch)){
			cin.putback(ch);
			cin>>val;
			opnd.push(val);
			cin>>ch;
			
		}else if(lp(op)<rp(ch)){
			optr.push(ch);
			cin>>ch;
			
		}else if(lp(op)==rp(ch)){
			optr.pop();
			cin>>ch;
			
		}else{
			theta=optr.top();
			optr.pop(); 
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			
			opnd.pop();
			opnd.push(operate(theta,a,b));
			 
		}
	
		op=optr.top(); 
		
		
	}
	if(opnd.top()==0){
		cout<<"´íÎó";
	} else{
		cout<<"="<<opnd.top();
	}
	
}
int main(){
	calculator c;
	
	c.evaluate();

	

	 
}
