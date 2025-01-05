#include "RenderSystem.h"

void RenderSystem::initWindow(int screenWidth, int screenHeight, const char* title)
{
	InitWindow(screenWidth, screenHeight, title);
}

void RenderSystem::closeWindow()
{
	CloseWindow();
}

void RenderSystem::beginDrawing()
{
	BeginDrawing();
}

void RenderSystem::endDrawing()
{
	EndDrawing();
}

void RenderSystem::clearBackground(Color color)
{
	ClearBackground(color);
}

void RenderSystem::drawText(const char* text, int posX, int posY, int fontSize, Color color)
{
	DrawText(text, posX, posY, fontSize, color);
}

void RenderSystem::drawTexture(Texture2D texture, int posX, int posY, Color color)
{
	DrawTexture(texture, posX, posY, color);
}

void RenderSystem::setTargetFPS(int fps)
{
	SetTargetFPS(fps);
}

float RenderSystem::getFrameTime()
{
	return GetFrameTime();
}

double RenderSystem::getTime()
{
	return GetTime();
}

int RenderSystem::getFPS()
{
	return GetFPS();
}

bool RenderSystem::windowShouldClose()
{
	return WindowShouldClose();
}

void RenderSystem::setWindowSize(int width, int height)
{
	SetWindowSize(width, height);
}

void RenderSystem::setWindowPosition(int x, int y)
{
	SetWindowPosition(x, y);
}

void RenderSystem::setWindowTitle(const char* title)
{
	SetWindowTitle(title);
}

void RenderSystem::toggleFullscreen()
{
	ToggleFullscreen();
}

void RenderSystem::toggleBorderless()
{
	ToggleBorderlessWindowed();
}

void RenderSystem::setWindowIcon(Image image)
{
	SetWindowIcon(image);
}

int RenderSystem::getMonitorRefreshRate(int monitor)
{
	return GetMonitorRefreshRate(monitor);
}

int RenderSystem::getMonitorScreenWidth(int monitor)
{
	return GetMonitorPhysicalWidth(monitor);
}

int RenderSystem::getMonitorScreenHeight(int monitor)
{
	return GetMonitorPhysicalHeight(monitor);
}

int RenderSystem::getScreenWidth()
{
	return GetScreenWidth();
}

int RenderSystem::getScreenHeight()
{
	return GetScreenHeight();
}

int RenderSystem::getMonitorCount()
{
	return GetMonitorCount();
}

void RenderSystem::render(GameObject* gameObject)
{
	auto transform = gameObject->GetComponent<TransformComponent>();
	auto sprite = gameObject->GetComponent<SpriteComponent>();
	if (transform && sprite)
	{
		DrawTexture(sprite->getSprite(), transform->getPosition().x, transform->getPosition().y, WHITE);
	}
	

}

Camera2D * RenderSystem::getCamera2D()
{
	return camera;
}

void RenderSystem::setCamera2D(Camera2D * camera)
{
	this->camera = camera;
}

void RenderSystem::beginDrawingWithCamera2D(Camera2D * camera)
{
	//BeginDrawing();
	BeginMode2D(*camera);
}

void RenderSystem::endDrawingWithCamera2D()
{
	EndMode2D();
	//EndDrawing();
}

//void RenderSystem::toggleMinimized()
//{
//	toggle
//}



//void RenderSystem::setExitKey(int key)
//{
//	SetExitKey(key);
//}
