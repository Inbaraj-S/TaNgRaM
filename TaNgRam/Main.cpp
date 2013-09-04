#include<stdlib.h>	
#include<GL/glut.h>
#include<process.h>
#include<ctime>	
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAX 6

//void background();

clock_t end,start;
int xyz=1;
int level;
int p=3; 
int flag2=1;
int z=0;
int count=0;
float b=0;
int flag=0;
float sf=1;
int menu1;
int fl=1;
int fe=0;

class objects
{
	public:
		int x[MAX],y[MAX],edges;
		int s_flag;
		void draw(int flag);
		void move(unsigned char dir);
		 objects()
		{
			s_flag=0;
		}
};

objects ob1,ob2,ob3;
int sel=2;

void objects::draw(int flag)
{
	//glPushMatrix();
	if(edges==3)
	{
		glColor3f(0.0,0.0,1.0);
		if(flag)
			glColor3f(0.0,0.6,1.0);
		glBegin(GL_TRIANGLES);
			glVertex2f(x[0],y[0]);
			glVertex2f(x[1],y[1]);
			glVertex2f(x[2],y[2]);
		glEnd();
	}
	if(edges==4)
	{
		glColor3f(0.0,0.0,1.0);
		if(flag)
			glColor3f(0.0,0.6,1.0);
		glBegin(GL_QUADS);
			glVertex2f(x[0],y[0]);
			glVertex2f(x[1],y[1]);
			glVertex2f(x[2],y[2]);
			glVertex2f(x[3],y[3]);
		glEnd();
	}

	if(edges==6)
	{
		glColor3f(0.0,0.0,1.0);
		if(flag)
			glColor3f(0.0,0.6,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(x[0],y[0]);
			glVertex2f(x[1],y[1]);
			glVertex2f(x[2],y[2]);
			glVertex2f(x[3],y[3]);
			glVertex2f(x[4],y[4]);
			glVertex2f(x[5],y[5]);
		glEnd();
	}
//	glPopMatrix();
	glutPostRedisplay();
}


void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void Sprintf( int x,int y,char *st)
 {
	 int l,i;
	 l=strlen(st);
	 glPushMatrix();
	 glRasterPos2i(x,y);
	 for(i=0;i<l;i++)
		 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st[i]);
	 glPopMatrix();
 }

void init()
{
	glOrtho(0,800,0,600,-500,500);
}

void background()
{

	glBegin(GL_POLYGON);
	glColor4f(0.7,0,0.2,1);
		glVertex2f(0,0);
		glVertex2f(800,0);

	glColor4f(0.9,0.2,0,1);
		glVertex2f(800,600);
		glVertex2f(0,600); 
	glEnd();
}

int sel_max=3;

 float xs[3]={550.0,650.0,550.0};
 float ys[3]={450.0,450.0,550.0};


 float x2[4]={550.0,650.0,650.0,550.0};
 float y2[4]={300.0,300.0,400.0,400.0};

 float x3[4]={500.0,700.0,700.0,500.0};
 float y3[4]={150.0,150.0,250.0,250.0};

 float xs1[3]={550.0,650.0,550.0};
 float ys1[3]={450.0,450.0,550.0};
 float theta=-90.0*(3.14 / 180.0);


 float x21[4]={550.0,650.0,650.0,550.0};
 float y21[4]={300.0,300.0,400.0,400.0};

float x31[4]={500.0,700.0,700.0,500.0};
 float y31[4]={150.0,150.0,250.0,250.0};
	


float rot_mat[3][3]={{0.0},{0.0},{0.0}};
float centerX,centerY;


void centrecalc(int n)
{
	switch(sel)
	{
	case 1:{
	if(n==3)
	{
		centerX=(xs[2]-xs[0])/2;
		centerY=(ys[1]-ys[0])/2;
	}
	
	if(n==4)
	{
		centerX=(xs[2]-xs[0])/2;
		centerY=(ys[2]-ys[0])/2;
	}
		   }
		   break;
	case 2:{
	if(n==3)
	{
		centerX=(x2[2]-x2[0])/2;
		centerY=(y2[1]-y2[0])/2;
	}
	if(n==4)
	{
		centerX=(x2[2]-x2[0])/2;
		centerY=(y2[2]-y2[0])/2;
	}
		   }
		   break;
		   case 3:{
	if(n==3)
	{
		centerX=(x3[2]-x3[0])/2;
		centerY=(y3[1]-y3[0])/2;
	}
	if(n==4)
	{
		centerX=(x3[2]-x3[0])/2;
		centerY=(y3[2]-y3[0])/2;
	}
		   }

	}
}


/*void rotate(int n)
		{
			float vertices[3][9];


			float mat[3][3];
			int i,j,k;
			float temp[3][20];
			centrecalc(n);
			
			int m = centerX*(cos(theta) - 1) + centerY*(sin(theta));
			int nm = -centerY*(cos(theta) - 1) - centerX*(sin(theta));
			switch(sel)
			{
			case 1:{
			for(i=0;i<n;i++)
			{
				vertices[0][i]=xs[i];
				vertices[1][i]=ys[i];
				vertices[2][i]=1;
			}
				   }
			break;
			case 2:{
			for(i=0;i<n;i++)
			{
				vertices[0][i]=x2[i];
				vertices[1][i]=y2[i];
				vertices[2][i]=1;
			}
				   }
			break;
			case 3:{
			for(i=0;i<n;i++)
			{
				vertices[0][i]=x3[i];
				vertices[1][i]=y3[i];
				vertices[2][i]=1;
			}
				   }
			break;
			}
			mat[0][0] = cos(theta);
			mat[0][1] = -sin(theta);
			mat[0][2] = m;
			
			mat[1][0] = sin(theta);
			mat[1][1] = cos(theta);
			mat[1][2] = nm;
			
			mat[2][0] = 0;
			mat[2][1] = 0;
			mat[2][2] = 1;

			for( i =0 ; i < 3;i++)
				for(j = 0;j < n;j++);
				{
					temp[i][j] = 0.0;
					for(k = 0; k < 3; k++)
					{
						temp[i][j]  += mat[i][k] * vertices[k][j]; 
					}			
				}

			switch(sel)
			{
			case 1:{
				for(i=0;i<n;i++)
				{
					xs[i]=vertices[0][i];
					ys[i]=vertices[0][i];
				}
				   }
				   break;
				   case 2:{
				for(i=0;i<n;i++)
				{
					x2[i]=vertices[0][i];
					y2[i]=vertices[0][i];
				}
				   }
						  break;
						  case 3:{
				for(i=0;i<n;i++)
				{
					x3[i]=vertices[0][i];
					y3[i]=vertices[0][i];
				}
				   }

		}
}
*/
void solution()
{	
	
	int flag=0;
	if((xs[2]+(xs[1]-xs[2])/2)==200)
		if((ys[1]+(ys[2]-ys[1])/2)==400)
			if((x2[1]+(x2[3]-x2[1])/2)==200)
				if((y2[1]+(y2[3]-y2[1])/2)==300)
					if((x3[1]+(x3[3]-x3[1])/2)==250)
						if((y3[1]+(y3[3]-y3[1])/2)==200)
							flag=1;

	char incorrect[100]="Incorrect ";
	char correct[100]="Correct ";
	glColor3f(0.0,0.0,1.0);
	
	if(flag)
	{	glFlush();
		Sprintf(300,300,correct);
	}
	else
	{	glFlush();
		Sprintf(300,300,incorrect);
	}	
	glutPostRedisplay();
	glutSwapBuffers();
}
void keys(unsigned char key,int x,int y)
{
	if(key =='z')
	{
		char text[] = "your socre is";
		Sprintf(0,0,text);
	}

	if(key=='l' )
	{
		sel++;
		if(sel>sel_max) sel=1;
	}
	if(key=='o')
	{
		sel--;
		if(sel<1) sel=sel_max;
	}
	/*if(key=='r')
	{
		switch(sel)
		{
		case 1:rotate(3);
			break;
		case 2:rotate(4);
			break;
		case 3:rotate(4);
			break;
		}
	}
	*/
	
	if(key=='a')
	{
		switch(sel)
		{
		case 1: for(int i=0;i<3;i++)
					xs[i]-=5;
					break;
		case 2: for(int i=0;i<4;i++)
					x2[i]-=5;
					break;
		case 3: for(int i=0;i<4;i++)
					x3[i]-=5;
					break;
		}
	}
	if(key=='d')
	{
		switch(sel)
		{
		case 1: for(int i=0;i<3;i++)
					xs[i]+=5;
					break;
		case 2: for(int i=0;i<4;i++)
					x2[i]+=5;
					break;
		case 3: for(int i=0;i<4;i++)
					x3[i]+=5;
					break;
		}
	}
	if(key=='w')
	{
		switch(sel)
		{
		case 1: for(int i=0;i<3;i++)
					ys[i]+=5;
					break;
		case 2: for(int i=0;i<4;i++)
					y2[i]+=5;
					break;
		case 3: for(int i=0;i<4;i++)
					y3[i]+=5;
					break;
		}
	}
	if(key=='s')
	{
		switch(sel)
		{
		case 1: for(int i=0;i<3;i++)
					ys[i]-=5;
					break;
		case 2: for(int i=0;i<4;i++)
					y2[i]-=5;
					break;
		case 3: for(int i=0;i<4;i++)
					y3[i]-=5;
					break;
		}
	}
		if(key=='c')
		{
			solution();
		}
	

}

	
void drawoutline()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,1.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(150.0,150.0);
		glVertex2f(150.0,450.0);
		glVertex2f(250.0,350.0);
		glVertex2f(250.0,250.0);
		glVertex2f(350.0,250.0);
		glVertex2f(350.0,150.0);
	glEnd();
	glFlush();
}


void drawobjects()
{	
	ob1.edges=3;
	ob1.s_flag=1;

	
	for(int i=0;i<ob1.edges;i++)
	{
		ob1.x[i]=xs[i];
		ob1.y[i]=ys[i];
	}
	if(sel==1)
		ob1.draw(fl);
	else
		ob1.draw(fe);

	ob2.edges=4;
	
	for(int i=0;i<ob2.edges;i++)
	{
		ob2.x[i]=x2[i];
		ob2.y[i]=y2[i];
	}

	if(sel==2)
		ob2.draw(fl);
	else
		ob2.draw(fe);

	ob3.edges=4;
	
	for(int i=0;i<ob3.edges;i++)
	{
		ob3.x[i]=x3[i];
		ob3.y[i]=y3[i];
	}
	if(sel==3)
		ob3.draw(fl);
	else
		ob3.draw(fe);
	glutPostRedisplay();
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND); //enable the blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //set the blend function
	background();
			
		    glColor3f(1.0,1.0,1.0);
			char h1[100]="TaNgRaM GaMe";
			Sprintf(375,550,h1);


/*			"To Select the object: use up/down keys",1
			"To Move the object: use 'w'/'a'/'s'/'d' keys",2
			"To Rotate the object: use 'r'/'t' keys",3
*/


	if(xyz)
	{
		drawoutline();
		drawobjects();
		//checkFIT();
		//nextlevel();
	}

	if(!xyz)
	{
		glColor3f(1.0,1.0,1.0);
		glLineWidth(20);
		glBegin(GL_LINES);
			glVertex2i(250,500);
			glVertex2i(150,500);
			glVertex2i(150,500);
			glVertex2i(150,400);
			glVertex2i(150,400);
			glVertex2i(250,400);
			glVertex2i(250,400);
			glVertex2i(250,450);
			glVertex2i(200,450);
			glVertex2i(250,450);

			glVertex2i(300,400);
			glVertex2i(300,500);
			glVertex2i(300,500);
			glVertex2i(375,500);
			glVertex2i(375,500);
			glVertex2i(375,400);
			glVertex2i(300,450);
			glVertex2i(375,450);

			glVertex2i(425,400);
			glVertex2i(425,500);
			glVertex2i(425,500);
			glVertex2i(475,450);
			glVertex2i(475,450);
			glVertex2i(525,500);
			glVertex2i(525,500);
			glVertex2i(525,400);

			glVertex2i(650,500);
			glVertex2i(575,500);
			glVertex2i(575,500);
			glVertex2i(575,400);
			glVertex2i(575,400);
			glVertex2i(650,400);
			glVertex2i(575,450);
			glVertex2i(650,450);

			glVertex2i(250,300);
			glVertex2i(150,300);
			glVertex2i(150,300);
			glVertex2i(150,200);
			glVertex2i(150,200);
			glVertex2i(250,200);
			glVertex2i(250,200);
			glVertex2i(250,300);

			glVertex2i(300,300);
			glVertex2i(350,200);
			glVertex2i(350,200);
			glVertex2i(400,300);

			glVertex2i(525,300);
			glVertex2i(450,300);
			glVertex2i(450,300);
			glVertex2i(450,200);
			glVertex2i(450,200);
			glVertex2i(525,200);
			glVertex2i(450,250);
			glVertex2i(525,250);

			glVertex2i(575,200);
			glVertex2i(575,300);
			glVertex2i(575,300);
			glVertex2i(650,300);
			glVertex2i(650,300);
			glVertex2i(650,250);
			glVertex2i(650,250);
			glVertex2i(575,250);
			glVertex2i(625,250);
			glVertex2i(650,200);
		glEnd();
			char sc[10];
			char a[100]="Your score is: ";
			int score=(end-start)/CLK_TCK;
			sprintf_s(sc,"%d",score);
			strcat_s(a,sc);
			Sprintf(150,150,a);
	}
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void menu(int val)
{
	switch(val)
	{
		case 1:
		case 2:
		case 3: display();
				break;
		case 4: exit(0);
				break;
	}
}

void callmenu()
{
	menu1=glutCreateMenu(menu);
	glutAddMenuEntry("To Select the object: use up/down keys",1);
	glutAddMenuEntry("To Move the object: use 'w'/'a'/'s'/'d' keys",2);
	glutAddMenuEntry("To Rotate the object: use 'r'/'t' keys",3);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
 
void dispmenu()
{
	int ch;
	while(1)
	{
	printf("\t\t\tWelcome to Tangram Game\n\n\n");
	printf("--> Press 1 to start the game...\n\n");
	printf("--> Press 2 for instructions...\n\n");
	printf("--> Press 3 to exit...\n\n");
	printf("--> ENTER YOUR CHOICE:\t");
	scanf_s("%d",&ch);
	switch(ch)
	{
		case 1:
			start=clock();
			return;
			break;
		case 2:
			printf("\n\nAIM:\nYou are given a Outline of an object and the Broken pieces \n\tof the same object. And we have to rejoin the object to its outline \nand solve the puzzle\n\n");
			printf("Instructions:\n1. You have to put the different pieces of the puzzle in such \n\ta way that the correctly FIT the outline..\n");
			printf("2. You will be having the option of SELECTION and MOVING of pieces\n");
			printf("3. You can select object with the key 'o'/'l' keys.\n");
			printf("4. Moving:\n\t\t(i)\t 'w' for up movement\n\t\t(ii)\t 's' for down movement\n\t\t(iii)\t 'a' for left movement\n\t\t(iv)\t 'd' for right movement\n");
			printf("5. To check the correctness of Solution, use the key 'c'.\n");
			printf("So there you go... press any key to return to the game... Enjoy..!!\n\n");
			_getch();
			start=clock();
			return;
			break;
		case 3:
			printf("\n\t\tThank You..!!\n");
			sleep(2000);
			exit(0);
			break;
		default:
			printf("\nEnter valid key..!!!!\n\n\n");
	}
	}
}

void myreshapefunc(int w,int h)
{
	glViewport(0,0,w,h);
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,0.0,600.0);
	display();
}
int main(int argc,char **argv)
{
	if(flag2)
	{
		dispmenu();
		flag2=0;
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(800,600);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glutCreateWindow("Tangram - A Logic Game");
	srand(time(NULL));
	callmenu();
	glutDisplayFunc(display);
	glutReshapeFunc(myreshapefunc);
	glutKeyboardFunc(keys);
	init();
	glutMainLoop();
}

