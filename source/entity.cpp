//
//  entity.cpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "entity.hpp"

NAMESPACE_BEGIN( GameEngine );

//===============================================================================================
Entity::Entity():
_mMesh(nullptr),
_mVisibility(true),
_mStatic(false),
_mSuper(nullptr)
{}
//===============================================================================================
Entity::~Entity(){
  if( _mMesh != nullptr )
    delete _mMesh;
}
//===============================================================================================
void Entity::draw(  ){
  if( _mVisibility ){
    for( Entity* entity : _mChildren )
      entity->draw(  );
    _mMesh->transform(_mTransform);
    _mTexture->bind( 0 );
    _mMesh->draw(  );
    _mTexture->unBind(  );
  }
}
//===============================================================================================
void Entity::update(  ){
  
}
//===============================================================================================
void Entity::destroy(  ){
  //delete this;
}
//===============================================================================================
void Entity::setFather( Entity* _super ){
  _mSuper = _super;
}
//===============================================================================================
void Entity::addChild( Entity* _child ){
  _mChildren.push_back( _child );
}
//===============================================================================================
void Entity::setMesh( Mesh* _mesh ){
  _mMesh = _mesh;
}
//===============================================================================================
void Entity::setTexture( Texture* _texture ){
  _mTexture = _texture;
}
//===============================================================================================
bool Entity::transform( const Transform& _transformation ){
  if( _mStatic ){
    // Reemplazar por una consola en el motor
    // Consola OpenGL
    std::cout<<"[Entity]["<<Object::_mId<<"] Warning: The entity is static!."<<std::endl;
    std::cout.flush(  );
    return false;
  }
  if( _mMesh != nullptr ){
    _mTransform = _transformation;
    return true;
  }
  
  std::cout<<"[Entity]["<<Object::_mId<<"] Error: In the entity mesh is null!."<<std::endl;
  std::cout.flush(  );

  return false;
}
//===============================================================================================
void Entity::setVisibility( const bool& _state ){
  _mVisibility = _state;
}
//===============================================================================================
void Entity::setStatic( const bool& _state ){
  _mStatic = _state;
}
//===============================================================================================

NAMESPACE_END( GameEngine );






