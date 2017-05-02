//
//  window.cpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "window.hpp"

NAMESPACE_BEGIN( GameEngine );
//===============================================================================================
Window::Window() :
_mTitle(""),
_mWidth( 100 ),
_mHeight( 100 ),
_mClosed( true )
{  }
//===============================================================================================
Window::~Window(  ){
  glfwTerminate(  );
}
//===============================================================================================
bool Window::create( const std::string& _title, int _width, int _height) throw(){
  _mTitle = _title;
  _mWidth = _width;
  _mHeight = _height;
  
  if( !glfwInit(  ) ){
    std::cout<<"Error on init OpenGL!."<<std::endl;
    return false;
  }
  
  glfwWindowHint( GLFW_SAMPLES,16 );
  
#ifdef __APPLE__
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  
  _mWindowContext = glfwCreateWindow( _mWidth, _mHeight, _mTitle.c_str( ), nullptr, nullptr );
  if( !_mWindowContext ){
    glfwTerminate(  );
    std::cout<<"Error on create Window!."<<std::endl;
    return false;
  }
  
  
  // INPUT
  _mInput._mWindowHandler = _mWindowContext;
  
  glfwMakeContextCurrent( _mWindowContext );
  glfwSetWindowUserPointer(_mWindowContext, this);
  
  glfwSetKeyCallback( _mWindowContext, key_callback );
  glfwSetMouseButtonCallback(_mWindowContext, mouse_button_callback);
  
  glfwSetCursorPosCallback( _mWindowContext,cursor_position_callback );
  
  glewExperimental = GL_TRUE;
  if( glewInit(  ) != GLEW_OK ){
    glfwTerminate(  );
    std::cout<<"Error on init GLEW!."<<std::endl;
    return false;
  }
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_BLEND);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
 
  
  // get version info
  const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString (GL_VERSION); // version as a string
  printf ("Renderer: %s\n", renderer);
  printf ("OpenGL version supported %s\n", version);
  
  _mClosed = false;
  return true;
}
//===============================================================================================
void Window::clear(  ) const{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}
//===============================================================================================
bool Window::close(  ){
  _mClosed = true;
  return glfwWindowShouldClose( _mWindowContext );
}
//===============================================================================================
void Window::update(  ){
  glfwSwapBuffers( _mWindowContext );
  glfwGetFramebufferSize( _mWindowContext , &_mWidth, &_mHeight);
  
  glViewport(0, 0, _mWidth, _mHeight);
  
  glfwPollEvents(  );
}
//===============================================================================================
bool Window::closed(  ){
  return _mClosed;
}
//===============================================================================================
void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods ){
  Window* _w = reinterpret_cast<Window*>(window);
  if( action == GLFW_PRESS )
    _w->_mInput.setKeyDown(key);
  else if( action == GLFW_RELEASE )
    _w->_mInput.setKeyUp(key);
}
//===============================================================================================
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
  Window* _w = reinterpret_cast<Window*>(window);
  if( action == GLFW_PRESS )
    _w->_mInput.setMouseButtonDown((char)button);
  else if( action == GLFW_RELEASE )
    _w->_mInput.setMouseButtonUp((char)button);
}
//===============================================================================================
void cursor_position_callback( GLFWwindow* window, double xpos, double ypos ){
  Window* _w = reinterpret_cast<Window*>(window);
  _w->_mInput.setMousePosition( xpos, ypos );
}
//===============================================================================================


NAMESPACE_END( GameEngine );