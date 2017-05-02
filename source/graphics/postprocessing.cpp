//
//  postprocessing.cpp
//  GameEngine
//
//  Created by Angel Land on 19/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "postprocessing.hpp"

NAMESPACE_BEGIN( GameEngine );

PostProcessing::PostProcessing(  ):
_mTexture(nullptr)
{
  glGenFramebuffers(1,&_mFBO);
}

PostProcessing::~PostProcessing(  ){
  glDeleteFramebuffers(1,&_mFBO);
}

void PostProcessing::create( float _width,float _height ){
  glBindFramebuffer( GL_FRAMEBUFFER,_mFBO );
  _mTexture = new Texture(  );
  _mTexture->_mTextureID = generateAttachmentTexture(false,false,_width,_height);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _mTexture->_mTextureID, 0);

  GLuint rbo;
  glGenRenderbuffers(1, &rbo);
  glBindRenderbuffer(GL_RENDERBUFFER, rbo);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); 
  if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void PostProcessing::bind(  )const{
  glBindFramebuffer(GL_FRAMEBUFFER,_mFBO);
}

void PostProcessing::unBind(  )const{
  glBindFramebuffer(GL_FRAMEBUFFER,0);
}


GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil,float _width,float _height){
  // What enum to use?
  GLenum attachment_type;
  if(!depth && !stencil)
    attachment_type = GL_RGB;
  else if(depth && !stencil)
    attachment_type = GL_DEPTH_COMPONENT;
  else if(!depth && stencil)
    attachment_type = GL_STENCIL_INDEX;
  
  //Generate texture ID and load texture data
  GLuint textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  if(!depth && !stencil)
    glTexImage2D(GL_TEXTURE_2D, 0, attachment_type, _width, _height, 0, attachment_type, GL_UNSIGNED_BYTE, NULL);
  else // Using both a stencil and depth test, needs special format arguments
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, _width, _height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glBindTexture(GL_TEXTURE_2D, 0);
  
  return textureID;
}


NAMESPACE_END( GameEngine );