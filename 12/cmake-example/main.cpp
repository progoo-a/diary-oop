#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include <chrono>
#include <iostream>

namespace
{
void InitOpenGLState(int width, int height)
{
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);

    GLfloat lightPos[] = {2.5f, 5.0f, 5.0f, 1.0f};
    GLfloat lightColor[] = {0.9f, 0.9f, 0.9f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);

    glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
}

void RenderFrame(float angleDeg, int width, int height)
{
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    const float aspect = static_cast<float>(width) / static_cast<float>(height ? height : 1);
    gluPerspective(60.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 1.5, 5.0,
              0.0, 0.5, 0.0,
              0.0, 1.0, 0.0);

    glRotatef(angleDeg, 0.0f, 1.0f, 0.0f);
    glColor3f(0.85f, 0.65f, 0.2f);
    glutSolidTeapot(1.0);
}
} // namespace

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    const int width = 960;
    const int height = 640;

    SDL_Window* window = SDL_CreateWindow(
        "SDL2 OpenGL Teapot",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext)
    {
        std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_GL_SetSwapInterval(1);

    glutInit(&argc, argv); // Initializes freeglut so glutSolidTeapot can be used.
    InitOpenGLState(width, height);

    bool running = true;
    float angle = 0.0f;
    auto lastFrame = std::chrono::steady_clock::now();

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
            else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                glViewport(0, 0, event.window.data1, event.window.data2);
            }
        }

        const auto now = std::chrono::steady_clock::now();
        const std::chrono::duration<float> delta = now - lastFrame;
        lastFrame = now;
        angle += delta.count() * 45.0f;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }

        int currentW, currentH;
        SDL_GetWindowSize(window, &currentW, &currentH);
        RenderFrame(angle, currentW, currentH);
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
