#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"��������"NOR);
	set("long", @LONG
������һ��������ʯ�����ϡ����洫�����󲻾��ڶ����̾�����
��������������ǳ���������һ����Ժ���������¡��������ǳ�
���������ķ��ݡ�����¥���������������ｻ���������
LONG
	);

	set("exits", ([
 "west" :__DIR__"xizhimen",
 "east" :__DIR__"xchjie3",
 "north":__DIR__"zyl",
 "south":__DIR__"hss",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

