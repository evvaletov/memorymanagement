#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

#define printVariableNameAndValue(x) cout<<"The name of variable **"<<(#x)<<"** and the value of variable is => "<<x<<"\n"

using namespace std;

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ChatBot(const ChatBot &source);

    ChatBot(ChatBot &&source);

    ChatBot &operator=(ChatBot &&source);

    ChatBot &operator=(const ChatBot &source);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);

    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }

    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }

    wxBitmap *GetImageHandle() {
        // printVariableNameAndValue(_image);
        return _image;
    }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */