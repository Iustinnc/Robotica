# Robotica
Aici voi incarca temele de la Robotica

Oancea Iustin-Alexandru

Tema 1 Robotică

	Descierea task-ului:

În această temă trebuie să simulați o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane. În cadrul acestui task trebuie să țineți cont de stările butonului și să folosiți debouncing, dar și să coordonați toate componentele ca într-un scenariu din viața reală.

Starea stației este ‘liberă’. Loader-ul este stins, iar led-ul pentru disponibilitate este verde.
Se apasă butonul pentru start.
Led-ul pentru disponibilitate se face roșu, iar încărcarea începe prin aprinderea primului LED L1.
Led-ul 1 clipește timp de 3s, celelalte fiind stinse.
Dupa încărcarea primului procent de 25% led-ul rămâne aprins și se trece la următorul led, care va începe să clipească.
La finalizarea încărcării toate led-urile vor clipi simultan de 3 ori, iar apoi se vor stinge, pentru a semnaliza finalizarea procesului.
Led-ul pentru disponibilitate se face verde.
Dacă oricând de la pornirea încărcării până la finalizarea acesteia este apăsat lung (min 1s) butonul de stop, încărcarea se întrerupe prin animația de final (toate led-urile clipesc de 3 ori), iar led-ul pentru disponibilitate devine verde.

Componente:

	4x LED-uri (pentru a simula procentul de încărcare)
	1x LED RGB (pentru starea de liber sau ocupat)
	2x Butoane (pentru start încărcare și stop încărcare)
	8x Rezistoare (6x 220/330ohm, 2x 1K)
	Breadboard
	Linii de legătură

Imagini cu setup ul fizic:

![image](https://github.com/user-attachments/assets/50abeb5f-3246-4b04-aff8-488738f1deee)

![image](https://github.com/user-attachments/assets/8e41be15-cebb-4a83-b334-f2dd3baacd40)






Schema electirca:
https://wokwi.com/projects/412621229780445185

video:
https://github.com/user-attachments/assets/bc01bbce-af53-4587-8c4d-a1991d72b64e


Tema 2:

În această temă veți crea un joc asemanator cu TypeRacer.

Jocul este în repaus. LED-ul RGB are culoarea albă.
Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.
Se apasă butonul de start/stop.
LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.
LED-ul devine verde și încep să apară cuvinte de tastat.
La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tasteaza cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.
O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta BackSpace.
Dupa 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.
Jocul se poate opri oricând cu butonul de start/stop.

Componente:

Arduino UNO (ATmega328P microcontroller)
1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
Breadbord
Fire de legătură

Imagini cu setup ul fizic: 

![WhatsApp Image 2024-11-07 at 00 23 25 (2)](https://github.com/user-attachments/assets/25e6a34d-5fb0-4925-925f-d79d6d11ff33)

![WhatsApp Image 2024-11-07 at 00 23 25 (1)](https://github.com/user-attachments/assets/5ca6dda5-55b9-42c8-ad2b-f87d7c7ca68e)

![WhatsApp Image 2024-11-07 at 00 23 25](https://github.com/user-attachments/assets/a3bebae0-d187-4d16-9b9f-b64b28819f33)

Schema electrica:
https://wokwi.com/projects/413263783922997249

Video:
https://github.com/user-attachments/assets/5a31ad6f-8f7b-4a75-aa1c-255782d2835c




