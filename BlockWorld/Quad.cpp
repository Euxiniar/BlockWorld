#include "Quad.h"
#include <vector>
#include "Texture_Atlas.h"

std::vector<GLfloat> vertexPositions =
{
	//Back
	1, 0, 0,
	0, 0, 0,
	0, 1, 0,
	1, 1, 0,

	//Right-Side
	1, 0, 1,
	1, 0, 0,
	1, 1, 0,
	1, 1, 1,

	//Front
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1,

	//Left
	0, 0, 0,
	0, 0, 1,
	0, 1, 1,
	0, 1, 0,

	//Top
	0, 1, 1,
	1, 1, 1,
	1, 1, 0,
	0, 1, 0,

	//Bottom
	0, 0, 0,
	1, 0, 0,
	1, 0, 1,
	0, 0, 1
};


std::vector<GLuint> indices =
{
	0, 1, 2,
	2, 3, 0,

	4, 5, 6,
	6, 7, 4,

	8, 9, 10,
	10, 11, 8,

	12, 13, 14,
	14, 15, 12,

	16, 17, 18,
	18, 19, 16,

	20, 21, 22,
	22, 23, 20
};

////x, y, z
//std::vector<GLfloat> vertexPositions =
//{
//	//Back
//	1, 0, 0,
//	0, 0, 0,
//	0, 1, 0,
//	1, 1, 0,
//
//	//Front
//	0, 0, 1,
//	1, 0, 1,
//	1, 1, 1,
//	0, 1, 1,
//};
//
//
//std::vector<GLuint> indices =
//{
//	//back
//	0, 1, 2,
//	2, 3, 0,
//
//	//left
//	1, 2, 7,
//	7, 4, 1,
//	
//	//front
//	7, 6, 4,
//	4, 5, 6,
//
//	//right
//	6, 5, 0,
//	0, 3, 6,
//
//	//top
//	7, 2, 3,
//	3, 6, 7,
//
//	//bottom
//	4, 5, 0,
//	0, 1, 4,
//};

std::vector<GLfloat> textureCoords;

void insertTextureCoords(const std::vector<GLfloat>& coords)
{
	//on se positionne à la derniere place du tableau (qui est vide au début) et on rempli de coordonnees)
	textureCoords.insert(textureCoords.end(), coords.begin(), coords.end());
}


Quad::Quad(Texture::Texture_Atlas& textureAtlas)
{
	//on crée le tableau de textures
	insertTextureCoords(textureAtlas.getTextureCoords({ 1, 0 }));
	insertTextureCoords(textureAtlas.getTextureCoords({ 1, 0 }));
	insertTextureCoords(textureAtlas.getTextureCoords({ 1, 0 }));
	insertTextureCoords(textureAtlas.getTextureCoords({ 1, 0 }));
	insertTextureCoords(textureAtlas.getTextureCoords({ 0, 0 }));
	insertTextureCoords(textureAtlas.getTextureCoords({ 2, 0 }));

	m_model.addData(vertexPositions, textureCoords, indices);
}

const Model& Quad::getModel() const
{
	return m_model;
}