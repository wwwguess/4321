// Room: /d/huashan/mishi.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����ǻ�ɽ�ɵ����ң����������޷����룬������˺ܶ໪ɽ�ؼ���
LONG
        );

        set("exits", ([
		"south" : __DIR__"midao",
        ]));
        set("objects",([
                CLASS_D("huashan") + "/lao-zhe" : 1,
                "d/huashan/obj/taxue" : 1,
		"d/huashan/obj/parry" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if ( present("gao laozhe", environment(me)) )
        if ( present("huashan miji", me)
        ||   objectp(ob = present("corpse", me)) && present("huashan miji", ob)
)
        {
                if (dir == "south" )
                {
                        return notify_fail("������˵��: �书�ؼ�ֻ������������ϰ������Я����� !\n");
                }
        }
          return ::valid_leave(me,dir);
}
