//
//  sprite.hpp
//  GameEngine
//
//  Created by Angel Land on 7/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_SPRITE_HPP__
#define __GAMEENGINE_SPRITE_HPP__

#include <vector>

#include "../../../extern/glew/glew.h"
#include "../../../extern/glfw3/glfw3.h"

#include "../../utils/helpers.hpp"

#include "../../maths/transform.hpp"

#include "../texture.hpp"

#include "rendereable.hpp"

NAMESPACE_BEGIN( GameEngine );

class Sprite : public Rendereable{
  enum{
    POSITION_VERTEXBUFFER,
    COLOR_VERTEXBUFFER,
    TEXTURE_VERTEXBUFFER,
    INDEX_VERTEXBUFFER,
    NUMBER_VERTEXBUFFER
  };
protected:
  GLuint _mVao; // VAO
  GLuint _mVbo[NUMBER_VERTEXBUFFER]; // VBO
  Shader* _mProgram; // Shader
  Texture* _mTexture; // Texture
  Transform _mTransform; // Transform
public:
  Sprite(  );
  virtual ~Sprite(  );
  
  inline void setTexture( Texture* _texture ){
    _mTexture = _texture;
  }
  
  inline void setProgram( Shader* _program ){
    _mProgram = _program;
  }
  
  inline void transform( const Transform& _transform ){
    _mTransform = _transform;
  }
  
  // Set vao and vbo to the gpu
  void init(  );
  
  virtual void draw(  ) override;
  virtual void update(  ) override;
  virtual void destroy(  ) override;

  friend class Scene;
};

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_SPRITE_HPP__ */
