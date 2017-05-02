//
//  scene.hpp
//  GameEngine
//
//  Created by Angel Land on 27/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_SCENE_HPP__
#define __GAMEENGINE_SCENE_HPP__

#include <vector>

#include "utils/helpers.hpp"

#include "entity.hpp"
#include "skybox.hpp"

#include "graphics/light.hpp"
#include "graphics/rendering/rendereable.hpp"
#include "graphics/rendering/sprite.hpp"

#include "graphics/camera/camera.hpp"

NAMESPACE_BEGIN(GameEngine);

class Scene : public Rendereable{
protected:
  Camera* _mCamera;
  SkyBox* _mSkyBox;
  //fix It!.
  std::vector<Entity*> _mEntities; // delete this from memory.
  std::vector<Sprite*> _mSprites; // delete this from memory.
  
  std::vector<Light*> _mStaticLights;
  bool _mIsActive;
public:
  Scene(  );
  virtual ~Scene(  );
  
  virtual void draw(  ) override;
  virtual void update(  ) override;
  virtual void destroy(  ) override;

  void setCamera( Camera* _camera );
  void setSkyBox( SkyBox* _skybox );
  
  void addEntity( Entity* _entity );
  void addSprite( Sprite* _sprite );
  inline void addStaticLight( Light* _light ){ _mStaticLights.push_back(_light); }
};

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_SCENE_HPP__ */
