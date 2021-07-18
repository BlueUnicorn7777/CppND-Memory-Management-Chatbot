#include "graphedge.h"
#include "graphnode.h"
#include<iostream>

GraphNode::GraphNode(int id)
{
    _id = id;


}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //std::cout<< ((_chatBot!=nullptr)?"T\n":"F\n");
   // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GE &edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
///
void GraphNode::MoveChatbotHere(ChatBot &chatbot) // pass by reference will avoid move constructor
//void GraphNode::MoveChatbotHere(ChatBot chatbot) //uncomment this line and comment above line to use the move contructor

{
    //_chatBot=chatbot;
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);

}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //newNode->MoveChatbotHere(std::move(_chatBot));

    newNode->MoveChatbotHere(_chatBot);
    //_chatBot = nullptr; // invalidate pointer at source

}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

   return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
