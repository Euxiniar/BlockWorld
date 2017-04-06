#pragma once
#include "../Rules/Glm_Common.h"
#include <GL\glew.h>
#include <string>

namespace Shader
{
	class Shader_Program
	{
	public:
		Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
		~Shader_Program();
		void bind();
		void unbind();

	protected:
		virtual void getUniformLocations() = 0;
		GLuint getID() const;

		void loadFloat(GLuint location, float value);
		void loadVector2(GLuint location, const Vector2& vector);
		void loadMatrix4(GLuint location, const Matrix4& matrix);

	private:
		GLuint m_programID;

	};
}