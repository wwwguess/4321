
#include <room.h>
inherit "/std/room/hockshop";
//inherit "/std/room/bank.c";

void create()
{
	set("short", "鹰记商号");
	set("long", @LONG
鹰记一向是信用卓著，生意鼎盛的商号。从藏东来的藏香，从关内来的瓷
器和丝缎，从打箭炉来的茶砖，无论什么，只要是值钱的东西，都可以在这里
买卖。柜台上放著一块牌子(sign)。
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
本商号财力雄厚。客倌可以在这里典当(pawn)、卖断(sell)各种货物，
铜钱、银两、黄金、银票一概通用。本商号还免费为客倌兑换(convert)钱币。
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"octo15",
	]));
        set("objects", ([
                __DIR__"npc/puying": 1 ]) );

	setup();

}
