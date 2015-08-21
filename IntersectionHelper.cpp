//
//  IntersectionHelper.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Jeffrey Chen on 6/2/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "IntersectionHelper.h"
#include "Vector3.h"
#include <cmath>

float InterSectionHelper:: plane_distance(Vector4 plane, Vector4 point, Vector4 origin) {
  return (point - plane).toVector3().dot((plane - origin).toVector3().normalize());
}

bool InterSectionHelper:: sphere_inside_plane(Sphere s, Vector4 p, Vector4 origin) {
  return -plane_distance(p, s.toWorld * s.center, origin) > s.radius;
}

bool InterSectionHelper:: sphere_outside_plane(Sphere s, Vector4 p, Vector4 origin) {
  return plane_distance(p, s.toWorld * s.center, origin) > s.radius;
}

bool InterSectionHelper:: sphere_intersects_plane(Sphere s, Vector4 p, Vector4 origin) {
  return fabs(plane_distance(p, s.toWorld * s.center, origin)) <= s.radius;
}

int InterSectionHelper:: sphere_inside_box(Sphere s, Box b) {
  
  if (!sphere_inside_plane(s, b.toWorld * b.front, b.toWorld * b.origin))  { return 0; }
  if (!sphere_inside_plane(s, b.toWorld * b.back, b.toWorld * b.origin))   { return 0; }
  if (!sphere_inside_plane(s, b.toWorld * b.top, b.toWorld * b.origin))    { return 0; }
  if (!sphere_inside_plane(s, b.toWorld * b.bottom, b.toWorld * b.origin)) { return 0; }
  if (!sphere_inside_plane(s, b.toWorld * b.left, b.toWorld * b.origin))   { return 0; }
  if (!sphere_inside_plane(s, b.toWorld * b.right, b.toWorld * b.origin))  { return 0; }
  
  return 1;
}

int InterSectionHelper:: sphere_intersects_box(Sphere s, Box b){
  bool in_left   = !sphere_outside_plane(s, b.toWorld * b.left, b.toWorld * b.origin);
  bool in_right  = !sphere_outside_plane(s, b.toWorld * b.right, b.toWorld * b.origin);
  bool in_front  = !sphere_outside_plane(s, b.toWorld * b.front, b.toWorld * b.origin);
  bool in_back   = !sphere_outside_plane(s, b.toWorld * b.back, b.toWorld * b.origin);
  bool in_top    = !sphere_outside_plane(s, b.toWorld * b.top, b.toWorld * b.origin);
  bool in_bottom = !sphere_outside_plane(s, b.toWorld * b.bottom, b.toWorld * b.origin);
  
  if (sphere_intersects_plane(s, b.toWorld * b.top, b.toWorld * b.origin) &&
      in_left && in_right && in_front && in_back) {
    return 1;
  }
  
  if (sphere_intersects_plane(s, b.toWorld * b.bottom, b.toWorld * b.origin) &&
      in_left && in_right && in_front && in_back) {
    return 1;
  }
  
  if (sphere_intersects_plane(s, b.toWorld * b.left, b.toWorld * b.origin) &&
      in_top && in_bottom && in_front && in_back) {
    return 1;
  }
  
  if (sphere_intersects_plane(s, b.toWorld * b.right, b.toWorld * b.origin) &&
      in_top && in_bottom && in_front && in_back) {
    return 1;
  }
  
  if (sphere_intersects_plane(s, b.toWorld * b.front, b.toWorld * b.origin) &&
      in_top && in_bottom && in_left && in_right) {
    return 1;
  }
  
  if (sphere_intersects_plane(s, b.toWorld * b.back, b.toWorld * b.origin) &&
      in_top && in_bottom && in_left && in_right) {
    return 1;
  }
  
  return 0;
}