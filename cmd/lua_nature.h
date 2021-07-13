#include <stdio.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>

#include "nature2d.h"

#include "lua_body.h"
#include "lua_vec2.h"

#ifdef DEBUG
#include "debug.h"
#endif


// double map(double value, double start1, double stop1, double start2, double stop2)
int l_map(lua_State *L)
{
    double value = luaL_checknumber(L, -5);
    double start1 = luaL_checknumber(L, -4);
    double stop1 = luaL_checknumber(L, -3);
    double start2 = luaL_checknumber(L, -2);
    double stop2 = luaL_checknumber(L, -1);
    double result = map(value, start1, stop1, start2, stop2);
    lua_pushnumber(L, result);
    return 1;
}

// void noise_seed(int seed)
int l_noiseseed(lua_State *L)
{
    double seed = luaL_checknumber(L, -1);
    noise_seed(seed);
    return 0;
}

// double noise(double x).
int l_noise(lua_State *L)
{
    double x = luaL_checknumber(L, -1);
    double result = noise(x);
    lua_pushnumber(L, result);
    return 1;
}

// double noise2(double x, double y)
int l_noise2(lua_State *L)
{
    double x = luaL_checknumber(L, -2);
    double y = luaL_checknumber(L, -1);
    double result = noise2(x, y);
    lua_pushnumber(L, result);
    return 1;
}

// double noise3(double x, double y, double z)
int l_noise3(lua_State *L)
{
    double x = luaL_checknumber(L, -3);
    double y = luaL_checknumber(L, -2);
    double z = luaL_checknumber(L, -1);
    double result = noise3(x, y, z);
    lua_pushnumber(L, result);
    return 1;
}

int luaopen_nature(lua_State *L)
{
    // register the nature module
    luaL_Reg natureLib[] = {
        {"noiseseed", l_noiseseed},
        {"noise", l_noise},
        {"noise2", l_noise2},
        {"noise3", l_noise3},
        {"newBody", l_new_body},
        {NULL, NULL}
    };
    luaL_newlib(L, natureLib);
    return 1;
}

// Register C functions in Lua
void register_global_functions(lua_State *L)
{
    // lib
    lua_pushcfunction(L, l_map);
    lua_setglobal(L, "map");

    // vec2
    lua_pushcfunction(L, l_vec2);
    lua_setglobal(L, "vec2");
}
