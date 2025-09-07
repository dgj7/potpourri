using System;




public class SearchWindow : GenericWindow
{
	int firstLabel = 0;
	int firstTextBox = 0;
	int firstButton = 0;
	int firstTabControl = 0;
	int firstTabPage = 0;
	int secondTabPage = 0;

	public SearchWindow( string title )
	{
		// configure the window itself - title, size, location, etc
		this.Text = title;
		this.Width = 800;
		this.Height = 600;
		
		// add widgets
		firstLabel = this.addLabel( "here is some text!", 0, 0, 100, 40 );
		firstTextBox = this.addTextBox( 0, 40, 100, 20 );
		firstButton = this.addButton( 0, 60, 100, 100 );
		firstTabControl = this.addTabControl( 150, 0, 200, 500 );
		firstTabPage = this.addTabPage( firstTabControl, "tab page title" );
		secondTabPage = this.addTabPage( firstTabControl, "second" );
		
		
		
		// modify widget states
		this.getLabel( firstLabel ).Text = "modified label text!!!";
		this.getButton( firstButton ).Text = "click to view text in the text box!";
		//this.getButton( firstButton ).Click += firstButtonHandler;
		
		
		// add a button to 2nd tab page
		System.Windows.Forms.Button btn = new System.Windows.Forms.Button(  );
		btn.Text = "button here";
		this.getTabPage( secondTabPage ).Controls.Add( btn );
	}
	
	/*
	private void firstButtonHandler( System.Object sender, RoutedEventArgs e )
	{
		//
	}
	*/
}