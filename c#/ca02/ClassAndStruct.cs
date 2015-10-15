//类和结构  数据结构 一组整体 作为一个逻辑单位的数据和行为
//1. 声明
//2. 引用类型
//3. 
// Person p1 = new Person(); p2 = p1; 

public class Person
{
		public int number{ get; set;}
		public Person()
		{
			number = 0;
		}
}

class MyClass{
	static void Main()
	{
		Person p1,p2; 
		p1 = new Person();
		p2 = p1;
		p2.number =  10;
		System.Console.WriteLine("number = " + p1.number);
	}
}