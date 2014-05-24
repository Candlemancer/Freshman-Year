// Jonathan Petersen
// A01236750
// Chapter 8 Exercise 19
// LayoutGUI

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class LayoutGui extends JFrame implements ActionListener {

	private static int HSIZE = 800;
	private static int VSIZE = 600;

	private Container pane = getContentPane();

	//Label Definintions
	private JLabel label1 = new JLabel("Keep ");
	private JLabel label2 = new JLabel("Calm ");
	private JLabel label3 = new JLabel("and ");
	private JLabel label4 = new JLabel("Carry ");
	private JLabel label5 = new JLabel("On");

	//Menu Definitions
	private JMenuBar menuBar = new JMenuBar();
	private JMenu layouts = new JMenu("Layout");
	private JMenuItem flowLayout = new JMenuItem("Flow");
	private JMenuItem gridLayout = new JMenuItem("Grid");
	private JMenuItem bordLayout = new JMenuItem("Border");

	public LayoutGui() {

		//Set up window
		setTitle("Layout Options");
		setSize(HSIZE, VSIZE);
		
		//Set up menu
		setJMenuBar(menuBar);
		menuBar.add(layouts);
		layouts.add(flowLayout);
		layouts.add(gridLayout);
		layouts.add(bordLayout);
		flowLayout.addActionListener(this);
		gridLayout.addActionListener(this);
		bordLayout.addActionListener(this);

		//Set up pane
		pane.setLayout(new BorderLayout());
		pane.add(label1, BorderLayout.NORTH);
		pane.add(label2, BorderLayout.WEST);
		pane.add(label3, BorderLayout.CENTER);
		pane.add(label4, BorderLayout.EAST);
		pane.add(label5, BorderLayout.SOUTH);
		pane.setBackground(Color.red);
		label1.setFont(new Font("Arial", Font.BOLD, 48));
		label1.setForeground(Color.white);
		label2.setFont(new Font("Arial", Font.BOLD, 48));
		label2.setForeground(Color.white);
		label3.setFont(new Font("Arial", Font.BOLD, 48));
		label3.setForeground(Color.white);
		label4.setFont(new Font("Arial", Font.BOLD, 48));
		label4.setForeground(Color.white);
		label5.setFont(new Font("Arial", Font.BOLD, 48));
		label5.setForeground(Color.white);

		//And Display that sucker.
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);

		return;
	}

	public void actionPerformed(ActionEvent e) {

		if(e.getSource() == flowLayout) { pane.setLayout(new FlowLayout());   }
		if(e.getSource() == gridLayout) { pane.setLayout(new GridLayout());   }
		if(e.getSource() == bordLayout) { 
			pane.setLayout(new BorderLayout());
			pane.add(label1, BorderLayout.NORTH);
			pane.add(label2, BorderLayout.WEST);
			pane.add(label3, BorderLayout.CENTER);
			pane.add(label4, BorderLayout.EAST);
			pane.add(label5, BorderLayout.SOUTH);
		}

		pane.validate();
		pane.repaint();

		return;
	}


	public static void main(String[] args) {

		LayoutGui example = new LayoutGui();

		return;
	}

}