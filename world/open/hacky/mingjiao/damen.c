// damen.c
// by yuer

inherit ROOM;

void create()
{
	set("short", "山门");
	set("long", @LONG
     这是明教总舵的第二道关卡，地势更为险要，三面环山，中间
   有条小路，通向光明顶。
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup" : __DIR__"guangchang",
	     
	]));
      set("objects",([
		CLASS_D("mingjiao") + "/yanyuan.c" : 1,
            ]));

	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if ( me->query_temp("riden") && dir == "northup")
		return notify_fail("这个地方不能骑马过去。\n");
	if ( !userp(me) && dir == "northup" )
			return 0;

        if ((!myfam || myfam["family_name"] != "明教") && dir == "northup" &&
                objectp(present("yan yuan", environment(me))))
           return notify_fail("颜垣喝道：你不是明教教徒，不得入内。\n");
        return ::valid_leave(me, dir);
}

