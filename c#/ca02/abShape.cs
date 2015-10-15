public abstract class Shape
{
    private string name;
	
	public string id
	{
		get{ return this.name; }
		set{ name = value; }
	}
	
	public abstract double area
	{
		get;
	}
	
	public Shape(string s)
	{
		this.id = s;
	}
	
	public override string ToString()
	{
		return this.id + "Area= " + string.Format("{0:F2}", this.area);
	}
}
