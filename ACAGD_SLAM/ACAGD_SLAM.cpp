#include "main_setting.hpp"

#include "EasyIO.hpp"
#include "samples.hpp"
#include <iostream>

#include "ch5_StereoFlow.h"
ch5_StereoFlow flowStereo;

int main()
{
    // sample_opencv();

    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress)) {
        printf("Failed to load glad.");
        return -1; // RES_ERROR_LOAD_GLAD;
    }

    flowStereo.main();
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        flowStereo.gldraw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
