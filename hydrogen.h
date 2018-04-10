/**
* @file hydrogen.h
*
* @brief generic interface mechanism
*
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
