#include "luaworck.h"
#include "qdebug.h"

LuaWorck::LuaWorck(MainWindow *mw):
    _mw(mw)
{
    //luaL_openlibs(_L);
}

LuaWorck::~LuaWorck()
{
    //lua_close(_L);
    //delete _L;
}

void LuaWorck::runScript(const QString &script)
{
    _mw->clearOut();
    QByteArray t = script.toLocal8Bit();
    const char* toDo = t.data();
    //luaL_dostring(_L,toDo);
    /*
    lua_pushinteger(_L,4);
    lua_pushstring(_L,"ssss");
    lua_pushinteger(_L,51);
    lua_pushstring(_L,"aaa");
    lua_pushinteger(_L,6);
    lua_pushstring(_L,"fffff");

    qDebug() << "count " << lua_gettop(_L);

    while (lua_gettop(_L))
    {
        int t= lua_type(_L,-1);
        switch (t)
        {
            case LUA_TSTRING:
                qDebug() << "string " << lua_tostring(_L,-1);
                break;

            case LUA_TNUMBER:
                qDebug() << "number " << lua_tonumber(_L,-1);
                break;

            default:
                break;
        }

        lua_remove(_L,-1);
    }
    */
}
