#include "Mug.h"


int main() {

	UniquePointer<mug::Core> engine(new mug::Core);
	return engine->runEngine();
}