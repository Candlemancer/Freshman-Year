// Jonathan Petersen
// A01236750
// CJA Project
// Snake Game Board

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Math.*;


public class SnakeBoard extends JPanel implements ActionListener {


	////////////////////////////////////////// DATA ///////////////////////////////////////////////

	//Graphics
	public static final int HSIZE 	= 700;
	public static final int VSIZE 	= 570;
	public static final int OBJSIZE = 10 ;
	public static final int MAXOBJS = 4200;
	private ImageIcon 	segmentPNG 	= new ImageIcon(this.getClass().getResource("Segment.jpg"));
	private ImageIcon 	applePNG	= new ImageIcon(this.getClass().getResource("Segment.jpg"));
	private Image 		segmentIMG  = segmentPNG.getImage();
	private Image 		appleIMG	= applePNG.getImage();

	//Game Mechanincs
	private static final int DELAY 	= 50;
	private static int 	score 		= 0;
	private static int 	highScore	= 50;
	private boolean 	gameOver 	= false;
	private Random 		random 		= new Random();
	private boolean 	left, right, up, down;
	private javax.swing.Timer timer;
	private int 		flash		= 6;


	//Snake Parts
	private int[] 		snakeX 		= new int [MAXOBJS];
	private int[] 		snakeY 		= new int [MAXOBJS];
	private int  		segments;

	//Apple Parts
	private int 		appleX;
	private int 		appleY;

	//////////////////////////////////////// FUNCTIONS ////////////////////////////////////////////

	//Constructor
	SnakeBoard() {
		super(false);

		//Setup the Keyboard Listeners
		KeyStroke u = KeyStroke.getKeyStroke(KeyEvent.VK_UP, 	0, true);
		KeyStroke d = KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 	0, true);
		KeyStroke l = KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, 	0, true);	
		KeyStroke r = KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, 0, true);

		this.registerKeyboardAction(this, "u", u, JComponent.WHEN_IN_FOCUSED_WINDOW);
		this.registerKeyboardAction(this, "d", d, JComponent.WHEN_IN_FOCUSED_WINDOW);
		this.registerKeyboardAction(this, "l", l, JComponent.WHEN_IN_FOCUSED_WINDOW);
		this.registerKeyboardAction(this, "r", r, JComponent.WHEN_IN_FOCUSED_WINDOW);

		//Setup the board and its objects
		//setSize(new Dimension(HSIZE, VSIZE));
		setBackground(Color.black);
		setFocusable(true);

		timer = new javax.swing.Timer(DELAY, this);
		timer.addActionListener(this);
		timer.start();

		resetGame();

		return;
	}

	//Move the snake on the board
	public void moveSnake() {

		//Iterate through each segment of the snake, moving it to where the last segement was
		for(int i=segments; i>0; i--) {
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}

		//Move the head to the new position
			 if (left) 		{ snakeX[0] -= OBJSIZE; }
		else if (right) 	{ snakeX[0] += OBJSIZE; }
		else if (up)		{ snakeY[0] -= OBJSIZE; }
		else if (down)		{ snakeY[0] += OBJSIZE; }

		//World Wrapping
		if (snakeX[0] >= HSIZE) 	{ snakeX[0] = 0;	 			return; }	
		if (snakeX[0] < 0) 			{ snakeX[0] = HSIZE - OBJSIZE; 	return; }	
		if (snakeY[0] > VSIZE) 		{ snakeY[0] = 0;	 			return; }	
		if (snakeY[0] < 0) 			{ snakeY[0] = VSIZE; 			return; }	

		return;
	}

	//Check if the snake ate itself
	public void isGameOver() {

		for(int i=4; i<segments; i++) {

			if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) gameOver = true;

		}

		return;
	}

	//Reset the game to the initial state
	public void resetGame() {

		//Stop The Timer
		timer.stop();

		//Reset Metrics
		gameOver = false;
		segments = 4;
		score = 0;
		flash = 6;

		Snake.segVal.setText(Integer.toString(segments));
		Snake.scoreVal.setText(Integer.toString(score));
		Snake.highVal.setText(Integer.toString(highScore));

		//Redraw the Snake
		for (int i=0; i<segments; i++) {
			snakeX[i] = 50 - (i * OBJSIZE);
			snakeY[i] = 50;
		}

		//Stop Movement
		left = false;
		right = true;
		down = false;
		up = false;

		//Generate Apple
		newApple();

		//Start Timer
		timer.start();

		return;
	}

	//Generate a new Apple
	public void newApple() {

		appleX = (int) (OBJSIZE * random.nextInt(HSIZE / OBJSIZE));
		appleY = (int) (OBJSIZE * random.nextInt(VSIZE / OBJSIZE));

		return;
	}

	//Check if someone got an apple
	public void gotApple() {

		if(snakeX[0] == appleX && snakeY[0] == appleY) {
			
			//Grow Snake
			segments += 3;
			Snake.segVal.setText(Integer.toString(segments));
			
			//Update Score
			score += 10;			
			Snake.scoreVal.setText(Integer.toString(score));
			
			if(score > highScore) {

				highScore = score;
				Snake.highVal.setText(Integer.toString(highScore));

			}

			newApple();
		}

		return;
	}

	//Draw all the objects!
	public void paintComponent(Graphics g) {

		super.paintComponent(g);

		if(!gameOver) {

			//Draw the apple
			g.drawImage(appleIMG, appleX, appleY, this);

			//Draw the snake
			for (int i=0; i<segments; i++) g.drawImage(segmentIMG, snakeX[i], snakeY[i], this);

		}

		else {

			//Clear Screen
			if (flash % 2 == 0) super.paintComponent(g);
			//Flash Snake
			if (flash % 2 == 1) 
				for (int i=0; i<segments; i++) g.drawImage(segmentIMG, snakeX[i], snakeY[i], this);

			//Draw the apple
			g.drawImage(appleIMG, appleX, appleY, this);
			
			flash--;
		}


		return;
	}

	//Handle Keys and Timer Events
	public void actionPerformed(ActionEvent e) {

		String command;

		if(e.getSource() == timer) {

			if (!gameOver) {

				gotApple();
				isGameOver();
				moveSnake();

			}

			else {



				
			}

			repaint();
			//System.out.print("X: " + Integer.toString(snakeX[0]) + " Y: " + Integer.toString(snakeY[0]) + ".\n");
		}

		else {

			command = e.getActionCommand();

			if(command.equals("u") && !down) 	{ left = false; right = false; 	up    = true; 	moveSnake(); return;}
			if(command.equals("d") && !up)		{ left = false; right = false; 	down  = true; 	moveSnake(); return;}
			if(command.equals("l") && !right)	{ down = false; up    = false; 	left  = true;  	moveSnake(); return;}
			if(command.equals("r") && !left)	{ down = false; up    = false; 	right = true; 	moveSnake(); return;}

		}

		return;
	}

}















