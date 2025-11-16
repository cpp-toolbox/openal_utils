#include "openal_utils.hpp"
#include <iostream>
#include <unordered_map>

namespace openal_utils {

const std::unordered_map<ALenum, std::string> al_attribute_names = {
    {AL_PITCH, "AL_PITCH"},
    {AL_GAIN, "AL_GAIN"},
    {AL_POSITION, "AL_POSITION"},
    {AL_VELOCITY, "AL_VELOCITY"},
    {AL_DIRECTION, "AL_DIRECTION"},
    {AL_LOOPING, "AL_LOOPING"},
    {AL_BUFFER, "AL_BUFFER"},
    {AL_SOURCE_RELATIVE, "AL_SOURCE_RELATIVE"}
    // TODO: Add more when needed
};

std::string get_attribute_name(ALenum attribute) {
    auto it = al_attribute_names.find(attribute);
    return (it != al_attribute_names.end()) ? it->second : "UNKNOWN_ATTRIBUTE";
}

void display_al_error(const std::string &message, ALenum error) {
    std::cerr << message << "Error code: " << error << std::endl;
}

// Source Attribute Setters and Getters
void set_source_float(ALuint source, ALenum attribute, float value) {
    alSourcef(source, attribute, value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourcef " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_source_float_vector(ALuint source, ALenum attribute, const ALfloat *values) {
    alSourcefv(source, attribute, values);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourcefv " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_source_int(ALuint source, ALenum attribute, ALint value) {
    alSourcei(source, attribute, value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourcei " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_source_float3(ALuint source, ALenum attribute, float x, float y, float z) {
    alSource3f(source, attribute, x, y, z);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSource3f " + get_attribute_name(attribute) + " : ", error);
    }
}

ALint get_source_int(ALuint source, ALenum attribute) {
    ALint value;
    alGetSourcei(source, attribute, &value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetSourcei " + get_attribute_name(attribute) + " : ", error);
        return -1; // Return a default value (you could also throw or handle it differently)
    }
    return value;
}

ALfloat get_source_float(ALuint source, ALenum attribute) {
    ALfloat value;
    alGetSourcef(source, attribute, &value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetSourcef " + get_attribute_name(attribute) + " : ", error);
        return -1.0f; // Return a default value
    }
    return value;
}

glm::vec3 get_source_float3(ALuint source, ALenum attribute) {
    ALfloat values[3];
    alGetSourcefv(source, attribute, values);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetSourcefv " + get_attribute_name(attribute) + " : ", error);
        return glm::vec3(0.0f); // Return a default value (zero vector)
    }
    return glm::vec3(values[0], values[1], values[2]);
}

ALfloat get_listener_float(ALenum attribute) {
    ALfloat value;
    alGetListenerf(attribute, &value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetListenerf " + get_attribute_name(attribute) + " : ", error);
        return -1.0f; // Return a default value
    }
    return value;
}

glm::vec3 get_listener_float3(ALenum attribute) {
    ALfloat values[3];
    alGetListenerfv(attribute, values);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetListenerfv " + get_attribute_name(attribute) + " : ", error);
        return glm::vec3(0.0f); // Return a default value (zero vector)
    }
    return glm::vec3(values[0], values[1], values[2]);
}

ALint get_buffer_int(ALuint buffer, ALenum attribute) {
    ALint value;
    alGetBufferi(buffer, attribute, &value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGetBufferi " + get_attribute_name(attribute) + " : ", error);
        return -1; // Return a default value
    }
    return value;
}

ALint get_source_state(ALuint source) {
    ALint state;
    return get_source_int(source, AL_SOURCE_STATE);
}

// Source Control
void play_source(ALuint source) {
    alSourcePlay(source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourcePlay : ", error);
    }
}

void stop_source(ALuint source) {
    alSourceStop(source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourceStop : ", error);
    }
}

void pause_source(ALuint source) {
    alSourcePause(source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourcePause : ", error);
    }
}

void rewind_source(ALuint source) {
    alSourceRewind(source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alSourceRewind : ", error);
    }
}

// listener [[
void set_listener_attribute_float(ALenum attribute, float value) {
    alListenerf(attribute, value);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alListenerf " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_listener_attribute_float_vector(ALenum attribute, const ALfloat *values) {
    alListenerfv(attribute, values);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alListenerfv " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_listener_attribute_float3(ALenum attribute, float x, float y, float z) {
    alListener3f(attribute, x, y, z);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alListener3f " + get_attribute_name(attribute) + " : ", error);
    }
}

void set_listener_position(const glm::vec3 &position) {
    set_listener_attribute_float3(AL_POSITION, position.x, position.y, position.z);
}

void set_listener_velocity(const glm::vec3 &velocity) {
    set_listener_attribute_float3(AL_VELOCITY, velocity.x, velocity.y, velocity.z);
}

void set_listener_orientation(const glm::vec3 &at, const glm::vec3 &up) {
    ALfloat orientation[] = {at.x, at.y, at.z, up.x, up.y, up.z};
    set_listener_attribute_float_vector(AL_ORIENTATION, orientation);
}

void set_listener_gain(float gain) { set_listener_attribute_float(AL_GAIN, gain); }

// listener ]]

// Buffer Management
ALuint create_buffer() {
    ALuint buffer;
    alGenBuffers(1, &buffer);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGenBuffers : ", error);
    }
    return buffer;
}

void delete_buffer(ALuint buffer) {
    alDeleteBuffers(1, &buffer);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alDeleteBuffers : ", error);
    }
}

// Source Management
ALuint create_source() {
    ALuint source;
    alGenSources(1, &source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alGenSources : ", error);
    }
    return source;
}

void delete_source(ALuint source) {
    alDeleteSources(1, &source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        display_al_error("alDeleteSources : ", error);
    }
}

// higher level logic [[
void set_source_buffer(ALuint source, ALuint buffer) { set_source_int(source, AL_BUFFER, buffer); }
void detach_source_buffer(ALuint source) { set_source_int(source, AL_BUFFER, AL_NONE); }

void set_source_position(ALuint source, const glm::vec3 &position) {
    set_source_float3(source, AL_POSITION, position.x, position.y, position.z);
}

void set_source_velocity(ALuint source, const glm::vec3 &velocity) {
    set_source_float3(source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
}

void set_source_direction(ALuint source, const glm::vec3 &direction) {
    set_source_float3(source, AL_DIRECTION, direction.x, direction.y, direction.z);
}

void set_source_pitch(ALuint source, float pitch) { set_source_float(source, AL_PITCH, pitch); }

void set_source_gain(ALuint source, float gain) { set_source_float(source, AL_GAIN, gain); }

void set_source_looping(ALuint source, bool loop) { set_source_int(source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE); }
// higher level logic ]]

// global openal context management
void initialize_openal() {
    ALCdevice *device = alcOpenDevice(nullptr);
    if (!device) {
        std::cerr << "Failed to open OpenAL device" << std::endl;
        return;
    }

    ALCcontext *context = alcCreateContext(device, nullptr);
    if (!context) {
        std::cerr << "Failed to create OpenAL context" << std::endl;
        alcCloseDevice(device);
        return;
    }

    alcMakeContextCurrent(context);
}

void shutdown_openal() {
    ALCcontext *context = alcGetCurrentContext();
    ALCdevice *device = alcGetContextsDevice(context);

    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
}
} // namespace openal_utils
