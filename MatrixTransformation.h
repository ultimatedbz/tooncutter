//
//  MatrixTransformation.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__MatrixTransformation__
#define __CSE167_Spring_2015_Starter_Code__MatrixTransformation__

#include <stdio.h>
#include "Matrix4.h"
#include "Group.h"

class MatrixTransformation: public Group{
public:
  Matrix4 matrix;
  void draw(Matrix4);
  MatrixTransformation();
  MatrixTransformation(Matrix4);
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__MatrixTransformation__) */
