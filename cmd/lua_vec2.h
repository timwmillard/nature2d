#include <lua.h>
#include <lauxlib.h>

#include "nature2d.h"

#ifdef DEBUG
#include "debug.h"
#endif

// typedef struct Vec2 {
//     double x;
//     double y;
// } Vec2;
int l_vec2(lua_State *L)
{
    double x = luaL_checknumber(L, -2);
    double y = luaL_checknumber(L, -1);
    Vec2 *v = (Vec2*) lua_newuserdata(L, sizeof(Vec2));
    v->x = x;
    v->y = y;
    return 1;
}

// static inline Vec2 vec2_add(const Vec2 a, const Vec2 b)
int l_vec2_add(lua_State *L)
{
    Vec2 *a = (Vec2 *) lua_touserdata(L, -2);
    Vec2 *b = (Vec2 *) lua_touserdata(L, -1);
    Vec2 c = vec2_add(*a, *b);
    Vec2 *v = (Vec2*) lua_newuserdata(L, sizeof(Vec2));
    v->x = c.x;
    v->y = c.y;
    return 1;
}
