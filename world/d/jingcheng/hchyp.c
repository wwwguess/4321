// Room: /d/jingcheng/hchyp.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m�ش�ҩ��[2;37;0m");
	set("long", @LONG
���ǳ�����һ�����ֺŵ�ҩ�̣���ҩ�̼�ֱ̫���ˣ��������Ҷ���
�ġ��ء��ֶ��쿴�������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bdj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yang" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
