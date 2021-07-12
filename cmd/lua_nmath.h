#include <lua.h>
#include <lauxlib.h>
#include "../lib/nmath.h"
#include "debug.h"

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
