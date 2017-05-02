//
//  camera.cpp
//  GameEngine
//
//  Created by Angel Land on 17/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "camera.hpp"

NAMESPACE_BEGIN( GameEngine );

Camera::Camera( ) :
_mPosition(glm::vec3(0,0,0)),
_mViewPoint(glm::vec3(0,0,0)),
_mWidth(800),
_mHeight(600){
  
  _mPerspective = glm::perspective(glm::radians(60.0f), 800.0f/600.0f, 0.1f, 1000.0f);
  _mOrtho = glm::ortho<float>( 0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f );
}

Camera::Camera( float _width,float _height ):
_mWidth(_width),
_mHeight(_height)
{
  _mPerspective = glm::perspective(glm::radians(60.0f), _width/_height, 0.1f, 1000.0f);
  _mOrtho = glm::ortho<float>( 0.0f, _width, _height, 0.0f, -1.0f, 1.0f );
}

Camera::~Camera(){

}

void Camera::init(  ){
  uint i=0;
  const uint lengthShaders = ShaderManagerInstance.getLength(  );
  while(i<lengthShaders){
    ShaderManagerInstance[i]->setUniform(GLSL_CAMERA_PROJECTION,_mPerspective);
    ShaderManagerInstance[i]->setUniform(GLSL_CAMERA_VIEW,glm::lookAt(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0)) );
    i++;
  }
}

void Camera::update(  ){
  uint i=0;
  const uint lengthShaders = ShaderManagerInstance.getLength(  );

  while(i<lengthShaders){
    ShaderManagerInstance[i]->setUniform(
                                GLSL_CAMERA_VIEW,
                                glm::lookAt(_mPosition, _mViewPoint, glm::vec3(0,1,0))
                                );
    i++;
  }
}

glm::mat4 Camera::getView(  )const{
  return  glm::lookAt( _mPosition,_mViewPoint,glm::vec3(0,1,0) );
}


NAMESPACE_END( GameEngine );