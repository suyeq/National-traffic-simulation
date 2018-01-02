#pragma once
template <class T>
class SeqList
{
protected:
	T *list;							//数组
	int maxSize;							//最大元素个数
	int size;								//当前元素个数
public:
	SeqList();
	SeqList(int max);		      			//构造函数
	~SeqList();		      				//析构函数

	int Size(void) const;					//取当前数据元素个数
	void Insert( T item, int i);//插入
	T Delete(const int i);			//删除
	T & GetData(int i)const;			//取数据元素
	T &operator [](int i);           //重载[]
	void Cleardate();//清空
	SeqList<T>& operator=(SeqList<T>& temp);
};
template <class T>
T &SeqList<T>::operator[](int i) {
	if (i<0 || i>size) {
		exit(0);
	}
	else {
		return list[i];
	}
}
template <class T>
SeqList<T>::SeqList()					//构造函数
{
	maxSize = 100;
	size = 0;
	list = new T[maxSize];
}
template <class T>
SeqList<T>::SeqList(int max)					//构造函数
{
	maxSize = max;
	size = 0;
	list = new T[maxSize];
}
template <class T>
SeqList<T>::~SeqList()						//析构函数
{
	//delete []list;
}
template <class T>
int SeqList<T>::Size(void) const			//取当前数据元素个数
{
	return size;
}

template <class T>
void SeqList<T>::Insert(T item, int i)	//插入
											//在指定位置i前插入一个数据元素item
{
	if (size == maxSize)
	{
		cout << "顺序表已满无法插入！" << endl;
		exit(0);
	}
	if (i < 0 || i > size)					//参数正确与否判断
	{
		cout << "参数i越界出错!" << endl;
		exit(0);
	}

	//从size-1至i逐个元素后移
	for (int j = size; j > i; j--) list[j] = list[j - 1];
	list[i] = item;	                  //在i位置插入item	
	size++;		//当前元素个数加1
}
template <class T>
T SeqList<T>::Delete(const int i)				//删除
												//删除指定位置i的数据元素，删除的元素由函数返回
{
	if (size == 0)
	{
		cout << "顺序表已空无元素可删！" << endl;
		exit(0);
	}
	if (i < 0 || i > size - 1)			//参数正确与否判断
	{
		cout << "参数i越界出错!" << endl;
		exit(0);
	}

	T x = list[i];				//取到要删除的元素

								//从i+1至size-1逐个元素前移
	for (int j = i; j < size - 1; j++) list[j] = list[j + 1];

	size--;								//当前元素个数减1
	return x;							//返回删除的元素
}
template <class T>
T & SeqList<T>::GetData(int i) const	//取数据元素
										//取位置i的数据元素，取到的数据元素由函数返回
{
	if (i < 0 || i > size - 1)			//参数正确与否判断
	{
		cout << "参数i越界出错!" << endl;
		exit(0);
	}
	return list[i];						//返回取到的元素
}
template<class T>
 SeqList<T>& SeqList<T>:: operator=(SeqList<T>& temp) {//深拷贝
	if (this == &temp)
		return *this;
	else {
		if (list != NULL) {
			delete[] list;
		}
		list = new T[100];
		for (int i = 0; i < temp.Size(); i++) {
			list[i] = temp[i];
			size++;
		}
		return *this;
	}
}
template<class T>
void SeqList<T>::Cleardate() {
	delete[] list;
	size = 0;
}