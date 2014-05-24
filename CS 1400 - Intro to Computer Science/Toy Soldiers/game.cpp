#include "toy.h"
#include "dww.h"
#include "jlw.h"
#include "guy.h"
#include "aaa.h"
#include "abr.h"
#include "awn.h"
#include "bio.h"
#include "bne.h"
#include "bom.h"
#include "chz.h"
#include "dbg.h"
#include "dmx.h"
#include "edc.h"
#include "gen.h"
#include "hmd.h"
#include "jam.h"
#include "jax.h"
#include "jds.h"
#include "jeh.h"
#include "jkp.h"
#include "jsh.h"
#include "kap.h"
#include "mas.h"
#include "mis.h"
#include "moo.h"
#include "nub.h"
#include "nyx.h"
#include "pbj.h"
#include "pwn.h"
#include "qed.h"
#include "ray.h"
#include "sah.h"
#include "scm.h"
#include "sgt.h"
#include "snl.h"
#include "sol.h"
#include "tdb.h"
#include "the.h"
#include "tjc.h"
#include "trs.h"
#include "win.h"
#include "wmd.h"
#include "wrs.h"
#include "wtf.h"
#include "wwf.h"
#include "zim.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define NUM 32
#define DIM 10
#define NUMTLAS 47

using namespace std;

char tla1[1024];
char tla2[1024];
char tla3[1024];
char tla4[1024];
 
char * tlalist[47]={
"aaa",
"abr",
"awn",
"bio",
"bne",
"bom",
"chz",
"dbg",
"dmx",
"dww",
"edc",
"gen",
"guy",
"hmd",
"jam",
"jax",
"jds",
"jeh",
"jkp",
"jlw",
"jsh",
"kap",
"mas",
"mis",
"moo",
"nub",
"nyx",
"pbj",
"pwn",
"qed",
"ray",
"sah",
"scm",
"sgt",
"snl",
"sol",
"tdb",
"the",
"tjc",
"trs",
"toy",
"win",
"wmd",
"wrs",
"wtf",
"wwf",
"zim"
};




intel getIntel(gamePiece *p[], int m);

//display the board
void display(gamePiece *p[]){
    char d[DIM*2][DIM*5];
    int i,j;
    recommendation r;
    intel s;
    //warning: major geekiness follows

    //make a big character array and fill it with 'blank' spaces
    //each blank space is 4 chars wide and looks like "--- "
    for(i=0;i<DIM;++i){
        for(j=0;j<DIM;++j){
            d[i*2][j*5+0]='-';
            d[i*2][j*5+1]='-';
            d[i*2][j*5+2]='-';
            d[i*2][j*5+3]=' ';
            d[i*2][j*5+4]=' ';

            d[i*2+1][j*5+0]=' ';
            d[i*2+1][j*5+1]=' ';
            d[i*2+1][j*5+2]=' ';
            d[i*2+1][j*5+3]=' ';
            d[i*2+1][j*5+4]=' ';
        }
    }

    //figure out which spaces are no blank, and fill in with 
    //appropriate information
    for(i=0;i<NUM;++i){
        if(p[i]->onBoard()){
            if(p[i]->getProvince()==gascogne){
		d[p[i]->getY()*2][p[i]->getX()*5+0]=tla1[0];
		d[p[i]->getY()*2][p[i]->getX()*5+1]=tla1[1];
		d[p[i]->getY()*2][p[i]->getX()*5+2]=tla1[2];
            }
            if(p[i]->getProvince()==anjou){
		d[p[i]->getY()*2][p[i]->getX()*5+0]=tla2[0];
		d[p[i]->getY()*2][p[i]->getX()*5+1]=tla2[1];
		d[p[i]->getY()*2][p[i]->getX()*5+2]=tla2[2];
            }
          
            if(p[i]->getProvince()==flandre){
		d[p[i]->getY()*2][p[i]->getX()*5+0]=tla3[0];
		d[p[i]->getY()*2][p[i]->getX()*5+1]=tla3[1];
		d[p[i]->getY()*2][p[i]->getX()*5+2]=tla3[2];
            }
            if(p[i]->getProvince()==bretagne){
		d[p[i]->getY()*2][p[i]->getX()*5+0]=tla4[0];
		d[p[i]->getY()*2][p[i]->getX()*5+1]=tla4[1];
		d[p[i]->getY()*2][p[i]->getX()*5+2]=tla4[2];
            }

            if(p[i]->getNumElements()==1)d[p[i]->getY()*2+1][p[i]->getX()*5+0]='1';
            if(p[i]->getNumElements()==2)d[p[i]->getY()*2+1][p[i]->getX()*5+0]='2';
            if(p[i]->getNumElements()==3)d[p[i]->getY()*2+1][p[i]->getX()*5+0]='3';
            if(p[i]->getNumElements()==4)d[p[i]->getY()*2+1][p[i]->getX()*5+0]='4';

            if(p[i]->getDir()==U)d[p[i]->getY()*2+1][p[i]->getX()*5+1]='^';
            if(p[i]->getDir()==L)d[p[i]->getY()*2+1][p[i]->getX()*5+1]='<';
            if(p[i]->getDir()==D)d[p[i]->getY()*2+1][p[i]->getX()*5+1]='V';
            if(p[i]->getDir()==R)d[p[i]->getY()*2+1][p[i]->getX()*5+1]='>';

            s=getIntel(p,i);
            r=p[i]->recommend(s);
            if(r==nothing)  d[p[i]->getY()*2+1][p[i]->getX()*5+2]='.';
            if(r==lft)      d[p[i]->getY()*2+1][p[i]->getX()*5+2]='?';
            if(r==rght)     d[p[i]->getY()*2+1][p[i]->getX()*5+2]='?';
            if(r==rear)     d[p[i]->getY()*2+1][p[i]->getX()*5+2]='?';
            if(r==goforward)d[p[i]->getY()*2+1][p[i]->getX()*5+2]='*';
            if(r==attck)    d[p[i]->getY()*2+1][p[i]->getX()*5+2]='!';
        }
    }

    //print out the big old character array
    for(i=0;i<DIM;++i){
        for(j=0;j<DIM;++j){
            cout << d[i*2][j*5+0];
            cout << d[i*2][j*5+1];
            cout << d[i*2][j*5+2];
            cout << d[i*2][j*5+3];
            cout << d[i*2][j*5+4];
        }
        cout << "\n";
        for(j=0;j<DIM;++j){
            cout << d[i*2+1][j*5+0];
            cout << d[i*2+1][j*5+1];
            cout << d[i*2+1][j*5+2];
            cout << d[i*2+1][j*5+3];
            cout << d[i*2+1][j*5+4];
        }
        cout << "\n";
        cout << "\n";
    }

}

//return true if the space in front of a unit is blocked
bool blocked(gamePiece *p[], int m){
	int i;
	//initialize x and y to the unit's location
	int x=p[m]->getX();
	int y=p[m]->getY();

	//move x and y to be in front of the unit's location
	compassPoint d=p[m]->getDir();
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;

	//check to see if any living unit occupies space [x,y]
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y)return true;
	}

	//nobody there? then return false
	return false;
}

//return true if the space in front of a unit is blocked
void makeSuffer(gamePiece *p[], int m, int hits){
	int i;
	//initialize x and y to the unit's location
	int x=p[m]->getX();
	int y=p[m]->getY();

	//move x and y to be in front of the unit's location
	compassPoint d=p[m]->getDir();
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;

	//check to see if any living unit occupies space [x,y]
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y)
			//if so, make it suffer
			p[i]->suffer(hits);
	}

	return;
}

// a really long and messy function that builds the intel report for 
// specific ToySoldier unit m.  Each section is commented, but they are
// all just different enough to keep me from writing a separate function
intel getIntel(gamePiece *p[], int m){
	intel sitRep;
	int i,dist,xdist,ydist;
	int x;
	int y;
	compassPoint d=p[m]->getDir();

	//get inFront data;
	x=p[m]->getX();
	y=p[m]->getY();
	if(d==U)y--;
	if(d==D)y++;
	if(d==L)x--;
	if(d==R)x++;
	sitRep.inFront = empty;
	sitRep.inFrontNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inFront=abyss;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y){
			sitRep.inFrontNum=p[i]->getNumElements();
			if(p[i]->getProvince()==p[m]->getProvince())
				sitRep.inFront=ally;
			else
				sitRep.inFront=enemy;
		}
	}

	
	//get inRear data;
	x=p[m]->getX();
	y=p[m]->getY();
	if(d==U)y++;
	if(d==D)y--;
	if(d==L)x++;
	if(d==R)x--;
	sitRep.inRear = empty;
	sitRep.inRearNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inRear=abyss;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y){
			sitRep.inRearNum=p[i]->getNumElements();
			if(p[i]->getProvince()==p[m]->getProvince())
				sitRep.inRear=ally;
			else
				sitRep.inRear=enemy;
		}
	}

	
	//get inLeft data;
	x=p[m]->getX();
	y=p[m]->getY();
	if(d==U)x--;
	if(d==D)x++;
	if(d==L)y++;
	if(d==R)y--;
	sitRep.inLeft = empty;
	sitRep.inLeftNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inLeft=abyss;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y){
			sitRep.inLeftNum=p[i]->getNumElements();
			if(p[i]->getProvince()==p[m]->getProvince())
				sitRep.inLeft=ally;
			else
				sitRep.inLeft=enemy;
		}
	}

	
	//get inRight data;
	x=p[m]->getX();
	y=p[m]->getY();
	if(d==U)x++;
	if(d==D)x--;
	if(d==L)y--;
	if(d==R)y++;
	sitRep.inRight = empty;
	sitRep.inRightNum = 0;
	if(y<0||y>=DIM||x<0||x>=DIM)sitRep.inRight=abyss;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getX()==x&&p[i]->getY()==y){
			sitRep.inRightNum=p[i]->getNumElements();
			if(p[i]->getProvince()==p[m]->getProvince())
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
		if(p[i]->onBoard()&&p[i]->getProvince()!=p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
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
				sitRep.nearestEnemyNum=p[i]->getNumElements();
			}
		}
	}
			
				
	//get weakestEnemy data;
	sitRep.weakestEnemyDir=U;
	sitRep.weakestEnemyDist=100;
	sitRep.weakestEnemyNum=100;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getProvince()!=p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i]->getNumElements()<sitRep.weakestEnemyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.weakestEnemyDir=L;
					else sitRep.weakestEnemyDir=R;
				}else{
					if(ydist>0)sitRep.weakestEnemyDir=U;
					else sitRep.weakestEnemyDir=D;
				}
				sitRep.weakestEnemyDist=dist;
				sitRep.weakestEnemyNum=p[i]->getNumElements();
			}
		}
	}
				
	//get strongestEnemy data;
	sitRep.strongestEnemyDir=U;
	sitRep.strongestEnemyDist=100;
	sitRep.strongestEnemyNum=0;
	for(i=0;i<NUM;++i){
		if(p[i]->onBoard()&&p[i]->getProvince()!=p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i]->getNumElements()>sitRep.strongestEnemyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.strongestEnemyDir=L;
					else sitRep.strongestEnemyDir=R;
				}else{
					if(ydist>0)sitRep.strongestEnemyDir=U;
					else sitRep.strongestEnemyDir=D;
				}
				sitRep.strongestEnemyDist=dist;
				sitRep.strongestEnemyNum=p[i]->getNumElements();
			}
		}
	}


	//get nearestAlly data;
	sitRep.nearestAllyDir=U;
	sitRep.nearestAllyDist=100;
	sitRep.nearestAllyNum=100;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i]->onBoard()&&p[i]->getProvince()==p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
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
				sitRep.nearestAllyNum=p[i]->getNumElements();
			}
		}
	}
			
				
	//get weakestAlly data;
	sitRep.weakestAllyDir=U;
	sitRep.weakestAllyDist=100;
	sitRep.weakestAllyNum=100;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i]->onBoard()&&p[i]->getProvince()==p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i]->getNumElements()<sitRep.weakestAllyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.weakestAllyDir=L;
					else sitRep.weakestAllyDir=R;
				}else{
					if(ydist>0)sitRep.weakestAllyDir=U;
					else sitRep.weakestAllyDir=D;
				}
				sitRep.weakestAllyDist=dist;
				sitRep.weakestAllyNum=p[i]->getNumElements();
			}
		}
	}
				
	//get strongestAlly data;
	sitRep.strongestAllyDir=U;
	sitRep.strongestAllyNum=100;
	sitRep.strongestAllyDist=0;
	for(i=0;i<NUM;++i){
		if(i!=m&&p[i]->onBoard()&&p[i]->getProvince()==p[m]->getProvince()){
			x=p[i]->getX();
			y=p[i]->getY();
			xdist=p[m]->getX()-x;
			ydist=p[m]->getY()-y;
			dist=abs(xdist)+abs(ydist);
			if(p[i]->getNumElements()>sitRep.strongestAllyNum){
				if(abs(xdist)>abs(ydist)){
					if(xdist>0)sitRep.strongestAllyDir=L;
					else sitRep.strongestAllyDir=R;
				}else{
					if(ydist>0)sitRep.strongestAllyDir=U;
					else sitRep.strongestAllyDir=D;
				}
				sitRep.strongestAllyDist=dist;
				sitRep.strongestAllyNum=p[i]->getNumElements();
			}
		}
	}

	return sitRep;

}

void printTlaList(){
	int i;
	for(i=0;i<NUMTLAS;++i)
		cout << tlalist[i]<<endl;
}
	
gamePiece * newSoldier(char tla[],int x, int y, compassPoint d, int n, provinceName p){
	if(!strcmp(tla,"toy"))return new gamePiece(x,y,d,n,p);
	if(!strcmp(tla,"dww"))return new dww(x,y,d,n,p);
	if(!strcmp(tla,"jlw"))return new jlw(x,y,d,n,p);
	if(!strcmp(tla,"guy"))return new guy(x,y,d,n,p);
	if(!strcmp(tla,"aaa"))return new aaa(x,y,d,n,p);
	if(!strcmp(tla,"abr"))return new abr(x,y,d,n,p);
	if(!strcmp(tla,"awn"))return new awn(x,y,d,n,p);
	if(!strcmp(tla,"bio"))return new bio(x,y,d,n,p);
	if(!strcmp(tla,"bne"))return new bne(x,y,d,n,p);
	if(!strcmp(tla,"bom"))return new bom(x,y,d,n,p);
	if(!strcmp(tla,"chz"))return new chz(x,y,d,n,p);
	if(!strcmp(tla,"dbg"))return new dbg(x,y,d,n,p);
	if(!strcmp(tla,"dmx"))return new dmx(x,y,d,n,p);
	if(!strcmp(tla,"edc"))return new edc(x,y,d,n,p);
	if(!strcmp(tla,"gen"))return new gen(x,y,d,n,p);
	if(!strcmp(tla,"hmd"))return new hmd(x,y,d,n,p);
	if(!strcmp(tla,"jam"))return new jam(x,y,d,n,p);
	if(!strcmp(tla,"jax"))return new jax(x,y,d,n,p);
	if(!strcmp(tla,"jds"))return new jds(x,y,d,n,p);
	if(!strcmp(tla,"jeh"))return new jeh(x,y,d,n,p);
	if(!strcmp(tla,"jkp"))return new jkp(x,y,d,n,p);
	if(!strcmp(tla,"jsh"))return new jsh(x,y,d,n,p);
	if(!strcmp(tla,"kap"))return new kap(x,y,d,n,p);
	if(!strcmp(tla,"mas"))return new mas(x,y,d,n,p);
	if(!strcmp(tla,"mis"))return new mis(x,y,d,n,p);
	if(!strcmp(tla,"moo"))return new moo(x,y,d,n,p);
	if(!strcmp(tla,"nub"))return new nub(x,y,d,n,p);
	if(!strcmp(tla,"nyx"))return new nyx(x,y,d,n,p);
	if(!strcmp(tla,"pbj"))return new pbj(x,y,d,n,p);
	if(!strcmp(tla,"pwn"))return new pwn(x,y,d,n,p);
	if(!strcmp(tla,"qed"))return new qed(x,y,d,n,p);
	if(!strcmp(tla,"ray"))return new ray(x,y,d,n,p);
	if(!strcmp(tla,"sah"))return new sah(x,y,d,n,p);
	if(!strcmp(tla,"scm"))return new scm(x,y,d,n,p);
	if(!strcmp(tla,"sgt"))return new sgt(x,y,d,n,p);
	if(!strcmp(tla,"snl"))return new snl(x,y,d,n,p);
	if(!strcmp(tla,"sol"))return new sol(x,y,d,n,p);
	if(!strcmp(tla,"tdb"))return new tdb(x,y,d,n,p);
	if(!strcmp(tla,"the"))return new the(x,y,d,n,p);
	if(!strcmp(tla,"tjc"))return new tjc(x,y,d,n,p);
	if(!strcmp(tla,"trs"))return new trs(x,y,d,n,p);
	if(!strcmp(tla,"win"))return new win(x,y,d,n,p);
	if(!strcmp(tla,"wmd"))return new wmd(x,y,d,n,p);
	if(!strcmp(tla,"wrs"))return new wrs(x,y,d,n,p);
	if(!strcmp(tla,"wtf"))return new wtf(x,y,d,n,p);
	if(!strcmp(tla,"wwf"))return new wwf(x,y,d,n,p);
	if(!strcmp(tla,"zim"))return new zim(x,y,d,n,p);
	cout << "making soldier.  quitting.\n";
}

bool checksOut(char tla[]){
	int i;
	for(i=0;i<NUMTLAS;++i){
		if(!strcmp(tlalist[i],tla))return true;
	}
	return false;
}

void setUpBoard(gamePiece *p[NUM]){
    bool gotNames=false;

    while(!gotNames){
	tryagain:
        cout << "tla1: ";
        cin >> tla1;
	if(tla1[0]=='?'){printTlaList();goto tryagain;}
        cout << "tla2: ";
        cin >> tla2;
	if(checksOut(tla1)&&checksOut(tla2))gotNames=true;
	else{
		cout << "one or both of those names are wrong.\n";
		cout << "type '?' to see a full list.\n";
	}
    }

    //set up the board -- deep breath now...
    p[ 0]= newSoldier(tla1,8,1,R,4,gascogne);
    p[ 1]= newSoldier(tla2,1,1,L,4,anjou);
    p[ 2]= newSoldier(tla1,8,2,R,4,gascogne);
    p[ 3]= newSoldier(tla2,1,2,L,4,anjou);
    p[ 4]= newSoldier(tla1,8,3,R,4,gascogne);
    p[ 5]= newSoldier(tla2,1,3,L,4,anjou);
    p[ 6]= newSoldier(tla1,8,4,R,4,gascogne);
    p[ 7]= newSoldier(tla2,1,4,L,4,anjou);
    p[ 8]= newSoldier(tla1,8,5,R,4,gascogne);
    p[ 9]= newSoldier(tla2,1,5,L,4,anjou);
    p[10]= newSoldier(tla1,8,6,R,4,gascogne);
    p[11]= newSoldier(tla2,1,6,L,4,anjou);
    p[12]= newSoldier(tla1,8,7,R,4,gascogne);
    p[13]= newSoldier(tla2,1,7,L,4,anjou);
    p[14]= newSoldier(tla1,8,8,R,4,gascogne);
    p[15]= newSoldier(tla2,1,8,L,4,anjou);

    strcpy(tla3,"toy");
    p[16]= newSoldier(tla3,0,0,L,0,anjou);
    p[17]= newSoldier(tla3,0,0,L,0,anjou);
    p[18]= newSoldier(tla3,0,0,L,0,anjou);
    p[19]= newSoldier(tla3,0,0,L,0,anjou);
    p[20]= newSoldier(tla3,0,0,L,0,anjou);
    p[21]= newSoldier(tla3,0,0,L,0,anjou);
    p[22]= newSoldier(tla3,0,0,L,0,anjou);
    p[23]= newSoldier(tla3,0,0,L,0,anjou);

    strcpy(tla4,"toy");
    p[24]= newSoldier(tla4,0,0,L,0,anjou);
    p[25]= newSoldier(tla4,0,0,L,0,anjou);
    p[26]= newSoldier(tla4,0,0,L,0,anjou);
    p[27]= newSoldier(tla4,0,0,L,0,anjou);
    p[28]= newSoldier(tla4,0,0,L,0,anjou);
    p[29]= newSoldier(tla4,0,0,L,0,anjou);
    p[30]= newSoldier(tla4,0,0,L,0,anjou);
    p[31]= newSoldier(tla4,0,0,L,0,anjou);
    // ... whew!
}



int main(){

    intel sitRep;
    gamePiece *piece[NUM];
    int i,j;
    int m;
    recommendation r;
    int hits;
    char line[1024];
    bool done=false;

    srand(time(NULL));

    // set up the board
    setUpBoard(piece);
    display(piece);
    cin.getline(line,1023);


    // pick a piece, ask for its recommendation, and order it to do that
    while(!done){
        //m=rand()%NUM;
	for(m=0;m<NUM;++m){
        	if(piece[m]->onBoard()){
            		sitRep=getIntel(piece,m);
            		r=piece[m]->recommend(sitRep);
            		switch(r){
            			case nothing: break;
                		case lft: piece[m]->turnLeft(); break;
                		case rght: piece[m]->turnRight(); break;
                		case rear: piece[m]->aboutFace(); break;
                		case goforward: 
					piece[m]->moveForward();
					if(piece[m]->getX()<0||piece[m]->getX()>=DIM)piece[m]->die();
					if(piece[m]->getY()<0||piece[m]->getY()>=DIM)piece[m]->die();
					break;
                		case attck: 
					hits=piece[m]->attack();
					makeSuffer(piece,m,hits);
					break;
            		}
//	                display(piece,piece[m]->getX(),piece[m]->getY());
//       	       	cin.getline(line,1023);
            		if(line[0]=='q')done=true;
        	  }
          }
          display(piece);
          cin.getline(line,1023);
    }
    return 0;
}

 
