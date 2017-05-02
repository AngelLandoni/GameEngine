//
//  camera.hpp
//  GameEngine
//
//  Created by Angel Land on 17/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_CAMERA_HPP__
#define __GAMEENGINE_CAMERA_HPP__

#include "../../../extern/glm/glm.hpp"
#include "../../../extern/glm/vec3.hpp"
#include "../../../extern/glm/mat4x4.hpp"
#include "../../../extern/glm/gtc/matrix_transform.hpp"
#include "../../../extern/glm/gtx/transform.hpp"

#include "../../utils/helpers.hpp"
#include "../../object.hpp"

#include "../shaders/shader.hpp"
#include "../shaders/shadermanager.hpp"

NAMESPACE_BEGIN( GameEngine );

#define GLSL_CAMERA_PROJECTION "projection"
#define GLSL_CAMERA_VIEW "view"

enum TypeCamera{
  CAMERA_PERSPECTIVE,
  CAMERA_ORTHO,
  CAMERA_MULTI
};

class Camera : public Object{
protected:
  // Proyeccion de la camara Perspectiva / orthografica
  glm::mat4 _mPerspective;
  glm::mat4 _mOrtho;
  // A donde ve la camara
  glm::vec3 _mViewPoint;
  // Posicion de la camara
  glm::vec3 _mPosition;
  // Camera height width
  float _mWidth,_mHeight;
public:
  Camera(  );
  Camera( float _width,float _height );
  virtual ~Camera(  );
  
  virtual void init(  );
  virtual void update(  );
  
  inline virtual void setPerspective(glm::mat4 _projection){
    _mPerspective = _projection;
  }
  inline virtual void setViewPoint( glm::vec3 _viewPoint ){
    _mViewPoint = _viewPoint;
  }
  inline virtual void setPosition( glm::vec3 _position ){
    _mPosition = _position;
  }
  
  inline virtual glm::mat4 getPerspective() const{ return _mPerspective; }
  inline virtual glm::mat4 getOrtho()const{ return _mOrtho; }
  
  glm::mat4 getView(  ) const;
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_CAMERA_HPP__ */
