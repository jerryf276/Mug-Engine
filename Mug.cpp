#include "imgui.h"
#include "rlImGui.h"
#include "raylib.h"
#include "Game.h"


int mainold(void)
{
    int screenWidth = 1280;
    int screenHeight = 720;
 

    InitWindow(screenWidth, screenHeight, "Enginoaly");
    InitAudioDevice();
    //Image testImage = LoadImage("Game/Assets/Images/Penguin-images-2/Animations/penguin_jump01.png");
   // Texture2D testTexture = LoadTextureFromImage(testImage);
	Texture2D testTexture = LoadTexture("Game/Assets/Images/Penguin-images-2/Animations/penguin_jump01.png");

	Sound sound = LoadSound("Game/Assets/Audio/coin.wav");
    
    //UnloadImage(testImage);
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
        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(sound);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 200, 300, 40, BLACK);
        
        DrawTexture(testTexture, screenWidth / 2 - testTexture.width / 2, screenHeight / 2 - testTexture.height / 2, WHITE);
        rlImGuiBegin();
        ImGui::Begin("Debug", NULL);
		ImGui::Text("Hello, world!");
		ImGui::Text("FPS: %d", GetFPS());
		ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    UnloadTexture(testTexture);

    
    CloseWindow();

    return 0;
}