#include "ToySoldiers.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define NUM 32
#define DIM 10

using namespace std;
 

//display the board
void display(gamePiece p[]){
    char d[DIM][DIM*4];
    int i,j;
    for(i=0;i<DIM;++i){
        for(j=0;j<DIM;++j){
            d[i][j*4+0]='-';
            d[i][j*4+1]='-';
            d[i][j*4+2]='-';
            d[i][j*4+3]=' ';
        }
    }


    for(i=0;i<NUM;++i){
        if(p[i].onBoard()){
            if(p[i].getProvince()==anjou) d[p[i].getY()][p[i].getX()*4+0]='a';
            if(p[i].getProvince()==flandre) d[p[i].getY()][p[i].getX()*4+0]='f';
            if(p[i].getProvince()==gascogne)d[p[i].getY()][p[i].getX()*4+0]='g';
            if(p[i].getProvince()==bretagne)d[p[i].getY()][p[i].getX()*4+0]='b';

            if(p[i].getNumElements()==1)d[p[i].getY()][p[i].getX()*4+1]='1';
            if(p[i].getNumElements()==2)d[p[i].getY()][p[i].getX()*4+1]='2';
            if(p[i].getNumElements()==3)d[p[i].getY()][p[i].getX()*4+1]='3';
            if(p[i].getNumElements()==4)d[p[i].getY()][p[i].getX()*4+1]='4';

            if(p[i].getDir()==U)d[p[i].getY()][p[i].getX()*4+2]='^';
            if(p[i].getDir()==L)d[p[i].getY()][p[i].getX()*4+2]='<';
            if(p[i].getDir()==D)d[p[i].getY()][p[i].getX()*4+2]='V';
            if(p[i].getDir()==R)d[p[i].getY()][p[i].getX()*4+2]='>';
        }
    }
    for(i=0;i<DIM;++i){
        for(j=0;j<DIM;++j){
            cout << d[i][j*4+0];
            cout << d[i][j*4+1];
            cout << d[i][j*4+2];
            cout << d[i][j*4+3];
        }
        cout << "\n";
        cout << "\n";
    }
    cout << "\n";

}

bool blocked(gamePiece p[], int m){
	int i;
	int x=p[m].getX();
	int y=p[m].getY();
	compassPoint d=p[m].getDir();
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y)return true;
	}
	return false;
}

intel getIntel(gamePiece p[], int m){
	intel sitRep;
	int i,dist,xdist,ydist;
	int x=p[m].getX();
	int y=p[m].getY();
	compassPoint d=p[m].getDir();

	//get inFront data;
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;
	sitRep.inFront = empty;
	sitRep.inFrontNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inFront=abyss;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y){
			sitRep.inFrontNum=p[i].getNumElements();
			if(p[i].getProvince()==p[m].getProvince())
				sitRep.inFront=ally;
			else
				sitRep.inFront=enemy;
		}
	}

	
	//get inRear data;
	if(d==U)y++;
	if(d==D)y--;
	if(d==L)x++;
	if(d==R)x--;
	sitRep.inRear = empty;
	sitRep.inRearNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inRear=abyss;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y){
			sitRep.inRearNum=p[i].getNumElements();
			if(p[i].getProvince()==p[m].getProvince())
				sitRep.inRear=ally;
			else
				sitRep.inRear=enemy;
		}
	}

	
	//get inLeft data;
	if(d==U)x--;
	if(d==D)x++;
	if(d==L)y++;
	if(d==R)y--;
	sitRep.inLeft = empty;
	sitRep.inLeftNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inLeft=abyss;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y){
			sitRep.inLeftNum=p[i].getNumElements();
			if(p[i].getProvince()==p[m].getProvince())
				sitRep.inLeft=ally;
			else
				sitRep.inLeft=enemy;
		}
	}

	
	//get inRight data;
	if(d==U)x++;
	if(d==D)x--;
	if(d==L)y--;
	if(d==R)y++;
	sitRep.inRight = empty;
	sitRep.inRightNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inRight=abyss;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y){
			sitRep.inRightNum=p[i].getNumElements();
			if(p[i].getProvince()==p[m].getProvince())
				sitRep.inRight=ally;
			else
				sitRep.inRight=enemy;
		}
	}

	
	//get nearestEnemy data;
	sitRep.nearestEnemyDir=U;
	sitRep.nearestEnemyDist=100;
	sitRep.nearestEnemyNum=100;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getProvince()!=p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(dist<sitRep.nearestEnemyDist){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.nearestEnemyDir=L;
					else sitRep.nearestEnemyDir=R;
				}else{
					if(ydist>0)sitRep.nearestEnemyDir=U;
					else sitRep.nearestEnemyDir=D;
				}
				sitRep.nearestEnemyDist=dist;
				sitRep.nearestEnemyNum=p[i].getNumElements();
			}
		}
	}
			
				
	//get weakestEnemy data;
	sitRep.weakestEnemyDir=U;
	sitRep.weakestEnemyDist=100;
	sitRep.weakestEnemyNum=100;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getProvince()!=p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i].getNumElements()<sitRep.weakestEnemyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.weakestEnemyDir=L;
					else sitRep.weakestEnemyDir=R;
				}else{
					if(ydist>0)sitRep.weakestEnemyDir=U;
					else sitRep.weakestEnemyDir=D;
				}
				sitRep.weakestEnemyDist=dist;
				sitRep.weakestEnemyNum=p[i].getNumElements();
			}
		}
	}
				
	//get strongestEnemy data;
	sitRep.strongestEnemyDir=U;
	sitRep.strongestEnemyDist=100;
	sitRep.strongestEnemyNum=0;
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getProvince()!=p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i].getNumElements()>sitRep.strongestEnemyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.strongestEnemyDir=L;
					else sitRep.strongestEnemyDir=R;
				}else{
					if(ydist>0)sitRep.strongestEnemyDir=U;
					else sitRep.strongestEnemyDir=D;
				}
				sitRep.strongestEnemyDist=dist;
				sitRep.strongestEnemyNum=p[i].getNumElements();
			}
		}
	}


	//get nearestAlly data;
	sitRep.nearestAllyDir=U;
	sitRep.nearestAllyDist=100;
	sitRep.nearestAllyNum=100;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i].onBoard()&&p[i].getProvince()==p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(dist<sitRep.nearestAllyDist){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.nearestAllyDir=L;
					else sitRep.nearestAllyDir=R;
				}else{
					if(ydist>0)sitRep.nearestAllyDir=U;
					else sitRep.nearestAllyDir=D;
				}
				sitRep.nearestAllyDist=dist;
				sitRep.nearestAllyNum=p[i].getNumElements();
			}
		}
	}
			
				
	//get weakestAlly data;
	sitRep.weakestAllyDir=U;
	sitRep.weakestAllyDist=100;
	sitRep.weakestAllyNum=100;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i].onBoard()&&p[i].getProvince()==p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i].getNumElements()<sitRep.weakestAllyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.weakestAllyDir=L;
					else sitRep.weakestAllyDir=R;
				}else{
					if(ydist>0)sitRep.weakestAllyDir=U;
					else sitRep.weakestAllyDir=D;
				}
				sitRep.weakestAllyDist=dist;
				sitRep.weakestAllyNum=p[i].getNumElements();
			}
		}
	}
				
	//get strongestAlly data;
	sitRep.strongestAllyDir=U;
	sitRep.strongestAllyNum=100;
	sitRep.strongestAllyDist=0;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i].onBoard()&&p[i].getProvince()==p[m].getProvince()){
			x=p[i].getX();
			y=p[i].getY();
			xdist=p[m].getX()-x;
			ydist=p[m].getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i].getNumElements()>sitRep.strongestAllyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.strongestAllyDir=L;
					else sitRep.strongestAllyDir=R;
				}else{
					if(ydist>0)sitRep.strongestAllyDir=U;
					else sitRep.strongestAllyDir=D;
				}
				sitRep.strongestAllyDist=dist;
				sitRep.strongestAllyNum=p[i].getNumElements();
			}
		}
	}

	return sitRep;

}
	


//make the piece in front of m suffer
void makeSuffer(gamePiece p[], int m, int hits){
	int i;
	//initialize x and y to the unit's location
	int x=p[m].getX();
	int y=p[m].getY();

	//move x and y to be in front of the unit's location
	compassPoint d=p[m].getDir();
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;

	//check to see if any living unit occupies space [x,y]
	for(i=0;i<NUM;++i){
		if(p[i].onBoard()&&p[i].getX()==x&&p[i].getY()==y)
			//if so, make it suffer
			p[i].suffer(hits);
	}

	return;
}


int main(){

    intel sitRep;
    gamePiece piece[NUM];
    int i,j;
    int m;
    recommendation r;
    int hits;
    char line[1024];
    bool done=false;

    srand(time(NULL));

    //set up the board -- deep breath now...
    gamePiece p00(1,1,R,4,gascogne);
    gamePiece p01(1,2,R,4,gascogne);
    gamePiece p02(1,3,R,4,gascogne);
    gamePiece p03(1,4,R,4,gascogne);
    gamePiece p04(1,5,R,4,gascogne);
    gamePiece p05(1,6,R,4,gascogne);
    gamePiece p06(1,7,R,4,gascogne);
    gamePiece p07(1,8,R,4,gascogne);
    gamePiece p24(8,1,L,4,anjou);
    gamePiece p25(8,2,L,4,anjou);
    gamePiece p26(8,3,L,4,anjou);
    gamePiece p27(8,4,L,4,anjou);
    gamePiece p28(8,5,L,4,anjou);
    gamePiece p29(8,6,L,4,anjou);
    gamePiece p30(8,7,L,4,anjou);
    gamePiece p31(8,8,L,4,anjou);
    piece[0]=p00;
    piece[1]=p01;
    piece[2]=p02;
    piece[3]=p03;
    piece[4]=p04;
    piece[5]=p05;
    piece[6]=p06;
    piece[7]=p07;
    piece[24]=p24;
    piece[25]=p25;
    piece[26]=p26;
    piece[27]=p27;
    piece[28]=p28;
    piece[29]=p29;
    piece[30]=p30;
    piece[31]=p31;

    // ... whew!
    display(piece);
    cin.getline(line,1023);


    // pick a piece, ask for its recommendation, and order it to do that
    while(!done){
        //m=rand()%NUM;
	for(m=0;m<NUM;++m){
        	if(piece[m].onBoard()){
            		sitRep=getIntel(piece,m);
            		r=piece[m].recommend(sitRep);
            		switch(r){
            			case nothing: break;
                		case lft: piece[m].turnLeft(); break;
                		case rght: piece[m].turnRight(); break;
                		case rear: piece[m].aboutFace(); break;
                		case goforward: 
					piece[m].moveForward();
					if(piece[m].getX()<0||piece[m].getX()>=DIM)piece[m].die();
					if(piece[m].getY()<0||piece[m].getY()>=DIM)piece[m].die();
					break;
                		case attck: 
					hits=piece[m].attack();
					makeSuffer(piece,m,hits);
					break;
            		}
            		if(line[0]=='q')done=true;
        	  }
          }
          display(piece);
          cin.getline(line,1023);
    }
    return 0;
}

 
