//  main.cpp
//  OpenGL_Demo
//
//  Created by Jack Robles García on 3/19/18.
//  Copyright © 2018 Alnilam Games. All rights reserved.
//
/*
#include<iostream>
#include "Dibujos.hpp"
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

#define Altura 400
#define Ancho 400 
int rot=0;

void draw_ball() {
    glColor3f(0.0, 0.0, 1.0);
    glScalef(1.3, 1.0, 1.0);
    Circulo(0.0, 0.0, 5.0, 100, 1.0, 1.0);
    
}

void Display (void) {
    //Swap buffers
    glutSwapBuffers();
    //
    glClear(GL_COLOR_BUFFER_BIT);
    Circulo(Altura/2, Ancho/2, 5.0, 100, 1.0, 0.5);
    glLoadIdentity();
    glFlush();
}
void reshape(int w, int h){
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D(0.0, Ancho, 0.0, Altura);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();

}

void init (void){
     glClearColor(0.0,0.8,0.0,1.0);
}
int main(int argc,char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Altura,Ancho);
    glutCreateWindow("Space Invaders");
    init();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutIdleFunc(Display);
    glutMainLoop();
    return 0;
}
*/
#include "Dibujos.hpp"
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <iostream>
int RadiusOfBall = 20, Altura=800, Ancho=500;
double xpos=RadiusOfBall, ypos=RadiusOfBall, ydir=1, xdir=1;  // x and y position for house to be drawn
GLint circle_points = 100;
#define PI 3.1415926535898

void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius) {
    GLint i;
    GLdouble angle;
    glBegin(GL_POLYGON);
    for (i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(centerx+radius*cos(angle), centery+radius*sin(angle));
    }
    glEnd();
}


// Draw the ball, centered at the origin
void draw_ball() {
    glColor3f(0.0,0.5,1.0);
    MyCircle2f(0.,0.,RadiusOfBall);
    if (xpos>Ancho-RadiusOfBall){
        xdir= -1;
    } else if (xpos<RadiusOfBall) {
        xdir= 1;
    }
    std::cout<<xpos<<std::endl;
    xpos = xpos+xdir;
}

void Display(void) {
    // swap the buffers
    glutSwapBuffers();
    //clear all pixels with the specified clear color
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // aplicar translación
    glTranslatef(xpos,ypos, 0.0);
    // dibujar pelota
    draw_ball();
    MyCircle2f(Ancho/2, Altura/2, 20);
    glutPostRedisplay();
}



void reshape (int w, int h) {
    // on reshape and on startup, keep the viewport to be the entire size of the window
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    // keep our logical coordinate system constant
    gluOrtho2D(0.0, Ancho, 0.0, Altura);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
}

void init(void) {
    //Color verde
    glClearColor(1.0,0.8,0.0,1.0);
}


int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Altura,Ancho);
    glutCreateWindow("Space Invaders");
    init();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutIdleFunc(Display);
    glutMainLoop();
    return 0;
}
