//
//  Plane.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/2/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Plane__
#define __CSE167_Spring_2015_Starter_Code__Plane__

#include <stdio.h>
#include "Vector4.h"
class Plane{
  Plane(Vector4, Vector4);
  Vector4 direction;
  Vector4 position;
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__Plane__) */
