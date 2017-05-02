//
//  window.hpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_WINDOW_HPP__
#define __GAMEENGINE_WINDOW_HPP__

#include <iostream>
#include <atomic>

#include "../../extern/glew/glew.h"
#include "../../extern/glfw3/glfw3.h"

#include "../utils/helpers.hpp"
#include "../maths/color.hpp"
#include "../events/inputmanager.hpp"
#include "../object.hpp"

NAMESPACE_BEGIN( GameEngine );

class Window : public Object{
  std::string _mTitle;
  int _mWidth,_mHeight;
  GLFWwindow* _mWindowContext;
  std::atomic<bool> _mClosed;

  InputManager _mInput;
  
  Color _mBackgroundColor;
public:
  Window(  );
  virtual ~Window(  );
  bool create(const std::string& _title,
              int _width,
              int _height ) throw();
  void clear(  ) const;
  void update(  );
  bool close(  );
  bool closed(  );
  
  inline int getWidth(  ) const{ return _mWidth; }
  inline int getHeight(  ) const{ return _mHeight; }
  
  friend void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);
  friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
  friend void cursor_position_callback(GLFWwindow* window,double xpos,double ypos);
 };

void key_callback( GLFWwindow* window,int key,int scancode,int action,int mods );
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window,double xpos,double ypos);

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_WINDOW_HPP__ */
