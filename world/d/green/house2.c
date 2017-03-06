// Room: /d/green/house2.c

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ���ª����լ, �ݶ���Լ�����Կ���һЩ�ƶ�. ǽ�Ƕ�
��Щ���, ǽ���ϻ����Կ�����Ѭ�ĺۼ�. ����һЩ��ª�ļҾ���
���ڿտյ�����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/field0",
]));
	set("no_clean_up", 0);
	set("objects", ([
		"/d/green/npc/oldman" :1,
		"/d/green/npc/oldwoman" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
