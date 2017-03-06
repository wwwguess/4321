//ROOM : /d/huashan/sleeproom.c
//Date: 97/1/1
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", BLK "华山休息室" NOR);
        set("long", @LONG
这里是华山弟子饮食起居的地方。靠墙一溜摆着几张木床，床
上铺的是棉被。使人一看就想睡觉。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                  "north" : __DIR__"houhuayuan2",
        ]));
        
        setup();
        replace_program(ROOM);
}
