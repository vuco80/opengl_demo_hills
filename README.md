# opengl_demo_hills
A simple c++/opengl program in which you can WASD your way through a hills heightmap.
Inspirational and/or *educational* purpose only.

DEPENDENCIES:
----------------------------------------------
OpenGL
SDL2
Glew
glm

You need SDL2 and glew dev packet properly installed and their path configured in your build environment.
For glm simply add include path, like this (glm 0.9.9.8 in this example): {path_to_your_glm_dir}\glm-0.9.9.8\glm\glm

HOW TO BUILD:
----------------------------------------------
Repository doesn't include a build system, only plain source code and resources files.
Whatever you use simply add all the files you find in src, link with SDL2 and glew and should be ok.
