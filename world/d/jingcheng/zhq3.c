#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"ʮ��·��"NOR);
	set("long", @LONG
��������������ֺ���ȸ��ֵ�ʮ��·�ڡ����Ϸ�����һ������
���ĵ��ۣ�����ۡ�������һ���ӻ��̣�������������ͦ���֡�
����ԶԶ�ľͿɿ�����ǽ�ˡ�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq4",
 "east" :__DIR__"zhq2",
 "north":__DIR__"ql5",
 "south":__DIR__"ql6",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

