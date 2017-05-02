//
//  skybox.cpp
//  GameEngine
//
//  Created by Angel Land on 21/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "skybox.hpp"

NAMESPACE_BEGIN( GameEngine );

SkyBox::SkyBox(  ):
_mTexture(nullptr)
{
  glGenVertexArrays( 1,&_mVao );
}

SkyBox::~SkyBox(  ){

}

void SkyBox::init(  ){
  
  // Bindeo el vao
  glBindVertexArray(_mVao);
  
  // VERTICES
  
  // make and bind the VBO
  glGenBuffers(1, &_mVbo[POSITION_VERTEXBUFFER]);
  glBindBuffer(GL_ARRAY_BUFFER, _mVbo[POSITION_VERTEXBUFFER]);
  // Seteo el buffer de datos
  glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
  
  // Setela los datos en la variable con location = 0
  glEnableVertexAttribArray(POSITION_VERTEXBUFFER);
  glVertexAttribPointer(POSITION_VERTEXBUFFER, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

  
  // unbind the VAO
  glBindVertexArray(0);
}

void SkyBox::draw(  ){
  glBindTexture(GL_TEXTURE_CUBE_MAP, _mTexture->_mTextureID);
  
  _mProgram->setUniform( "transform",_mTransform.getTransformation(  ) );

  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  
  _mProgram->enable( );
  
  glDepthFunc(GL_LEQUAL);
  
  glBindVertexArray(_mVao);
  
  glDrawArrays(GL_TRIANGLES, 0, 36);
  
  glBindVertexArray(0);
  
  glDepthFunc(GL_LESS);
  
  _mProgram->disable(  );
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  
  
  glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void SkyBox::update(  ){
  
}

void SkyBox::destroy(  ){
  
}

NAMESPACE_END( GameEngine );