//
//  MatrixTransformation.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "MatrixTransformation.h"
#include <iostream>
void MatrixTransformation::draw(Matrix4 m){
  for(auto it = nodes.begin(); it != nodes.end(); it++){
    (*it)->draw(m*matrix);
  }
}

MatrixTransformation::MatrixTransformation(Matrix4 m):matrix(m){
  
}

MatrixTransformation::MatrixTransformation(){
  
}