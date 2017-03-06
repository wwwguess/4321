// biaoju.c

//#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", HIR "振远镖局" NOR);
        set("long", @LONG
你现在正站在镖局里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/eroad2" ]) );

        set("objects", ([
                CLASS_D("guardman") + "/b_header" : 1,
		CLASS_D("guardman") + "/biaotou1" : 1,	
                "/u/cloud/npc/bfighter" : 2,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("valid_startroom", 1);
        setup();

}

string look_sign(object me)
{
        return "招牌写著："+ HIY "镖。\n" NOR;
}

