//door.c
//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"��ѩɽׯ����"NOR);
	set("long", @LONG
	  ��վ����һ����ΰ��Ժ��֮ǰ�����ŵ����Է�����ֻʯʨ�����ϲ���һ��
���������Ŷ�֮�Ϲ���һ����ҡ����������ɷ����д���ĸ����֡���ѩɽׯ������
�����½Ǹվ���������ׯ�����˷���������ʮ���ա����������⣬�벻����
ѩɽ�ϻ�����ôһ����ׯԺ��
LONG
	);


      set("exits", ([
      "north" : __DIR__"guarden.c", 
	"down" : __DIR__"road2",
]));

        set("objects", ([
		__DIR__"npc/guard":	1,
			]));

         set("outdoors", "mountain");

	setup();
}
int valid_leave(object me,string dir)
{
	if( present("guard", environment(this_player())) )
    {
        if ( dir=="north" && !(int)me->query("marks/��ѩɽׯ") )
        return notify_fail("�ŷ�������ס�����ȥ·���ȵ�����ʲô����\n");

	    if ( me->query("marks/��ѩɽׯ") )
		 me->delete("marks/��ѩɽׯ");
    }
    return ::valid_leave(me,dir);

}
