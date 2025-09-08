#include "BuildPostPhaseBehavior.hpp"

BuildPostPhaseBehavior::BuildPostPhaseBehavior(WindowConfig input)
: winConfig(input)
{
	//
}

void BuildPostPhaseBehavior::execute()
{
	int bits = 16;
	GLuint pixelFormat;
	HDC tmpHdc;
	HGLRC hrc;
	
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof( PIXELFORMATDESCRIPTOR ),	// Size of this pfd
		1,									// Version
		PFD_DRAW_TO_WINDOW |				// Format must support window
		PFD_SUPPORT_OPENGL |				// Format must support opengl
		PFD_DOUBLEBUFFER,					// Must support double buffering
		PFD_TYPE_RGBA,						// Request RBGA format
		bits,								// Select colour depth
		0, 0, 0, 0, 0, 0,					// Color bits ignored
		0,									// No alpha buffer
		0,									// Shift bit ignored
		0,									// No accumulation buffer
		0, 0, 0, 0,							// Accumulation bits ignored
		16,									// 16-bit Z-Buffer (depth buffer)
		0,									// No stencil buffer
		0,									// No auxiliary buffer
		PFD_MAIN_PLANE,						// Main drawing layer
		0,									// Reserved
		0, 0, 0 };							// Layer masks ignored
		
	if(!(tmpHdc = GetDC(ptrWindow->getHwnd())))
	{
		MessageBox(NULL,"Can't create a GL device context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}
	ptrWindow->setHdc(tmpHdc);
	
	if(!(pixelFormat = ChoosePixelFormat(tmpHdc, &pfd)))
	{
		MessageBox(NULL,"Can't set the PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}
	
	/*
	if(!(hrc = wglCreateContext(tmpHdc)))
	{
		MessageBox(NULL,"Can't create gl rendering context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}
	
	if(!wglMakeCurrent(tmpHdc,hrc))
	{
		MessageBox(NULL,"Can't activate the gl rendering context.","ERROR", MB_OK|MB_ICONEXCLAMATION);
	}
	*/
}

void BuildPostPhaseBehavior::setPtrWindow(std::shared_ptr<Window> winPtr)
{
	ptrWindow = winPtr;
}
