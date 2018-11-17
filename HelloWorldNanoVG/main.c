#include <stdio.h>
#define GLFW_INCLUDE_ES2
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "nanovg.h"
#define NANOVG_GLES2_IMPLEMENTATION
#include "nanovg_gl.h"
#include "nanovg_gl_utils.h"

#include <emscripten.h>

void errorcb(int error, const char* desc)
{
  printf("GLFW error %d: %s\n", error, desc);
}

GLFWwindow* window;
NVGcontext* vg = NULL;
double prevt = 0;

void render() {
  double t, dt;
  int winWidth, winHeight;
  int fbWidth, fbHeight;
  float pxRatio;

  t = glfwGetTime();
  dt = t - prevt;
  prevt = t;

  glfwGetWindowSize(window, &winWidth, &winHeight);
  glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
  // Calculate pixel ration for hi-dpi devices.
  pxRatio = (float)fbWidth / (float)winWidth;

  // Update and render
  glViewport(0, 0, fbWidth, fbHeight);
  glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);

  nvgBeginFrame(vg, winWidth, winHeight, pxRatio);
  
  nvgFillColor(vg, nvgRGBf(1.f, 0.f, 0.f));
  nvgCircle(vg, winWidth/2., winHeight/2., 100);
  nvgFill(vg);

  nvgEndFrame(vg);

  glEnable(GL_DEPTH_TEST);

  glfwSwapBuffers(window);
  glfwPollEvents();
}

int main()
{
  if (!glfwInit()) {
    printf("Failed to init GLFW.");
    return -1;
  }

  glfwSetErrorCallback(errorcb);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(1000, 600, "NanoVG", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  vg = nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
  if (vg == NULL) {
    printf("Could not init nanovg.\n");
    return -1;
  }

  glfwSwapInterval(0);

  glfwSetTime(0);
  prevt = glfwGetTime();

  emscripten_set_main_loop(render, 0, 1);

  nvgDeleteGLES2(vg);

  glfwTerminate();
  return 0;
}
