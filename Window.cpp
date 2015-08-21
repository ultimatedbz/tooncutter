#include <iostream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "Matrix4.h"
#include "Globals.h"
#include <cmath>
#include <iostream>

int Window::width  = 512;   //Set window width in pixels here
int Window::height = 512;   //Set window height in pixels here
int Window:: controlMode = 0;
int Window:: bind = 0;

Vector3 Window::lastPoint;
int Window::buttonPressed;
ToonLink Globals::toonLink;

using namespace std;
Shader* Window::shader;

extern "C" {
  #include "glm.h"
}


//GLMmodel* Globals::toonLink;

void Window::initialize(void)
{
  Globals::toonLink.initialize();
  shader = new Shader("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/sample.vert","/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/sample.frag",true);
  if(bind)
    shader->bind();

}

//----------------------------------------------------------------------------
// Callback method called when system is idle.
// This is called at the start of every new "frame" (qualitatively)
void Window::idleCallback()
{
        
        //Call the display routine to draw the cube
        displayCallback();
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
  
  glViewport(0, 0, w, h);
    width = w;                                                       //Set the window width
    height = h;                                                      //Set the window height
    glViewport(0, 0, w, h);                                          //Set new viewport size
    glMatrixMode(GL_PROJECTION);                                     //Set the OpenGL matrix mode to Projectionview
    glLoadIdentity();                                                //Clear the projection matrix by loading the identity
    gluPerspective(60.0, double(width)/(double)height, 1.0, 1000.0); //Set perspective projection viewing frustum
   glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    
        //Clear color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();

        glLoadMatrixf(Globals::camera.getInverseMatrix().ptr());
  

  
        //glLoadIdentity();
  
      //  glTranslatef(0, 0, -3);
  
        Matrix4 m;
        m.identity();
        glMultMatrixf(m.ptr());
  
        glPushMatrix();

  
        Globals::toonLink.draw(m);
        glPopMatrix();
  
       // glTranslatef(0, 0, 3);
  
        //Pop off the changes we made to the matrix stack this frame
        glPopMatrix();
        

        //glFlush();
        
        //Swap the off-screen buffer (the one we just drew to) with the on-screen buffer
        glutSwapBuffers();


}

void Window::processNormalKeys(unsigned char key, int x, int y) {

  Matrix4 m;
  switch (key) {
      case 'x':
      m.makeTranslate(-1, 0, 0); //moves link to roughly the origin
      if(controlMode){
        Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
      }else{
        Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
      }
          break;
      case 'X':
      m.makeTranslate(1, 0, 0); //moves link to roughly the origin
      if(controlMode){
        Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
      }else{
      Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
      }
          break;
      case 'y':
      m.makeTranslate(0, -1, 0); //moves link to roughly the origin
      if(controlMode){
        Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
      }else{
      Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
      }
          break;
      case 'Y':
      m.makeTranslate(0, 1, 0); //moves link to roughly the origin
      if(controlMode){
        Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
      }else{
      Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
      }
          break;
      case 'z':
      m.makeTranslate(0, 0, -0.5); //moves link to roughly the origin
      if(controlMode){
        Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
      }else{
      Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
      }
          break;
      case 'Z':
      m.makeTranslate(0, 0, .5); //moves link to roughly the origin
        if(controlMode){
          Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
        }else{
      Globals::toonLink.matrix =  m * Globals::toonLink.matrix;
        }
          break;
      case 'r':
          Globals::toonLink.matrix = m.makeTranslate(0, 0, 0); //moves link to roughly the origin
            Globals::toonLink.bomb.toWorld = m * Globals::toonLink.bomb.toWorld;
          Globals::toonLink.bomb.toWorld.makeTranslate(0, 0, 5);
      
          break;
      case 'b':
        controlMode = !controlMode;
        cout<<"Switching control mode!"<<endl;
        break;
      case 'm':
      Globals::toonLink.bound = !Globals::toonLink.bound;
      break;
      case 't':
      if(bind){
        Window::shader->unbind();
        bind = !bind;
      }else{
        Window::shader->bind();
       bind = !bind;
      }
      break;
  }
  

}

/* Function Key */
void Window::processSpecialKeys(int key, int x, int y) {

}

void Window:: processMouse(int button, int state, int x, int y){
  // save last point
  
  lastPoint = trackBallMapping(x,y);
  if(!state)
    buttonPressed = button;
  else
    buttonPressed = 0;
}



void Window:: processMotion(int x, int y){
  Vector3 currentPoint = trackBallMapping(x, y);
  float velocity = lastPoint.angle(currentPoint);
  Vector3 difference = currentPoint - lastPoint;
  
  if(velocity > 0.001){
    if(buttonPressed == 0){
      Vector3 rotAxis = lastPoint.cross(currentPoint).normalize();
      Matrix4 rotate;
      rotate.makeRotateArbitrary(rotAxis, velocity);
      if(controlMode){
        Globals::toonLink.bomb.toWorld = rotate * Globals::toonLink.bomb.toWorld;
      }else{
        
        Globals::toonLink.matrix = rotate * Globals::toonLink.matrix;
      }
    }else{
      Matrix4 translate;
      translate.makeTranslate(difference[0] * 16.5, difference[1] * 15.5, 0);
      if(controlMode){
        Globals::toonLink.bomb.toWorld = translate * Globals::toonLink.bomb.toWorld;
      }else{
        Globals::toonLink.matrix = translate * Globals::toonLink.matrix;
      }
    }
  }
  
  lastPoint = currentPoint;
}



Vector3 Window::trackBallMapping(int x, int y)
{
  float d;
  Vector3 v((2.0 * x - width) / width, (height - 2.0 * y) / height, 0.0);
  d = v.magnitude();
  d = (d < 1.0) ? d : 1.0;
  v[2] = sqrtf(1.001 - d * d);
  return v.normalize();
}
