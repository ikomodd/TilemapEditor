#include "UiTransform.h"

#include "../../../Node/Frame2D/Frame2D.h"
#include "../../../Singleton/Display/DisplayCore.h"

void GAME_UiTransform::UpdateTransform() {



	auto& Display = GAME_DisplayCore::Get();

	auto* OwnerFrame = static_cast<GAME_Frame2D*>(this);
	auto* ParentFrame = dynamic_cast<GAME_Frame2D*>(OwnerFrame->GetParent());

	GlobalSize = Display.WindowSize * LocalSize;

	if (ControledByAnother) return;

	// Esta dentro de um frame, e pode usar a escala local
	if (ParentFrame) {

		auto* ParentTransform = static_cast<GAME_UiTransform*>(ParentFrame);
		GlobalPosition = (ParentTransform->GlobalPosition + ParentTransform->GlobalSize * LocalPosition) + GlobalSize * Anchor;
	}
	// Esta fora de um frame, e deve usar a escala da janela
	else {

		GlobalPosition = Display.WindowSize * LocalPosition + GlobalSize * Anchor;
	}
	//std::cout << OwnerFrame->Name << " " << GlobalPosition.ToString() << " " << GlobalSize.ToString() << "\n";
}
