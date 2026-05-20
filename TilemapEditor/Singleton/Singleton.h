#pragma once

#include <string>
#include <vector>
#include <SDL3/SDL.h>

// CORE_Singleton: Classe base para os CORE_Singletons, precisa para que eles sejam armazenados. Usa GetManagers() para pegar eles


class CORE_iSingleton {
public:

	std::string Name;
	int CallOrder;

	CORE_iSingleton(std::string name, int call_order) : Name(name), CallOrder(call_order) {}
	virtual ~CORE_iSingleton() {}

	virtual void _Init() {}
	virtual void _Event(SDL_Event& event) {}
	virtual void _Process(float delta) {}
	virtual void _Exit() {}

	//

	static std::vector<CORE_iSingleton*>& GetSingletons() {

		static std::vector<CORE_iSingleton*> Singletons;
		return Singletons;
	}

	static void InitAll() {
		for (CORE_iSingleton* singleton : GetSingletons()) {
			singleton->_Init();
		}
	}

	static void EventAll(SDL_Event& event) {
		for (CORE_iSingleton* singleton : GetSingletons()) {
			singleton->_Event(event);
		}
	}

	static void ProcessAll(float delta) {
		for (CORE_iSingleton* singleton : GetSingletons()) {
			singleton->_Process(delta);
		}
	}

	static void ExitAll() {
		for (CORE_iSingleton* singleton : GetSingletons()) {
			singleton->_Exit();
		}
	}
};

// CORE_Singleton, função que é usada como Singleton, Usa Get() para criar e pegar

template <typename T>
class CORE_Singleton : public CORE_iSingleton {
protected:

	CORE_Singleton(std::string name = "NO_NAME", int call_order = 0) : CORE_iSingleton(name, call_order) {}
public:

	static T& Get() {

		static T Instance;

		static bool Instancied = false;
		if (Instancied == false) {

			GetSingletons().push_back(&Instance);
			Instancied = true;
		}
		return Instance;
	}
};