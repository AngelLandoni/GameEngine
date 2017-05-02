//
//  flycamera.hpp
//  GameEngine
//
//  Created by Angel Land on 17/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_FLYCAMERA_HPP__
#define __GAMEENGINE_FLYCAMERA_HPP__

#include <cmath>

#include "../../utils/helpers.hpp"

#include "../../events/inputmanager.hpp"

#include "camera.hpp"

NAMESPACE_BEGIN( GameEngine );


class FlyCamera : public Camera{
protected:
  InputManager _mInput;
  float _mHorizontalAngle;
  float _mVerticalAngle;
  
  float _mSpeed;
  
  uint testing;
public:
  FlyCamera(  );
  FlyCamera( float _width,float _height );
  virtual ~FlyCamera(  );
  
  virtual void update(  );
  
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_FLYCAMERA_HPP__ */
