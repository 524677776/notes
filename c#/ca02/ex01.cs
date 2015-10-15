// A Hello World! program in C#. 
using System;
namespace HelloWorld
{
	class Ex01
	{
		
		static void RefArray(int[] arr)
		{
			arr[0] = 11111;
		}
		
		static void Main()
		{
			
			int a  = 5;
			string s = "\"aaaaa\"";
			
			int[] array1 = { 1, 4, 5};
			int[,] array2 = {{3, 5}, {5,3}};
			
			string[] weekDays = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

			weekDays[0] = "abc";
			weekDays[1] = "abc1";
			
			RefArray(array1);
			
			Console.WriteLine("{0},{1}, {2}", array1[0], s, weekDays[0]);
			
			Console.ReadKey();
		}
	}
}