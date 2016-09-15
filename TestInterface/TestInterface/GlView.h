#pragma once

#define WXUSINGDLL

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <gl\GL.h>
#include <gl\GLU.h>	
#include <wx/glcanvas.h>


class GlView: public wxGLCanvas
{
public:
	GlView(wxWindow* parent, wxSize const& taille = wxDefaultSize, wxPoint const& position = wxDefaultPosition);

	void InitOpenGL();

private:
	void draw(wxPaintEvent& event);

};

