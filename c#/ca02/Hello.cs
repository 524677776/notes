// A Hello World! program in C#. 
using System;
using System.Collections.Generic;

namespace HelloWorld
{
	class Shape
	{
		public virtual void Draw()
		{
			Console.WriteLine("Shape Draw");
		}
	}
	
	class Rectangle : Shape
	{
		public override void Draw()
		{
			Console.WriteLine("Rectangle Draw");
		}
	}
	
	class Circle : Shape
	{
		public override void Draw()
		{
			Console.WriteLine("Circle Draw");
		}
	}
	
	class Triangle : Shape
	{
		public override void Draw()
		{
			Console.WriteLine("Triangle Draw");
		}
	}
	
	class Hello
	{
		static void Main()
		{
			List<Shape> shapes = new List<Shape>();
			shapes.Add(new Rectangle());
			shapes.Add(new Triangle());
			shapes.Add(new Circle());
			
			foreach (Shape s in shapes)
		   {
			   s.Draw();
		   }
   
			// Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
			Console.ReadKey();
		}
	}
}