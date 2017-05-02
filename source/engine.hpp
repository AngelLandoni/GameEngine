//
//  engine.hpp
//  GameEngine
//
//  Created by Angel Land on 9/3/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_ENGINE_HPP__
#define __GAMEENGINE_ENGINE_HPP__

#include <iostream>
#include <chrono>
#include <thread>

#include "graphics/window.hpp"
#include "graphics/shaders/shader.hpp"
#include "graphics/shaders/shadermanager.hpp"

#include "graphics/shaders/default/basic_shader.hpp"
#include "graphics/shaders/default/terrain_shader.hpp"
#include "graphics/shaders/default/normal_shader.hpp"
#include "graphics/shaders/default/sprite_shader.hpp"
#include "graphics/shaders/default/skybox_shader.hpp"
#include "graphics/shaders/default/texture_shader.hpp"

#include "graphics/rendering/mesh.hpp"
#include "graphics/rendering/sprite.hpp"
#include "graphics/rendering/basic/testcube.hpp"

#include "graphics/texturemanager.hpp"
#include "graphics/rendering/meshmanager.hpp"

#include "graphics/camera/camera.hpp"
#include "graphics/camera/flycamera.hpp"

#include "graphics/postprocessing.hpp"

#include "maths/color.hpp"
#include "maths/mat4.hpp"

#include "events/inputmanager.hpp"

#include "utils/timer.hpp"
#include "utils/fps.hpp"

#include "../extern/glm/mat4x4.hpp"
#include "../extern/glm/glm.hpp"
#include "../extern/glm/gtc/type_ptr.hpp"

#include "../extern/glm/gtc/matrix_transform.hpp"
#include "../extern/glm/gtx/transform.hpp"

#include "skybox.hpp"
#include "scene.hpp"

#define ENGINE_VERSION "V0.01"
#define ENGINE_AUTHOR "LANDONI,Angel"

#endif /* __GAMEENGINE_ENGINE_HPP__ */
