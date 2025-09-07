using System;
using System.Windows.Forms;
using System.Drawing;
using System.Collections.Generic;


public class GenericWindow : System.Windows.Forms.Form
{
	private List<System.Windows.Forms.Label> listLabel;
	private List<System.Windows.Forms.TextBox> listTextBox;
	private List<System.Windows.Forms.Button> listButton;
	private List<System.Windows.Forms.TabControl> listTabControl;
	private List<System.Windows.Forms.TabPage> listTabPage;
	
	
	
	// GenericWindowConstants, with the below PUBLIC static constant variables
	private const int GENWIN_CONTROL_LABEL = 0;
	private const int GENWIN_CONTROL_TEXTBOX = 1;
	private const int GENWIN_CONTROL_BUTTON = 2;
	private const int GENWIN_CONTROL_TABCONTROL = 3;
	private const int GENWIN_CONTROL_TABPAGE = 4;

	
	
	public GenericWindow(  )
	{
		listLabel = new List<Label>(  );
		listTextBox = new List<TextBox>(  );
		listButton = new List<Button>(  );
		listTabControl = new List<TabControl>(  );
		listTabPage = new List<TabPage>(  );
	}
	
	
	
	public int addLabel( string text, int xpos, int ypos, int width, int height )
	{
		Label lbl = new Label(  );
		lbl.Text = text;
		lbl.Location = new System.Drawing.Point( xpos, ypos );
		lbl.Size = new System.Drawing.Size( width, height );
		
		listLabel.Add( lbl );
		this.Controls.Add( lbl );
		
		return listLabel.Count - 1;
	}
	public Label getLabel( int identifier )
	{
		return listLabel[identifier];
	}
	
	
	
	public int addTextBox( int xpos, int ypos, int width, int height )
	{
		TextBox txt = new TextBox(  );
		txt.Location = new System.Drawing.Point( xpos, ypos );
		txt.Size = new System.Drawing.Size( width, height );
		
		listTextBox.Add( txt );
		this.Controls.Add( txt );
		
		return listTextBox.Count - 1;
	}
	public TextBox getTextBox( int identifier )
	{
		return listTextBox[identifier];
	}
	
	
	
	public int addButton( int xpos, int ypos, int width, int height )
	{
		Button button = new Button(  );
		button.Location = new System.Drawing.Point( xpos, ypos );
		button.Size = new System.Drawing.Size( width, height );
		
		listButton.Add( button );
		this.Controls.Add( button );
		
		return listButton.Count - 1;
	}
	public Button getButton( int identifier )
	{
		return listButton[identifier];
	}
	
	
	
	public int addTabControl( int xpos, int ypos, int width, int height )
	{
		TabControl tc = new TabControl(  );
		tc.Location = new System.Drawing.Point( xpos, ypos );
		tc.Size = new System.Drawing.Size( width, height );
		tc.SelectedIndex = 0;
		
		listTabControl.Add( tc );
		this.Controls.Add( tc );
		
		return listTabControl.Count - 1;
	}
	public TabControl getTabControl( int identifier )
	{
		return listTabControl[identifier];
	}
	
	
	
	public int addTabPage( int tabControl, string title )
	{
		TabPage tp = new TabPage( title );
		listTabControl[tabControl].Controls.Add( tp );
		
		listTabPage.Add( tp );
		
		return listTabPage.Count - 1;
	}
	public TabPage getTabPage( int identifier )
	{
		return listTabPage[identifier];
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// print an alert window (ok button only)
	/*
	public void alertMessageOk( string text )
	{
		MessageBox.Show( text, "Alert", MessageBoxButtons.OK, MessageBoxIcon.Exclamation );
	}
	*/
}



