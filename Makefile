CC=g++

OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
# LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
LIBS = -lXi -lGLEW -lGLU -lGL -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama -lXxf86vm -lXcursor -lXext -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp
# LIBS = -lGLEW -lGL -lglfw3 -ldl -lXrandr -lXinerama -lXxf86vm -lXcursor -lX11 -lpthread
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include -I./

BIN=assign01
SRCS=Assignment1.cpp gl_framework.cpp shader_util.cpp 
INCLUDES=gl_framework.hpp shader_util.hpp Assignment1.hpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)