#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
��������ȸ��ֵ��жΡ�·���Ǿ�������һ�����ۣ���������
�ۡ�����������ȸ��ֺ�������ֵ�ʮ��·�ڡ������Ǿ��ǵ���
��ȥ������������˶�������
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq3",
 "east" :__DIR__"zhq1",
 "south" :__DIR__"qxguan",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

