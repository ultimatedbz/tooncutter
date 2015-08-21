#include "Light.h"
#include "Window.h"
#include <iostream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif


Light::Light()
{

}

Light::~Light()
{
    //Delete any dynamically allocated memory/objects here
}

void Light::bind(int id)
{
  /* Lighting Variables */
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
  
  GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
  GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat high_shininess[] = { 100.0 };
  
    if(id < 0 || id > 7) {
        std::cout << "ERROR: The light bind ID " << id << " is not valid!" << std::endl;
        return;
    }
    
    //Set the bindID
    bindID = id;
    

    
  
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
  
  //Configure the light at the bindID
  glEnable(GL_LIGHT0 + bindID);
  

}

void Light::setColor(Vector3 v){
  ambientColor = Color(v[0], v[1], v[2]);
  diffuseColor = Color(v[0], v[1], v[2]);
  specularColor = Color(v[0], v[1], v[2]);
}

void Light::unbind(void)
{
    glDisable(GL_LIGHT0 + bindID);
    bindID = -1;
}
