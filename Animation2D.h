#pragma once
#include "SpriteComponent.h"

struct Frame {
	Rectangle rect;
	float speed = 1.0f;
};

enum class AnimLoopType {
	NoLoop = 0,
	Loop = 1,
	Boomerang = 2
};

class Animation2D
{
public:
	Animation2D();
	~Animation2D();

	void addFrame(Rectangle frameRectangle, float frameSpeed = 1.0f);

	// Add a batch of frames to the animation. Offset is the gap in pixels between each frame.
	void addFramesRow(Rectangle frameRect, int numFrames, int offset = 0);

	// Get the rectangle for the current frame of animation.
	Rectangle getCurrentFrame();

	// Return the index of the current frame in the vector.
	int getFrameIndex() const { return current_frame; }

	void setFrameIndex(int frameIndex);

	bool hasFrameChanged();

	// Set the speed of animation using the time in seconds between frames.
	void setAnimationSpeed(float frameTime) { animation_speed = frameTime; };
	// Set the speed of animation using the rate of frames per second.
	void setAnimationFps(float fps) { animation_speed = 1.0f / fps; };
	// Get the time in seconds between animation frames.
	float getAnimationSpeed() const { return animation_speed; }

	// Set the speed modifier of one specific frame, relative to the animation framerate. 1 is default.
	// e.g. 0.5 makes a frame persist twice as long, 2.0 makes it persist half as long.
	void setFrameSpeed(int frameIndex, float speed);
	// Get the speed % of one specific frame.
	float getFrameSpeed(int frameIndex);


	// Set the animation loop type. NoLoop disables looping, Loop enables looping,
// Boomerang reverses the play direction at the start/end
	void setLooping(AnimLoopType loopType) { loop_type = loopType; }
	// Get the animation loop type.
	AnimLoopType getLooping() const { return loop_type; };

	// Set the play direction of the animation.
	void setPlayDirection(bool forward) { playing_forward = forward; }
	// Get the direction of play.
	bool isPlayingForward() const { return playing_forward; }

	// Set the animation's horizontal flip.
	void setHorizontalFlip(bool flip);
	// Set the animation's vertical flip.
	void setVerticalFlip(bool flip);
	// Get the animation's horizontal flip.
	bool getHorizontalFlip() const { return h_flip; }
	// Get the animation's vertical flip.
	bool getVerticalFlip() const { return v_flip; }

	// Play the animation.
	void play() { playing = true; }
	// Pause the animation.
	void pause() { playing = false; }
	// Reset the animation.
	void reset();
	// Get whether or not this animation is being played.
	bool isPlaying() const { return playing; }

	// Advance the animation by the time elapsed. Returns true if the frame has changed.
	void animate(float dt);

private:
	std::vector<Frame> frames;
	int current_frame = 0;
	float elapsed_time = 0;

	AnimLoopType loop_type = AnimLoopType::Loop;
	float animation_speed = 1.0f;
	bool playing = true;
	bool playing_forward = true;

	bool frame_changed = false;

	bool h_flip = false;
	bool v_flip = false;

};

