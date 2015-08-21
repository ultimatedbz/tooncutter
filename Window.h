#ifndef CSE167_Window_h
#define CSE167_Window_h
#include "vector3.h"
#include "Shader.h"

class Window	  // OpenGL output window related routines
{
    
public:
    
    static int width, height; 	            // window size
    
    static void initialize(void);
    static void idleCallback(void);
    static void reshapeCallback(int, int);
    static void displayCallback(void);
    static void processNormalKeys(unsigned char key, int x, int y);
    static void processSpecialKeys(int key, int x, int y);
  static void processMouse(int button, int state, int x, int y);
  static void processMotion(int x, int y);
  static Shader* shader;
  static int bind;
  
private:
  static Vector3 lastPoint;
  static int buttonPressed;
  static Vector3 trackBallMapping(int x, int y);
  static int controlMode; // 0 = toonLink, 1 = bomb
};
#endif

