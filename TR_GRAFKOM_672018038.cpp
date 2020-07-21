#include<Windows.h>
#include<gl/glut.h>
#include <math.h>

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
const double PI = 3.141592653589793;
float titik;

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
	//glEnable(GL_LIGHTING);
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

void lingkaran(float nilai_radius, float total, float koordinatX, float koordinatY, float sumbuZ)
{
	glBegin(GL_POLYGON);
	for (titik = 0; titik <= 360; titik++)
	{
		float angle = titik * (2 * PI / total);
		float nilai_x = koordinatX + nilai_radius * cos(angle);
		float nilai_y = koordinatY + nilai_radius * sin(angle);
		glVertex3f(nilai_x, nilai_y, sumbuZ);
	}
	glEnd();
}

void lingkaran2(float nilai_radius, float total, float koordinatX, float koordinatY, float sumbuZ)
{
	glBegin(GL_POLYGON);
	for (titik = 0; titik <= 360; titik++)
	{
		float angle = titik * (2 * PI / total);
		float nilai_x = koordinatX + nilai_radius * cos(angle);
		float nilai_y = koordinatY + nilai_radius * sin(angle);
		glVertex3f(sumbuZ, nilai_y, nilai_x);
	}
	glEnd();
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
	glVertex3f(-17.5, -18.0, 42.1);
	glVertex3f(-17.5, 12.0, 42.1);
	glVertex3f(-16.5, 12.0, 42.1);
	glVertex3f(-16.5, -18.0, 42.1);
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

	//pintu1
	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(-9.0, -24.0, 42.2);
	glVertex3f(-9.0, -20.0, 42.2);
	glVertex3f(-15.0, -20.0, 42.2);
	glVertex3f(-15.0, -24.0, 42.2);
	glEnd();

	//pintu2
	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(-17.0, -20.0, 42.2);
	glVertex3f(-17.0, -24.0, 42.2);
	glVertex3f(-23.0, -24.0, 42.2);
	glVertex3f(-23.0, -20.0, 42.2);
	glEnd();

	//pintu3
	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(-6.0, -24.0, 42.2);
	glVertex3f(-6.0, -18.0, 42.2);
	glVertex3f(-1.0, -18.0, 42.2);
	glVertex3f(-1.0, -24.0, 42.2);

	//pintu4
	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(6.0, -24.0, 42.2);
	glVertex3f(6.0, -18.0, 42.2);
	glVertex3f(1.0, -18.0, 42.2);
	glVertex3f(1.0, -24.0, 42.2);
	glEnd();

	//merahataspintu
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -18.0, 42.1);
	glVertex3f(-8.0, -12.0, 42.1);
	glVertex3f(8.0, -12.0, 42.1);
	glVertex3f(8.0, -18.0, 42.1);
	glEnd();

	//putihbanner
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-2.8, 10.0, 42.2);
	glVertex3f(-2.8, -10.0, 42.2);
	glVertex3f(2.8, -10.0, 42.2);
	glVertex3f(2.8, 10.0, 42.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-2.6, 5.0, 42.3);
	glVertex3f(-2.6, 1.0, 42.3);
	glVertex3f(2.6, 1.0, 42.3);
	glVertex3f(2.6, 5.0, 42.3);
	glEnd();

	//merahjalan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-1.0, -18.0, 42.1);
	glVertex3f(-1.0, -24.0, 42.1);
	glVertex3f(1.0, -24.0, 42.1);
	glVertex3f(1.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(8.0, -18.0, 42.1);
	glVertex3f(8.0, -24.0, 42.1);
	glVertex3f(6.0, -24.0, 42.1);
	glVertex3f(6.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-8.0, -18.0, 42.1);
	glVertex3f(-8.0, -20.0, 42.1);
	glVertex3f(-24.0, -20.0, 42.1);
	glVertex3f(-24.0, -18.0, 42.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-6.0, -18.0, 42.1);
	glVertex3f(-6.0, -24.0, 42.1);
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

	//putihatas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(14.1, -24.0, 42.2);
	glVertex3f(14.1, 26.4, 42.2);
	glVertex3f(17.9, 26.4, 42.2);
	glVertex3f(17.9, -24.0, 42.2);

	glVertex3f(14.1, -24.0, 43.2);
	glVertex3f(14.1, 26.4, 43.2);
	glVertex3f(17.9, 26.4, 43.2);
	glVertex3f(17.9, -24.0, 43.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.0, -24.0, 42.0);
	glVertex3f(14.0, -24.0, 43.2);
	glVertex3f(18.0, -24.0, 43.2);
	glVertex3f(18.0, -24.0, 42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.0, -24.0, 42.0);
	glVertex3f(14.0, -24.0, 43.2);
	glVertex3f(14.0, 26.4, 43.2);
	glVertex3f(14.0, 26.4, 42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(18.0, -24.0, 42.0);
	glVertex3f(18.0, -24.0, 43.2);
	glVertex3f(18.0, 26.4, 43.2);
	glVertex3f(18.0, 26.4, 42.0);
	glEnd();

	//merahatas
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(14.1, 36.2, 43.2);
	glVertex3f(14.1, 26.4, 43.2);
	glVertex3f(17.9, 26.4, 43.2);
	glVertex3f(17.9, 36.2, 43.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(14.0, 36.2, 42.0);
	glVertex3f(14.0, 36.2, 43.2);
	glVertex3f(14.0, 26.4, 43.2);
	glVertex3f(14.0, 26.4, 42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(18.0, 36.2, 42.0);
	glVertex3f(18.0, 36.2, 43.2);
	glVertex3f(18.0, 26.4, 43.2);
	glVertex3f(18.0, 26.4, 42.0);
	glEnd();

	//verticalkotak
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, -24.0, 43.3);
	glVertex3f(15.0, 35.4, 43.3);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(16.0, -24.0, 43.3);
	glVertex3f(16.0, 35.4, 43.3);
	glEnd();

	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(17.0, -24.0, 43.3);
	glVertex3f(17.0, 35.4, 43.3);
	glEnd();

	//4
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(18.0, -24.0, 43.3);
	glVertex3f(18.0, 35.4, 43.3);
	glEnd();

	//horizontalkotak
	//1
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -22.2, 43.3);
	glVertex3f(18.0, -22.2, 43.3);
	glEnd();

	//2
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -20.4, 43.3);
	glVertex3f(18.0, -20.4, 43.3);
	glEnd();

	//3
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -18.6, 43.3);
	glVertex3f(18.0, -18.6, 43.3);
	glEnd();

	//4
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -16.8, 43.3);
	glVertex3f(18.0, -16.8, 43.3);
	glEnd();

	//5
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -15.0, 43.3);
	glVertex3f(18.0, -15.0, 43.3);
	glEnd();

	//6
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -13.2, 43.3);
	glVertex3f(18.0, -13.2, 43.3);
	glEnd();

	//7
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -11.4, 43.3);
	glVertex3f(18.0, -11.4, 43.3);
	glEnd();

	//8
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -9.6, 43.3);
	glVertex3f(18.0, -9.6, 43.3);
	glEnd();

	//9
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -7.8, 43.3);
	glVertex3f(18.0, -7.8, 43.3);
	glEnd();

	//10
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -6.0, 43.3);
	glVertex3f(18.0, -6.0, 43.3);
	glEnd();

	//11
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -4.2, 43.3);
	glVertex3f(18.0, -4.2, 43.3);
	glEnd();

	//12
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -2.4, 43.3);
	glVertex3f(18.0, -2.4, 43.3);
	glEnd();

	//13
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, -0.6, 43.3);
	glVertex3f(18.0, -0.6, 43.3);
	glEnd();

	//14
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 1.2, 43.3);
	glVertex3f(18.0, 1.2, 43.3);
	glEnd();

	//15
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 3.0, 43.3);
	glVertex3f(18.0, 3.0, 43.3);
	glEnd();

	//16
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 4.8, 43.3);
	glVertex3f(18.0, 4.8, 43.3);
	glEnd();

	//17
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 6.6, 43.3);
	glVertex3f(18.0, 6.6, 43.3);
	glEnd();

	//18
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 8.4, 43.3);
	glVertex3f(18.0, 8.4, 43.3);
	glEnd();

	//19
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 10.2, 43.3);
	glVertex3f(18.0, 10.2, 43.3);
	glEnd();

	//20
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 12.0, 43.3);
	glVertex3f(18.0, 12.0, 43.3);
	glEnd();

	//21
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 13.8, 43.3);
	glVertex3f(18.0, 13.8, 43.3);
	glEnd();

	//22
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 15.6, 43.3);
	glVertex3f(18.0, 15.6, 43.3);
	glEnd();

	//23
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 17.4, 43.3);
	glVertex3f(18.0, 17.4, 43.3);
	glEnd();

	//24
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 19.2, 43.3);
	glVertex3f(18.0, 19.2, 43.3);
	glEnd();

	//25
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 21.0, 43.3);
	glVertex3f(18.0, 21.0, 43.3);
	glEnd();

	//26
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 22.8, 43.3);
	glVertex3f(18.0, 22.8, 43.3);
	glEnd();

	//27
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 24.8, 43.3);
	glVertex3f(18.0, 24.8, 43.3);
	glEnd();

	//28
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 26.4, 43.3);
	glVertex3f(18.0, 26.4, 43.3);
	glEnd();

	//29
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 28.2, 43.3);
	glVertex3f(18.0, 28.2, 43.3);
	glEnd();

	//30
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 30.0, 43.3);
	glVertex3f(18.0, 30.0, 43.3);
	glEnd();

	//31
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 31.8, 43.3);
	glVertex3f(18.0, 31.8, 43.3);
	glEnd();

	//32
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14.0, 33.6, 43.3);
	glVertex3f(18.0, 33.6, 43.3);
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

void bagiankanan(void)
{
	//garis silver horizontal
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(30.5, -18.5, 42.0);
	glVertex3f(30.5, -17.5, 42.0);
	glVertex3f(30.5, -17.5, -42.0);
	glVertex3f(30.5, -18.5, -42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.0, -18.5, 42.0);
	glVertex3f(29.0, -17.5, 42.0);
	glVertex3f(30.5, -17.5, 42.0);
	glVertex3f(30.5, -18.5, 42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.0, -18.5, -42.0);
	glVertex3f(29.0, -17.5, -42.0);
	glVertex3f(30.5, -17.5, -42.0);
	glVertex3f(30.5, -18.5, -42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.0, -18.5, 42.0);
	glVertex3f(29.0, -18.5, -42.0);
	glVertex3f(30.5, -18.5, -42.0);
	glVertex3f(30.5, -18.5, 42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.0, -17.5, 42.0);
	glVertex3f(29.0, -17.5, -42.0);
	glVertex3f(30.5, -17.5, -42.0);
	glVertex3f(30.5, -17.5, 42.0);
	glEnd();

	//pintu kanan bagian bawah
	glBegin(GL_QUADS);
	glColor3f(0.5, 0, 0);
	glVertex3f(29.8, -24.0, 23.0);
	glVertex3f(29.8, -17.5, 23.0);
	glVertex3f(29.8, -17.5, 5.0);
	glVertex3f(29.8, -24.0, 5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(30.0, -24.0, 18.5);
	glVertex3f(30.0, -19.5, 18.5);
	glVertex3f(30.0, -19.5, 9.5);
	glVertex3f(30.0, -24.0, 9.5);
	glEnd();

	//pintu kanan bagian atas
	glBegin(GL_QUADS);
	glColor3f(0.5, 0, 0);
	glVertex3f(29.8, -17.5, 23.0);
	glVertex3f(29.8, -11.5, 23.0);
	glVertex3f(29.8, -11.5, 5.0);
	glVertex3f(29.8, -17.5, 5.0);
	glEnd();

	//jembatan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -17.5, 18.0);
	glVertex3f(30.0, -14.5, 18.0);
	glVertex3f(60.0, -14.5, 18.0);
	glVertex3f(60.0, -16.5, 18.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -17.5, 13.0);
	glVertex3f(30.0, -14.5, 13.0);
	glVertex3f(60.0, -14.5, 13.0);
	glVertex3f(60.0, -16.5, 13.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(30.0, -17.5, 18.0);
	glVertex3f(30.0, -17.5, 13.0);
	glVertex3f(60.0, -16.5, 13.0);
	glVertex3f(60.0, -16.5, 18.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(30.0, -14.5, 18.0);
	glVertex3f(30.0, -11.5, 17.5);
	glVertex3f(60.0, -11.5, 17.5);
	glVertex3f(60.0, -14.5, 18.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(30.0, -14.5, 13.0);
	glVertex3f(30.0, -11.5, 13.5);
	glVertex3f(60.0, -11.5, 13.5);
	glVertex3f(60.0, -14.5, 13.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(30.0, -11.5, 17.5);
	glVertex3f(30.0, -11.5, 13.5);
	glVertex3f(60.0, -11.5, 13.5);
	glVertex3f(60.0, -11.5, 17.5);
	glEnd();

	//garisjembatanbawah horizontal
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -14.9, 18.1);
	glVertex3f(60.0, -14.9, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -15.9, 18.1);
	glVertex3f(60.0, -15.9, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -16.9, 18.1);
	glVertex3f(40.0, -16.9, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -14.9, 12.8);
	glVertex3f(60.0, -14.9, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -15.9, 12.8);
	glVertex3f(60.0, -15.9, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, -16.9, 12.8);
	glVertex3f(40.0, -16.9, 12.8);
	glEnd();

	//garis jembatan vertikal
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(31.5, -17.5, 18.1);
	glVertex3f(31.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(33.0, -17.5, 18.1);
	glVertex3f(33.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(34.5, -17.4, 18.1);
	glVertex3f(34.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(36.0, -17.3, 18.1);
	glVertex3f(36.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(37.5, -17.2, 18.1);
	glVertex3f(37.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(39.0, -17.1, 18.1);
	glVertex3f(39.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(40.5, -17.0, 18.1);
	glVertex3f(40.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(42.0, -16.9, 18.1);
	glVertex3f(42.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(43.5, -16.8, 18.1);
	glVertex3f(43.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(45.0, -16.7, 18.1);
	glVertex3f(45.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(46.5, -16.6, 18.1);
	glVertex3f(46.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(48.0, -16.5, 18.1);
	glVertex3f(48.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(49.5, -16.4, 18.1);
	glVertex3f(49.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(51.0, -16.3, 18.1);
	glVertex3f(51.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(52.5, -16.2, 18.1);
	glVertex3f(52.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(54.0, -16.1, 18.1);
	glVertex3f(54.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(55.5, -16.0, 18.1);
	glVertex3f(55.5, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(57.0, -15.9, 18.1);
	glVertex3f(57.0, -14.5, 18.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(58.5, -15.8, 18.1);
	glVertex3f(58.5, -14.5, 18.1);
	glEnd();

	//garis jembatan vertikal belakang
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(31.5, -17.5, 12.8);
	glVertex3f(31.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(33.0, -17.5, 12.8);
	glVertex3f(33.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(34.5, -17.4, 12.8);
	glVertex3f(34.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(36.0, -17.3, 12.8);
	glVertex3f(36.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(37.5, -17.2, 12.8);
	glVertex3f(37.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(39.0, -17.1, 12.8);
	glVertex3f(39.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(40.5, -17.0, 12.8);
	glVertex3f(40.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(42.0, -16.9, 12.8);
	glVertex3f(42.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(43.5, -16.8, 12.8);
	glVertex3f(43.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(45.0, -16.7, 12.8);
	glVertex3f(45.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(46.5, -16.6, 12.8);
	glVertex3f(46.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(48.0, -16.5, 12.8);
	glVertex3f(48.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(49.5, -16.4, 12.8);
	glVertex3f(49.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(51.0, -16.3, 12.8);
	glVertex3f(51.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(52.5, -16.2, 12.8);
	glVertex3f(52.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(54.0, -16.1, 12.8);
	glVertex3f(54.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(55.5, -16.0, 12.8);
	glVertex3f(55.5, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(57.0, -15.9, 12.8);
	glVertex3f(57.0, -14.5, 12.8);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(58.5, -15.8, 12.8);
	glVertex3f(58.5, -14.5, 12.8);
	glEnd();

	//pipa rangka
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(30.0, -19.5, 15.3);
	glVertex3f(30.0, -18.5, 15.3);
	glVertex3f(60.0, -18.5, 15.3);
	glVertex3f(60.0, -19.5, 15.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(30.0, -19.5, 15.8);
	glVertex3f(30.0, -18.5, 15.8);
	glVertex3f(60.0, -18.5, 15.8);
	glVertex3f(60.0, -19.5, 15.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(60.0, -19.5, 15.3);
	glVertex3f(60.0, -18.5, 15.3);
	glVertex3f(60.0, -18.5, 15.8);
	glVertex3f(60.0, -19.5, 15.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(30.0, -19.5, 15.8);
	glVertex3f(30.0, -19.5, 15.3);
	glVertex3f(60.0, -19.5, 15.3);
	glVertex3f(60.0, -19.5, 15.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(30.0, -18.5, 15.8);
	glVertex3f(30.0, -18.5, 15.3);
	glVertex3f(60.0, -18.5, 15.3);
	glVertex3f(60.0, -18.5, 15.8);
	glEnd();

	//pipa V1

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 15.5);
	glVertex3f(40.0, -17.0, 18.0);
	glVertex3f(41.0, -17.0, 18.0);
	glVertex3f(41.0, -24.0, 15.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 15.0);
	glVertex3f(40.0, -17.0, 17.5);
	glVertex3f(41.0, -17.0, 17.5);
	glVertex3f(41.0, -24.0, 15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 15.0);
	glVertex3f(40.0, -17.0, 17.5);
	glVertex3f(40.0, -17.0, 18.5);
	glVertex3f(40.0, -24.0, 15.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(41.0, -24.0, 15.0);
	glVertex3f(41.0, -17.0, 17.5);
	glVertex3f(41.0, -17.0, 18.5);
	glVertex3f(41.0, -24.0, 15.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 15.5);
	glVertex3f(40.0, -17.0, 13.0);
	glVertex3f(41.0, -17.0, 13.0);
	glVertex3f(41.0, -24.0, 15.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 16.0);
	glVertex3f(40.0, -17.0, 13.5);
	glVertex3f(41.0, -17.0, 13.5);
	glVertex3f(41.0, -24.0, 16.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(40.0, -24.0, 16.0);
	glVertex3f(40.0, -17.0, 13.5);
	glVertex3f(40.0, -17.0, 13.0);
	glVertex3f(40.0, -24.0, 15.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(41.0, -24.0, 16.0);
	glVertex3f(41.0, -17.0, 13.5);
	glVertex3f(41.0, -17.0, 13.0);
	glVertex3f(41.0, -24.0, 15.5);
	glEnd();

	//pintujembatan
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -16.8, 18.3);
	glVertex3f(41.5, -13.5, 18.3);
	glVertex3f(41.5, -13.5, 18.9);
	glVertex3f(41.5, -16.8, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -16.8, 18.9);
	glVertex3f(41.5, -16.8, 18.3);
	glVertex3f(45.0, -16.8, 18.3);
	glVertex3f(45.0, -16.8, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.75, -11.5, 18.9);
	glVertex3f(41.75, -11.5, 18.3);
	glVertex3f(44.75, -11.5, 18.3);
	glVertex3f(44.75, -11.5, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -13.5, 18.9);
	glVertex3f(41.5, -13.5, 18.3);
	glVertex3f(41.75, -11.5, 18.3);
	glVertex3f(41.75, -11.5, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(45.0, -13.5, 18.9);
	glVertex3f(45.0, -13.5, 18.3);
	glVertex3f(44.75, -11.5, 18.3);
	glVertex3f(44.75, -11.5, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(45.0, -16.8, 18.3);
	glVertex3f(45.0, -13.5, 18.3);
	glVertex3f(45.0, -13.5, 18.9);
	glVertex3f(45.0, -16.8, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -16.8, 18.9);
	glVertex3f(41.5, -13.5, 18.3);
	glVertex3f(45.0, -13.5, 18.3);
	glVertex3f(45.0, -16.8, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -13.5, 18.9);
	glVertex3f(41.75, -11.5, 18.3);
	glVertex3f(44.75, -11.5, 18.3);
	glVertex3f(45.0, -13.5, 18.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glVertex3f(42.5, -16.8, 19.0);
	glVertex3f(42.5, -13.5, 19.0);
	glVertex3f(44.0, -13.5, 19.0);
	glVertex3f(44.0, -16.8, 19.0);
	glEnd();
	//tangga turun
	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(42.5, -20.0, 22.0);
	glVertex3f(42.5, -16.8, 19.0);
	glVertex3f(44.0, -16.8, 19.0);
	glVertex3f(44.0, -20.0, 22.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(42.5, -20.0, 22.0);
	glVertex3f(42.5, -16.8, 19.0);
	glVertex3f(44.0, -16.8, 19.0);
	glVertex3f(44.0, -20.0, 22.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -20.0, 24.0);
	glVertex3f(41.5, -20.0, 22.0);
	glVertex3f(44.0, -20.0, 22.0);
	glVertex3f(44.0, -20.0, 24.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(41.5, -24.0, 19.0);
	glVertex3f(41.5, -20.0, 22.0);
	glVertex3f(42.5, -20.0, 22.0);
	glVertex3f(42.5, -24.0, 19.0);
	glEnd();

	//papan
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(32.5, -17.2, 18.4);
	glVertex3f(32.5, -15.0, 18.4);
	glVertex3f(35.0, -15.0, 18.4);
	glVertex3f(35.0, -17.2, 18.4);
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
	glVertex3f(29.5, -24.0, 21.5);
	glVertex3f(29.5, 12.0, 21.5);
	glVertex3f(29.5, 12.0, 22.5);
	glVertex3f(29.5, -24.0, 22.5);
	glEnd();

	//kotak tengah strip 1 dan 2
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -10.0, 20.0);
	glVertex3f(29.5, 9.0, 20.0);
	glVertex3f(29.5, 9.0, 19.5);
	glVertex3f(29.5, -10.0, 19.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -10.0, 8.0);
	glVertex3f(29.5, 9.0, 8.0);
	glVertex3f(29.5, 9.0, 8.5);
	glVertex3f(29.5, -10.0, 8.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -9.0, 20.0);
	glVertex3f(29.5, -10.0, 20.0);
	glVertex3f(29.5, -10.0, 8.0);
	glVertex3f(29.5, -9.0, 8.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, 9.0, 20.0);
	glVertex3f(29.5, 10.0, 20.0);
	glVertex3f(29.5, 10.0, 8.0);
	glVertex3f(29.5, 9.0, 8.0);
	glEnd();


	//strip 2
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, 5.5);
	glVertex3f(29.5, 12.0, 5.5);
	glVertex3f(29.5, 12.0, 6.5);
	glVertex3f(29.5, -24.0, 6.5);
	glEnd();

	//strip 3
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, -9.5);
	glVertex3f(29.5, 12.0, -9.5);
	glVertex3f(29.5, 12.0, -10.5);
	glVertex3f(29.5, -24.0, -10.5);
	glEnd();

	//strip 4
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(29.5, -24.0, -25.5);
	glVertex3f(29.5, 12.0, -25.5);
	glVertex3f(29.5, 12.0, -26.5);
	glVertex3f(29.5, -24.0, -26.5);
	glEnd();


	//kerucut 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, 30.0);
	glVertex3f(30.5, 0.0, 30.0);
	glVertex3f(29.5, 0.0, 32.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, 30.0);
	glVertex3f(30.5, 0.0, 30.0);
	glVertex3f(29.5, 0.0, 28.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, 30.0);
	glVertex3f(30.5, 0.0, 30.0);
	glVertex3f(29.5, 0.0, 32.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, 30.0);
	glVertex3f(30.5, 0.0, 30.0);
	glVertex3f(29.5, 0.0, 28.0);
	glEnd();

	//kerucut 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, -2.0);
	glVertex3f(30.5, 0.0, -2.0);
	glVertex3f(29.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, -2.0);
	glVertex3f(30.5, 0.0, -2.0);
	glVertex3f(29.5, 0.0, -4.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, -2.0);
	glVertex3f(30.5, 0.0, -2.0);
	glVertex3f(29.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, -2.0);
	glVertex3f(30.5, 0.0, -2.0);
	glVertex3f(29.5, 0.0, -4.0);
	glEnd();

	//kerucut 3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, -34.0);
	glVertex3f(30.5, 0.0, -34.0);
	glVertex3f(29.5, 0.0, -36.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.5, -6.0, -34.0);
	glVertex3f(30.5, 0.0, -34.0);
	glVertex3f(29.5, 0.0, -32.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, -34.0);
	glVertex3f(30.5, 0.0, -34.0);
	glVertex3f(29.5, 0.0, -36.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(29.5, -6.0, -34.0);
	glVertex3f(30.5, 0.0, -34.0);
	glVertex3f(29.5, 0.0, -32.0);
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
	glVertex3f(29.1, 12.0, 42.0);
	glVertex3f(29.1, 12.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 6.0, 42.0);
	glVertex3f(29.1, 6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, 0.0, 42.0);
	glVertex3f(29.1, 0.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -6.0, 42.0);
	glVertex3f(29.1, -6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -12.0, 42.0);
	glVertex3f(29.1, -12.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(29.1, -18.0, 42.0);
	glVertex3f(29.1, -18.0, -42.0);
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
	glVertex3f(-29.1, 12.0, 42.0);
	glVertex3f(-29.1, 12.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 6.0, 42.0);
	glVertex3f(-29.1, 6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, 0.0, 42.0);
	glVertex3f(-29.1, 0.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -6.0, 42.0);
	glVertex3f(-29.1, -6.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -12.0, 42.0);
	glVertex3f(-29.1, -12.0, -42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-29.1, -18.0, 42.0);
	glVertex3f(-29.1, -18.0, -42.0);
	glEnd();
}
void atasbawah(void) {

	//atas
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(-29.0, 8.0, -42.0);
	glVertex3f(-29.0, 8.0, 42.0);
	glVertex3f(29.0, 8.0, 42.0);
	glVertex3f(29.0, 8.0, -42.0);
	glEnd();

	//lapangan atas
	glBegin(GL_QUADS);
	glColor3f(0.07568f, 0.61424f, 0.07568f);
	glVertex3f(-20.0, 8.1, -10.0);
	glVertex3f(-20.0, 8.1, 10.0);
	glVertex3f(20.0, 8.1, 10.0);
	glVertex3f(20.0, 8.1, -10.0);
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

void selakiri(void) {
	//selakiri 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-29.0, 8.0, 32.0);
	glVertex3f(-29.0, 24.0, 32.0);
	glVertex3f(-24.0, 24.0, 32.0);
	glVertex3f(-24.0, 8.0, 32.0);
	glEnd();

	//selakiri 2
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 27.0);
	glVertex3f(-29.0, 24.0, 27.0);
	glVertex3f(-24.0, 24.0, 27.0);
	glVertex3f(-24.0, 8.0, 27.0);
	glEnd();

	//selakiri 3
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 22.0);
	glVertex3f(-29.0, 24.0, 22.0);
	glVertex3f(-24.0, 24.0, 22.0);
	glVertex3f(-24.0, 8.0, 22.0);
	glEnd();

	//selakiri 4
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 17.0);
	glVertex3f(-29.0, 24.0, 17.0);
	glVertex3f(-24.0, 24.0, 17.0);
	glVertex3f(-24.0, 8.0, 17.0);
	glEnd();

	//selakiri 5
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 12.0);
	glVertex3f(-29.0, 24.0, 12.0);
	glVertex3f(-24.0, 24.0, 12.0);
	glVertex3f(-24.0, 8.0, 12.0);
	glEnd();

	//selakiri 6
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 7.0);
	glVertex3f(-29.0, 24.0, 7.0);
	glVertex3f(-24.0, 24.0, 7.0);
	glVertex3f(-24.0, 8.0, 7.0);
	glEnd();

	//selakiri 7
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, 2.0);
	glVertex3f(-29.0, 24.0, 2.0);
	glVertex3f(-24.0, 24.0, 2.0);
	glVertex3f(-24.0, 8.0, 2.0);
	glEnd();

	//selakiri 8
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -3.0);
	glVertex3f(-29.0, 24.0, -3.0);
	glVertex3f(-24.0, 24.0, -3.0);
	glVertex3f(-24.0, 8.0, -3.0);
	glEnd();

	//selakiri 9
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -8.0);
	glVertex3f(-29.0, 24.0, -8.0);
	glVertex3f(-24.0, 24.0, -8.0);
	glVertex3f(-24.0, 8.0, -8.0);
	glEnd();

	//selakiri 10
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -13.0);
	glVertex3f(-29.0, 24.0, -13.0);
	glVertex3f(-24.0, 24.0, -13.0);
	glVertex3f(-24.0, 8.0, -13.0);
	glEnd();

	//selakiri 11
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -18.0);
	glVertex3f(-29.0, 24.0, -18.0);
	glVertex3f(-24.0, 24.0, -18.0);
	glVertex3f(-24.0, 8.0, -18.0);
	glEnd();

	//selakiri 12
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -23.0);
	glVertex3f(-29.0, 24.0, -23.0);
	glVertex3f(-24.0, 24.0, -23.0);
	glVertex3f(-24.0, 8.0, -23.0);
	glEnd();

	//selakiri 13
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -28.0);
	glVertex3f(-29.0, 24.0, -28.0);
	glVertex3f(-24.0, 24.0, -28.0);
	glVertex3f(-24.0, 8.0, -28.0);
	glEnd();

	//selakiri 14
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 8.0, -33.0);
	glVertex3f(-29.0, 24.0, -33.0);
	glVertex3f(-24.0, 24.0, -33.0);
	glVertex3f(-24.0, 8.0, -33.0);
	glEnd();


}
void selakanan(void) {
	//selakanan 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(29.0, 8.0, 32.0);
	glVertex3f(29.0, 24.0, 32.0);
	glVertex3f(24.0, 24.0, 32.0);
	glVertex3f(24.0, 8.0, 32.0);
	glEnd();

	//selakanan 2
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 27.0);
	glVertex3f(29.0, 24.0, 27.0);
	glVertex3f(24.0, 24.0, 27.0);
	glVertex3f(24.0, 8.0, 27.0);
	glEnd();

	//selakanan 3
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 22.0);
	glVertex3f(29.0, 24.0, 22.0);
	glVertex3f(24.0, 24.0, 22.0);
	glVertex3f(24.0, 8.0, 22.0);
	glEnd();

	//selakanan 4
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 17.0);
	glVertex3f(29.0, 24.0, 17.0);
	glVertex3f(24.0, 24.0, 17.0);
	glVertex3f(24.0, 8.0, 17.0);
	glEnd();

	//selakanan 5
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 12.0);
	glVertex3f(29.0, 24.0, 12.0);
	glVertex3f(24.0, 24.0, 12.0);
	glVertex3f(24.0, 8.0, 12.0);
	glEnd();

	//selakanan 6
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 7.0);
	glVertex3f(29.0, 24.0, 7.0);
	glVertex3f(24.0, 24.0, 7.0);
	glVertex3f(24.0, 8.0, 7.0);
	glEnd();

	//selakanan 7
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, 2.0);
	glVertex3f(29.0, 24.0, 2.0);
	glVertex3f(24.0, 24.0, 2.0);
	glVertex3f(24.0, 8.0, 2.0);
	glEnd();

	//selakanan 8
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -3.0);
	glVertex3f(29.0, 24.0, -3.0);
	glVertex3f(24.0, 24.0, -3.0);
	glVertex3f(24.0, 8.0, -3.0);
	glEnd();

	//selakanan 9
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -8.0);
	glVertex3f(29.0, 24.0, -8.0);
	glVertex3f(24.0, 24.0, -8.0);
	glVertex3f(24.0, 8.0, -8.0);
	glEnd();

	//selakanan 10
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -13.0);
	glVertex3f(29.0, 24.0, -13.0);
	glVertex3f(24.0, 24.0, -13.0);
	glVertex3f(24.0, 8.0, -13.0);
	glEnd();

	//selakanan 11
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -18.0);
	glVertex3f(29.0, 24.0, -18.0);
	glVertex3f(24.0, 24.0, -18.0);
	glVertex3f(24.0, 8.0, -18.0);
	glEnd();

	//selakanan 12
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -23.0);
	glVertex3f(29.0, 24.0, -23.0);
	glVertex3f(24.0, 24.0, -23.0);
	glVertex3f(24.0, 8.0, -23.0);
	glEnd();

	//selakanan 13
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -28.0);
	glVertex3f(29.0, 24.0, -28.0);
	glVertex3f(24.0, 24.0, -28.0);
	glVertex3f(24.0, 8.0, -28.0);
	glEnd();

	//selakanan 14
	glBegin(GL_QUADS);
	glVertex3f(29.0, 8.0, -33.0);
	glVertex3f(29.0, 24.0, -33.0);
	glVertex3f(24.0, 24.0, -33.0);
	glVertex3f(24.0, 8.0, -33.0);
	glEnd();


}
void seladepan(void) {

	//seladepan 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-20.0, 8.0, 36.0);
	glVertex3f(-20.0, 24.0, 36.0);
	glVertex3f(-20.0, 24.0, 42.0);
	glVertex3f(-20.0, 8.0, 42.0);
	glEnd();

	//seladepan 2
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 8.0, 36.0);
	glVertex3f(-15.0, 24.0, 36.0);
	glVertex3f(-15.0, 24.0, 42.0);
	glVertex3f(-15.0, 8.0, 42.0);
	glEnd();

	//seladepan 3
	glBegin(GL_QUADS);
	glVertex3f(-10.0, 8.0, 36.0);
	glVertex3f(-10.0, 24.0, 36.0);
	glVertex3f(-10.0, 24.0, 42.0);
	glVertex3f(-10.0, 8.0, 42.0);
	glEnd();

	//seladepan 4
	glBegin(GL_QUADS);
	glVertex3f(-5.0, 8.0, 36.0);
	glVertex3f(-5.0, 24.0, 36.0);
	glVertex3f(-5.0, 24.0, 42.0);
	glVertex3f(-5.0, 8.0, 42.0);
	glEnd();

	//seladepan 5
	glBegin(GL_QUADS);
	glVertex3f(0.0, 8.0, 36.0);
	glVertex3f(0.0, 24.0, 36.0);
	glVertex3f(0.0, 24.0, 42.0);
	glVertex3f(0.0, 8.0, 42.0);
	glEnd();

	//seladepan 6
	glBegin(GL_QUADS);
	glVertex3f(5.0, 8.0, 36.0);
	glVertex3f(5.0, 24.0, 36.0);
	glVertex3f(5.0, 24.0, 42.0);
	glVertex3f(5.0, 8.0, 42.0);
	glEnd();

	//seladepan 7
	glBegin(GL_QUADS);
	glVertex3f(10.0, 8.0, 36.0);
	glVertex3f(10.0, 24.0, 36.0);
	glVertex3f(10.0, 24.0, 42.0);
	glVertex3f(10.0, 8.0, 42.0);
	glEnd();

	//seladepan 8
	glBegin(GL_QUADS);
	glVertex3f(15.0, 8.0, 36.0);
	glVertex3f(15.0, 24.0, 36.0);
	glVertex3f(15.0, 24.0, 42.0);
	glVertex3f(15.0, 8.0, 42.0);
	glEnd();

	//seladepan 9
	glBegin(GL_QUADS);
	glVertex3f(20.0, 8.0, 36.0);
	glVertex3f(20.0, 24.0, 36.0);
	glVertex3f(20.0, 24.0, 42.0);
	glVertex3f(20.0, 8.0, 42.0);
	glEnd();

}
void selabelakang(void) {
	//selablkng 1
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-20.0, 8.0, -36.0);
	glVertex3f(-20.0, 24.0, -36.0);
	glVertex3f(-20.0, 24.0, -42.0);
	glVertex3f(-20.0, 8.0, -42.0);
	glEnd();

	//selablkg 2
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 8.0, -36.0);
	glVertex3f(-15.0, 24.0, -36.0);
	glVertex3f(-15.0, 24.0, -42.0);
	glVertex3f(-15.0, 8.0, -42.0);
	glEnd();

	//selablkg 3
	glBegin(GL_QUADS);
	glVertex3f(-10.0, 8.0, -36.0);
	glVertex3f(-10.0, 24.0, -36.0);
	glVertex3f(-10.0, 24.0, -42.0);
	glVertex3f(-10.0, 8.0, -42.0);
	glEnd();

	//selablkg 4
	glBegin(GL_QUADS);
	glVertex3f(-5.0, 8.0, -36.0);
	glVertex3f(-5.0, 24.0, -36.0);
	glVertex3f(-5.0, 24.0, -42.0);
	glVertex3f(-5.0, 8.0, -42.0);
	glEnd();

	//selablkg 5
	glBegin(GL_QUADS);
	glVertex3f(0.0, 8.0, -36.0);
	glVertex3f(0.0, 24.0, -36.0);
	glVertex3f(0.0, 24.0, -42.0);
	glVertex3f(0.0, 8.0, -42.0);
	glEnd();

	//selablkg 6
	glBegin(GL_QUADS);
	glVertex3f(5.0, 8.0, -36.0);
	glVertex3f(5.0, 24.0, -36.0);
	glVertex3f(5.0, 24.0, -42.0);
	glVertex3f(5.0, 8.0, -42.0);
	glEnd();

	//selablkg 7
	glBegin(GL_QUADS);
	glVertex3f(10.0, 8.0, -36.0);
	glVertex3f(10.0, 24.0, -36.0);
	glVertex3f(10.0, 24.0, -42.0);
	glVertex3f(10.0, 8.0, -42.0);
	glEnd();

	//selablkg 8
	glBegin(GL_QUADS);
	glVertex3f(15.0, 8.0, -36.0);
	glVertex3f(15.0, 24.0, -36.0);
	glVertex3f(15.0, 24.0, -42.0);
	glVertex3f(15.0, 8.0, -42.0);
	glEnd();

	//selablkg 9
	glBegin(GL_QUADS);
	glVertex3f(20.0, 8.0, -36.0);
	glVertex3f(20.0, 24.0, -36.0);
	glVertex3f(20.0, 24.0, -42.0);
	glVertex3f(20.0, 8.0, -42.0);
	glEnd();
}
void ornamenatas(void) {

	//depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-29.0, 8.0, 37.0);
	glVertex3f(-29.0, 24.0, 37.0);
	glVertex3f(29.0, 24.0, 37.0);
	glVertex3f(29.0, 8.0, 37.0);
	glEnd();

	//depan 1
	glBegin(GL_QUADS);
	glVertex3f(-24.0, 16.0, 36.0);
	glVertex3f(-24.0, 16.0, 42.0);
	glVertex3f(24.0, 16.0, 42.0);
	glVertex3f(24.0, 16.0, 36.0);
	glEnd();

	seladepan();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-25.0, 8.0, -42.0);
	glVertex3f(-25.0, 24.0, -42.0);
	glVertex3f(-25.0, 24.0, 42.0);
	glVertex3f(-25.0, 8.0, 42.0);
	glEnd();

	//kiri 1
	glBegin(GL_QUADS);
	glVertex3f(-29.0, 16.0, -42.0);
	glVertex3f(-29.0, 16.0, 42.0);
	glVertex3f(-24.0, 16.0, 42.0);
	glVertex3f(-24.0, 16.0, -42.0);
	glEnd();

	selakiri();

	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(25.0, 8.0, -42.0);
	glVertex3f(25.0, 24.0, -42.0);
	glVertex3f(25.0, 24.0, 42.0);
	glVertex3f(25.0, 8.0, 42.0);
	glEnd();

	//kanan 1
	glBegin(GL_QUADS);
	glVertex3f(29.0, 16.0, -42.0);
	glVertex3f(29.0, 16.0, 42.0);
	glVertex3f(24.0, 16.0, 42.0);
	glVertex3f(24.0, 16.0, -42.0);
	glEnd();

	selakanan();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-29.0, 8.0, -37.0);
	glVertex3f(-29.0, 24.0, -37.0);
	glVertex3f(29.0, 24.0, -37.0);
	glVertex3f(29.0, 8.0, -37.0);
	glEnd();

	//belakang 1
	glBegin(GL_QUADS);
	glVertex3f(-24.0, 16.0, -35.0);
	glVertex3f(-24.0, 16.0, -42.0);
	glVertex3f(24.0, 16.0, -42.0);
	glVertex3f(24.0, 16.0, -35.0);
	glEnd();

	selabelakang();

	//banner/kotak diatep

	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(17.9, 26.4, 30.0);
	glVertex3f(17.9, 36.2, 30.0);
	glVertex3f(17.9, 36.2, 42.2);
	glVertex3f(17.9, 26.4, 42.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.9, 26.4, 30.0);
	glVertex3f(17.9, 24.0, 30.0);
	glVertex3f(17.9, 24.0, 42.2);
	glVertex3f(17.9, 26.4, 42.2);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(14.1, 26.4, 30.0);
	glVertex3f(14.1, 36.2, 30.0);
	glVertex3f(14.1, 36.2, 42.2);
	glVertex3f(14.1, 26.4, 42.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.1, 26.4, 30.0);
	glVertex3f(14.1, 24.0, 30.0);
	glVertex3f(14.1, 24.0, 42.2);
	glVertex3f(14.1, 26.4, 42.2);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(14.1, 36.2, 30);
	glVertex3f(14.1, 24, 30);
	glVertex3f(17.9, 24, 30);
	glVertex3f(17.9, 36.2, 30);
	glEnd();

	//beam ato penyangga
	glBegin(GL_LINE_LOOP);
	glVertex3f(17.9, 24, 30);
	glVertex3f(24, 24, 30);
	glEnd();

	//2
	glBegin(GL_LINE_LOOP);
	glVertex3f(21.4, 24, 30);
	glVertex3f(24, 19, 30);
	glEnd();

	//3
	glBegin(GL_LINE_LOOP);
	glVertex3f(16, 24, 30);
	glVertex3f(16, 8, 30);
	glEnd();

	//4
	glBegin(GL_LINE_LOOP);
	glVertex3f(21.4, 24, 30);
	glVertex3f(16, 8, 30);
	glEnd();
}


void ling(void)
{
	glColor3f(0.0, 0.0, 0.0);
	//lingkaran kanan
	lingkaran2(1.7, 100.0, 22.0, 15.0, 29.2);
	lingkaran2(1.7, 100.0, 6.0, 15.0, 29.2);
	lingkaran2(1.7, 100.0, -10.0, 15.0, 29.2);
	lingkaran2(1.7, 100.0, -26.0, 15.0, 29.2);
	lingkaran2(1.7, 100.0, 30.0, -8.0, 29.2);
	lingkaran2(1.7, 100.0, 30.0, -12.0, 29.2);
	lingkaran2(1.7, 100.0, 30.0, -16.0, 29.2);
	lingkaran2(1.7, 100.0, -2.0, -8.0, 29.2);
	lingkaran2(1.7, 100.0, -2.0, -12.0, 29.2);
	lingkaran2(1.7, 100.0, -2.0, -16.0, 29.2);
	lingkaran2(1.7, 100.0, -34.0, -8.0, 29.2);
	lingkaran2(1.7, 100.0, -34.0, -12.0, 29.2);
	lingkaran2(1.7, 100.0, -34.0, -16.0, 29.2);

	lingkaran(1.0, 100.0, -17.0, 14.0, 42.5);

	lingkaran(1.0, 100.0, -15.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, -13.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, -11.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, -9.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, -7.0, 2.0, 42.5);

	lingkaran(1.0, 100.0, 13.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, 11.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, 9.0, 2.0, 42.5);
	lingkaran(1.0, 100.0, 7.0, 2.0, 42.5);

	lingkaran(1.0, 100.0, -23.0, -9.0, 42.5);
	lingkaran(1.0, 100.0, -23.0, -12.0, 42.5);
	lingkaran(1.0, 100.0, -23.0, -15.0, 42.5);

	lingkaran(1.0, 100.0, -11.0, -9.0, 42.5);
	lingkaran(1.0, 100.0, -11.0, -12.0, 42.5);
	lingkaran(1.0, 100.0, -11.0, -15.0, 42.5);

	lingkaran(1.0, 100.0, 11.0, -9.0, 42.5);
	lingkaran(1.0, 100.0, 11.0, -12.0, 42.5);
	lingkaran(1.0, 100.0, 11.0, -15.0, 42.5);

	lingkaran(1.0, 100.0, 23.0, -9.0, 42.5);
	lingkaran(1.0, 100.0, 23.0, -12.0, 42.5);
	lingkaran(1.0, 100.0, 23.0, -15.0, 42.5);
}

void objek(void)
{
	//pohon
	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0, -23.9, 39.0);
	glVertex3f(11.0, -20.0, 39.0);
	glVertex3f(13.0, -20.0, 39.0);
	glVertex3f(13.0, -23.9, 39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0, -23.9, 37.0);
	glVertex3f(11.0, -20.0, 37.0);
	glVertex3f(13.0, -20.0, 37.0);
	glVertex3f(13.0, -23.9, 37.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0, -23.9, 37.0);
	glVertex3f(11.0, -20.0, 37.0);
	glVertex3f(11.0, -20.0, 39.0);
	glVertex3f(11.0, -23.9, 39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(13.0, -23.9, 37.0);
	glVertex3f(13.0, -20.0, 37.0);
	glVertex3f(13.0, -20.0, 39.0);
	glVertex3f(13.0, -23.9, 39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5882, 0.2941, 0.0);
	glVertex3f(11.0, -23.9, 37.0);
	glVertex3f(13.0, -23.9, 37.0);
	glVertex3f(13.0, -23.9, 39.0);
	glVertex3f(11.0, -23.9, 39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(9.0, -20.0, 35.0);
	glVertex3f(15.0, -20.0, 35.0);
	glVertex3f(15.0, -20.0, 41.0);
	glVertex3f(9.0, -20.0, 41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0, -12.0, 38.0);
	glVertex3f(15.0, -20.0, 41.0);
	glVertex3f(9.0, -20.0, 41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0, -12.0, 38.0);
	glVertex3f(9.0, -20.0, 35.0);
	glVertex3f(9.0, -20.0, 41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0, -12.0, 38.0);
	glVertex3f(15.0, -20.0, 35.0);
	glVertex3f(15.0, -20.0, 41.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(12.0, -12.0, 38.0);
	glVertex3f(15.0, -20.0, 35.0);
	glVertex3f(15.0, -20.0, 35.0);
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

	bagiankanan();
	kanankiri();
	depanbelakang();
	atasbawah();
	ornamenatas();
	objek();
	ling();



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
