//
//  toonlink.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/30/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__toonlink__
#define __CSE167_Spring_2015_Starter_Code__toonlink__

#include <stdio.h>
#include "MatrixTransformation.h"
#include <vector>
#include "Box.h"
#include "Sphere.h"
#include "glm.h"

class ToonLink: public MatrixTransformation{
public:
  ToonLink();
  void initialize();
  void draw(Matrix4);
  int intersecting();
  MatrixTransformation* rightArm;
  MatrixTransformation* leftArm;
  MatrixTransformation* luffy;
  float angle;
  float direction;
  int arm; // 0 = left, 1 = right
  std::vector<Box*> boxes;
  Sphere bomb;
  Box* sword, *luffyArm, *luffyBody;
  void update();
  float armAngle;
  GLMmodel* bombM;
  int bound;
};


#endif /* defined(__CSE167_Spring_2015_Starter_Code__toonlink__) */
