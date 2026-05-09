// #include "openalengine.h"
// #include <iostream>
// #include <fstream>

// OpenALEngine::OpenALEngine()
// {
//     device = alcOpenDevice(nullptr);
//     if (!device) std::cerr << "OpenAL device error\n";

//     context = alcCreateContext(device, nullptr);
//     if (!context) std::cerr << "OpenAL context error\n";

//     alcMakeContextCurrent(context);
// }

// OpenALEngine::~OpenALEngine()
// {
//     alcMakeContextCurrent(nullptr);
//     alcDestroyContext(context);
//     alcCloseDevice(device);
// }

// ALuint OpenALEngine::loadWav(const std::string& filename)
// {
//     ALuint buffer = 0;
//     alGenBuffers(1, &buffer);

//     // -------- WAV Loader (simple PCM 16bit) --------
//     std::ifstream file(filename, std::ios::binary);
//     if(!file.is_open()) {
//         std::cerr << "Cannot open wav file\n";
//         return 0;
//     }

//     char header[44];
//     file.read(header, 44);

//     int dataSize = *(int*)&header[40];
//     char* data = new char[dataSize];
//     file.read(data, dataSize);
//     file.close();

//     alBufferData(buffer, AL_FORMAT_MONO16, data, dataSize, 44100);
//     delete[] data;

//     return buffer;
// }

// void OpenALEngine::play(ALuint buffer)
// {
//     ALuint source;
//     alGenSources(1, &source);
//     alSourcei(source, AL_BUFFER, buffer);
//     alSourcePlay(source);
// }
