public class BaseClass
{
    public virtual void DoWork()
	{
		System.Console.WriteLine("BaseClass DoWork");
	}
	
	public virtual int WorkProperty
	{
		get{ return 0;}
	}
}

public class DerivedClass : BaseClass
{
		public new void DoWork()
		{
			System.Console.WriteLine("DerivedClass DoWork");
		}
		
		public override int WorkProperty
		{
			get{return 10;}
		}
}

class Hello
{
	static void Main()
	{
		DerivedClass dc = new DerivedClass();
		BaseClass bc = new BaseClass();
		
		bc = (BaseClass)dc;
		
		dc.DoWork();
		bc.DoWork();
		
		System.Console.WriteLine(dc.WorkProperty);
	}
}