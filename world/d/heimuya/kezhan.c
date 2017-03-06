// Room: /heimuya/.c
// dfbb 1997/1/24 

inherit ROOM;

void create()
{
	set("short", "顺升客栈");
	set("long", @LONG
这是保定城外最大的客店，是家老字号了,过往行商大多在此歇息一宿
好第二天进保定城.因而生意非常兴隆,墙上挂着一个牌子(paizi)。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);

	set("item_desc", ([
		"paizi" : "顺升客栈老字号\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	        __DIR__"npc/power" : 1,

	]));

	set("exits", ([
		"east" : __DIR__"sancha",
	]));

	setup();
//       call_other( "/clone/board/kezhan_b", "???" );
}

