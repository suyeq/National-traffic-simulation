#pragma once
template <class T>
class Stack//模板栈
{
private:
	T *list;
	int size;
	int maxSize;
public:
	Stack();
	~Stack();
	void Push(T temp);
	void Pop();
	T &operator [](int i);
	int Size();
};
template <class T>
Stack<T>::Stack(){
	maxSize = 100;
	size = 0;
	list = new T[maxSize];
}
template <class T>
Stack<T>::~Stack() {
	//delete[] T;
}
template <class T>
void Stack<T>::Push(T item)
{
	if (size == maxSize)
	{
		cout << "顺序表已满无法插入！" << endl;
		//exit(0);
		return;
	}
	list[size] = item;	                
	size++;	
}

template <class T>
void Stack<T>:: Pop()
{
	if (size == 0)
	{
		cout << "顺序表已空无元素可删！" << endl;
		//exit(0);
		return;
	}	
	size--;
}

template<class T>
int Stack<T>::Size()
{
	return size;
}
template<class T>
T &Stack<T>::operator[](int i) {
	if (i<0 || i>size) {
		cout << "参数越界出错！！" << endl;
		//system("pause");
		exit(0);
	}
	else {
		return list[i];
	}
}