// Room: /d/new_taohua/haibian.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������һ������뺣�ڣ�һ����Ȼ�ĺ��壬��
�ü�ֻ��ͣ�ڰ��ߣ�����һƬ�ۺ���һ���         
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
        	if ((!myfam || myfam["family_name"] != "�һ���") && dir == "north"&&
		obj->query_temp("block_msg/all")==0)
	                return notify_fail("½�˷�˵��: �Ǳ��ɵ��Ӳ������һ�����\n");
	}

        if (((int)this_player()->query_skill("qimen-bagua",1)<50) &&
            (objectp(present("lu sheng feng",environment(me)))))
          { if (dir == "north")
            return notify_fail("������Ű��Ե���Ϊ�����������뵺!\n");
           }
        this_player()->delete_temp("noway");
	return ::valid_leave(me, dir);
}
