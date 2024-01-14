#ifndef CHATGUI_H_
#define CHATGUI_H_

#include <memory>
#include <wx/wx.h>

class ChatLogic; // forward declaration

// control panel for background image display
class ChatBotFrameImagePanel : public wxPanel {
  // control elements
  wxBitmap _image;

public:
  // constructor / desctructor
  ChatBotFrameImagePanel(wxFrame *parent);

  // events
  void paintEvent(wxPaintEvent &evt);
  void paintNow();
  void render(wxDC &dc);

  DECLARE_EVENT_TABLE()
};

// dialog item shown in ChatBotPanelDialog
class ChatBotPanelDialogItem : public wxPanel {
private:
  // control elements
  wxStaticBitmap *_chatBotImg;
  wxStaticText *_chatBotTxt;

public:
  // constructor / destructor
  ChatBotPanelDialogItem(wxPanel *parent, wxString text, bool isFromUser);
};

// middle part of the window containing the dialog between user and chatbot
class ChatBotPanelDialog : public wxScrolledWindow {
private:
  // control elements
  wxBoxSizer *_dialogSizer;
  wxBitmap _image;

  //// STUDENT CODE
  ////
  
  // data handles (owned)
  std::unique_ptr<ChatLogic> _chat_logic;

  ////ChatLogic
  //// EOF STUDENT CODE

public:
  // constructor / destructor
  ChatBotPanelDialog(wxWindow *parent, wxWindowID id);

  // events
  void paintEvent(wxPaintEvent &evt);
  void paintNow();
  void render(wxDC &dc);

  // proprietary functions
  void AddDialogItem(wxString text, bool isFromUser = true);
  void PrintChatbotResponse(std::string response);
  void SendMessageToChatbot(const wxString &);
  wxBitmap *GetImageFromChatbot();

  DECLARE_EVENT_TABLE()
};

// frame containing all control elements
class ChatBotFrame : public wxFrame {
private:
  // control elements
  ChatBotPanelDialog *_panelDialog;
  wxTextCtrl *_userTextCtrl;

  // events
  void OnEnter(wxCommandEvent &WXUNUSED(event));

public:
  // constructor / desctructor
  ChatBotFrame(const wxString &title);
};

// wxWidgets app that hides main()
class ChatBotApp : public wxApp {
public:
  // events
  virtual bool OnInit();
};

#endif /* CHATGUI_H_ */
