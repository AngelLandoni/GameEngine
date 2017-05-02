//
//  flycamera.cpp
//  GameEngine
//
//  Created by Angel Land on 17/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "flycamera.hpp"

NAMESPACE_BEGIN( GameEngine );

FlyCamera::FlyCamera():
_mHorizontalAngle(0),
_mVerticalAngle(0),
_mSpeed(0.3f)
{
  testing=0;
  
  
  glfwSetInputMode(_mInput.getWindowContext(  ), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  setPosition(glm::vec3(0,0,0));
  setViewPoint(glm::vec3(0,0,10));
  
  setPerspective(glm::perspective(glm::radians(60.0f), 1600.0f/1024.0f, 0.1f, 1000.0f));
  
  init(  );

  Camera(  );
}

FlyCamera::FlyCamera( float _width,float _height ):
_mHorizontalAngle(0),
_mVerticalAngle(0),
_mSpeed(0.3f)
{
  
 
  setPosition(glm::vec3(0,0,0));
  setViewPoint(glm::vec3(0,0,10));
  
  setPerspective(glm::perspective(glm::radians(60.0f), _width/_height, 0.1f, 1000.0f));
  
  init(  );
  
  Camera( _width,_height );
}

FlyCamera::~FlyCamera(  ){}


void FlyCamera::update(  ){
  double mouseX = _mInput.getMouseX(  );
  double mouseY = _mInput.getMouseY(  );
 
  if( _mInput.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1) ){
    _mHorizontalAngle += 0.1 * float( _mWidth/2 - mouseX ) / 100;
    _mVerticalAngle += 0.1 *float( _mHeight/2 - mouseY ) / 100;
    
    _mInput.setCursorPosition(_mWidth/2, _mHeight/2);
    
    glfwSetInputMode(_mInput.getWindowContext(  ), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }else{
    glfwSetInputMode(_mInput.getWindowContext(  ), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  }
  
  glm::vec3 direction(
                      
                      cos(_mVerticalAngle) * sin(_mHorizontalAngle),
                      
                      sin(_mVerticalAngle),
                      
                      cos(_mVerticalAngle) * cos(_mHorizontalAngle)
                      
                      );
  
  glm::vec3 right = glm::vec3(
                              sin(_mHorizontalAngle - 3.14f/2.0f),
                              0,
                              cos(_mHorizontalAngle - 3.14f/2.0f)
                              );
  

  if ( _mInput.isKeyPressed( GLFW_KEY_W ) ){
    _mPosition += direction * _mSpeed;
  }
  
  if ( _mInput.isKeyPressed( GLFW_KEY_S ) ){
    _mPosition -= direction *  _mSpeed;
  }
  
  if ( _mInput.isKeyPressed( GLFW_KEY_D ) ){
    _mPosition += right *  _mSpeed;
  }
  
  if ( _mInput.isKeyPressed( GLFW_KEY_A ) ){
    _mPosition -= right *  _mSpeed;
  }
  
  setViewPoint(direction+_mPosition);
  
  Camera::update(  );
}


NAMESPACE_END( GameEngine );