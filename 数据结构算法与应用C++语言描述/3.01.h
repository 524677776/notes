/*
	线性表

	1. 创建一个线性表
	2. 确定线性表是否为空
	3. 确定线性表的长度
	4. 查找第K个元素
	5. 查找指定的元素
	6. 删除第K个元素
	7. 在第K个元素之后插入一个新元素

	公式化描述
*/

template<class T>
class LinearList
{
public:
	LinearList(int MaxListSize = 10); //默认创建一个包含10个节点的线性表
	~LinearList(){ delete[] Element; }
	inline bool IsEmpty() const { return Length == 0; }
	inline int Length() const { return Length; }
	bool Find(int k, T& x) const;
	int Search(const T&x) const;
	LinearList<T>& Delete(int k, T& x);  //删除第k个元素并将它返回至x中
	LinearList<T>& Insert(int k, const T& x); //在第k个元素之后插入x
	void Output(ostream& out) const;

private:
	T* Element; //一维动态数组
	int MaxSize; //线性表的最大长度
	int Length; //当前线性表的长度
};