//
//  Group.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Group__
#define __CSE167_Spring_2015_Starter_Code__Group__

#include <stdio.h>
#include <list>
#include "Node.h"
#include "Matrix4.h"

class Group:public Node{
public:
  Group();
  std::list<Node*> nodes;
  virtual void removeChild(Node*);
  virtual void addChild(Node*);
  virtual void draw(Matrix4);
};


#endif /* defined(__CSE167_Spring_2015_Starter_Code__Group__) */
