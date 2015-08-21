//
//  Box.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/1/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "Box.h"
Box::Box(){
  
}

Box::Box(float w, float l, float h):width(w), height(h), length(l){
  front = Vector4(0,0, l/2.0, 1);
  back = Vector4(0, 0, -l/2.0, 1);
  left = Vector4(-w/2.0, 0, 0, 1);
  right = Vector4(w/2.0, 0, 0, 1);
  top = Vector4(0, h/2.0, 0, 1);
  bottom = Vector4(0, -h/2.0, 0, 1);
  origin = Vector4(0,0,0,1);
  
  toWorld.identity();
}

void Box::draw(){
  
}