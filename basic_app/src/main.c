// Source - https://stackoverflow.com/q/76142085
// Posted by theerrormagnet
// Retrieved 2026-11-27, License - CC BY-SA 4.0

#include <stdio.h>
#include <pulse/error.h>
#include <pulse/simple.h>
#include <math.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    (void)argc; // Silences the -Wunused-parameter warning

    short buffer[22050]; // 0.5 seconds of audio at 44100 Hz
    pa_simple *s;
    pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 44100,
        .channels = 1
    };
    float frequency = 440.0;

    for (int i = 0; i < 22050; i++) {
        buffer[i] = (short)(32767.0 * sin(2.0 * M_PI * frequency * i / 44100.0));
    }

    if (!(s = pa_simple_new(NULL, argv[0], PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &errno))) {
        fprintf(stderr, "pa_simple_new() failed: %s\n", pa_strerror(errno));
        return 1;
    }

    if (pa_simple_write(s, buffer, sizeof(buffer), NULL) < 0) {
        fprintf(stderr, "pa_simple_write() failed: %s\n", pa_strerror(errno));
        return 1;
    }

    pa_simple_drain(s, NULL);

    pa_simple_free(s);

    return 0;
}

