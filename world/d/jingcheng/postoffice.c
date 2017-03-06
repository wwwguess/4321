// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
	set("short", "驿站");
	set("long", @LONG
这里是负责官府文书跟军令往来的驿站，百姓的信件也可以通过这个驿站
进行传递。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"dchjie1",
	]));
	set("objects", ([
		"/d/jingcheng/npc/daizong": 1,
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回驿站。\n");
		destruct(mbox);
	}
	return 1;
}
