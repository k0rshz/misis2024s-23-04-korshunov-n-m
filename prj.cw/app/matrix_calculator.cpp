// ImGui + SDL2
#define SDL_MAIN_HANDLED

#include "matrix/matrix.hpp"
#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl2.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL2/SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif
// fmt
#include <fmt/core.h>



int main(int, char**)
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    if (window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return -1;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("C:/Users/narut/my-project/f/Arial.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    // Устанавливаем этот шрифт как основной для Dear ImGui и русский текст будет отображаться корректно
    io.FontDefault = io.Fonts->Fonts.back();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    // - Our Emscripten build process allows embedding fonts to be accessible at runtime from the "fonts/" folder. See Makefile.emscripten for details.
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    bool done = false;
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    Matrix mat(3, 3);
    double multiplier = 1.0f;
    char userInput[20];
    int degree = 1;
    int r = 0;
    bool showMatrixRank = false;
    double det = 0;
    bool showMatrixDet = false;
    int n = 3;
    int m = 3;

    while (!done)
#endif
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
            if (event.type == SDL_TEXTINPUT && ImGui::GetIO().WantCaptureKeyboard) {
                if (event.text.text[0] == '\b' && strlen(userInput) > 0) {
                    // Удаляем последний символ при нажатии Backspace
                    userInput[strlen(userInput) - 1] = '\0';
                }
                else if (event.text.text[0] >= 32 && event.text.text[0] <= 126 && strlen(userInput) < 19) {
                    // Добавляем символ в пользовательский ввод
                    strncat(userInput, reinterpret_cast<const char*>(&event.text.text), 1);
                }

                // Обновляем значение в активной ячейке
                if (ImGui::IsAnyItemActive()) {
                    int index = strlen(userInput) > 0 ? atoi(userInput) : 0;
                    for (int i = 0; i < mat.rows(); ++i) {
                        for (int j = 0; j < mat.cols(); ++j) {
                            if (ImGui::IsItemActive()) {
                                mat.at(i, j) = static_cast<double>(index);
                            }
                        }
                    }
                }
            }
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImGuiStyle& style = ImGui::GetStyle();
        style.ItemSpacing = ImVec2(0, 12.0f);

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin(u8"Матричный калькулятор", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text(u8"\t\t\t\t\t\t\t\t\t\tМатрица A");               // Display some text (you can use a format strings too)

            const float cellSize = 30.0f; // Размер каждой маленькой ячейки
            ImVec2 windowSize = ImGui::GetWindowSize();
            ImVec2 startPos((windowSize.x - cellSize * 3 - 45) / 2 - 15 - 27 * (mat.cols() - 3), (windowSize.y - cellSize * 3 - 10) / 2 - 60);
            const float inputWidth = 48.5f;
            for (int i = 0; i < mat.rows(); ++i) {
                for (int j = 0; j < mat.cols(); ++j) {

                    ImGui::SetCursorPos(startPos);
                    ImGui::SetNextItemWidth(inputWidth);
                    ImGui::InputDouble(("##cell" + std::to_string(i) + std::to_string(j)).c_str(), &mat.at(i, j), 0, 0, "%f");
         
                    startPos.x += cellSize + 25.0f; // Увеличиваем X координату для следующей ячейки
                }
                startPos.x = (windowSize.x - cellSize * 3 - 45) / 2 - 15 - 27 * (mat.cols() - 3); // Возвращаем X координату в начало строки
                startPos.y += cellSize + 5.0f; // Увеличиваем Y координату для следующей строки
            }
            

            ImGui::Dummy(ImVec2(100.0f, 10.0f));
            ImGui::Dummy(ImVec2(10.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Очистить")) {
                mat.clear();
            }
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(115.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Размер:"))
                mat.resize(n, m);
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(5.0f, 0));
            ImGui::SameLine();
            ImGui::SetNextItemWidth(17);
            ImGui::InputInt("##n", &n, 0, 0, 0);
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(3.0f, 0));
            ImGui::SameLine();
            ImGui::Text(u8"×");
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(3.0f, 0));
            ImGui::SameLine();
            ImGui::SetNextItemWidth(17);
            ImGui::InputInt("##m", &m, 0, 0, 0);


            ImGui::Dummy(ImVec2(10.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Найти ранг")) {
                r = mat.rank();
                showMatrixRank = true;
            }
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(104.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Умножить на"))
                mat.multi(multiplier);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(40.6);
            ImGui::InputDouble("##multi", &multiplier, 0, 0, "%f");

            ImGui::Dummy(ImVec2(10.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Транспонировать"))
                mat.transpose();
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(61.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Возвести в степень"))
                mat.degree(degree);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(23);
            ImGui::InputInt("##degree", &degree, 0, 0, 0);

            ImGui::Dummy(ImVec2(10.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Найти определитель")) {
                det = mat.determinant();
                showMatrixDet = true;
            }
            ImGui::SameLine();
            ImGui::Dummy(ImVec2(38.0f, 0));
            ImGui::SameLine();
            if (ImGui::Button(u8"Найти обратную матрицу")) {
                if (mat.determinant() != 0) {
                    mat.inverse();
                }
                else {
                    void;
                }
            }

            ImGui::End();
        }

        if (showMatrixRank) {
            ImGui::SetNextWindowPos(ImVec2(289, 10), ImGuiCond_Always);
            ImGui::SetNextWindowBgAlpha(0.3f);
            ImGui::Begin("RankInfo", &showMatrixRank, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
            ImGui::Text(u8"Ранг матрицы: %d", r);
            ImGui::End();
        }

        if (showMatrixDet) {
            ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always);
            ImGui::SetNextWindowBgAlpha(0.3f);
            ImGui::SetNextWindowSize(ImVec2(250, 8), ImGuiCond_Always);
            ImGui::Begin("DetInfo", &showMatrixDet, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
            ImGui::Text(u8"Определитель матрицы: %.4f", det);
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}