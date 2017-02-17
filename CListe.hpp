


/* ************************************************************************************************************ */
	/* **************************************************************************************************** */
/* ************************************************************************************************************ */
	/*


	CListe -- Classe template gérant les allocation dynamiques d'une liste d'objet, et les modifications de cette liste


		Copyright (C)  2014   MiG (alias Benoit Nocaudie)


	This file is part of CListe.

	CListe is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	CListe is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with CListe.  If not, see <http://www.gnu.org/licenses/>.



	*/
/* ************************************************************************************************************ */
	/* **************************************************************************************************** */
/* ************************************************************************************************************ */






#pragma once




#include <iostream>		// pour que NULL soit compris

using namespace std;






/* **************************** */
/* ***********      *********** */
/* ******                ****** */
/* ***         .hpp         *** */
/* ******                ****** */
/* ***********      *********** */
/* **************************** */





template <typename Object>
class CListe
{

private:

	int m_nNbObject;	/// nb d'objets dans la liste

	Object** m_pAdress;	/// tableau contenant les adresses des objets de la liste (tableau [m_nNbObjects+2])

	Object** m_pPosition;	/// Pointeur contenant l'adresse d'un Objet

	int m_nPosition;	/// indice d'un objet dans le tableau d'adresses


public:

//-------------------------------------------------------------------------------------------------------------------------------
		// Constructeurs
//-------------------------------------------------------------------------------------------------------------------------------

	CListe();
	CListe(CListe & L);
	CListe operator= (CListe L);
	~CListe();


//-------------------------------------------------------------------------------------------------------------------------------
		// Outils
//-------------------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------------------
			// Positions

				/* toutes */

	int Get_nPosition(Object* aPosition, bool bSaveIt = true);	/// retourne l'indice de l'adresse aPosition, if(bSaveIt)-> le sauve dans m_nPosition ; -1-> aPosition inconnue
	Object* Get_aPosition(int nPosition);	/// retourne l'adress de l'indice nPosition [0;m_nNbObject+2-1] ; Access error-> indice non viable ; NULL-> pas d'Objet : [0] ou [m_nNbObject+2-1]

				/* début */

	Object** Get_aHeadPosition();	/// retourne l'adresse du premier objet de la Liste, et sauve l'indice associé dans m_nPosition ; NULL-> pas d'objets dans la liste
	int Get_nHeadPosition();	/// retourne l'indice du premier objet de la Liste ; -1-> pas d'objets dans la liste

				/* fin */

	Object** Get_aTailPosition();	/// retourne l'adresse du dernier objet de la Liste, et sauve l'indice associé dans m_nPosition ; NULL-> pas d'objets dans la liste
	int Get_nTailPosition();	/// retourne l'indice du dernier objet de la Liste ; -1-> pas d'objets dans la liste


	//-------------------------------------------------------------------------------------------------------------------------------
			// Modification Tableau (incrémentation des "Positions")

				/* Ajouter */

	bool Add_anObjectATnPosition(int nPosition, Object Obj, bool bGoToNewObject = true, bool bBefore = true);	/// ajoute un objet au tableau à l'indice nPosition, et incrémente (ou pas) la Position actuelle ; false-> nPosition invalide
	bool Add_tabObjectATnPosition(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true, bool bBefore = true);	/// ajoute les objets d'un tableau au tableau à partir de l'indice nPosition, et incrémente (ou pas) la Position actuelle ; false-> nPosition invalide ; Access error-> mauvaise entrée tableau

				/* Retirer */

	bool Remove_nPositionObject(int nPosition);	/// enlève une adresse au tableau à l'indice nPosition ; false-> nPosition invalide (ou pas d'objets dans la Liste)
	bool RemoveBefore_nPositionObject(int nPosition);	/// enlève toute les adresse depuis nPosition (nPosition conservé) ; false-> nPosition invalide
	bool RemoveAfter_nPositionObject(int nPosition);	/// enlève toute les adresse jusqu'à nPosition (nPosition conservé) ; false-> nPosition invalide
	bool RemoveBetween_nPositionsObjects(int nAfterPosition, int nBeforePosition);	/// enlève toute les adresse à l'intérieur de ]nAfterPosition;nBeforePosition[ (nPositions conservées) ; false-> nPositions invalide
	bool RemoveOutside_nPositionsObjects(int nAfterPosition, int nBeforePosition);	/// enlève toute les adresse à l'extérieur de [nAfterPosition;nBeforePosition] (nPositions conservées) ; false-> nPositions invalide


//-------------------------------------------------------------------------------------------------------------------------------
		// Récupération d'Objet
//-------------------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------------------
			// Récupération simple

				/* Mode Liste */

	Object Get_At(Object* aPosition);	/// retourne l'objet contenu à l'adresse aPosition ; Access error-> adresse non viable
	Object Get_At(int nPosition);	/// retourne le nPosition° objet de la Liste [1;m_nNbObject+2-1] ; Access error-> indice non viable

				/* Mode Tableau */

	Object operator[] (int nPosition);	/// retourne le nPosition° objet de la Liste [0;m_nNbObject] ; Access error-> indice non viable


			// Récupération et incrémentation

	Object Get_Next(Object** aPosition);	/// retourne l'objet contenu à l'adresse aPosition, et passe à l'adresse suivante ; Access error-> adresse non viable
	Object Get_Prev(Object** aPosition);	/// retourne l'objet contenu à l'adresse aPosition, et passe à l'adresse précedente ; Access error-> adresse non viable


//-------------------------------------------------------------------------------------------------------------------------------
		// Modification d'Objet
//-------------------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------------------
			// Modification simple

	bool Set_At(Object* aPosition, Object Obj);	/// remplace l'objet à l'adresse aPosition par Obj ; false-> adresse non viable
	bool Set_At(int nPosition, Object Obj);	/// remplace l'objet à l'indice nPosition par Obj [1;m_nNbObject] ; false-> indice non viable


	//-------------------------------------------------------------------------------------------------------------------------------
			// Modification et incrémentation

	bool Set_Next(Object** aPosition, Object Obj);	/// remplace l'objet à l'adresse aPosition par Obj, et passe à l'adresse suivante ; false-> adresse non viable
	bool Set_Prev(Object** aPosition, Object Obj);	/// remplace l'objet à l'adresse aPosition par Obj, et passe à l'adresse précedente ; false-> adresse non viable


//-------------------------------------------------------------------------------------------------------------------------------
		// Ajouter un Objet (incrémentation des "Positions")
//-------------------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------------------
			// Ajout aux extrémitées

	void Add_Head(Object Obj, bool bGoToNewObject = true);	/// ajoute un objet au début de la Liste, et incrémente (ou pas) la Position actuelle
	void Add_Tail(Object Obj, bool bGoToNewObject = true);	/// ajoute un objet à la fin de la Liste, et incrémente (ou pas) la Position actuelle


	//-------------------------------------------------------------------------------------------------------------------------------
			// Ajout à une place spécifique

				/* Avant un Objet */

	bool Add_Before(Object* aPosition, Object Obj, bool bGoToNewObject = true);	/// Ajoute l'objet Obj avant l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle ; false-> adresse non viable
	bool Add_Before(int nPosition, Object Obj, bool bGoToNewObject = true);	/// Ajoute l'objet Obj avant l'objet situé à nPosition, et incrémente (ou pas) la Position actuelle ; false-> indice non viable

				/* Après un Objet */

	bool Add_After(Object* aPosition, Object Obj, bool bGoToNewObject = true);	/// Ajoute l'objet Obj après l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle ; false-> adresse non viable
	bool Add_After(int nPosition, Object Obj, bool bGoToNewObject = true);	/// Ajoute l'objet Obj après l'objet situé à nPosition, et incrémente (ou pas) la Position actuelle ; false-> indice non viable


	//-------------------------------------------------------------------------------------------------------------------------------
			// Ajout d'un tableau d'Objet

				/* Aux extrémitées */

	bool Add_Head(Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau au début de la Liste, et incrémente (ou pas) la Position actuelle ; false-> aPosition invalide ; Access error-> mauvaise entrée tableau
	bool Add_Tail(Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau à la fin de la Liste, et incrémente (ou pas) la Position actuelle ; false-> nPosition invalide ; Access error-> mauvaise entrée tableau

				/* Avant un Objet */

	bool Add_Before(Object* aPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau avant l'adresse aPosition, et incrémente (ou pas) la Position actuelle ; false-> aPosition invalide ; Access error-> mauvaise entrée tableau
	bool Add_Before(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau avant l'indice nPosition, et incrémente (ou pas) la Position actuelle ; false-> nPosition invalide ; Access error-> mauvaise entrée tableau

				/* Après un Objet */

	bool Add_After(Object* aPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau après l'adresse aPosition, et incrémente (ou pas) la Position actuelle ; false-> aPosition invalide ; Access error-> mauvaise entrée tableau
	bool Add_After(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject = true);	/// ajoute les objets d'un tableau au tableau après l'indice nPosition, et incrémente (ou pas) la Position actuelle ; false-> nPosition invalide ; Access error-> mauvaise entrée tableau


//-------------------------------------------------------------------------------------------------------------------------------
		// Retirer un Objet (incrémentation des "Positions")
//-------------------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------------------
			// Retrait aux extrémitées

	bool Remove_Head();	/// retire le premier Objet de la Liste ; false-> pas d'objet dans la Liste
	bool Remove_Tail();	/// retire le dernier Objet de la Liste ; false-> pas d'objet dans la Liste


	//-------------------------------------------------------------------------------------------------------------------------------
			// Retrait à une place spécifique

	bool Remove_At(Object* aPosition);	/// retire l'Objet à l'adresse aPosition ; false-> adresse non viable
	bool Remove_At(int nPosition);	/// retire l'Objet à l'indice nPosition ; false-> indice non viable


	//-------------------------------------------------------------------------------------------------------------------------------
			// Retrait d'une partie de la Liste

				/* avant un Objet (Objet conservé) */

	bool RemoveAll_Before(Object* aPosition);	/// retire tout les objets avant l'Objet à l'adresse aPosition ; false-> adresse non viable
	bool RemoveAll_Before(int nPosition);	/// retire tout les objets avant l'Objet à l'indice nPosition ; false-> indice non viable

				/* jusqu'à un Objet (Objet détruit) */

	bool RemoveAll_To(Object* aPosition);	/// retire tout les objets jusqu'à l'Objet à l'adresse aPosition ; false-> adresse non viable
	bool RemoveAll_To(int nPosition);	/// retire tout les objets jusqu'à l'Objet à l'indice nPosition ; false-> indice non viable

				/* après un Objet (Objet conservé) */

	bool RemoveAll_After(Object* aPosition);	/// retire tout les objets après l'Objet à l'adresse aPosition ; false-> adresse non viable
	bool RemoveAll_After(int nPosition);	/// retire tout les objets après l'Objet à l'indice nPosition ; false-> indice non viable

				/* depuis un Objet (Objet détruit) */

	bool RemoveAll_From(Object* aPosition);	/// retire tout les objets depuis l'Objet à l'adresse aPosition ; false-> adresse non viable
	bool RemoveAll_From(int nPosition);	/// retire tout les objets depuis l'Objet à l'indice nPosition ; false-> indice non viable

				/* entre 2 Objets (Objets conservés) */

	bool RemoveAll_Between(Object* aAfterPosition, Object* aBeforePosition);	/// retire tout les objets entre les Objets aux l'adresses aAfterPosition et aBeforePosition ; false-> adresses non viable
	bool RemoveAll_Between(int nAfterPosition, int nBeforePosition);	/// retire tout les objets entre les Objets d'indices nAfterPosition et nBeforePosition ; false-> adresses non viable

				/* depuis un Objet jusqu'à un autre Objet (Objets détruits) */

	bool RemoveAll_FromTo(Object* aFromPosition, Object* aToPosition);	/// retire tout les objets depuis l'Objet à l'adresse aFromPosition, jusqu'à l'Objet à l'adresse aToPosition ; false-> adresses non viable
	bool RemoveAll_FromTo(int nFromPosition, int nToPosition);	/// retire tout les objets depuis l'Objet à l'indice nFromPosition, jusqu'à l'Objet à l'indice nToPosition ; false-> adresses non viable

				/* à l'extérieur de 2 Objets (Objets conservés) */

	bool RemoveAll_Outside(Object* aBeforePosition, Object* aAfterPosition);	/// retire tout les objets à l'extérieur des Objets aux l'adresses aBeforePosition et aAfterPosition ; false-> adresses non viable
	bool RemoveAll_Outside(int nBeforePosition, int nAfterPosition);	/// retire tout les objets à l'extérieur des Objets d'indices nBeforePosition et nAfterPosition ; false-> adresses non viable

				/* depuis un Objet (Objet détruit) */

	bool RemoveAll_ToAndFrom(Object* aToPosition, Object* aFromPosition);	/// retire tout les objets jusqu'à l'objet à l'adrresse aToPosition et tous les objets depuis l'Objet à l'adresse aFromPosition ; false-> adresses non viable
	bool RemoveAll_ToAndFrom(int nToPosition, int nFromPosition);	/// retire tout les objets jusqu'à l'objet d'indice nToPosition et tous les objets depuis l'Objet d'indice nFromPosition ; false-> indices non viable


	//-------------------------------------------------------------------------------------------------------------------------------
			// Retrait de toute la Liste

	void RemoveAll();	/// virginise la Liste


//-------------------------------------------------------------------------------------------------------------------------------
		// Accès en lecture
//-------------------------------------------------------------------------------------------------------------------------------

	int Get_m_nNbObject();	/// return le nombre d'objets de la Liste (taille du tableau-2)

	int Get_m_nPosition();	/// return l'indice de la position actuellement utilisée

	Object** Get_aCurrentPosition();	/// return un pointeur sur l'adresse de la position actuellement utilisée

	
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------

};











/* **************************** */
/* ***********      *********** */
/* ******                ****** */
/* ***         .cpp         *** */
/* ******                ****** */
/* ***********      *********** */
/* **************************** */





//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Constructeurs
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
CListe<Object>::CListe()
: m_nNbObject(0)
, m_pAdress(NULL)
, m_pPosition(NULL)
, m_nPosition(0)
{
	m_pAdress = new Object*[2];	// création d'une Liste "vierge"

	m_pAdress[0] = NULL;
	m_pAdress[1] = NULL;

	m_pPosition = new Object*;	// création du pointeur d'adresse Objet
	*m_pPosition = NULL;	// vierge
}


template <typename Object>
CListe<Object>::CListe(CListe & L)
: m_nNbObject(L.m_nNbObject)
, m_pAdress(NULL)
, m_pPosition(NULL)
, m_nPosition(L.m_nPosition)
{
	m_pAdress = new Object*[m_nNbObject+2];	// on cré le tableau d'adresse

	for(int i=0; i<m_nNbObject+2; i++)
	{
		m_pAdress[i] = new Object(*(L.m_pAdress[i]));	// on recré des new Object avec les valeurs de L
	}

	m_pPosition = new Object*;	// création du pointeur d'adresse Objet
	*m_pPosition = *L.m_pPosition;	// avec l'adresse stocké dans L
}


template <typename Object>
CListe<Object> CListe<Object>::operator= (CListe L)
{
	m_nPosition = L.m_nPosition;	// récupération de l'indice de l'objet utilisé

	if(L.m_pAdress != NULL)	// si la liste à copier contient des "Objects"
	{
		if(m_nNbObject != L.m_nNbObject)	// si la liste existante n'a pas le même nombre d'objet que la liste à copier, ou n'existe pas
		{
			if(m_pAdress != NULL)	// si la liste existante a des objets en mémoire
			{
				delete[] m_pAdress;	// on la détruit
				m_pAdress = NULL;
			}

			m_nNbObject = L.m_nNbObject;	// on répupère le nombre d'objets de la liste à copier
			m_pAdress = new Object*[m_nNbObject+2];	// on crée le tableau d'adresses
		}

		for(int i=0; i<m_nNbObject+2; i++)
		{
			m_pAdress[i] = new Object(*(L.m_pAdress[i]));	// on recré des new Object avec les valeurs de L
		}
	}

	if(m_pPosition == NULL)	// si Pointeur d'adresse object null
	{
		m_pPosition = new Object*;	// création du pointeur d'adresse Objet
	}
	*m_pPosition = *L.m_pPosition;	// on lui met l'adresse stocké dans L

	return *this;
}


template <typename Object>
CListe<Object>::~CListe()
{
	if(m_pAdress != NULL)
	{
		for(int i=0; i<m_nNbObject+2; i++)
		{
			if(m_pAdress[i] != NULL)
			{
				delete m_pAdress[i];
				m_pAdress[i] = NULL;
			}
		}

		delete[] m_pAdress;
	}
	m_pAdress = NULL;

	if(m_pPosition != NULL)
	{
		delete m_pPosition;
	}
	m_pPosition = NULL;
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Outils
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------------------
				// Positions
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* pour toute la Liste */

template <typename Object>
int CListe<Object>::Get_nPosition(Object* aPosition, bool bSaveIt)
	/// retourne l'indice de l'adresse aPosition, if(bSaveIt)-> le sauve dans m_nPosition
		/// -1-> aPosition inconnue
{
	for(int i=0; i<m_nNbObject+2; i++)	// on fouille le tableau d'adresse
	{
		if(m_pAdress[i] == aPosition)	// si on trouve l'adresse recherchée
		{
			if(bSaveIt)	// si on veut garder son indice
			{
				m_nPosition = i;	// on le sauve dans m_nPosition
			}

			return i;	// on retourne l'indice (sans finir de fouiller le tableau)
		}
	}

	return -1;	// si pas trouvé, on retourne -1
}


template <typename Object>
Object* CListe<Object>::Get_aPosition(int nPosition)
	/// retourne l'adress de l'indice nPosition [0;m_nNbObject+2-1]
		/// Access error-> indice non viable ; NULL-> pas d'objet à cet indice : [0] ou [m_nNbObject+2-1]
{
	*m_pPosition = m_pAdress[nPosition];	// on met l'adresse associée à nPosition dans m_pPosition

	return *m_pPosition;	// on retourne l'adresse contenue dans m_pPosition
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* pour le début de la Liste */

template <typename Object>
Object** CListe<Object>::Get_aHeadPosition()
	/// retourne l'adresse du premier objet de la Liste, et sauve l'indice associé dans m_nPosition
		/// NULL-> pas d'objets dans la liste
{
	m_nPosition = 1;	// on sauve l'indice dans m_nPosition

	*m_pPosition = m_pAdress[1];	// on met l'adresse associée au début de la Liste dans m_pPosition

	return m_pPosition;	// on retourne l'adresse contenue dans m_pPosition
}


template <typename Object>
int CListe<Object>::Get_nHeadPosition()
	/// retourne l'indice du premier objet de la Liste
		/// -1-> pas d'objets dans la liste
{
	int nPosition = 1;	// on indique l'indice de début (1)

	if(m_pAdress[1] == NULL)	// si il n'y a pas d'objets dans la Liste
	{
		nPosition = -1;	// on dit -1
	}
	else	// si il y a des objets
	{
		m_nPosition = 1;	// on met m_nPosition au début de la Liste
	}

	return nPosition;	// on retourne l'indice (ou -1)
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* pour la fin de la Liste */

template <typename Object>
Object** CListe<Object>::Get_aTailPosition()
	/// retourne l'adresse du dernier objet de la Liste, et sauve l'indice associé dans m_nPosition
		/// NULL-> pas d'objets dans la liste
{
	m_nPosition = m_nNbObject;	// on calcule l'indice du dernier Objet de la Liste : m_pAdress[m_nNbObject+2-2];

	*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

	return m_pPosition;	// on retourne l'adresse contenue dans m_pPosition
}


template <typename Object>
int CListe<Object>::Get_nTailPosition()
	/// retourne l'indice du dernier objet de la Liste
		/// -1-> pas d'objets dans la liste
{
	int nPosition = m_nNbObject+1;	// on indique l'indice de fin (m_nNbObject+2-1)

	if(m_pAdress[nPosition] == NULL)	// si il n'y a pas d'objets dans la Liste
	{
		nPosition = -1;	// on dit -1
	}
	else	// si il y a des objets
	{
		m_nPosition = m_nNbObject+1;	// on met m_nPosition à la fin de la Liste
	}

	return nPosition;	// on retourne l'indice (ou -1)
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Modification Tableau (incrémentation des "Positions")
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Ajout d'Objet(s) */

template <typename Object>
bool CListe<Object>::Add_anObjectATnPosition(int nPosition, Object Obj, bool bGoToNewObject, bool bBefore)
	/// ajoute une adresse au tableau à l'indice nPosition, et incrémente (ou pas) la Position actuelle
		/// false-> nPosition invalide
{
	bool bOK = false;

	if( (nPosition > 0) && (nPosition < m_nNbObject+2) )	// si nPosition est l'indice d'un Objet de la Liste : [1;m_nNbObject+2-2], ou AddTail [m_nNbObject+1]
	{
		m_nNbObject += 1;	// on ajoute 1 au nombre d'objets

		Object** pAdress = new Object*[m_nNbObject+2];	// On crée un tableau de recopie

		for(int i=0; i<nPosition; i++)	// on balaie le tableau jusqu'à nPosition
		{
			pAdress[i] = m_pAdress[i];	// on copie les valeurs de m_pAdress
		}

		pAdress[nPosition] = new Object(Obj);	// on met aObject à [nPosition] du tableau de recopie

		for(int i=nPosition+1; i<m_nNbObject+2; i++)	// on balaie la fin du tableau
		{
			pAdress[i] = m_pAdress[i-1];	// on copie les valeurs de m_pAdress
		}

		delete[] m_pAdress;	// on détruit m_pAdress
		m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie

		if(bGoToNewObject)	// si on se positionne sur l'objet ajouté
		{
			m_nPosition = nPosition;	// on incrémente m_nPosition
			*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition
		}
		else	// ou si on ne se positionne pas sur l'objet ajouté
		{
			if(bBefore)	// si ajouté avant
			{
				m_nPosition = nPosition +1;	// on incrémente m_nPosition
			}
			else	// si ajouté après
			{
				m_nPosition = nPosition -1;	// on décrémente m_nPosition
			}

			*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition
		}

		bOK = true;	// on dit que c'est good

	}
	else if(m_nNbObject == 0)	// si il n'y a pas encore d'objet dans la liste
	{
		m_nNbObject = 1;	// on dit que maintenant il y en a un

		delete[] m_pAdress;
		m_pAdress = new Object*[3];	// on cré un nouveau tableau avec 3 adresses

		m_pAdress[0] = NULL;	// NULL (début de la Liste)
		m_pAdress[1] = new Object(Obj);	// aObject
		m_pAdress[2] = NULL;	// NULL (fin de la Liste)

		m_nPosition = 1;	// on initialise m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition
	}


	return bOK;
}


template <typename Object>
bool CListe<Object>::Add_tabObjectATnPosition(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject, bool bBefore)
	/// ajoute les objets d'un tableau au tableau à partir de l'indice nPosition, et incrémente (ou pas) la Position actuelle
		/// false-> nPosition invalide ; Access error-> mauvaise entrée tableau
{
	bool bOK = true;


	for(int i=0; i<nNbObjectInTabObject; i++)	// pour tout le tableau entré
	{
		bOK = Add_anObjectATnPosition(nPosition+i, TabObject[i], bGoToNewObject, bBefore);	// on ajoute l'objet [i] du tableau à l'adresse[nPosition+i]

		if(!bOK)	// si erreur lors de l'ajout
		{
			return bOK;	// on le dit en ne finnissant pas le tableau
		}
	}


	return bOK;
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Suppression d'Objet(s) */

template <typename Object>
bool CListe<Object>::Remove_nPositionObject(int nPosition)
	/// enlève une adresse au tableau à l'indice nPosition
		/// false-> nPosition invalide (ou pas d'objets dans la Liste)
{
	bool bOK = false;

	if( (nPosition > 0) && (nPosition < m_nNbObject+1) )	// si nPosition est l'indice d'un Objet de la Liste : [1;m_nNbObject+2-2]
	{
		m_nNbObject -= 1;	// on enlève 1 au nombre d'objets

		Object** pAdress = new Object*[m_nNbObject+2];	// On crée un tableau de recopie

		for(int i=0; i<nPosition; i++)	// on balaie le tableau jusqu'à nPosition
		{
			pAdress[i] = m_pAdress[i];	// on copie les valeurs de m_pAdress
		}

		delete m_pAdress[nPosition];	// on détruit l'Object* à nPosition

		for(int i=nPosition; i<m_nNbObject+2; i++)	// on balaie la fin du tableau
		{
			pAdress[i] = m_pAdress[i+1];	// on copie les valeurs de m_pAdress
		}

		delete[] m_pAdress;	// on détruit m_pAdress
		m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie
		m_nPosition = nPosition;	// on réinitialise m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

		bOK = true;	// on dit que c'est good
	}

	return bOK;
}


template <typename Object>
bool CListe<Object>::RemoveBefore_nPositionObject(int nPosition)
	/// enlève toute les adresse avant nPosition (nPosition conservé)
		/// false-> nPosition invalide
{
	bool bOK = false;

	if( (nPosition > 0) && (nPosition < m_nNbObject+1) )	// si nPosition est l'indice d'un Objet de la Liste : [1;m_nNbObject+2-2]
	{
		for(int i=0; i<nPosition; i++)	// on parcours la partie de la Liste à supprimer (début)
		{
			delete m_pAdress[i];	// suppression des Object* de m_pAdress
		}

		m_nNbObject -= nPosition-1;	// m_nNbObject devient égal à l'ancien m_nNbObject-nPosition-1

		/* optimisation */
		int nNbCopie = m_nNbObject+2;	// nombres d'adresses à copier
		/* */

		Object** pAdress = new Object*[nNbCopie];	// On crée un tableau de recopie

		pAdress[0] = NULL;	// on met NULL pour le premier indice du tableau d'adresses

		int nDebutOld = nPosition-1;	// on indique qu'on commencera à recopier depuis nPosition-1 (for commençant à 1)
		for(int i=1; i<nNbCopie; i++)	// on balaie le tableau de recopie (et la partie de la Liste à recopier : la fin)
		{
			pAdress[i] = m_pAdress[i+nDebutOld];	// on copie les valeurs de m_pAdress depuis nPosition
		}

		delete[] m_pAdress;	// on détruit m_pAdress
		m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie
		m_nPosition = 1;	// on réinitialise m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

		bOK = true;	// on dit que c'est good
	}

	return bOK;
}


template <typename Object>
bool CListe<Object>::RemoveAfter_nPositionObject(int nPosition)
	/// enlève toute les adresse après nPosition (nPosition conservé)
		/// false-> nPosition invalide
{
	bool bOK = false;

	if( (nPosition > 0) && (nPosition < m_nNbObject+1) )	// si nPosition est l'indice d'un Objet de la Liste : [1;m_nNbObject+2-2]
	{
		Object** pAdress = new Object*[nPosition+2];	// On crée un tableau de recopie

		int nNbCopie = nPosition+1;	// nombres d'adresses à copier
		for(int i=0; i<nNbCopie; i++)	// on balaie le tableau jusqu'à nPosition (partie de la Liste à copier)
		{
			pAdress[i] = m_pAdress[i];	// on copie les valeurs de m_pAdress
		}

		pAdress[nNbCopie] = NULL;	// on met NULL au dernier indice du tableau d'adresses

		for(int i=nNbCopie+1; i<m_nNbObject+2; i++)	// on parcours la partie de la Liste à supprimer (fin)
		{
			delete m_pAdress[i];	// on delete les Object* de m_pAdress
		}

		delete[] m_pAdress;	// on détruit m_pAdress
		m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie
		m_nNbObject = nPosition;	// m_nNbObject devient égal à nPosition
		m_nPosition = nPosition;	// on réinitialise m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

		bOK = true;	// on dit que c'est good
	}

	return bOK;
}


template <typename Object>
bool CListe<Object>::RemoveBetween_nPositionsObjects(int nAfterPosition, int nBeforePosition)
	/// enlève toute les adresse à l'intérieur de ]nAfterPosition;nBeforePosition[ (nPositions conservées)
		/// false-> nPositions invalide
{
	bool bOK = false;


	if(nAfterPosition < nBeforePosition)	// si il y a quelque chose à supprimer (et que l'ordre des nPositions est respecté)
	{
		if(	( (nAfterPosition > 0) && (nAfterPosition < m_nNbObject+1) )	// si les nPositions sont les indices d'un Objet de la Liste : [1;m_nNbObject+2-2]
			&& ( (nBeforePosition > 0) && (nBeforePosition < m_nNbObject+1) ) )
		{
			int nNbObject = m_nNbObject - nBeforePosition + nAfterPosition +1;	// calcul du nouveau nombre d'objets

			Object** pAdress = new Object*[nNbObject+2];	// création d'un tableau de recopie

			int nCopieTill = nAfterPosition+1;	// calcul du nombre d'adresse à copier jusqu'à nAfterPosition

			for(int i=0; i<nCopieTill; i++)	// parcours du début du tableau de recopie
			{
				pAdress[i] = m_pAdress[i];	// recopie des adresses
			}

			/* optimisation */
			int nCopieEnd = nNbObject+2;
			/* */

			for(int i=nCopieTill; i<nBeforePosition; i++)	// on parcours la partie de la Liste à supprimer (le milieu)
			{
				delete m_pAdress[i];	// on détruit les Object* de m_pAdress
			}

			int nOffset = nBeforePosition - nAfterPosition -1;	// calcul des cases de m_pAdress à zapper : nBeforePosition-nAfterPosition-1 (for commençant à nAfterPosition+1)

			for(int i=nCopieTill; i<nCopieEnd; i++)	// parcours de la fin du tableau de recopie
			{
				pAdress[i] = m_pAdress[i+nOffset];	// recopie des adresses [i+nBeforePosition-1] (for commençant à nAfterPosition+1)
			}

			delete[] m_pAdress;	// on détruit m_pAdress
			m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie
			m_nNbObject = nNbObject;	// on lui donne le nouveu nombre d'objets
			m_nPosition = 0;	// on réinitialise m_nPosition
			*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

			bOK = true;	// on dit que c'est good
		}
	}


	return bOK;
}


template <typename Object>
bool CListe<Object>::RemoveOutside_nPositionsObjects(int nAfterPosition, int nBeforePosition)
	/// enlève toute les adresse à l'extérieur de [nAfterPosition;nBeforePosition] (nPositions conservées)
		/// false-> nPositions invalide
{
	bool bOK = false;


	if(nAfterPosition < nBeforePosition)	// si il y a quelque chose à supprimer (et que l'ordre des nPositions est respecté)
	{
		if(	( (nAfterPosition > 0) && (nAfterPosition < m_nNbObject+1) )	// si les nPositions sont les indices d'un Objet de la Liste : [1;m_nNbObject+2-2]
			&& ( (nBeforePosition > 0) && (nBeforePosition < m_nNbObject+1) ) )
		{
			int nNbObject = nBeforePosition - nAfterPosition +1;	// calcul du nouveau nombre d'objets

			Object** pAdress = new Object*[nNbObject+2];	// création d'un tableau de recopie

			for(int i=0; i<nAfterPosition; i++)	// parcours la première partie de la Liste à supprimer (le début)
			{
				delete m_pAdress[i];	// délete le Object* de m_pAdress
			}

			int nOffset = nAfterPosition-1;	// calcul des cases de m_pAdress à zapper : nAfterPosition-1 (for commençant à 1)

			pAdress[0] = NULL;	// première adresse = NULL
			for(int i=1; i<=nNbObject; i++)	// parcours du tableau de recopie
			{
				pAdress[i] = m_pAdress[i+nOffset];	// copie des adresses [i+nAfterPosition-1] (for commençant à 1)
			}
			pAdress[nNbObject+1] = NULL;	// dernière adresse = NULL

			for(int i=nBeforePosition+1; i<m_nNbObject+2; i++)	// parcours la deuxième partie de la Liste à supprimer (la fin)
			{
				delete m_pAdress[i];	// délete le Object* de m_pAdress
			}

			delete[] m_pAdress;	// on détruit m_pAdress
			m_pAdress = pAdress;	// on lui donne l'adresse du tableau de recopie
			m_nNbObject = nNbObject;	// on lui donne le nouveu nombre d'objets
			m_nPosition = 0;	// on réinitialise m_nPosition
			*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

			bOK = true;	// on dit que c'est good
		}
	}


	return bOK;
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Récupération d'Objet
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------------------
				// Récupération simple
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Mode Liste */

template <typename Object>
Object CListe<Object>::Get_At(Object* aPosition)
	/// retourne l'objet contenu à l'adresse aPosition
		/// Access error-> adresse non viable
{
	Object ObjetActuel;
	int nPos = -1;

	if(aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,true); // recherche de l'indice de aPosition, et on le sauve dans m_nPosition
		}
	}

	ObjetActuel = *(m_pAdress[nPos]);	// récupération de la valeur de l'objet associé à aPosition


	return ObjetActuel;	// retourne l'objet
}


template <typename Object>
Object CListe<Object>::Get_At(int nPosition)
	/// retourne le nPosition° objet de la Liste [nPosition]
		/// Access error-> indice non viable
{
	return *(m_pAdress[nPosition]);	// récupération de l'objet associé à l'indice nPosition
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Mode Tableau */

template <typename Object>
Object CListe<Object>::operator[] (int nPosition)
	/// retourne le nPosition+1° objet de la Liste [nPosition+1]
		/// Access error-> indice non viable
{
	return *(m_pAdress[nPosition+1]);	// récupération de l'objet associé à l'indice nPosition+1
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Récupération et incrémentation
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
Object CListe<Object>::Get_Next(Object** aPosition)
	/// retourne l'objet contenu à l'adresse aPosition, et passe à l'adresse suivante
		/// Access error-> adresse non viable
{
	Object ObjetActuel;
	int nPos = -1;

	if(aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == *aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(*aPosition,true); // recherche de l'indice de aPosition, et on le sauve dans m_nPosition
		}
	}

	ObjetActuel = *(m_pAdress[nPos]);	// récupération et castage de l'adresse de l'objet associé

	m_nPosition += 1;	// on incrémente m_nPosition
	*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

	aPosition = m_pPosition;	// modification de aPosition avec l'adresse suivante


	return ObjetActuel;	// retourne l'objet
}


template <typename Object>
Object CListe<Object>::Get_Prev(Object** aPosition)
	/// retourne l'objet contenu à l'adresse aPosition, et passe à l'adresse précedente
		/// Access error-> adresse non viable
{
	Object ObjetActuel;

	int nPos = -1;

	if(aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == *aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(*aPosition,true); // recherche de l'indice de aPosition
		}
	}

	ObjetActuel = *m_pAdress[nPos];	// récupération et castage de l'adresse de l'objet associé

	m_nPosition -= 1;	// on décrémente m_nPosition
	*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

	aPosition = m_pPosition;	// modification de aPosition avec l'adresse suivante


	return ObjetActuel;	// retourne l'objet
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Modification d'Objet
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------------------
				// Modification simple
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
bool CListe<Object>::Set_At(Object* aPosition, Object Obj)
	/// remplace l'objet à l'adresse aPosition par Obj
		/// false-> addresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,true); // recherche de l'indice de aPosition, et on le sauve dans m_nPosition

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		*m_pAdress[nPos] = Obj;	// on met l'adresse du nouvelle objet à la bonne place
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Set_At(int nPosition, Object Obj)
	/// remplace l'objet à l'indice nPosition par Obj [1;m_nNbObject]
		/// false-> indice non viable
{
	bool bOK = false;

	if( (nPosition > 0) && (nPosition < m_nNbObject+1) )	// si indice viable ]0;m_nNbObject+2-1[
	{
		bOK = true;	// on le dit
	}


	if(bOK)	// si indice viable
	{
		*m_pAdress[nPosition] = Obj;	// on met l'adresse du nouvelle objet à la bonne place
	}


	return bOK;	// retourne l'état de la modification
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Modification et incrémentation
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
bool CListe<Object>::Set_Next(Object** aPosition, Object Obj)
	/// remplace l'objet à l'adresse aPosition par Obj, et passe à l'adresse suivante
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(*aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == *aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(*aPosition,true); // recherche de l'indice de aPosition, et on le sauve dans m_nPosition

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		*m_pAdress[nPos] = Obj;	// on met l'adresse du nouvelle objet à la bonne place

		m_nPosition += 1;	// on incrémente m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

		aPosition = m_pPosition;	// modification de aPosition avec l'adresse suivante
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Set_Prev(Object** aPosition, Object Obj)
	/// remplace l'objet à l'adresse aPosition par Obj, et passe à l'adresse précedente
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(*aPosition != NULL)	// si aPosition non NULL
	{
		if(m_pAdress[m_nPosition] == *aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(*aPosition,true); // recherche de l'indice de aPosition, et on le sauve dans m_nPosition

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		*m_pAdress[nPos] = Obj;	// on met l'adresse du nouvelle objet à la bonne place

		m_nPosition -= 1;	// on décrémente m_nPosition
		*m_pPosition = m_pAdress[m_nPosition];	// on met l'adresse associée à la fin de la Liste dans m_pPosition

		aPosition = m_pPosition;	// modification de aPosition avec l'adresse suivante
	}


	return bOK;	// retourne l'état de la modification
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Ajouter un Objet (incrémentation des "Positions")
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------------------
				// Ajout aux extrémitées
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
void CListe<Object>::Add_Head(Object Obj, bool bGoToNewObject)
	/// ajoute un objet au début de la Liste, et incrémente (ou pas) la Position actuelle
{
	Add_anObjectATnPosition(1, Obj, bGoToNewObject, true);	// ajoute l'adresse de Obj à l'indice [1]
}


template <typename Object>
void CListe<Object>::Add_Tail(Object Obj, bool bGoToNewObject)
	/// ajoute un objet à la fin de la Liste, et incrémente (ou pas) la Position actuelle
{
	Add_anObjectATnPosition(m_nNbObject+1, Obj, bGoToNewObject, false);	// ajoute l'adresse de Obj à l'indice [m_nNbObject+2-1]
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Ajout à une place spécifique
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Avant un Objet */

template <typename Object>
bool CListe<Object>::Add_Before(Object* aPosition, Object Obj, bool bGoToNewObject)
	/// Ajoute l'objet Obj avant l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = Add_anObjectATnPosition(nPos, Obj, bGoToNewObject, true);	// on met l'adresse du nouvel objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Add_Before(int nPosition, Object Obj, bool bGoToNewObject)
	/// Ajoute l'objet Obj avant l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> indice non viable
{
	return Add_anObjectATnPosition(nPosition, Obj, bGoToNewObject, true);	// on met l'adresse du nouvel objet à l'indice nPosition, et on retourne l'état de la modification
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Après un Objet */

template <typename Object>
bool CListe<Object>::Add_After(Object* aPosition, Object Obj, bool bGoToNewObject)
	/// Ajoute l'objet Obj après l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = Add_anObjectATnPosition(nPos+1, Obj, bGoToNewObject, false);	// on met l'adresse du nouvel objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Add_After(int nPosition, Object Obj, bool bGoToNewObject)
	/// Ajoute l'objet Obj après l'objet situé à aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> indice non viable
{
	return Add_anObjectATnPosition(nPosition+1, Obj, bGoToNewObject, false);	// on met l'adresse du nouvel objet à l'indice nPosition, et on retourne l'état de la modification
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Ajout d'un tableau d'Objet
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Aux extrémitées */

template <typename Object>
bool CListe<Object>::Add_Head(Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau au début de la Liste, et incrémente (ou pas) la Position actuelle
		/// false-> aPosition invalide ; Access error-> mauvaise entrée tableau
{
	return Add_tabObjectATnPosition(1, TabObject, nNbObjectInTabObject, bGoToNewObject, true);	// ajoute le tableau au le début de la Liste [1], et dit comment ça s'est passé
}


template <typename Object>
bool CListe<Object>::Add_Tail(Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau à la fin de la Liste, et incrémente (ou pas) la Position actuelle
		/// false-> nPosition invalide ; Access error-> mauvaise entrée tableau
{
	return Add_tabObjectATnPosition(m_nNbObject+1, TabObject, nNbObjectInTabObject, bGoToNewObject, false);	// ajoute le tableau à la début de la Liste [m_nNbObject+1], et dit comment ça s'est passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Avant un Objet */

template <typename Object>
bool CListe<Object>::Add_Before(Object* aPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau avant l'adresse aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> aPosition invalide ; Access error-> mauvaise entrée tableau
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = Add_tabObjectATnPosition(nPos, TabObject, nNbObjectInTabObject, bGoToNewObject, true);	// ajoute le tableau à partir de l'indice de aPosition [nPos], et dit comment ça s'est passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Add_Before(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau avant l'indice nPosition, et incrémente (ou pas) la Position actuelle
		/// false-> nPosition invalide ; Access error-> mauvaise entrée tableau
{
	return Add_tabObjectATnPosition(nPosition, TabObject, nNbObjectInTabObject, bGoToNewObject, true);	// ajoute le tableau à partir de l'indice [nPosition], et dit comment ça s'est passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* Après un Objet */

template <typename Object>
bool CListe<Object>::Add_After(Object* aPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau après l'adresse aPosition, et incrémente (ou pas) la Position actuelle
		/// false-> aPosition invalide ; Access error-> mauvaise entrée tableau
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = Add_tabObjectATnPosition(nPos+1, TabObject, nNbObjectInTabObject, bGoToNewObject, false);	// ajoute le tableau à partir de l'indice de aPosition [nPos+1], et dit comment ça s'est passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Add_After(int nPosition, Object* TabObject, int nNbObjectInTabObject, bool bGoToNewObject)
	/// ajoute les objets d'un tableau au tableau après l'indice nPosition, et incrémente (ou pas) la Position actuelle
		/// false-> nPosition invalide ; Access error-> mauvaise entrée tableau
{
	return Add_tabObjectATnPosition(nPosition+1, TabObject, nNbObjectInTabObject, bGoToNewObject, false);	// ajoute le tableau à partir de l'indice [nPosition+1], et dit comment ça s'est passé
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Retirer un Objet (incrémentation des "Positions")
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------------------
				// Retrait aux extrémitées
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
bool CListe<Object>::Remove_Head()
	/// retire le premier Objet de la Liste, et décrémente la Position actuelle
		/// false-> pas d'objet dans la Liste
{
	return Remove_nPositionObject(1);	// on retire l'objet du premier indice de la Liste [1], et on dit si ça s'est bien passé
}


template <typename Object>
bool CListe<Object>::Remove_Tail()
	/// retire le dernier Objet de la Liste, et décrémente la Position actuelle
		/// false-> pas d'objet dans la Liste
{
	return Remove_nPositionObject(m_nNbObject);	// on retire l'objet du dernier indice de la Liste [m_nNbObject], et on dit si ça s'est bien passé
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Retrait à une place spécifique
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
bool CListe<Object>::Remove_At(Object* aPosition)
	/// retire l'Objet à l'adresse aPosition, et décrémente la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = Remove_nPositionObject(nPos);	// on retire l'objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::Remove_At(int nPosition)
	/// retire l'Objet à l'indice nPosition, et décrémente la Position actuelle
		/// false-> indice non viable
{
	return Remove_nPositionObject(nPosition);	// on retire l'objet à l'indice nPosition, et on dit si ça s'est bien passé
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Retrait d'une partie de la Liste
	//-------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------------
					/* avant un Objet (Objet conservé) */

template <typename Object>
bool CListe<Object>::RemoveAll_Before(Object* aPosition)
	/// retire tout les objets avant l'Objet à l'adresse aPosition, et décrémente la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = RemoveBefore_nPositionObject(nPos);	// on retire tout les objets avant l'objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}

template <typename Object>
bool CListe<Object>::RemoveAll_Before(int nPosition)
	/// retire tout les objets avant l'Objet à l'indice nPosition, et décrémente la Position actuelle
		/// false-> indice non viable
{
	return RemoveBefore_nPositionObject(nPosition);	// on retire tout les objets avant l'objet à l'indice nPosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* jusqu'à un Objet (Objet détruit) */

template <typename Object>
bool CListe<Object>::RemoveAll_To(Object* aPosition)
	/// retire tout les objets jusqu'à l'Objet à l'adresse aPosition, et décrémente la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = RemoveBefore_nPositionObject(nPos-1);	// on retire tout les objets jusqu'à l'objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}

template <typename Object>
bool CListe<Object>::RemoveAll_To(int nPosition)
	/// retire tout les objets jusqu'à l'Objet à l'indice nPosition, et décrémente la Position actuelle
		/// false-> indice non viable
{
	return RemoveBefore_nPositionObject(nPosition-1);	// on retire tout les objets jusqu'à l'objet à l'indice nPosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* après un Objet (Objet conservé) */

template <typename Object>
bool CListe<Object>::RemoveAll_After(Object* aPosition)
	/// retire tout les objets après l'Objet à l'adresse aPosition, et décrémente la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = RemoveAfter_nPositionObject(nPos);	// on retire tout les objets après l'objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}

template <typename Object>
bool CListe<Object>::RemoveAll_After(int nPosition)
	/// retire tout les objets après l'Objet à l'indice nPosition, et décrémente la Position actuelle
		/// false-> indice non viable
{
	return RemoveAfter_nPositionObject(nPosition);	// on retire tout les objets après l'objet à l'indice nPosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* depuis un Objet (Objet détruit) */

template <typename Object>
bool CListe<Object>::RemoveAll_From(Object* aPosition)
	/// retire tout les objets depuis l'Objet à l'adresse aPosition, et décrémente la Position actuelle
		/// false-> adresse non viable
{
	bool bOK = true;


	int nPos;

	if(aPosition != NULL)	// si aPosition est une vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aPosition)	// si on a déja l'indice de cette adresse
		{
			nPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nPos = Get_nPosition(aPosition,false); // recherche de l'indice de aPosition, et on le met dans nPos

			if(nPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si aPosition est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresse viable
	{
		bOK = RemoveAfter_nPositionObject(nPos+1);	// on retire tout les objets depuis l'objet à l'indice de aPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}

template <typename Object>
bool CListe<Object>::RemoveAll_From(int nPosition)
	/// retire tout les objets depuis l'Objet à l'indice nPosition, et décrémente la Position actuelle
		/// false-> indice non viable
{
	return RemoveAfter_nPositionObject(nPosition+1);	// on retire tout les objets depuis l'objet à l'indice nPosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* entre 2 Objets (Objets conservés) */

template <typename Object>
bool CListe<Object>::RemoveAll_Between(Object* aAfterPosition, Object* aBeforePosition)
	/// retire tout les objets entre les Objets aux l'adresses aAfterPosition et aBeforePosition, et décrémente la Position actuelle
		/// false-> adresses non viable
{
	bool bOK = true;


	int nAPos;
	int nBPos;

	if( (aAfterPosition != NULL) && (aBeforePosition != NULL) )	// si les aPosition sont de vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aAfterPosition)	// si on a déja l'indice de la première adresse
		{
			nAPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nAPos = Get_nPosition(aAfterPosition,false); // recherche de l'indice de aAfterPosition, et on le met dans nAPos

			if(nAPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}

		if(m_pAdress[m_nPosition] == aBeforePosition)	// si on a déja l'indice de la deuxième adresse
		{
			nBPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nBPos = Get_nPosition(aBeforePosition,false); // recherche de l'indice de aBeforePosition, et on le met dans nBPos

			if(nBPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si l'une des adresse (ou les deux) est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresses viable
	{
		bOK = RemoveBetween_nPositionsObjects(nAPos,nBPos);	// on retire tout les objets entre l'objet à l'indice nAPos et l'objet à l'indice nBPos, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::RemoveAll_Between(int nAfterPosition, int nBeforePosition)
	/// retire tout les objets entre les Objets d'indices nAfterPosition et nBeforePosition, et décrémente la Position actuelle
		/// false-> indices non viable
{
	return RemoveBetween_nPositionsObjects(nAfterPosition,nBeforePosition);	// on retire tout les objets entre l'objet à l'indice nAfterPosition et l'objet à l'indice nBeforePosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* depuis un Objet jusqu'à un autre Objet (Objets détruits) */

template <typename Object>
bool CListe<Object>::RemoveAll_FromTo(Object* aFromPosition, Object* aToPosition)
	/// retire tout les objets depuis l'Objet à l'adresse aFromPosition, jusqu'à l'Objet à l'adresse aToPosition, et décrémente la Position actuelle
		/// false-> adresses non viable
{
	bool bOK = true;


	int nFPos;
	int nTPos;

	if( (aFromPosition != NULL) && (aToPosition != NULL) )	// si les aPosition sont de vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aFromPosition)	// si on a déja l'indice de la première adresse
		{
			nFPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nFPos = Get_nPosition(aFromPosition,false); // recherche de l'indice de aFromPosition, et on le met dans nFPos

			if(nFPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}

		if(m_pAdress[m_nPosition] == aToPosition)	// si on a déja l'indice de la deuxième adresse
		{
			nTPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nTPos = Get_nPosition(aToPosition,false); // recherche de l'indice de aToPosition, et on le met dans nTPos

			if(nTPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si l'une des adresse (ou les deux) est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresses viable
	{
		bOK = RemoveBetween_nPositionsObjects(nFPos-1,nTPos+1);	// on retire tout les objets entre l'objet à l'indice nFPos-1 et l'objet à l'indice nTPos+1, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::RemoveAll_FromTo(int nFromPosition, int nToPosition)
	/// retire tout les objets depuis l'Objet à l'indice nFromPosition, jusqu'à l'Objet à l'indice nToPosition, et décrémente la Position actuelle
		/// false-> indices non viable
{
	return RemoveBetween_nPositionsObjects(nFromPosition-1,nToPosition+1);	// on retire tout les objets entre l'objet à l'indice nFromPosition-1 et l'objet à l'indice nToPosition+1, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* à l'extérieur de 2 Objets (Objets conservés) */

template <typename Object>
bool CListe<Object>::RemoveAll_Outside(Object* aBeforePosition, Object* aAfterPosition)
	/// retire tout les objets à l'extérieur des Objets aux l'adresses aBeforePosition et aAfterPosition, et décrémente la Position actuelle
		/// false-> adresses non viable
{
	bool bOK = true;


	int nBPos;
	int nAPos;

	if( (aAfterPosition != NULL) && (aBeforePosition != NULL) )	// si les aPosition sont de vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aBeforePosition)	// si on a déja l'indice de la deuxième adresse
		{
			nBPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nBPos = Get_nPosition(aBeforePosition,false); // recherche de l'indice de aBeforePosition, et on le met dans nBPos

			if(nBPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}

		if(m_pAdress[m_nPosition] == aAfterPosition)	// si on a déja l'indice de la première adresse
		{
			nAPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nAPos = Get_nPosition(aAfterPosition,false); // recherche de l'indice de aAfterPosition, et on le met dans nAPos

			if(nAPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si l'une des adresse (ou les deux) est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresses viable
	{
		bOK = RemoveOutside_nPositionsObjects(nBPos,nAPos);	// on retire tout les objets à l'extérieur des objets à l'indice nBeforePosition et à l'indice nAfterPosition, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::RemoveAll_Outside(int nBeforePosition, int nAfterPosition)
	/// retire tout les objets à l'extérieur des Objets d'indices nBeforePosition et nAfterPosition, et décrémente la Position actuelle
		/// false-> indices non viable
{
	return RemoveOutside_nPositionsObjects(nBeforePosition,nAfterPosition);	// on retire tout les objets à l'extérieur des objets à l'indice nBeforePosition et à l'indice nAfterPosition, et on dit si ça s'est bien passé
}


		//-------------------------------------------------------------------------------------------------------------------------------
					/* jusqu'à un Objet et depuis un autre Objet (Objets détruits) */

template <typename Object>
bool CListe<Object>::RemoveAll_ToAndFrom(Object* aToPosition, Object* aFromPosition)
	/// retire tout les objets jusqu'à l'objet à l'adrresse aToPosition et tous les objets depuis l'Objet à l'adresse aFromPosition, et décrémente la Position actuelle
		/// false-> adresses non viable
{
	bool bOK = true;


	int nTPos;
	int nFPos;

	if( (aToPosition != NULL) && (aFromPosition != NULL) )	// si les aPosition sont de vraie adresse (non NULL)
	{
		if(m_pAdress[m_nPosition] == aToPosition)	// si on a déja l'indice de la deuxième adresse
		{
			nTPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nTPos = Get_nPosition(aToPosition,false); // recherche de l'indice de aToPosition, et on le met dans nTPos

			if(nTPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}

		if(m_pAdress[m_nPosition] == aFromPosition)	// si on a déja l'indice de la première adresse
		{
			nFPos = m_nPosition;	// on le récupère
		}
		else	// sinon
		{
			nFPos = Get_nPosition(aFromPosition,false); // recherche de l'indice de aFromPosition, et on le met dans nFPos

			if(nFPos == -1)	// si Adresse introuvable
			{
				bOK = false;	// on le dit
			}
		}
	}
	else	// si l'une des adresse (ou les deux) est NULL
	{
		bOK = false;	// on le dit
	}


	if(bOK)	// si adresses viable
	{
		bOK = RemoveOutside_nPositionsObjects(nTPos+1,nFPos-1);	// on retire tout les objets à l'extérieur des objets à l'indice nTPos+1 et à l'indice nFPos-1, et on dit si ça s'est bien passé
	}


	return bOK;	// retourne l'état de la modification
}


template <typename Object>
bool CListe<Object>::RemoveAll_ToAndFrom(int nToPosition, int nFromPosition)
	/// retire tout les objets jusqu'à l'objet d'indice nToPosition et tous les objets depuis l'Objet d'indice nFromPosition, et décrémente la Position actuelle
		/// false-> indices non viable
{
	return RemoveOutside_nPositionsObjects(nToPosition+1,nFromPosition-1);	// on retire tout les objets à l'extérieur des objets à l'indice nToPosition+1 et à l'indice nFromPosition-1, et on dit si ça s'est bien passé
}



	//-------------------------------------------------------------------------------------------------------------------------------
				// Retrait de toute la Liste
	//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
void CListe<Object>::RemoveAll()
	/// virginise la Liste et la Position Actuelle
{
	if(m_pAdress != NULL)	// suppression du tableau d'adresses
		delete[] m_pAdress;
	m_pAdress = NULL;

	m_nNbObject = 0;	// on dit qu'il n'y a pas d'Objets dans la Liste
	m_nPosition = 0;	// ni de Position enregistrée
	*m_pPosition = NULL;	// on dit qu'il n'y a pas de Position en cours

	m_pAdress = new Object*[2];	// on recrée le tableau d'adresses
	m_pAdress[0] = NULL;	// avec deux adresses NULL
	m_pAdress[1] = NULL;
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
			// Accès en lecture
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------


template <typename Object>
int CListe<Object>::Get_m_nNbObject()
/// return le nombre d'objets de la Liste (taille du tableau-2)
{
	return m_nNbObject;
}

template <typename Object>
int CListe<Object>::Get_m_nPosition()
	/// return l'indice de la position actuellement utilisée
{
	return m_nPosition;
}

template <typename Object>
Object** CListe<Object>::Get_aCurrentPosition()
	/// return l'adresse de la position actuellement utilisée
{
	Object** pCurrent = new Object*;

	*pCurrent = *m_pPosition;

	return pCurrent;
}






//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------






















