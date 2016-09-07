#ifndef __INC_OBJECT_H__
#define __INC_OBJECT_H__

#include "includes.h"
#include "mesh.h"
#include "material.h"
#include "transform.h"

class Object{
public:
    Object(glm::vec3 *pos,glm::vec3 *rot,glm::vec3 *scale=NULL,Mesh *m=NULL,Material *material=NULL,const char* _type="",std::map<std::string,std::string> *_data=NULL);
    void Draw(glm::mat4 *VP);
    void Draw(glm::mat4 *VP,Material *overrideMat);
    Transform *t;
    Mesh *mesh;
    Material *mat;
    const char *type;
    std::map<std::string,std::string> *data;
};

class Camera : public Object{
public:
    Camera(glm::vec3 *pos,glm::vec3 *rot,glm::vec3 *scale,const char* _type="Camera",std::map<std::string,std::string> *_data=NULL);
    glm::mat4 projectionMatrix,VP;
    glm::mat4 CalculateVP();
    void SetAspectRatio(float aspectRatio);
    float FOV,nearClip,farClip;
};

class ShadowLight : public Object{
public:
    ShadowLight(glm::vec3 *pos,glm::vec3 *rot,const char* _type="SLight",std::map<std::string,std::string> *_data=NULL);
    virtual void FindVP();
    void SaveTexture();
    void InitShadowRender();
    glm::mat4 VP;
    GLuint depthMapFBO,depthMapTex;
    uint resX,resY;
    glm::vec3 color;
};
    
#endif
