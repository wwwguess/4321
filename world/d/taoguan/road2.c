
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ���̳ɵ�ɽ����������ï�ܵ���ľ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road3",
  "southdown" : __DIR__"road1",
]));
	set("outdoors", "taoguan");
        set("objects",(["/obj/npc/pig.c":4]));
	setup();
	replace_program(ROOM);
}
