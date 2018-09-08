#ifndef MIME_TYPES_H
#define MIME_TYPES_H

typedef struct
{
	const char *extension;
	const char *mime_type;
} mime_types_map_t;

static const char *get_mime_type_by_filename(char *filename);

#endif
