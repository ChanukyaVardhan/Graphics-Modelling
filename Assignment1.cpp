/*
  CSX75 Assignment 1

  Taken from tutorials by Parag Chaudhuri, 2015
*/


#include "Assignment1.hpp"

GLuint shaderProgram;
GLuint vbo[10], vao[10];
int number_points_object[10];
glm::vec4 centroid_each_object[10];

glm::mat4 rotation_matrix;
glm::mat4 projection_matrix;
glm::mat4 c_rotation_matrix;
glm::mat4 lookat_matrix;

//translation matrix
glm::mat4 translation_matrix;
glm::mat4 orig_trans_matrix;
glm::mat4 centroid_trans_matrix;

glm::mat4 model_matrix;
glm::mat4 view_matrix;

glm::mat4 modelview_matrix;
GLuint uModelViewMatrix;

double area_triangle(glm::vec4 a, glm::vec4 b, glm::vec4 c)
{
  double abx = b.x - a.x;
  double aby = b.y - a.y;
  double abz = b.z - a.z;

  double acx = c.x - a.x;
  double acy = c.y - a.y;
  double acz = c.z - a.z;

  double cross_product_x = aby*acz - acy*abz;
  double cross_product_y = abx*acz - acx*abz;
  double cross_product_z = abx*acy - acx*aby;

  double area = sqrt(cross_product_x*cross_product_x + cross_product_y*cross_product_y + cross_product_z*cross_product_z) / 2;
  return area;
}

glm::vec4 centroid_object(int points) // sigma(AiCi)/sigma(Ai) 
{
  double centroid_x = 0.0, centroid_y = 0.0, centroid_z = 0.0;

  double area_total=0;
  for (int i = 0; i < points - 2; i+=3) 
  {
    glm::vec4 a = clck_pts[i], b = clck_pts[i+1], c = clck_pts[i+2];
    double area = area_triangle(a, b, c);

    double centroid_triangle_x = (a.x + b.x + c.x) /3;
    double centroid_triangle_y = (a.y + b.y + c.y) /3;
    double centroid_triangle_z = (a.z + b.z + c.z) /3;

    centroid_x = (centroid_x*area_total + centroid_triangle_x*area) / (area_total+area);
    centroid_y = (centroid_y*area_total + centroid_triangle_y*area) / (area_total+area);
    centroid_z = (centroid_z*area_total + centroid_triangle_z*area) / (area_total+area);
    area_total = area_total + area;
  }

  glm::vec4 centroid_final(centroid_x, centroid_y, centroid_z, 1.0f);
  return centroid_final;
}

void init_buffers(void)
{
  // Load shaders and use the resulting shader program
  std::string vertex_shader_file("vshader.glsl");
  std::string fragment_shader_file("fshader.glsl");

  std::vector<GLuint> shaderList;
  shaderList.push_back(csX75::LoadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
  shaderList.push_back(csX75::LoadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

  shaderProgram = csX75::CreateProgramGL(shaderList);
  glUseProgram( shaderProgram );

  uModelViewMatrix = glGetUniformLocation( shaderProgram, "uModelViewMatrix");

  glEnable(GL_PROGRAM_POINT_SIZE);

  //Ask GL for Vertex Attribute Objects (vao))
  glGenVertexArrays (10, vao);
  //Ask GL for Vertex Buffer Object (vbo)
  glGenBuffers (10, vbo);

  return;
}

void create_objects(int object_index)
{
  // binding here
  glBindVertexArray (vao[object_index]);
  glBindBuffer (GL_ARRAY_BUFFER, vbo[object_index]);

  //Copy the points into the current buffer
  glBufferData (GL_ARRAY_BUFFER, (sizeof(clck_pts[0]))*(number_points_object[object_index] * 2), NULL, GL_STATIC_DRAW);
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(clck_pts[0])*number_points_object[object_index], clck_pts );
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(clck_pts[0])*number_points_object[object_index], sizeof(pts_clrs[0])*number_points_object[object_index], pts_clrs );
  
  // getting the attributes from the shader program
  GLuint vPosition = glGetAttribLocation( shaderProgram, "vPosition" );
  GLuint vColor = glGetAttribLocation( shaderProgram, "vColor" );

  // set up vertex array
  glEnableVertexAttribArray( vPosition );
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
  
  glEnableVertexAttribArray( vColor );
  glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(clck_pts[0])*number_points_object[object_index]) );
}

void renderGL(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Creating the lookat and the up vectors for the camera
  c_rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(c_xrot), glm::vec3(1.0f,0.0f,0.0f));
  c_rotation_matrix = glm::rotate(c_rotation_matrix, glm::radians(c_yrot), glm::vec3(0.0f,1.0f,0.0f));
  c_rotation_matrix = glm::rotate(c_rotation_matrix, glm::radians(c_zrot), glm::vec3(0.0f,0.0f,1.0f));

  glm::vec4 c_pos = glm::vec4(c_xpos,c_ypos,c_zpos, 1.0)*c_rotation_matrix;
  glm::vec4 c_up = glm::vec4(c_up_x,c_up_y,c_up_z, 1.0)*c_rotation_matrix;
  //Creating the lookat matrix
  lookat_matrix = glm::lookAt(glm::vec3(c_pos),glm::vec3(0.0),glm::vec3(c_up));

  //creating the projection matrix
  if(enable_perspective)
    projection_matrix = glm::frustum(-1.0, 1.0, -1.0, 1.0, 1.0, 5.0);
    //projection_matrix = glm::perspective(glm::radians(90.0),1.0,0.1,5.0);
  else
    projection_matrix = glm::ortho(-2.0, 2.0, -2.0, 2.0, 2.0, 100.0);

  view_matrix = projection_matrix*lookat_matrix;

  for(int i=0; i<=num_objects; i++)
  {
    rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(xrot[i]), glm::vec3(1.0f,0.0f,0.0f));
    rotation_matrix = glm::rotate(rotation_matrix, glm::radians(yrot[i]), glm::vec3(0.0f,1.0f,0.0f));
    rotation_matrix = glm::rotate(rotation_matrix, glm::radians(zrot[i]), glm::vec3(0.0f,0.0f,1.0f));

    orig_trans_matrix = glm::translate(glm::mat4(), glm::vec3(-centroid_each_object[i].x,-centroid_each_object[i].y,-centroid_each_object[i].z));
    centroid_trans_matrix = glm::translate(glm::mat4(), glm::vec3(centroid_each_object[i].x,centroid_each_object[i].y,centroid_each_object[i].z));

    translation_matrix = glm::translate(glm::mat4(), glm::vec3(xpos[i],ypos[i],zpos[i]));

    model_matrix = translation_matrix*centroid_trans_matrix*rotation_matrix*orig_trans_matrix;

    modelview_matrix = view_matrix*model_matrix;
    glUniformMatrix4fv(uModelViewMatrix, 1, GL_FALSE, glm::value_ptr(modelview_matrix));
    glBindVertexArray (vao[i]);
    glDrawArrays(GL_TRIANGLES, 0, number_points_object[i]);
  }

  glUniformMatrix4fv(uModelViewMatrix, 1, GL_FALSE, glm::value_ptr(view_matrix * model_matrix));
  glBindVertexArray (vao[num_objects]);
  glDrawArrays(GL_POINTS, 0, number_points_object[num_objects]);
}

int main(int argc, char** argv)
{
  //! The pointer to the GLFW window
  GLFWwindow* window;

  //! Setting up the GLFW Error callback
  glfwSetErrorCallback(csX75::error_callback);

  //! Initialize GLFW
  if (!glfwInit())
    return -1;

  //We want OpenGL 4.0
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //This is for MacOSX - can be omitted otherwise
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
  //We don't want the old OpenGL 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

  //! Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(512, 512, "CS475 Assignment 1", NULL, NULL);
  if (!window)
    {
      glfwTerminate();
      return -1;
    }
  
  //! Make the window's context current 
  glfwMakeContextCurrent(window);

  //Initialize GLEW
  //Turn this on to get Shader based OpenGL
  glewExperimental = GL_TRUE;
  GLenum err = glewInit();
  if (GLEW_OK != err)
    {
      //Problem: glewInit failed, something is seriously wrong.
      std::cerr<<"GLEW Init Failed : %s"<<std::endl;
    }

  //Print and see what context got enabled
  std::cout<<"Vendor: "<<glGetString (GL_VENDOR)<<std::endl;
  std::cout<<"Renderer: "<<glGetString (GL_RENDERER)<<std::endl;
  std::cout<<"Version: "<<glGetString (GL_VERSION)<<std::endl;
  std::cout<<"GLSL Version: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<std::endl;

  //Keyboard Callback
  glfwSetKeyCallback(window, csX75::key_callback);
  //Mouse Callback
  glfwSetMouseButtonCallback(window, csX75::mouse_callback);
  //Framebuffer resize callback
  glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  std::cout<<"Current Mode : Modelling Mode"<<std::endl; // This is to specify the starting mode in terminal

  //Initialize GL state
  csX75::initGL();
  init_buffers();

  // Loop until the user closes the window
  while (glfwWindowShouldClose(window) == 0)
    {
       
      // Render here
      renderGL();

      // Swap front and back buffers
      glfwSwapBuffers(window);
      
      // Poll for and process events
      glfwPollEvents();
    }
  
  glfwTerminate();
  return 0;
}

//-------------------------------------------------------------------------

