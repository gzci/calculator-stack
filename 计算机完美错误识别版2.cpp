#include<iostream>
#include<stack>
using namespace std;
//详细内容分析在实验报告中 
 //使用系统自带STL库函数 
 //这个版本能判断 结果是0的式子 
class calculator{
	private:
		stack<char> optr;
		stack<double> opnd;
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
//操作具体的方法 
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
				
 		default:ret=-1;
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
 		default:ret=-1;
	 }
 	return ret;
 }
void calculator::evaluate(){
	char ch,op,theta;
	double val,a,b;
	int tag=0;
	cin>>ch;
	op='#';
	
	//当判断ch结束时 堆栈也是空的时候 结束循环 
	//this if以为着 式子首位只能是( 或者是数字的判断  错误判断语句 
	if(isdigit(ch)||rp(ch)==6){ 
			while((ch!='#')||(op!='#')){
			if(((rp(ch)!=-1) ||isdigit(ch))){
			
			if(isdigit(ch)){
			cin.putback(ch);
			cin>>val;
			opnd.push(val);
			cin>>ch;
		//计算优先级 根据优先级进行判断 
		}else if(lp(op)<rp(ch)){
				optr.push(ch);
		      	cin>>ch;
		      	if(!isdigit(ch))break;
			
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
			//运算具体结果 
			opnd.push(operate(theta,a,b));
			
		}
	
		op=optr.top(); 
		}else{
			cin>>ch;
		}
		if(ch=='#'&&(lp(op)>=3)&&(lp(op)<=5)){
			
			theta=optr.top();
			optr.pop(); 
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			opnd.pop();
			//运算具体结果 
			opnd.push(operate(theta,a,b));
			op=optr.top(); 
			tag=1;
		}
		if(tag==1)break;
		
	}
	}

	//判断结果是否正确 
	
	int final1=opnd.top();
	opnd.pop();
	int final2=opnd.top();
cout<<final1<<"               "<<final2<<endl;
	if(final1==0){
		if(final2==0) cout<<"="<<0<<endl;
		else  cout<<"错误";
	}else if(optr.top()!='#'){
		cout<<"错误";
		//this if 用于判断两个括号之间没有运算符 这种错误。也属于错误判断语句。 
	}else if(final2!=0){ 
		
		cout<<"错误";
	}else cout<<"="<<final1;
	


 
	
}
int main(){
	calculator c;
	
	c.evaluate();

	

	 
}
