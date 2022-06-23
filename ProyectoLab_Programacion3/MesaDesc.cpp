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
	//DescPreguntas.load();







	Font = DescPreguntas.getFont();

	
	

	
}

void MesaDesc::Avanzar()
{
	preguntaActual = 0;
}

bool MesaDesc::checkSelected(int pos)
{
	if (GivenAnswers[pos] > -1) {
		
		return true;


	
	
	}
	return false;
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
	
	
	

		Bottons[i].setFrase(Answers[preguntaActual][i].c_str());
		
	}
}

bool MesaDesc::CheckAnswers()
{
	int count=0;
	for (int i = 0; i < 5;i++) {
		if (GivenAnswers[i] == CorrectAnswers[i]) {
			count++;
		
		}
		std::cout << GivenAnswers[i] << "----" << CorrectAnswers[i] <<std::endl;
	
		
	}
	if (count == 5) {

		win = true;
		return true;
	
	}

	return false;



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

	//int CorrectAnswers[5];
	CorrectAnswers[0] = 3;
	CorrectAnswers[1] = 2;
	CorrectAnswers[2] = 1;
	CorrectAnswers[3] = 0;
	CorrectAnswers[4] = 0;



	Answers[0][0] = "Los sentidos nos engañan";
	Answers[0][1] = " la existencia del genio maligno";
	Answers[0][2] = "imposibilidad para	diferenciar la vigilia del sueño";
	Answers[0][3] = "Todas son correctas";


	Answers[1][0] = "Hipótesis.";
	Answers[1][1] = "Deducción.";
	Answers[1][2] = "Evidencia.";
	Answers[1][3] = "Inducción.";

	Answers[2][0] = "Los sentidos son una fuente confiable para conocer.";
	Answers[2][1] = "Desconfianza de lo que los sentido	nos proporcionan.";
	Answers[2][2] = "Los sentidos son complementarios.";
	Answers[2][3] = "Los sentidos son determinantes";

	


	Answers[3][0] = " René Descartes.";
	Answers[3][1] = " David Hume.";
	Answers[3][2] = " George Berkeley.";
	Answers[3][3] = " Aristóteles";


	Answers[4][0] = "Es preciso dudar";
	Answers[4][1] = " Debemos confiar ciegamente.";
	Answers[4][2] = " Nada es importante";
	Answers[4][3] = " Todo es posible";





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


	CargarPreguntas();
	CambiarPregunas();

}



void MesaDesc::DrawTable()
{

	int _xPos=100;
	int _yPos=200;
	Map::Draw(1,1);


	if (Progress == 5) {
	
		Victory = false;
	}

	//Boton Izquierdo
	if (!Victory) {
		if (collision(*MouseX, *MouseY, 30, 600, 92, 92)) {

			Left.DrawInTable(30, 600, true);

			if (*MouseClicked) {
				if (preguntaActual > 0) {
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
				if (preguntaActual < DescPreguntas.getSize() - 1) {
					preguntaActual++;
					CambiarPregunas();
				}
			}
		}
		else {

			Right.DrawInTable(900, 600, false);
		}

		for (int i = 0; i < Bottons.size(); i++) {


			if (collision(*MouseX, *MouseY, _xPos + 92, _yPos + 92, 32, 32)) {

				Bottons[i].DrawInTable(_xPos, _yPos, true);
				
				if (*MouseClicked) {
					if (i==CorrectAnswers[preguntaActual]) {
					
						std::cout << "Cambiando";
					
						
						Progress++;

						





						CambiarPregunas();
						
						//Confirmas que se ha presionado la correcta
					}
					GivenAnswers[preguntaActual] = i;


				}


			}
			else {

				Bottons[i].DrawInTable(_xPos, _yPos, false);
			}


			

			if (checkSelected(preguntaActual)) {

				if (i == GivenAnswers[preguntaActual]) {
					Bottons[i].DrawInTable(_xPos, _yPos,true);

				}

			}

			_yPos += 120;
		}
	
		

		DrawPreguntas();

	
	}
	





}

bool MesaDesc::isCompleted()
{
	return win;
}

bool MesaDesc::collision(float x, float y, float ex, float ey, int width, int height)
{

	if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {
		return false;
	}
	return true;
}
