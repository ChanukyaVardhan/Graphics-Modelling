/*
  A program which opens a window and draws the "color cube."

  Use the arrow keys and PgUp,PgDn, 
  keys to make the cube move.

  Written by - 
               Parag Chaudhuri
*/
#ifndef _COLORCUBE_HPP_
#define _COLORCUBE_HPP_

// Defining the ESCAPE Key Code
#define ESCAPE 27
// Defining the DELETE Key Code
#define DELETE 127

#include "gl_framework.hpp"
#include "shader_util.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// Translation Parameters
GLfloat xpos[10]={0.0},ypos[10]={0.0},zpos[10]={0.0};
// Rotation Parameters
GLfloat xrot[10]={0.0},yrot[10]={0.0},zrot[10]={0.0};

// Camera position and rotation Parameters
GLfloat c_xpos = 0.0, c_ypos = 0.0, c_zpos = 10.0; // To account for rotation problems
GLfloat c_up_x = 0.0, c_up_y = 1.0, c_up_z = 0.0;
GLfloat c_xrot=0.0,c_yrot=0.0,c_zrot=0.0;
//Running variable to toggle culling on/off
bool enable_culling=true;
//Running variable to toggle wireframe/solid modelling
bool solid=true;
//Enable/Disable perspective view
bool enable_perspective=false;

glm::vec4 clck_pts[10000];
glm::vec4 pts_clrs[10000];
int no_points = 0;
char current_mode = 'M'; // default is Modeling(M). Can take values 'M' or 'I'
glm::vec4 current_color(0.5f, 0.5f, 0.5f, 1.0f);
GLfloat current_z_plane = 0.0f;
GLfloat max_z_plane = 0.0f + c_zpos;
int num_objects = 0;

#endif
