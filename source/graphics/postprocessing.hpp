//
//  postprocessing.hpp
//  GameEngine
//
//  Created by Angel Land on 19/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_POSTPROCESSING_HPP__
#define __GAMEENGINE_POSTPROCESSING_HPP__

#include <iostream>

#include "../../extern/glew/glew.h"
#include "../../extern/glfw3/glfw3.h"

#include "../utils/helpers.hpp"

#include "texture.hpp"

NAMESPACE_BEGIN( GameEngine );

class PostProcessing{
protected:
  GLuint _mFBO; // FrameBufferObject
  GLuint _mRBO; // RenderBufferObject
  Texture* _mTexture; // Final texture
public:
  PostProcessing(  ); // Constructor
  virtual ~PostProcessing(  ); // Destructor
  
  void create( float _width,float _height );
  
  void bind(  ) const; // Active
  void unBind() const; // Desactive
  
  inline Texture* getTexture(  ){ return _mTexture; }
};

GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil,float _width,float _height);

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_POSTPROCESSING_HPP__ */
