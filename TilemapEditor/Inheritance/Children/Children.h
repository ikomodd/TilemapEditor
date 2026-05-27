#pragma once

#include <iostream>
#include <vector>

class GAME_Node;

class GAME_Children {
private:

	GAME_Node* Owner;
	GAME_Node* Parent = nullptr;
	std::vector <GAME_Node*> Children = {};

public:

	GAME_Children(GAME_Node* owner) : Owner(owner) {}

	GAME_Node* GetParent();
	std::vector <GAME_Node*> GetChildren();

	void AddNode(GAME_Node* node);
	void RemoveNode(GAME_Node* node);

	bool HasNode(std::string node_name);

	size_t GetNodeIndex(std::string node_name);

	std::vector <GAME_Node*> GetFullChildren();

	template <typename T>
	T* GetNode(std::string node_name) {

		GAME_Node* Node = GetPureNode(node_name);
		if (Node) {
			return static_cast<T*>(Node);
		}
		return nullptr;
	}

	template <typename T>
	T* GetNodeFromIndex(size_t index) {

		return static_cast<T*>(Children[index]);
	}

	virtual void _NodeAdded(GAME_Node* node) {}
	virtual void _NodeRemoved(GAME_Node* node) {}

private:

	GAME_Node* GetPureNode(std::string node_name);
};