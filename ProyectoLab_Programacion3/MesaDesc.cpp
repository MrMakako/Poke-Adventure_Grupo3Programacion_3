#include "MesaDesc.h"

void MesaDesc::AddInput(int*_Mx, int*_My, bool* _MouseClicked)
{
	MouseX = _Mx;
	MouseY = _My;
	MouseClicked = _MouseClicked;
}

void MesaDesc::CargarPreguntas()
{


	Respuestas = Dialog("Dialogs/RespuestasDesc.txt", 50);
	DescPreguntas = Dialog("Dialogs/PreguntasDescartes.txt", 50);
	DescPreguntas.load();
	Respuestas.load();






	Font = DescPreguntas.getFont();

	
	

	
}

void MesaDesc::DrawPreguntas()
{
	int Ypos=30;
	for (int i = 0; i < DescPreguntas.getMessage(preguntaActual).size(); i++) {

		al_draw_text(Font, al_map_rgb(255, 255, 255), 10, Ypos, 0, DescPreguntas.getMessage(preguntaActual)[i].c_str());

		Ypos += 50;
	}
	

}

void MesaDesc::CambiarPregunas()
{

		

	const char* frase;

	for (int i = 0; i < Bottons.size(); i++) {
	
	
		frase = Respuestas.getMessage(preguntaActual)[i].c_str();

		Bottons[i].setFrase(frase);
		std::cout << frase << "\n";
	}
}

void MesaDesc::AddButton(ALLEGRO_BITMAP* _Sprite, int w, int h)
{
	if (MainPlayer == nullptr) {
		std::cout << "------------------------------------------------------------------------------------------ERROr";
	


	}
	PokemonBtn Btn(_Sprite, 0, 0, w, h, Snivy, MainPlayer);
	Btn.setRx(2);
	Btn.setRx(2);
	
	Bottons.push_back(Btn);




}

void MesaDesc::LoadButtons()
{

	CargarPreguntas();
	Left=PokemonBtn(al_load_bitmap("Pokemon/Left.png"),0,0,92,92,Snivy,MainPlayer);
	Right = PokemonBtn(al_load_bitmap("Pokemon/Right.png"), 0, 0, 92, 92,Snivy, MainPlayer);
	Left.setRx(1);
	Left.setRy(1);

	Right.setRx(1);
	Right.setRy(1);
	AddButton(al_load_bitmap("Pokemon/A.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/B.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/C.png"), 96, 96);
	AddButton(al_load_bitmap("Pokemon/D.png"), 96, 96);




}



void MesaDesc::DrawTable()
{

	int _xPos=100;
	int _yPos=200;
	Map::Draw(1,1);


	

	//Boton Izquierdo

	if (collision(*MouseX, *MouseY,30, 600, 92, 92)) {
	
		Left.DrawInTable(30, 600, true);

		if (*MouseClicked) {
			if (preguntaActual >0) {
				preguntaActual--;

				CambiarPregunas();
			}
		}
	}
	else {
	
		Left.DrawInTable(30, 600, false);
	
	}
	//BotonDerecho
	if (collision(*MouseX, *MouseY, 900, 600, 92, 92)) {
		Right.DrawInTable(900, 600, true);
		if (*MouseClicked) {
			if (preguntaActual < DescPreguntas.getSize()-1) {
				preguntaActual++;
				CambiarPregunas();
			}
		}
	}
	else {
	
		Right.DrawInTable(900,600, false);
	}

	for (int i = 0; i < Bottons.size();i++) {
		
		
		if (collision(*MouseX, *MouseY, _xPos+92, _yPos+92, 32,32)) {
			
			Bottons[i].DrawInTable(_xPos, _yPos, true);
			std::cout << "Cambiando";

		}
		else {
		
			Bottons[i].DrawInTable(_xPos, _yPos, false);
		}
	


		_yPos += 120;
	}



	DrawPreguntas();






}

bool MesaDesc::collision(float x, float y, float ex, float ey, int width, int height)
{

	if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {
		return false;
	}
	return true;
}
