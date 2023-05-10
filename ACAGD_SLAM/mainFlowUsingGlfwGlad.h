#pragma once
#include <GLFW/glfw3.h>
#ifndef M_PI
#define M_PI       3.14159265358979323846   // pi
#endif
class MainFlowUsingGlfwGlad {
    bool isPressedLButton = false;
    double xPressedLast, yPressedLast;
    double xPressedInstant, yPressedInstant;
protected:
    double angleX = 0, angleY = 0; // openGL rotate x rotate y
private:
    int cxwin = 500, cywin = 500; 
public:
	GLFWwindow* window;
    static MainFlowUsingGlfwGlad& s();
protected:
    virtual bool mainloopPre();
    virtual void mainloopAfter();
public:
    virtual void mainLoop();
private:
    void key_callback(GLFWwindow* window, int keycode, int scancode, int action, int mods);
    static void key_callbacks(GLFWwindow* window, int keycode, int scancode, int action, int mods);
private:
    void mouse_callback(GLFWwindow* window, int button, int action, int mods);
    void cursor_callback(GLFWwindow* window, double xpos, double ypos);
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callbacks(GLFWwindow* window, int button, int action, int mods);
    static void cursor_callbacks(GLFWwindow* window, double xpos, double ypos);
    static void framebuffer_size_callbacks(GLFWwindow* window, int width, int height);
protected:
    void guiMainMenu();
    void glDrawXYZAxis();// x-y-z ¶b
};