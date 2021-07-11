#include <stdio.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>

#include "lua_nmath.h"
#include "lua_body.h"
#include "lua_vec2.h"

#ifdef DEBUG
#include "debug.h"
#endif

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
