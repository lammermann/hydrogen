/**
* @file hydrogen.h
*
* @brief generic interface mechanism
*
* Copyright (c) 2018 Benjamin Kober
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef HYDROGEN_H
#define HYDROGEN_H

#define h_concat(x,y) x##y

/* Defines a unique identifier of type const void*. */
#define h_unique_id(name) \
    static const int h_concat(name, ___) = 0;\
    const void *name = & h_concat(name, ___);

#define h_public_unique_id(name) \
    extern const void *name;

/*  Takes a pointer to a member variable and computes pointer to the structure
    that contains it. 'type' is type of the structure, not the member. */
#define h_get_container(ptr, type, member) \
    (ptr ? ((type*) (((char*) ptr) - offsetof(type, member))) : NULL)

typedef struct h_vfs {
  void *(*query)(struct h_vfs *vfs, const void *type);
  int (*close)(struct h_vfs *vfs);
} h_vfs;

void *h_query(h_vfs *vfs, const void *type);

int h_close(h_vfs *vfs);

#endif /* HYDROGEN_H */
