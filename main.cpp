//
//  main.cpp
//  GameEngine
//
//  Created by Angel Land on 9/3/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//
#include <cstdlib>

#include "source/engine.hpp"

using namespace GameEngine;

//===============================================================================================
#define SCREEN_WITDH 1600
#define SCREEN_HEIGHT 900
//===============================================================================================

void load_shaders(  );
void load_textures(  );
void load_meshes(  );

//===============================================================================================
int main( int argc,char** argv ){
  // The window
  Window window;
  // Input hanlder
  InputManager input;
  // A color
  Color background( Color::white );
  // Create window
  window.create( "Engine Testing 1", SCREEN_WITDH, SCREEN_HEIGHT );
  
  // Set window background color
  glClearColor( background.r, background.g, background.b, 1.0f );
  
  // Load Resources
  load_shaders(  );
  load_textures(  );
  load_meshes(  );
  
  //Camera
  FlyCamera* camera = new FlyCamera( SCREEN_WITDH,SCREEN_HEIGHT );
  
  // The Logo!
  Sprite* logo = new Sprite(  );
  logo->setTexture( TextureManagerInstance.get("logoGrande") );
  logo->setProgram( ShaderManagerInstance.get("sprite") );
  logo->transform( Transform(glm::vec3( 2.0f,2.0f,0.0f ),
                             glm::vec4( 0,1,1,1 ),
                             glm::vec3( 2.0f,1.0f,1.0f ) ));
  logo->init(  );
  
  // SkyBox
  SkyBox* skyboxsunny = new SkyBox(  );
  skyboxsunny->setProgram(ShaderManagerInstance.get("skyBoxSunny"));
  skyboxsunny->setTexture(TextureManagerInstance.get("skyBoxSunny"));
  skyboxsunny->transform(Transform({0,0,0},{0,1,0,0},{500,500,500}));
  skyboxsunny->init(  );
  
  
  // Mesa
  Entity* mesa = new Entity();
  mesa->setMesh(MeshManagerInstance.get("stall"));
  mesa->setTexture(TextureManagerInstance.get("stall"));
  mesa->setProgram(ShaderManagerInstance.get("texture"));
  mesa->transform(Transform(glm::vec3(0,0,0)));

  // Barril
  Entity* barrel = new Entity();
  barrel->setMesh(MeshManagerInstance.get("woodBarrel"));
  barrel->setTexture(TextureManagerInstance.get("woodBarrel"));
  barrel->setProgram(ShaderManagerInstance.get("texture"));
  barrel->transform(Transform(glm::vec3(8,0,0)));

  // Floating Jail
  Entity* jail = new Entity(  );
  jail->setMesh(MeshManagerInstance.get("floatingJail"));
  jail->setTexture(TextureManagerInstance.get("floatingJail"));
  jail->setProgram(ShaderManagerInstance.get("texture"));
  jail->transform(Transform(glm::vec3(12,0,0)));
  
  // Level
  Scene levelDemo;
  levelDemo.setCamera( camera );
  levelDemo.setSkyBox( skyboxsunny );
  levelDemo.addSprite( logo );
  levelDemo.addEntity( mesa );
  levelDemo.addEntity( barrel );

  // Floating Jail
  for( int i=0;i<50;i++ ){
    Entity* tempjail = new Entity(  );
    tempjail->setMesh(MeshManagerInstance.get("floatingJail"));
    tempjail->setTexture(TextureManagerInstance.get("floatingJail"));
    tempjail->setProgram(ShaderManagerInstance.get("texture"));
    tempjail->transform( Transform(glm::vec3(14+i*5,0,0),
                                   glm::vec4( (float)(rand()%360),0,1,0 ),
                                   glm::vec3( 1,1,1 ) ));
    levelDemo.addEntity( tempjail );
  }
  
  
  
  
  // Main Loop
  while( !window.close(  ) ){
    window.clear(  );
    
    if( input.isKeyPressed( GLFW_KEY_ESCAPE ) ){
      window.close(  );
      break;
    }
    
    mesa->transform( Transform(glm::vec3(0,0,0),glm::vec4(0,1,0,0),glm::vec3(3,3,3)) );
    
    levelDemo.draw(  );
    
    window.update(  );
  }
  
  delete logo;
  
  return 0;
}
//===============================================================================================
void load_shaders(  ){
  ShaderManagerInstance.createProgram("sprite", SPRITE_VERTEXSHADER,SPRITE_FRAGMENTSHADER );
  ShaderManagerInstance.createProgram("skyBoxSunny",SKYBOX_VERTEXSHADER,SKYBOX_FRAGMENTSHADER);
  ShaderManagerInstance.createProgram("texture", TEXTURE_VERTEXSHADER, TEXTURE_FRAGMENTSHADER);
}
//===============================================================================================
void load_textures(  ){
  TextureManagerInstance.load("logoGrande","resources/textures/wow1.tga");
  TextureManagerInstance.load("stall", "resources/textures/building_1_c.tga");
  TextureManagerInstance.load("woodBarrel", "resources/textures/woodBarrel.tga");
  TextureManagerInstance.load("floatingJail", "resources/textures/floatingJail.tga");

  TextureManagerInstance.loadCubeMap("skyBoxSunny", {
    "resources/skybox/right.tga",
    "resources/skybox/left.tga",
    "resources/skybox/top.tga",
    "resources/skybox/bottom.tga",
    "resources/skybox/back.tga",
    "resources/skybox/front.tga"
  });
}
//===============================================================================================
void load_meshes(  ){
  MeshManagerInstance.load("stall", "resources/models/building_1.obj");
  MeshManagerInstance.load("woodBarrel", "resources/models/woodBarrel.obj");
  MeshManagerInstance.load("floatingJail", "resources/models/floatingJail.obj");
}
//===============================================================================================
