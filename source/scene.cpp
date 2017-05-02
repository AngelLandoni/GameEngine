//
//  scene.cpp
//  GameEngine
//
//  Created by Angel Land on 27/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "scene.hpp"

NAMESPACE_BEGIN(GameEngine);

Scene::Scene(  ):
_mIsActive(false),
_mCamera(nullptr),
_mSkyBox(nullptr){
  
}
//===============================================================================================
Scene::~Scene(  ){
  if( _mCamera != nullptr )
    delete _mCamera;
  if( _mSkyBox != nullptr )
    delete _mSkyBox;
}
//===============================================================================================
void Scene::draw(  ){
  uint i=0;
  const uint lengthEntities = (uint)_mEntities.size(  );
  const uint lengthSprites = (uint)_mSprites.size(  );
  
  if( _mCamera != nullptr )
    _mCamera->update();
  
  // SkyBox Render
  if (_mSkyBox != nullptr)
    _mSkyBox->draw(  );
  
  // 3D Render
  while( i<lengthEntities ){
    Shader* _program = _mEntities[i]->_mProgram;
    _mEntities[i]->_mMesh->_mProgram = _program;
      
    _mEntities[i]->_mMesh->_mProgram->setUniform(GLSL_CAMERA_PROJECTION,_mCamera->getPerspective(  ) );
    _mEntities[i]->draw(  );
    i++;
  }
  
  // 2D Render
  i=0;
  while( i<lengthSprites ){
    _mSprites[i]->_mProgram->setUniform(GLSL_CAMERA_PROJECTION,_mCamera->getOrtho(  ) );
    _mSprites[i]->draw(  );
    i++;
  }
  
}
//===============================================================================================

void Scene::update(  ){

}
//===============================================================================================

void Scene::destroy(  ){

}
//===============================================================================================

void Scene::addEntity( Entity* _entity ){
  _mEntities.push_back(_entity);
}
//===============================================================================================

void Scene::addSprite( Sprite* _sprite ){
  _mSprites.push_back( _sprite );
}
//===============================================================================================

void Scene::setCamera( Camera* _camera ){
  _mCamera = _camera;
}
//===============================================================================================
void Scene::setSkyBox( SkyBox* _skybox ){
  _mSkyBox = _skybox;
}
//===============================================================================================


NAMESPACE_END(GameEngine);