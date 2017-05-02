//
//  inputmanager.cpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "inputmanager.hpp"

NAMESPACE_BEGIN( GameEngine );

std::atomic<bool> InputManager::_mKeys[MAX_KEYS];
std::atomic<double> InputManager::_mMousePosition[2];
std::atomic<bool> InputManager::_mMouseButtons[MAX_MOUSE_BUTTONS];
GLFWwindow* InputManager::_mWindowHandler;

//===============================================================================================
InputManager::InputManager(  ){
  uint i=0;
  for( i=0;i<MAX_KEYS;i++ )
    _mKeys[i] = false;
}
//===============================================================================================
InputManager::~InputManager(  ){  }
//===============================================================================================
bool InputManager::isKeyPressed( short _key ){
  return _mKeys[_key];
}
//===============================================================================================
bool InputManager::isMouseButtonPressed( char _button ){
  return _mMouseButtons[_button];
}
//===============================================================================================
double InputManager::getMouseX(  ){
  return _mMousePosition[0];
}
//===============================================================================================
double InputManager::getMouseY(  ){
  return _mMousePosition[1];
}
//===============================================================================================
void InputManager::setCursorPosition( double _x,double _y ){
  _mMousePosition[0] = _x;
  _mMousePosition[1] = _y;
  glfwSetCursorPos(_mWindowHandler, _x, _y);
}
//===============================================================================================
void InputManager::setKeyDown(short _key){
  _mKeys[_key] = true;
}
//===============================================================================================
void InputManager::setKeyUp(short _key){
  _mKeys[_key] = false;
}
//===============================================================================================
void InputManager::setMousePosition( double _x,double _y ){
  _mMousePosition[0] = _x;
  _mMousePosition[1] = _y;
}
//===============================================================================================
void InputManager::setMouseButtonDown( char _button ){
  _mMouseButtons[_button] = true;
}
//===============================================================================================
void InputManager::setMouseButtonUp( char _button ){
  _mMouseButtons[_button] = false;
}
//===============================================================================================
GLFWwindow* InputManager::getWindowContext(){
  return _mWindowHandler;
}
//===============================================================================================
NAMESPACE_END( GameEngine );