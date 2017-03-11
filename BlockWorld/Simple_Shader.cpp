#include "Simple_Shader.h"


namespace Shader
{
	Simple_Shader::Simple_Shader()
		: Shader_Program("Simple_Vertex", "Simple_Fragment")
	{
	}

	void Simple_Shader::setTime(float time)
	{
	}

	void Simple_Shader::setViewMatrix(const Matrix4 & matrix)
	{
	}

	void Simple_Shader::setModelMatrix(const Matrix4 & matrix)
	{
	}

	void Simple_Shader::setProjMatrix(const Matrix4 & matrix)
	{
	}

	void Simple_Shader::getUniformLocations()
	{
	}
}