// xiaolu2.c 林间小径

#include <room.h>
inherit ROOM;
int valid_leave();
void create()
{
        set("short", "林间小径");
        set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。北面似乎有一座简陋的小院。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan.c",
                "south" : __DIR__"xiaolu1",
        ]));

        create_door("north", "竹门", "south", DOOR_CLOSED);

        set("objects",([
                CLASS_D("wudang") + "/yin" : 1,
        ]));

        setup();
 }

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
      if (objectp(present("yin liting", environment(me))) && dir == "north")
       {
        if ((!myfam || myfam["family_name"] != "武当派"))
           return notify_fail("殷梨亭拦住去路,抱拳道：我师傅正在闭关，没事不得打扰。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 80) 
           return notify_fail("殷梨亭把手一拦,劝道：倘若没要紧的事,不要防碍师傅他老人家清修。\n");
       }         
        return ::valid_leave(me, dir);
}
