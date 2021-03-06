// Room: /d/new_taohua/haibian.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "海边");
	set("long", @LONG
这里是桃花岛的入海口，一个天然的海湾，有
好几只船停在岸边，岛内一片粉红的桃花。         
LONG
	);

	set("exits", ([
		"north" : __DIR__"taolin",
                "enter" : __DIR__"boat1",
	]));
        set("objects",([
		CLASS_D("taohua") + "/lushengf.c" : 1,
            ]));
	setup();
}


int valid_leave(object me, string dir)
{
        mapping myfam;
	object obj;
        myfam = (mapping)me->query("family");
	if (objectp((obj=present("lu sheng feng", environment(me)))))
	{	
        	if ((!myfam || myfam["family_name"] != "桃花岛") && dir == "north"&&
		obj->query_temp("block_msg/all")==0)
	                return notify_fail("陆乘风说到: 非本派弟子不能入桃花岛。\n");
	}

        if (((int)this_player()->query_skill("qimen-bagua",1)<50) &&
            (objectp(present("lu sheng feng",environment(me)))))
          { if (dir == "north")
            return notify_fail("你的奇门八卦的修为不够，不能入岛!\n");
           }
        this_player()->delete_temp("noway");
	return ::valid_leave(me, dir);
}
