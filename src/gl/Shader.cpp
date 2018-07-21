#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "Shader.h"
#include "../Utils.h"

const char* Shader::getName() {
	return this->name;
}

void Shader::bind() {
	glUseProgram(this->program);
}

void Shader::unbind() {
	glUseProgram(0);
}

void Shader::destroy() {
	glDeleteProgram(this->program);
	this->program = 0;
}

GLuint loadShader(const char* name, const char* suffix, GLenum type) {
	std::stringstream filePath;
	filePath << "res/shaders/" << name << "_" << suffix << ".glsl";
	std::string src  = Utils::readFile(filePath.str());
	if(&src == nullptr) {
		std::cerr << "Bailing out of loading " << name << "_" << suffix << std::endl;
		return -1;
	}
	const char* csrc = src.c_str();

	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &csrc, NULL);
	glCompileShader(shader);

	GLint status, logLen;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE) {
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		std::vector<GLchar> infoLog(logLen);
		glGetShaderInfoLog(shader, logLen, &logLen, &infoLog[0]);

		std::cerr << "ERR: failed to compile " << name << "_" << suffix << "!" << std::endl;
		std::cerr << &infoLog[0] << std::endl;

		glDeleteShader(shader);
		return -1;
	}

	return shader;
}

GLint Shader::getUniformLocation(const char* name) {
	if(this->uniforms.find(name) != this->uniforms.end()) {
		return this->uniforms[name];
	}
	GLint location = glGetUniformLocation(this->program, name);
	if(location <= -1) {
		std::cerr << "Uniform variable " << name << " not found in program " << this->getName() << std::endl;
	}
	this->uniforms[name] = location;
	return location;
}

Shader Shader::load(const char* name) {
	Shader shader;
	shader.name    = name;
	shader.program = glCreateProgram();

	GLuint vs = loadShader(name, "vs", GL_VERTEX_SHADER);
	GLuint fs = loadShader(name, "fs", GL_FRAGMENT_SHADER);
	glAttachShader(shader.program, vs);
	glAttachShader(shader.program, fs);
	glLinkProgram(shader.program);

	GLint status, logLen;
	glGetProgramiv(shader.program, GL_LINK_STATUS, &status);
	if(status != GL_TRUE) {
		glGetProgramiv(shader.program, GL_INFO_LOG_LENGTH, &logLen);
		std::vector<GLchar> infoLog(logLen);
		glGetProgramInfoLog(shader.program, logLen, &logLen, &infoLog[0]);

		std::cerr << "Failed to link program " << name << "!" << std::endl;
		std::cerr << infoLog[0] << std::endl;

		glDeleteShader(vs);
		glDeleteShader(fs);
		glDeleteProgram(shader.program);
		shader.program = 0;
	} else {
		glDetachShader(shader.program, vs);
		glDetachShader(shader.program, fs);
		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	return shader;
}
