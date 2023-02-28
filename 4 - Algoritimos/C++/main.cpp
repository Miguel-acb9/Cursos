/*
[] - Arrumar placar(imprimir) - 131
[] - 
[] - 
[] - 
[] - 
*/


// Declara��o de Bibliotecas
#include <iostream>
#include <string>
#include <fstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

// Declara��o de Constantes
#define ALTURA_DA_JANELA 720
#define LARGURA_DA_JANELA 1280

// Declara��o de Vari�veis Globais
float velocidade = 1.0;
ALLEGRO_FONT* arial30 = NULL;
ALLEGRO_FONT* arial65 = NULL;
ALLEGRO_BITMAP* fundo = NULL;
ALLEGRO_DISPLAY* janela = NULL;
ALLEGRO_EVENT_QUEUE* fila_de_eventos = NULL;
enum CONTROLES { DIREITA, ESQUERDA };

// Declara��o de Fun��es
int main(), jogar(), inicializacao();
void desenhar_hud(ALLEGRO_FONT* arial65, ALLEGRO_FONT* arial30, int x, int y);

using namespace std;

int main()
{
	// Faz a Verifica��o da Inicializa��o da Biblioteca Allego
	if (inicializacao() == -1) { return -1; }

	// Declara��o de Vari�veis
	ALLEGRO_EVENT evento;
	int i, menu = 1, item = 0, jogo = 0, placar = 1, opcoes = 1, dificuldade = 1, pontos[5];
	string auxiliar, nomes[5];
	
	// Declara��o das Fontes
	arial30 = al_load_font("fontes/arial.ttf", 30, NULL);
	arial65 = al_load_font("fontes/arial.ttf", 65, NULL);

	// Cria��o da Fila de Enventos
	fila_de_eventos = al_create_event_queue();
	al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_de_eventos, al_get_display_event_source(janela));

	// Configura��o do Placar
	ifstream placar_nomes;
	ifstream placar_pontos;
	placar_nomes.open("textos/nomes.txt");
	placar_pontos.open("textos/pontos.txt");

	for (i = 0; i < 5; i++)
	{
		getline(placar_nomes, nomes[i]);
		getline(placar_pontos, auxiliar);
		pontos[i] = stoi(auxiliar);
	}
	placar_nomes.close();
	placar_pontos.close();

	// Menu Inicial
	while (menu)
	{
		fundo = al_load_bitmap("imagens/menu_inicial.bmp");
		al_draw_bitmap(fundo, 0, 0, NULL);

		// Marcar Op��es do Menu
		switch (item)
		{
		case 0:
			al_draw_rounded_rectangle(382, 238, 917, 316, 16, 16, al_map_rgb(255, 255, 0), 7);
			break;

		case 1:
			al_draw_rounded_rectangle(382, 351, 917, 429, 16, 16, al_map_rgb(255, 255, 0), 7);
			break;

		case 2:
			al_draw_rounded_rectangle(382, 463, 917, 541, 16, 16, al_map_rgb(255, 255, 0), 7);
			break;

		case 3:
			al_draw_rounded_rectangle(382, 578, 917, 657, 16, 16, al_map_rgb(255, 255, 0), 7);
			break;
		}
		al_flip_display();

		// Entrada do Evento
		al_wait_for_event(fila_de_eventos, &evento);
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				if (item == 0) { item = 3; }
				else { item--; }
				break;

			case ALLEGRO_KEY_DOWN:
				if (item == 3) { item = 0; }
				else { item++; }
				break;

			case ALLEGRO_KEY_ENTER:
				switch (item)
				{
				case 0: // ===================================================================== Jogo 
					jogar();
					break;

				case 1: // Placar
					placar = 1;
					while (placar)
					{
						fundo = al_load_bitmap("imagens/placar.bmp");
						al_draw_bitmap(fundo, 0, 0, NULL);

						// Escrever nomes e pontos do placar





						al_draw_textf(arial30, al_map_rgb(0, 0, 255), 400, 350, NULL, "%s - %d", nomes[0], pontos[0]);


						al_flip_display();

						al_wait_for_event(fila_de_eventos, &evento);
						if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
						{
							if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
							{
								placar = false;
							}
						}
						else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
						{
							menu = false;
							placar = false;
						}
					}
					break;

				case 2: // Op��es
					opcoes = true;
					while (opcoes)
					{
						fundo = al_load_bitmap("imagens/opcoes.bmp");
						al_draw_bitmap(fundo, 0, 0, NULL);
						switch (dificuldade)
						{
						case 0:
							al_draw_text(arial30, al_map_rgb(0, 255, 0), 650, 283, ALLEGRO_ALIGN_CENTRE, "Facil");
							velocidade = 0.75;
							break;

						case 1:
							al_draw_text(arial30, al_map_rgb(255, 255, 255), 650, 283, ALLEGRO_ALIGN_CENTRE, "Normal");
							velocidade = 1.00;
							break;

						case 2:
							al_draw_text(arial30, al_map_rgb(255, 0, 0), 650, 283, ALLEGRO_ALIGN_CENTRE, "Dificil");
							velocidade = 1.25;
							break;
						}
						al_flip_display();

						al_wait_for_event(fila_de_eventos, &evento);
						if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
						{
							if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { opcoes = 0; }

							switch (evento.keyboard.keycode)
							{
							case ALLEGRO_KEY_RIGHT:
								if (dificuldade == 2) { dificuldade = 0; }
								else { dificuldade++; }
								break;

							case ALLEGRO_KEY_LEFT:
								if (dificuldade == 0) { dificuldade = 2; }
								else { dificuldade--; }
								break;
							}
						}
						else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
						{
							menu = false;
							opcoes = false;
						}
					}
					break;

				case 3: // Sair
					menu = false;
					return 0;
				}
			}
		}

		// Bot�o Fechar [ X ]
		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { menu = false; }

		al_flip_display();
	}

	// Libera��o de Espa�o
	al_destroy_font(arial30);
	al_destroy_font(arial65);
	al_destroy_bitmap(fundo);
	al_destroy_display(janela);
	al_destroy_event_queue(fila_de_eventos);
	return 0;
}

int inicializacao()
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_init( )", "Houve um erro ao tentar inicializar a biblioteca Allegro.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	janela = al_create_display(LARGURA_DA_JANELA, ALTURA_DA_JANELA);
	if (!janela)
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_create_display( )", "Houve um erro ao tentar criar a janela!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_init_primitives_addon( )", "Houve um erro ao inicializar o modulo de formas primitivas.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init_font_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_init_font_addon( )", "Houve um erro ao inicializar o modulo de fontes.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init_ttf_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_init_ttf_addon( )", "Houve um erro ao inicializar o modulo de ttf.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_install_keyboard())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_install_keyboard( )", "Houve um erro ao inicializar o modulo de leitura do teclado.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init_image_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "Erro: al_init_image_addon( )", "Houve um erro ao inicializar o modulo de imagens.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	return 0;
}

int jogar()
{
	// Declara��o de Vari�veis
	int fim = 0;
	int pos_x_nave = 20;
	int pos_y_nave = 630;
	ALLEGRO_EVENT evento;
	bool controles[2] = { false, false };

	desenhar_hud(&*arial65, &*arial30, pos_x_nave, pos_y_nave);

	al_flip_display();
	// Loop Principal do Jogo
	while (!fim)
	{
		al_wait_for_event(fila_de_eventos, &evento);

		// Tecla Apertada
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			// ==================================================================================================================== Menu PAUSE
			if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { fim = true; }

			// Controles
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				controles[DIREITA] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				controles[ESQUERDA] = true;
				break;

			default:
				break;
			}
		}

		// Tecla Solta
		if (evento.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				controles[DIREITA] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				controles[ESQUERDA] = false;
				break;

			default:
				break;
			}
		}

		// Bot�o Fechar [ X ]
		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { fim = false; }

		// Movimenta��o do Personagem
		if (pos_x_nave + 5 <= 670) { pos_x_nave += controles[DIREITA] * 5; }
		else if (pos_x_nave - 5 >= 20) { pos_x_nave -= controles[ESQUERDA] * 5; }

		// Atualizar Mudan�as na Tela
		desenhar_hud(&*arial65, &*arial30, pos_x_nave, pos_y_nave);
		al_draw_rectangle(pos_x_nave, pos_y_nave, pos_x_nave + 30, pos_y_nave + 30, al_map_rgb(255, 255, 255), 3); // jogador
	}

	return 0;
}

// ==================================================

void desenhar_hud(ALLEGRO_FONT* arial65, ALLEGRO_FONT* arial30, int x, int y)
{
	int pontos = 1234, maior_pontuacao = 10000000;
	al_clear_to_color(al_map_rgb(0, 0, 0));

	fundo = al_load_bitmap("imagens/fundo.bmp");
	al_draw_bitmap(fundo, 0, 0, NULL);

	al_flip_display();
}
