#include "Shader_Program.h"
#include "Shader_Loader.h"


namespace Shader
{
	Shader_Program::Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
		: m_programID(Shader::loadShader(vertexShaderFile, fragmentShaderFile))
	{
	}

	Shader_Program::~Shader_Program()
	{
		glDeleteProgram(m_programID);
	}

	void Shader_Program::bind()
	{
		//le program doit etre selectionne pour etre utilise
		glUseProgram(m_programID);
	}

	void Shader_Program::unbind()
	{
		//on déselectionne le program
		glUseProgram(0);
	}

	GLuint Shader_Program::getID() const
	{
		//on retourne l'ID du programme genere avec loadShader
		return m_programID;
	}

	void Shader_Program::loadFloat(GLuint location, float value)
	{
		glUniform1f(location, value);
	}

	void Shader_Program::loadVector2(GLuint location, const Vector2 & vector)
	{
		glUniform2f(location, vector.x, vector.y);
	}

	void Shader_Program::loadMatrix4(GLuint location, const Matrix4 & matrix)
	{
		//on charge la matrice dans la variable du shader selectionnee
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}