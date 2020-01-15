//
//  Dibujos.cpp
//  OpenGL_Demo
//
//  Created by Jack Robles García on 5/22/18.
//  Copyright © 2018 Alnilam Games. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include "Dibujos.hpp"
Pooh::Pooh (int Kedad, int Kcintura) {
    edad = Kedad;
    cintura = Kcintura;
}

void Pooh::Accion () {
    std::cout<<"Soy Pooh y veo que mi cintura mide "<<cintura<<"cm. Creo que es por mucha miel"<<std::endl;
    
}

void Pooh::Comer(){
    std::cout<<"Me dio hambre así que iré a comer algo de miel, perfecta par un oso de "<<edad<<"años."<<std::endl;
}

void Circulo (float posX,float posY,float radio,int puntos,float sX, float sY) {
    int i=0;
    float angulo = 0;
    glBegin(GL_POLYGON);
    for (i=0;i<puntos;i++){
        angulo= 2*M_PI*i/puntos;
        glVertex2f(posX + posX*cos(angulo)*sX, posY*sin(angulo)*sY);
        std::cout<<i<<std::endl;
    }
    glEnd();
}


