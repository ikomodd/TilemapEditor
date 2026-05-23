#include "UiTransform.h"

#include "../../../Node/Frame2D/Frame2D.h"
#include "../../../Singleton/Display/DisplayCore.h"

void GAME_UiTransform::UpdateTransform() {

	auto* OwnerFrame = static_cast<GAME_Frame2D*>(this);
	auto* ParentFrame = dynamic_cast<GAME_Frame2D*>(OwnerFrame->GetParent());

	// Esta dentro de um frame, e pode usar a escala local
	if (ParentFrame) {
		auto* ParentTransform = static_cast<GAME_UiTransform*>(ParentFrame);

		GlobalPosition = (ParentTransform->GlobalPosition + ParentTransform->GlobalSize * LocalPosition) + GlobalSize * Anchor;
		GlobalSize = ParentTransform->GlobalSize + ParentTransform->GlobalSize * LocalSize;
	}
	// Esta fora de um frame, e deve usar a escala da janela
	else {
		auto& Display = GAME_DisplayCore::Get();

		GlobalPosition = Display.WindowSize * LocalPosition + GlobalSize * Anchor;
		GlobalSize = Display.WindowSize * LocalSize;
	}

	//std::cout << OwnerFrame->Name << " " << GlobalPosition.ToString() << " " << GlobalSize.ToString() << "\n";
}
