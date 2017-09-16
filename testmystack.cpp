#include<iostream>
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
int main(){
	stackchar a;
	a.push(1);
	a.push(2);
	cout<<a.top();
	a.pop();
	cout<<a.top();
	 
}
