//Jonathan Petersen
//A01236750
//Dumb Stoplight

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH03_EX12 extends JFrame {

	private JButton stop, look, go, red, yellow, green;

	private StopButtonHandler 	sHandler;
	private LookButtonHandler 	lHandler;
	private GoButtonHandler 	gHandler;
	private RedButtonHandler 	rHandler;
	private YellowButtonHandler yHandler;
	private GreenButtonHandler 	nHandler;

	private Container pane;

	private static final int WIDTH = 350;
	private static final int HEIGHT = 100;

	public CH03_EX12() {

		//Create the buttons
		stop = new JButton("Stop");
		sHandler = new StopButtonHandler();
		stop.addActionListener(sHandler);

		look = new JButton("Look");
		lHandler = new LookButtonHandler();
		look.addActionListener(lHandler);

		go = new JButton("Go");
		gHandler = new GoButtonHandler();
		go.addActionListener(gHandler);

		red = new JButton("Red");
		rHandler = new RedButtonHandler();
		red.addActionListener(rHandler);

		yellow = new JButton("Yellow");
		yHandler = new YellowButtonHandler();
		yellow.addActionListener(yHandler);

		green = new JButton("Green");
		nHandler = new GreenButtonHandler();
		green.addActionListener(nHandler);

		//Now create the window.
		setTitle("Stoplight");
		pane = getContentPane();
		pane.setLayout(new GridLayout(2, 3));
		pane.add(red);
		pane.add(yellow);
		pane.add(green);
		pane.add(stop);
		pane.add(look);
		pane.add(go);

		//And display it.
		setSize(WIDTH, HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

	}

	private class StopButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.red);
			yellow.setBackground(Color.white);
			green.setBackground(Color.white);
		}
	}

	private class LookButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.white);
			yellow.setBackground(Color.yellow);
			green.setBackground(Color.white);
		}
	}

	private class GoButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.white);
			yellow.setBackground(Color.white);
			green.setBackground(Color.green);
		}
	}

	private class RedButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.red);
			yellow.setBackground(Color.white);
			green.setBackground(Color.white);
		}
	}

	private class YellowButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.white);
			yellow.setBackground(Color.yellow);
			green.setBackground(Color.white);
		}
	}

	private class GreenButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			red.setBackground(Color.white);
			yellow.setBackground(Color.white);
			green.setBackground(Color.green);
		}
	}

	public static void main(String[] args) {
		CH03_EX12 demoObject = new CH03_EX12();
	}

}