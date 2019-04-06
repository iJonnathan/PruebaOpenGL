//
//  main.cpp
//  TestOpenGL
//
//  Created by iJonna on 4/5/19.
//  Copyright © 2019 iJonna. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <stdio.h>

// Brecha entre las ventanas
#define GAP 10
// numeros de ventanas del programa
int ventanaGLMain, ventanaGL1, ventanaGL2, ventanaGL3, ventanaGL4;

void pantalla(void){
    // Borra varios búferes de color simultáneamente
    glClear(GL_COLOR_BUFFER_BIT);
    // vacia todos los buffers incluyendo buffers de red y acelerador de gráficos.
    glFlush();
}
void reshape(int w, int h){
    int width = 50;
    int height = 50;
    // establece las coordenadas de la ventana
    glViewport(0, 0, w, h);
    if (w > 50) {
        width = (w - 3 * GAP) / 2;
    } else {
        width = 10;
    }
    if (h > 50) {
        height = (h - 3 * GAP) / 2;
    } else {
        height = 10;
    }
    // posiciona y remodela cada una de las ventanas
    glutSetWindow(ventanaGL1);
    glutPositionWindow(GAP, GAP);
    glutReshapeWindow(width, height);
    glutSetWindow(ventanaGL2);
    glutPositionWindow(GAP + width + GAP, GAP);
    glutReshapeWindow(width, height);
    glutSetWindow(ventanaGL3);
    glutPositionWindow(GAP, GAP + height + GAP);
    glutReshapeWindow(width, height);
    glutSetWindow(ventanaGL4);
    glutPositionWindow(GAP + width + GAP, GAP + height + GAP);
    glutReshapeWindow(width, height);
}

int main(int argc, char **argv){
    // inizializa la libreria de GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(210, 210);
    
    // crea unna ventana con 4 subventanas
    ventanaGLMain = glutCreateWindow("4 subwindows");
    // Determina que se debe volver a mostrar el plano normal de la ventana
    glutDisplayFunc(pantalla);
    // invoca mediante un puntero la funcion 'reshape', definida anteriormente
    glutReshapeFunc(reshape);
    // parametros para asignar color: valores float de: R,G,B,Alpha
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // los parámetros de glutSubWindow: glContenedor,posX, posY, Ancho y Alto
    ventanaGL1 = glutCreateSubWindow(ventanaGLMain, 10, 10, 90, 90);
    glutDisplayFunc(pantalla);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    ventanaGL2 = glutCreateSubWindow(ventanaGLMain, 110, 10, 90, 90);
    glutDisplayFunc(pantalla);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    ventanaGL3 = glutCreateSubWindow(ventanaGLMain, 10, 110, 90, 90);
    glutDisplayFunc(pantalla);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    ventanaGL4 = glutCreateSubWindow(ventanaGLMain, 110, 110, 90, 90);
    glutDisplayFunc(pantalla);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Procesa los eventos de la ventana GLUT
    glutMainLoop();
    
    return 0;
}
