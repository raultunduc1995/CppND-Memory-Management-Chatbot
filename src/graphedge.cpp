#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphEdge::GraphEdge(int id) {
  std::cout << "GraphEdge constructor " << id << std::endl;
  _id = id;
}

GraphEdge::~GraphEdge() {
  std::cout << "GraphEdge destructor " << _id << std::endl;
}

void GraphEdge::SetChildNode(GraphNode *childNode) { _childNode = childNode; }

void GraphEdge::SetParentNode(GraphNode *parentNode) {
  _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token) {
  _keywords.emplace_back(std::move(token));
}