// Room: /d/taishan/biwutai.c
// Date: 98/2/24 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY "比武擂台" NOR);
	set("long", @LONG
    这儿就是一片空旷的广场，地面经过人工修砌，用长条
青石铺得整整齐齐，南北各搭有两个大凉棚，摆上了八仙桌，
长条簦，东面就是比武擂台。 
    每年中秋各派好手都将云集此处进行一年一度的比武
大会，推选出谁是当今「河海风云」的最强者。擂台的两侧挂着
一副对子(duizi)。
LONG
	);

	set("exits", ([
		"west" : __DIR__"riguan",
	]));
        set("objects", ([ 
        "/d/taishan/npc/referee":1,
]));
	set("item_desc",(["duizi": "左边："+HIR "会四方豪杰，一展身手\n" NOR+
       "右边："+ HIR "聚八方朋友，点到为止\n" NOR +
"横批："+HIY " 英 雄 大 会 \n" NOR]));
     set("no_kill",1);
     set("no_beg",1);
     set("no_sleep",1);
	
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

