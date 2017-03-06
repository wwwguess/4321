#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "永定门" NOR);
        set("long", @LONG
 这是长安城的南城门,城门上的牌子写着三个大字－－永定门。高耸坚固的城墙
透出一股威严。城墙上贴着几张告示（gaoshi).因为是京畿重镇，所以官兵们
戒备森严，动不动就截住行人盘问。北边是城里。
LONG
        );
        set("outdoors", "jingcheng");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
        "north" : __DIR__"ndj3",
        ]));
        set("objects", ([
   "/obj/npc/wujiang1"+random(3) : 2,
// "open/diablo/dmenzg" : 1,
 "/obj/npc/bing" : 5,
        ]));
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t九门提督\n\n\t\t    南宫灭\n";
}
