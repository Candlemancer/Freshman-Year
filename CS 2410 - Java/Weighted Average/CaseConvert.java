//Jonathan Petersen
//A01236750
//CH04 EX22
//Case Conversion

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CaseConvert extends JFrame {

	public static final int WIDTH = 150;
	public static final int HEIGHT = 75;

	//Constructor
	public CaseConvert() {

		setTitle("Alpha");

		text.addActionListener(txtH);

		pane.setLayout(new GridLayout(1, 1));
		pane.add(text);

		setSize(WIDTH, HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		return;
	}

	//Main
	public static void main(String[] args) {

		CaseConvert convert = new CaseConvert();

		return;
	}

	//Variables for the window
	private Container  pane = getContentPane();
	private JTextField text = new JTextField();
	private TextHandle txtH = new TextHandle();

	//What to do when enter is pressed.
	private class TextHandle implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			//Rip apart the string into characters.
			String input = text.getText();
			char[] convert = input.toCharArray();
			String output;
		
			for(int i=0; i<convert.length; i++) {

				char swap = convert[i];

				if(Character.isUpperCase(swap)) convert[i] = Character.toLowerCase(swap);
				if(Character.isLowerCase(swap)) convert[i] = Character.toUpperCase(swap);

			}

			//Reconstruct the string and display.
			output = new String(convert);
			text.setText(output);

		}

	}


}