#include<Windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void idle();

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Lotte Dept Store");
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutDisplayFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.4, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(4.0f);
	glLineWidth(1.0f);
}

void depanbelakang(void)
{
	//depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-29.0, -18.0, 42.0);
	glVertex3f(-29.0, 24.0, 42.0);
	glVertex3f(29.0, 24.0, 42.0);
	glVertex3f(29.0, -18.0, 42.0);
	glEnd();

	//putihkiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-29.0, -18.0, 42.0);
	glVertex3f(-29.0, -24.0, 42.0);
	glVertex3f(-24.0, -24.0, 42.0);
	glVertex3f(-24.0, -18.0, 42.0);
	glEnd();

	//putihkanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(8.0, -18.0, 42.0);
	glVertex3f(8.0, -24.0, 42.0);
	glVertex3f(29.0, -24.0, 42.0);
	glVertex3f(29.0, -18.0, 42.0);
	glEnd();

	//garispojokkiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-19.5, -18.0, 42.1);
	glVertex3f(-19.5, 12.0, 42.1);
	glVertex3f(-18.5, 12.0, 42.1);
	glVertex3f(-18.5, -18.0, 42.1);
	glEnd();

	//gariskiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-5.0, -12.0, 42.1);
	glVertex3f(-5.0, 18.0, 42.1);
	glVertex3f(-3.0, 18.0, 42.1);
	glVertex3f(-3.0, -12.0, 42.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-5.0, 18.2, 42.2);
	glVertex3f(-3.0, 18.2, 42.2);
	glVertex3f(-2.2, 23.8, 42.2);
	glVertex3f(-5.8, 23.8, 42.2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-3.0, 23.8, 42.2);
	glVertex3f(-5.0, 23.8, 42.2);
	glVertex3f(-4.0, 19.0, 42.2);
	glEnd();

	//gariskanan
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, -12.0, 42.1);
	glVertex3f(5.0, 18.0, 42.1);
	glVertex3f(3.0, 18.0, 42.1);
	glVertex3f(3.0, -12.0, 42.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 18.2, 42.2);
	glVertex3f(3.0, 18.2, 42.2);
	glVertex3f(2.2, 23.8, 42.2);
	glVertex3f(5.8, 23.8, 42.2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(3.0, 23.8, 42.2);
	glVertex3f(5.0, 23.8, 42.2);
	glVertex3f(4.0, 19.0, 42.2);
	glEnd();

	//merahataspintu
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -18.0, 42.1);
	glVertex3f(-8.0, -12.0, 42.1);
	glVertex3f(8.0, -12.0, 42.1);
	glVertex3f(8.0, -18.0, 42.1);
	glEnd();

	//merahajalan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -18.0, 42.1);
	glVertex3f(-8.0, -20.0, 42.1);
	glVertex3f(-24.0, -20.0, 42.1);
	glVertex3f(-24.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -18.0, 42.1);
	glVertex3f(-8.0, -24.0, 42.1);
	glVertex3f(-9.0, -24.0, 42.1);
	glVertex3f(-9.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-24.0, -18.0, 42.1);
	glVertex3f(-24.0, -24.0, 42.1);
	glVertex3f(-23.0, -24.0, 42.1);
	glVertex3f(-23.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-15.0, -18.0, 42.1);
	glVertex3f(-15.0, -24.0, 42.1);
	glVertex3f(-17.0, -24.0, 42.1);
	glVertex3f(-17.0, -18.0, 42.1);
	glEnd();

	//vertical
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-28.0, 24.0, 42.1);
	glVertex3f(-28.0, -18.0, 42.1);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-26.0, 24.0, 42.1);
	glVertex3f(-26.0, -18.0, 42.1);
	glEnd();

	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-24.0, 24.0, 42.1);
	glVertex3f(-24.0, -18.0, 42.1);
	glEnd();

	//4
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-22.0, 24.0, 42.1);
	glVertex3f(-22.0, -18.0, 42.1);
	glEnd();

	//5
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-20.0, 24.0, 42.1);
	glVertex3f(-20.0, -18.0, 42.1);
	glEnd();

	//6
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-18.0, 24.0, 42.1);
	glVertex3f(-18.0, -18.0, 42.1);
	glEnd();

	//7
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-16.0, 24.0, 42.1);
	glVertex3f(-16.0, -18.0, 42.1);
	glEnd();

	//8
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-14.0, 24.0, 42.1);
	glVertex3f(-14.0, -18.0, 42.1);
	glEnd();

	//9
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-12.0, 24.0, 42.1);
	glVertex3f(-12.0, -18.0, 42.1);
	glEnd();

	//10
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.0, 24.0, 42.1);
	glVertex3f(-10.0, -18.0, 42.1);
	glEnd();

	//11
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-8.0, 24.0, 42.1);
	glVertex3f(-8.0, -12.0, 42.1);
	glEnd();

	//12
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-6.0, 24.0, 42.1);
	glVertex3f(-6.0, -12.0, 42.1);
	glEnd();

	//13
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-4.0, 24.0, 42.1);
	glVertex3f(-4.0, -12.0, 42.1);
	glEnd();

	//14
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-2.0, 24.0, 42.1);
	glVertex3f(-2.0, -12.0, 42.1);
	glEnd();

	//15
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 24.0, 42.1);
	glVertex3f(0.0, -12.0, 42.1);
	glEnd();

	//16
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.0, 24.0, 42.1);
	glVertex3f(2.0, -12.0, 42.1);
	glEnd();

	//17
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(4.0, 24.0, 42.1);
	glVertex3f(4.0, -12.0, 42.1);
	glEnd();

	//18
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(6.0, 24.0, 42.1);
	glVertex3f(6.0, -12.0, 42.1);
	glEnd();

	//19
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(8.0, 24.0, 42.1);
	glVertex3f(8.0, -12.0, 42.1);
	glEnd();

	//20
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 24.0, 42.1);
	glVertex3f(10.0, -18.0, 42.1);
	glEnd();

	//21
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(12.0, 24.0, 42.1);
	glVertex3f(12.0, -18.0, 42.1);
	glEnd();

	//22
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 24.0, 42.1);
	glVertex3f(14.0, -18.0, 42.1);
	glEnd();

	//23
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(16.0, 24.0, 42.1);
	glVertex3f(16.0, -18.0, 42.1);
	glEnd();

	//24
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(18.0, 24.0, 42.1);
	glVertex3f(18.0, -18.0, 42.1);
	glEnd();

	//25
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 24.0, 42.1);
	glVertex3f(20.0, -18.0, 42.1);
	glEnd();

	//26
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(22.0, 24.0, 42.1);
	glVertex3f(22.0, -18.0, 42.1);
	glEnd();

	//27
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(24.0, 24.0, 42.1);
	glVertex3f(24.0, -18.0, 42.1);
	glEnd();

	//28
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(26.0, 24.0, 42.1);
	glVertex3f(26.0, -18.0, 42.1);
	glEnd();

	//29
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(28.0, 24.0, 42.1);
	glVertex3f(28.0, -18.0, 42.1);
	glEnd();

	//horizontal
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 18.0, 42.1);
	glVertex3f(29.0, 18.0, 42.1);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 12.0, 42.1);
	glVertex3f(29.0, 12.0, 42.1);
	glEnd();

	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 6.0, 42.1);
	glVertex3f(29.0, 6.0, 42.1);
	glEnd();

	//4	
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 0.0, 42.1);
	glVertex3f(29.0, 0.0, 42.1);
	glEnd();

	//5
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -6.0, 42.1);
	glVertex3f(29.0, -6.0, 42.1);
	glEnd();

	//6
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -12.0, 42.1);
	glVertex3f(29.0, -12.0, 42.1);
	glEnd();

	//7
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -18.0, 42.1);
	glVertex3f(29.0, -18.0, 42.1);
	glEnd();

	//kerucutdepan1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-22.5, -0.5, 42.1);
	glVertex3f(-23.0, -5.5, 42.1);
	glVertex3f(-23.0, -1.0, 42.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-23.5, -0.5, 42.1);
	glVertex3f(-23.0, -5.5, 42.1);
	glVertex3f(-23.0, -1.0, 42.5);
	glEnd();

	//kerucutdepan2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.5, -0.5, 42.1);
	glVertex3f(-11.0, -5.5, 42.1);
	glVertex3f(-11.0, -1.0, 42.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-11.5, -0.5, 42.1);
	glVertex3f(-11.0, -5.5, 42.1);
	glVertex3f(-11.0, -1.0, 42.5);
	glEnd();

	//kerucutdepan3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(22.5, -0.5, 42.1);
	glVertex3f(23.0, -5.5, 42.1);
	glVertex3f(23.0, -1.0, 42.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(23.5, -0.5, 42.1);
	glVertex3f(23.0, -5.5, 42.1);
	glVertex3f(23.0, -1.0, 42.5);
	glEnd();

	//kerucutdepan4
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(10.5, -0.5, 42.1);
	glVertex3f(11.0, -5.5, 42.1);
	glVertex3f(11.0, -1.0, 42.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(11.5, -0.5, 42.1);
	glVertex3f(11.0, -5.5, 42.1);
	glVertex3f(11.0, -1.0, 42.5);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-29.0, -24.0, -42.0);
	glVertex3f(-29.0, 24.0, -42.0);
	glVertex3f(29.0, 24.0, -42.0);
	glVertex3f(29.0, -24.0, -42.0);
	glEnd();

	//vertical
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-28.0, 24.0, -42.1);
	glVertex3f(-28.0, -24.0, -42.1);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-26.0, 24.0, -42.1);
	glVertex3f(-26.0, -24.0, -42.1);
	glEnd();

	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-24.0, 24.0, -42.1);
	glVertex3f(-24.0, -24.0, -42.1);
	glEnd();

	//4
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-22.0, 24.0, -42.1);
	glVertex3f(-22.0, -24.0, -42.1);
	glEnd();

	//5
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-20.0, 24.0, -42.1);
	glVertex3f(-20.0, -24.0, -42.1);
	glEnd();

	//6
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-18.0, 24.0, -42.1);
	glVertex3f(-18.0, -24.0, -42.1);
	glEnd();

	//7
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-16.0, 24.0, -42.1);
	glVertex3f(-16.0, -24.0, -42.1);
	glEnd();

	//8
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-14.0, 24.0, -42.1);
	glVertex3f(-14.0, -24.0, -42.1);
	glEnd();

	//9
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-12.0, 24.0, -42.1);
	glVertex3f(-12.0, -24.0, -42.1);
	glEnd();

	//10
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.0, 24.0, -42.1);
	glVertex3f(-10.0, -24.0, -42.1);
	glEnd();

	//11
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-8.0, 24.0, -42.1);
	glVertex3f(-8.0, -24.0, -42.1);
	glEnd();

	//12
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-6.0, 24.0, -42.1);
	glVertex3f(-6.0, -24.0, -42.1);
	glEnd();

	//13
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-4.0, 24.0, -42.1);
	glVertex3f(-4.0, -24.0, -42.1);
	glEnd();

	//14
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-2.0, 24.0, -42.1);
	glVertex3f(-2.0, -24.0, -42.1);
	glEnd();

	//15
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 24.0, -42.1);
	glVertex3f(0.0, -24.0, -42.1);
	glEnd();

	//16
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.0, 24.0, -42.1);
	glVertex3f(2.0, -24.0, -42.1);
	glEnd();

	//17
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(4.0, 24.0, -42.1);
	glVertex3f(4.0, -24.0, -42.1);
	glEnd();

	//18
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(6.0, 24.0, -42.1);
	glVertex3f(6.0, -24.0, -42.1);
	glEnd();

	//19
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(8.0, 24.0, -42.1);
	glVertex3f(8.0, -24.0, -42.1);
	glEnd();

	//20
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 24.0, -42.1);
	glVertex3f(10.0, -24.0, -42.1);
	glEnd();

	//21
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(12.0, 24.0, -42.1);
	glVertex3f(12.0, -24.0, -42.1);
	glEnd();

	//22
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 24.0, -42.1);
	glVertex3f(14.0, -24.0, -42.1);
	glEnd();

	//23
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(16.0, 24.0, -42.1);
	glVertex3f(16.0, -24.0, -42.1);
	glEnd();

	//24
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(18.0, 24.0, -42.1);
	glVertex3f(18.0, -24.0, -42.1);
	glEnd();

	//25
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 24.0, -42.1);
	glVertex3f(20.0, -24.0, -42.1);
	glEnd();

	//26
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(22.0, 24.0, -42.1);
	glVertex3f(22.0, -24.0, -42.1);
	glEnd();

	//27
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(24.0, 24.0, -42.1);
	glVertex3f(24.0, -24.0, -42.1);
	glEnd();

	//28
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(26.0, 24.0, -42.1);
	glVertex3f(26.0, -24.0, -42.1);
	glEnd();

	//29
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(28.0, 24.0, -42.1);
	glVertex3f(28.0, -24.0, -42.1);
	glEnd();

	//horizontal
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 18.0, -42.1);
	glVertex3f(29.0, 18.0, -42.1);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 12.0, -42.1);
	glVertex3f(29.0, 12.0, -42.1);
	glEnd();
	
	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 6.0, -42.1);
	glVertex3f(29.0, 6.0, -42.1);
	glEnd();

	//4	
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, 0.0, -42.1);
	glVertex3f(29.0, 0.0, -42.1);
	glEnd();

	//5
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -6.0, -42.1);
	glVertex3f(29.0, -6.0, -42.1);
	glEnd();

	//6
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -12.0, -42.1);
	glVertex3f(29.0, -12.0, -42.1);
	glEnd();

	//7
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.0, -18.0, -42.1);
	glVertex3f(29.0, -18.0, -42.1);
	glEnd();

}
void kanankiri(void)
{
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-29.0, -24.0, -42.0);
	glVertex3f(-29.0, 24.0, -42.0);
	glVertex3f(-29.0, 24.0, 42.0);
	glVertex3f(-29.0, -24.0, 42.0);
	glEnd();

	//strip 1
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, 24.5);
	glVertex3f(29.5, 16.0, 24.5);
	glVertex3f(29.5, 16.0, 25.5);
	glVertex3f(29.5, -24.0, 25.5);
	glEnd();

	//kotak tengah strip 1 dan 2
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -11.0, 22.5);
	glVertex3f(29.5, 14.0, 22.5);
	glVertex3f(29.5, 14.0, 23.5);
	glVertex3f(29.5, -11.0, 23.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -11.0, 10.5);
	glVertex3f(29.5, 14.0, 10.5);
	glVertex3f(29.5, 14.0, 11.5);
	glVertex3f(29.5, -11.0, 11.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -10.0, 22.5);
	glVertex3f(29.5, -11.0, 22.5);
	glVertex3f(29.5, -11.0, 11.5);
	glVertex3f(29.5, -10.0, 11.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, 13.0, 22.5);
	glVertex3f(29.5, 14.0, 22.5);
	glVertex3f(29.5, 14.0, 11.5);
	glVertex3f(29.5, 13.0, 11.5);
	glEnd();

	//strip 2
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, 8.5);
	glVertex3f(29.5, 16.0, 8.5);
	glVertex3f(29.5, 16.0, 9.5);
	glVertex3f(29.5, -24.0, 9.5);
	glEnd();

	//strip 3
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, -7.5);
	glVertex3f(29.5, 16.0, -7.5);
	glVertex3f(29.5, 16.0, -8.5);
	glVertex3f(29.5, -24.0, -8.5);
	glEnd();

	//strip 4
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, -25.5);
	glVertex3f(29.5, 16.0, -25.5);
	glVertex3f(29.5, 16.0, -26.5);
	glVertex3f(29.5, -24.0, -26.5);
	glEnd();

	//kerucut 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, 35.0);
	glVertex3f(30.5, -3.0, 35.0);
	glVertex3f(29.5, -3.0, 37.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, 35.0);
	glVertex3f(30.5, -3.0, 35.0);
	glVertex3f(29.5, -3.0, 33.0);
	glEnd();

	//kerucut 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, 0.0);
	glVertex3f(30.5, -3.0, 0.0);
	glVertex3f(29.5, -3.0, 2.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, 0.0);
	glVertex3f(30.5, -3.0, 0.0);
	glVertex3f(29.5, -3.0, -2.0);
	glEnd();

	//kerucut 3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, -35.0);
	glVertex3f(30.5, -3.0, -35.0);
	glVertex3f(29.5, -3.0, -37.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -10.0, -35.0);
	glVertex3f(30.5, -3.0, -35.0);
	glVertex3f(29.5, -3.0, -33.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(29.0, -24.0, -42.0);
	glVertex3f(29.0, 24.0, -42.0);
	glVertex3f(29.0, 24.0, 42.0);
	glVertex3f(29.0, -24.0, 42.0);
	glEnd();

	//garis vertikal kanan
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 40.0);
	glVertex3f(29.1, -24.0, 40.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 36.0);
	glVertex3f(29.1, -24.0, 36.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 32.0);
	glVertex3f(29.1, -24.0, 32.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 28.0);
	glVertex3f(29.1, -24.0, 28.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 24.0);
	glVertex3f(29.1, -24.0, 24.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 20.0);
	glVertex3f(29.1, -24.0, 20.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 16.0);
	glVertex3f(29.1, -24.0, 16.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 12.0);
	glVertex3f(29.1, -24.0, 12.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 8.0);
	glVertex3f(29.1, -24.0, 8.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 4.0);
	glVertex3f(29.1, -24.0, 4.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, 0.0);
	glVertex3f(29.1, -24.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -4.0);
	glVertex3f(29.1, -24.0, -4.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -8.0);
	glVertex3f(29.1, -24.0, -8.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -12.0);
	glVertex3f(29.1, -24.0, -12.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -16.0);
	glVertex3f(29.1, -24.0, -16.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -20.0);
	glVertex3f(29.1, -24.0, -20.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -24.0);
	glVertex3f(29.1, -24.0, -24.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -28.0);
	glVertex3f(29.1, -24.0, -28.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -32.0);
	glVertex3f(29.1, -24.0, -32.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -36.0);
	glVertex3f(29.1, -24.0, -36.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 24.0, -40.0);
	glVertex3f(29.1, -24.0, -40.0);
	glEnd();

	//garis horizontal kanan
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 18.0, 42.0);
	glVertex3f(29.1, 18.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 10.0, 42.0);
	glVertex3f(29.1, 10.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 2.0, 42.0);
	glVertex3f(29.1, 2.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -6.0, 42.0);
	glVertex3f(29.1, -6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -14.0, 42.0);
	glVertex3f(29.1, -14.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -22.0, 42.0);
	glVertex3f(29.1, -22.0, -42.0);
	glEnd();

	//garis vertikal kiri
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 40.0);
	glVertex3f(-29.1, -24.0, 40.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 36.0);
	glVertex3f(-29.1, -24.0, 36.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 32.0);
	glVertex3f(-29.1, -24.0, 32.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 28.0);
	glVertex3f(-29.1, -24.0, 28.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 24.0);
	glVertex3f(-29.1, -24.0, 24.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 20.0);
	glVertex3f(-29.1, -24.0, 20.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 16.0);
	glVertex3f(-29.1, -24.0, 16.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 12.0);
	glVertex3f(-29.1, -24.0, 12.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 8.0);
	glVertex3f(-29.1, -24.0, 8.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 4.0);
	glVertex3f(-29.1, -24.0, 4.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, 0.0);
	glVertex3f(-29.1, -24.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -4.0);
	glVertex3f(-29.1, -24.0, -4.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -8.0);
	glVertex3f(-29.1, -24.0, -8.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -12.0);
	glVertex3f(-29.1, -24.0, -12.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -16.0);
	glVertex3f(-29.1, -24.0, -16.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -20.0);
	glVertex3f(-29.1, -24.0, -20.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -24.0);
	glVertex3f(-29.1, -24.0, -24.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -28.0);
	glVertex3f(-29.1, -24.0, -28.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -32.0);
	glVertex3f(-29.1, -24.0, -32.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -36.0);
	glVertex3f(-29.1, -24.0, -36.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 24.0, -40.0);
	glVertex3f(-29.1, -24.0, -40.0);
	glEnd();

	//garis horizontal kiri
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 18.0, 42.0);
	glVertex3f(-29.1, 18.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 10.0, 42.0);
	glVertex3f(-29.1, 10.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 2.0, 42.0);
	glVertex3f(-29.1, 2.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -6.0, 42.0);
	glVertex3f(-29.1, -6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -14.0, 42.0);
	glVertex3f(-29.1, -14.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -22.0, 42.0);
	glVertex3f(-29.1, -22.0, -42.0);
	glEnd();
}
void atasbawah(void) {

	//atas
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex3f(-29.0, 10.0, -42.0);
	glVertex3f(-29.0, 10.0, 42.0);
	glVertex3f(29.0, 10.0, 42.0);
	glVertex3f(29.0, 10.0, -42.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-29.0, -24.0, -42.0);
	glVertex3f(-29.0, -24.0, 42.0);
	glVertex3f(29.0, -24.0, 42.0);
	glVertex3f(29.0, -24.0, -42.0);
	glEnd();

}


void objek(void)
{
	//pohon
	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0,-23.9,39.0);
	glVertex3f(11.0,-20.0,39.0);
	glVertex3f(13.0,-20.0,39.0);
	glVertex3f(13.0,-23.9,39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0,-23.9,37.0);
	glVertex3f(11.0,-20.0,37.0);
	glVertex3f(13.0,-20.0,37.0);
	glVertex3f(13.0,-23.9,37.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0,-23.9,37.0);
	glVertex3f(11.0,-20.0,37.0);
	glVertex3f(11.0,-20.0,39.0);
	glVertex3f(11.0,-23.9,39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(13.0,-23.9,37.0);
	glVertex3f(13.0,-20.0,37.0);
	glVertex3f(13.0,-20.0,39.0);
	glVertex3f(13.0,-23.9,39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0,-23.9,37.0);
	glVertex3f(13.0,-23.9,37.0);
	glVertex3f(13.0,-23.9,39.0);
	glVertex3f(11.0,-23.9,39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(9.0,-20.0,35.0);
	glVertex3f(15.0,-20.0,35.0);
	glVertex3f(15.0,-20.0,41.0);
	glVertex3f(9.0,-20.0,41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0,-12.0,38.0);
	glVertex3f(15.0,-20.0,41.0);
	glVertex3f(9.0,-20.0,41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0,-12.0,38.0);
	glVertex3f(9.0,-20.0,35.0);
	glVertex3f(9.0,-20.0,41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0,-12.0,38.0);
	glVertex3f(15.0,-20.0,35.0);
	glVertex3f(15.0,-20.0,41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0,-12.0,38.0);
	glVertex3f(15.0,-20.0,35.0);
	glVertex3f(15.0,-20.0,35.0);
	glEnd();

	//kursi
	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.9, -41.9);
	glVertex3f(-24.0, -23.9, -41.9);
	glVertex3f(-24.0, -23.9, -30.0);
	glVertex3f(-28.9, -23.9, -30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.0, -41.9);
	glVertex3f(-24.0, -23.0, -41.9);
	glVertex3f(-24.0, -23.0, -30.0);
	glVertex3f(-28.9, -23.0, -30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.9, -38.0);
	glVertex3f(-24.0, -23.9, -38.0);
	glVertex3f(-24.0, -21.0, -38.0);
	glVertex3f(-28.9, -21.0, -38.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.9, -30.0);
	glVertex3f(-24.0, -23.9, -30.0);
	glVertex3f(-24.0, -21.0, -30.0);
	glVertex3f(-28.9, -21.0, -30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.9, -41.9);
	glVertex3f(-28.9, -23.9, -30.0);
	glVertex3f(-28.9, -19.0, -30.0);
	glVertex3f(-28.9, -19.0, -41.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-28.9, -23.9, -41.9);
	glVertex3f(-14.0, -23.9, -41.9);
	glVertex3f(-14.0, -19.0, -41.9);
	glVertex3f(-28.9, -19.0, -41.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-14.0, -23.9, -41.9);
	glVertex3f(-24.0, -23.9, -41.9);
	glVertex3f(-24.0, -23.9, -38.0);
	glVertex3f(-14.0, -23.9, -38.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-14.0, -23.0, -41.9);
	glVertex3f(-24.0, -23.0, -41.9);
	glVertex3f(-24.0, -23.0, -38.0);
	glVertex3f(-14.0, -23.0, -38.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.585, 0.292, 0.0);
	glVertex3f(-14.0, -23.9, -41.9);
	glVertex3f(-14.0, -23.9, -38.0);
	glVertex3f(-14.0, -21.0, -38.0);
	glVertex3f(-14.0, -21.0, -41.9);
	glEnd();

}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotated(xrot, 1.0f, 0.0f, 0.0f);
	glRotated(yrot, 0.0f, 1.0f, 0.0f);

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	kanankiri();
	depanbelakang();
	atasbawah();
	//glPushMatrix();
	//glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 50.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}
