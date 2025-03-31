#ifndef OPENAL_UTILS_HPP
#define OPENAL_UTILS_HPP

#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <glm/glm.hpp>

// TODO: renmae to openal_utils and then make it a submodule
// TODO: on operations that can fail we can return an optional

std::string get_attribute_name(ALenum attribute);
void display_al_error(const std::string &message, ALenum error);

// source attribute setters and getters
void set_source_float(ALuint source, ALenum attribute, float value);
ALfloat get_source_float(ALuint source, ALenum attribute);

void set_source_float_vector(ALuint source, ALenum attribute, const ALfloat *values);

void set_source_int(ALuint source, ALenum attribute, ALint value);
ALint get_source_int(ALuint source, ALenum attribute);

void set_source_float3(ALuint source, ALenum attribute, float x, float y, float z);
glm::vec3 get_source_float3(ALuint source, ALenum attribute);

ALfloat get_listener_float(ALenum attribute);
glm::vec3 get_listener_float3(ALenum attribute);

ALint get_buffer_int(ALuint buffer, ALenum attribute);

ALint get_source_state(ALuint source);

// source control
void play_source(ALuint source);
void stop_source(ALuint source);
void pause_source(ALuint source);
void rewind_source(ALuint source);

void set_source_buffer(ALuint source, ALuint buffer);
void detach_source_buffer(ALuint source);
void set_source_position(ALuint source, const glm::vec3 &position);
void set_source_velocity(ALuint source, const glm::vec3 &velocity);
void set_source_direction(ALuint source, const glm::vec3 &direction);
void set_source_pitch(ALuint source, float pitch);
void set_source_gain(ALuint source, float gain);
void set_source_looping(ALuint source, bool loop);

// listener attributes
void set_listener_attribute_float(ALenum attribute, float value);
void set_listener_attribute_float_vector(ALenum attribute, const ALfloat *values);
void set_listener_attribute_float3(ALenum attribute, float x, float y, float z);

void set_listener_position(const glm::vec3 &position);
void set_listener_velocity(const glm::vec3 &velocity);
void set_listener_orientation(const glm::vec3 &at, const glm::vec3 &up);
void set_listener_gain(float gain);

// buffer management
ALuint create_buffer();
void delete_buffer(ALuint buffer);

// source management
ALuint create_source();
void delete_source(ALuint source);

// global openal context management
void initialize_openal();
void shutdown_openal();

#endif // OPENAL_UTILS_HPP
