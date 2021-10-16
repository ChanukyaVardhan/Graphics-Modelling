#include "gl_framework.hpp"

extern GLfloat xrot[10],yrot[10],zrot[10],c_xrot,c_yrot,c_zrot;
extern GLfloat xpos[10],ypos[10],zpos[10];
extern GLfloat c_xpos, c_ypos, c_zpos;
extern bool enable_perspective;
extern glm::mat4 view_matrix;
extern glm::vec4 clck_pts[10000];
extern glm::vec4 pts_clrs[10000];
extern int no_points;
extern char current_mode;
extern glm::vec4 current_color;
extern GLfloat current_z_plane, max_z_plane;

extern void create_objects(int object_index);
extern glm::vec4 centroid_object(int points);
extern int num_objects;
extern int number_points_object[10];
extern glm::vec4 centroid_each_object[10];

namespace csX75
{
  //! Initialize GL State
  void initGL(void)
  {
    //Set framebuffer clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //Set depth buffer furthest depth
    glClearDepth(1.0);
    //Set depth test to less-than
    glDepthFunc(GL_LESS);
    //Enable depth testing
    glEnable(GL_DEPTH_TEST);
  }
  
  //!GLFW Error Callback
  void error_callback(int error, const char* description)
  {
    std::cerr<<description<<std::endl;
  }
  
  //!GLFW framebuffer resize callback
  void framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    //!Resize the viewport to fit the window size - draw to entire window
    glViewport(0, 0, width, height);
  }
  
  //!GLFW keyboard callback
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    //!Close the window if the ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        yrot[i] -= 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        yrot[num_objects] -= 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        yrot[i] += 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        yrot[num_objects] += 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_UP && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        xrot[i] -= 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        xrot[num_objects] -= 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        xrot[i] += 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        xrot[num_objects] += 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_PAGE_UP && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        zrot[i] -= 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        zrot[num_objects] -= 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_PAGE_DOWN && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        zrot[i] += 5.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        zrot[num_objects] += 5.0;
      }
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
    }
    else if (key == GLFW_KEY_R && action == GLFW_PRESS && current_mode == 'I')
    {
      centroid_each_object[num_objects] = centroid_object(number_points_object[num_objects]);
      glm::vec4 centroid;
      for(int i=0; i<num_objects; i++)
      {
        centroid = centroid_each_object[i];

        xpos[i] = -centroid.x;
        ypos[i] = -centroid.y;
        zpos[i] = -centroid.z;
      }
      if(number_points_object[num_objects] > 2)
      {
        centroid = centroid_each_object[num_objects];

        xpos[num_objects] = -centroid.x;
        ypos[num_objects] = -centroid.y;
        zpos[num_objects] = -centroid.z;
      }
    }
    else if (key == GLFW_KEY_W  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        ypos[i] += 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        ypos[num_objects] += 0.1;
      }
    }
    else if (key == GLFW_KEY_S  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        ypos[i] -= 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        ypos[num_objects] -= 0.1;
      }
    }
    else if (key == GLFW_KEY_A  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        xpos[i] += 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        xpos[num_objects] += 0.1;
      }
    }
    else if (key == GLFW_KEY_D  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        xpos[i] -= 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        xpos[num_objects] -= 0.1;
      }
    }
    else if (key == GLFW_KEY_Z  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        zpos[i] += 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        zpos[num_objects] += 0.1;
      }
    }
    else if (key == GLFW_KEY_X  && action == GLFW_PRESS && current_mode == 'I')
    {
      for(int i=0; i<num_objects; i++)
      {
        zpos[i] -= 0.1;
      }
      if(number_points_object[num_objects] > 2)
      {
        zpos[num_objects] -= 0.1;
      }
    }
    else if (key == GLFW_KEY_F  && action == GLFW_PRESS && current_mode == 'M')
    {
      // for setting the z co-ordinate of the point selected
      std::cout<<"Current z value of the plane is "<<current_z_plane<<std::endl;
      std::cout<<"Enter the new z value in order to move the plane"<<std::endl;
      float z_val;
      std::cin>>z_val;
      current_z_plane = z_val;
      max_z_plane = std::max(current_z_plane + 10.0f, c_zpos);
      c_zpos = max_z_plane;
      std::cout<<"Updated z value of the plane is "<<current_z_plane<<std::endl;
    }
    else if (key == GLFW_KEY_M  && action == GLFW_PRESS)
    {
      current_mode = 'M';
      std::cout<<"Current Mode : Modelling Mode"<<std::endl;
    }
    else if (key == GLFW_KEY_I  && action == GLFW_PRESS)
    {
      current_mode = 'I';
      std::cout<<"Current Mode : Inspection Mode"<<std::endl;
    }
    else if (key == GLFW_KEY_C  && action == GLFW_PRESS) // for color
    {
      std::cout<<"Current RGB color values are "<<current_color.x<<" "<<current_color.y<<" "<<current_color.z<<" respectively"<<std::endl;
      float r,g,b;
      std::cout<<"Enter the new RGB values"<<std::endl;
      std::cin>>r>>g>>b;
      current_color.x = r;
      current_color.y = g;
      current_color.z = b;
      std::cout<<"Updated RGB color values are "<<current_color.x<<" "<<current_color.y<<" "<<current_color.z<<" respectively"<<std::endl;
    }
    else if (key == GLFW_KEY_K  && action == GLFW_PRESS)
    {
      std::cout<<"Enter the file name for storing the data"<<std::endl;
      std::string file_name;
      std::cin>>file_name;

      std::ofstream file_ptr;
      // file_ptr.open((file_name + ".raw").c_str());
      file_ptr.open((file_name).c_str());
      for(int i=0; i<no_points; i++)
      {
        file_ptr<<clck_pts[i].x<<","<<clck_pts[i].y<<","<<clck_pts[i].z<<","<<pts_clrs[i].x<<","<<pts_clrs[i].y<<","<<pts_clrs[i].z<<std::endl;
      }
      file_ptr.close();

      // creating the object
      number_points_object[num_objects] = no_points;
      // centroid_each_object[num_objects] = centroid_object(no_points);
      create_objects(num_objects);
      // num_objects++;

      // no_points = 0; // Object is formed. Ready for a new object
    }
    else if (key == GLFW_KEY_L  && action == GLFW_PRESS)
    {
      std::cout<<"Enter the file name to load the data"<<std::endl;
      std::string file_name, line;
      std::cin>>file_name;

      // std::ifstream file_ptr((file_name + ".raw").c_str());
      std::ifstream file_ptr((file_name).c_str());
      if(file_ptr.is_open())
      {
        float x, y, z, r, g, b;
        // no_points = 0; // Setting the index to array as 0 to clear the array of points

        glm::mat4 translation_matrix = glm::translate(glm::mat4(), glm::vec3(xpos[num_objects],ypos[num_objects],zpos[num_objects]));
        glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(xrot[num_objects]), glm::vec3(1.0f,0.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(yrot[num_objects]), glm::vec3(0.0f,1.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(zrot[num_objects]), glm::vec3(0.0f,0.0f,1.0f));

        glm::mat4 orig_trans_matrix = glm::translate(glm::mat4(), glm::vec3(-centroid_each_object[num_objects].x,-centroid_each_object[num_objects].y,-centroid_each_object[num_objects].z));
        glm::mat4 centroid_trans_matrix = glm::translate(glm::mat4(), glm::vec3(centroid_each_object[num_objects].x,centroid_each_object[num_objects].y,centroid_each_object[num_objects].z));

        glm::mat4 model_matrix = translation_matrix*centroid_trans_matrix*rotation_matrix*orig_trans_matrix;

        glm::mat4 inverse_transform = glm::inverse(model_matrix);

        while(getline(file_ptr, line, ','))
        {
          x = strtof(line.c_str(), NULL);
          getline(file_ptr, line, ',');

          y = strtof(line.c_str(), NULL);
          getline(file_ptr, line, ',');

          z = strtof(line.c_str(), NULL);
          getline(file_ptr, line, ',');

          r = strtof(line.c_str(), NULL);
          getline(file_ptr, line, ',');

          g = strtof(line.c_str(), NULL);
          getline(file_ptr, line);

          b = strtof(line.c_str(), NULL);

          clck_pts[no_points] = inverse_transform*glm::vec4(x, y, z, 1.0f);
          // clck_pts[no_points] = glm::vec4(x, y, z, 1.0f);
          pts_clrs[no_points] = glm::vec4(r, g, b, 1.0f);
          no_points++;
        }

        // creating the object
        number_points_object[num_objects] = no_points;
        // centroid_each_object[num_objects] = centroid_object(no_points);
        create_objects(num_objects);
        // num_objects++;

        // no_points = 0; // Object is formed. Ready for a new object
      }
      else
      {
        std::cout<<"Unable to open the specified file"<<std::endl;
      }
    }
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {
      centroid_each_object[num_objects] = centroid_object(no_points);
      std::cout<<"Switched to a new model"<<std::endl;
      no_points = 0;
      num_objects++;
    }
    else if (key == GLFW_KEY_O && action == GLFW_PRESS)
    {
      for(int i=0; i<num_objects; i++)
      {
        xrot[i] = 0.0;
        yrot[i] = 0.0;
        zrot[i] = 0.0;
      }
      if(number_points_object[num_objects] > 2)
      {
        xrot[num_objects] = 0.0;
        yrot[num_objects] = 0.0;
        zrot[num_objects] = 0.0;
      }
    }
  }

  //!GLFW mouse callback
  void mouse_callback(GLFWwindow* window, int button, int action, int mods)
  {
    double x, y;
    if(button == GLFW_MOUSE_BUTTON_LEFT && current_mode == 'M')
    {
      if(action == GLFW_RELEASE && mods != GLFW_MOD_SHIFT)
      {
        // using glm
        glfwGetCursorPos(window, &x, &y);
        GLfloat winX, winY, winZ;
        GLint viewport[4];

        glGetIntegerv( GL_VIEWPORT, viewport );
        winX = (float)x;
        winY = (float)viewport[3] - (float)y;
        // glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
        winZ = (float)0;

        // should we use this or any other
        glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f,0.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(0.0f), glm::vec3(0.0f,1.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(0.0f), glm::vec3(0.0f,0.0f,1.0f));
        glm::vec3 world_pos = glm::unProject(glm::vec3(winX, winY, winZ), rotation_matrix, view_matrix, glm::vec4(0.0f, 0.0f, (float)viewport[2], (float)viewport[3]));
        
        world_pos.z = current_z_plane; // the z co-ordinate is exactly the current_z_plane value


        glm::mat4 translation_matrix = glm::translate(glm::mat4(), glm::vec3(xpos[num_objects],ypos[num_objects],zpos[num_objects]));
        rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(xrot[num_objects]), glm::vec3(1.0f,0.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(yrot[num_objects]), glm::vec3(0.0f,1.0f,0.0f));
        rotation_matrix = glm::rotate(rotation_matrix, glm::radians(zrot[num_objects]), glm::vec3(0.0f,0.0f,1.0f));

        glm::mat4 orig_trans_matrix = glm::translate(glm::mat4(), glm::vec3(-centroid_each_object[num_objects].x,-centroid_each_object[num_objects].y,-centroid_each_object[num_objects].z));
        glm::mat4 centroid_trans_matrix = glm::translate(glm::mat4(), glm::vec3(centroid_each_object[num_objects].x,centroid_each_object[num_objects].y,centroid_each_object[num_objects].z));

        glm::mat4 model_matrix = translation_matrix*centroid_trans_matrix*rotation_matrix*orig_trans_matrix;

        glm::mat4 inverse_transform = glm::inverse(model_matrix);

        // clck_pts[no_points] = glm::vec4(world_pos, 1.0f);
        clck_pts[no_points] = inverse_transform*glm::vec4(world_pos, 1.0f);
        pts_clrs[no_points] = glm::vec4(current_color);
        no_points++;

        number_points_object[num_objects] = no_points;
        // centroid_each_object[num_objects] = centroid_object(no_points);
        create_objects(num_objects); // object
      }
      else if(action == GLFW_PRESS && mods == GLFW_MOD_SHIFT)
      {
        if(no_points != 0)
        {
          no_points--;

          number_points_object[num_objects] = no_points;
          // centroid_each_object[num_objects] = centroid_object(no_points);
          create_objects(num_objects);
        }
        else
        {
          std::cout<<"Currently there are no points stored. Please first add some points for the object"<<std::endl;
        }
      }
    }
  }
};