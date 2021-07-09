#include <lua.h>
#include <lauxlib.h>

#include "../lib/body.h"

#ifdef DEBUG
#include "debug.h"
#endif

// Body *body_new(Vec2 pos, double mass)
int l_new_body(lua_State *L)
{
  double x = luaL_checknumber(L, -3);
  double y = luaL_checknumber(L, -2);
  double mass = luaL_checknumber(L, -1);

  Body *b = (Body*) lua_newuserdata(L, sizeof(*b));
  body_init(b, vec2(x, y), mass);

  

  // setmetatable
  return 1;
}

// void body_apply_force(Body *body, Vec2 force)
int l_body_apply_force(lua_State *L)
{
    Body *b = (Body *) lua_touserdata(L, -3);
    double x = luaL_checknumber(L, -2);
    double y = luaL_checknumber(L, -1);

    body_apply_force(b, vec2(x, y));
    return 0;
}

int l_body_acc(lua_State *L)
{
    Body *b = (Body *) lua_touserdata(L, -1);
    lua_pushnumber(L, b->acc.x);
    lua_pushnumber(L, b->acc.y);
    return 2;
}

int l_body_x(lua_State *L)
{
    Body *b = (Body *) lua_touserdata(L, -1);
    lua_pushnumber(L, b->pos.x);
    return 2;
}

int l_body_y(lua_State *L)
{
    Body *b = (Body *) lua_touserdata(L, -1);
    lua_pushnumber(L, b->pos.y);
    return 2;
}
