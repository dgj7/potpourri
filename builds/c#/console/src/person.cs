

class Person
{
	private string _name = "none";
	private int _age = 0;
	
	// read/write access of name
	public string Name
	{
		get
		{
			return _name;
		}
		set
		{
			_name = value;
		}
	}
	
	public int Age
	{
		get
		{
			return _age;
		}
		set
		{
			_age = value;
		}
	}
	
	public override string ToString(  )
	{
		return "Person=(name=" + _name + ", age=" + _age + ")";
	}
}



