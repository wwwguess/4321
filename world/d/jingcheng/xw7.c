// Room: /d/jingcheng/xw7.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[30m�����ֶ���·��[2;37;0m");
	set("long", @LONG
�����������ֺͰ׻���ֵĶ���·�ڡ�������һ�ο��Կ���һ��
���������ǵ����ֳ������ۼ��ڰ׻���ֵ��϶ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"baih3",
  "south" : __DIR__"baih2",
  "west" : __DIR__"xw6",
]));
	set("no_clean_up", 0);
	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
