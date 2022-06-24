#include "kant.h"

void Kant::AddInput(int* _Mx, int* _My, bool* _MouseClicked)
{
	MouseX = _Mx;
	MouseY = _My;
	MouseClicked = _MouseClicked;

}

void Kant::CargarPreguntas()
{
	Respuestas = Dialog("Dialogs/RespuestasDesc.txt", 50);
	DescPreguntas = Dialog("Dialogs/PreguntasKant.txt", 50);
	//DescPreguntas.load();


	Font = DescPreguntas.getFont();

}

void Kant::Avanzar()
{
	preguntaActual = 0;
}

bool Kant::checkSelected(int pos)
{
	if (GivenAnswers[pos] > -1) {

		return true;




	}
	return false;
}

void Kant::DrawPreguntas()
{
	int Ypos = 30;
	for (int i = 0; i < DescPreguntas.getMessage(preguntaActual).size(); i++) {

		al_draw_text(Font, al_map_rgb(255, 255, 255), 50, Ypos, 0, DescPreguntas.getMessage(preguntaActual)[i].c_str());

		Ypos += 50;
	}


}

void Kant::CambiarPregunas()
{



	const char* frase;


	for (int i = 0; i < Bottons.size(); i++) {




		Bottons[i].setFrase(Answers[preguntaActual][i].c_str());

	}
}

bool Kant::CheckAnswers()
{
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (GivenAnswers[i] == CorrectAnswers[i]) {
			count++;

		}
		std::cout << GivenAnswers[i] << "----" << CorrectAnswers[i] << std::endl;


	}
	if (count == 6) {

		win = true;
		return true;

	}

	return false;



}

void Kant::AddButton(ALLEGRO_BITMAP* _Sprite, int w, int h)
{
	if (MainPlayer == nullptr) {
		std::cout << "------------------------------------------------------------------------------------------ERROr";



	}
	PokemonBtn Btn(_Sprite, 0, 0, w, h, Snivy, MainPlayer);
	Btn.setRx(2);
	Btn.setRx(2);

	Bottons.push_back(Btn);




}

void Kant::LoadButtons()
{

	//int CorrectAnswers[5];
	CorrectAnswers[0] = 0;
	CorrectAnswers[1] = 1;
	CorrectAnswers[2] = 1;
	CorrectAnswers[3] = 2;
	CorrectAnswers[4] = 2;
	CorrectAnswers[5] = 1;



	Answers[0][0] = "Imperativo Hipotetico";
	Answers[0][1] = "Imperativo categorico.";
	Answers[0][2] = "ambos";
	Answers[0][3] = "Ninguno";


	Answers[1][0] = "Conocimiento Noumenico.";
	Answers[1][1] = "Conocimiento fenoménico.";
	Answers[1][2] = "conocimiento Empírico.";
	Answers[1][3] = "Conocimiento Racional .";

	Answers[2][0] = "Sopesa tus acciones.";
	Answers[2][1] = "Atrévete a saber por ti mismo.";
	Answers[2][2] = "Saber a la fuerza.";
	Answers[2][3] = "Someterse al conocimiento";

	Answers[3][0] = " Subjetivismo.";
	Answers[3][1] = " Pregjuicio.";
	Answers[3][2] = " giro copernicano.";
	Answers[3][3] = " Suerte";


	Answers[4][0] = " Racionalismo,";
	Answers[4][1] = " Empirismo.";
	Answers[4][2] = " Criticismo.";
	Answers[4][3] = " Escepticismo.";

	Answers[5][0] = " Critica de la razon y la practica";
	Answers[5][1] = " Critica de la razon pura.";
	Answers[5][2] = " Critica del juicio";
	Answers[5][3] = " Critica Fenomenologico";





	Left = PokemonBtn(al_load_bitmap("Pokemon/Left.png"), 0, 0, 92, 92, Snivy, MainPlayer);
	Right = PokemonBtn(al_load_bitmap("Pokemon/Right.png"), 0, 0, 92, 92, Snivy, MainPlayer);
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



void Kant::DrawTable()
{

	int _xPos = 100;
	int _yPos = 200;
	Map::Draw(1, 1);


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
					if (i == CorrectAnswers[preguntaActual]) {

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
					Bottons[i].DrawInTable(_xPos, _yPos, true);

				}

			}

			_yPos += 120;
		}



		DrawPreguntas();


	}






}

bool Kant::isCompleted()
{
	return win;
}

bool Kant::collision(float x, float y, float ex, float ey, int width, int height)
{

	if (x + width<ex || x>ex + width || y > ey + height || y + height < ey) {
		return false;
	}
	return true;
}