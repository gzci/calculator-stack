#include<iostream>

#include<stack>

using namespace std;

 //ʹ��ϵͳ�Դ�STL�⺯�� 

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

//��������ķ��� 

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

 		

	 }

 	return ret;

 }

void calculator::evaluate(){

	char ch,op,theta;

	double val,a,b;

	cin>>ch;

	op='#';

	//���ж�ch����ʱ ��ջҲ�ǿյ�ʱ�� ����ѭ�� 

	if(rp(ch)>1){
		while((ch!='#')||(op!='#')){

		if(((lp(ch)!=-1) ||isdigit(ch))){

			

			if(isdigit(ch)){

			cin.putback(ch);

			cin>>val;

			opnd.push(val);

			cin>>ch;

		//�������ȼ� �������ȼ������ж� 

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

			//��������� 

			opnd.push(operate(theta,a,b));

			 

		}

	

		op=optr.top(); 

		}else{

			cin>>ch;

		} 

		

		

		

	}
	}

	//�жϽ���Ƿ���ȷ 

	if(opnd.top()==0){

		cout<<"����";

	} else{

		cout<<"="<<opnd.top();

	}

	

}

int main(){

	calculator c;

	

	c.evaluate();



	



	 

}