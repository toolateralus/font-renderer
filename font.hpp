#pragma once
// clang-format off
#include <GL/glew.h>
#include <GL/gl.h>
// clang-format on

#include "freetype/freetype.h"
#include <GLFW/glfw3.h>
#include <array>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>

#include <jstl/opengl/shader.hpp>
#include <jstl/opengl/camera.hpp>

using namespace jstl::opengl;

struct Character {
  GLuint textureID;
  glm::ivec2 size;
  glm::ivec2 bearing;
  FT_Pos advance;
};

struct Font {
  static auto defaultFont() -> Font &;
public:
  Font(const std::string &path =
           "/usr/share/fonts/truetype/firacode/FiraCode-Bold.ttf");
  FT_Library ft;
  FT_Face face;
  std::array<Character, 128> characters;
};

struct FontRenderer {
  std::unique_ptr<Shader> shader;
  GLuint vao, vbo;
  FontRenderer(const char *vertPath, const char *fragPath);
  auto getTextSize(Font &font, const std::string &text, float scale) -> glm::vec2;
  auto renderText(Font &font, const std::string &text, float x, float y,
                  float scale, const glm::vec3 &color,
                  const std::unique_ptr<Camera> &camera) -> void;
};
