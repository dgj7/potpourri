using System.Windows.Forms;

public class MainProgram
{
	public static int Main( string[] args )
	{
		// run the application
		Application.Run( new SearchWindow( "here's the window title" ) );
		
		// signal success to os
		return 0;
	}
}



