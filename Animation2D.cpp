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
	//if (!h_flip && !v_flip)
	//	return frames[current_frame].rect;

	//Rectangle r = frames[current_frame].rect;
	//if (h_flip && v_flip) {
	//	//Look into this
	//	return Rectangle{ {r.x}, {r.y}, {r.width}, {r.height} };
	//}
	//if (h_flip) {
	//	//Look into this
	//	return sf::IntRect{ {r.position.x + r.size.x, r.position.y}, {-(r.size.x), r.size.y} };
	//}
	//// v_flip case
	////Look into this
	//return sf::IntRect{ {r.position.x, r.position.y + r.size.y}, {r.size.x, -(r.size.y)} };
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
