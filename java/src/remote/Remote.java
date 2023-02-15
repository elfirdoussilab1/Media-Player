package Remote;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class Remote extends JFrame{
	
	private static final long serialVersionUID = 1L;
	
	// This Frame contains 3 buttons and one textArea
	
	JTextArea textArea;
	
	JButton button1, button2, button3;
	
	// We will put these elements in Panels
	
	JPanel panel1 = new JPanel();
	JPanel panel2 = new JPanel();
	
	
	public static void main(String argv[]) {
		Remote remote = new Remote("Remote control");
	}
	
	
	public Remote(String name) {
		super("Remote control");
		
		// Adding buttons to the first panel.
		
		setLayout(new BorderLayout());
		
		panel1.add(button1 = new JButton("Button1"), BorderLayout.WEST);
		panel1.add(button2 = new JButton("Button2"), BorderLayout.CENTER);
		panel1.add(button3 = new JButton("Button3"), BorderLayout.EAST);
		
		// Adding the First panel in the SOUTH of the Frame
		
		add(panel1, BorderLayout.SOUTH);
		
		// Adding the TextArea to the second Panel
		
		panel2.add(textArea = new JTextArea("Enter here", 10, 50), BorderLayout.CENTER);
		add(panel2, BorderLayout.CENTER);
		
		// connecting buttons to their listeners
		button1.addActionListener(new Button1Listener());
		button2.addActionListener(new Button2Listener());
		button3.addActionListener(new Button3Listener());
		// Setting default functions related to our Frame
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
		
	}
	
	// Now we will create inner classes that implements the interface ActionListener 
	
	class Button1Listener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			
			// we will add a new row, and then insert our text in that row
			int nRows = textArea.getRows();
			textArea.setRows(nRows + 1);
			textArea.append("Je suis créé par le premier bouton \n");
			
		}
		
	}
	class Button2Listener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			
			// we will add a new row, and then insert our text in that row
			int nRows = textArea.getRows();
			textArea.setRows(nRows + 1);
			textArea.append("Je suis créé par le deuxième bouton \n");
			
		}
	}
	class Button3Listener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
			
		}
	}
	
	
	
}
