
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����С��ɽ�ȣ����ɽ��������Ψһ�ĳ��ڡ�ɽ��
�����ﻨ�㣬����������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"grassland1",
  "south" : __DIR__"hole3",
]));
	set("outdoors", "taoguan");
	setup();
        replace_program(ROOM);
}
