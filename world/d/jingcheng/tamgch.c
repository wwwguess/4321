// Room: /d/jingcheng/tamgch.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[31m�㳡[2;37;0m");
	set("long", @LONG
�����Ǿ��ǵ����ģ�������ֽ����ڴˡ�Ρ��ߴ����¥������ǰ
ÿ���峿��������ӵ���������ɴ˴�������˷������ﳵˮ��
¡�������˳����ϡ�����һ���ܴ�Ĺ㳡����ʯ���棬������ɰأ�
Ӫ�����һ�ֺ�г�����ŵ����ա��㳡��ϡϡ�������м����ˣ���
����ǻʳ��ˡ������ǿ����ϴ�֡����������ǳ�����, ������
��վ����ʱ�г����� ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/libai" : 1,
	__DIR__"npc/girl" : 2,
]));
	set("outdoors", "city");

	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"xchjie5",
	"north" : __DIR__"bdj1",
	"south" : __DIR__"ndj1",
	"east" : __DIR__"dchjie1",
]));

	setup();
	replace_program(ROOM);
}
