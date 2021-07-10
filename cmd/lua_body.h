#include <lua.h>
#include <lauxlib.h>

#include "../lib/body.h"

#ifdef DEBUG
#include "debug.h"
#endif

#define BODY_METATABLE_NAME "BodyObject"


// Body *body_new(Vec2 pos, double mass)
int l_body_new(lua_State *L)
{
    double x = luaL_checknumber(L, -3);
    double y = luaL_checknumber(L, -2);
    double mass = luaL_checknumber(L, -1);

    Body *b = (Body*) lua_newuserdata(L, sizeof(*b));
    body_init(b, vec2(x, y), mass);

    int b_index = lua_gettop(L);

    luaL_newmetatable(L, BODY_METATABLE_NAME);
    lua_pushstring(L, "__index");
    lua_getglobal(L, "Body");
    lua_settable(L, -3);
    lua_setmetatable(L, b_index);

    return 1;
}

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
    body_update(b);
    return 0;
}

void l_body(lua_State *L)
{

    luaL_Reg bodyLib[] = {
        {"new", l_body_new},
        {"applyForce", l_body_apply_force},
        {"position", l_body_position},
        {"velocity", l_body_velocity},
        {"acceleration", l_body_acceleration},
        {"update", l_body_update},
        {NULL, NULL}
    };

    luaL_newlib(L, bodyLib);

    int body_table_index = lua_gettop(L);
    lua_pushvalue(L, body_table_index);
    lua_setglobal(L, "Body");
}
