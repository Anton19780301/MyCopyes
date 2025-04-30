#ifndef LUAWORCK_H
#define LUAWORCK_H

#include "QObject"
#include "mainwindow.h"
// #include <lua.hpp>
// #include <lualib.h>
// #include <lauxlib.h>

class LuaWorck
{
public:
    explicit LuaWorck(MainWindow *mw);
    ~LuaWorck();
    void runScript(const QString &script);

private:
    MainWindow *_mw = nullptr;
    //lua_State *_L = luaL_newstate();
};

#endif // LUAWORCK_H
