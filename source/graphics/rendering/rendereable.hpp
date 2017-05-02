//
//  rendereable.hpp
//  GameEngine
//
//  Created by Angel Land on 11/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_GAMEOBJECT_HPP__
#define __GAMEENGINE_GAMEOBJECT_HPP__

#include <string>

#include "../../utils/helpers.hpp"

#include "../shaders/shader.hpp"

NAMESPACE_BEGIN( GameEngine );

class Rendereable{
public:
  virtual void draw(  ) = 0;
  virtual void update(  )= 0;
  virtual void destroy(  ) = 0;
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_GAMEOBJECT_HPP__ */
