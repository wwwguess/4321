#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
��������ȸ��ֵ��жΡ�������һ�Ҳ��꣬��������ȸ��ֺ�����
��ֵ�ʮ��·�ڡ��������Ǿ��ǵı���֮�أ���ׯ�ù����е��̵�
���ֺŻ㼯֮����������Ⱥ���ϡ�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq2",
 "east" :__DIR__"ndj3",  
 "north" :__DIR__"bdian",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

