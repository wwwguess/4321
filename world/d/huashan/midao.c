// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "��ɽ�ص�");
        set("long", @LONG
������һ���ڰ������ȣ�������ͨ��ɽ�ɵ����ҡ�
LONG
        );

        set("exits", ([
                "out" : __DIR__"buwei2",
                "north" : __DIR__"mishi",
        ]));
        set("objects",([
                CLASS_D("huashan") + "/lao-zhe2" : 1,
//        	"/open/yuer/obj/zitanhua" : 1,
        ]));
        setup();
}



int valid_leave(object me, string dir)
{

        if( (this_player()->query("family/family_name")!="��ɽ��")
        && (objectp(present("ai laozhe", environment(me)))) )
        {
                if (dir == "north" )
                {
                        return notify_fail("������˵��: ����һ�ɽ���ӣ����ܽ����ҡ�\n");
                }
        }
        return ::valid_leave(me, dir);
}
