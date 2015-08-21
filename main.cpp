#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "Matrix4.h"
#include "Globals.h"
#include "MathTestBench.h"
//#include <OpenGL/gl3.h>

/* Lighting Variables */
GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat high_shininess[] = { 100.0 };

int main(int argc, char *argv[])
{
   /*
    glutInit(&argc, argv);                                      //Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
  //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH|GLUT_3_2_CORE_PROFILE);   //Open an OpenGL context with double buffering, RGB colors, and depth buffering
    glutInitWindowSize(Window::width, Window::height);          //Set initial window size
    glutCreateWindow("Toon Link"); //Open window and set window title

  
    glClear(GL_DEPTH_BUFFER_BIT);                               //Clear depth buffer
    glClearColor(0.0, 0.0, 0.0, 0.0);                           //Set clear color to black
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);                  //Set polygon drawing mode to fill front and back of each polygon

    
    //Register callback functions:
    glutDisplayFunc(Window::displayCallback);
    glutReshapeFunc(Window::reshapeCallback);

    glutIdleFunc(Window::idleCallback);
    //Register the callback for the keyboard
    glutKeyboardFunc(Window::processNormalKeys);
    //Register the callback for the keyboard function keys
    glutSpecialFunc(Window::processSpecialKeys);
  glutMouseFunc(Window::processMouse);
  //Register the callback for the mouse motion
  glutMotionFunc(Window::processMotion);
    //Register the callback for the mouse
    //Register the callback for the mouse motion

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glEnable(GL_TEXTURE_2D);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  
    
    //Initialize the Window:
    //The body of this function is a great place to load textures, shaders, etc.
    //and do any operations/calculations/configurations that only need to happen once.
    Window::initialize();
    
    //Start up the render loop!
    glutMainLoop();
    
    return 0;
  */
  
  //Math Test Bench
  //MathTestBench::runTests();
  glutInit(&argc, argv);                                      //Initialize GLUT
//  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH|GLUT_3_2_CORE_PROFILE );   //Open an OpenGL context with double buffering, RGB colors, and depth buffering
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize(Window::width, Window::height);          //Set initial window size
  glutCreateWindow("UCSD CSE 167 - Project 2 - Viewing 3D Scenes"); //Open window and set window title
  
  glEnable(GL_DEPTH_TEST);                                    //Enable depth buffering
  glClear(GL_DEPTH_BUFFER_BIT);                               //Clear depth buffer
  glClearColor(0.0, 0.0, 0.0, 0.0);                           //Set clear color to black
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);                  //Set polygon drawing mode to fill front and back of each polygon
  glDisable(GL_CULL_FACE);                                    //Disable backface culling to render both sides of polygons
  //Set shading to smooth
  
  glEnable(GL_COLOR_MATERIAL);                                //Enable color materials
  
  glEnable(GL_LIGHTING);                                      //Enable lighting
  
  //Register callback functions:
  glutDisplayFunc(Window::displayCallback);
  glutReshapeFunc(Window::reshapeCallback);
  glutIdleFunc(Window::idleCallback);
  //Register the callback for the keyboard
  glutKeyboardFunc(Window::processNormalKeys);
  //Register the callback for the keyboard function keys
  glutSpecialFunc(Window::processSpecialKeys);
  //Register the callback for the mouse
  //Register the callback for the mouse motion
  //Register the callback for the mouse
  glutMouseFunc(Window::processMouse);
  //Register the callback for the mouse motion
  glutMotionFunc(Window::processMotion);
  //Initialize the Window:
  //The body of this function is a great place to load textures, shaders, etc.
  //and do any operations/calculations/configurations that only need to happen once.
  
  Window::initialize();
  
  
  glShadeModel(GL_SMOOTH);
  glEnable(GL_TEXTURE_2D);   // enable texture mapping
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // black background
  glClearDepth(1.0f);        // depth buffer setup
  glDepthFunc(GL_LEQUAL);    // configure depth testing
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // really nice perspective calculations
  
  
  //Start up the render loop!
  glutMainLoop();
  
  return 0;
}



