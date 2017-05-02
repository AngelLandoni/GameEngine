//
//  light.hpp
//  GameEngine
//
//  Created by Angel Land on 6/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_LIGHT_HPP__
#define __GAMEENGINE_LIGHT_HPP__

#include "../../extern/glm/vec3.hpp"
#include "../../extern/glm/vec4.hpp"

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

typedef struct Light{
  glm::vec3 position;
  glm::vec4 color;
  float intensity;
}Light;

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_LIGHT_HPP__ */
