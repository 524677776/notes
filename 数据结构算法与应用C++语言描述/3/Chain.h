#ifndef __CHAIN_H__
#define __CHAIN_H__

#include <iostream>

using namespace std;

template <class T>
class Chain;

template <class T>
class ChainNode
{
public:
	friend Chain<T>; //与Chain<T>共享所有成员

private:
	T data;  //数据域
	ChainNode<T> *link;  //链接域  指向下一个 ChainNode<T>
};

template <class T>
class Chain
{
public:
	Chain(){ first = 0; };
	~Chain();
	bool IsEmpty() const{ return first == 0; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;

private:

	//指向第一个节点的指针
	ChainNode<T> *first; 
};

//链表的析构, 用于删除链表中的所有节点
template<class T>
Chain<T>::~Chain()
{
	ChainNode<T> *next;
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

//返回链表中元素的总数
template<class T>
int Chain<T>::Length() const
{
	ChainNode<T> *current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}

	return len;
}

//在链表中查找第k个元素
template<class T>
bool Chain<T>::Find(int k, T& x) const
{
	//1.如果不存在第k个元素, 则返回false, 否则返回true
	if (k < 1)
		return false;
	ChainNode<T>* current = first;
	//current的索引
	int index = 1; 
	while (index<k && current)
	{
		current = current->link;
		index++;
	}
	if (current){
		x = current->data;
		return true;
	}

	return false;
}

//在链表中搜索, 寻找x, 如果发现x,则返回x的位置, 如果x不再链表中,则返回0
template<class T>
int Chain<T>::Search(const T& x) const
{
	ChainNode<T> *current = first;
	int index = 1;
	while (current && current->data != x){
		current = current->link;
		index++;
	}
	if (current)
		return index;

	return 0;
}

//输出链表, 将链表元素送至输出流
template<class T>
void Chain<T>::Output(ostream& out) const
{
	ChainNode<T>* current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
}

//重载<<
template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

//从链表中删除一个元素
template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
	//1. 把第k个元素取至x, 然后从链表中删除第K个元素
	//2. 如果不存在第K个元素, 则引发异常OutOfBounds
	if (k < 1 || !first)
		throw OutOfBounds();

	//p最终指向第k个节点
	ChainNode<T> *p = first;
	
	//将p移动至第k个元素,并从链表中删除该元素
	if (k == 1)
		first = first->link;
	else{
		//用q指向第k-1个元素
		ChainNode<T> *q = first;
		for (int index = 1; index < k-1 && q; index++)
		{
			q = q->link;
		}

		if (!q || !q->link)
			throw OutOfBounds();
		
		p = q->link;//存在第k个元素
		q->link = p->link;//从链表中删除该元素
	}

	//保存第k个元素并释放节点P
	x = p->data;
	delete p;

	return *this;
}


//向链表中插入元素
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
	//在第K个元素之后插入x
	//如果不存在第k个元素, 则引发异常OutOfBounds
	//如果没有足够的空间则传递NoMem异常
	if (k < 0)
		throw OutOfBounds();

	//p最终指向第k个节点
	ChainNode<T> *p = first;
	//将P移动至第k个元素
	for (int index = 1; index < k && p; index++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
		throw OutOfBounds(); // 不存在第k个元素

	//插入
	ChainNode<T> *y = new ChainNode<T>;
	y->data = x;
	if (k){
		y->link = p->link;
		p->link = y;
	}
	else{
		y->link = first;
		first = y;
	}

	return *this;
}

#endif // !__CHAIN_H__