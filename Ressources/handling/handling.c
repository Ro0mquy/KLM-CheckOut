
#include "includes\includes.c"


void set_colors (void) {			// �ndert die Text- und Hintergrundfarbe
									// der Konsole
	_textcolor (TEXT_COLOR);
	_textbackground (BACKGROUND_COLOR);
	_clrscr ();
}


void error_msg (const char *string) {			// Funktion die bei einem Fehler aufgerufen wird
												// und das Programm verl�sst
	printf (STR_ERROR "%s\n\n", string);
	_getch ();
	_fcloseall();
	exit (1);
}


void bubble_sort (unit *data) {				// sotiert ein Datenfeld nach der Verk�ufernummer
											// mit der Bubbelsort-Methode
	unit temp;
	unit *pdata;

	for (; data->seller_id != -1; ++data) {
		for (pdata = data + 1; pdata->seller_id != -1; ++pdata) {
			
			if (data->seller_id > pdata->seller_id) {					// wenn ein folgender Wert gr�sser als
																		// der Aktuelle ist werden beide getauscht
				temp.seller_id = data->seller_id;
				temp.price = data->price;

				data->seller_id = pdata->seller_id;
				data->price = pdata->price;

				pdata->seller_id = temp.seller_id;
				pdata->price = temp.price;
			}
		}
	}
}


long count_seller (unit *data) {			// z�hlt die Anzahl der verschiedenen Verk�ufernummern
											// in einem Datenfeld und gibt sie zur�ck
	long counter; 

	for (counter = 1; data->seller_id != -1; ++data) {		// durchgehen aller Artikel und inkrementieren des Z�hler,
		if (data->seller_id != (data + 1)->seller_id)		// wenn zwei verschiedene Verk�ufernummern gefunden wurden
			++counter;
	}
	return counter;
}


void sum_data (unit *data, unit *sum) {			// summiert die Preise aller Artikel eines Vek�ufers
												// und schreibt sie in das Feld auf das 'sum' zeigt

	for (sum->seller_id = data->seller_id; data->seller_id != -1; ++data) {
		sum->price += data->price;

		if (data->seller_id != (data + 1)->seller_id) {			// �ndern der Verk�ufernummer
			++sum;												// auf die neue aktuelle
			sum->seller_id = (data + 1)->seller_id;
		}
	}
}
