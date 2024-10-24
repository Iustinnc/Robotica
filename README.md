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

