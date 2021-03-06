#ifndef __INC_GAME_GL_H__
#define __INC_GAME_GL_H__

#define GL_GLEXT_PROTOTYPES
#define GLM_FORCE_RADIANS
#include <SDL.h> 
#include <SDL_opengl.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>
#include <cstdlib>

#define GAME_GL_MAX_MESH 32
#define GAME_GL_MAX_TEXTURES 32
class c_game_gl
{
public:
    c_game_gl(int width, int height);
    ~c_game_gl();
    int init(void);
    void draw(class c_game_level *level);
    void draw_start(class c_game_level *level);
    void draw_mesh(float x, float y, float z, int mesh, int texture);
    void draw_complete(void);

    float aspect_ratio;
    glm::mat4 V;
    class c_shader_game *game_shader;
    class c_shader_ortho_flat *flat_shader;
    GLuint VertexArrayID;
    GLuint M_MatrixID;

    float FOV;
    float head_yaw, head_pitch;
    int use_ortho_flat;
    glm::vec3 body_pos;
    glm::vec3 body_facing; // z is probably 0

    class c_mesh *meshes[GAME_GL_MAX_MESH];
    class c_texture *textures[GAME_GL_MAX_TEXTURES];
};

#endif // __INC_GAME_GL_H__
