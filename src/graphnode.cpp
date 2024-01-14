#include "graphnode.h"
#include "graphedge.h"
#include <iostream>

GraphNode::GraphNode(int id) : _chatBot(), _parentEdges{}, _answers{} {
  std::cout << "GraphNode constructor " << id << std::endl;
  _id = id;
}

GraphNode::~GraphNode() {
  std::cout << "GraphNode destructor " << _id << std::endl;
}

void GraphNode::AddToken(std::string token) {
  _answers.emplace_back(std::move(token));
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////
  return _childEdges[index].get();
  ////
  //// EOF STUDENT CODE
}