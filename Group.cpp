//
//  Group.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 5/7/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "Group.h"

Group::Group(){
  
}

void Group::removeChild(Node* node){
  nodes.remove(node);
}

void Group::addChild(Node * node){
  nodes.push_back(node);
}

void Group:: draw(Matrix4 m){
  for(auto it = nodes.begin(); it != nodes.end(); it++){
    (*it)->draw(m);
  }
}




