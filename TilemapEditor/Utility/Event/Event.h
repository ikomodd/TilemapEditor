#pragma once

#include <iostream>
#include <vector>
#include <functional>

template<typename... Args>
struct GAME_Event {
private:

	std::vector<std::function<void(Args...)>> Functions;

public:

	void Connect(std::function<void(Args...)> function) {

		Functions.push_back(function);
	}

	void Invoke(Args... args) {

		for (auto function : Functions) {

			function(args...);
		}
	}
};