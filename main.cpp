


/* ************************************************************************************************************ */
	/* **************************************************************************************************** */
/* ************************************************************************************************************ */
	/*


	HowToUse_CListe -- petit programme montrant différentes utilisation de CListe


		Copyright (C)  2014   MiG (alias Benoit Nocaudie)


	This file is part of CListe.

	HowToUse_CListe is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	HowToUse_CListe is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with CListe.  If not, see <http://www.gnu.org/licenses/>.



	*/
/* ************************************************************************************************************ */
	/* **************************************************************************************************** */
/* ************************************************************************************************************ */





#include "CListe.hpp"


#include <iostream>
#include <cstdlib>

using namespace std;

// #include <windows.h>



int main()
{
    CListe<int> Toto;

	cout << "creation d'une CListe de int"
		 << endl << endl
		 << "contenant " << Toto.Get_m_nNbObject() << " objets"
		 << endl << endl;

    cout << "Ajout de 10 objets"
		 << endl << endl;

    for(int i=0; i<10; i++)
	{
		cout << "\t" << i+1 << "e entree : " << i+1 << endl;

		Toto.Add_Tail(i+1);		// !!! Tjs même adresse !!!

		cout << "\t" << i+1 << "° objet : " << Toto[i] << endl
			 << endl;
	}

	cout << endl << endl
		 << "Multiplication par 11 de tous les objets (via Set_Next) :"
		 << endl << endl;

	int** Pos = Toto.Get_aHeadPosition();
	int nObj = 1;
	while(*Pos != NULL)
	{
		Toto.Set_Next(Pos,(nObj*10)+nObj);

		nObj++;
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " suppression de la tete "
		 << endl << endl;

	Toto.Remove_Head();

	cout << endl << endl
		 << " Affichage (decroissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aTailPosition();
	nObj = Toto.Get_m_nNbObject();
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Prev(Pos) << endl;

		nObj--;

	//	system("pause");
	}

	cout << endl << endl
		 << " suppression de la queue "
		 << endl << endl;

	Toto.Remove_Tail();

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " suppression Between 3 et 6 "
		 << endl << endl;

	Toto.RemoveAll_Between(3,6);

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " suppression Outside 3 et 4 "
		 << endl << endl;

	Toto.RemoveAll_Outside(3,4);

	int nNbObj = Toto.Get_m_nNbObject();
	cout << endl << endl
		 << " Affichage (en mode tableau) des " << nNbObj << " Object de la Liste :"
		 << endl << endl;

	for(int i=0; i<nNbObj; i++)
	{
		cout << "\t" << i+1 << "e objet : " << Toto[i] << endl;

	//	system("pause");
	}

	cout << endl << endl
		 << " suppression Totale "
		 << endl << endl;

	Toto.RemoveAll();

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Ajout d'un tableau i*i (10 entrees) :"
		 << endl << endl;

	int nTab = 10;
	int* pTab = new int[nTab];
	for(int i=0; i<nTab; i++)
	{
		pTab[i] = i*i;

		cout << "\t" << i+1 << "e entree : " << pTab[i] << endl;
	}

	Toto.Add_Head(pTab,nTab);

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Suppression avant 3 :"
		 << endl << endl;

	Toto.RemoveAll_Before(3);

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Suppression après 6 :"
		 << endl << endl;

	Toto.RemoveAll_After(6);

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Suppression des nombres impairs :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	while(*Pos != NULL)
	{
		if(Toto.Get_At(*Pos)%2 != 0)
		{
			if(!Toto.Remove_At(*Pos))
				cout << "erreur lors de la suppression";
		}
		else
		{
			Toto.Get_Next(Pos);
		}

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Modification des Objets avec la valeur du 1er ([n] = [n]+[1]) :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	int** Pos1 = Toto.Get_aCurrentPosition();
	cout << "L'adresse courrante (ici Head) : " << *Pos1 << " (contient : " << **Pos1 << ")" << endl;
	while(*Pos != NULL)
	{
		Toto.Set_Next(Pos,Toto.Get_At(*Pos)+Toto.Get_At(*Pos1));

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Toto.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	Pos = Toto.Get_aHeadPosition();
	nObj = 1;
	while(*Pos != NULL)
	{
		cout << "\t" << nObj << "e objet : " << Toto.Get_Next(Pos) << endl;

		nObj++;

	//	system("pause");
	}

	cout << endl << endl
		 << "Creation d'une liste de doubles de -12 à 12 (de 4 en 4) :"
		 << endl << endl;

	CListe<double> Double;

	// boucle for personnalisée
	int i = -12;
	while(i < 13)
	{
		Double.Add_Tail(i);

		i += 4;
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Double.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	double** PosD = Double.Get_aHeadPosition();
	int nObjD = 1;
	while(*PosD != NULL)
	{
		cout << "\t" << nObjD << "e objet : " << Double.Get_Next(PosD) << endl;

		nObjD++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Ajout de 1 2 3 après 0 (via for 1->3) :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	cout << "L'adresse courrante (ici Head) : " << *Pos1 << " (contient : " << **Pos1 << ")" << endl;
	while(*PosD != NULL)
	{
		if(Double.Get_At(*PosD) == 0)
		{
			for(int i=0; i<3; i++)
			{
				Double.Add_After(*PosD,i+1,true);
			}
		}

		Double.Get_Next(PosD);

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Double.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	nObjD = 1;
	while(*PosD != NULL)
	{
		cout << "\t" << nObjD << "e objet : " << Double.Get_Next(PosD) << endl;

		nObjD++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Ajout de 3 2 1 avant 0 (via for 1->3) :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	bool bDone = false;
	while(*PosD != NULL)
	{
		if( (Double.Get_At(*PosD) == 0) && (!bDone) )
		{
			for(int i=0; i<3; i++)
			{
				Double.Add_Before(*PosD,i+1,true);
			}
			bDone = true;
		}

		Double.Get_Next(PosD);

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Double.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	nObjD = 1;
	while(*PosD != NULL)
	{
		cout << "\t" << nObjD << "e objet : " << Double.Get_Next(PosD) << endl;

		nObjD++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Ajout de 3 2 1 après 4 (via for 1->3) :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	cout << "L'adresse courrante (ici Head) : " << *Pos1 << " (contient : " << **Pos1 << ")" << endl;
	while(*PosD != NULL)
	{
		if(Double.Get_At(*PosD) == 4)
		{
			for(int i=0; i<3; i++)
			{
				Double.Add_After(*PosD,i+1,false);
			}
		}

		Double.Get_Next(PosD);

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Double.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	nObjD = 1;
	while(*PosD != NULL)
	{
		cout << "\t" << nObjD << "e objet : " << Double.Get_Next(PosD) << endl;

		nObjD++;

	//	system("pause");
	}

	cout << endl << endl
		 << " Ajout de 1 2 3 avant -4 (via for 1->3) :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	bDone = false;
	while(*PosD != NULL)
	{
		if( (Double.Get_At(*PosD) == -4) && (!bDone) )
		{
			for(int i=0; i<3; i++)
			{
				Double.Add_Before(*PosD,i+1,false);
			}
			bDone = true;
		}

		Double.Get_Next(PosD);

	//	system("pause");
	}

	cout << endl << endl
		 << " Affichage (croissant) des " << Double.Get_m_nNbObject() << " Object de la Liste :"
		 << endl << endl;

	PosD = Double.Get_aHeadPosition();
	nObjD = 1;
	while(*PosD != NULL)
	{
		cout << "\t" << nObjD << "e objet : " << Double.Get_Next(PosD) << endl;

		nObjD++;

	//	system("pause");
	}


	delete Pos1;	/// !!! ne pas deleter Pos : déjà delete dans ~CListe<int>() !!!
					/// !!! ne pas deleter PosD : déjà delete dans ~CListe<double>() !!!


	cout << endl << endl;
	system("pause");

    return 0;
}


















