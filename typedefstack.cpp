#include<iostream>
using namespace std;
const int maxstack =100;
typedef struct{
	char entry[maxstack];//�ܶ��һ�ٲ���Ҫ 
	int count;
}node;
class stackchar{
	
	public:
		stackchar();
		bool empty() const;
		int push(const int &item);
		int top(); 
		int pop();
	private:
		node n; 
			
};
stackchar::stackchar(){
   	stackchar::n.count=0;
	}
int stackchar::push(const int & item){
	n.entry[n.count++]=item;
	return 0;
}
int stackchar::pop(){
	--n.count;
	return 0;
}
int stackchar::top()
{	char item;
	item=n.entry[n.count-1];
	return item;
}
int main(){
	
}
