//
//  terrain_shader.hpp
//  GameEngine
//
//  Created by Angel Land on 28/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_TERRAIN_HPP__
#define __GAMEENGINE_TERRAIN_HPP__

#include "../../../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

const std::string TERRAIN_VERTEXSHADER = R"(

#version 330

layout(location = 0)in vec3 Position;
layout(location = 1)in vec4 Color;
layout(location = 2)in vec2 TextCoord;
layout(location = 3)in vec3 Normal;

uniform mat4 projection;
uniform mat4 view;

uniform mat4 transform;

out vec2 vs_uv;

// FOG
out float visivility;
const float density=0.0075;
const float gradient=3.0;

void main(  ){
  vec4 worldPosition = transform * vec4(Position,1.0f);
  vec4 poisitionRelativeToCamera = view * worldPosition;
  
  vec4 pos = projection * poisitionRelativeToCamera;
  gl_Position = pos;
  vs_uv = TextCoord;
  
  float distanceVertexCamera = length(poisitionRelativeToCamera.xyz);
  visivility = exp( -pow((distanceVertexCamera*density),gradient) );
  visivility = clamp(visivility,0.0,1.0);
}

)";


const std::string TERRAIN_FRAGMENTSHADER = R"(

#version 330

uniform sampler2D blendMap;
uniform sampler2D textureA; // BackGround
uniform sampler2D textureB;
uniform sampler2D textureC;
uniform sampler2D textureD;


out vec4 fragColor;

in vec2 vs_uv;

// FOG
//vec3 skyColorFog = vec4(1.0,1.0,1.0,1.0);
in float visivility;

void main(){

  vec4 blendMapFragColor = texture( blendMap,vs_uv );
  float backTextureAmount = 1-(blendMapFragColor.r+blendMapFragColor.g+blendMapFragColor.b);
  vec2 tileCoords = vs_uv * 100.0;
  vec4 backgroundTexture = texture( textureA,tileCoords ) * backTextureAmount;
  
  vec4 rTextureColor = texture(textureB,tileCoords) * blendMapFragColor.r;
  vec4 gTextureColor = texture(textureC,tileCoords) * blendMapFragColor.g;
  vec4 bTextureColor = texture(textureD,tileCoords) * blendMapFragColor.b;
  
  vec4 totalColor = backgroundTexture + rTextureColor + gTextureColor + bTextureColor;
  
  fragColor = mix( vec4(1.0,1.0,1.0,1.0),totalColor,visivility ) * vec4(0.1,0.1,0.1,1.0);
}

)";

NAMESPACE_END(GameEngine);


#endif /* __GAMEENGINE_TERRAIN_HPP__ */
