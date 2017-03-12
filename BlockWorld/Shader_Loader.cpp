#include "Shader_Loader.h"
#include <fstream>
#include <sstream>
#include <stdexcpt.h>

namespace Shader
{
	GLuint loadShader(const std::string & vertexShaderFile, const std::string & fragmentShaderFile)
	{
		//on appelle la methode pour ouvrir les fichiers
		auto vertexSource = getSource(vertexShaderFile);
		auto fragmentSource = getSource(fragmentShaderFile);

		//on appelle la compilation du code d'abord pour le shader de sommets, puis de pixels
		auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
		auto fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

		//on appelle la fonction createProgram (seul un program peut etre execute par la carte graphique)
		auto programID = createProgram(vertexShaderID, fragmentShaderID);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		//on retourne l'ID du program pour pouvoir l'utiliser
		return programID;
	}

	std::string getSource(const std::string & sourceFile)
	{
		//on ouvre le fichier
		std::ifstream inFile("Data/Shaders/" + sourceFile + ".glsl");
		std::string source;
		std::stringstream stringStream;

		//on verifie qu'il s'est bien ouvert
		if (!inFile.is_open())
		{
			throw std::runtime_error("Could not open file: " + sourceFile);
		}

		//on recupere grace au flux l'intégralite du fichier
		stringStream << inFile.rdbuf();

		//on le convertit en string
		source = stringStream.str();

		//on le renvoie
		return source;
	}

	GLuint compileShader(const GLchar * source, GLenum type)
	{
		//on crée le shader avec le type (frag ou vert)
		auto ID = glCreateShader(type);

		//on envoie à notre shader courant le code de notre fichier
		glShaderSource(ID, 1, &source, nullptr);

		//puis on le compile
		glCompileShader(ID);

		GLint isSuccess;
		GLchar infoLog[GL_INFO_LOG_LENGTH];

		//on recupere l'état de la compilation
		glGetShaderiv(ID, GL_COMPILE_STATUS, &isSuccess);

		//Si la compilation n'a pas fonctionne, 
		if (!isSuccess)
		{
			glGetShaderInfoLog(ID, GL_INFO_LOG_LENGTH, nullptr, infoLog);
			throw std::runtime_error("Error compiling shader: " + std::string(infoLog));
		}

		//retourne l'ID du shader
		return ID;
	}
	
	GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		//on cree un program
		auto ID = glCreateProgram();

		//on lui attache nos deux codes precompiles.
		glAttachShader(ID, vertexShaderID);
		glAttachShader(ID, fragmentShaderID);

		//on link les deux fichiers vert et frag entre eux
		glLinkProgram(ID);

		GLint isSuccess;
		GLchar infoLog[GL_INFO_LOG_LENGTH];

		//on recupere l'état du link
		glGetShaderiv(ID, GL_LINK_STATUS, &isSuccess);

		//Si le link n'a pas fonctionne
		if (!isSuccess)
		{
			glGetShaderInfoLog(ID, GL_INFO_LOG_LENGTH, nullptr, infoLog);
			throw std::runtime_error("Error link shader: " + std::string(infoLog));
		}

		return ID;
	}
}