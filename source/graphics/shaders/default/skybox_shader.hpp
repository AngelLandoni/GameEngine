//
//  skybox_shader.hpp
//  GameEngine
//
//  Created by Angel Land on 21/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_SKYBOXSHADER_HPP__
#define __GAMEENGINE_SKYBOXSHADER_HPP__

#include "../../../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

const std::string SKYBOX_VERTEXSHADER =
R"(
#version 330

layout(location = 0)in vec3 Position;

uniform mat4 projection;
uniform mat4 view;

uniform mat4 transform;

out vec3 vs_uv;

void main(  ){
  vec4 worldPosition = transform * vec4(Position,1.0f);
  vec4 poisitionRelativeToCamera = view * worldPosition;
  
  vec4 pos = projection * poisitionRelativeToCamera;
  gl_Position = pos;
  
  vs_uv = Position;
}

)";

const std::string SKYBOX_FRAGMENTSHADER = R"(
#version 330

uniform samplerCube cubeTexture;

out vec4 fragColor;

in vec3 vs_uv;

void main(){
  fragColor = texture(cubeTexture,vs_uv);
}

)";

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_SKYBOXSHADER_HPP__ */
