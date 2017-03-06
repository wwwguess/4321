// square.c1.c
inherit ROOM;
void create()
{
        set("short", "客厅");
        set("long", @LONG
这是华山掌门岳不群的居所「有所不为轩」，此处是前厅，厅上挂着
「正气堂」三字匾额。厅中很宽敞，却没什么摆设，靠墙放着两把交椅，
这里是岳不群议事、授徒的地方，后面是花园。
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"square",
  "south" : __DIR__"houhuayuan1",
]));
        set("objects", ([
                CLASS_D("huashan") + "/dayou" : 1,
                CLASS_D("huashan") + "/yueling" : 1]));
        setup();
        set("no_clean_up", 0);
        setup();
        "/obj/board/huashan_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
	object obj;
        myfam = (mapping)me->query("family");
	if (objectp((obj=present("lu dayou", environment(me)))))
	{	
        	if ((!myfam || myfam["family_name"] != "华山派") && dir == "south"&&
		obj->query_temp("block_msg/all")==0)
	                return notify_fail("陆大友喝道：你不是华山弟子，不得入内。\n");
	}
        return ::valid_leave(me, dir);
}
