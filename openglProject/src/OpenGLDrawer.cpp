#include "OpenGLDrawer.h"


OpenGLDrawer::OpenGLDrawer(OpenGLShapeRenderer* renderer)
	:renderer{ renderer } {}



void OpenGLDrawer::draw(const Circle& circle)
{
	renderer->addShape(circle);
}

void OpenGLDrawer::draw(const Rectangle& rectangle)
{
	renderer->addShape(rectangle);
}
