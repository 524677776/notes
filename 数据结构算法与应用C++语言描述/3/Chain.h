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
	friend Chain<T>; //��Chain<T>�������г�Ա

private:
	T data;  //������
	ChainNode<T> *link;  //������  ָ����һ�� ChainNode<T>
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

	//ָ���һ���ڵ��ָ��
	ChainNode<T> *first; 
};

//���������, ����ɾ�������е����нڵ�
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

//����������Ԫ�ص�����
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

//�������в��ҵ�k��Ԫ��
template<class T>
bool Chain<T>::Find(int k, T& x) const
{
	//1.��������ڵ�k��Ԫ��, �򷵻�false, ���򷵻�true
	if (k < 1)
		return false;
	ChainNode<T>* current = first;
	//current������
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

//������������, Ѱ��x, �������x,�򷵻�x��λ��, ���x����������,�򷵻�0
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

//�������, ������Ԫ�����������
template<class T>
void Chain<T>::Output(ostream& out) const
{
	ChainNode<T>* current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
}

//����<<
template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

//��������ɾ��һ��Ԫ��
template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
	//1. �ѵ�k��Ԫ��ȡ��x, Ȼ���������ɾ����K��Ԫ��
	//2. ��������ڵ�K��Ԫ��, �������쳣OutOfBounds
	if (k < 1 || !first)
		throw OutOfBounds();

	//p����ָ���k���ڵ�
	ChainNode<T> *p = first;
	
	//��p�ƶ�����k��Ԫ��,����������ɾ����Ԫ��
	if (k == 1)
		first = first->link;
	else{
		//��qָ���k-1��Ԫ��
		ChainNode<T> *q = first;
		for (int index = 1; index < k-1 && q; index++)
		{
			q = q->link;
		}

		if (!q || !q->link)
			throw OutOfBounds();
		
		p = q->link;//���ڵ�k��Ԫ��
		q->link = p->link;//��������ɾ����Ԫ��
	}

	//�����k��Ԫ�ز��ͷŽڵ�P
	x = p->data;
	delete p;

	return *this;
}


//�������в���Ԫ��
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
	//�ڵ�K��Ԫ��֮�����x
	//��������ڵ�k��Ԫ��, �������쳣OutOfBounds
	//���û���㹻�Ŀռ��򴫵�NoMem�쳣
	if (k < 0)
		throw OutOfBounds();

	//p����ָ���k���ڵ�
	ChainNode<T> *p = first;
	//��P�ƶ�����k��Ԫ��
	for (int index = 1; index < k && p; index++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
		throw OutOfBounds(); // �����ڵ�k��Ԫ��

	//����
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