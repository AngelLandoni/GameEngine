//
//  transform.cpp
//  GameEngine
//
//  Created by Angel Land on 15/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "transform.hpp"

NAMESPACE_BEGIN( GameEngine );

Transform::Transform(  ):
_mTranslate({0,0,0}),
_mRotate({0,1,1,1}),
_mScale({1,1,1})
{}

Transform::Transform( glm::vec3 _t,glm::vec4 _r,glm::vec3 _s ):
_mTranslate(_t),
_mRotate(_r),
_mScale(_s)
{}

Transform::~Transform(  ){  }


void Transform::reset(  ){
  _mTranslate = {0,0,0};
  _mRotate = {0,0,0,0};
  _mScale = {0,0,0};
}

glm::mat4 Transform::getTransformation(  ){
  return glm::translate( _mTranslate ) *
         glm::rotate( _mRotate.x , glm::vec3( _mRotate.y,_mRotate.z,_mRotate.w ) )*
        glm::scale(_mScale);
}

NAMESPACE_END( GameEngine );