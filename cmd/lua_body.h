#include <lua.h>
#include <lauxlib.h>

#include "../lib/body.h"

#ifdef DEBUG
#include "debug.h"
#endif

#define BODY_METATABLE_NAME "BodyObject"

// void body_apply_force(Body *body, Vec2 force)
int l_body_apply_force(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -3, BODY_METATABLE_NAME);
    double x = luaL_checknumber(L, -2);
    double y = luaL_checknumber(L, -1);

    body_apply_force(b, vec2(x, y));
    return 0;
}

int l_body_position(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -1, BODY_METATABLE_NAME);
    lua_pushnumber(L, b->pos.x);
    lua_pushnumber(L, b->pos.y);
    return 2;
}

int l_body_velocity(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -1, BODY_METATABLE_NAME);
    lua_pushnumber(L, b->vel.x);
    lua_pushnumber(L, b->vel.y);
    return 2;
}

int l_body_acceleration(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -1, BODY_METATABLE_NAME);
    lua_pushnumber(L, b->acc.x);
    lua_pushnumber(L, b->acc.y);
    return 2;
}

int l_body_update(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -1, BODY_METATABLE_NAME);
    body_update(b, 1);
    return 0;
}

int l_body_tostring(lua_State *L)
{
    Body *b = (Body *) luaL_checkudata(L, -1, BODY_METATABLE_NAME);

    lua_pushfstring(L, "x=%f, y=%f", b->pos.x, b->pos.y);
    return 1;
}

// Body *body_new(Vec2 pos, double mass)
int l_new_body(lua_State *L)
{
    double x = luaL_checknumber(L, -3);
    double y = luaL_checknumber(L, -2);
    double mass = luaL_checknumber(L, -1);

    Body *b = (Body*) lua_newuserdata(L, sizeof(*b));
    body_init(b, vec2(x, y), mass);

    int b_index = lua_gettop(L);

    luaL_newmetatable(L, BODY_METATABLE_NAME);

    lua_pushstring(L, "__index");
    luaL_Reg bodyLib[] = {
        {"applyForce", l_body_apply_force},
        {"position", l_body_position},
        {"velocity", l_body_velocity},
        {"acceleration", l_body_acceleration},
        {"update", l_body_update},
        {"tostring", l_body_tostring},
        {NULL, NULL}
    };
    luaL_newlib(L, bodyLib);
    lua_settable(L, -3);

    lua_pushstring(L, "__tostring");
    lua_pushcfunction(L, l_body_tostring);
    lua_settable(L, -3);

    lua_setmetatable(L, b_index);

    return 1;
}
