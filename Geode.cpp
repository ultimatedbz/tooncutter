//
//  Geode.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "Geode.h"
#include <iostream>

using namespace std;

Geode::Geode(GLMmodel* g):model(g){
  //glmUnitize(model);
  glmVertexNormals(model, 90.0, GL_TRUE);
}

void Geode::draw(Matrix4 m){
  glPushMatrix();
  glMultMatrixf(m.ptr());
  glmDraw(model, GLM_SMOOTH| GLM_2_SIDED|
          GLM_MATERIAL| GLM_TEXTURE);
  glPopMatrix();
}