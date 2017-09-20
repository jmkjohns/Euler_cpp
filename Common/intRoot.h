#ifndef __INTROOT__
#define __INTROOT__

#define INTROOT(_TYPE_) \
    _TYPE_ intRoot( _TYPE_ num ) { \
        bool term = false; \
        _TYPE_ root = 2; \
        _TYPE_ quot = num / root; \
        _TYPE_ prev = 0; \
        while (!(root == quot) && !term && !(quot - root == 1)) { \
            if (root - prev == 1) { \
                root = prev; \
                term = true; } \
            else { \
                prev = root; \
                quot = num / root; \
                root = (root + quot) / 2; } } \
        return root; }
#endif
