//
//  Sphere.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/1/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(){
}

Sphere::Sphere(Vector4 c, float r):radius(r), center(c){
  toWorld.identity();
}

void Sphere::draw(Matrix4 m){
  
}