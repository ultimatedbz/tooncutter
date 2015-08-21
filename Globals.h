#ifndef CSE167_Globals_h
#define CSE167_Globals_h

#include "Camera.h"
#include "Light.h"
#include "DrawData.h"
#include "UpdateData.h"
#include "toonlink.h"

struct _GLMmodel;
typedef _GLMmodel GLMmodel;



class Globals
{
    
public:
    
    static Camera camera;
  static Light light;
    static DrawData drawData;
    static UpdateData updateData;
  static ToonLink toonLink;
    //Feel free to add more member variables as needed
    
    
};



#endif
