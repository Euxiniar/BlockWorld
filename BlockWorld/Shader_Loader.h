#pragma once
#include <GL\glew.h>
#include <string>

namespace Shader
{
	GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	std::string getSource(const std::string& sourceFile);
	GLuint compileShader(const GLchar* source, GLenum type);
	GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
}