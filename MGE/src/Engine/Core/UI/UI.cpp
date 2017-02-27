#include "UI.h"
#include <Renderers\UIRenderer.hpp>

UI::UI()
{
	UIRenderer::Instance().AddUIElement(this);
}

UI::~UI()
{
	UIRenderer::Instance().RemoveUIElement(this);
}
