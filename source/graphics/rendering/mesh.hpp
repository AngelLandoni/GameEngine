//
//  mesh.hpp
//  GameEngine
//
//  Created by Angel Land on 15/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_MESH_HPP__
#define __GAMEENGINE_MESH_HPP__

#include <vector>

#include "../../../extern/glew/glew.h"
#include "../../../extern/glfw3/glfw3.h"

#include "../../../extern/glm/glm.hpp"
#include "../../../extern/glm/vec2.hpp"
#include "../../../extern/glm/vec3.hpp"
#include "../../../extern/glm/vec4.hpp"
#include "../../../extern/glm/gtc/type_ptr.hpp"
#include "../../../extern/glm/gtc/matrix_transform.hpp"
#include "../../../extern/glm/gtx/transform.hpp"

#include "../../utils/helpers.hpp"

#include "../../maths/transform.hpp"

#include "../shaders/shader.hpp"

#include "rendereable.hpp"

using namespace glm;

NAMESPACE_BEGIN( GameEngine );

class Mesh : public Rendereable{
  enum{
    POSITION_VERTEXBUFFER,
    COLOR_VERTEXBUFFER,
    TEXTURE_VERTEXBUFFER,
    NORMAL_VERTEXBUFFER,
    INDEX_VERTEXBUFFER,
    NUMBER_VERTEXBUFFER
  };
protected:
  // VAO
  GLuint _mVao;
  // VBO
  GLuint _mVbo[NUMBER_VERTEXBUFFER];
  // IBO
  // Shader
  Shader* _mProgram;
  // Coordenadas de los vertices
  std::vector<float>* _mVertices;
  // Coordenadas de la textura
  std::vector<float>* _mUVs;
  // Coordenadas de las normales
  std::vector<float>* _mNormals;
  // Coordenadas de los colores
  std::vector<float>* _mColors;
  // Indeices de los vertices
  std::vector<GLushort>* _mIndices;
  // Transformacion
  Transform _mTransform;
public:
  Mesh(  );
  Mesh(std::vector<float> _vertices,
       std::vector<float> _uvs,
       std::vector<float> _colors,
       std::vector<float> _normal,
       std::vector<GLushort> _indices );
  virtual ~Mesh(  );
  
  /* Seters */
  
  
  inline void setProgram( Shader* _s ){ _mProgram = _s; }
  
  void setVertices( std::vector<float> _v );
  
  void setUVs( std::vector<float> _uvs );
  
  
  void setNormals( std::vector<float> _n );
  
  void setColors( std::vector<float> _c );
  
  void setIndices( std::vector<GLushort> _i );
  
  // Translacion rotacion escalado
  inline void transform( Transform _t ){ _mTransform = _t; }
  
  // Envia los bufferes a la placa de video
  void init(  );
  
  // Elimina los vertices, uvs, colors e indices
  void freeLocalMemory(  );
  
  virtual void draw(  ) override;
  virtual void update(  ) override;
  virtual void destroy(  ) override;

  friend class Scene;
};


NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_MESH_HPP__ */
