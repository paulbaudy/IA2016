#include "GlView.h"



GlView::GlView(wxWindow* parent, wxSize const& taille, wxPoint const& position): wxGLCanvas(parent, wxID_ANY)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(GlView::draw));
}

void GlView::InitOpenGL() {
	

	
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(65.0, 1.0, 1.0, 100.0);
	
	glClearColor(1.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
}

void GlView::draw(wxPaintEvent& event) {
	SetCurrent(this);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	


	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	

	glFlush();
	SwapBuffers();
}
