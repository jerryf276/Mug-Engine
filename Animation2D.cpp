#include "Animation2D.h"

void Animation2D::addFrame(Rectangle rect, float frameSpeed) {
	frames.push_back({ rect, frameSpeed });
}

void Animation2D::addFramesRow(Rectangle frameRect, int numFrames, int offset)
{
	frames.push_back({ frameRect, 1.0f });

	Rectangle rect = frameRect;
	for (int i = 1; i < numFrames; i++) {
		rect = { {rect.x}, {rect.y}, {rect.width}, {rect.height} };
		frames.push_back({ rect, 1.0f });
	}
}

Rectangle Animation2D::getCurrentFrame()
{
	if (!h_flip && !v_flip)
		return frames[current_frame].rect;

	Rectangle r = frames[current_frame].rect;
	if (h_flip && v_flip) {
		//Look into this
		return { {r.x - r.width}, {r.y - r.height}, {r.width}, {r.height} };
	}
	if (h_flip) {
		//Look into this
		return { {r.x - r.width}, {r.y}, {r.width}, {r.height} };
	}
	//// v_flip case
	////Look into this
	return { {r.x}, {r.y - r.height}, {r.width}, {r.height} };
}

void Animation2D::setFrameIndex(int frameIndex)
{
	if (frameIndex == current_frame) return;
	current_frame = frameIndex;
	frame_changed = true;
}

bool Animation2D::hasFrameChanged()
{
	if (frame_changed) {
		frame_changed = false;
		return true;
	}
	return false;
}

void Animation2D::setFrameSpeed(int frameIndex, float speed)
{
	frames[frameIndex].speed = speed;
}

float Animation2D::getFrameSpeed(int frameIndex)
{
	return frames[frameIndex].speed;
}

void Animation2D::setHorizontalFlip(bool flip)
{
	h_flip = flip;
	frame_changed = true;
}

void Animation2D::setVerticalFlip(bool flip)
{
	v_flip = flip;
	frame_changed = true;
}

void Animation2D::reset()
{
	current_frame = 0;
	elapsed_time = 0.0f;
	frame_changed = true;
}

void Animation2D::animate(float dt)
{
	if (!playing) return;

	elapsed_time += (dt * getFrameSpeed(current_frame));
	if (elapsed_time <= animation_speed) return;
	elapsed_time -= animation_speed;

	int frameCount = getFrameCount();

	if (playing_forward) {
		if (current_frame + 1 < frameCount) {
			current_frame++;
			frame_changed = true;
			return;
		}
	}
	else if (current_frame - 1 >= 0) {
		current_frame--;
		frame_changed = true;
		return;
	}

	if (loop_type == AnimLoopType::NoLoop) {
		playing = false;
		return;
	}

	frame_changed = true;
	if (loop_type == AnimLoopType::Loop) {
		if (playing_forward) {
			current_frame = 0;
			return;
		}
		else {
			current_frame = frameCount - 1;
			return;
		}
	}

	// boomerang case
	playing_forward = !playing_forward;
	if (playing_forward) {
		current_frame = current_frame + 1;
	}
	else {
		current_frame = current_frame - 1;
	}
	return;
}
