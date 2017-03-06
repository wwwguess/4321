// Room: /u/k/karrimor/temple/temple1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���Ĺ۴��");
	set("long", @LONG
�������������Ĺ۵Ĵ��, �������ǰ��һ�������۵Ľ���
�ڽ�����·���һ�����ɫ�Ĵ���, �����������ʻ��ع���������
��ǰ����ڷ������ĸ����š����������Բ�ι���ͨ�����Ӻ��Ļ�
�ȡ��߹��ϱߵĺ���ľ�ž��ǹ㳡��
LONG
	);

	set("item_desc", ([
		"door": (: this_object(), ({"look_door", "south"}) :),
	]) );
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"corridor2",
		"south" : __DIR__"square",
		"east" : __DIR__"corridor1",
	]));

	set("valid_startroom", 1);
	set("objects", ([
		CLASS_D("taoist") + "/taolord" :1,
		CLASS_D("taoist") + "/zhanglao1" : 1,
		__DIR__"npc/trainer"  :1,
		__DIR__"npc/tfighter" :1,
	 ]) );
	
	setup();

	// To cause the taoist's board to be loaded.
	call_other("/obj/board/taoist_b", "???");

    create_door("south", "����ľ��", "north");

//	replace_program(ROOM);
}
