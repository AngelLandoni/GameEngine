//
//  basic_shader.hpp
//  GameEngine
//
//  Created by Angel Land on 28/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef _GAMEENGINE_BASICSHADER_HPP_
#define _GAMEENGINE_BASICSHADER_HPP_

#include "../../../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

const std::string BASIC_VERTEXSHADER = R"(

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
const float density=0.0035;
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


const std::string BASIC_FRAGMENTSHADER = R"(

#version 330

uniform sampler2D textData;

out vec4 fragColor;

in vec2 vs_uv;

// FOG
//vec3 skyColorFog = vec4(1.0,1.0,1.0,1.0);
in float visivility;

void main(){
  //fragColor = vec4(1.0,1.0,1.0,1.0);
  mix( vec4(1.0,1.0,1.0,1.0),texture( textData,vs_uv ),visivility );
}

)";

NAMESPACE_END(GameEngine);

#endif /* _GAMEENGINE_BASICSHADER_HPP_ */
