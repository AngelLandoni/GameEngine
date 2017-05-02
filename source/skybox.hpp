//
//  skybox.hpp
//  GameEngine
//
//  Created by Angel Land on 21/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_SKYBOX_HPP__
#define __GAMEENGINE_SKYBOX_HPP__

#include "../extern/glew/glew.h"
#include "../extern/glfw3/glfw3.h"

#include "utils/helpers.hpp"
#include "maths/transform.hpp"
#include "graphics/rendering/rendereable.hpp"
#include "graphics/texture.hpp"

NAMESPACE_BEGIN( GameEngine );

class SkyBox : public Rendereable{
public:
  enum FaceType{TOP,BOTTOM,FRONT,BACK,LEFT,RIGHT,NUM_FACES};
  enum{
    POSITION_VERTEXBUFFER,
    NUMBER_VERTEXBUFFER
  };
protected:
  // VAO
  GLuint _mVao;
  // VBO
  GLuint _mVbo[NUMBER_VERTEXBUFFER];
  // Shader
  Shader* _mProgram;
  // Textures
  Texture* _mTexture;
  // Transformation
  Transform _mTransform;
public:
  SkyBox(  );
  virtual ~SkyBox(  );

  void init(  );
  inline void setProgram( Shader* _program ){ _mProgram = _program; }
  inline void setTexture( Texture* _texture ){ _mTexture = _texture; }
  inline void transform( Transform _transform ){ _mTransform = _transform; }
  
  virtual void draw(  ) override;
  virtual void update(  ) override;
  virtual void destroy(  ) override;
};


const GLfloat skyboxVertices[] = {
  // Positions
  -1.0f,  1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f,  1.0f, -1.0f,
  -1.0f,  1.0f, -1.0f,
  
  -1.0f, -1.0f,  1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f,  1.0f, -1.0f,
  -1.0f,  1.0f, -1.0f,
  -1.0f,  1.0f,  1.0f,
  -1.0f, -1.0f,  1.0f,
  
  1.0f, -1.0f, -1.0f,
  1.0f, -1.0f,  1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f,  1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  
  -1.0f, -1.0f,  1.0f,
  -1.0f,  1.0f,  1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f, -1.0f,  1.0f,
  -1.0f, -1.0f,  1.0f,
  
  -1.0f,  1.0f, -1.0f,
  1.0f,  1.0f, -1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f,  1.0f,  1.0f,
  -1.0f,  1.0f,  1.0f,
  -1.0f,  1.0f, -1.0f,
  
  -1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f,  1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f,  1.0f,
  1.0f, -1.0f,  1.0f
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_SKYBOX_HPP__ */
