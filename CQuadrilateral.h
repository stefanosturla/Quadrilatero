/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/


#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include<iostream>

using namespace std;

/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
class Quadrilateral {
protected: /*visibili all'interno dell'ereditarietà
mentre all'esterno è come se sono private*/

	float sides[4];
	
	void SetSides(float s1, float s2, float s3, float s4); 
	/*non voglio che dall'esterno chiunque possa mettere i lati come
	vuole, ma questa funzione la possono usare i quadrilateri che la 
	ereditano, in modo che possono settare i dati secondo le regole
	specifiche (del rombo, quadrato, rettangolo...)


public:  /*visibili all'esterno*/

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();
	Quadrilateral(const Quadrilateral &o);
	virtual ~Quadrilateral();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Quadrilateral& operator=(const Quadrilateral &o); 
	bool operator==(const Quadrilateral &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Quadrilateral &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	/*c'è solo il perimetro: perchè il perimetro è sempre
	uguale per qualunque quadrilatero, mentre l'area cambia da
	quadrilatero a quadrilatero*/
	void GetSides(float &s0, float &s1, float &s2, float &s3);
	/*questa invece è pubblica perchè non crea problemi*/
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif