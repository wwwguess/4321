// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
//#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC "�¹۷�" NOR);
	set("long", @LONG
������λ�������������ɽ�룬��ʯ�ܴأ���ߵĵط�һʯ
׿������Ϊ���ӷ塣�����߱���̩ɽ�������š������߾���
������̨�ĳ�������ҿ��������������񵶣��񽣵���̨��
���бȻ���
LONG
	);

	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"east"   : __DIR__"biwutai",
		"eastup" : __DIR__"tanhai",
	]));
        set("objects", ([ 
	"/d/snow/obj/bamboo_sword":2,
	"/d/resort/obj/bblade":2,
          "/d/guanwai/obj/junkstaff":2,
]));
	set("outdoors", "taishan");
	setup();
	set("no_kill",1);
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

        if (dir == "east")
        {
             if (wizardp(me)) return ::valid_leave(me,dir); 
             if (me->query_temp("mark/bwdh") == 1) {
                me->set("mark/bwdh",0);
		tell_object (me,"��ƽ��˵,��λӢ����!\n");
		return ::valid_leave(me,dir);
                 }
            if( me->query("mark/bwdh") == 0 )
            {
             tell_object (me, "��ƽ��˵������û�о��б����ᣬ��ذɡ�\n");
             return notify_fail("����̨��·����ƽ�ӵ�ס�ˡ�\n");     
            }
        }

        return ::valid_leave(me, dir);
}                                       
