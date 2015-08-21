//
//  toonlink.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/30/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "toonlink.h"
#include "Geode.h"
#include "Window.h"
#include "IntersectionHelper.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <iostream>
#include <cmath>

using namespace std;
ToonLink:: ToonLink():MatrixTransformation(){
 }

void ToonLink::initialize(){
  
  Box box(5,5,5);
  Sphere sphere(Vector4(0,0,0,1), 2.4);
  cout << InterSectionHelper::sphere_inside_box(sphere, box)<<endl;
   cout << InterSectionHelper::sphere_intersects_box(sphere, box)<<endl;
  
  
  angle = 0;
  direction = 1;
  GLMmodel* temp;
  bound = 0;
  
  Matrix4 m, m1, m2, s;
  m.identity();
  matrix = m;
  
  Matrix4 origin;
  origin.makeTranslate(0, -9, 0);

  /*TODO */
  bomb = Sphere(Vector4(0, 0, 0, 1), 1);
  bomb.toWorld.makeTranslate(0, 0, 5);
  luffyBody = new Box(13.6, 0.5, 1);
  sword = new Box(15.2, 1, 0.5);
  luffyArm = new Box(0.5, 1, 8.5);
  
  boxes.push_back(luffyBody);
  boxes.push_back(luffyArm);
  boxes.push_back(sword);
  
  armAngle = 0;
  
  
  bombM = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/Wii - Super Smash Bros Brawl - Toon Link Effects/Toon Link Effects 2/ItmToonLinkBomb.obj");
  
  /* Add the main body transformation */
  MatrixTransformation* body = new MatrixTransformation(origin);
  addChild(body);
  
    /* Add the model to the transformation */
    temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/noArms.obj");
    Geode* g_body = new Geode(temp);
    body->addChild(g_body);
  
  
  /* Add left arm transformation */
  m1.makeTranslate(-1.3, 0, 0);
  MatrixTransformation* leftArmSetUpL = new MatrixTransformation(m1);
  addChild(leftArmSetUpL);
  
    m.identity();
    m.makeRotateZ(-0.5);
    leftArm = new MatrixTransformation(m);
    leftArmSetUpL -> addChild(leftArm);
    
      m1.makeTranslate(1.5, 0, 0);
      MatrixTransformation* leftArmSetUpR = new MatrixTransformation(m1 * origin);
      leftArm -> addChild(leftArmSetUpR);
    
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/leftArm.obj");
      
      Geode* g_leftArm = new Geode(temp);
      leftArmSetUpR->addChild(g_leftArm);
  
  
      /* Left Hand */
      m1.makeTranslate(1.5, 0, 0);
      MatrixTransformation* leftHandSetUpR = new MatrixTransformation(m1 * origin);
      leftArm -> addChild(leftHandSetUpR);
      
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/leftHand.obj");
      
      Geode* g_leftHand = new Geode(temp);
      leftHandSetUpR->addChild(g_leftHand);
  
  
  
      /* Luffy */
      m.makeRotateZ(1.57);
      m1.makeTranslate(-10, -0.5, 0);
      s.makeScale(0.05);
  
      luffy = new MatrixTransformation( m1 * m * s);
      leftArm ->addChild(luffy);
      
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/TimeSkip Luffy/luffy.obj");
      
      Geode* g_luffy = new Geode(temp);
      luffy -> addChild(g_luffy);
  
  
  
  
  
  /* Add right arm transformation */
  m1.makeTranslate(1.3, 0, 0);
  MatrixTransformation* rightArmSetUpR = new MatrixTransformation(m1);
  addChild(rightArmSetUpR);
  
    m.identity();
    m.makeRotateZ(0.5);
    rightArm = new MatrixTransformation(m);
    rightArmSetUpR -> addChild(rightArm);
  
      m1.makeTranslate(-1.5, 0, 0);
      MatrixTransformation* rightArmSetupL = new MatrixTransformation(m1 * origin);
      rightArm ->addChild(rightArmSetupL);
      
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/rightArm.obj");
      
      Geode* g_rightArm = new Geode(temp);
      rightArmSetupL -> addChild(g_rightArm);
  
  
      /* Right Hand */
      m1.makeTranslate(-1.5, 0, 0);
      MatrixTransformation* rightHandSetUpR = new MatrixTransformation(m1 * origin);
      rightArm -> addChild(rightHandSetUpR);
      
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/rightHand.obj");
      
      Geode* g_rightHand = new Geode(temp);
      rightHandSetUpR->addChild(g_rightHand);
  
      /* Sword */
      m.makeRotateY(1.57);
      m1.makeTranslate(-6.6, 0, 0);
      m2.makeTranslate(6.6,0, 0);
  
      MatrixTransformation* swordL = new MatrixTransformation(m2 * m * m1 * origin);
      rightArm ->addChild(swordL);
      
      /* Add the model to the transformation */
      temp = glmReadOBJ("/Users/jeffreychen/Desktop/Misc/school/past classes/cse_167/FINAL/untitled folder/sword.obj");
      
      Geode* g_sword = new Geode(temp);
      swordL -> addChild(g_sword);


  
}

void ToonLink::draw(Matrix4 m){
  
  
  Matrix4 m2, tempR, tempL;
  tempL = leftArm->matrix;
  tempR = rightArm->matrix;
  float tempA = angle;
  int tempD = direction;
    if(arm){
      if( angle + (0.1) * direction <= 3.14 && angle + (0.1) * direction > 0){
        angle += 0.05 * direction;
        m2.makeRotateY(-0.05 * direction);
        rightArm->matrix = rightArm -> matrix * m2;
      }else{
        if(direction == -1)
          arm = !arm;
        direction *= -1;
      }
    }else{
      if( angle + 0.1 * direction <= 3.14 && angle + 0.1 * direction > 0 ){
        angle += 0.05 * direction;
        m2.makeRotateY(0.05 * direction);
        leftArm->matrix = leftArm -> matrix * m2;
      }else{
        if(direction == -1)
          arm = !arm;
        direction *= -1;
      }
    }
    
  armAngle += 0.05;
  update();
  //undo
  if(intersecting()){
    armAngle -= 0.05;
    rightArm->matrix = tempR;
    leftArm->matrix = tempL;
    angle = tempA;
    direction = tempD;
  }else{
  
    m2.makeRotateX(0.05);
    luffy -> matrix = m2 * luffy -> matrix;
    if( armAngle > 6.2831)
      armAngle -= 6.2831;
  }
  
  // Draw sphere and boxes here
  glMatrixMode(GL_MODELVIEW);
  
  glPushMatrix();
  
  if(!bound){
    Matrix4 scale;
    scale.makeScale(0.36);
    glMultMatrixf((matrix * (bomb.toWorld) * scale).ptr());
    
    glmDraw(bombM,GLM_SMOOTH| GLM_2_SIDED|
            GLM_MATERIAL| GLM_TEXTURE);
  }else{
    glMultMatrixf((matrix * (bomb.toWorld)).ptr());
    glutSolidSphere(bomb.radius, 50, 50);
  }
  glPopMatrix();
  
  if(bound){
    for(auto it = boxes.begin(); it != boxes.end(); it++){
      glPushMatrix();
      Matrix4 s;
      s.makeScale(2 * (*it) ->right[0], 2 * (*it) ->top[1],2 * (*it) ->front[2]);
      glMultMatrixf(((*it)->toWorld * s) .ptr());
      glutSolidCube(1);
      glPopMatrix();
    }
  }
  
  // Draw children
  for(auto it = nodes.begin(); it != nodes.end(); it++){
    (*it)->draw(m*matrix);
  }
  
  glPushMatrix();
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glMultMatrixf(matrix.ptr());
  glBegin(GL_LINES);
  
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(.8f, 0.05f, 0.0);
  glVertex3f(1.0, 0.25f, 0.0);	/*  Letter X */
  glVertex3f(0.8f, .25f, 0.0);
  glVertex3f(1.0, 0.05f, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(1.0, 0.0, 0.0);	/*  X axis */
  
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 1.0, 0.0);	/*  Y axis */
  
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 1.0);	/*  Z axis */
  glEnd();
  glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
  
}


int ToonLink:: intersecting(){
  Sphere temp = bomb;
  temp.toWorld = matrix * temp.toWorld; //apply toonlink's transformation. This needs to be applied last!
  for(auto it = boxes.begin(); it != boxes.end(); it++){
    if( InterSectionHelper::sphere_intersects_box(temp, **it)||
      InterSectionHelper:: sphere_inside_box(temp, **it)){
      return 1;
    }
  }
  return 0;
}

void ToonLink:: update(){
  Matrix4 rotZ, rotY, transR, transL, identity, m, m2;
  
  //sword
  transR.makeTranslate(sword->width/2, 0, 0);
  m.makeTranslate(1.3, 0, 0);

  sword->toWorld = matrix * m * rightArm->matrix * transR;

  // luffy body
  transL.makeTranslate(-luffyBody->width/2,-0.5,-0.5);
  m2.makeRotateX(armAngle);
  m.makeTranslate(-1.3, 0, 0);
  luffyBody->toWorld = matrix * m * leftArm->matrix * m2 *transL;

  //luffy arm
  transL.makeTranslate(-luffyBody->width * 7/8, -0.5, -0.5);
  luffyArm->toWorld = matrix * m * leftArm->matrix * m2 *transL;
  
}











