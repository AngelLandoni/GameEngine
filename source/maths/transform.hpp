//
//  transform.hpp
//  GameEngine
//
//  Created by Angel Land on 15/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_TRANSFORM_HPP__
#define __GAMEENGINE_TRANSFORM_HPP__

#include "../../extern/glm/glm.hpp"
#include "../../extern/glm/gtc/matrix_transform.hpp"
#include "../../extern/glm/gtx/transform.hpp"
#include "../../extern/glm/mat4x4.hpp"

#include "../../extern/glm/vec3.hpp"
#include "../../extern/glm/vec4.hpp"

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

struct Transform{
  glm::vec3 _mTranslate;
  glm::vec4 _mRotate;
  glm::vec3 _mScale;
  
  Transform(  );
  Transform( glm::vec3 _t,glm::vec4 _r= glm::vec4(0,1,1,1),glm::vec3 _s = glm::vec3(1,1,1) );
  
  virtual ~Transform(  );
  
  inline void translate( const glm::vec3& _t ){ _mTranslate = _t; }
  inline void rotate( const glm::vec4& _r ){ _mRotate = _r; }
  inline void scale( const glm::vec3& _s ){ _mScale = _s; }
  
  void reset(  );
  
  glm::mat4 getTransformation(  );
  
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_TRANSFORM_HPP__ */
