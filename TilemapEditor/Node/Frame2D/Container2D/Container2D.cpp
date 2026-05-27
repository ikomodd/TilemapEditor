#include "Container2D.h"
#include "../../../Singleton/Display/DisplayCore.h"

/*

OBS1: O Ordenate e toda a estrutura dos Container2D's só afetam a posição do objeto, o tamanho ainda
é controlado peloUiTransform2D do próprio objeto, fiz assim porque fica mais simples e evitaria
menos problema.

OBS2: Além disso, o Ordenate está sendo chamado no _Process(), sei que o ideal seria chama-lo apenas quando
a janela é redimensionada, mas aparentemente o UpdateTransfom do _Process() do GameCore é chamado depois
do SDL_EVENT_WINDOW_RESIZED do DisplayCore, então deixei assim porque acho que por agora não vai
dar problema.

*/

void GAME_Container2D::Ordenate() {

	auto& Display = GAME_DisplayCore::Get();

	vector2 PrevSize = 0;

	for (size_t i = 0; i < GetChildren().size(); i++) {

		auto* Frame = GetNodeFromIndex<GAME_Frame2D>(i);

		PrevSize = Frame->GlobalSize;
		Frame->GlobalPosition = GlobalPosition + PrevSize * i * Direction;
	}
}

//


void GAME_Container2D::_Process(float delta) {

	Ordenate();
}

void GAME_Container2D::_NodeAdded(GAME_Node* node) {

	std::cout << "coisou\n";

	auto* Frame2D = static_cast<GAME_Frame2D*>(node);
	Frame2D->ControledByAnother = true;
}

void GAME_Container2D::_NodeRemoved(GAME_Node* node) {

	auto* Frame2D = static_cast<GAME_Frame2D*>(node);
	Frame2D->ControledByAnother = false;
}
