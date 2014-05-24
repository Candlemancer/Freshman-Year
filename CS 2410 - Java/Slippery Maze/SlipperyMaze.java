// Jonathan Petersen
// A01236750
// Slippery Maze
// Main Class

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

public class SlipperyMaze {

	public static void main(String[] args) {

		//Create Game Board
		GameBoard gameBoard = new GameBoard();

		//Run Game
		gameBoard.setup(1);

		return;
	}

	static class GameBoard extends JFrame implements ActionListener {

		//Data Members
		private static final int HSIZE 	= 800;
		private static final int VSIZE 	= 600;

		private int 		rows 		= 5;
		private int 		cols 		= 5;
		private int 		level 		= 1;

		private Container 	pane 		= getContentPane();
		private JPanel		boardPanel 	= new JPanel();
		private JPanel		menuPanel 	= new JPanel();
		private JButton 	reset 		= new JButton("Reset");
		private JButton 	board[][];

		private Random 		random 		= new Random();
		private int 		xpos, ypos, xini, yini, xfin, yfin;

		GameBoard() {	

			//////////////////////////////////// GUI /////////////////////////////////////////

			//Initialize the Window
			setTitle("SlipperyMaze");
			setSize(HSIZE, VSIZE);

			//Setup the Layouts
			boardPanel.setLayout(	new GridLayout(rows, cols));
			menuPanel.setLayout(	new BoxLayout (menuPanel, BoxLayout.PAGE_AXIS));
			pane.setLayout(			new BoxLayout (pane,	  BoxLayout.LINE_AXIS));

			//Add things to the primary pane
			pane.add(boardPanel);
			pane.add(menuPanel);

			//Add things to the menu
			menuPanel.add(reset);
			reset.addActionListener(this);

			///////////////////////////////// GAME LOGIC /////////////////////////////////////

			//Setup the Keyboard Listeners
			KeyStroke 	u 			= KeyStroke.getKeyStroke(KeyEvent.VK_UP, 	0, true);
			KeyStroke 	d 			= KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 	0, true);
			KeyStroke 	l 			= KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, 	0, true);	
			KeyStroke 	r 			= KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, 0, true);

			boardPanel.registerKeyboardAction(this, "u", u, JComponent.WHEN_IN_FOCUSED_WINDOW);
			boardPanel.registerKeyboardAction(this, "d", d, JComponent.WHEN_IN_FOCUSED_WINDOW);
			boardPanel.registerKeyboardAction(this, "l", l, JComponent.WHEN_IN_FOCUSED_WINDOW);
			boardPanel.registerKeyboardAction(this, "r", r, JComponent.WHEN_IN_FOCUSED_WINDOW);


			//Create a 5x5
			board = new JButton[rows][cols];

			for (int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++) {

					board[i][j] = new JButton("");
					boardPanel.add(board[i][j]);	
					board[i][j].addActionListener(this);
					board[i][j].setActionCommand(Integer.toString(i) + Integer.toString(j));

				}
			}

			//Draw the Board
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			setVisible(true);
			requestFocusInWindow();	

			return;
		}

		public void setup(int level) {

			/*
			xfin = random.nextInt(cols);
			yfin = random.nextInt(rows);
			while (xpos == xfin) xpos = random.nextInt(cols);
			while (ypos == yfin) ypos = random.nextInt(rows);
			xini = xpos;
			yini = ypos;

			board[yfin][xfin].setText("Exit");
			board[ypos][xpos].setText("Hero");

			for (int i=0; i<rows; i++) {
				for (int j=0; j<cols; j++) {

					if (board[i][j].getText() == "" && random.nextInt(2) == 1) board[i][j].setText("[ ]");

				}
			}

			board[yfin][xfin].setText("Exit");
			xpos = xini;
			ypos = yini;
			board[ypos][xpos].setText("Hero");
			*/

			if (level == 1) {

				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						board[i][j].setText("");
						board[i][j].setVisible(true);
					
					}

				}

				board[1][1].setText("Exit");
				xfin = 1;
				yfin = 1;
				board[1][2].setText("[ ]");
				board[2][0].setText("[ ]");
				board[2][1].setText("[ ]");
				board[2][4].setText("[ ]");
				board[4][2].setText("[ ]");
				board[4][4].setText("Hero");
				ypos = 4;
				xpos = 4;

				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						if(i < ypos - 1 || i > ypos + 1) board[i][j].setVisible(false);
						if(j < xpos - 1 || j > xpos + 1) board[i][j].setVisible(false);

					}

				}

			}

			if (level == 2) {

				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						board[i][j].setText("");
						board[i][j].setVisible(true);
					
					}

				}

				board[4][0].setText("Exit");
				xfin = 0;
				yfin = 4;
				board[0][2].setText("[ ]");
				board[1][0].setText("[ ]");
				board[2][4].setText("[ ]");
				board[2][1].setText("[ ]");
				board[4][1].setText("[ ]");
				board[1][1].setText("Hero");
				ypos = 1;
				xpos = 1;

				
				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						if(i < ypos - 1 || i > ypos + 1) board[i][j].setVisible(false);
						if(j < xpos - 1 || j > xpos + 1) board[i][j].setVisible(false);

					}

				}
				

			}

			if (level == 3) {

				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						board[i][j].setText("");
						board[i][j].setVisible(true);
					
					}

				}

				board[0][4].setText("Exit");
				xfin = 4;
				yfin = 0;
				board[0][3].setText("[ ]");
				board[2][4].setText("[ ]");
				board[3][0].setText("[ ]");
				board[3][1].setText("[ ]");
				board[4][0].setText("Hero");
				ypos = 4;
				xpos = 0;

				
				for (int i=0; i<rows; i++) {
					for (int j=0; j<rows; j++) {

						if(i < ypos - 1 || i > ypos + 1) board[i][j].setVisible(false);
						if(j < xpos - 1 || j > xpos + 1) board[i][j].setVisible(false);

					}

				}
				
			}

			if (level > 3) System.exit(0);

			return;
		}

		private void moveHero(int x, int y) {

			//Vertical Movement
			if (y < ypos) {
				while (ypos > 0 && board[ypos - 1][xpos].getText() != "[ ]") {

					board[ypos][xpos].setText("");
					ypos--;
					board[ypos][xpos].setText("Hero");

				}

				return;
			}

			if (y > ypos) {
				while (ypos < rows - 1 && board[ypos + 1][xpos].getText() != "[ ]") {

					board[ypos][xpos].setText("");
					ypos++;
					board[ypos][xpos].setText("Hero");

				}

				return;
			}

			//Horizontal Movement
			if (x < xpos) {
				while (xpos > 0 && board[ypos][xpos - 1].getText() != "[ ]") {

					board[ypos][xpos].setText("");
					xpos--;
					board[ypos][xpos].setText("Hero");

				}

				return;
			}

			if (x > xpos) {
				while (xpos < cols - 1 && board[ypos][xpos + 1].getText() != "[ ]") {

					board[ypos][xpos].setText("");
					xpos++;
					board[ypos][xpos].setText("Hero");

				}

				return;
			}

			return;	
		}

		/*
		private void moveHero(int x, int y, String s) {

			if (board[ypos][xpos].getText() == "Exit") return;

			if(ypos > y)	{ while (ypos > y) {

								board[ypos][xpos].setText(s);
								ypos--;
								//System.out.print(".");

							} return; }

			else if(ypos < y)	{ while (ypos < y) {

								board[ypos][xpos].setText(s);
								ypos++;
								//System.out.print(".");

							} return; }

			if(xpos > x)	{ while (xpos > x) {

								board[ypos][xpos].setText(s);
								xpos--;
								//System.out.print(".");
							} return; }

			else if(xpos < x)	{ while (xpos < x) {

								board[ypos][xpos].setText(s);
								xpos++;
								//System.out.print(".");

							} return; }

			return;	
		}
		*/

		public void actionPerformed(ActionEvent e) {

			String direction;
			String coords;
			int x, y;

			if(e.getSource() == reset) {

				setup(level);
				
				return;
			}

			if(e.getSource() instanceof JButton) {
			
				coords = e.getActionCommand();
				y = Integer.parseInt(coords.substring(0,1));
				x = Integer.parseInt(coords.substring(1,2));	
				moveHero(x, y);
				
			}

			direction = e.getActionCommand();
			if(direction.equals("u")) moveHero(xpos, 0);
			if(direction.equals("d")) moveHero(xpos, rows - 1);
			if(direction.equals("l")) moveHero(0, ypos);
			if(direction.equals("r")) moveHero(cols - 1, ypos);

			requestFocusInWindow();

			for (int i=0; i<rows; i++) {
				for (int j=0; j<rows; j++) {

					board[i][j].setVisible(true);

					if(i < ypos - 1 || i > ypos + 1) board[i][j].setVisible(false);
					if(j < xpos - 1 || j > xpos + 1) board[i][j].setVisible(false);

				}

			}

			if(xpos == xfin && ypos == yfin) { System.out.print("You solved level " + level + "! Congrats!\n"); setup(++level); }

			return;
		}	

		
		/* Well, this was version 2 and it still doesn't work. Too many trivial solutions, among other things.
		private void generate(int xfin, int yfin, int xpos, int ypos, int dir) {

			//Base Case
			if(xpos == xfin && ypos == yfin) { System.out.print("Base case.\n"); return; }

			System.out.print("Dir: " + dir + ".\n");

			//Generate a block to hit
			switch (dir) {
				case 0: //Move Up
					len = random.nextInt(rows); // How many squares to move

					//Move up each square, making sure you don't overflow.
					while (ypos != 0 && len != 0) {
						if(board[ypos][xpos].getText() == "[ ]") break;
						if(board[ypos][xpos].getText() != "Hero" || board[ypos][xpos].getText() != "Exit") board[ypos][xpos].setText(" ");
						ypos--;
						len--;
					}
					if(board[ypos][xpos].getText() == "[ ]") ypos++;
					System.out.print("Xpos: " + xpos + " Ypos: " + ypos + ".\n");

					//Make a block in front of you, if needed.
					if (ypos != 0 && ypos != rows - 1) {
						if(board[ypos - 1][xpos].getText() ==     "") { board[ypos - 1][xpos].setText("[ ]");			} //Standard Block
						if(board[ypos - 1][xpos].getText() ==    " ") { board[ypos][xpos].setText("[ ]"); 		ypos++; } //It's a path. Move back one and block.
						if(board[ypos - 1][xpos].getText() ==  "[ ]") ;
						if(board[ypos - 1][xpos].getText() == "Exit") { generate(xfin, yfin, xpos, ypos - 1, 0); }
					}

					generate(xfin, yfin, xpos, ypos, random.nextInt(2) + 2);					
					break;

				case 1: //Move Down
					len = random.nextInt(rows); // How many squares to move

					//Move down each square, making sure you don't overflow.
					while (ypos != rows - 1 && len != 0) {
						if(board[ypos][xpos].getText() == "[ ]") break;
						if(board[ypos][xpos].getText() != "Hero" || board[ypos][xpos].getText() != "Exit") board[ypos][xpos].setText(" ");
						ypos++;
						len--;
					}
					if(board[ypos][xpos].getText() == "[ ]") ypos--;
					System.out.print("Xpos: " + xpos + " Ypos: " + ypos + ".\n");

					//Make a block in front of you, if needed.
					if (ypos != 0 && ypos != rows - 1) {
						if(board[ypos + 1][xpos].getText() ==     "") { board[ypos + 1][xpos].setText("[ ]");			} //Standard Block
						if(board[ypos + 1][xpos].getText() ==    " ") { board[ypos][xpos].setText("[ ]"); 		ypos--; } //It's a path. Move back one and block.
						if(board[ypos + 1][xpos].getText() ==  "[ ]") ;
						if(board[ypos + 1][xpos].getText() == "Exit") { generate(xfin, yfin, xpos, ypos + 1, 0); }
					}

					generate(xfin, yfin, xpos, ypos, random.nextInt(2) + 2);					
					break;

				case 2: //Move Right
					len = random.nextInt(cols); // How many squares to move

					//Move up each square, making sure you don't overflow.
					while (xpos != cols - 1 && len != 0) {
						if(board[ypos][xpos].getText() == "[ ]") break;
						if(board[ypos][xpos].getText() != "Hero" || board[ypos][xpos].getText() != "Exit") board[ypos][xpos].setText(" ");
						xpos++;
						len--;
					}
					if(board[ypos][xpos].getText() == "[ ]") xpos--;
					System.out.print("Xpos: " + xpos + " Ypos: " + ypos + ".\n");

					//Make a block in front of you, if needed.
					if (xpos != 0 && xpos != cols - 1) {
						if(board[ypos][xpos + 1].getText() ==     "") { board[ypos][xpos + 1].setText("[ ]");			} //Standard Block
						if(board[ypos][xpos + 1].getText() ==    " ") { board[ypos][xpos].setText("[ ]"); 		xpos--; } //It's a path. Move back one and block.
						if(board[ypos][xpos + 1].getText() ==  "[ ]") ;
						if(board[ypos][xpos + 1].getText() == "Exit") { generate(xfin, yfin, xpos + 1, ypos, 0); }
					}

					generate(xfin, yfin, xpos, ypos, random.nextInt(2));
					break;

				case 3: //Move Left
					len = random.nextInt(cols); // How many squares to move

					//Move up each square, making sure you don't overflow.
					while (xpos != 0 && len != 0) {
						if(board[ypos][xpos].getText() == "[ ]") break;
						if(board[ypos][xpos].getText() != "Hero" || board[ypos][xpos].getText() != "Exit") board[ypos][xpos].setText(" ");
						xpos--;
						len--;
					}
					if(board[ypos][xpos].getText() == "[ ]") xpos++;
					System.out.print("Xpos: " + xpos + " Ypos: " + ypos + ".\n");

					//Make a block in front of you, if needed.
					if (xpos != 0 && xpos != cols - 1) {
						if(board[ypos][xpos - 1].getText() ==     "") { board[ypos][xpos - 1].setText("[ ]");			} //Standard Block
						if(board[ypos][xpos - 1].getText() ==    " ") { board[ypos][xpos].setText("[ ]"); 		xpos++; } //It's a path. Move back one and block.
						if(board[ypos][xpos - 1].getText() ==  "[ ]") ;
						if(board[ypos][xpos - 1].getText() == "Exit") { generate(xfin, yfin, xpos - 1, ypos, 0); }
					}

					generate(xfin, yfin, xpos, ypos, random.nextInt(2));
					break;

			}

			return;
		}
		*/
		/*
		private void makePath(int xfin, int yfin, int xpos, int ypos) {

			//Base Case
			if(xpos == xfin && ypos == yfin) {System.out.print("Base\n"); return; }

			//Alternative Cases
			dir = !dir;
			if (dir) { moveHero(xfin, ypos, "X"); }
			else	 { moveHero(xpos, yfin, "X"); }

			System.out.print(" X: " + xpos + " Y: " + ypos + " Dir: " + dir + "\n");

			makePath(xfin, yfin, xpos, ypos);

			return;
		}
		*/
	}


}