#include <stdio.h>
#include <math.h>
#include <emscripten.h>
#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

GLFWwindow* g_window;

void render();
void error_callback(int error, const char* description);

void render() {
  static float g = 0.;
  glClearColor(g, g, g, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  g += 0.01;
  g = fmod(g, 1.);
}

void error_callback(int error, const char* description) {
  fprintf(stderr, "Error %d: %s\n", error, description);
}

int main() {
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit()) {
    printf("Could not create window.\n");
    return -1;
  }
  
  glfwWindowHint(GLFW_RESIZABLE , 1);
  g_window = glfwCreateWindow(600, 450, "Hello GLFW", NULL, NULL);
  
  if (!g_window) {
    printf("Could not create window\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(g_window);
  
  emscripten_set_main_loop(render, 0, 1);
  
  glfwTerminate();
  
  return 0;
}
