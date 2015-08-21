//
//  Box.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/1/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Box__
#define __CSE167_Spring_2015_Starter_Code__Box__

#include <stdio.h>
#include "Matrix4.h"
#include "Vector4.h"
class Box{
public:
  Box();
  Box(float, float, float);
  float height;
  float width;
  float length;
  Vector4 front, back, left, right, top, bottom;
  Matrix4 toWorld;
  Vector4 origin;
  void draw();
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__Box__) */
