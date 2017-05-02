//
//  shader.cpp
//  MushRoom
//
//  Created by Angel Land on 29/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

#include "shader.hpp"

NAMESPACE_BEGIN( GameEngine );

Shader::Shader(  ){

}

Shader::Shader( const std::string& _fileName ){
  load( _fileName );
}

Shader::~Shader(  ){
  unsigned int i = 0;
  for( i=0;i<NUMBER_SHADERS;i++ )
    glDetachShader( _mProgramID, _mShaders[i] );
  glDeleteProgram( _mProgramID );
}

bool Shader::load( const std::string& _fileName ){
  if( _fileName == "" )
    return false;

  _mFileName = _fileName;
  
  _mProgramID = glCreateProgram(  );

  File shader;

  shader.load( _fileName + SHADER_VERTEX_EXTENSION );
  _mShaders[VERTEX_SHADER] = compile( shader.getData(  ),GL_VERTEX_SHADER );
  
  shader.load( _fileName + SHADER_FRAGMENT_EXTENSION );
  _mShaders[FRAMENT_SHADER] = compile( shader.getData(  ),GL_FRAGMENT_SHADER );

  unsigned int i = 0;
  for( i=0;i<NUMBER_SHADERS;i++ ){
    glAttachShader( _mProgramID , _mShaders[i] );
    glDeleteShader( _mShaders[i] );
  }

  glLinkProgram( _mProgramID );
  checkError( _mProgramID,GL_LINK_STATUS, true );
  glValidateProgram( _mProgramID );
  checkError( _mProgramID,GL_VALIDATE_STATUS,true );

  return true;
}

void Shader::create(const std::string& _vertex,const std::string& _fragment){
  
  _mFileName = "";
  
  _mProgramID = glCreateProgram(  );
  
  _mShaders[VERTEX_SHADER] = compile( _vertex,GL_VERTEX_SHADER );
  _mShaders[FRAMENT_SHADER] = compile( _fragment,GL_FRAGMENT_SHADER );

  
  unsigned int i = 0;
  for( i=0;i<NUMBER_SHADERS;i++ ){
    glAttachShader( _mProgramID , _mShaders[i] );
    glDeleteShader( _mShaders[i] );
  }
  
  glLinkProgram( _mProgramID );
  checkError( _mProgramID,GL_LINK_STATUS, true );
  glValidateProgram( _mProgramID );
  checkError( _mProgramID,GL_VALIDATE_STATUS,true );
}

void Shader::enable(  ) const {
  glUseProgram( _mProgramID );
}

void Shader::disable(  ) const{
  glUseProgram( 0 );
}

GLuint Shader::getId(  ) const{
  return _mProgramID;
}


void Shader::setUniform(const std::string& _varName,
                        const float& _data ){
  enable(  );
  GLint loc = glGetUniformLocation(_mProgramID, _varName.c_str());
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
  }
  glUniform1f(loc, _data);
  disable(  );
}

void Shader::setUniform(const std::string& _varName,
                        const int& _data ){
  enable();
  GLint loc = glGetUniformLocation( _mProgramID ,_varName.c_str(  ) );
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
    return;
  }
  glUniform1i(loc, _data);
  disable();
}

void Shader::setUniform(const std::string& _varName,
                        const glm::mat4& _matrix ){
  enable(  );
  GLint loc = glGetUniformLocation( _mProgramID ,_varName.c_str(  ) );
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
    return;
  }
  
  glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr( _matrix ));
  disable(  );
}

void Shader::setUniform(const std::string& _varName,
                        const glm::vec2& _vector ){
  enable(  );
  GLint loc = glGetUniformLocation( _mProgramID ,_varName.c_str(  ) );
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
    return;
  }
  glUniform2f(loc, _vector.x, _vector.y);
  disable(  );
}

void Shader::setUniform(const std::string& _varName,
                        const glm::vec3& _vector ){
  enable( );
  GLint loc = glGetUniformLocation( _mProgramID ,_varName.c_str(  ) );
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
    return;
  }
  glUniform3f(loc, _vector.x, _vector.y, _vector.z);
  disable(  );
}

void Shader::setUniform(const std::string& _varName,
                        const glm::vec4& _vector){
  enable();
  GLint loc = glGetUniformLocation( _mProgramID ,_varName.c_str(  ) );
  if(loc==-1){
    std::cout<<"[Shader] Error: the variable ("<<_varName<<") doesn't exist!."<<std::endl;
    std::cout.flush(  );
    return;
  }
  glUniform4f(loc, _vector.x, _vector.y, _vector.z, _vector.w);
  disable();
}

int Shader::getUniformLocation( const std::string& _var ){
  return glGetUniformLocation(_mProgramID, _var.c_str());
}

// Checkea los errores
void Shader::checkError( GLuint _shader,
                         GLuint _flag,
                         bool _isProgram ){
  GLint success = 0;
  GLchar error[1024] = { 0 };

  if( _isProgram )
     glGetProgramiv( _shader, _flag, &success);
  else
     glGetShaderiv( _shader, _flag, &success);

  if(success == GL_FALSE){
     if( _isProgram )
         glGetProgramInfoLog( _shader, sizeof(error), NULL, error);
     else
         glGetShaderInfoLog( _shader, sizeof(error), NULL, error);
     std::cerr << error << std::endl;
  }
}

// Compila el shader
GLuint Shader::compile( const std::string& _code, unsigned int _type ){
  GLuint shader = glCreateShader( _type );

  if(shader == 0)
    std::cerr<<"Error compiling shader type "<<_type<<std::endl;

  const GLchar* p[1];
  p[0] = _code.c_str();
  GLint lengths[1];
  lengths[0] = (int)_code.length();

  glShaderSource( shader, 1, p, lengths );
  glCompileShader( shader );

  checkError( shader, GL_COMPILE_STATUS, false );

  return shader;
}

NAMESPACE_END( GameEngine );
