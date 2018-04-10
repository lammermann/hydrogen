#include <stddef.h>

#include "hydrogen.h"

void *h_query(h_vfs *vfs, const void *type) {
  if (vfs == NULL || vfs->query == NULL) { return NULL; }
  return vfs->query(vfs, type);
}

int h_close(h_vfs *vfs) {
  if (vfs == NULL) { return -1; }
  if (vfs->close == NULL) { return 0; }
  return vfs->close(vfs);
}

