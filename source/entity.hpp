//
//  entity.cpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_MODEL_HPP__
#define __GAMEENGINE_MODEL_HPP__

#include "utils/helpers.hpp"

#include "maths/transform.hpp"

//#include "graphics/rendering/rendereable.hpp"
#include "graphics/rendering/mesh.hpp"

#include "texture.hpp"
#include "object.hpp"

NAMESPACE_BEGIN( GameEngine );

class Entity : public Rendereable, public Object{
protected:
  Mesh* _mMesh;
  Texture* _mTexture;
  bool _mVisibility;
  bool _mStatic;
  Entity* _mSuper;
  Shader* _mProgram;
  std::vector<Entity*> _mChildren;
  Transform _mTransform;
public:
  Entity(  );
  virtual ~Entity(  );
  
  virtual void draw(  ) override;
  virtual void update(  ) override;
  virtual void destroy(  ) override;
  
  virtual void setFather( Entity* _super );
  virtual void addChild( Entity* _child );
  
  virtual void setMesh( Mesh* _mesh );
  virtual void setTexture( Texture* _texture );
  
  bool transform( const Transform& _transformation );
  
  void setVisibility( const bool& _state );
  void setStatic( const bool& _state );

  inline void setProgram( Shader* _program ){
    _mProgram = _program;
  }

  friend class Scene;
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_MODEL_HPP__ */
