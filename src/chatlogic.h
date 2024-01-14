#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include "chatbot.h"

#include <memory>
#include <string>
#include <vector>

// forward declarations
class GraphEdge;
class GraphNode;
class ChatBotPanelDialog;

class ChatLogic {
private:
  //// STUDENT CODE
  ////

  // data handles (owned)
  using NodesList = std::vector<std::unique_ptr<GraphNode>>;
  NodesList _nodes;

  ////
  //// EOF STUDENT CODE

  // data handles (not owned)
  GraphNode *_currentNode;
  ChatBotPanelDialog *_panelDialog;
  ChatBot *_chatBot;

  // proprietary type definitions
  typedef std::vector<std::pair<std::string, std::string>> tokenlist;

  // proprietary functions
  template <typename T>
  void AddAllTokensToElement(std::string tokenID, tokenlist &tokens,
                             T &element);

public:
  // constructor / destructor
  ChatLogic();
  ~ChatLogic();

  // getter / setter
  void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
  void SetChatbotHandle(ChatBot *chatbot);

  // proprietary functions
  void LoadAnswerGraphFromFile(std::string filename);
  void SendMessageToChatbot(std::string message);
  void SendMessageToUser(std::string message);
  wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */