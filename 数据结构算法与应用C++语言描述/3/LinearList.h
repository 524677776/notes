#ifndef __LinearList_H__
#define __LinearList_H__

#include <iostream>
#include <exception>

using namespace std;

template<class T>

class LinearList
{
public:
	//创建一个线性表
	LinearList(int MaxListSize = 10)
	{
		maxSize = MaxListSize;
		element = new T[maxSize];
		length = 0;
	}

	~LinearList(){ delete[] element; }

	//确认线性表是否为空
	bool IsEmpty(){ return length == 0; }
	
	//确认线性表的当前长度
	int Length(){ return length; }

	//查找第k个元素
	bool Find(int k, T& x) const
	{
		//1.如果不存在第k个元素,则返回false
		if (k <1 || k > length)
			return false;

		//2.把找到的元素存入x中
		x = element[k - 1];

		return true;
	}

	//查找X元素所在位置
	int Search(const T& x) const
	{
		for (int i = 0; i < length; i++)
		{
			if (element[i] == x)
				return ++i;
		}

		return 0;
	}

	//删除第k个元素
	LinearList<T>& Delete(int k, T& x)
	{
		//1. 如果不存在第k个元素,则引发异常
		if (Find(k, x)){
			//2. 把元素k+1, .. 向前移动一个位置 
			for (int i = k; i < length; i++)
				element[i - 1] = element[i];
			length--;

			return *this;
		}

		throw exception("out of bounds");
	}

	//在第k个元素之后插入x
	LinearList<T>& Insert(int k, const T& x)
	{
		//1. 如果不存在第k个元素,则引发异常
		if (k<0 || k > length)
			throw exception("out of bounds");

		//2. 如果表已满,则引发异常NoMem
		if (length == maxSize)
			throw exception("no memery");

		//3. 向后移动一个位置
		for (int i = length - 1; i >= k; i--)
			element[i + 1] = element[i];

		element[k] = x;
		length++;

		return *this;
	}

	//输出
	void Output(ostream& out) const
	{
		for (int i = 0; i < length; i++)
			out << element[i] << " ";
	}

private:
	T* element;
	int length;
	int maxSize;
};

template<class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out);

	return out;
}

#endif // !__LinearList_H__