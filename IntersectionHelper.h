//
//  IntersectionHelper.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/2/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__IntersectionHelper__
#define __CSE167_Spring_2015_Starter_Code__IntersectionHelper__

#include <stdio.h>
#include "Vector4.h"
#include "Sphere.h"
#include "Box.h"

class InterSectionHelper{
public:
  static float plane_distance(Vector4, Vector4, Vector4);
  static bool sphere_inside_plane(Sphere, Vector4, Vector4);
  static bool sphere_outside_plane(Sphere , Vector4, Vector4);
  static bool sphere_intersects_plane(Sphere s, Vector4, Vector4);
  static int sphere_inside_box(Sphere s, Box b);
  static int sphere_intersects_box(Sphere s, Box b);
 // static int sphere_outside_box(Sphere s, Box b);
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__IntersectionHelper__) */
