#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "lua_nature.h"

#ifdef DEBUG
#include "debug.h"
#endif


int main(int argc, const char *argv[])
{
    const char *lua_file = "main.lua";
    int nature_mod = 0;

    if (argc > 1) {
        lua_file = argv[1];
    }

    // load nature as a module
    // otherwise nature is a global
    if (argc > 2 && strcmp(argv[2], "-m")==0) {
        nature_mod = 1;
    }

    // Create a new lua state
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // register all global functions with lua
    register_global_functions(L);

    if (nature_mod) {
        // load nature as module
        luaL_requiref(L, "nature", luaopen_nature, 0);
        lua_pop(L, 1);
    } else {
        // register nature as a global
        luaopen_nature(L);
        lua_setglobal(L, "nature");
    }


    stackDump(L);

    // execute the lua file
    int err = luaL_dofile(L, lua_file);
    if (err) {
        printf("%s\n", lua_tostring(L, -1));
        return 1;
    }

    return 0;
}
