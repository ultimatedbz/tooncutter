//
//  Sphere.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/1/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Sphere__
#define __CSE167_Spring_2015_Starter_Code__Sphere__

#include <stdio.h>
#include "Matrix4.h"
#include "Vector4.h"

class Sphere{
public:
  Sphere(Vector4,float);
  Sphere();
  float radius;
  Vector4 center;
  void draw(Matrix4 m);
  Matrix4 toWorld;
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__Sphere__) */
