/*KETERANGAN
q/Q = atas
a/A = bawah
w/W = kiri
s/S = kanan
e/E = zoom in
d/D = zoom out
z/Z = Atas 
x/X = Bawah
c/C = Kiri
v/V = Kanan
b/B = Miring kiri
n/N = Miring Kanan

mouse + klik kiri = rotasi
*/

#include <windows.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void myInit() {
    glClearColor((float)0 / 255.0f, (float)33 / 255.0f, (float)110 / 255.0f, 1);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, -100.0f);
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void warna(int r = 1, int g = 1, int b = 1, float a = 1) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void depanbelakang(int panjang = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, (1 * tinggi) + p_y, 0 + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void kirikanan(int lebar = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void atasbawah(int panjang = 1, int lebar = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glEnd();
}

void rumah() {
	//tanah
	warna(125,82,26);
   atasbawah(100,100,-50,0,40);
   atasbawah(100,100,-50,-20,40);
   warna(242,168,112);
   depanbelakang(100,20,-50,-20,40);
   depanbelakang(100,20,-50,-20,-60);
   kirikanan(100,20,-50,-20,40);
   kirikanan(100,20,50,-20,40);
   

   //rantai kanan
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(255/255.0f, 255/255.0f, 255/255.0f);
	glVertex3f(26.0, 0.0, 25.0);
	glVertex3f(28.0, 1.0, 25.0);
	glVertex3f(30.0, 4.0, 25.0);
	glVertex3f(30.0, 6.0, 25.0);
	glVertex3f(28.0, 9.0, 25.0);
	glVertex3f(26.0, 10.0, 25.0);
	glVertex3f(-26.0, 10.0, 25.0);
	glVertex3f(-28.0, 9.0, 25.0);
	glVertex3f(-30.0, 6.0, 25.0);
	glVertex3f(-30.0, 4.0, 25.0);
	glVertex3f(-28.0, 1.0, 25.0);
	glVertex3f(-26.0, 0.0, 25.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(255/255.0f, 255/255.0f, 255/255.0f);
	glVertex3f(26.0, 0.0, 15.0);
	glVertex3f(28.0, 1.0, 15.0);
	glVertex3f(30.0, 4.0, 15.0);
	glVertex3f(30.0, 6.0, 15.0);
	glVertex3f(28.0, 9.0, 15.0);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(-26.0, 10.0, 15.0);
	glVertex3f(-28.0, 9.0, 15.0);
	glVertex3f(-30.0, 6.0, 15.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glVertex3f(-28.0, 1.0, 15.0);
	glVertex3f(-26.0, 0.0, 15.0);
	glEnd();
	//selimut atas
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(26.0, 10.0, 26.0);
	glVertex3f(-26.0, 10.0, 26.0);
	glVertex3f(-26.0, 10.0, 15.0);
	glEnd();
	//selimut bawah
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, 25.0);
	glVertex3f(26.0, 0.0, 26.0);
	glVertex3f(-26.0, 0.0, 26.0);
	glVertex3f(-26.0, 0.0, 25.0);
	glEnd();
	//selimut ataskanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(26.0, 10.0, 26.0);
	glVertex3f(28.0, 9.0, 26.0);
	glVertex3f(28.0, 9.0, 15.0);
	glEnd();
	//selimut ataskanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 9.0, 15.0);
	glVertex3f(28.0, 9.0, 26.0);
	glVertex3f(30.0, 6.0, 26.0);
	glVertex3f(30.0, 6.0, 15.0);
	glEnd();
	//selimut sampingkanan
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(30.0, 6.0, 15.0);
	glVertex3f(30.0, 6.0, 26.0);
	glVertex3f(30.0, 4.0, 26.0);
	glVertex3f(30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 1.0, 15.0);
	glVertex3f(28.0, 1.0, 26.0);
	glVertex3f(30.0, 4.0, 26.0);
	glVertex3f(30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, 15.0);
	glVertex3f(26.0, 0.0, 26.0);
	glVertex3f(28.0, 1.0, 26.0);
	glVertex3f(28.0, 1.0, 15.0);
	glEnd();
	//selimut ataskiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 10.0, 15.0);
	glVertex3f(-26.0, 10.0, 26.0);
	glVertex3f(-28.0, 9.0, 26.0);
	glVertex3f(-28.0, 9.0, 15.0);
	glEnd();
	//selimut ataskiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 9.0, 15.0);
	glVertex3f(-28.0, 9.0, 26.0);
	glVertex3f(-30.0, 6.0, 26.0);
	glVertex3f(-30.0, 6.0, 15.0);
	glEnd();
	//selimut sampingkiri
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-30.0, 6.0, 15.0);
	glVertex3f(-30.0, 6.0, 26.0);
	glVertex3f(-30.0, 4.0, 26.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 1.0, 15.0);
	glVertex3f(-28.0, 1.0, 26.0);
	glVertex3f(-30.0, 4.0, 26.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 0.0, 15.0);
	glVertex3f(-26.0, 0.0, 26.0);
	glVertex3f(-28.0, 1.0, 26.0);
	glVertex3f(-28.0, 1.0, 15.0);
	glEnd();

	//rantai kiri
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(255/255.0f, 255/255.0f, 255/255.0f);
	glVertex3f(26.0, 0.0, -25.0);
	glVertex3f(28.0, 1.0, -25.0);
	glVertex3f(30.0, 4.0, -25.0);
	glVertex3f(30.0, 6.0, -25.0);
	glVertex3f(28.0, 9.0, -25.0);
	glVertex3f(26.0, 10.0, -25.0);
	glVertex3f(-26.0, 10.0, -25.0);
	glVertex3f(-28.0, 9.0, -25.0);
	glVertex3f(-30.0, 6.0, -25.0);
	glVertex3f(-30.0, 4.0, -25.0);
	glVertex3f(-28.0, 1.0, -25.0);
	glVertex3f(-26.0, 0.0, -25.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(255/255.0f, 255/255.0f, 255/255.0f);
	glVertex3f(26.0, 0.0, -15.0);
	glVertex3f(28.0, 1.0, -15.0);
	glVertex3f(30.0, 4.0, -15.0);
	glVertex3f(30.0, 6.0, -15.0);
	glVertex3f(28.0, 9.0, -15.0);
	glVertex3f(26.0, 10.0,-15.0);
	glVertex3f(-26.0, 10.0, -15.0);
	glVertex3f(-28.0, 9.0, -15.0);
	glVertex3f(-30.0, 6.0, -15.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glVertex3f(-28.0, 1.0, -15.0);
	glVertex3f(-26.0, 0.0, -15.0);
	glEnd();
	//selimut atas
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, -15.0);
	glVertex3f(26.0, 10.0, -26.0);
	glVertex3f(-26.0, 10.0, -26.0);
	glVertex3f(-26.0, 10.0, -15.0);
	glEnd();
	//selimut bawah
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, -25.0);
	glVertex3f(26.0, 0.0, -26.0);
	glVertex3f(-26.0, 0.0, -26.0);
	glVertex3f(-26.0, 0.0, -25.0);
	glEnd();
	//selimut ataskanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, -15.0);
	glVertex3f(26.0, 10.0, -26.0);
	glVertex3f(28.0, 9.0, -26.0);
	glVertex3f(28.0, 9.0, -15.0);
	glEnd();
	//selimut ataskanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 9.0, -15.0);
	glVertex3f(28.0, 9.0, -26.0);
	glVertex3f(30.0, 6.0, -26.0);
	glVertex3f(30.0, 6.0, -15.0);
	glEnd();
	//selimut sampingkanan
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(30.0, 6.0, -15.0);
	glVertex3f(30.0, 6.0, -26.0);
	glVertex3f(30.0, 4.0, -26.0);
	glVertex3f(30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 1.0, -15.0);
	glVertex3f(28.0, 1.0, -26.0);
	glVertex3f(30.0, 4.0, -26.0);
	glVertex3f(30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, -15.0);
	glVertex3f(26.0, 0.0, -26.0);
	glVertex3f(28.0, 1.0, -26.0);
	glVertex3f(28.0, 1.0, -15.0);
	glEnd();

	//selimut ataskiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 10.0, -15.0);
	glVertex3f(-26.0, 10.0, -26.0);
	glVertex3f(-28.0, 9.0, -26.0);
	glVertex3f(-28.0, 9.0, -15.0);
	glEnd();
	//selimut ataskiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 9.0, -15.0);
	glVertex3f(-28.0, 9.0, -26.0);
	glVertex3f(-30.0, 6.0, -26.0);
	glVertex3f(-30.0, 6.0, -15.0);
	glEnd();
	//selimut sampingkiri
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-30.0, 6.0, -15.0);
	glVertex3f(-30.0, 6.0, -26.0);
	glVertex3f(-30.0, 4.0, -26.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 1.0, -15.0);
	glVertex3f(-28.0, 1.0, -26.0);
	glVertex3f(-30.0, 4.0, -26.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 0.0, -15.0);
	glVertex3f(-26.0, 0.0, -26.0);
	glVertex3f(-28.0, 1.0, -26.0);
	glVertex3f(-28.0, 1.0, -15.0);
	glEnd();
	//penghubung rantai
	//dudukan atas bawah
	warna(248, 194, 92);
	atasbawah(35.0, 30.0, -15.0, 8.0, 15.0);
	atasbawah(35.0, 30.0, -15.0, 4.0, 15.0);
	////dudukan kiri kanan
	warna(155,155,155);
	kirikanan(30,4,-15,4,15);
	kirikanan(30,4,20,4,15);
	
	//leher
	//leher belakang
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, -3.0);
	glVertex3f(-10, 8.0, -3.0);
	glVertex3f(-3, 8.0, -10.0);
	glVertex3f(-3, 13.0, -10.0);
	glVertex3f(-3, 13.0, -10.0);
	glVertex3f(-3, 8.0, -10.0);
	glVertex3f(3, 8.0, -10.0);
	glVertex3f(3, 13.0, -10.0);
	glVertex3f(3, 13.0, -10.0);
	glVertex3f(3, 8.0, -10.0);
	glVertex3f(10, 8.0,-3.0);
	glVertex3f(10, 13.0, -3.0);
	glEnd();
	//leher depan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, 3.0);
	glVertex3f(-10, 8.0, 3.0);
	glVertex3f(-3, 8.0, 10.0);
	glVertex3f(-3, 13.0, 10.0);
	glVertex3f(-3, 13.0, 10.0);
	glVertex3f(-3, 8.0, 10.0);
	glVertex3f(3, 8.0, 10.0);
	glVertex3f(3, 13.0, 10.0);
	glVertex3f(3, 13.0, 10.0);
	glVertex3f(3, 8.0, 10.0);
	glVertex3f(10, 8.0,3.0);
	glVertex3f(10, 13.0, 3.0);
	glEnd();
	//leher kanan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(10, 13.0, -3.0);
	glVertex3f(10, 8.0, -3.0);
	glVertex3f(10, 8.0, 3.0);
	glVertex3f(10, 13.0, 3.0);
	glEnd();
	//kiri
	//leher kanan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, -3.0);
	glVertex3f(-10, 8.0, -3.0);
	glVertex3f(-10, 8.0, 3.0);
	glVertex3f(-10, 13.0, 3.0);
	glEnd();

	//bodi
	//bodi atas
	glBegin(GL_POLYGON);
	glColor3f(175/255.0f, 155/255.0f, 255/255.0f);
	glVertex3f(16, 35.0, 22.0);
	glVertex3f(16, 35.0, -22.0);
	glVertex3f(-35, 35.0, -22.0);
	glVertex3f(-40, 35.0, -15.0);
	glVertex3f(-40, 35.0, 15.0);
	glVertex3f(-35, 35.0, 22.0);
	glEnd();
	//bodi depan
	glBegin(GL_POLYGON);
	glColor3f(270/255.0f, 218/255.0f, 0/255.0f);
	glVertex3f(16, 35.0, 22.0);
	glVertex3f(16, 35.0, -22.0);
	glVertex3f(16, 18.0, -22.0);
	glVertex3f(16, 13.0, -15.0);
	glVertex3f(16, 13.0, 15.0);
	glVertex3f(16, 18.0, 22.0);
	glVertex3f(16, 35.0, 22.0);
	glEnd();
	//depan2
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(10, 35.0, 22.0);
	glVertex3f(10, 35.0, -22.0);
	glVertex3f(10, 18.0, -22.0);
	glVertex3f(10, 13.0, -15.0);
	glVertex3f(10, 13.0, 15.0);
	glVertex3f(10, 18.0, 22.0);
	glVertex3f(10, 35.0, 22.0);
	glEnd();
	//bawah miring kanan
	glBegin(GL_POLYGON);
	glColor3f(240/255.0f, 188/255.0f, 0/255.0f);
	glVertex3f(10, 18.0, 22.0);
	glVertex3f(16, 18.0, 22.0);
	glVertex3f(16, 13.0, 15.0);
	glVertex3f(10, 13.0, 15.0);
	glEnd();
	//bawah miring kiri
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(10, 18.0, -22.0);
	glVertex3f(16, 18.0, -22.0);
	glVertex3f(16, 13.0, -15.0);
	glVertex3f(10, 13.0, -15.0);
	glEnd();
	//depan kanan kiri
	warna(265, 213, 0);
	depanbelakang(6, 17, 10, 18, -22);
	depanbelakang(6, 17, 10, 18, 22);
	kirikanan(30, 22, -40, 13, 15);

	//belakang miring
	glBegin(GL_POLYGON);
	glColor3f(235/255.0f, 183/255.0f, 0/255.0f);
	glVertex3f(-40, 35.0, 15.0);
	glVertex3f(-40, 13.0, 15.0);
	glVertex3f(-35, 13.0, 22.0);
	glVertex3f(-35, 35.0, 22.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235/255.0f, 183/255.0f, 0/255.0f);
	glVertex3f(-40, 35.0, -15.0);
	glVertex3f(-40, 13.0, -15.0);
	glVertex3f(-35, 13.0, -22.0);
	glVertex3f(-35, 35.0, -22.0);
	glEnd();

	//belakang2
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(-28.2, 35.0, 22.0);
	glVertex3f(-28.2, 13.0, 22.0);
	glVertex3f(-28.2, 13.0, -22.0);
	glVertex3f(-28.2, 35.0, -22.0);
	glEnd();
	//belakang bawah
	glBegin(GL_POLYGON);
	glColor3f(145/255.0f, 93/255.0f, 0/255.0f);
	glVertex3f(-28.2, 13.1, 22.0);
	glVertex3f(-35, 13.1, 22.0);
	glVertex3f(-40, 13.1, 15.0);
	glVertex3f(-40, 13.1, -15.0);
	glVertex3f(-35, 13.1, -22.0);
	glVertex3f(-28.2, 13.1, -22.0);
	glEnd();

	//bodi belakang
	warna(265, 213, 0);
	depanbelakang(7, 22, -35, 13, 22);
	depanbelakang(7, 22, -35, 13, -22);

	//bodi tengah
	//depan belakang
	warna(265, 213, 0);
	kirikanan(44,17,9.9,18,22);
	kirikanan(44,17,-28,18,22);
	kirikanan(32,5,9.9,13,16);
	kirikanan(32, 5, -28, 13, 16);
	//kanan kiri
	warna(265, 213, 0);
	depanbelakang(38, 17, -28, 18, 22);
	depanbelakang(38, 17, -28, 18, -22);
	warna(205, 153, 0);
	atasbawah(38, 6.8, -28, 18, 22);
	atasbawah(38, 6.8, -28, 18, -16);
	warna(225, 173, 0);
	depanbelakang(38, 5, -28, 13, 16);
	depanbelakang(38, 5, -28, 13, -16);
	warna(56, 60, 66);
	atasbawah(38, 32, -28, 13, 16);
	
}


void tampil() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        gluLookAt(-45, 15, 150, 0, 0, 0, 0, 1, 0);
        glRotatef(xrot, 1, 0, 0);
        glRotatef(yrot, 0, 1, 0);
        rumah();
		
    glPopMatrix();

    glutSwapBuffers();
}



void key(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
            glTranslatef(-1.0, 0.0, 0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(1.0, 0.0, 0.0);
            break;
        case 'e':
        case 'E':
            glTranslatef(0.0, 0.0, 1.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(0.0, 0.0, -1.0);
            break;
        case 'q':
        case 'Q':
            glTranslatef(0.0, 1.0, 0.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(0.0, -1.0, 0.0);
            break;
        case 'v':
        case 'V':
            glRotatef(1.0, 0.0, -5.0, 0.0);
            break;
        case 'c':
        case 'C':
            glRotatef(1.0, 0.0, 5.0, 0.0);
            break;
        case 'b':
        case 'B':
            glRotatef(1.0, 0.0, 0.0, -5.0);
            break;
        case 'n':
        case 'N':
            glRotatef(1.0, 0.0, 0.0, 5.0);
            break;
        case 'x':
        case 'X':
            glRotatef(1.0, -5.0, 0.0, 0.0);
            break;
        case 'z':
        case 'Z':
            glRotatef(1.0, 5.0, 0.0, 0.0);
            break;
    }
    cout << key << endl;
    tampil();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(133, 54);
    glutCreateWindow("Danu Satria Wiratama - 672018183");
    myInit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(tampil);
    glutKeyboardFunc(key);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}