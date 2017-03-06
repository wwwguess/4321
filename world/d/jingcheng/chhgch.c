// Room: /d/jingcheng/chhgch.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m����㳡[2;37;0m");
	set("long", @LONG
�����ǳ�����ǰ��һƬ�㳡��������ѹ�ĵ���ʮ��ƽ������Χ��һ
Щʯ���̵ĵ�·����Ҳ�ر�Ķ࣬�м��ſ����յģ��������Եģ�
����һȺС��Χ�������˵Ŀ�ϡ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"chhuang",
 		"south" : __DIR__"xw4",
  		"east" : __DIR__"gdd",
		]));
	
	set("objects", ([ /* sizeof() == 1 */
        	__DIR__"npc/tseller.c" : 1,
		__DIR__"npc/kid" : 2,
        	__DIR__"npc/kid2" : 1,
		]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
