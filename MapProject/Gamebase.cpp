//#include "Gamebase.h"

#include "stdafx.h"


Gamebase::Gamebase()
{
	gameData = NULL;
	gameFPS = 0;
	eventTimer = NULL;
	eventQueue = NULL;
}


Gamebase::~Gamebase()
{
	if (gameData) {
		delete gameData;
		gameData = NULL;
	}

	if (eventTimer)
		al_destroy_timer(eventTimer);

	if (eventQueue)
		al_destroy_event_queue(eventQueue);

}


int Gamebase::init()
{
	int iRet = 0;
	ostringstream dbgTxt;

	try {
		iRet = initFrameworks();	// allegro frameworks
		iRet = initResources();

		dbgTxt << "Game Initialisation\n";
		fprintf(stderr, dbgTxt.str().c_str());

		gameData = new(GameData);		// alloc of game Data class
		if (!gameData) {
			return RET_ERR;
		}
		gameData->init();

		gameVisuals.init(this, gameData);

		eventTimer = al_create_timer(1.0 / gameFPS);
		if (!eventTimer) {
			fprintf(stderr, "\tfailed to create timer!\n");
			return RET_ERR;
		}

		eventQueue = al_create_event_queue();
		if (!eventQueue) {
			fprintf(stderr, "\tfailed to create event_queue!\n");
			al_destroy_timer(eventTimer);
			return RET_ERR;
		}

		al_register_event_source(eventQueue, al_get_display_event_source(gameVisuals.getDisplay()));
		al_register_event_source(eventQueue, al_get_timer_event_source(eventTimer));
		al_register_event_source(eventQueue, al_get_mouse_event_source());
		al_register_event_source(eventQueue, al_get_keyboard_event_source());

		al_start_timer(eventTimer);

		dbgTxt << "Game Initialisation finished\n";
		fprintf(stderr, dbgTxt.str().c_str());

		return iRet;
	}
	//catch (bad_alloc &ba) {
	catch (exception &ex) {
		cout << ex.what() << endl;
		return RET_ERR;
	}
}


int Gamebase::initFrameworks(void) {

	// init Allegro and addons
	if (!al_init()) {
		return RET_ERR;
	}

	if (!al_init_primitives_addon()) {
		return RET_ERR;
	}
	if (!al_init_image_addon()) {
		return RET_ERR;
	}

	// initialize the font addon
	al_init_font_addon();

	// initialize the ttf (True Type Font) addon
	al_init_ttf_addon();

	//initialize Keyboard
	al_install_keyboard();
	// initialize mouse
	al_install_mouse();

	return RET_OKAY;
}

int Gamebase::initResources(void) {


	return RET_OKAY;
}

GameData* Gamebase::getData()
{
	return gameData;
}

void Gamebase::gameLoop(void) {

	bool needRedraw = true;
	bool mousebuttons[NUM_MOUSEBUTTONS] = { false };

	ALLEGRO_EVENT alEvent;
	int mouse_change_z = 0;
	int mouse_change_dz = 0;

//	ostringstream debugTxt;

	gameVisuals.draw(getData());


	while (true)
	{
		//CGameEvent gameEvent;
		al_wait_for_event(eventQueue, &alEvent);

		if (alEvent.type == ALLEGRO_EVENT_TIMER) {
			needRedraw = true;
		}
		else if (alEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (alEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (alEvent.mouse.button <= NUM_MOUSEBUTTONS) {
				mousebuttons[alEvent.mouse.button - 1] = true;
				fprintf(stderr, "\nMouse button 1 or 2 pressed");

				//gameEvent.setAlEvent(&alEvent);
				//gameEvent.setEventType(MOUSEBUTTON_DOWN);
				//m_screen->processEvent(&gameEvent);
			}
		}
		else if (alEvent.type == ALLEGRO_EVENT_MOUSE_AXES) {
			ostringstream debugTxt;
			mouse_change_z = alEvent.mouse.z;
			mouse_change_dz = alEvent.mouse.dz;
			if (mouse_change_dz != 0) {
				//fprintf(stderr, "Mouse wheel z value: " << mouse_change_z << "\t");
				//fprintf(stderr, "Mouse wheel dz value: " << mouse_change_dz << "\n");
				debugTxt << "Mouse wheel z value " << mouse_change_z << "\t";
//				fprintf(stderr, debugTxt.str().c_str());
				debugTxt << "Mouse wheel dz value " << mouse_change_dz << "\n";
				fprintf(stderr, debugTxt.str().c_str());

			/// adjust scale with vertical mouse wheel
				//figure_scale_hundredths += 5 * m_z_change;
				//if (figure_scale_hundredths < 1) { figure_scale_hundredths = 1; }
				//figure_scale = static_cast<double>(figure_scale_hundredths) / 100.0;
				//head_buf_dest_pivot_x = body_buf_dest_pivot_x + (int)((figure_scale*body_pivot_to_head_pivot_initial_distance)*cos(body_pivot_to_head_pivot_initial_angle + figure_angle));
				//head_buf_dest_pivot_y = body_buf_dest_pivot_y + (int)((figure_scale*body_pivot_to_head_pivot_initial_distance)*sin(body_pivot_to_head_pivot_initial_angle + figure_angle));
			}
		}

		if (needRedraw && al_is_event_queue_empty(eventQueue)) {
			needRedraw = false;
			gameVisuals.draw(getData());
		}
	}

}