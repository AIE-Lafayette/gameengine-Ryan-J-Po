#pragma once
namespace GameGraphics
{
	template<typename T, int size>
	struct UniformData
	{
		const char* name = "";
		T data[size];
	};

	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragPath);

		unsigned int getProgramID() { return m_shaderProgram; }
		unsigned int getVertexBufferID() { return m_vertexBufferID; }
		unsigned int getFragBufferID() { return m_fragBufferID; }
		unsigned int getVertexArrayID() { return m_vertexBufferID; }

		void use();

		void setBool(const char* name, bool value);
		void setInt(const char* name, int value);
		void setFloat(const char* name, float value);
		void setVec2(const char* name, float x, float y);
		void setColor(const char* name, float x, float y, float z, float w);

	private:
		unsigned int m_vertexBufferID;
		unsigned int m_fragBufferID;
		unsigned int m_shaderProgram;
		unsigned int m_vertexArrayID;

		GameGraphics::UniformData<bool, 1> m_boolData;
		GameGraphics::UniformData<int, 1> m_intData;
		GameGraphics::UniformData<float, 1> m_floatData;
		GameGraphics::UniformData<float, 2> m_vec2Data;
	};
}
