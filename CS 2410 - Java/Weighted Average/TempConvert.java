//Jonathan Petersen
//A01236750
//CH04 EX26
//Temperature Conversion

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TempConvert extends JFrame {

	//Setup of the GUI window. Lavels on top, then text, then buttons.
	private Container pane = getContentPane();

	private JLabel fahL = new JLabel("Fahrenheit", SwingConstants.CENTER);
	private JLabel celL = new JLabel("Celsius"	 , SwingConstants.CENTER);

	//Two boxes for input.
	private JTextField fahTF = new JTextField(10);
	private JTextField celTF = new JTextField(10);

	private FahHandler fahH = new FahHandler();
	private CelHandler celH = new CelHandler();

	private static final int WIDTH = 325;
	private static final int HEIGHT = 150;


	//Constructors
	public TempConvert() {

		setTitle("Temperature Conversion");

		fahTF.addActionListener(fahH);
		celTF.addActionListener(celH);

		pane.setLayout(new GridLayout(2, 2));

		pane.add(fahL);
		pane.add(celL);
		pane.add(fahTF);
		pane.add(celTF);

		setSize(WIDTH, HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		return;
	}

	private class FahHandler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			//Convert to Celsius
			double toConvert = Double.parseDouble(fahTF.getText());

			toConvert = (toConvert - 32.0) * (5.0/9.0);
			celTF.setText(Double.toString(toConvert));

			return;
		}

	}

	private class CelHandler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			//Convert to Fahrenheit
			double toConvert = Double.parseDouble(celTF.getText());

			toConvert = (toConvert * (9.0/5.0)) + 32.0 ;
			fahTF.setText(Double.toString(toConvert));

			return;
		}

	}



	public static void main(String[] args) {

		TempConvert window = new TempConvert();
		return;
	}

}