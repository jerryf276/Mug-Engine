#include "imgui.h"
//#include "imgui_impl_glfw.h"
//#include "imgui_impl_opengl3.h"
#include "rlImGui.h"
#include "raylib.h"

int main(void)
{
    InitWindow(1280, 720, "raylib [core] example - basic window");
    SetTargetFPS(60);
   // IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//IMGuiIO& io = ImGui::GetIO(); (void)io;
    //ImGui::StyleColorsDark();
	//ImGui_ImplGlfw_InitForOpenGL(window, true);
	//ImGui_ImplOpenGL3_Init("#version 330");

	rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 200, 300, 40, BLACK);
        rlImGuiBegin();
        ImGui::Begin("Debug", NULL);
		ImGui::Text("Hello, world!");
		ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();

    return 0;
}