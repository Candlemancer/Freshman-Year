//Jonathan Petersen
//A01236750
//Chapter 5 Exercise 28
//Convert Inches to Centimeters.

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class InchConvert extends JFrame {

	private static final int WIDTH = 300;
	private static final int HEIGHT = 475;

	private int row = 15;
	private int col = 30;

	private	JTextArea convertTA = new JTextArea(row, col);
	private	JTextField convertTF = new JTextField(20);
	private	JButton convertB = new JButton("=");
	private	JButton exitB = new JButton("Exit");


	public InchConvert() {
		//Setup Window
		setTitle("Inches to Centimeters");
		setSize(WIDTH, HEIGHT);

		Container pane = getContentPane();
		pane.setLayout(null);

		//Setup GUI Elemenets
		convertTA.setLocation(10, 10);
		convertTF.setLocation(10, 350);
		convertB.setLocation(220, 350);
		exitB.setLocation(80, 400);

		convertTA.setSize(280, 330);
		convertTF.setSize(210, 40);
		convertB.setSize(70, 40);
		exitB.setSize(140, 40);

		convertTA.setText("Please input a length in inches\ninto the text box.\n");
		convertTA.setEditable(false);

		//Handle Events
		Handler eventHandler = new Handler();
		convertB.addActionListener(eventHandler);
		exitB.addActionListener(eventHandler);

		//Draw Window
		pane.add(convertTA);
		pane.add(convertTF);
		pane.add(convertB);
		pane.add(exitB);

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);

		return;
	}

	private class Handler implements ActionListener {

		int count = 0;

		public void actionPerformed(ActionEvent e) {

			if(e.getActionCommand().equals("=")) {
				if(count > 14) {
					convertTA.setText("");
					count = 0;
				}

				double inches = Double.parseDouble(convertTF.getText());
				double centimeters = inches * 2.54;

				convertTA.append( Double.toString(inches) + " inches is " +
								  Double.toString(centimeters) + " centimeters.\n");
			
				count++;
			}

			if(e.getActionCommand().equals("Exit")) System.exit(0);

		}

	}

	public static void main(String[] args) {

		InchConvert example = new InchConvert();

		return;
	}

}