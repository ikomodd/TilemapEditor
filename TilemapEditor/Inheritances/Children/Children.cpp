#include "Children.h"

#include "../../Singleton/Scene/SceneCore.h" // CurrentScene
#include "../../Node/Origin/Origin.h"

#include "../../Node/Node.h"

GAME_Node* GAME_Children::GetParent() {

	return Parent;
}

std::vector<GAME_Node*> GAME_Children::GetChildren() {

	return Children;
}

void GAME_Children::AddNode(GAME_Node* node) {

	if (!node->Parent) {

		Children.push_back(node);
		node->Parent = Owner;

		if (GAME_SceneCore::Get().CurrentScene->Initialized)
			node->_Ready();
	}
	else
		std::cerr << "[CHILDREN] Node: " << node->Name << " ja esta em uma familia e nao pode ser adicionado em: " << Owner->Name << "\n";
}

void GAME_Children::RemoveNode(GAME_Node* node) {

	if (HasNode(node->Name)) {

		Children.erase(Children.begin() + GetNodeIndex(node->Name));
	}
}

bool GAME_Children::HasNode(std::string node_name)
{
	for (GAME_Node* node : Children) {
		if (node->Name == node_name)
			return true;
	}
	return false;
}

size_t GAME_Children::GetNodeIndex(std::string node_name)
{
	for (size_t i = 0; i < Children.size(); i++) {
		GAME_Node* Node = Children[i];

		if (Node->Name == node_name)
				return i;
	}
	std::cerr << "[CHILDREN] Nao é possivel determinar o index de: " << node_name << " ja que ele nao pertence a: " << Owner->Name << "\n";
	return -1;
}

std::vector<GAME_Node*> GAME_Children::GetFullChildren() {
	std::vector <GAME_Node*> Result;

	for (GAME_Node* node : GetChildren()) {
		Result.push_back(node);

		auto Current = node->GetFullChildren();
		Result.insert(Result.end(), Current.begin(), Current.end());
	}
	return Result;
}

GAME_Node* GAME_Children::GetPureNode(std::string node_name) {

	for (GAME_Node* node : Children) {
		if (node->Name == node_name)
			return node;
	}
	std::cerr << "[CHILDREN] Node: " << node_name << " nao pode serr retornado porque nao pertence a familia de: " << Owner->Name << "\n";
	return nullptr;
}

