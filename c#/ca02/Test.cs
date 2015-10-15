// A Hello World! program in C#. 
// 
namespace HelloWorld
{
	public struct CoOrds
	{
		
		private static int currentId;
		
		public int x, y;
		private int m;
		
		static CoOrds()
		{
			currentId = 0;
		}
		
		public int GetNextId()
		{
			return ++currentId;
		}
		
		public CoOrds(int p1, int p2)
		{
			this.x = p1;
			this.y = p2;
			this.m = this.y;
		}
	}
	
	class Hello
	{
		static void Main()
		{
			CoOrds co = new CoOrds();
			co.x = 10;
			CoOrds co2 = new CoOrds();
			
			System.Console.Write(co.GetNextId());
		}
	}
}

