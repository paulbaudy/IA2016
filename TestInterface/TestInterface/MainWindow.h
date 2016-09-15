#pragma once

#define WXUSINGDLL

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/frame.h>
#include <wx/event.h>
#include <wx/menu.h>


class MainWindow: public wxApp
{
public:
	/* MainWindow();
	~MainWindow(); */
	virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};


enum {
	ID_Main = 1
};


