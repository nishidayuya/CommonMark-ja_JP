#ifndef __HOUDINI_H__
#define __HOUDINI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "buffer.h"

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#ifdef HOUDINI_USE_LOCALE
#	define _isxdigit(c) isxdigit(c)
#	define _isdigit(c) isdigit(c)
#else
/*
 * Helper _isdigit methods -- do not trust the current locale
 * */
#	define _isxdigit(c) (strchr("0123456789ABCDEFabcdef", (c)) != NULL)
#	define _isdigit(c) ((c) >= '0' && (c) <= '9')
#endif

#define HOUDINI_ESCAPED_SIZE(x) (((x) * 12) / 10)
#define HOUDINI_UNESCAPED_SIZE(x) (x)

extern size_t houdini_unescape_ent(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_html(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_html0(strbuf *ob, const uint8_t *src, size_t size, int secure);
extern int houdini_unescape_html(strbuf *ob, const uint8_t *src, size_t size);
extern void houdini_unescape_html_f(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_xml(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_uri(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_url(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_href(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_unescape_uri(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_unescape_url(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_escape_js(strbuf *ob, const uint8_t *src, size_t size);
extern int houdini_unescape_js(strbuf *ob, const uint8_t *src, size_t size);

#ifdef __cplusplus
}
#endif

#endif
