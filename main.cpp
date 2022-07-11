
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /*Declaring OpenGL v3.3 will be used*/        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "HelloWorld", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout<<"Failed to create window"<<std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*Initializing glad*/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }  

    /*adjusting viewpoint, and resizing it with window*/
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Loop until the user closes the window. Each loop represents one frame.*/
    while (!glfwWindowShouldClose(window))
    {        
        /*check if escape buton has been pressed, and close window if so*/
        void processInput(GLFWwindow *window);
 
        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // sets the clear colour
        glClear(GL_COLOR_BUFFER_BIT); // clears the colour of the previous frame
         
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

//function checks if the escape button is pressed and closes window if so.
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        std::cout<<"You pressed ESCAPE"<<std::endl;
        glfwSetWindowShouldClose(window, true);
    }    
}