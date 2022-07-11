default:
	g++ main.cpp ~/gitprojects/personal/glad/src/glad.c -o main -Wall -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lXcursor