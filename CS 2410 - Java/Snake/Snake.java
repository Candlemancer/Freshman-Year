// Jonathan Petersen
// A01236750
// CJA Project
// Main

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Snake extends JFrame implements ActionListener {
	
 	//Window Size
	public static final int HSIZE 	= 800;
	public static final int VSIZE 	= 610;
	public static final int GUIHSIZE = 100;
	public static final int GUIVSIZE = 570;

	//Gui Elements
	private 		Container 	pane 		= getContentPane();
	private 		JPanel		guiP		= new JPanel();
	private 		BoxLayout	winLayout	= new BoxLayout(pane, BoxLayout.LINE_AXIS);
	private 		BoxLayout	guiLayout	= new BoxLayout(guiP, BoxLayout.PAGE_AXIS);
	private 		JLabel 		title1		= new JLabel("-Serpentine-");
	private 		JLabel 		title2		= new JLabel("A Snake Game");
	private 		JLabel 		title3		= new JLabel("  By Jon P  ");
	private 		JLabel 		highLabel	= new JLabel("High Score: ");
	private 		JLabel 		scoreLabel	= new JLabel("Score: ");
	private 		JLabel 		segLabel	= new JLabel("Current Length:");
	public static 	JLabel		highVal		= new JLabel("");
	public static 	JLabel 		scoreVal	= new JLabel("");
	public static 	JLabel 		segVal		= new JLabel("5");
	public static 	JButton 	resetB		= new JButton("Reset");
	public static 	JButton 	exitB		= new JButton("Exit");

	//The Game Board
	private SnakeBoard board = new SnakeBoard();

	//Constructor
	public Snake() {


		//Configure Layouts
		pane.setLayout(winLayout);
		guiP.setLayout(guiLayout);

		//Add objects
		pane.add(board);
		pane.add(guiP);

		guiP.add(title1);
		guiP.add(title2);
		guiP.add(title3);
		guiP.add(Box.createRigidArea(new Dimension(0, 10)));
		guiP.add(highLabel);
		guiP.add(highVal);
		guiP.add(Box.createRigidArea(new Dimension(0, 10)));
		guiP.add(scoreLabel);
		guiP.add(scoreVal);
		guiP.add(Box.createRigidArea(new Dimension(0, 10)));
		guiP.add(segLabel);
		guiP.add(segVal);
		guiP.add(Box.createVerticalGlue());
		guiP.add(resetB);
		guiP.add(exitB);
		guiP.add(Box.createRigidArea(new Dimension(0, 10)));

		//Sizing
		this.setSize(HSIZE, VSIZE);
		board.setPreferredSize(new Dimension(SnakeBoard.HSIZE, SnakeBoard.VSIZE));
		guiP.setPreferredSize(new Dimension(GUIHSIZE, GUIVSIZE));

		//Add Listeners
		resetB.addActionListener(this);
		exitB.addActionListener(this);

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setTitle("Snake");	
		setResizable(false);
		setVisible(true);

		return;
	}

	//Handle Button Events
	public void actionPerformed(ActionEvent e) {

		if (e.getSource() == resetB) board.resetGame();
		if (e.getSource() == exitB) System.exit(0);

		return;
	}

	//Create a Snake Object
	public static void main(String[] args) {

		Snake snake = new Snake();

		return;
	}

}