#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>

#include <lua.h>

static void stackdump(lua_State *L)
{
    int i;
    int top = lua_gettop(L);
    for (i = 1; i <= top; i++)
    { /* repeat for each level */
        int t = lua_type(L, i);
        switch (t)
        {

        case LUA_TSTRING: /* strings */
            printf("'%s'", lua_tostring(L, i));
            break;

        case LUA_TBOOLEAN: /* booleans */
            printf(lua_toboolean(L, i) ? "true" : "false");
            break;

        case LUA_TNUMBER: /* numbers */
            printf("%g", lua_tonumber(L, i));
            break;

        case LUA_TTABLE: /* table */
            lua_getfield(L, i, "__name");
            printf("table:%s", lua_tostring(L, -1));
            lua_pop(L, 1);
            break;

        default: /* other values */
            printf("%s", lua_typename(L, t));
            break;
        }
        printf("  "); /* put a separator */
    }
    printf("\n"); /* end the listing */
}

static void printstatck(lua_State *L, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf(" ");
    stackdump(L);
}

#endif
