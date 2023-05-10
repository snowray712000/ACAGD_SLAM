#include "main_setting.hpp"

#include "EasyIO.hpp"
#include "samples.hpp"
#include <iostream>

#include "ch5_StereoFlow.h"
ch5_StereoFlow flowStereo;
#include "mainFlowUsingGlfwGlad.h"
#include "EasyImGui.h"

class MyFlow : public MainFlowUsingGlfwGlad {
protected:
    virtual bool mainloopPre() {
        auto result = MainFlowUsingGlfwGlad::mainloopPre();
        
        sample_opencv();
        flowStereo.main();
        return result;
    }
public:
    virtual void mainLoop() {
        mainloopPre();
        while (!glfwWindowShouldClose(window))
        {
            EasyImGUI::callThisBeforeGLClear();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            this->guiMainMenu();
            EasyImGUI::callThisAfterGLClearBeforeSwapBuffer();
            

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(angleX * 180 / M_PI, 1, 0, 0);
            glRotatef(angleY * 180 / M_PI, 0, 1, 0);
            this->glDrawXYZAxis();

            flowStereo.gldraw();
            
            //glColor3ub(255, 255, 255);
            //glBegin(GL_TRIANGLES);
            //glVertex2f(0, 0);
            //glVertex2f(0.5, 0);
            //glVertex2f(0.5, 0.5);
            //glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        mainloopAfter();
    }
}flow;

int main()
{
    flow.mainLoop(); 
    return 0;
}
