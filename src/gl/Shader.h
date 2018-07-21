#ifndef GL_SHADER_H_
#define GL_SHADER_H_

#include <map>
#include "../gl.h"

class Shader {
private:
	const char* name;
	GLuint program;

	std::map<const char*, GLint> uniforms;

public:
	const char* getName();
	void bind();
	void unbind();
	void destroy();

	GLint getUniformLocation(const char* name);

	static Shader load(const char* name);
};

#endif
