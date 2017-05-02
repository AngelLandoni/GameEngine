//
//  shader.hpp
//  MushRoom
//
//  Created by Angel Land on 29/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

/*
 * Cambiar la carga de shades al shader manager
 * para optimizar RAM.
 */

#ifndef __GAMEENGINE_SHADER_H__
#define __GAMEENGINE_SHADER_H__

#include <iostream>
#include <string>

#include "../../../extern/glfw3/glfw3.h"
#include "../../../extern/glm/mat4x4.hpp"
#include "../../../extern/glm/gtc/type_ptr.hpp"

#include "../../utils/helpers.hpp"
#include "../../utils/file.hpp"

NAMESPACE_BEGIN( GameEngine );

#define SHADER_VERTEX_EXTENSION ".vs"
#define SHADER_FRAGMENT_EXTENSION ".fs"

class Shader{
  enum{
    VERTEX_SHADER,
    FRAMENT_SHADER,
    NUMBER_SHADERS
  };
  // El id del shader en gpu
  GLuint _mProgramID;
  // Referencia a los shaders en memoria
  GLuint _mShaders[NUMBER_SHADERS];
  // Nombre del shader / path
  std::string _mFileName;
public:
  Shader(  );
  Shader( const std::string& _fileName );
  virtual ~Shader(  );
  // Cargo el shader
  bool load( const std::string& _fileName );
  // Crea el shader desde strings
  void create(const std::string& _vertex,
              const std::string& _fragment);
  // Usa el shader program
  void enable(  ) const;
  // Desactiva el shader
  void disable() const;
  // Retorna el id del shader
  GLuint getId( ) const;
  // Setea una variable uniform
  void setUniform( const std::string& _varName,const float& _data );
  void setUniform( const std::string& _varName,const int& _data );
  void setUniform( const std::string& _varName,const glm::mat4& _matrix );
  void setUniform( const std::string& _varName,const glm::vec2& _vector );
  void setUniform( const std::string& _varName,const glm::vec3& _vector );
  void setUniform( const std::string& _varName,const glm::vec4& _vector );
  
  int getUniformLocation( const std::string& _var );
  
  inline std::string getName(  ) const{ return _mFileName; }
  
private:
  // Checkea los errores
  void checkError( GLuint _shader, GLuint _flag, bool _isProgram );
  // Compila el shader
  GLuint compile( const std::string& _text, unsigned int _type );
};

NAMESPACE_END( GameEngine );

#endif
