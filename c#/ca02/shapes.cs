public class Square : Shape
{
	private int side;
	
	public override double area
	{
		get{ return this.side * this.side;}
	}
	
	public Square(int side, string id) : base(id)
	{
		this.side = side;
	}
}