#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
class RenderSystem
{
public:
	void initWindow(int screenWidth, int screenHeight, const char* title);
	void closeWindow();
	void beginDrawing();
	void endDrawing();
	void clearBackground(Color color);
	void drawText(const char* text, int posX, int posY, int fontSize, Color color);
	void drawTexture(Texture2D texture, int posX, int posY, Color color);
	void setTargetFPS(int fps);
	float getFrameTime();
	double getTime();
	int getFPS();
	//void setExitKey(int key);
	bool windowShouldClose();
	void setWindowSize(int width, int height);
	void setWindowPosition(int x, int y);
	void setWindowTitle(const char* title);
	void toggleFullscreen();
	void toggleBorderless();
	void setWindowIcon(Image image);
	int getMonitorRefreshRate(int monitor);
	int getMonitorScreenWidth(int monitor);
	int getMonitorScreenHeight(int monitor);
	int getScreenWidth();
	int getScreenHeight();
	int getMonitorCount();


	void render(GameObject * gameObject);




	
//	void toggleResizable();
	//void toggleMinimized();
	//void toggleMaximized();
	//void toggleVSync();
	//void toggleShowCursor();
	//void toggleLockCursor();
	//void setClipboardText(const char* text);
	//const char* getClipboardText();
	//void takeScreenshot(const char* fileName);
	//void setMasterVolume(float volume);

private:

protected:

};

