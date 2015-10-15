#ifndef __LinearList_H__
#define __LinearList_H__

#include <iostream>
#include <exception>

using namespace std;

template<class T>

class LinearList
{
public:
	//����һ�����Ա�
	LinearList(int MaxListSize = 10)
	{
		maxSize = MaxListSize;
		element = new T[maxSize];
		length = 0;
	}

	~LinearList(){ delete[] element; }

	//ȷ�����Ա��Ƿ�Ϊ��
	bool IsEmpty(){ return length == 0; }
	
	//ȷ�����Ա�ĵ�ǰ����
	int Length(){ return length; }

	//���ҵ�k��Ԫ��
	bool Find(int k, T& x) const
	{
		//1.��������ڵ�k��Ԫ��,�򷵻�false
		if (k <1 || k > length)
			return false;

		//2.���ҵ���Ԫ�ش���x��
		x = element[k - 1];

		return true;
	}

	//����XԪ������λ��
	int Search(const T& x) const
	{
		for (int i = 0; i < length; i++)
		{
			if (element[i] == x)
				return ++i;
		}

		return 0;
	}

	//ɾ����k��Ԫ��
	LinearList<T>& Delete(int k, T& x)
	{
		//1. ��������ڵ�k��Ԫ��,�������쳣
		if (Find(k, x)){
			//2. ��Ԫ��k+1, .. ��ǰ�ƶ�һ��λ�� 
			for (int i = k; i < length; i++)
				element[i - 1] = element[i];
			length--;

			return *this;
		}

		throw exception("out of bounds");
	}

	//�ڵ�k��Ԫ��֮�����x
	LinearList<T>& Insert(int k, const T& x)
	{
		//1. ��������ڵ�k��Ԫ��,�������쳣
		if (k<0 || k > length)
			throw exception("out of bounds");

		//2. ���������,�������쳣NoMem
		if (length == maxSize)
			throw exception("no memery");

		//3. ����ƶ�һ��λ��
		for (int i = length - 1; i >= k; i--)
			element[i + 1] = element[i];

		element[k] = x;
		length++;

		return *this;
	}

	//���
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