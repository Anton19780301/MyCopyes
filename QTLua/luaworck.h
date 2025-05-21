#ifndef LUAWORCK_H
#define LUAWORCK_H

#include "QObject"
#include <lua.hpp>
#include <lualib.h>
#include <lauxlib.h>

class LuaWorck
{
public:
    explicit LuaWorck();
    ~LuaWorck();
    void runScript(const QString &script);

private:
    lua_State *_L = luaL_newstate();
};

#endif // LUAWORCK_H
