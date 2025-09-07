public class CommandLineArgumentInterpreter
{
	public static int Main( string[] args )
	{
		System.Console.WriteLine( "testing person class..." );
		
		Person person = new Person(  );
		
		// print out person details
		System.Console.WriteLine( "Person details: {0}", person );
		
		// set some values on person object
		person.Name = "Joe";
		person.Age = 99;
		System.Console.WriteLine( "Person details: {0}", person );
		
		// change values
		
		person.Name = "Dave";
		person.Age += 1;
		System.Console.WriteLine( "Person details: {0}", person );

		// signal success to os
		return 0;
	}
}
