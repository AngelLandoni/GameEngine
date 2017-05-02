//
//  sprite.cpp
//  GameEngine
//
//  Created by Angel Land on 7/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "sprite.hpp"

NAMESPACE_BEGIN( GameEngine );

Sprite::Sprite(  ):
_mVao(0),
_mProgram(nullptr){
  glGenVertexArrays( 1,&_mVao );
}

Sprite::~Sprite(  ){

}

void Sprite::init(  ){
  glBindVertexArray(_mVao);
  
  // VERTICES
   static const GLfloat vertices[12] = {-1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
     -1.0,  1.0,  1.0};

  // make and bind the VBO
  glGenBuffers(1, &_mVbo[POSITION_VERTEXBUFFER]);
  glBindBuffer(GL_ARRAY_BUFFER, _mVbo[POSITION_VERTEXBUFFER]);
  // Seteo el buffer de datos
  glBufferData(GL_ARRAY_BUFFER, 12*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
  
  // Setela los datos en la variable con location = 0
  glEnableVertexAttribArray(POSITION_VERTEXBUFFER);
  glVertexAttribPointer(POSITION_VERTEXBUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
  
  // TEXTURA
  const GLfloat uvs[8] = {0,1,1,1,1,0,0,0};
  // make and bind the VBO
  glGenBuffers(1, &_mVbo[TEXTURE_VERTEXBUFFER]);
  glBindBuffer(GL_ARRAY_BUFFER, _mVbo[TEXTURE_VERTEXBUFFER]);
  // Seteo el buffer de datos
  glBufferData(GL_ARRAY_BUFFER, 8*sizeof(GLfloat), uvs, GL_STATIC_DRAW);
  
  // Setela los datos en la variable con location = 1
  glEnableVertexAttribArray(TEXTURE_VERTEXBUFFER);
  glVertexAttribPointer(TEXTURE_VERTEXBUFFER, 2, GL_FLOAT, GL_FALSE, 0,0 );
  
  // COLORES
   static const GLfloat colors[16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
  // make and bind the VBO
  glGenBuffers(1, &_mVbo[COLOR_VERTEXBUFFER]);
  glBindBuffer(GL_ARRAY_BUFFER, _mVbo[COLOR_VERTEXBUFFER]);
  // Seteo el buffer de datos
  glBufferData(GL_ARRAY_BUFFER, 16*sizeof(GLfloat), colors, GL_STATIC_DRAW);
  
  // Setela los datos en la variable con location = 1
  glEnableVertexAttribArray(COLOR_VERTEXBUFFER);
  glVertexAttribPointer(COLOR_VERTEXBUFFER, 4, GL_FLOAT, GL_FALSE, 0,0 );
  
  // INDICES
  static const GLushort indices[6] = {0,1,2,2,3,0};
  // make and bind the VBO
  glGenBuffers(1, &_mVbo[INDEX_VERTEXBUFFER]);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _mVbo[INDEX_VERTEXBUFFER]);
  // Seteo el buffer de datos
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(GLushort), indices, GL_STATIC_DRAW);
  
  // -1??????????????? numero de elementos
  
  // unbind the VAO
  glBindVertexArray(0);
}

void Sprite::draw(  ){
  
  _mProgram->setUniform("transform", _mTransform.getTransformation(  ) );
  
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  
  _mTexture->bind(0);
  
  _mProgram->enable(  );
  
  glBindVertexArray(_mVao);
  
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,_mVbo[INDEX_VERTEXBUFFER] );
  
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
  
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,0 );
  
  glBindVertexArray(0);
  _mProgram->disable(  );
  
  _mTexture->unBind(  );

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void Sprite::update(  ){

}

void Sprite::destroy(  ){
}


NAMESPACE_END(GameEngine);