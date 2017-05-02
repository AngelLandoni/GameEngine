//
//  inputmanager.hpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_INPUTMANAGER_HPP__
#define __GAMEENGINE_INPUTMANAGER_HPP__

#include <iostream>
#include <atomic>

#include "../../extern/glew/glew.h"
#include "../../extern/glfw3/glfw3.h"

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 3

class InputManager{
  static std::atomic<bool> _mKeys[MAX_KEYS];
  static std::atomic<double> _mMousePosition[2]; // 0 = x, 1 = y
  static std::atomic<bool> _mMouseButtons[MAX_MOUSE_BUTTONS];

  static GLFWwindow* _mWindowHandler;
  
  friend class Window;
public:
  InputManager(  );
  virtual ~InputManager(  );
  
  
  static bool isKeyPressed( short _key );
  static bool isMouseButtonPressed( char _button );
  static double getMouseX(  );
  static double getMouseY(  );
  static void setCursorPosition( double _x,double _y );
  
  static GLFWwindow* getWindowContext();
  
private:
  static void setKeyDown( short _key );
  static void setKeyUp( short _key );
  static void setMousePosition( double _x,double _y );
  static void setMouseButtonDown( char _button );
  static void setMouseButtonUp( char _button );
  
  friend void key_callback(GLFWwindow* window,
                           int key,
                           int scancode,
                           int action,
                           int mods);
  friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
  friend void cursor_position_callback(GLFWwindow* window,
                                       double xpos,
                                       double ypos);
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_INPUTMANAGER_HPP__ */
