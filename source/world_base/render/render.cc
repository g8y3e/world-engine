#include "render.h"

#include <string>

#include <third_party/sdl2/SDL.h>
#include <world_base/debug/log.h>
#include <world_base/helper/define.h>

#ifdef WINDOWS_OS
#include <Windows.h>
#include <third_party/sdl2/SDL_syswm.h>
#endif

namespace world_base {
    void Render::init() {
        std::string name = "Test game";
        std::string init_message = "Init game '";
        init_message.append(name).append("'!");
        debug::LOGCONFIG(init_message);


        // init screen 
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::string error_msg = "Unable to initialize SDL: ";
            debug::LOGERROR(error_msg.append(SDL_GetError()));
            throw std::exception(error_msg.c_str());
        }

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 0);
        SDL_GL_SetAttribute(SDL_GL_STEREO, 0);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 0);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 0);
        SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);


        auto width = 1024;
        auto height = 768;

        SDL_Window *window_;

        #if defined(MOBILE_OS)
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);

            window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                0, 0, SDL_WINDOW_OPENGL);
        #else  
            window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       width, height, SDL_WINDOW_OPENGL);

                // load icon
            #ifdef WINDOWS_OS
                HINSTANCE handle = ::GetModuleHandle(nullptr);
                HICON icon = ::LoadIcon(handle, MAKEINTRESOURCE(102));
                if (icon != nullptr) {
                    SDL_SysWMinfo wminfo;
                    SDL_VERSION(&wminfo.version);
                    if (SDL_GetWindowWMInfo(window_, &wminfo) == 1) {
                        HWND hwnd = wminfo.info.win.window;
                        ::SetClassLong(hwnd, GCL_HICON, reinterpret_cast<LONG>(icon));
                    }
                }
            #endif
        #endif

        if (window_ == nullptr) {
            std::string error_msg = "Error: can't create SDL window: ";
            debug::LOGERROR(error_msg.append(SDL_GetError()));
            throw std::exception(error_msg.c_str());
        }
    }
}