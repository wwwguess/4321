#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"ʮ��·��"NOR);
	set("long", @LONG
�������������ֺ�������ֵ�ʮ��·�ڡ�һֱ�����߿��Ե����ǵ�
���š����Ϸ�����һ����ģ��С����Ժ�������Ϸ�����ǵ���ة��
��ɽ�ĸ����ˡ�
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie2",
 "east" :__DIR__"xchjie4",
 "north":__DIR__"ql3",
 "south":__DIR__"ql4",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

