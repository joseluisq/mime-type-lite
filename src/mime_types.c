#include <node_api.h>
#include <napi-macros.h>
#include <stdlib.h>
#include <string.h>
#include "mime_types.h"

char *default_mime_type = "text/plain";

mime_types_map_t meme_types[] = {
	{".txt", "text/plain"},
	{".css", "text/css"},
	{".htm", "text/html"},
	{".html", "text/html"},
	{".png", "image/png"},
	{".jpeg", "image/jpeg"},
	{".jpg", "image/jpeg"},
	{".svg", "image/svg+xml"},
	{".gif", "image/gif"},
	{".webp", "image/webp"},
	{".ico", "image/x-icon"},
	{".js", "application/javascript"},
	{".json", "application/json"},
	{".map", "application/json"},
	{".pdf", "application/pdf"},
	{".xml", "text/xml"},
	{".yml", "application/x-yaml"},
	{".zip", "application/zip"},
	{".gz", "application/gzip"},
	{".tar", "application/tar"},
	{".tgz", "application/tar+gzip"},
	{".tar.gz", "application/tar+gzip"},
	{".m4a", "audio/mp4"},
	{".aac", "audio/aac"},
	{".mp3", "audio/mp3"},
	{".wav", "audio/wav"},
	{".mpeg", "video/mpeg"},
	{".mpg", "video/mpeg"},
	{".ogg", "video/ogg"},
	{".ogv", "video/ogg"},
	{".mp4", "video/mp4"},
	{".m4v", "video/mp4"},
	{".webm", "video/webm"},
	{NULL, NULL},
};

static const char *get_mime_type_by_filename(char *filename)
{
	char *dot = strrchr(filename, '.');

	if (dot)
	{
		mime_types_map_t *map = meme_types;

		while (map->extension)
		{
			if (strcmp(map->extension, dot) == 0)
			{
				return map->mime_type;
			}

			map++;
		}
	}

	return default_mime_type;
}

NAPI_METHOD(get_mime_type)
{
	NAPI_ARGV(1);
	NAPI_ARGV_UTF8_MALLOC(str, 0);
	NAPI_RETURN_STRING(get_mime_type_by_filename(str));
}

NAPI_INIT()
{
	NAPI_EXPORT_FUNCTION(get_mime_type);
}
