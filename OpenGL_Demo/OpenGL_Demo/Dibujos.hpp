//
//  Dibujos.hpp
//  OpenGL_Demo
//
//  Created by Jack Robles García on 5/22/18.
//  Copyright © 2018 Alnilam Games. All rights reserved.
//

#ifndef Dibujos_hpp
#define Dibujos_hpp

#include <iostream>
//void Circulo(float centrox,float centroY,float rad);
//void Tacha(float Centro);
class Pooh {
private:
    int edad;
    int cintura;
public:
    Pooh (int,int);
    void Accion();
    void Comer();
};

void Circulo (float posX,float posY,float radio,int puntos,float sX, float sY);

#endif /* Dibujos_hpp */
