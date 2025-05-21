#include "luaworck.h"
#include "draw.h"
#include "qdebug.h"

LuaWorck::LuaWorck()
{
    luaL_openlibs(_L);
}

LuaWorck::~LuaWorck()
{
    lua_close(_L);
    //delete _L;
}

void LuaWorck::runScript(const QString &script)
{
    auto Circle = [](lua_State* L) -> int
    {
        lua_Number x = lua_tonumber(L,-3);
        lua_Number y = lua_tonumber(L,-2);
        lua_Number d = lua_tonumber(L,-1);
        Draw::drawCircle((int)x,(int)y,(int)d);
        return 1;
    };

    auto Sqere = [](lua_State* L) -> int
    {
        lua_Number x = lua_tonumber(L,-3);
        lua_Number y = lua_tonumber(L,-2);
        lua_Number d = lua_tonumber(L,-1);
        Draw::drawSqere((int)x,(int)y,(int)d);
        return 1;
    };

    auto Clear = [](lua_State* L) -> int
    {
        Draw::clear();
        return 1;
    };

    auto backround = [](lua_State* L) -> int
    {
        lua_Number r = lua_tonumber(L,-3);
        lua_Number g = lua_tonumber(L,-2);
        lua_Number b = lua_tonumber(L,-1);
        Draw::backround(r,g,b);
        return 1;
    };

    auto line = [](lua_State* L) -> int
    {
        lua_Number x0 = lua_tonumber(L,-4);
        lua_Number y0 = lua_tonumber(L,-3);
        lua_Number x1 = lua_tonumber(L,-2);
        lua_Number y1 = lua_tonumber(L,-1);
        Draw::line(x0,y0,x1,y1);
        return 1;
    };

    QByteArray ba = script.toLocal8Bit();
    const char* LUA_FILE = ba.data();

    lua_State* L = luaL_newstate();
    lua_pushcfunction(L, Circle);
    lua_setglobal(L, "Circle");
    lua_pushcfunction(L, Sqere);
    lua_setglobal(L, "Sqere");
    lua_pushcfunction(L, Clear);
    lua_setglobal(L, "Clear");
    lua_pushcfunction(L, backround);
    lua_setglobal(L, "backround");
    lua_pushcfunction(L, line);
    lua_setglobal(L, "line");

    luaL_dostring(L, LUA_FILE);
    lua_pcall(L, 0, 0, 0);

    lua_close(L);
}
