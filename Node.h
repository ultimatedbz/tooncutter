//
//  Node.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Node__
#define __CSE167_Spring_2015_Starter_Code__Node__

#include <stdio.h>
#include "Matrix4.h"

class Node{
public:
  virtual void draw(Matrix4 C) = 0;
  //virtual void update() = 0;
};
#endif /* defined(__CSE167_Spring_2015_Starter_Code__Node__) */
